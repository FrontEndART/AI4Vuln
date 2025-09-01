#ifndef _BOOL_CONSTRAINT_H_
#define _BOOL_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class BoolConstraint: public Constraint {
    public:
        BoolConstraint(RelationType type, BoolSymbol* lSymbol, BoolSymbol* rSymbol);
        BoolConstraint(const BoolConstraint&);
        BoolConstraint& operator=(const BoolConstraint&);
        virtual ~BoolConstraint();

    private:
        BoolSymbol* leftSymbol;
        BoolSymbol* rightSymbol;
    };

}}

#endif
