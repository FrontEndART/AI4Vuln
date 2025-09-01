#include "../../inc/listener/JavaSymbolicCheckerWarningListener.h"
#include "../../inc/messages.h"
#include <graphsupport/inc/GraphConstants.h>
#include <graphsupport/inc/Metric.h>
#include <common/inc/WriteMessage.h>
#include <iostream>
#include <fstream>

using namespace common;
using namespace columbus::java::asg;
using namespace std;

namespace columbus { namespace symbolic {

JavaSymbolicCheckerWarningListener::JavaSymbolicCheckerWarningListener(java::asg::Factory& asgFactory, std::list<RuleChecker*>& ruleCheckers, std::string checkerId) : WarningListener(checkerId), m_asgFactory(asgFactory), ruleCheckers(ruleCheckers) {}

void JavaSymbolicCheckerWarningListener::addWarningWithText(columbus::NodeId id, RuleChecker& ruleChecker, const std::string& warningText, const graph::AttributeComposite* extraInfo) {

    java::asg::base::Positioned& node = dynamic_cast<java::asg::base::Positioned&>(m_asgFactory.getRef(id));
    java::asg::Range pos = node.getPosition();

    //if (ruleChecker.getWarningSuppressor() != NULL) {
    //  const WarningSuppressor::StringSet* suppressionMarkers = ruleChecker.getWarningSuppressor()->getSuppressionMarkers(pos.getPath(), pos.getLine(), pos.getCol());
    //  if (suppressionMarkers != NULL) {
    //    for (WarningSuppressor::StringSet::const_iterator markerIt = suppressionMarkers->begin(); markerIt != suppressionMarkers->end(); ++markerIt) {
    //      if (markerIt->compare("RH") == 0 || markerIt->compare("NORH") == 0) {
    //          return;
    //      }
    //    }
    //  }
    //}


    if (!ruleChecker.addWarning(&node, pos.getPath(), pos.getLine(), pos.getCol(), pos.getEndLine(), pos.getEndCol(), std::list<std::string>(1, warningText), extraInfo))
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_FAILED_TO_ADD_WARNING, id);
}

void JavaSymbolicCheckerWarningListener::addWarning(columbus::NodeId id, RuleChecker& ruleChecker, const std::list<columbus::NodeId>& warningTextParams = std::list<columbus::NodeId>()) {
    java::asg::base::Positioned& node = dynamic_cast<java::asg::base::Positioned&>(m_asgFactory.getRef(id));
    java::asg::Range pos = node.getPosition();

    unsigned int lastPathKey = 0;
    unsigned int lastLine = 0;
    std::stringstream ss;
    for (std::list<columbus::NodeId>::const_iterator iter = warningTextParams.begin(); iter != warningTextParams.end(); ++iter) {
        base::Base& b = m_asgFactory.getRef(*iter);
        if (Common::getIsPositioned(b)) {
            base::Positioned& p = dynamic_cast<base::Positioned&>(b);
            const Range& r = p.getPosition();
            if (r.getPathKey() == lastPathKey && r.getLine() == lastLine){
                // dont store it again
            } else {
                lastPathKey = r.getPathKey();
                lastLine = r.getLine();
                ss << r.getPath() << ", line: " << lastLine << std::endl;
            }
        } else {
            ss << *iter << std::endl;
        }
    }

    if (!ruleChecker.addWarning(&node, pos.getPath(), pos.getLine(), pos.getCol(), pos.getEndLine(), pos.getEndCol(), std::list<std::string>(1, ss.str())))
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_FAILED_TO_ADD_WARNING, id);
    else
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_ADD_WARNING, id);
}


    void JavaSymbolicCheckerWarningListener::addWarning(std::string checkerId, columbus::NodeId id, const std::list<columbus::NodeId>& warningTextParams) {
        for (std::list<RuleChecker*>::iterator it = ruleCheckers.begin(); it != ruleCheckers.end(); ++it) {
            if ((*it)->getCheckerID().compare(checkerId) == 0) {
                addWarning(id, **it, warningTextParams);
            }
        }
    }

    void JavaSymbolicCheckerWarningListener::addWarning(std::string checkerId, columbus::NodeId nodeId, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo) {
        for (std::list<RuleChecker*>::iterator it = ruleCheckers.begin(); it != ruleCheckers.end(); ++it) {
            if ((*it)->getCheckerID().compare(checkerId) == 0) {
                addWarningWithText(nodeId, **it, warningText, extraInfo);
            }
        }
    }

}}
