#ifndef _JAVA_SYMBOLIC_CHECKER_INF_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_INF_CHECKER_H_

#include "SymbolicRuleChecker.h"

namespace columbus { namespace symbolic {

    class JavaSymbolicINFChecker : public SymbolicRuleChecker {
    public:
        JavaSymbolicINFChecker(JavaSymbolicChecker& checker, SymbolicEngine& engine);
        virtual std::string getCheckerID();
    };

}}

#endif
