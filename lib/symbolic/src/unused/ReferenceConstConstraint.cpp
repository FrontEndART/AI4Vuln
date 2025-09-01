#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    ReferenceConstConstraint::ReferenceConstConstraint(RelationType type, ReferenceSymbol* lSymbol, NodeId rightRefConstId) : Constraint(type), leftSymbol(lSymbol), rightRefConstId(rightRefConstId) {
    }

    ReferenceConstConstraint::~ReferenceConstConstraint() {
    }

}}
