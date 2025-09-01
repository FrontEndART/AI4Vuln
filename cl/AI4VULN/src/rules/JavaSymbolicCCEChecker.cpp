#include "../../inc/rules/JavaSymbolicCCEChecker.h"

using namespace columbus;
using namespace common;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicCCEChecker::JavaSymbolicCCEChecker(JavaSymbolicChecker& checker) : SymbolicRuleChecker(checker) {}

std::string JavaSymbolicCCEChecker::getCheckerID() {
    return SYMBOLIC_CLASS_CAST_EXCEPTION_RULECHECKER_ID;
}

}}
