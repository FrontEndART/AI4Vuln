#include "../../inc/common.h"

using namespace columbus::cfg;
namespace columbus { namespace symbolic {

    StateListener::~StateListener() {
        for (std::vector<StackTrace*>::iterator it = m_exceptions.begin(); it != m_exceptions.end(); ++it) {
            StackTrace *st = *it;
            if (st != NULL) {
                delete st;
                st = NULL;
            }
        }
    }

    void StateListener::checkForRepeating() {
        for (std::vector<StackTrace*>::iterator it = m_exceptions.begin(); it != m_exceptions.end(); ++it) {
            StackTrace *st = *it;
            processStackTraceForRepeating(st);
        }
    }

    void StateListener::processStackTraceForRepeating(StackTrace *st) {
        ExceptionType et = st->getExceptionType();

        if (m_filteredExceptions.find(et) != m_filteredExceptions.end()) {
            // At this point there are at least one element in the set
            FilteredExceptionSetType existingSet = m_filteredExceptions[et];

            // Get the existing leaderNode
            FilteredExceptionSetType::iterator found = existingSet.find(st);
            if (found == existingSet.end()) {
                existingSet.insert(st);
                m_filteredExceptions[et] = existingSet;
            } else {
                // Check if the trace length is shorter the the found one
                StackTrace *existing = *found;
                if (*st < *existing) {
                    // Replace
                    existingSet.erase(existing);
                    existingSet.insert(st);
                    m_filteredExceptions.erase(et);
                    m_filteredExceptions[et] = existingSet;
                    existing->setIsRepeated(true);
                } else {
                    st->setIsRepeated(true);
                }
            }

        } else {
            FilteredExceptionSetType newSet;
            newSet.insert(st);
            m_filteredExceptions[et] = newSet;
        }
    }

    void StateListener::createStackTrace(ExceptionType type, LeaderPoint *leaderPoint, columbus::NodeId nodeId, const State& state) {
        StackTrace *st = new StackTrace(type);
        st->setLeaderPoint(leaderPoint);

        // Collect the involved stateIds
        //std::set<unsigned int> involvedStateIds;

        // Set the call stack
        const State *current = &state;
        bool lastIsExit = false;
        bool lastIsCall = false;
        do {
            bool containsProxyTreeState = true;//involvedStateIds.find(current->getStateId()) != involvedStateIds.end();
            if (!containsProxyTreeState) {
                current = &current->getParent();
                continue;
            }

            if (current->getBasicBlock().getBlockId() == ENTRY_BLOCK_ID) {
                lastIsCall = true;
            } else if (current->getBasicBlock().getBlockId() == EXIT_BLOCK_ID) {
                lastIsExit = true;
            } else {
            }

            if (current->getBasicBlock().getBlockId() != ENTRY_BLOCK_ID && current->getBasicBlock().getBlockId() != EXIT_BLOCK_ID) {
                if (lastIsExit) {
                    // CALL RETURN
                    createStackTraceForState(*current, st, columbus::symbolic::CALL_RETURN, lastIsExit);
                    lastIsExit = false;

                } else if (lastIsCall) {
                    // Before CALL
                    createStackTraceForState(*current, st, columbus::symbolic::EMPTY, lastIsCall);
                    lastIsCall = false;

                } else {
                    // CONTROL
                    const State *tempState = &current->getParent();
                    if (tempState != NULL && tempState->hasParent())
                        createStackTraceForState(*current, st, columbus::symbolic::CONTROL);
                }

            } else if (current->getBasicBlock().getBlockId() == ENTRY_BLOCK_ID) {
                // CALL
                TracePoint tpoint = {(NodeId)state.getStateFactory().getState(current->getStateId())->getBasicBlock().getParent()->getMethodId(), columbus::symbolic::CALL, current->getStateId(), current->getCallDepth()};
                st->addTracePoint(tpoint);
            }

            current = &current->getParent();

        } while (current->hasParent());

        // The ENTRY point
        TracePoint tpoint = {(NodeId)state.getStateFactory().getState(current->getStateId())->getBasicBlock().getParent()->getMethodId(), columbus::symbolic::ENTRY, current->getStateId(), current->getCallDepth()};
        st->addTracePoint(tpoint);

        m_exceptions.push_back(st);
    }

    bool StateListener::createStackTraceForState(const columbus::symbolic::State& state, StackTrace *st, TracePointType tp, bool lastNode) {
        const columbus::cfg::BasicBlock& bb = state.getBasicBlock();

        // Get the first (control)/last (return) nodeId of the actual BB
        columbus::NodeId firstNode = 0;
        if (!lastNode) {
            columbus::cfg::BasicBlock::NodesConstIterator iter = bb.nodesConstIterator();
            if (!iter.hasNext())
                return false;
            firstNode = iter.next();

        } else {
            columbus::cfg::BasicBlock::NodesReverseConstIterator iter = bb.nodesReverseConstIterator();
            if (!iter.hasNext())
                return false;
            firstNode = iter.next();
        }

        TracePoint tpoint = {firstNode, tp, state.getStateId(), state.getCallDepth()};
        st->addTracePoint(tpoint);
        return true;
    }

    void StateListener::printOutAllStackTrace() {
        checkForRepeating();

        // Sorting the result: 1. by type, 2. by probability
        for (int exType = 0; exType < EXCEPTIONTYPE_END; ++exType) {
            ExceptionType currentType = (ExceptionType) exType;
            //std::cout << "ct: " << currentType << std::endl;
            std::multiset<StackTrace*, StackTrace_compare_by_Probability> tempExceptions;
            for (std::vector<StackTrace*>::const_iterator it = m_exceptions.begin(); it != m_exceptions.end(); ++it) {
                if ((*it)->getExceptionType() == currentType) {
                    tempExceptions.insert(*it);
                }
            }

            for (std::multiset<StackTrace*, StackTrace_compare_by_Probability>::const_iterator it = tempExceptions.begin(); it != tempExceptions.end(); ++it) {
                //std::cout << "ct: " << (*it)->getExceptionType() << ", prob: " << (*it)->getLeaderPoint()->getPropability() << ", nodeId: " << (*it)->getLeaderPoint()->getOrigNodeId() << std::endl;
                printOutStackTrace(*it);
            }
        }
    }

#if 0
    bool StateListener::isAlreadyExistsLeaderNode(const columbus::NodeId nodeId) const {
        // TODO: ezt itt lehet gyorsitani, ha eltarolom, hogy mely leader node-okhoz mely stateId-k tartoznak
        bool result = false;
        for (std::vector<StackTrace*>::const_iterator it = m_exceptions.begin(); it != m_exceptions.end(); ++it) {
            StackTrace *st = *it;
            if (st != NULL && st->getLeaderNodeId() == nodeId) {
                result = true;
                break;
            }
        }
        return result;
    }

    void StateListener::getExistingStateIdsForLeaderNode(const columbus::NodeId nodeId, std::vector<StackTrace*>& existingStackTraces) const {
        // TODO: ezt itt lehet gyorsitani, ha eltarolom, hogy mely leader node-okhoz mely stateId-k tartoznak
        for (std::vector<StackTrace*>::const_iterator it = m_exceptions.begin(); it != m_exceptions.end(); ++it) {
            StackTrace *st = *it;
            if (st != NULL && st->getLeaderNodeId() == nodeId) {
                existingStackTraces.push_back(st);
            }
        }
    }
#endif

}} // end of namespaces
