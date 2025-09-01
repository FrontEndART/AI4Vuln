#include "../../inc/constraint/Z3ConstraintExpression.h"

using namespace columbus;
using namespace symbolic;


Z3ConstraintExpression::Z3ConstraintExpression(const std::string& strRep, NodeId type, bool isComplex) :ConstraintSolverExpr(strRep), type(type), complex(isComplex) {

}

Z3ConstraintExpression::Z3ConstraintExpression(const std::string& strRep, NodeId type, bool isComplex, bool isBitvector) :ConstraintSolverExpr(strRep), type(type), complex(isComplex), bitvector(isBitvector) {

}

Z3ConstraintExpression::Z3ConstraintExpression(NodeId type, bool isComplex) :ConstraintSolverExpr("false"), type(type), complex(isComplex) {

}

bool Z3ConstraintExpression::isComplex()const {
	return complex;
}

bool Z3ConstraintExpression::isBool()const {
	return type == SymbolicTypesPreVisitor::getBooleanTypeId();
}

bool Z3ConstraintExpression::isInt()const {
	return type == SymbolicTypesPreVisitor::getIntTypeId();
}
bool Z3ConstraintExpression::isFloat()const {
	return type == SymbolicTypesPreVisitor::getFloatTypeId();
}
bool Z3ConstraintExpression::isString()const {
	return type == SymbolicTypesPreVisitor::getStringTypeId();
}
bool Z3ConstraintExpression::isDouble()const {
	return type == SymbolicTypesPreVisitor::getDoubleTypeId();
}
bool Z3ConstraintExpression::isLong()const {
	return type == SymbolicTypesPreVisitor::getLongTypeId();
}
bool Z3ConstraintExpression::isShort()const {
	return type == SymbolicTypesPreVisitor::getShortTypeId();
}

bool Z3ConstraintExpression::isByte()const {
	return type == SymbolicTypesPreVisitor::getByteTypeId();;
}

bool Z3ConstraintExpression::isChar()const {
	return type == SymbolicTypesPreVisitor::getCharTypeId();
}

bool Z3ConstraintExpression::isBitvector()const {
	return bitvector;
}

bool Z3ConstraintExpression::isObject()const {
	return type == SymbolicTypesPreVisitor::getObjectTypeId();
}

ConstraintSolverExpr* Z3ConstraintExpression::copy() const {
	return new Z3ConstraintExpression(strRep, type, complex);
}

Z3ConstraintExpressionNegation::Z3ConstraintExpressionNegation(const std::string& strRep, const std::string& originalStrRep, bool negated):
	Z3ConstraintExpression(strRep, SymbolicTypesPreVisitor::getBooleanTypeId(), true), originalStrRep(originalStrRep), negated(negated){

}

const string& Z3ConstraintExpressionNegation::getOriginalStringRep()const {
	return originalStrRep;
}


bool Z3ConstraintExpressionNegation::isIdentifierCondition() const {
	return true;
}

bool Z3ConstraintExpressionNegation::isNegated() const {
	return negated;
}


