#ifndef _GRAPHSUPPORTRULBUILDER
#define _GRAPHSUPPORTRULBUILDER

#include <graph/inc/graph.h>
#include "GraphRangeIndexer.h"


namespace columbus {

  namespace rul {
    class RulHandler;
    class Tag;
  }

  namespace graphsupport {
    void buildRulToGraph(graph::Graph& graph, rul::RulHandler& rulHandler);
        
    void buildRuleItemToGraph(graph::Graph& graph,
                              const std::string& metricID, 
                              const std::string& toolID, 
                              const std::string& description, 
                              const std::string& displayName, 
                              bool isEnabled, 
                              const std::string& groupType, 
                              const std::string& helpText, 
                              bool isWarning, 
                              const std::map<std::string, std::string>& settings, 
                              const std::set<std::string>& calculated,
                              const std::set<rul::Tag>& tags);
                              
    bool readRuleItemFromGraph(graph::Graph& graph,
                              const std::string& metricID, 
                              std::string& description, 
                              std::string& displayName, 
                              bool& isEnabled, 
                              std::string& groupType, 
                              std::string& helpText, 
                              bool& isWarning, 
                              std::map<std::string, std::string>& settings, 
                              std::set<std::string>& calculated,
                              std::set<rul::Tag>& tags);
  }
}

#endif
