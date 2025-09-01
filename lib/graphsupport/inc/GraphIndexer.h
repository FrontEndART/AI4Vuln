#ifndef _GRAPH_INDEXER_H_
#define _GRAPH_INDEXER_H_


#include <graph/inc/graph.h>
#include <boost/icl/split_interval_map.hpp>
#include <boost/icl/interval_map.hpp>
#include <map>
#include <set>


namespace columbus {
namespace graphsupport {


class GraphIndexer
{
    public:
      typedef std::pair<graph::Node, graph::Node> NodePair;

      class NodeSelector
      {
        public:
          NodeSelector() : nodePair(std::make_pair(graph::Graph::invalidNode, graph::Graph::invalidNode)), size(-1) {}
          NodeSelector(const NodePair& nodePair, int size): nodePair(nodePair), size(size) { }

          const graph::Node& getNode() const
          {
            return nodePair.second;
          };

          const std::vector<graph::Node>& getExtraNodes() const
          {
            return extraNodes;
          }

          bool operator==(const NodeSelector& right) const
          {
            return (right.nodePair == nodePair) && (right.size == size);
          }

          NodeSelector& operator+=(const NodeSelector& right)
          {
            if (size == -1)
            {
              nodePair = right.nodePair;
              size = right.size;
              extraNodes  = right.extraNodes;
            }
            else
            {
              // siblings
              if (right.nodePair.first == nodePair.first)
              {
                  extraNodes.push_back(right.nodePair.second);
              }
              else
              {
                if ((right.size >= 0) && (right.size < size))
                {
                  nodePair = right.nodePair;
                  size = right.size;
                  extraNodes.clear();
                }
              }
            }
            return *this;
          }
        private:
          NodePair nodePair;
          int size;
          std::vector<graph::Node> extraNodes;
      };

      typedef boost::icl::split_interval_map<int, NodeSelector> IntIntervalToNodeMap;

    public:
      GraphIndexer(graph::Graph* graph);
      void buildRangeIndex();
      IntIntervalToNodeMap getNodesInRange(const std::string& path, const boost::icl::discrete_interval<int>& range) const;

    private:
      typedef std::map<std::string, IntIntervalToNodeMap> StringToIntIntervalToNodeMapMap;

    private:
      graph::Graph* graph;
      StringToIntIntervalToNodeMapMap pathToNodeRangeMap;

};


} // namespace graphsupport
} // namespace columbus

#endif
