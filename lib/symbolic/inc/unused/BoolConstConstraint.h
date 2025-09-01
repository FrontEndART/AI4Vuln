#ifndef _BOOL_CONST_CONSTRAINT_H_
#define _BOOL_CONST_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class BoolConstConstraint: public Constraint {
    public:
        BoolConstConstraint(RelationType type, BoolSymbol* lSymbol, bool rConstValue);
        BoolConstConstraint(const BoolConstConstraint&);
        BoolConstConstraint& operator=(const BoolConstConstraint&);
        virtual ~BoolConstConstraint();

    private:
        BoolSymbol* leftSymbol;
        bool rigthConstValue;
    };

}}

#endif
