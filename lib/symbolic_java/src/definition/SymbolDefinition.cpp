

#include "symbolic_java/inc/definition/SymbolDefinition.h"
#include "symbolic_java/inc/definition/BooleanValueDefinition.h"
#include "symbolic_java/inc/definition/Array.h"
#include "symbolic_java/inc/definition/Reference.h"
#include "symbolic_java/inc/constraint/Z3ConstraintExpression.h"
//#include "symbolic_java/inc/definition/ClassValueDefinition.h"
#include "symbolic/inc/structure/SymbolicCommon.h"
#include "java/inc/java.h"
#include "java/inc/Types.h"

namespace columbus { namespace symbolic {

    using namespace java::asg;

SymbolDefinition::SymbolDefinition(columbus::NodeId _type, const Address& addrs, SymbolicEngine& engine, bool setCsExpr): DefinitionDispatcher<SymbolDefinition>(_type, addrs, engine) {
        m_definitionType = _type;

        if (!setCsExpr) {
            return;
        }
        if (_type == SymbolicTypesPreVisitor::getIntTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeIntVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getBooleanTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeBoolVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getLongTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeLongVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getShortTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeShortVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getByteTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeByteVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getCharTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeCharVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getFloatTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeFloatVar(*this);
        } else if (_type == SymbolicTypesPreVisitor::getDoubleTypeId()) {
            csExpr = engine.getConstraintBuilder()->makeDoubleVar(*this);
        } 
        /*else if (Common::getIsScopedType(type)
            || Common::getIsParameterizedType(typeRef)
            || Common::getIsWildcardType(typeRef)) {
            State& state = engine.getCurrentState();
            Memory& memory = state.getMemory();
            Address refValue = memory.allocate();
            return createReference(refValue, type, engine, true);
        }
        else if (Common::getIsErrorType(typeRef)) {
            // if type is error type, we create symbol with type of Object
            State& state = engine.getCurrentState();
            Memory& memory = state.getMemory();
            Address refValue = memory.allocate();
            return createReference(refValue, SymbolicTypesPreVisitor::getObjectTypeId(), engine, true);
        }*/
        else {
            csExpr = engine.getConstraintBuilder()->makeReferenceVar(*this);
        }

    }

SmartDefinition SymbolDefinition::negate() const {
    if (this->getType() == SymbolicTypesPreVisitor::getBooleanTypeId()) {

        auto negated = DefinitionFactory::createNegatedSymbol(engine, this);
        auto res = engine.getConstraintBuilder()->makeConditionalExpr(*negated.get(), true);
        negated->setCsExpr(res);
        ConstraintSet dependencies = engine.getConstraintBuilder()->makeDependencies(*this);
        negated->setDependencies(dependencies);

        return negated;

    }
    throw SymbolicColumbusException("Negate operation on non boolean value!");
}

SmartDefinition SymbolDefinition::conditionalExpr() const {
    if (this->getType() == SymbolicTypesPreVisitor::getBooleanTypeId()) {

        auto negated = DefinitionFactory::createConditionalSymbol(engine, this);
        auto res = engine.getConstraintBuilder()->makeConditionalExpr(*negated.get(), false);
        negated->setCsExpr(res);
        ConstraintSet dependencies = engine.getConstraintBuilder()->makeDependencies(*this);
        
       // makeBoolValue();
       // dependencies.insert();
        negated->setDependencies(dependencies);

        return negated;

    }
    throw SymbolicColumbusException("Negate operation on non boolean value!");
}

SmartDefinition SymbolDefinition::equalsImpl(const Reference& def) const {
    
    //if (SymbolicTypesPreVisitor::isBoxingType(def.getType())) {
      //  auto val = def.getValue();
    //}
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);

    }

    SymbolDefinition::SymbolDefinition(columbus::NodeId _type, const Address& addrs, SymbolicEngine& engine, shared_ptr<ConstraintSolverExpr> expr, const ConstraintSet& dependencies) : DefinitionDispatcher<SymbolDefinition>(_type, engine) {
        m_definitionType = _type;
        csExpr = expr;
        this->gatherdDependencies = dependencies;
    }

