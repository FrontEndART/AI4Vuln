#include "../../inc/common.h"

using namespace columbus::cfg;
namespace columbus { namespace symbolic {

    StateTree2Graphml::StateTree2Graphml(const columbus::NodeId _entry, columbus::java::asg::ASGFactory& asgFact) : graphmlIO(NULL), treeEdges(), TreeElement2Graphml(), ICFGs(), m_entryFunction(_entry), m_asgFactory(asgFact), m_printer(NULL) {
    }

    StateTree2Graphml::StateTree2Graphml(const StateTree2Graphml& orig) : graphmlIO(orig.graphmlIO), treeEdges(orig.treeEdges), TreeElement2Graphml(orig.TreeElement2Graphml), ICFGs(orig.ICFGs), m_entryFunction(orig.m_entryFunction), m_asgFactory(orig.m_asgFactory), m_printer(orig.m_printer) {
    }

    StateTree2Graphml& StateTree2Graphml::operator=(const StateTree2Graphml& node) {
        if (this != &node) {
            if (graphmlIO) delete graphmlIO;
            // TODO
        }
        return *this;
    }

    StateTree2Graphml::~StateTree2Graphml() {
        delete graphmlIO;
    }

    void StateTree2Graphml::printState(State *currentState, const unsigned int parentGraphmlId) {
        columbus::cfg::ICFGid icfgId = currentState->getCallStackElement().currentMethod;
        unsigned int origBBId = currentState->getBasicBlock().getBlockId();
        unsigned int mlBBId = initICFGandBB(icfgId, currentState, parentGraphmlId);

        // Print out ICFG group
        std::string color = "#F2F0D8";
        if (m_printer != NULL)
            graphmlIO->writeGroupBegin(common::toString(icfgId), "ICFG: " + common::toString(icfgId) + " : " + m_printer->toString(icfgId), color);
        else
            graphmlIO->writeGroupBegin(common::toString(icfgId), "ICFG: " + common::toString(icfgId), color);

        // Print out BasicBlock
        std::string source = common::toString(icfgId) + "::" + common::toString(mlBBId);
        std::string fillColor = "#CCCCFF";
        if (origBBId == ENTRY_BLOCK_ID) {
            graphmlIO->writeNode(common::toString(mlBBId), "Entry (id: " + common::toString(currentState->getStateId()) + ", CD: "+ common::toString(currentState->getCallStackDepth()) +", w: " + common::toString(currentState->getWeight()) + ", BB: " + common::toString(origBBId) + ")", "", "#00FF00", common::toString(icfgId));
        } else if (origBBId == EXIT_BLOCK_ID) {
            graphmlIO->writeNode(common::toString(mlBBId), "Exit (id: " + common::toString(currentState->getStateId()) + ", CD: "+ common::toString(currentState->getCallStackDepth()) +", w: " + common::toString(currentState->getWeight()) + ", BB: " + common::toString(origBBId) + ")", "", "#FF0000", common::toString(icfgId));
        } else {
            graphmlIO->writeNode(common::toString(mlBBId), "State (id: " + common::toString(currentState->getStateId()) + ", CD: "+ common::toString(currentState->getCallStackDepth()) + ", w: " + common::toString(currentState->getWeight()) + ", BB: " + common::toString(origBBId) + ")", "", "#CCCCFF", common::toString(icfgId), fillColor);
        }

        // Root of ProxyTree (basically all of the states have a root context; and classes, arrays too)
        unsigned int mlRootId = getNextFreeBBId(icfgId);
        std::string root = common::toString(icfgId) + "::" + common::toString(mlRootId);
        graphmlIO->writeNode(common::toString(mlRootId), "context", "", "#9C9CFF", common::toString(icfgId), fillColor);
        EdgesInStateTree treeEdge = {source, root, ""};
        addTreeEdge(treeEdge);

        // ProxyTree (context) dump
        dumpContextNodes(currentState->getContext(), icfgId, root);

        graphmlIO->writeGroupEnd();

        // dump the children states
        for (std::vector<State*>::iterator it = currentState->getChildren().begin(); it != currentState->getChildren().end(); ++it) {
            printState(*it, mlBBId);
        }
    }

