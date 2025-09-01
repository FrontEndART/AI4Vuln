#include "../../inc/rules/JavaSymbolicIOBChecker.h"

using namespace columbus;
using namespace common;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicIOBChecker::JavaSymbolicIOBChecker(JavaSymbolicChecker& checker) : SymbolicRuleChecker(checker) {}

std::string JavaSymbolicIOBChecker::getCheckerID() {
    return SYMBOLIC_INDEX_OUT_OF_BOUNDS_EXCEPTION_RULECHECKER_ID;
}

}}
