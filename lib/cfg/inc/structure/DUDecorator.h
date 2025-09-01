#ifndef _DUDECORATOR_H
#define _DUDECORATOR_H

namespace columbus {  namespace cfg {

class DUDecorator{
public:
    virtual ~DUDecorator() {}
    virtual void init(const BasicBlock*) = 0;
    virtual bool meet(const BasicBlock*) = 0;
    virtual void flow(const BasicBlock*) = 0;
};

}}


#endif
