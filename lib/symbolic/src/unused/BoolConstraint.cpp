#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    BoolConstraint::BoolConstraint(RelationType type, BoolSymbol* lSymbol, BoolSymbol* rSymbol) : Constraint(type), leftSymbol(lSymbol), rightSymbol(rSymbol) {
    }

    BoolConstraint::~BoolConstraint() {
    }

}}
