#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    StringConstConstraint::StringConstConstraint(RelationType type, StringSymbol* lSymbol, std::string rConstValue) : Constraint(type), leftSymbol(lSymbol), rightConstValue (rConstValue) {
    }

    StringConstConstraint::~StringConstConstraint() {
    }

}}
