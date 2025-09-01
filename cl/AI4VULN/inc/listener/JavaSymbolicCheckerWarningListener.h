#ifndef _JAVA_SYMBOLIC_CHECKER_WARNINGLISTENER_H_
#define _JAVA_SYMBOLIC_CHECKER_WARNINGLISTENER_H_

#include "symbolic/inc/common.h"

#include "../rules/SymbolicRuleChecker.h"
#include <java/inc/java.h>
#include <list>
#include <rulechecker/inc/Suppressor.h>

using namespace columbus;

namespace columbus { namespace symbolic {

	class SymbolicRuleChecker;

    class JavaSymbolicCheckerWarningListener : public columbus::symbolic::WarningListener {
    public:
        java::asg::Factory& m_asgFactory;
        //SymbolicRuleChecker* m_ruleChecker;
        std::list<RuleChecker*> ruleCheckers;

        JavaSymbolicCheckerWarningListener(java::asg::Factory& asgFactory, std::list<RuleChecker*>& ruleCheckers, std::string checkerId);
        virtual void addWarning(columbus::NodeId id, RuleChecker& rulechecker, const std::list<columbus::NodeId>& warningTextParams /*= std::list<columbus::NodeId>()*/);
        virtual void addWarningWithText(columbus::NodeId id, RuleChecker& rulechecker, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo = NULL);

        void addWarning(std::string checkerId, columbus::NodeId nodeId, const std::list<columbus::NodeId>& warningTextParams = std::list<columbus::NodeId>());
        void addWarning(std::string checkerId, columbus::NodeId nodeId, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo = NULL);
    };

}}

#endif