    void StateTree2Graphml::dumpEdges(State *currentState) {
        dumpContextEdges(currentState->getContext());
        for (std::vector<State*>::iterator it = currentState->getChildren().begin(); it != currentState->getChildren().end(); ++it) {
            dumpEdges(*it);
        }
    }

    void StateTree2Graphml::convertStateTree2Graphml(StateFactory& stateFactory, const CFGFactory& cfgFactory, const std::string& graphOutputName, columbus::cfg::ASGNodePrinter *printer) {
        if (graphmlIO != NULL)
            delete graphmlIO;
        graphmlIO = new io::GraphmlIO(graphOutputName, "State Tree");
        m_printer = printer;

        // Get the root state, and iterate through its children states
        printState(stateFactory.getRootState(), 0);
        dumpEdges(stateFactory.getRootState());

        const ICFGContainer& icfgContainer = cfgFactory.getICFGContainer();
        for (std::vector<ICFGsInGraphML>::const_iterator iit = ICFGs.begin(); iit != ICFGs.end(); ++iit) {
            for (std::vector<StatesInGraphMl>::const_iterator sit = iit->states.begin(); sit != iit->states.end(); ++sit) {

                ICFGContainer::const_iterator foundCurrentICFG = icfgContainer.find(iit->icfgId);
                ICFG *currentICFG = NULL;
                if (foundCurrentICFG != icfgContainer.end()) {
                    currentICFG = foundCurrentICFG->second;
                } else
                    continue;

                ICFGid parentICFGId = currentICFG->getMethodId();

                const BasicBlock& currentBB = sit->stateForBasicBlock->getBasicBlock();
                unsigned int parentBBId = currentBB.getBlockId();
                unsigned int parentGraphmlId = sit->graphmlId;

                // Iterate the children
                State *currentState = sit->stateForBasicBlock;
                for (std::vector<State*>::iterator it = currentState->getChildren().begin(); it != currentState->getChildren().end(); ++it) {
                    State *childState = *it;
                    const BasicBlock& childBB = childState->getBasicBlock();
                    ICFG *childICFG = childBB.getParent();
                    ICFGid childICFGId = childICFG->getMethodId();
                    unsigned int childBBId = childBB.getBlockId();
                    unsigned int childGraphmlId = getGraphmlId(childICFGId, childState->getStateId(), parentGraphmlId);

                    // Control edges
                    cfg::BasicBlock::EdgesConstIterator controlOutEdgeIt = currentBB.controlOutEdgesIterator();
                    while (controlOutEdgeIt.hasNext()) {
                        const Edge *edge = controlOutEdgeIt.next();
                        if(edge != NULL){
                            const BasicBlock *fromBlock = edge->getFrom();
                            const BasicBlock *toBlock = edge->getTo();
                            if (parentICFGId == fromBlock->getParent()->getMethodId() && parentBBId == fromBlock->getBlockId() &&
                                childICFGId == toBlock->getParent()->getMethodId() && childBBId == toBlock->getBlockId()) {

                                std::string source = common::toString(parentICFGId) + "::" + common::toString(parentGraphmlId);
                                std::string target = common::toString(childICFGId) + "::" + common::toString(childGraphmlId);

                                std::string edgeLabel = "control";
                                if(edge->getLabel().compare("") != 0){
                                    edgeLabel += " - " + edge->getLabel();
                                }
                                EdgesInStateTree stateEdge = {source, target, edgeLabel};
                                addTreeEdge(stateEdge);
                            }
                        }
                    }

                    // Call edges
                    cfg::BasicBlock::EdgesConstIterator callOutEdgeIt = currentBB.callOutEdgesIterator();
                    while (callOutEdgeIt.hasNext()) {
                        const Edge *edge = callOutEdgeIt.next();
                        if(edge != NULL){
                            const BasicBlock *fromBlock = edge->getFrom();
                            const BasicBlock *toBlock = edge->getTo();
                            if (parentICFGId == fromBlock->getParent()->getMethodId() && parentBBId == fromBlock->getBlockId() &&
                                childICFGId == toBlock->getParent()->getMethodId() && childBBId == toBlock->getBlockId()) {

                                std::string source = common::toString(parentICFGId) + "::" + common::toString(parentGraphmlId);
                                std::string target = common::toString(childICFGId) + "::" + common::toString(childGraphmlId);
                                std::string edgeLabel = "call";
                                if(edge->getLabel().compare("") != 0){
                                    edgeLabel += " - " + edge->getLabel();
                                }
                                EdgesInStateTree stateEdge = {source, target, edgeLabel};
                                addTreeEdge(stateEdge);
                            }
                        }
                    }
                }
            }
        }

        // Print out the edges
        for(std::vector<EdgesInStateTree>::const_iterator treeIt = treeEdges.begin(); treeIt != treeEdges.end(); ++treeIt) {
            std::size_t found = treeIt->label.find("call");
            if (found != std::string::npos)
                graphmlIO->writeEdge(treeIt->source, treeIt->target, treeIt->label, 1, graphmlIO->ls_dashed, graphmlIO->at_none, graphmlIO->at_standard);
            else
                graphmlIO->writeEdge(treeIt->source, treeIt->target, treeIt->label, 1, graphmlIO->ls_line, graphmlIO->at_none, graphmlIO->at_standard);
        }
    }

