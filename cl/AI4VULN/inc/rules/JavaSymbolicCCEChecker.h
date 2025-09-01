#ifndef _JAVA_SYMBOLIC_CHECKER_CCE_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_CCE_CHECKER_H_

#include "SymbolicRuleChecker.h"

namespace columbus { namespace symbolic {

    class JavaSymbolicCCEChecker : public SymbolicRuleChecker {
    public:
        JavaSymbolicCCEChecker(JavaSymbolicChecker& checker);
        virtual std::string getCheckerID();
    };

}}

#endif
