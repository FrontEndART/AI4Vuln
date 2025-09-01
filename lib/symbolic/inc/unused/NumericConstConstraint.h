#ifndef _NUMERIC_CONST_CONSTRAINT_H_
#define _NUMERIC_CONST_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class NumericConstConstraint : public Constraint {
    public:
        NumericConstConstraint(RelationType type, NumericSymbol* lSymbol, columbus::NodeId rConstId);
        NumericConstConstraint(const NumericConstConstraint&);
        NumericConstConstraint& operator=(const NumericConstConstraint&);
        virtual ~NumericConstConstraint();

    private:
        NumericSymbol* leftSymbol;
        columbus::NodeId rightConstId;
    };

}}

#endif