    void StateTree2Graphml::dumpContextNodes(Context *ctx, const columbus::cfg::ICFGid icfgId, const std::string root) {
        if (ctx != NULL) {
            TreeElement2Graphml.insert(std::make_pair<Context*, std::string>(&(*ctx), root));

            std::string fillColor = "#CCCCFF";
            std::string source = root;

            std::map<SmartDefinition, Context*, ltDeref<SmartDefinition> > elements = ctx->getElements();
            std::map<SmartDefinition, Context*, ltDeref<SmartDefinition> >::const_iterator elIt;
            for (elIt = elements.begin(); elIt != elements.end(); ++elIt) {
                SmartDefinition sd = elIt->second->operator columbus::symbolic::SmartDefinition();
                Context *nextContext = NULL;
                //if (sd->isClassValueDefinition()) // branch need here if CVD/AVD is a separated proxy tree
                nextContext = elIt->second;

                stringstream ss;
                sd->operator<<(ss);
                unsigned int nextId = getNextFreeBBId(icfgId);
                std::string nodeName = ss.str();
                try {
                    if (smartDefinitionToNodeId(elIt->first) == 0) {
                        nodeName = "heap";
                    }
                } catch (SymbolicColumbusException &ex) {
                    // empty catch, but nothing to do here
                }

                std::string nodeColor = "#9C9CFF";
                if (sd->isSymbolDefinition()) {
                    nodeColor = "#FF00FF";
                    if (nodeName.find("NULL") != std::string::npos)
                        nodeName = "";
                }
                if (m_printer == NULL)
                    graphmlIO->writeNode(common::toString(nextId), nodeName, "", nodeColor, common::toString(icfgId), fillColor);
                else {
                    std::string printerName = "";
                    if (!sd->isClassValueDefinition() && !sd->isArrayValueDefinition())
                        try {
                            printerName =  m_printer->toString(smartDefinitionToNodeId(elIt->first)); // variable name
                        } catch (SymbolicColumbusException &ex) {
                            // empty catch, but nothing to do here
                        }
                    graphmlIO->writeNode(common::toString(nextId), nodeName + std::string("\n") + printerName, "", nodeColor, common::toString(icfgId), fillColor);
                }

                std::string target = common::toString(icfgId) + "::" + common::toString(nextId);
                dumpContextNodes(nextContext, icfgId, target);
            }
        }
    }

