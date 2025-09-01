#include <iomanip>
#include <iterator>
#include <utility>
#include "java/inc/java.h"
#include "../../inc/constraint/Z3Solver.h"
#include "../../inc/constraint/Z3ConstraintExpression.h"
#include <z3++.h>
#include "../../inc//SMTFunctionStrings.h"


//#include <symbolic/inc/structure/ProxyTree.h>
//#include <symbolic/inc/structure/ProxyTree.hpp>


using namespace std;

namespace columbus { namespace symbolic {

Z3Solver::Z3Solver(const string& name): ConstraintSolver(name) {
}
//todo -> ne set legyen
std::string Z3Solver::generateVariableDeclarations(const std::set<shared_ptr<ConstraintSolverExpr>>& variables) const {
	string declarations;
	declarations += SMT_REMAINDER_OP_DEF_ALL;																		// <--- NEEDED TO TEST % OP
	for (auto expr : variables) {
		if (expr->isIdentifierCondition()) {
			continue;
			//Z3ConstraintExpressionNegation* negExpr = dynamic_cast<Z3ConstraintExpressionNegation*>(expr);
			//declarations += "(declare-fun " + expr->getStrRep() + " () Bool ( not " + negExpr->getOriginalStringRep() + " ))";
		}
		const Z3ConstraintExpression* castedExpr = dynamic_cast<const Z3ConstraintExpression*>(expr.get());
		if (castedExpr->isInt() || castedExpr->isShort() || castedExpr->isLong()|| castedExpr->isByte() || castedExpr->isObject()) {
			declarations += "(declare-fun " + expr->getStrRep() + " () Int)";
		}
		else if (castedExpr->isFloat() || castedExpr->isDouble()) {
			declarations += "(declare-fun " + expr->getStrRep() + " () Real)";
		}
		else if (castedExpr->isBool()) {
			declarations += "(declare-fun " + expr->getStrRep() + " () Bool)";
		}
		else if (castedExpr->isString()) {
			declarations += "(declare-fun " + expr->getStrRep() + " () String)";
		}
		
	}
	for (auto expr : variables) {
		if (expr->isIdentifierCondition()) {
			const Z3ConstraintExpressionNegation* negExpr = dynamic_cast<Z3ConstraintExpressionNegation*>(expr.get());
			if (negExpr->isNegated()) {
				declarations += "(define-fun " + expr->getStrRep() + " () Bool ( not " + negExpr->getOriginalStringRep() + " ))";
			}
			else {
				declarations += "(define-fun " + expr->getStrRep() + " () Bool " + negExpr->getOriginalStringRep() + " )";
			}
			
		}

	}
	return declarations;
}

string wrapConstraint(const string& constraint) {
	//return "(assert (" + constraint + "))";
	return constraint;
}

Solution Z3Solver::solve(const string& str, const std::set<shared_ptr<ConstraintSolverExpr>>& variables) const{
	if (str.empty()) {
		return Solution(true, false, false, false);
	}
	z3::context c;
	z3::solver s(c);
	z3::params p(c);
	p.set(":timeout", 10000u);
	s.set(p);
	string declarations;
	try {
		declarations = generateVariableDeclarations(variables);
		declarations += wrapConstraint(str);
		cout << declarations << endl;
		s.from_string(declarations.c_str());
		
		if (s.check() == z3::sat) {
			cout << "SAT" << endl;
			return Solution(true, false, false, false);
		}
		else if (s.check() == z3::unsat) {
			cout << "UNSAT" << endl;
			return Solution(false, false, false, false);
		}
		else if (s.check() == z3::unknown) {
			cout << "Timeout from Z3" << endl;
			return Solution(false, false, true, false);
		}
		cout << "This shouldn't happen..." << endl;
		return Solution(false, false, false, true);

	}
	catch (const z3::exception& ex) {
		cout << "EXCEPTION!!" << endl;
		return Solution(false, false, false, true);
	}

	return Solution(false, false, false, true); //should not happen
	
}



}}
