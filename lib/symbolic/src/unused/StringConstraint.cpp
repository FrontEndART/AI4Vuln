#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    StringConstraint::StringConstraint(RelationType type, StringSymbol* lSmybol, StringSymbol* rSymbol) : Constraint(type), leftSymbol(lSmybol), rightSymbol(rSymbol) {
    }

    StringConstraint::~StringConstraint() {
    }

}}