    void StateTree2Graphml::dumpContextEdges(Context *ctx) {
        if (ctx != NULL) {
            std::string root = "";
            std::map<Context*, std::string>::const_iterator foundRoot = TreeElement2Graphml.find(&(*ctx));
            if (foundRoot != TreeElement2Graphml.end()) {
                root = foundRoot->second;
            } else {
                // TODO
                return;
            }

            std::map<Context*, std::string>::const_iterator foundParent = TreeElement2Graphml.find(&(*(ctx->getParent())));
            if (foundParent != TreeElement2Graphml.end()) {
                EdgesInStateTree treeEdge = {root, foundParent->second, ""};
                addTreeEdge(treeEdge);
            } else {
                // TODO
            }

            std::map<SmartDefinition, Context*, ltDeref<SmartDefinition> > elements = ctx->getElements();
            std::map<SmartDefinition, Context*, ltDeref<SmartDefinition> >::const_iterator elIt;
            for (elIt = elements.begin(); elIt != elements.end(); ++elIt) {
                SmartDefinition sd = elIt->second->operator columbus::symbolic::SmartDefinition();
                Context *nextContext = NULL;
                //if (sd->isClassValueDefinition()) // branch need here if CVD/AVD is a separated proxy tree
                nextContext = elIt->second;

                std::string target = "";
                std::map<Context*, std::string>::const_iterator foundTarget = TreeElement2Graphml.find(&(*(nextContext)));;
                if (foundTarget != TreeElement2Graphml.end()) {
                    target = foundTarget->second;
                    std::string edgeLabel = *elIt->first;
                    EdgesInStateTree treeEdge = {root, target, edgeLabel};
                    addTreeEdge(treeEdge);
                } else {
                    // TODO
                }

                dumpContextEdges(nextContext);
            }
        }
    }

    void StateTree2Graphml::addTreeEdge(EdgesInStateTree& edge) {
        std::vector<EdgesInStateTree>::const_iterator foundEdge = std::find(treeEdges.begin(), treeEdges.end(), edge);
        if (foundEdge == treeEdges.end())
            treeEdges.push_back(edge);
    }

    unsigned int StateTree2Graphml::initICFGandBB(const columbus::cfg::ICFGid icfgId, State *state, const unsigned int parentGraphmlId) {
        StatesInGraphMl bb;
        bb.stateForBasicBlock = state;
        bb.parentGraphmlId = parentGraphmlId;

        std::vector<ICFGsInGraphML>::iterator found = std::find(ICFGs.begin(), ICFGs.end(), icfgId);
        if (found == ICFGs.end()) {
            ICFGsInGraphML newICFG = {};
            newICFG.icfgId = icfgId;
            newICFG.nextFreeGraphmlId = EXIT_BLOCK_ID + 1;

            std::vector<StatesInGraphMl> states;
            bb.graphmlId = newICFG.nextFreeGraphmlId;
            newICFG.nextFreeGraphmlId++;
            states.push_back(bb);

            newICFG.states = states;
            ICFGs.push_back(newICFG);

        } else {
            bb.graphmlId = found->nextFreeGraphmlId;
            found->nextFreeGraphmlId++;
            found->states.push_back(bb);
        }
        return bb.graphmlId;
    }

    unsigned int StateTree2Graphml::getNextFreeBBId(const columbus::cfg::ICFGid icfgId) {
        unsigned int result = 0;
        std::vector<ICFGsInGraphML>::iterator found = std::find(ICFGs.begin(), ICFGs.end(), icfgId);
        if (found != ICFGs.end()) {
            result = found->nextFreeGraphmlId;
            found->nextFreeGraphmlId++;
        } else {
            result = 1;
        }
        return result;
    }

    unsigned int StateTree2Graphml::getGraphmlId(const ICFGid methodId, const unsigned int stateId, const unsigned int parentGID) const {
        unsigned int result = 0;
        bool found = false;
        for (std::vector<ICFGsInGraphML>::const_iterator iit = ICFGs.begin(); iit != ICFGs.end() && !found; ++iit) {
            if (iit->icfgId == methodId) {
                for (std::vector<StatesInGraphMl>::const_iterator bit = iit->states.begin(); bit != iit->states.end(); ++bit) {
                    if (bit->stateForBasicBlock->getStateId() == stateId && bit->parentGraphmlId == parentGID) {
                        result = bit->graphmlId;
                        found = true;
                        break;
                    }
                }
            }
        }
        return result;
    }

}} // end of namespaces
