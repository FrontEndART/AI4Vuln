#ifndef _CONSTRAINT_SOLVER_EXPR_H_
#define _CONSTRAINT_SOLVER_EXPR_H_

#include <sstream>

namespace columbus { namespace symbolic {

    class ConstraintSolverExpr {
    protected:
        /** String representation of the expression. Prefix notation used. Needs for testing. */
        std::string strRep;

    public:

        ConstraintSolverExpr(const std::string &strRep);
        virtual ~ConstraintSolverExpr();


        const std::string& getStrRep() const { return strRep; }

        bool operator==(const ConstraintSolverExpr& e) {
            return strRep == e.strRep;
        }

        virtual ConstraintSolverExpr* copy() const = 0;

        virtual bool isIdentifierCondition() const {
            return false;
        }

};

}}

#endif
