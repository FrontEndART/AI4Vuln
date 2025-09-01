#ifndef _CFG_ALGORITHMCDG_H
#define _CFG_ALGORITHMCDG_H

#include "cfg/inc/cfg.h"


namespace columbus {  namespace cfg {
    /**
    * \brief AlgorithmCDG class is responsible for the control dependence relation computations of each method and theirs blocks stored by the cfgFactory. 
    */
    class BasicBlockLess{
        
    public:
        bool operator()(const BasicBlock* left, const BasicBlock* right) const {
            unsigned int leftId;
            unsigned int rightId;
            if (left == 0)
                leftId = 0;
            else
                leftId = left->getBlockId();

            if(right == 0)
                rightId = 0;
            else
                rightId = right->getBlockId();

            return leftId < rightId;
        } 
    };

  class AlgorithmCDG {
    private:
      /**
      * \brief CFGFactory stores the appropriate basic block information for control dependence computations.
      */
      CFGFactory &cfgFactory;

      /**
      * \brief Map for the computed control relations. Once we have computed dependence information of a method, we strore the results. 
      */
      std::map <NodeId, std::map <const BasicBlock*, const BasicBlock*> > controlDependence;

      /**
      * \brief Auxiliary variables for control dependence computation.
      */
      std::map <const BasicBlock*, std::set <const BasicBlock*> > succ, pred, bucket;
      std::map<const BasicBlock*, const BasicBlock*> parent, label, ancestor, child, idom;
      std::map<const BasicBlock*, int> dfn, sdno, size;
      std::vector<const BasicBlock*> ndfs;
      int counter;

      /**
      * \brief Auxiliary methods for control dependence computation based on the dominance algorithm of Lengauer and Tarjan.
      */
      void link(const BasicBlock*, const BasicBlock*);
      const BasicBlock* eval(const BasicBlock*);
      void compress(const BasicBlock*);
      void DFS(const BasicBlock*);
      void computeCDG(NodeId, std::map <const BasicBlock*, const BasicBlock*>&);

      /**
      * \brief init methods of postdominance and dominance computation.
      */
      void initSuccForCDG(NodeId function);
      void initSucc(NodeId function);

      /**
      * \brief entry method of the dominance and postdominance computation. Based on the initialization we can compute dominance or postdominance relations.
      */
      void computeIdom(NodeId function);
    public:
      /**
      * \brief clearContainers clears all temporarly created containers. Without the clear operation we can achive the post  dominance information after the control dependence computation.
      */
      void clearContainers();
      AlgorithmCDG(CFGFactory& cfgFactory) : cfgFactory(cfgFactory), controlDependence(), succ(), pred(), bucket(), parent(), label(), ancestor(), child(), idom(), dfn(), sdno(), size(), ndfs(), counter(0) {}

      /**
      * Entry point of control dependence computation.
      */
      const std::map <const BasicBlock*, const BasicBlock*>& getCDG(NodeId function);

      /**
      * \brief Entry point of dominance computation if the temporarly containers are empty. Otherway it gives back the post dominance information computed by the last getCDG calls.
      */
      const std::map <const BasicBlock*, const BasicBlock*>& getIdom(NodeId function);

      /**
      * \brief If func parameter is given, it computes the control dependence information of the selected function, otherway it computes the control dependence of functions stored by the cfgFactory.
      */
      void run(NodeId func=0);
  };
}}

#endif
