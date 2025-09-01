#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    SymbolicEngine::SymbolicEngine(columbus::cfg::CFGFactory& _cfgFactory, columbus::java::asg::ASGFactory& asgFact, const columbus::rul::RulHandler* _rulHandler, ConstraintSolver* solver, ConstraintBuilder* builder, int optionalDepth)
                  : 
				    currentState(NULL),
                    cfgFactory(_cfgFactory),
					asgFactory(asgFact),
                    executor(NULL),
                    strategy(NULL),
                    stateFactory(NULL),
                    maxState(0),
                    maxDepth(0),
                    m_stateNumber(1),
                    m_exceptionalStateNumber(0),
                    rulHandler(_rulHandler), symbolIdentifierCounter(0), definitionCounter(0), heapPointer(1),
					constraintSolver(solver),
				    constraintBuilder(builder){
        Configuration *config = Configuration::getInstance();
        if (config->getSearchStrategy() == DEPTH_FIRST) {
            strategy = new DepthFirstSearchStrategy(*this);
        } else {    // default
            strategy = new BreadthFirstSearchStrategy(*this);
        }
        maxState = config->getMaxState();
        maxDepth = optionalDepth != -1 ? optionalDepth : config->getMaxDepth();
    }

    SymbolicEngine::SymbolicEngine(const SymbolicEngine& engine)
                  : currentState(NULL),
                    cfgFactory(engine.cfgFactory),
					asgFactory(engine.asgFactory),
                    executor(NULL),
                    strategy(NULL),
                    stateFactory(NULL),
                    maxState(0),
                    maxDepth(0),
                    m_stateNumber(1),
                    m_exceptionalStateNumber(0),
                    rulHandler(engine.rulHandler), symbolIdentifierCounter(0), definitionCounter(0), heapPointer(1) {
        Configuration *config = Configuration::getInstance();
        if (config->getSearchStrategy() == DEPTH_FIRST) {
            strategy = new DepthFirstSearchStrategy(*this);
        } else {    // default
            strategy = new BreadthFirstSearchStrategy(*this);
        }
        maxState = config->getMaxState();
        maxDepth = config->getMaxDepth();
    }

    SymbolicEngine::~SymbolicEngine() {
        delete strategy;
    }

    void SymbolicEngine::run(StateFactory *_stateFactory, NodeId _methodId) {
        if (executor == NULL)
            throw SymbolicColumbusException("Executor not set");
        
        const columbus::cfg::ICFGContainer& container = cfgFactory.getICFGContainer();
        stateFactory = _stateFactory;

        if (_methodId != 0 && container.find(_methodId) != container.end()) {
            /**
            *    We have a method for which there is an ICFG
            */
            columbus::cfg::ICFG *methodCFG = cfgFactory.getICFG(_methodId);
            if (!methodCFG->getIsStaticInit() && !methodCFG->getIsInstanceInit()) {
                /**
                *    The method is not a static or instance initializer of a class
                */
                NodeId parent=executor->getScopeOrMethodDeclarationParent(_methodId);
                currentState = stateFactory->createState(*(methodCFG->getEntryBlock()));
                executor->initializeThis(parent, *currentState);
                search(*stateFactory);
            }
        }
    }

    void SymbolicEngine::search(StateFactory& stateFactory) {
        State *rootState = stateFactory.getRootState();
        if (rootState != NULL) {
            strategy->initialize(*rootState);
            while (m_stateNumber <= maxState) {
                //nextState->preExecuteInit(); // build PC
                State* nextState = NULL;
                try {
                    nextState = strategy->getNextState();
                    if (nextState==NULL)
                        break;
                    else //if(!nextState->isUnreachableState())
                        executeState(*nextState);
                } catch (SymbolicColumbusException& e) {
                    if (nextState!=NULL)
                        nextState->setExceptional();
                    m_exceptionalStateNumber++;
                    common::WriteMsg::write(common::WriteMsg::mlDebug, "Warning: a SymbolicColumbusException occoured: %s\n", e.what());
                }
                ++m_stateNumber;

                //TODO: isSatisfiable
                //TODO: limitReached
                //TODO: sameState?
            }
        }
    }

    std::vector<State*> SymbolicEngine::expandState(State &state) {
        std::vector<State*> ret;
        try {
            if (state.getDepth() > maxDepth || state.isExceptional()  || state.isUnreachableState())
                return ret;

            const columbus::cfg::BasicBlock& basicBlock = state.getBasicBlock();
            // Check if this is a returning BB
            if (basicBlock.isExitBlock()) {
                //exit block
                State* callerState = state.getCallerState();
                if (callerState == NULL) {
                    return ret;
                }
                columbus::cfg::BasicBlock::EdgesConstIterator iter = callerState->getBasicBlock().controlOutEdgesIterator();
                if (iter.hasNext()) {
                    const columbus::cfg::Edge *edge = iter.next();
                    State* newState = state.getStateFactory().createState(*edge->getTo(), &state, State::RETURN_EDGE);
                    ret.push_back(newState);
                    executor->makeCallReturn(*newState);
                    if (newState->getVariables().size() != state.getVariables().size()) {
                        for (auto var : state.getVariables()) {
                            newState->addVariable(var);
                        }
                    }
                    if (newState->getConstraintSolverExprs().size() != state.getConstraintSolverExprs().size()) {
                        for (auto [k, v] : state.getConstraintSolverExprs()) {
                            newState->addConstraintSolverExpr(k, v);
                        }
                    }
                } else {
                    throw SymbolicColumbusException("Returning from a call, but no control out edge exists");
                }
            
                return ret;
            }

            columbus::cfg::BasicBlock::EdgesConstIterator callOutIter = basicBlock.callOutEdgesIterator();
            if (callOutIter.hasNext()) {
                /** 
                *    Call edge out
                */
                const columbus::cfg::Edge* callOutEdge = callOutIter.next();
                columbus::cfg::BasicBlock::EdgesConstIterator controlOutIter = basicBlock.controlOutEdgesIterator();

                if (!callOutEdge->getFrom()->isExitBlock() && !callOutEdge->getTo()->getParent()->getIsStaticInit()) {
                    /**
                    *    We have a normal method call...which is not a static init call (we don't go into static init blocks)
                    */
                    if (state.isExceptional()) {
                        /**
                        *    ...but we are in an exceptional state, we cannot make the call
                        */
                    } else {
                        /**
                        *    ....we are in a non-exceptional state, the call will occur
                        */
                        if (!callOutEdge->getTo()->isEntryBlock()) {
                            /**
                            *    A call edge to a non-entry block....this should never happen
                            */
                            throw SymbolicColumbusException("Call edge ''to'' is not an entry block");
                        }
                        if (!controlOutIter.hasNext())  {
                            /**
                            *    Control egde is missing for the call....this should never happen
                            */

                            throw SymbolicColumbusException("Call edge without a control edge");
                        }
                        const columbus::cfg::BasicBlock *calledBB = callOutEdge->getTo();
                        const columbus::cfg::Edge* controlOutedge=controlOutIter.next();

                        const columbus::cfg::BasicBlock *nextBBOnControlEdge = controlOutedge->getTo();
                        cfg::BasicBlock::NodesConstIterator nodesInNextControlBlockIter = nextBBOnControlEdge->nodesConstIterator();
                        std::vector<const columbus::cfg::BasicBlock*> nextBBs;
                        nextBBs.push_back(calledBB);
                        if (nodesInNextControlBlockIter.hasNext()) {
                            /**
                            *
                            */
                            nextBBs.pop_back();
                            cfg::BasicBlock::EdgesConstIterator callOutIter = basicBlock.callOutEdgesIterator();
                            while (callOutIter.hasNext()) {
                                nextBBs.push_back(callOutIter.next()->getTo());
                            }

                        }

                        for (std::vector<const columbus::cfg::BasicBlock*>::const_iterator nextBBIt = nextBBs.begin(); nextBBIt != nextBBs.end(); ++nextBBIt) {
                            calledBB = *nextBBIt;

                            columbus::cfg::ICFGid methodId = calledBB->getParent()->getMethodId();
                        
                            State* newState = state.getStateFactory().createState(*calledBB, &state, State::CALL_EDGE);
                        
                            ret.push_back(newState);
                            cfg::BasicBlock::NodesConstIterator nodesInNextControlBlockInternalIter = nextBBOnControlEdge->nodesConstIterator();
                            if (nodesInNextControlBlockInternalIter.hasNext()) {
                                NodeId leader = nodesInNextControlBlockInternalIter.next();
                                while (leader == STATEMENT_BORDER_ID && nodesInNextControlBlockInternalIter.hasNext()) {
                                    leader = nodesInNextControlBlockInternalIter.next();
                                }
                                if (leader != STATEMENT_BORDER_ID) {
                                    executor->setupCalledState(*newState, leader, methodId);
                                } 
                            } else {
                                // TODO
                                // Bug in cfg
                                throw SymbolicColumbusException("Error in CFG! MethodInvocation/NewClass node not found in next control block.");
                            }
                        
                        }
                    }
                } else if (callOutEdge->getTo()->getParent()->getIsStaticInit()) {
                    // skipp calls to static inits
                    if (controlOutIter.hasNext()) {
                        const cfg::BasicBlock& target = *controlOutIter.next()->getTo();
                        ret.push_back(state.getStateFactory().createState(target, &state, State::NORMAL_EDGE));
                    }
                }
            } else {
               /**
                * There is no call edge
                */
                bool isStackEmpty = state.isStackEmpty();
                columbus::cfg::BasicBlock::EdgesConstIterator iter = basicBlock.controlOutEdgesIterator();
                SmartDefinition lastDefinition;
                if (iter.size() > 0) {
                    //TODO: Ures is lehet a stack!!!
                    if (!isStackEmpty) {
                        lastDefinition = state.topDefinition();
                    }
                } else {
                    // TODO
                    //throw SymbolicColumbusException("Basic Block has more than one following blocks, but does not have any nodes in it!");
                }

                //bool foundSwitch = false;
                while (iter.hasNext()) {
                    const columbus::cfg::Edge* edge = iter.next();
                    if (edge->getIsExceptional())
                        continue;
                    const columbus::cfg::BasicBlock* target = edge->getTo();

                    bool hasToCreateState = false;
                    bool hasToCreateStateOnFalseBranch = false;
                    bool hasToCreateStateOnTrueBranch = false;

                    SmartDefinition def;
                    // Boolean expression - if
                    if (edge->getLabel().compare("true") == 0 && !isStackEmpty) {
                        // lastDefinition must not be NULL
                        if (!lastDefinition->getIsSymbol() && executor->getBooleanValueDefinitionValue(lastDefinition) == true) {
                            hasToCreateState = true;
                        } else if (!lastDefinition->getIsSymbol() && executor->getBooleanValueDefinitionValue(lastDefinition) == false) {
                            // we don't create a new state at this point
                        } else if (lastDefinition->getIsSymbol()) {
                            hasToCreateStateOnTrueBranch = hasToCreateState = true;
                            //Constraint!!!
                        }
                    } else if (edge->getLabel().compare("false") == 0 && !isStackEmpty) {
                        // lastDefinition must not be NULL
                        if (!lastDefinition->getIsSymbol() && executor->getBooleanValueDefinitionValue(lastDefinition) == false) {
                            hasToCreateState = true;
                        } else if (!lastDefinition->getIsSymbol() && executor->getBooleanValueDefinitionValue(lastDefinition) == true) {
                            //we don't create a new state at this point
                        } else if (lastDefinition->getIsSymbol()) {
                            hasToCreateStateOnFalseBranch = hasToCreateState = true;
                            //Constraint!!!
                        }

                    } else if (edge->getLabel().compare("") == 0) {
                
                        // We have a direct control flow
                        hasToCreateState = true;

                    } else if (executor->getLastIsSwitch()) {
                        // Switch statement
                       hasToCreateState = true;
                      /* NodeId id = executor->getCurrentNodeId();
                        if (lastDefinition->isIntValueDefinition() || lastDefinition->isByteValueDefinition() || lastDefinition->isShortValueDefinition()) {
                            long long value = dynamic_cast<const Definition*>(lastDefinition.get());
                            std::string expectedSwitchLabel = common::toString(value);
                            if (edge->getLabel().compare(expectedSwitchLabel) == 0) {
                                hasToCreateState = true;
                                foundSwitch = true;

                            } else if (!foundSwitch && edge->getLabel().compare("default") == 0) {
                                hasToCreateState = true;
                            }

                        } else if (lastDefinition->getIsSymbol()) {
                            hasToCreateState = true;

                        } else if (lastDefinition->isE) {
                            std::string expectedSwitchLabel = lastDefinition->getEnumConstantName();
                            if (edge->getLabel().compare(expectedSwitchLabel) == 0) {
                                hasToCreateState = true;
                                foundSwitch = true;

                            } else if (!foundSwitch && edge->getLabel().compare("default") == 0) {
                                hasToCreateState = true;
                            }
                        }
                        hasToCreateState = true;*/
                       // executor->setLastIsSwitch(false); // ez jo igy???
                        
                    }

                    if (hasToCreateState) {
                        State* newState = state.getStateFactory().createState(*target, &state, State::NORMAL_EDGE);
                        if (hasToCreateStateOnFalseBranch) {
                            // if we are on a false branch and the logical value was symbol we swap that symbol with a false value on the stack
                            auto t = newState->topDefinition();
                            newState->popDefinition();
                            auto newDef = executor->createBooleanValueDefinition(false);
                            if (t->getIsSymbol() && t->getCsExpr() != nullptr) {
                                Constraint* c = getConstraintBuilder()->makeNegatedConstraint(t->getCsExpr());
                                newDef->setCsExpr(t->getCsExpr()); //todo -> negálni?
                                newState->addNewCondition(c);
                            }
                            newState->pushDefinition(newDef);
                            
                        } else if (hasToCreateStateOnTrueBranch) {
                            // if we are on a true branch and the logical value was symbol, we swap that symbol with a true value on the stack
                            auto t = newState->topDefinition();
                            newState->popDefinition();
                            auto newDef = executor->createBooleanValueDefinition(true);
                            if (t->getIsSymbol() && t->getCsExpr() != nullptr) {
                                newDef->setCsExpr(t->getCsExpr());
                                auto c = getConstraintBuilder()->makeConstraint(t->getCsExpr());
                                newState->addNewCondition(c);
                            }
                            newState->pushDefinition(newDef);
                        }
                        ret.push_back(newState);
                    }
                    executor->setLastIsSwitch(false);
                }

                if (executor->getLastIsSwitch()) {
                    executor->setLastIsSwitch(false);//EZ JO?
                }
                    
                
            }
        } catch (SymbolicColumbusException &ex) {
            state.setExceptional();
            m_exceptionalStateNumber++;
            ret.clear();
            common::WriteMsg::write(common::WriteMsg::mlDebug, "Warning: a SymbolicColumbusException occoured at expandState: %s\n", ex.what());
        }
        
        return ret;
    }

    void SymbolicEngine::executeState(State& state) {
        stringstream rs;
        
        currentState = &state;
        const columbus::cfg::BasicBlock& bb = currentState->getBasicBlock();
        columbus::cfg::BasicBlock::NodesConstIterator iter = bb.nodesConstIterator();
        while (iter.hasNext()) {
            NodeId currentNode = iter.next();

            if (currentNode == STATEMENT_BORDER_ID) {
                // Empty the stack
                while (!currentState->isStackEmpty()) {
                    currentState->popDefinition();
                }
            } else {
                executor->execute(currentNode);
            }
        }
    }

    bool SymbolicEngine::isNodeIdBefore(const columbus::NodeId before, const columbus::NodeId last) const {
        bool result = false;

        bool foundLast = false;
        cfg::BasicBlock::NodesReverseConstIterator nodesIt = currentState->getBasicBlock().nodesReverseConstIterator();
        while (nodesIt.hasNext()) {
            NodeId currentNode = nodesIt.next();
            if (currentNode == last)
                foundLast = true;
            else if (currentNode == before) {
                if (foundLast)
                    result = true;
                break;
            }
        }
        return result;
    }

    void SymbolicEngine::setExecutor(AbstractSymbolicExecutor& _executor) {
        if (executor != NULL)
            throw SymbolicColumbusException("Attempting to change the executor of a symbolic engine");
        executor = &_executor;
    }

    void SymbolicEngine::fireNullPointerDereferenced(NodeId nodeId, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->nullPointerDereferenced(nodeId, state);
        }
        
    }

    void SymbolicEngine::fireInfiniteLoop(NodeId nodeId, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->infiniteLoop(nodeId, state);
        }
       
    }

    void SymbolicEngine::fireClassCastException(NodeId nodeId, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->classCastException(nodeId, state);
        }
        
    }

    void SymbolicEngine::fireDivisionByZero(NodeId nodeId, const State& state) {
      
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->divisionByZero(nodeId, state);
        }
      
    }

    void SymbolicEngine::fireIndexOutOfBounds(NodeId nodeId, int arrayLength, int index, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->indexOutOfBounds(nodeId, state, arrayLength, index);
        }
        
    }

    void SymbolicEngine::fireNegativeArraySize(NodeId nodeId, int arrayLength, const State& state) {
       
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->negativeArraySize(nodeId, state, arrayLength);
        }

    }

    void SymbolicEngine::fireDefinitionPushed(SmartDefinition definition, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->definitionPushed(state, definition);
        }
    }

    void SymbolicEngine::fireDefinitionPoped(SmartDefinition definition, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->definitionPoped(state, definition);
        }
    }

    void SymbolicEngine::fireUsedStaticVariable(const NodeId variableId, const std::vector<State*>& exitStates, const State& state) {
        
        for (std::vector<StateListener*>::iterator iter = listeners.begin(); iter != listeners.end(); iter++) {
            (*iter)->usedStaticVariable(variableId, exitStates);
        }
    }


    // void SymbolicEngine::addWarning(std::string checkerId, columbus::NodeId id, const std::list<columbus::NodeId>& warningTextParams) {
    //    if (warningListener->getCheckerId().compare(checkerId) == 0) {
    //        warningListener->addWarning(id, warningTextParams);
    //    }
    //}

    //void SymbolicEngine::addWarning(std::string checkerId, columbus::NodeId nodeId, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo) {
    //    if (warningListener->getCheckerId().compare(checkerId) == 0) {
    //        warningListener->addWarningWithText(nodeId, warningText, extraInfo);
    //    }
    //}


}}
