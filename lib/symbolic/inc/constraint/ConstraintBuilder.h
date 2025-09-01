#ifndef _CONSTRAINT_BUILDER_H_
#define _CONSTRAINT_BUILDER_H_

#include "../definition/Definition.h"
#include "ConstraintSolverExpr.h"
#include "lim/inc/lim.h"
#include "java/inc/java.h"
#include "SymbolIdentifier.h"
#include "../common.h"

namespace columbus { namespace symbolic {

    class IntValueDefinition;
    class SymbolDefinition;

    class ConstraintBuilder {
    protected:
        SymbolicEngine* engine;
    public:
        ConstraintBuilder();
        virtual ~ConstraintBuilder(void);


        void setSymbolicEngine(SymbolicEngine* engine);

        virtual std::shared_ptr<ConstraintSolverExpr> makeIntValue(const int value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeLongValue(const long value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeShortValue(const short value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeByteValue(const char value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeCharValue(const wchar_t value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolValue(const bool value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeFloatValue(const float value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeDoubleValue(const double value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeStringValue(const string value) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeReferenceValue(const unsigned long value) = 0; // TODO: Reference parameter

        virtual std::shared_ptr<ConstraintSolverExpr> makeIntVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeLongVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeShortVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeByteVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeCharVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeFloatVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeDoubleVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeStringVar(const string& addr) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeReferenceVar(const string& addr) = 0;

        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolExpr(const ConstraintSolverExpr* left, const ConstraintSolverExpr* right, const columbus::java::asg::InfixOperatorKind op, CastTypes cast = CastTypes::NONE) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeNumericExpr(const Definition& operand, const java::asg::PrefixOperatorKind op) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolExpr(const Definition& operand, const java::asg::PrefixOperatorKind op) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeNumericExpr(const Definition& left, const Definition& right, const java::asg::InfixOperatorKind op, columbus::NodeId ex) = 0;
        virtual std::shared_ptr<ConstraintSolverExpr> makeBoolExpr(const Definition& left, const Definition& right, const java::asg::InfixOperatorKind op, CastTypes cast = CastTypes::NONE) = 0;
        virtual Constraint* makeConstraint(shared_ptr<ConstraintSolverExpr> expr) = 0;
        virtual Constraint* makeNegatedConstraint(shared_ptr<ConstraintSolverExpr> expr) = 0;

        /** Creates the dependency list of the two sides */
        virtual ConstraintSet makeDependencies(const Definition &left, const Definition &right) = 0;

        /** Make a (hard)copy of the dependency list of the operand. */
        virtual ConstraintSet makeDependencies(const Definition &operand) = 0;
        virtual ConstraintSet makeDependenciesSimple(const Definition& operand) = 0;

        /**
         * Determines that the constraint building currently supports the given type.
         */
        virtual bool isTypeHandled(NodeId type) = 0;

        virtual std::shared_ptr<ConstraintSolverExpr> makeConditionalExpr(const Definition& operand, bool negated) = 0;

    };


}}

#endif
