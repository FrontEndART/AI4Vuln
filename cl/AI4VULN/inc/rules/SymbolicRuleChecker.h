#ifndef _JAVA_SYMBOLIC_CHECKER_SYMBOLICCHECKER_H__
#define _JAVA_SYMBOLIC_CHECKER_SYMBOLICCHECKER_H__

#include <rulechecker/inc/RuleChecker.h>
#include <rulechecker/inc/Suppressor.h>

#include "../checker/JavaSymbolicChecker.h"
#include "../listener/JavaSymbolicCheckerWarningListener.h"


namespace columbus { namespace symbolic {
    
    class JavaSymbolicCheckerWarningListener;

class SymbolicRuleChecker : public RuleChecker {



    public:
        ~SymbolicRuleChecker();
        virtual void executeBeforeVisit(java::asg::Factory& javaFactory);
        virtual columbus::java::asg::Visitor* getVisitor(java::asg::Factory& javaFactory);
        virtual bool addWarning(const ASG_Base::Base* asgNode, const std::string& path, int line, int col, int endLine, int endCol, const std::list<std::string>& warningTextParams = std::list<std::string>(), const graph::AttributeComposite* extraInfo = NULL);
        void setWarningSuppressor(WarningSuppressor* warningSuppressor);
        WarningSuppressor* getWarningSuppressor() const;
        virtual std::string getCheckerID() { return ""; }
    
    protected:
        SymbolicRuleChecker(JavaSymbolicChecker& checker);
        SymbolicRuleChecker(JavaSymbolicChecker& checker, SymbolicEngine& engine);
        WarningSuppressor* m_warningSuppressor;
        columbus::symbolic::JavaSymbolicCheckerWarningListener *cwl;
};

}}

#endif
