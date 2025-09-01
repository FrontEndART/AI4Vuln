#ifndef _CSVEXPORTER_H
#define _CSVEXPORTER_H

#include <graph/inc/graph.h>
#include <string>
#include <map>
#include <vector>

namespace columbus { namespace graphsupport {

  /**
   * \brief export impacted nodes from graph to a csv file
   * \param graph [in] graph
   * \param filename [in] the output file name
   * \param edgeTypes [in] the impaction edges
   */
  void exportImpactSet(graph::Graph& graph, const std::string& filename, graph::Edge::EdgeTypeSet& edgeTypes);

  /**
   * \brief export impacted nodes from graph to a csv file
   * \param graph [in] graph
   * \param filename [in] the output file name
   * \param edgeTypes [in] the impaction edges
   * \param parentNodes [in] the impacted nodes parents
   */
  void exportImpactSet(graph::Graph& graph, const std::string& filename, graph::Edge::EdgeTypeSet& edgeTypes, const std::set<graph::Node>& parentNodes);

  void exportReadableMetricsCSV(graph::Graph& graph, const std::string& filename, char separator = ',', char dmark = '.');

}}

#endif
