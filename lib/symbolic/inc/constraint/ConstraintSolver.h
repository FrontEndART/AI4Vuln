#ifndef _CONSTRAINTSOLVER_H_
#define _CONSTRAINTSOLVER_H_

#include <map>
#include <set>
#include "ConstraintSolverExpr.h"


using namespace std;

namespace columbus { namespace symbolic {

struct Solution {
    bool hasSolution;
    bool hasMoreSolutions;
    bool timeLimitReached;
    bool error;

    Solution() : hasSolution(false), hasMoreSolutions(false), timeLimitReached(false), error(false) {
    }

    Solution(bool s, bool m, bool t, bool e) : hasSolution(s), hasMoreSolutions(m), timeLimitReached(t), error(e) {

    }
};

/**
 * Base class of specific constraint solvers.
 */
class ConstraintSolver {

protected:

string name;
std::vector<std::string> smtlib2Strigs;
string smtExit = "(exit)";

public:
    ConstraintSolver(const string& name);
    virtual ~ConstraintSolver() = default;

    /**
     * Solves the path condition of the given State.
     */
    virtual Solution solve(const std::string& str,const std::set<std::shared_ptr<ConstraintSolverExpr>>& variables) const = 0;
};


}}

#endif
