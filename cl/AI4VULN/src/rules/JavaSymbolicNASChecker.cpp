#include "../../inc/rules/JavaSymbolicNASChecker.h"

using namespace columbus;
using namespace common;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicNASChecker::JavaSymbolicNASChecker(JavaSymbolicChecker& checker) : SymbolicRuleChecker(checker) {}

std::string JavaSymbolicNASChecker::getCheckerID() {
    return SYMBOLIC_INDEX_NEGATIVE_ARRAY_SIZE_RULECHECKER_ID;
}

}}
