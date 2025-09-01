#ifndef _CFG2GRAPHML_H
#define _CFG2GRAPHML_H

#include "cfg/inc/cfg.h"
#include <io/inc/GraphmlIO.h>

namespace columbus {  namespace cfg {

    class CFG2Graphml{
    private:
        /**
         * \brief Struct definition for edges to store source node, target node and the label. 
         */
        struct EdgesInCFG{
            std::string source;
            std::string target;
            std::string label;
        };

        /**
         * \brief The GraphmlIO pointer that will point to a GraphmlIO, that can write elements into the graphml. 
         */
        io::GraphmlIO *graphmlIO;

        /**
         * \brief \internal Storage for the EdgesInCFG structs, that stores control edge informations. 
         */
        std::vector<EdgesInCFG> controlEdgesInCFG;

        /**
         * \brief \internal Storage for the EdgesInCFG structs, that stores call edge informations. 
         */
        std::vector<EdgesInCFG> callEdgesInCFG;
    public:
        CFG2Graphml();
        ~CFG2Graphml();
        CFG2Graphml(const CFG2Graphml& cfg2Graphml);
        CFG2Graphml& operator=(const CFG2Graphml& cfg2Graphml);

        /**
         * \brief Converts the given CFG to a given named control flow graph .graphml.
         * \param cfgFactory            [in] The CFGFactory which needs to be convert to .grpahml.
         * \param cfgGraphOutputName    [in] The graphml file output name.
         * \param print                 [in] Optional printer that can convert node and method ids to something else.
         * \param printNodeInformation  [in] Nodes information appearance
         */
        void convertCFG2Graphml(const CFGFactory& cfgFactory, const std::string &cfgGraphOutputName, ASGNodePrinter* print = NULL, bool printNodeInformation = true);

        /**
         * \brief Converts the subgraph within a given distance around a basic block of the given CFG to a named control flow graph .graphml.
         * \param cfgFactory            [in] The CFGFactory which part is needed to be convert to .grpahml.
         * \param cfgGraphOutputName    [in] The name of the graphml output file.
         * \param startNode             [in] Pointer to the basic block from which the conversion starts.
         * \param distance              [in] The maximum distance within the nodes will be converted.
         * \param forward               [in] The forward edges are taken into account during the conversion.
         * \param backward              [in] The backward edges are taken into account during the conversion.
         * \param printNodeInformation  [in] Nodes information appearance
         */
        void convertCFG2Graphml(const CFGFactory& cfgFactory, const std::string &cfgGraphOutputName, const BasicBlock* startNode, unsigned distance = 3, bool forward = false, bool backward = true, ASGNodePrinter* print = NULL, bool printNodeInformation = true, const std::set<ICFGid>& icfgConstraint = std::set<ICFGid>());

        /**
         * \brief Converts the given CFG to a given named call graph .graphml.
         * \param cfgFactory            [in] The CFGFactory which needs to be convert to .grpahml.
         * \param cfgGraphOutputName    [in] The call graph graphml file output name.
         * \param print                 [in] Optional printer that can convert method ids to something else.
         */
        void convertCFG2CallGraphml(const CFGFactory& cfgFactory, const std::string &callGraphOutputName, ASGNodePrinter* print = NULL);
    };

}}


#endif