
#ifndef __COLUMBUS_RULECHECKER_H__
#define __COLUMBUS_RULECHECKER_H__

#include <string>
//#include <lim/inc/lim.h>
#include <list>
#include <graph/inc/graph.h>
#include <java/inc/java.h>
//#include "Checker.h"
#include "common.h"

namespace columbus {
  class Checker;
  
  class RuleChecker {
    public:
      RuleChecker(Checker& checker);
      virtual std::string getCheckerID() = 0;
      virtual ~RuleChecker();
      
      virtual void executeBeforeVisit(columbus::java::asg::Factory& factory);
      virtual columbus::java::asg::Visitor* getVisitor(columbus::java::asg::Factory& factory);
      virtual void executeAfterVisit(columbus::java::asg::Factory& factory);

      virtual bool addWarning(const columbus::java::asg::base::Base* asgNode, const std::string& path, int line, int col, int endLine, int endCol, const std::list<std::string>& warningTextParams = std::list<std::string>(), const graph::AttributeComposite* extraInfo = NULL);
    
      virtual graph::Graph& getResultGraph();
    protected:
      Checker& checker;
      
  };

}

#endif
