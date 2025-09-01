#ifndef _ALGORITHMITERATIVETRAVERSAL_H
#define _ALGORITHMITERATIVETRAVERSAL_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    class AlgorithmIterativeTraversal{
    private:
        /**
         * \brief The block node worklist, which blocks needs to be meet. 
         */
        std::vector<const BasicBlock*> workList;
    public:
        /**
         * \brief Default constructor
         */
        AlgorithmIterativeTraversal() : workList() {}

        /**
         * \brief Starts the iterative data-flow analysis from the given EntryBlock in parent ICFG.
         * \param cfgFactory    [in] The CFGFactory which reaching definitions needs to be calculate.
         * \param duDecorator   [in] The DUDecorator which meet function needs to be call and determine if the actualy analysed block's children needs to put to the worklist.
         * \param entryBlock    [in] The EntryBlock which parent ICFG's blocks needs to be analyse.
         */
        void run(columbus::cfg::CFGFactory& cfgFactory, DUDecorator &duDecorator, EntryBlock *entryBlock);
    };

}}

#endif
