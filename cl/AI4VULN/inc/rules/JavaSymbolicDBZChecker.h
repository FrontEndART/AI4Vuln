#ifndef _JAVA_SYMBOLIC_CHECKER_DBZ_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_DBZ_CHECKER_H_

#include "SymbolicRuleChecker.h"

namespace columbus { namespace symbolic {

    class JavaSymbolicDBZChecker : public SymbolicRuleChecker {
    public:
        JavaSymbolicDBZChecker(JavaSymbolicChecker& checker);
        virtual std::string getCheckerID();
    };

}}

#endif
