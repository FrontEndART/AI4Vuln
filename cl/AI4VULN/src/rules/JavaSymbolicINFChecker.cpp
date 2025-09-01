#include "../../inc/rules/JavaSymbolicINFChecker.h"

using namespace columbus;
using namespace common;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicINFChecker::JavaSymbolicINFChecker(JavaSymbolicChecker& checker, SymbolicEngine& engine) : SymbolicRuleChecker(checker, engine) {}

std::string JavaSymbolicINFChecker::getCheckerID() {
    return SYMBOLIC_INFINITE_LOPP_RULECHECKER_ID;
}
}}
