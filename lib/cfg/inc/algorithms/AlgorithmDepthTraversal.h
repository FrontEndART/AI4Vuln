#ifndef _ALGORITHMDEPTHTRAVERSAL_H
#define _ALGORITHMDEPTHTRAVERSAL_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    /**
     * \brief Depth Traversal algorithm for CFG. 
     */
    class AlgorithmDepthTraversal{
    public:
        /**
         * \brief Visitor class to store the leave numbers.
         */
        class LeaveNumberVisitor : public VisitorBasicBlock {
        private:
            std::vector<unsigned int>& blockVisitLeaveNumbers;

        public:
            LeaveNumberVisitor(std::vector<unsigned int>& blockVisitLeaveNumbers) : blockVisitLeaveNumbers(blockVisitLeaveNumbers) {}

            ~LeaveNumberVisitor(){}

            void visit(const BasicBlock* basicBlock){}

            void visitEnd(const BasicBlock* basicBlock){
                if(basicBlock != NULL && !basicBlock->isEntryBlock() && !basicBlock->isExitBlock())
                    blockVisitLeaveNumbers.push_back(basicBlock->getBlockId());
            }

        };

        private:
        /**
         * \brief Pointer to the visitor, which visit and visitEnd methods will be called for each block.
         */
        VisitorBasicBlock *visitor;

        /**
         * \brief The container, that contains the already visited blocks, to prevent the infinite recursion.
         */
        std::set<const BasicBlock*> visitedBlocks;


        /**
         * \brief Recursive travel function, to travel the nodes through the control out edges.
         * \param basicBlock    [in] The BasicBlock through the depth travel goes.
         */
        void travelControlEdges(const BasicBlock* basicBlock);
    public:
        /**
         * \internal
         * \brief Constructor that initializes the visitedBlocks container and the visitor pointer with NULL.
         */
        AlgorithmDepthTraversal();
        AlgorithmDepthTraversal(const AlgorithmDepthTraversal& algorithmDepthTraversal);
        AlgorithmDepthTraversal& operator=(const AlgorithmDepthTraversal& algorithmDepthTraversal);

        /**
         * \brief Starts the depth travel from the given method Id's ICFG's EntryBlock.
         * \param cfgFactory    [in] The CFGFactory which given ICFG needs to be travel.
         * \param visitor       [in] The visitor which visit and visitEnd methods will be called.
         * \param methodId      [in] The method Id which indexes an ICFG.
         */
        void run(columbus::cfg::CFGFactory& cfgFactory, VisitorBasicBlock *visitor, const columbus::cfg::ICFGid methodId, const unsigned int blockId = 0);

        /**
         * \brief Starts the depth travel from the given nodeId's BasicBlock that contains the nodeId.
         * \param cfgFactory    [in] The CFGFactory which given ICFG needs to be travel.
         * \param visitor       [in] The visitor which visit and visitEnd methods will be called.
         * \param methodId      [in] The method Id which indexes an ICFG.
         */
        void run(columbus::cfg::CFGFactory& cfgFactory, VisitorBasicBlock &visitor, const columbus::NodeId nodeId);


    };

}}

#endif