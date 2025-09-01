#ifndef _STIRNG_CONSTRAINT_H_
#define _STIRNG_CONSTRAINT_H_

#include "../constraint/Constraint.h"
#include "../definition/Symbol.h"

namespace columbus { namespace symbolic {

    class StringConstraint: public Constraint {
    public:
        StringConstraint(RelationType type, StringSymbol* lSmybol, StringSymbol* rSymbol);
        virtual ~StringConstraint();
        StringConstraint(const StringConstraint&);
        StringConstraint& operator=(const StringConstraint&);

    private:
        StringSymbol* leftSymbol;
        StringSymbol* rightSymbol;
    };

}}

#endif
