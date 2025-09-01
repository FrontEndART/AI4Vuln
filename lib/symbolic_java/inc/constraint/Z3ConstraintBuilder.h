#ifndef _Z3CONSTRAINT_BUILDER_H_
#define _Z3CONSTRAINT_BUILDER_H_

#include <symbolic/inc/constraint/ConstraintBuilder.h>
#include <symbolic_java/inc/structure/StateJava.h>
#include <symbolic/inc/constraint/ConstraintSolverExpr.h>
#include <symbolic_java/inc/constraint/Z3ConstraintExpression.h>
#include "lim/inc/lim.h"
#include "java/inc/java.h"
#include "java/inc/Types.h"
#include "../common.h"

namespace columbus { namespace symbolic {

    class NegatedSymbolDefinition;
    class Definition;

    class Z3ConstraintBuilder: public ConstraintBuilder {
        ///StateJava* currentState;
    public:
        Z3ConstraintBuilder() = default;
		virtual ~Z3ConstraintBuilder() = default;

        //void setCurrentState(StateJava* state);

        virtual std::shared_ptr<ConstraintSolverExpr> makeIntValue(const int value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeLongValue(const long value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeShortValue(const short value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeByteValue(const char value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeCharValue(const wchar_t value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolValue(const bool value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeFloatValue(const float value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeDoubleValue(const double value) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeReferenceValue(const unsigned long value) override; // TODO: Reference parameter
        virtual std::shared_ptr<ConstraintSolverExpr> makeStringValue(const string value) override;

        virtual std::shared_ptr<ConstraintSolverExpr> makeIntVar(const std::string& add) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeLongVar(const std::string& addr) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeShortVar(const std::string& addr) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeByteVar(const string& addr)override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeCharVar(const string& addr)override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolVar(const std::string& addr) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeFloatVar(const std::string& addr) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeDoubleVar(const std::string& addr) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeReferenceVar(const string& addr) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeStringVar(const string& addr) override;

        virtual std::shared_ptr<ConstraintSolverExpr> makeNumericExpr(const Definition& left, const Definition& right, const java::asg::InfixOperatorKind op, columbus::NodeId type) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeNumericExpr(const Definition& operand, const java::asg::PrefixOperatorKind op) override;

        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolExpr(const ConstraintSolverExpr* left,const ConstraintSolverExpr* right, const columbus::java::asg::InfixOperatorKind op, CastTypes cast) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolExpr(const Definition& operand, const java::asg::PrefixOperatorKind op) override;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolExpr(const Definition& left, const Definition& right, const java::asg::InfixOperatorKind op, CastTypes cast = CastTypes::NONE) override;
        virtual Constraint* makeConstraint(std::shared_ptr<ConstraintSolverExpr> expr) override;
        virtual Constraint* makeNegatedConstraint(shared_ptr<ConstraintSolverExpr> expr) override;

        /** Creates the dependency list of the two sides */
        virtual ConstraintSet makeDependencies(const Definition &left, const Definition &right) override;

        /** Make a (hard)copy of the dependency list of the operand. */
        virtual ConstraintSet makeDependencies(const Definition &operand) override;
        virtual ConstraintSet makeDependenciesSimple(const Definition& operand) override;

        /**
         * Determines that the constraint building currently supports the given type.
         */
        virtual bool isTypeHandled(NodeId type) override;
        //columbus { namespace java { namespace asg
        static std::string operatorToString(const columbus::java::asg::PrefixOperatorKind op);
        static std::string operatorToString(const columbus::java::asg::InfixOperatorKind op);

        std::shared_ptr<ConstraintSolverExpr> makeConditionalExpr(const Definition& def, bool negated) override;

    };


}}

#endif
