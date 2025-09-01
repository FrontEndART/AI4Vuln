#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    NumericConstConstraint::NumericConstConstraint(RelationType type, NumericSymbol* lSymbol, NodeId rConstId) : Constraint(type), leftSymbol(lSymbol), rightConstId(rConstId) {
    }

    NumericConstConstraint::~NumericConstConstraint() {
    }

}}
