#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    BoolConstConstraint::BoolConstConstraint(RelationType type, BoolSymbol* lSymbol, bool rConstValue) : Constraint(type), leftSymbol(lSymbol), rigthConstValue(rConstValue) {
    }

    BoolConstConstraint::~BoolConstConstraint() {
    }

}}
