#ifndef _NUMERIC_CONSTRAINT_H_
#define _NUMERIC_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class NumericConstraint: public Constraint {
    public:
        NumericConstraint(RelationType type, NumericSymbol* leftSymbol, NumericSymbol* rSymbol);
        NumericConstraint(const NumericConstraint&);
        NumericConstraint& operator=(const NumericConstraint&);
        virtual ~NumericConstraint();

    private:
        NumericSymbol* leftSymbol;
        NumericSymbol* rightSymbol;
    };

}}

#endif