    SymbolDefinition::~SymbolDefinition() {
    }

    std::ostream& SymbolDefinition::print(std::ostream& out) const {
        out << "SymbolDefinition (typeId=" << m_definitionType << ")";
        return out;
    }

    // ~~~~~~~~~~~~~~~~~~~~~IntValueDefinition~~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::lessImpl(const IntValueDefinition& def) const { 
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
    }
    // ~~~~~~~~~~~~~~~~~~~~~IntValueDefinition~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~SymbolDefinition~~~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::lessImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }
    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }
    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }
    
    // ~~~~~~~~~~~~~~~~~~~~~~SymbolDefinition~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~FloatValueDefinition~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::lessImpl(const FloatValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }


    SmartDefinition SymbolDefinition::greaterImpl(const FloatValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const FloatValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }

    // ~~~~~~~~~~~~~~~~~~~~FloatValueDefinition~~~~~~~~~~~~~~~~~~~~  
    // ~~~~~~~~~~~~~~~~~~~~DoubleValueDefinition~~~~~~~~~~~~~~~~~~~~

    //Exception thrown: read access violation this was 0x8.
    SmartDefinition SymbolDefinition::lessImpl(const DoubleValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterImpl(const DoubleValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const DoubleValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }
    // ~~~~~~~~~~~~~~~~~~~~DoubleValueDefinition~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~LongValueDefinition~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::lessImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
    }
    // ~~~~~~~~~~~~~~~~~~~~LongValueDefinition~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~ShortValueDefinition~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::lessImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }


    SmartDefinition SymbolDefinition::greaterImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
    }
    // ~~~~~~~~~~~~~~~~~~~~ShortValueDefinition~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~CharValueDefinition~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::lessImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
    }
    //  ~~~~~~~~~~~~~~~~~~~~CharValueDefinition~~~~~~~~~~~~~~~~~~~~
    //  ~~~~~~~~~~~~~~~~~~~~ByteValueDefinition~~~~~~~~~~~~~~~~~~~~
    SmartDefinition SymbolDefinition::lessImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::equalsImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
    }

    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
    }
    //  ~~~~~~~~~~~~~~~~~~~~ByteValueDefinition~~~~~~~~~~~~~~~~~~~~
