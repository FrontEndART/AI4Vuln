#include "../../inc/rules/SymbolicRuleChecker.h"
#include "../../inc/listener/JavaSymbolicCheckerWarningListener.h"

using namespace columbus;
using namespace common;
using namespace std;
using namespace java::asg;

namespace columbus { namespace symbolic {

SymbolicRuleChecker::~SymbolicRuleChecker() {
	//delete cwl;
}

SymbolicRuleChecker::SymbolicRuleChecker(JavaSymbolicChecker& checker, SymbolicEngine& engine) : RuleChecker(checker), m_warningSuppressor(NULL) {
	//cwl = new JavaSymbolicCheckerWarningListener(*checker.getASGFactory(), this, getCheckerID());	
	//engine.setWarningListener(cwl);
}

SymbolicRuleChecker::SymbolicRuleChecker(JavaSymbolicChecker& checker) : RuleChecker(checker), m_warningSuppressor(NULL), cwl(NULL) {
}

columbus::java::asg::Visitor* SymbolicRuleChecker::getVisitor(java::asg::Factory& javaFactory) {
    return NULL;
}

bool SymbolicRuleChecker::addWarning(const ASG_Base::Base* asgNode, const std::string& path, int line, int col, int endLine, int endCol, const std::list<std::string>& warningTextParams, const graph::AttributeComposite* extraInfo) {
    bool result = RuleChecker::addWarning(asgNode, path, line, col, endLine, endCol, warningTextParams, extraInfo);
    return result;
}

void SymbolicRuleChecker::executeBeforeVisit(java::asg::Factory& javaFactory)  {
    JavaSymbolicChecker& jsc = (JavaSymbolicChecker&)checker;
    jsc.startExecutor(true);
}


void SymbolicRuleChecker::setWarningSuppressor(WarningSuppressor* warningSuppressor) {
  m_warningSuppressor = warningSuppressor;
}

WarningSuppressor* SymbolicRuleChecker::getWarningSuppressor() const {
  return m_warningSuppressor;
}


}}
