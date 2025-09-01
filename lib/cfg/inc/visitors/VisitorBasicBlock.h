#ifndef _BASICBLOCKVISITOR_H
#define _BASICBLOCKVISITOR_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    /**
     * \brief CFG visitor that can be used with trave algorithms to call visit and visitEnd methods by entering and leaving a node. 
     */
    class VisitorBasicBlock{
    public:
        virtual ~VisitorBasicBlock();
        virtual void visit(const BasicBlock*);
        virtual void visitEnd(const BasicBlock*);
    };

}}

#endif