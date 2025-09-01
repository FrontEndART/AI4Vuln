#ifndef _REFERENCE_CONST_CONSTRAINT_H_
#define _REFERENCE_CONST_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class ReferenceConstConstraint: public Constraint {
    public:
        ReferenceConstConstraint(RelationType type, ReferenceSymbol* lSymbol, columbus::NodeId rightRefConstId);
        ReferenceConstConstraint(const ReferenceConstConstraint&);
        ReferenceConstConstraint& operator=(const ReferenceConstConstraint&);
        virtual ~ReferenceConstConstraint();

    private:
        ReferenceSymbol* leftSymbol;
        columbus::NodeId rightRefConstId;
    };

}}

#endif
