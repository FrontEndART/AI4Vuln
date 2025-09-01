#ifndef __SYMBOLIC_WARNING_LISTENER_H
#define __SYMBOLIC_WARNING_LISTENER_H

#include <rulechecker/inc/RuleChecker.h>
#include <list>
#include <string>
//#include "../common.h"


namespace columbus { namespace symbolic {

class WarningListener {
private:
    std::string m_checkerId;
public:
    WarningListener(std::string checkerId) : m_checkerId(checkerId) {}
    virtual void addWarning(columbus::NodeId, RuleChecker& ruleChecker, const std::list<columbus::NodeId>& warningTextParams = std::list<columbus::NodeId>()) = 0;
    virtual void addWarningWithText(columbus::NodeId id, RuleChecker& ruleChecker, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo = NULL) = 0;

    virtual void addWarning(std::string checkerId, columbus::NodeId nodeId, const std::list<columbus::NodeId>& warningTextParams = std::list<columbus::NodeId>()) = 0;
    virtual void addWarning(std::string checkerId, columbus::NodeId nodeId, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo = NULL) = 0;

    inline std::string getCheckerId() { return m_checkerId; }
    virtual ~WarningListener() {}
};


}}
#endif