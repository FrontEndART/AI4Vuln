#ifndef _JAVA_SYMBOLIC_CHECKER_NPE_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_NPE_CHECKER_H_

#include "SymbolicRuleChecker.h"

namespace columbus { namespace symbolic {

    class JavaSymbolicNPEChecker : public SymbolicRuleChecker {
    public:
        JavaSymbolicNPEChecker(JavaSymbolicChecker& checker);
        virtual std::string getCheckerID();

    };

}}

#endif
