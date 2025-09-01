#include "../../inc/constraint/Z3ConstraintBuilder.h"
#include "../../inc/constraint/Z3Constraint.h"
#include "../../inc/constraint/Z3ConstraintExpression.h"
#include <common/inc/WriteMessage.h>
#include "../../inc/messages.h"
#include "../../inc/SMTFunctionStrings.h"


using namespace columbus;
using namespace symbolic;
using namespace columbus::java::asg;

shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeIntValue(const int value){ 
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getIntTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeLongValue(const long value){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getLongTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeShortValue(const short value){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getShortTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeByteValue(const char value){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getByteTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeStringValue(const string value) {
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(value, SymbolicTypesPreVisitor::getStringTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeCharValue(const wchar_t value){ 
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getIntTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeBoolValue(const bool value){
    string rep = value ? "true" : "false";
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(rep, SymbolicTypesPreVisitor::getBooleanTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeFloatValue(const float value){
    //int alapján
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getFloatTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeDoubleValue(const double value){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getDoubleTypeId(), false);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeReferenceValue(const unsigned long value){ 
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(to_string(value), SymbolicTypesPreVisitor::getObjectTypeId(), false);
    return expr;
} 

shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeIntVar(const string& addr){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getIntTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeLongVar(const string& addr){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getLongTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeShortVar(const string& addr){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getShortTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeByteVar(const string& addr){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getByteTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeCharVar(const string& addr){
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getShortTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}


shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeConditionalExpr(const Definition& def, bool negated) {
    const NegatedSymbolDefinition& ndef = dynamic_cast<const NegatedSymbolDefinition&>(def);
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpressionNegation>(ndef, *ndef.getOriginal(), negated);
    engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), expr);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeBoolVar(const string& addr){
	shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getBooleanTypeId(), false);
    engine->getCurrentState().addVariable(expr);
	return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeStringVar(const string& addr) {
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getStringTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeFloatVar(const string& addr){
    //int alapján
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getFloatTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeDoubleVar(const string& addr) {
    //int alapján
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getDoubleTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}
shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeReferenceVar(const string& addr){ 
    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(addr, SymbolicTypesPreVisitor::getObjectTypeId(), false);
    engine->getCurrentState().addVariable(expr);
    return expr;
}

Constraint* Z3ConstraintBuilder::makeConstraint(shared_ptr<ConstraintSolverExpr> expr) {
    if (expr == nullptr)
    {
        throw SymbolicColumbusException("Empty constraint expression");
    }
    const Z3ConstraintExpression& z3Expr = dynamic_cast<const  Z3ConstraintExpression&>(*expr.get());
    //return make_shared<Z3ConstraintExpression>(expr);
    if (z3Expr.isBool()) {
        Z3Constraint* copiedZ3 = new Z3Constraint(z3Expr);
        engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), expr);
        return copiedZ3;
    }
    throw SymbolicColumbusException("Cannot make constraint from a non-bool expression.");
}
Constraint* Z3ConstraintBuilder::makeNegatedConstraint(shared_ptr<ConstraintSolverExpr> expr){ 
    const Z3ConstraintExpression& z3Expr = dynamic_cast<const  Z3ConstraintExpression&>(*expr.get());
    
    auto convertConstraint = [](const string& con) {
        if (find(con.begin(), con.end(), ' ') != con.end()) {
            string result("(");
            result += con + ")";
            return result;
        }
        return con;
    };

    if (z3Expr.isBool()) {
        engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), make_shared<Z3ConstraintExpression>("not (" + expr->getStrRep() + ")"));
        return new Z3Constraint(Z3ConstraintExpression("not " + convertConstraint(expr->getStrRep()), SymbolicTypesPreVisitor::getBooleanTypeId(), true));
    }
    throw SymbolicColumbusException("Cannot make constraint from a non-bool expression.");
    
}

/** Creates the dependency list of the two sides */
ConstraintSet Z3ConstraintBuilder::makeDependencies(const Definition &left, const Definition &right){ 
    ConstraintSet deps;

    // gather the existing dependencies from left and right
    for (ConstraintSet::const_iterator it = left.getGatherdDependencies().begin(); it != left.getGatherdDependencies().end(); ++it) {
        const Z3Constraint* z3Constraint = dynamic_cast<const Z3Constraint*>(*it);
        deps.insert(new Z3Constraint(*z3Constraint)); // make a copy
    }
   
    
    for (ConstraintSet::const_iterator it = right.getGatherdDependencies().begin(); it != right.getGatherdDependencies().end(); ++it) {
        Z3Constraint* z3Constraint = dynamic_cast<Z3Constraint*>(*it);
        deps.insert(new Z3Constraint(*z3Constraint)); // make a copy
    }
    engine->getCurrentState().setLastBuildDependencies(engine->getExecutor()->getCurrentNodeId(), deps);
    return deps;
}


/** Make a (hard)copy of the dependency list of the operand. */
ConstraintSet Z3ConstraintBuilder::makeDependencies(const Definition &operand){ 
    ConstraintSet deps;

    // gather the existing dependencies from left and right
    for (ConstraintSet::const_iterator it = operand.getGatherdDependencies().begin(); it != operand.getGatherdDependencies().end(); ++it) {
        const Z3Constraint* z3Constraint = dynamic_cast<const Z3Constraint*>(*it);
        deps.insert( new Z3Constraint(*z3Constraint)); // make a copy
    }
    engine->getCurrentState().setLastBuildDependencies(engine->getExecutor()->getCurrentNodeId(), deps);
    return deps;
}

ConstraintSet Z3ConstraintBuilder::makeDependenciesSimple(const Definition& operand) {
    ConstraintSet deps;

    // gather the existing dependencies from left and right
    for (ConstraintSet::const_iterator it = operand.getGatherdDependencies().begin(); it != operand.getGatherdDependencies().end(); ++it) {
        const Z3Constraint* z3Constraint = dynamic_cast<const Z3Constraint*>(*it);
        deps.insert(new Z3Constraint(*z3Constraint)); // make a copy
    }
    return deps;
}

/**
 * Determines that the constraint building currently supports the given type.
 */
bool Z3ConstraintBuilder::isTypeHandled(NodeId type){ return false;}

std::string Z3ConstraintBuilder::operatorToString(const InfixOperatorKind op) {
    switch (op) {
    case iokBitwiseAndLogicalAnd:   return "bvand";
    case iokBitwiseAndLogicalOr:    return "bvor";
    case iokBitwiseAndLogicalXor:   return "bvxor";
    case iokConditionalAnd:         return "&&";
    case iokConditionalOr:          return "||";
    case iokDivide:                 return "/";
    case iokEqualTo:                return "="; //smt2lib-ben az "egyenlo" a = az == helyett
    case iokGreaterThan:            return ">";
    case iokGreaterThanOrEqualTo:   return ">=";
    case iokLAST:                   return "";
    case iokLeftShift:              return "bvshl";
    case iokLessThan:               return "<";
    case iokLessThanOrEqualTo:      return "<=";
    case iokMinus:                  return "-";
    case iokNotEqualTo:             return "="; // negálva lesz
    case iokPlus:                   return "+";
    case iokRemainder:              return "%";
    case iokSignedRightShift:       return "bvashr";
    case iokTimes:                  return "*";
    case iokUnsignedRightShift:     return "bvlshr"; //TODO: smt-ben talan ez?
    default: throw SymbolicColumbusException("unknown operator");
    }
}

std::string Z3ConstraintBuilder::operatorToString(const PrefixOperatorKind op) {
    switch (op) {
    case peokComplement:  return "~";
    case peokDecrement:   return "--";
    case peokIncrement:   return "++";
    case peokMinus:       return "-";
    case peokPlus:        return "+";
    case peokNot:         return "!";
    default: throw SymbolicColumbusException("unknown operator");
    }
}

shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeNumericExpr(const Definition& left, const Definition& right, const InfixOperatorKind op, columbus::NodeId expressionType) {
    const Z3ConstraintExpression* exprLeft = dynamic_cast<Z3ConstraintExpression*>(left.getCsExpr().get());
    const Z3ConstraintExpression* exprRight = dynamic_cast<Z3ConstraintExpression*>(right.getCsExpr().get());

    stringstream ss;
    ss << operatorToString(op);
    bool isBitwiseOp = 
        op == iokBitwiseAndLogicalAnd ||
        op == iokBitwiseAndLogicalOr  ||
        op == iokBitwiseAndLogicalXor ||
        op == iokSignedRightShift     ||
        op == iokUnsignedRightShift   ||
        op == iokLeftShift;
    string strR = exprRight->getStrRep(), strL = exprLeft->getStrRep();
    if (exprRight->getStrRep().compare("true")==0 || exprRight->getStrRep().compare("false")==0) {
        strR = std::string(1, exprRight->getStrRep() == "true" ? '0' : '1');
    }
    if (exprLeft->getStrRep().compare("true")==0 || exprLeft->getStrRep().compare("false")==0) {
        strL = std::string(1, exprLeft->getStrRep() == "true" ? '0' : '1');
    }
    if (strR.find(" ") != string::npos) {
        strR = "( " + strR + " )";
    }

    if (strL.find(" ") != string::npos) {
        strL = "( " + strL + " )";
    }
    if (isBitwiseOp) {
        ss << "((_ int2bv 8) " << exprLeft->getStrRep() << ")" << " ((_ int2bv 8) " << exprRight->getStrRep() << ")"; //TODO bitand utan sima egyenloseg eseten a szamot is kovertalni kell bv-ra (vagy a bv-t vissza)
    }
    else if (op == iokRemainder) {
        if ((exprLeft->isDouble() || exprLeft->isFloat()) && (exprRight->isShort() || exprRight->isLong() || exprRight->isInt() || exprRight->isByte() || exprRight->isChar()|| exprRight->isShort())){
            ss << "ri"  << " " << strL << " " << strR;
        }
        if ((exprLeft->isDouble() || exprLeft->isFloat()) && (exprRight->isDouble() || exprRight->isFloat())) {
            ss << "rr" << " " << strL << " " << strR;
        }
        if ((exprLeft->isLong() || exprLeft->isInt() || exprLeft->isByte() || exprLeft->isChar() || exprLeft->isShort())&& (exprRight->isLong() || exprRight->isInt() || exprRight->isByte() || exprRight->isChar()|| exprRight->isShort())) {
            ss << " " << strL << " " << strR; //int%int is not changed
        }
        if ((exprLeft->isLong() || exprLeft->isInt() || exprLeft->isByte() || exprLeft->isChar() || exprLeft->isShort()) && (exprRight->isDouble() || exprRight->isFloat())) {
            ss << "ir" << " " << strL << " " << strR;
        }
    }
    else {
        ss << " " << strL << " " << strR;
    }

    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(ss.str(), expressionType, true, isBitwiseOp);

    engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), expr);
    return expr;
}

shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeNumericExpr(const Definition& operand, const java::asg::PrefixOperatorKind op) {
    const Z3ConstraintExpression* ex = dynamic_cast<Z3ConstraintExpression*>(operand.getCsExpr().get());

    stringstream ss;
    ss << operatorToString(op);
    ss << " " << ex->getStrRep();

    shared_ptr<Z3ConstraintExpression> expr = make_shared<Z3ConstraintExpression>(ss.str(), operand.getType(), true);

    engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), expr);
    return expr;
}


shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeBoolExpr(const Definition& left, const Definition& right, const InfixOperatorKind op, CastTypes cast) {

    //const Z3ConstraintExpression* exprLeft = dynamic_cast<Z3ConstraintExpression*>(left.getCsExpr().get());
    //const Z3ConstraintExpression* exprRight = dynamic_cast<Z3ConstraintExpression*>(right.getCsExpr().get());

    return makeBoolExpr(left.getCsExpr().get(), right.getCsExpr().get(), op, cast);
}

std::shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeBoolExpr(const ConstraintSolverExpr* left, const ConstraintSolverExpr* right, const columbus::java::asg::InfixOperatorKind op, CastTypes cast) {
    auto exprLeft = dynamic_cast<const Z3ConstraintExpression*>(left);
    auto exprRight = dynamic_cast<const Z3ConstraintExpression*>(right);

    if (exprLeft == nullptr || exprRight == nullptr) {
        //TODO hibakezelés
        return nullptr;
    }

    string strL = exprLeft->getStrRep();
    string strR = exprRight->getStrRep();

    if (cast != NONE) {
        if (strR.find(" ") != string::npos) {
            strR = "( " + strR + " )";
        }
        if(cast == TO_INT) {
            strR = "to_int " + strR;
        }
    }

   if (exprRight->isBool() && (!exprLeft->isBool() || strL == "0")) {
        strR = "bool_to_int( " + strR + " )";
    }
    if (exprLeft->isBool() && (!exprRight->isBool() || strR == "0")) {
        strL = "bool_to_int( " + strL + " )";
    }
    

    if (strR.find(" ") != string::npos) {
       strR = "( " + strR + " )";
    }

    if (strL.find(" ") != string::npos) {
       strL = "( " + strL + " )";
    }

    stringstream ss;
    ss << operatorToString(op);
    if (exprLeft && exprRight) {
        if (exprLeft->isBitvector() != exprRight->isBitvector()) {
            if (op == iokGreaterThan || op == iokGreaterThanOrEqualTo || op == iokLessThan || op == iokLessThanOrEqualTo) {
                ss.str("");
                if (op == iokGreaterThan)
                    ss << "bvsgt";
                else if (op == iokGreaterThanOrEqualTo)
                    ss << "bvsge";
                else if (op == iokLessThan)
                    ss << "bvslt";
                else if (op == iokLessThanOrEqualTo)
                    ss << "bvsle";
            }
            if (exprLeft->isBitvector())
                ss << " " << strL << " ((_ int2bv 8) " << strR << ")";
            else
                ss << " ((_ int2bv 8) " << strL << ") " << strR;
        }
        else
            ss << " " << strL << " " << strR;
    } 
    else {
        common::WriteMsg::write(CMSG_SYM_CONST_CREATING_BOOL_EXPRESSION);
        return make_shared<Z3ConstraintExpression>(SymbolicTypesPreVisitor::getBooleanTypeId());
    }
    shared_ptr<ConstraintSolverExpr> expr;
    if (op == iokNotEqualTo) {
        stringstream temp;
        temp << "not ( " << ss.str() << " )";
        expr = make_shared<Z3ConstraintExpression>(temp.str(), SymbolicTypesPreVisitor::getBooleanTypeId(), true);
        /*temp << ss.rdbuf();
        ss.str("");
        ss << " not ( " << temp.rdbuf() << " )";*/
    }
    else {
        expr = make_shared<Z3ConstraintExpression>(ss.str(), SymbolicTypesPreVisitor::getBooleanTypeId(), true);
    }

    /*else {
        throw SymbolicColumbusException("Cannot build expression at makeBoolExpr()");
    }*/
    engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), expr);
    return expr;
}


shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeBoolExpr(const Definition& operand, const java::asg::PrefixOperatorKind op) {
    const Z3ConstraintExpression* exprOp = dynamic_cast<Z3ConstraintExpression*>(operand.getCsExpr().get());

    stringstream ss;
    ss << operatorToString(op);
    if (exprOp) {
        ss << " " << exprOp;
    }
    else {
        common::WriteMsg::write(CMSG_SYM_CONST_CREATING_BOOL_EXPRESSION);
        return make_shared<Z3ConstraintExpression>(SymbolicTypesPreVisitor::getBooleanTypeId());
    }

    shared_ptr<ConstraintSolverExpr> expr = make_shared<Z3ConstraintExpression>(ss.str(), SymbolicTypesPreVisitor::getBooleanTypeId(), true);
    engine->getCurrentState().addConstraintSolverExpr(engine->getExecutor()->getCurrentNodeId(), expr);
    return expr;
}
