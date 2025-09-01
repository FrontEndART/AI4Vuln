#ifndef _Z3CONSTRAINTEXPRESSION_H_
#define _Z3CONSTRAINTEXPRESSION_H_

#include <vector>
#include <map>
#include <list>

#include <symbolic/inc/constraint/ConstraintSolverExpr.h>
#include <symbolic_java/inc/algorithms/SymbolicTypesPreVisitor.h>
#include <z3++.h>



namespace columbus { namespace symbolic {


    class Z3ConstraintExpression : public ConstraintSolverExpr {
        columbus::NodeId type;
        bool complex;
        bool bitvector=false;

    public:
		Z3ConstraintExpression(const std::string& strRep, columbus::NodeId type = SymbolicTypesPreVisitor::getBooleanTypeId(), bool isComplex = true);
        Z3ConstraintExpression(columbus::NodeId typee, bool isComplex = false);
        Z3ConstraintExpression(const std::string& strRep, NodeId type, bool isComplex, bool isBitvector);
        virtual ~Z3ConstraintExpression() = default;

        bool isBool()const;
        bool isInt()const;
        bool isFloat()const;
        bool isString()const;
        bool isDouble()const;
        bool isLong()const;
        bool isShort()const;
        bool isByte()const;
        bool isChar()const;
        bool isComplex()const;
        bool isBitvector()const;
        bool isObject()const;

        ConstraintSolverExpr* copy() const override;

    };

    class Z3ConstraintExpressionNegation: public Z3ConstraintExpression {
        std::string originalStrRep;
        bool negated;
    public:
        Z3ConstraintExpressionNegation(const std::string& strRep, const std::string& originalStrRep, bool negated);
        bool isIdentifierCondition() const override;
        const string& getOriginalStringRep()const;
        bool isNegated() const;
    };


}}

#endif
