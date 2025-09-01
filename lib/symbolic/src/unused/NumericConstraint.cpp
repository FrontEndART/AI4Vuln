#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    NumericConstraint::NumericConstraint(RelationType type, NumericSymbol* lSymbol, NumericSymbol* rSymbol) : Constraint(type), leftSymbol(lSymbol), rightSymbol(rSymbol) {
    }

    NumericConstraint::~NumericConstraint() {
    }

}}