#define CONSTRAINT_BUILDING

    SmartDefinition SymbolDefinition::makeSymbolDefinition(const Definition& left, const Definition& right, InfixOperatorKind operation, NodeId type, SymbolicEngine& engine) {

#ifdef CONSTRAINT_BUILDING
        // currently we do not handle Infix operations over reference types, such Integer + int or String + String, but Reference ==  Reference,
        // Reference != Reference handled (boxing, unboxing)

        /*if (!SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) || !SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType())) {
            if (SymbolicTypesPreVisitor::isBoxingType(left.getType())) {

            }
            else if (SymbolicTypesPreVisitor::isBoxingType(right.getType())) {
            }

        }

        if (operation == iokEqualTo || operation == iokNotEqualTo) {
            

            if ((SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) && !SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType()))
                || (!SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) && SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType()))) {
                
                return DefinitionFactory::createSymbol(type, engine);
            }
        }
        else {
            if (!SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) || !SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType())) {
                return DefinitionFactory::createSymbol(type, engine);
            }
        }*/

        ConstraintBuilder* builder = engine.getConstraintBuilder();
        /*if (!builder->isTypeHandled(left.getType()) || !builder->isTypeHandled(right.getType())) { // TODO ez mar nem kell
            //return SmartDefinition(new SymbolDefinition(type));
        }*/

        // which kind of expression have to create
        shared_ptr<ConstraintSolverExpr> csExpr = nullptr;
        if (type == SymbolicTypesPreVisitor::getBooleanTypeId()) {
            csExpr = builder->makeBoolExpr(left, right, operation);
        }
        else {
            csExpr = builder->makeNumericExpr(left, right, operation, type);
        }

        ConstraintSet dependencies = builder->makeDependencies(left, right);
        SmartDefinition symDef = DefinitionFactory::createSymbol(type, engine);
        if(csExpr != nullptr)
            symDef->setCsExpr(csExpr);
        symDef->setDependencies(dependencies);
        return  symDef;
#else
      /*  NodeId stringClassTypeId = SymbolicTypesPreVisitor::getClassType(SymbolicTypesPreVisitor::getStringClassId());
        if (left.getType() == stringClassTypeId || right.getType() == stringClassTypeId)
            return SmartDefinition(new SymbolDefinition(stringClassTypeId));
        else
            return SmartDefinition(new SymbolDefinition(type));
            */
      //  return nullptr;
#endif
        //return nullptr;

    }


    SmartDefinition SymbolDefinition::makeSymbolDefinition(const Definition& operand, PrefixOperatorKind operation, NodeId type, SymbolicEngine& engine) {
#ifdef CONSTRAINT_BUILDING
        // currently we do not handle operations over reference types, such !Boolean, ++Integer  (boxing, unboxing)
        if (!SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(operand.getType())) {
            return DefinitionFactory::createSymbol(type, engine);
        }

        ConstraintBuilder* builder = engine.getConstraintBuilder();
        // which kind of expression have to create
        shared_ptr<ConstraintSolverExpr> csExpr;
        if (type == SymbolicTypesPreVisitor::getBooleanTypeId()) {
            csExpr = builder->makeBoolExpr(operand, operation);
        }
        else {
            csExpr = builder->makeNumericExpr(operand, operation);
        }

        ConstraintSet dependencies = builder->makeDependencies(operand);

        SmartDefinition symDef = DefinitionFactory::createSymbol(type, engine);
        if (csExpr != nullptr)
            symDef->setCsExpr(csExpr);
        symDef->setDependencies(dependencies);
        return  symDef;
#else
        //return SmartDefinition(new SymbolDefinition(type));
        return nullptr;
#endif
    }



    SmartDefinition SymbolDefinition::makeSymbolDefinitionForAssignment(const Definition& left, const Definition& right, AssignmentOperatorKind assignmentType, SymbolicEngine& engine) {
#ifdef CONSTRAINT_BUILDING

        // create the additional equality constraint
        SmartDefinition newLeft = DefinitionFactory::createSymbol(left.getType(), engine); //uj memoriacim

        ConstraintSet dependencies;
        ConstraintBuilder* builder = engine.getConstraintBuilder();
        if (assignmentType == askAssign) {
            // currently we do not handle Integer = int like assignments (boxing, unboxing), so when left is primitive and right is reference or vica versa
            if ((!SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) && SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType()))
                || (SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) && !SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType()))) {
                return newLeft;
            }

            Constraint* assignmentConstraint = engine.getConstraintBuilder()->makeConstraint(engine.getConstraintBuilder()->makeBoolExpr(*newLeft, right, iokEqualTo));
            // union right side dependencies with the new assignmentConstraint
            dependencies = builder->makeDependencies(right);
            dependencies.insert(assignmentConstraint);
        }
        else {
            /*if (!SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(left.getType()) || !SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(right.getType())) {
                return SmartDefinition(new SymbolDefinition(left.getType()));
            }

            SmartDefinition fullRightSide;
            if (assignmentType == askPlusAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokPlus, left.getType()); // TODO a típus így nem jó, nem biztos, hogy left kell
            }
            else if (assignmentType == askMinusAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokMinus, left.getType());
            }
            else if (assignmentType == askTimesAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokTimes, left.getType());
            }
            else if (assignmentType == askDivideAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokDivide, left.getType());
            }
            else if (assignmentType == askRemainderAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokRemainder, left.getType());
            }
            else if (assignmentType == askAndAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokBitwiseAndLogicalAnd, left.getType());
            }
            else if (assignmentType == askOrAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokBitwiseAndLogicalOr, left.getType());
            }
            else if (assignmentType == askXorAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokBitwiseAndLogicalXor, left.getType());
            }
            else if (assignmentType == askLeftShiftAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokLeftShift, left.getType());
            }
            else if (assignmentType == askSignedRightShiftAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokSignedRightShift, left.getType());
            }
            else if (assignmentType == askUnsignedRightShiftAssign) {
                fullRightSide = makeSymbolDefinition(left, right, iokUnsignedRightShift, left.getType());
            }
            Constraint* assignmentConstraint = builder->makeConstraint(*builder->makeBoolExpr(*newLeft, *fullRightSide, iokEqualTo));
            // union right side dependencies with the new assignmentConstraint
            dependencies = builder->makeDependencies(*fullRightSide);
            dependencies.insert(assignmentConstraint);*/
        }
        newLeft->setDependencies(dependencies);
        return newLeft;
