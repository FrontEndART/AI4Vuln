#include "../../inc/constraint/Z3Constraint.h"
#include "../../inc/constraint/Z3ConstraintExpression.h"

using namespace columbus;
using namespace symbolic;

Z3Constraint::Z3Constraint(const Z3ConstraintExpression& expr): Constraint(), Z3Expr(expr) {
}

Z3Constraint::Z3Constraint(const Z3Constraint& other) : Constraint(other), Z3Expr(other.Z3Expr) {
}

Z3Constraint::~Z3Constraint() {
}

/*Z3Constraint::operator BoolVar () {
    assert(Z3Expr.isBoolVar());
    return Z3Expr.getBoolVar();
}

SymbolIdentifierSet Z3Constraint::getSymbolIdentifiers() const {
    SymbolIdentifierSet idSet;
    for (Z3IntSymbolMap::const_iterator it = getIntSymbols().begin(); it != getIntSymbols().end(); ++it) {
        idSet.insert(it->first);
    }
    for (Z3BoolSymbolMap::const_iterator it = getBoolSymbols().begin(); it != getBoolSymbols().end(); ++it) {
        idSet.insert(it->first);
    }
    for (Z3FloatSymbolMap::const_iterator it = getFloatSymbols().begin(); it != getFloatSymbols().end(); ++it) {
        idSet.insert(it->first);
    }
    return idSet;
}*/

