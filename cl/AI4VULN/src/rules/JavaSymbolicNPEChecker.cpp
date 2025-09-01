#include "../../inc/rules/JavaSymbolicNPEChecker.h"

using namespace columbus;
using namespace common;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicNPEChecker::JavaSymbolicNPEChecker(JavaSymbolicChecker& checker) : SymbolicRuleChecker(checker) {}

std::string JavaSymbolicNPEChecker::getCheckerID() {
    return SYMBOLIC_NULL_POINTER_EXCEPTION_RULECHECKER_ID;
}


}}