#else
       /* NodeId stringClassTypeId = SymbolicTypesPreVisitor::getClassType(SymbolicTypesPreVisitor::getStringClassId());
        if (left.getType() == stringClassTypeId || right.getType() == stringClassTypeId)
            return SmartDefinition(new SymbolDefinition(stringClassTypeId));
        else
            return SmartDefinition(new SymbolDefinition(left.getType()));
            */
        return nullptr;
#endif
    }

    SmartDefinition SymbolDefinition::plusAssignValueImpl(const IntValueDefinition& def) const {
        //return nullptr;
        //return SymbolDefinition::makeSymbolDefinitionForAssignment(def, *this, columbus::java::asg::askPlusAssign, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
        return makeSymbolDefinitionForAssignment(*this, def, askPlusAssign, engine);
    }

    SmartDefinition SymbolDefinition::minusAssignValueImpl(const IntValueDefinition& def) const {
        //return nullptr;
        //return SymbolDefinition::makeSymbolDefinitionForAssignment(def, *this, columbus::java::asg::askPlusAssign, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
        return makeSymbolDefinitionForAssignment(*this, def, askMinusAssign, engine);
    }

    SmartDefinition SymbolDefinition::assignValueImpl(const SymbolDefinition& def) const {
        return makeSymbolDefinitionForAssignment(*this, def, askAssign, engine);
    }


    SmartDefinition SymbolDefinition::plusImpl(const CharValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const ByteValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const ShortValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const IntValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const LongValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);

    }
    SmartDefinition SymbolDefinition::plusImpl(const FloatValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const DoubleValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const Reference& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::plusImpl(const SymbolDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::minusImpl(const CharValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const ByteValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const ShortValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const IntValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const LongValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const FloatValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const DoubleValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const Reference& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::minusImpl(const SymbolDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::timesImpl(const CharValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const ByteValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const ShortValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const IntValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const LongValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const FloatValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const DoubleValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const Reference& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::timesImpl(const SymbolDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::divideImpl(const CharValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const ByteValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const ShortValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const IntValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const LongValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const FloatValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const DoubleValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const Reference& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::divideImpl(const SymbolDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::remainderImpl(const CharValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const ByteValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const ShortValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const IntValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const LongValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const FloatValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const DoubleValueDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const Reference& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::remainderImpl(const SymbolDefinition& def) const { 
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::leftShiftImpl(const CharValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::leftShiftImpl(const ByteValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::leftShiftImpl(const ShortValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::leftShiftImpl(const IntValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::leftShiftImpl(const LongValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    //SmartDefinition SymbolDefinition::leftShiftImpl(const Reference& def) const {
    //    return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    //}
    SmartDefinition SymbolDefinition::leftShiftImpl(const SymbolDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const CharValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const ByteValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const ShortValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const IntValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const LongValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    //SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const Reference& def) const {
    //    return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    //}
    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const SymbolDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    SmartDefinition SymbolDefinition::signedRightShiftImpl(const CharValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::signedRightShiftImpl(const ByteValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::signedRightShiftImpl(const ShortValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::signedRightShiftImpl(const IntValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::signedRightShiftImpl(const LongValueDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    //SmartDefinition SymbolDefinition::signedRightShiftImpl(const Reference& def) const {
    //    return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    //}
    SmartDefinition SymbolDefinition::signedRightShiftImpl(const SymbolDefinition& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    // OSCrash
    SmartDefinition SymbolDefinition::greaterImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
    }

    SmartDefinition SymbolDefinition::lessImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
    }
    SmartDefinition SymbolDefinition::lessThanOrEqualToImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
        //return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLessThanOrEqualTo, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
       // return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokGreaterThanOrEqualTo, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::notEqualsImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
       // return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokNotEqualTo, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::leftShiftImpl(const Reference& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokLeftShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::signedRightShiftImpl(const Reference& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokSignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::unsignedRightShiftImpl(const Reference& def) const {
        return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokUnsignedRightShift, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::bitwiseAndLogicalAndImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalAnd, def, engine);
        //return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokBitwiseAndLogicalAnd, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::bitwiseAndLogicalOrImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalOr, def, engine);
       // return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokBitwiseAndLogicalOr, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }
    SmartDefinition SymbolDefinition::bitwiseAndLogicalXorImpl(const Reference& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokBitwiseAndLogicalXor, def, engine);
       // return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokBitwiseAndLogicalXor, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
    }

    template<typename T>
    SmartDefinition incrementer(SmartDefinition one, const SymbolDefinition* tiz, SymbolicEngine& engine) {
        T onei = dynamic_cast<T>(one.get());
        const SymbolDefinition* incremented = dynamic_cast<const SymbolDefinition*>(tiz->plusImpl(*onei).get());
        return SymbolDefinition::makeSymbolDefinitionForAssignment(*tiz, *incremented, askAssign, engine);
    }

    SmartDefinition SymbolDefinition::increment() const {
        if (getType() == SymbolicTypesPreVisitor::getIntTypeId()) {
            SmartDefinition one = DefinitionFactory::createInt(1, engine);
            return incrementer<const IntValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getLongTypeId()) {
            SmartDefinition one = DefinitionFactory::createLong(1, engine);
            return incrementer<const LongValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getCharTypeId()) {
            SmartDefinition one = DefinitionFactory::createChar(1, engine);
            return incrementer<const CharValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getByteTypeId()) {
            SmartDefinition one = DefinitionFactory::createByte(1, engine);
            return incrementer<const ByteValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getShortTypeId()) {
            SmartDefinition one = DefinitionFactory::createShort(1, engine);
            return incrementer<const ShortValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getFloatTypeId()) {
            SmartDefinition one = DefinitionFactory::createFloat(1, engine);
            return incrementer<const FloatValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getDoubleTypeId()) {
            SmartDefinition one = DefinitionFactory::createDouble(1, engine);
            return incrementer<const DoubleValueDefinition*>(one, this, engine);
        }
        throw SymbolicColumbusException("increment is not possible");
    }

    template<typename T>
    SmartDefinition decrementer(SmartDefinition one, const SymbolDefinition* tiz, SymbolicEngine& engine) {
        T onei = dynamic_cast<T>(one.get());
        const SymbolDefinition* decremented = dynamic_cast<const SymbolDefinition*>(onei->minusImpl(*tiz).get());
        return SymbolDefinition::makeSymbolDefinitionForAssignment(*tiz, *decremented, askAssign, engine);
    }

    SmartDefinition SymbolDefinition::decrement() const {
        if (getType() == SymbolicTypesPreVisitor::getIntTypeId()) {
            SmartDefinition one = DefinitionFactory::createInt(1, engine);
            return decrementer<const IntValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getLongTypeId()) {
            SmartDefinition one = DefinitionFactory::createLong(1, engine);
            return decrementer<const LongValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getCharTypeId()) {
            SmartDefinition one = DefinitionFactory::createChar(1, engine);
            return decrementer<const CharValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getByteTypeId()) {
            SmartDefinition one = DefinitionFactory::createByte(1, engine);
            return decrementer<const ByteValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getShortTypeId()) {
            SmartDefinition one = DefinitionFactory::createShort(1, engine);
            return decrementer<const ShortValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getFloatTypeId()) {
            SmartDefinition one = DefinitionFactory::createFloat(1, engine);
            return decrementer<const FloatValueDefinition*>(one, this, engine);
        }
        else if (getType() == SymbolicTypesPreVisitor::getDoubleTypeId()) {
            SmartDefinition one = DefinitionFactory::createDouble(1, engine);
            return decrementer<const DoubleValueDefinition*>(one, this, engine);
        }
        throw SymbolicColumbusException("decrement is not possible");

    }


    SmartDefinition SymbolDefinition::conditionalAndImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokConditionalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::conditionalAndImpl(const BooleanValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokConditionalAnd, def, engine);
    }

    SmartDefinition SymbolDefinition::conditionalOrImpl(const BooleanValueDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokConditionalOr, def, engine);
    }


    SmartDefinition SymbolDefinition::equalsImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
    }


    SmartDefinition SymbolDefinition::notEqualsImpl(const SymbolDefinition& def) const {
        return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
    }


    NegatedSymbolDefinition::NegatedSymbolDefinition(const Address& addr, SymbolicEngine& engine, const SymbolDefinition* original, bool negated):
        SymbolDefinition(SymbolicTypesPreVisitor::getBooleanTypeId(), addr, engine,false), original(original), negated(negated) {
        //csExpr = engine.getConstraintBuilder()->makeBoolVar(*this);
    }


    SmartDefinition SymbolDefinition::castIntegralType() const {
        if (getType() == SymbolicTypesPreVisitor::getBooleanClassId() || getType() == SymbolicTypesPreVisitor::getBooleanTypeId() ||
            getType() == SymbolicTypesPreVisitor::getStringTypeId() || getType() == SymbolicTypesPreVisitor::getStringClassId()) {
            throw SymbolicColumbusException("This should not be happenning");
        }
        SmartDefinition casted = DefinitionFactory::createSymbol(SymbolicTypesPreVisitor::getIntTypeId(), engine);
        ConstraintSet dependencies;
        //ConstraintBuilder* builder = engine.getConstraintBuilder();
        Constraint* assignmentConstraint;
        if (getType() == SymbolicTypesPreVisitor::getFloatClassId() || getType() == SymbolicTypesPreVisitor::getFloatTypeId() ||
            getType() == SymbolicTypesPreVisitor::getDoubleTypeId() || getType() == SymbolicTypesPreVisitor::getDoubleClassId()) {
            assignmentConstraint = engine.getConstraintBuilder()->makeConstraint(engine.getConstraintBuilder()->makeBoolExpr(*casted, *this, iokEqualTo, TO_INT));
        }
        else {
            assignmentConstraint = engine.getConstraintBuilder()->makeConstraint(engine.getConstraintBuilder()->makeBoolExpr(*casted, *this, iokEqualTo));
        }
        dependencies.insert(assignmentConstraint);
        casted->setDependencies(dependencies);
        return casted;
    }

    SmartDefinition SymbolDefinition::castToInt() const {
        return castIntegralType();
    }


    SmartDefinition SymbolDefinition::castToLong() const {
        return castIntegralType();
    }

    SmartDefinition SymbolDefinition::castToShort() const {
        return castIntegralType();
    }

    SmartDefinition SymbolDefinition::castToBoolean() const {
        if (getType() != SymbolicTypesPreVisitor::getBooleanTypeId()) {
            throw SymbolicColumbusException("Invalid conversion");
        }
        else {
            SmartDefinition casted = DefinitionFactory::createSymbol(SymbolicTypesPreVisitor::getBooleanTypeId(), engine);
            ConstraintSet dependencies;
            Constraint* assignmentConstraint = engine.getConstraintBuilder()->makeConstraint(engine.getConstraintBuilder()->makeBoolExpr(*casted, *this, iokEqualTo));
            dependencies.insert(assignmentConstraint);
            casted->setDependencies(dependencies);
            return casted;
        }
    }


}}


