#ifndef __COLUMBUS_CHECKER_H__
#define __COLUMBUS_CHECKER_H__

#include <lim/inc/lim.h>
#include <rul/inc/RulHandler.h>
#include <graph/inc/graph.h>
#include <string>
#include <list>
#include "common.h"
#include "Suppressor.h"
#include <graphsupport/inc/Metric.h>


namespace columbus { 
  class RuleChecker;
  class Checker {
    public:
      Checker(const std::string& limFileName, const std::string& rulFileName, const std::string& rulConfig, const bool exportRul = true);
      
      virtual void addRuleChecker(RuleChecker* ruleChecker);
      virtual bool executeCheck(const std::list<std::string>& inputFileNames, const std::string changepathfrom = "", std::string changepathto = "");
      virtual bool addWarning(RuleChecker* ruleChecker, const columbus::java::asg::base::Base* asgNode, const std::string& path, int line, int col, int endLine, int endCol, const std::list<std::string>& warningTextParams = std::list<std::string>(), const graph::AttributeComposite* extraInfo = NULL);
      virtual void saveResultGraph(const std::string& graphOutputFilename, bool createXMLdump);
      
      virtual void initNewAsg(columbus::java::asg::Factory* currentFactory,columbus::java::asg::AlgorithmPreorder* preorder, WarningSuppressor* warningSuppressor);
      virtual void releaseAsg();

      const rul::RulHandler& getRulHandler() const;
      const lim::asg::Factory& getLimFactory() const;
      
      void addLicenseTypeToTheGraphHeader(const std::string& toolName);

      NodeId getCurrentComponentId() const;
      WarningSuppressor* getCurrentWarningSuppressor() const;
      
      const LimOrigin& getLimOrigin() const;

      virtual ~Checker();
      
      graph::Graph& getResultGraph();
      
    protected:
      void collectComponents(std::set<const lim::asg::base::Component*>& components);

      
      Checker(const Checker& checker); // Deliberately not implemented
  
    protected:
      LimOrigin limOrigin;
      RefDistributorStrTable limStrTable;
      lim::asg::Factory limFactory;
      rul::RulHandler rulHandler;
      graph::Graph graph;
      std::list<RuleChecker*> ruleCheckers;

      NodeId currentComponentId;
      WarningSuppressor* currentWarningSuppressor;
      graphsupport::WarningCache warningCache;
    
  };

}

#endif
