#ifndef _ALGORITHMICCFG_H
#define _ALGORITHMICCFG_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    class AlgorithmICCFG{
    private:
        /**
         * \brief Gets the ICCFG component block that contains the parameter toBlock from the original ICFG.
         * \param toBlock                       [in] The block what we are looking for.
         * \param iccfg                         [in] The ICCFG, that contains the component block.
         * \param icfg                          [in] The ICFG that contains the original blocks.
         * \param blocksInComponentsContainer   [in] The map, that contains the component, contained blocks pairs.
         * \return Pointer to the component BasickBlock in the ICCFG.
         */
        BasicBlock* getComponent(const BasicBlock* toBlock, const ICFG* iccfg, const ICFG* icfg, const std::map<unsigned int, std::vector<unsigned int> >& blocksInComponentsContainer) const;

        /**
         * \brief Produces a transposed ICFG graph from the given parameter icfg and stores it in the parameter CFGFactory.
         * \param icfg                          [in] The block what we are looking for.
         * \param transposedCFGFactory          [out] The CFGFactory, that will contain the transposed ICFG.
         */
        void getTransposedICFG(const ICFG* icfg, CFGFactory &transposedCFGFactory);
    public:
		AlgorithmICCFG(){};
        AlgorithmICCFG(const AlgorithmICCFG& iccfgAlg);
        AlgorithmICCFG& operator=(const AlgorithmICCFG& iccfgAlg);

        /**
         * \brief Produces the ICCFG CFGFactory.
         * \param cfgFactory                    [in] The original CFGFactory which ICFGs needs to be converted to ICCFGs.
         * \param iccfgFactory                  [out] The CFGFactory, with the result ICCFGs.
         * \param asgNamedString                [in] An ASGNodePrinter printer to convert the block id-s, if that is not given then te default printer will be used.
         */
        void createICCFG(CFGFactory& cfgFactory, CFGFactory &iccfgFactory, const ASGNodePrinter* asgNamedString = NULL);

    };


}}

#endif