#include "../../inc/rules/JavaSymbolicDBZChecker.h"

using namespace columbus;
using namespace common;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicDBZChecker::JavaSymbolicDBZChecker(JavaSymbolicChecker& checker) : SymbolicRuleChecker(checker) {}

std::string JavaSymbolicDBZChecker::getCheckerID() {
    return SYMBOLIC_DIVISION_BY_ZERO_RULECHECKER_ID;
}

}}
