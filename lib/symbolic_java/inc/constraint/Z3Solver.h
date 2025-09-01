#ifndef _Z3SOLVER_H_
#define _Z3SOLVER_H_

#include <set>
#include <map>

#include <symbolic/inc/constraint/ConstraintSolver.h>



namespace columbus { namespace symbolic {


    class Z3Solver : public ConstraintSolver {
		std::string  generateVariableDeclarations(const std::set<std::shared_ptr<ConstraintSolverExpr>>& variables) const;
    public:
		Z3Solver(const string& name);
		virtual ~Z3Solver() = default;
		Solution solve(const std::string& str, const std::set<shared_ptr<ConstraintSolverExpr>>& variables) const override;
    };


}}

#endif
