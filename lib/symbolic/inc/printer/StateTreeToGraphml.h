#ifndef _STATE_TREE_TO_GRAPHML_H
#define _STATE_TREE_TO_GRAPHML_H

#include "../common.h"

namespace columbus { namespace symbolic {

    class StateTree2Graphml {
    private:
        /**
        * \brief Struct definition for edges to store source node, target node and the label. 
        */
        struct EdgesInStateTree {
            std::string source;
            std::string target;
            std::string label;
            bool operator==(const EdgesInStateTree& b) const {
                return source == b.source && target == b.target && label == b.label;
            }
        };

        struct StatesInGraphMl {
            unsigned int graphmlId;
            unsigned int parentGraphmlId;
            State* stateForBasicBlock;
            bool operator==(const StatesInGraphMl& s) const {
                return stateForBasicBlock->getStateId() == s.stateForBasicBlock->getStateId() && graphmlId == s.graphmlId;
            }

            StatesInGraphMl() : graphmlId(0), parentGraphmlId(0), stateForBasicBlock(NULL) {}
        };

        struct ICFGsInGraphML {
            columbus::cfg::ICFGid icfgId;
            std::vector<StatesInGraphMl> states;
            unsigned int nextFreeGraphmlId;
            bool operator==(const columbus::cfg::ICFGid _icfg) const {
                return icfgId == _icfg;
            }
        };

        /** \brief The GraphmlIO pointer that will point to a GraphmlIO, that can write elements into the graphml. */
        io::GraphmlIO *graphmlIO;

        /**
        * \brief \internal Storage for the EdgesInStateTree structs, that stores tree edge informations. 
        */
        std::vector<EdgesInStateTree> treeEdges;

        /**
        * \brief \internal Storage for mapping the ICFG to root id.
        */
        std::map<Context*, std::string> TreeElement2Graphml;

        std::vector<ICFGsInGraphML> ICFGs;

        columbus::NodeId m_entryFunction;
        columbus::java::asg::ASGFactory& m_asgFactory;
        columbus::cfg::ASGNodePrinter *m_printer;

    public:
        /**
        * \brief Constructor.
        */
        StateTree2Graphml(const columbus::NodeId _entry, columbus::java::asg::ASGFactory& asgFact);

        /**
        * \brief Copy constructor.
        */
        StateTree2Graphml(const StateTree2Graphml& orig);

        /**
        * \brief operator "=" overloading.
        */
        StateTree2Graphml& operator=(const StateTree2Graphml& node);

        /**
        * \brief Destructor.
        */
        virtual ~StateTree2Graphml();

        /**
        * \brief Converts the given CG to a given named constraint graph .graphml.
        * \param stateFactory         [in] The StateFactory which needs to be convert to .grpahml.
        * \param cfgFactory           [in] The CFGFactory which needs to be convert to .grpahml.
        * \param graphOutputName      [in] The graphml file output name.
        * \param printer              [in] Optional printer that can convert node to something else.
        */
        void convertStateTree2Graphml(StateFactory& stateFactory, const columbus::cfg::CFGFactory& cfgFactory, const std::string &graphOutputName, columbus::cfg::ASGNodePrinter *printer = NULL);

    private:
        void dumpContextNodes(Context *ctx, const columbus::cfg::ICFGid icfgId, const std::string root);
        void dumpContextEdges(Context *ctx);
        void addTreeEdge(EdgesInStateTree& edge);
        unsigned int initICFGandBB(const columbus::cfg::ICFGid icfgId, State *state, const unsigned int parentGraphmlId);
        unsigned int getNextFreeBBId(const columbus::cfg::ICFGid icfgId);
        unsigned int getGraphmlId(const columbus::cfg::ICFGid methodId, const unsigned int BBid, const unsigned int parentGID) const;
        void printState(State *currentState, const unsigned int parentGraphmlId);
        void dumpEdges(State *currentState);
    };

}}

#endif
