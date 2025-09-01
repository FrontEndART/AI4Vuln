#ifndef _JAVA_SYMBOLIC_CHECKER_NAS_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_NAS_CHECKER_H_

#include "SymbolicRuleChecker.h"

namespace columbus { namespace symbolic {

    class JavaSymbolicNASChecker : public SymbolicRuleChecker {
    public:
        JavaSymbolicNASChecker(JavaSymbolicChecker& checker);
        virtual std::string getCheckerID();
    };

}}

#endif
