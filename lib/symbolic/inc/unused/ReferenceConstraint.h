#ifndef _REFERENCE_CONSTRAINT_H_
#define _REFERENCE_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class ReferenceConstraint : public Constraint {
    public:
        ReferenceConstraint(RelationType type, ReferenceSymbol* lSymbol, ReferenceSymbol* rSymbol);
        ReferenceConstraint(const ReferenceConstraint&);
        ReferenceConstraint& operator=(const ReferenceConstraint&);
        virtual ~ReferenceConstraint();

    private:
        ReferenceSymbol* leftSymbol;
        ReferenceSymbol* rightSymbol;
    };

}}

#endif
