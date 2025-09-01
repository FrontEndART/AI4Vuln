#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    ReferenceConstraint::ReferenceConstraint(RelationType type, ReferenceSymbol* lSymbol, ReferenceSymbol* rSymbol) : Constraint(type), leftSymbol(lSymbol), rightSymbol(rSymbol) {
    }

    ReferenceConstraint::~ReferenceConstraint() {
    }

}}
