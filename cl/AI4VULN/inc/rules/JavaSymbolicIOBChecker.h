#ifndef _JAVA_SYMBOLIC_CHECKER_IOB_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_IOB_CHECKER_H_

#include "SymbolicRuleChecker.h"

namespace columbus { namespace symbolic {

    class JavaSymbolicIOBChecker : public SymbolicRuleChecker {
    public:
        JavaSymbolicIOBChecker(JavaSymbolicChecker& checker);
        virtual std::string getCheckerID();
    };

}}

#endif
