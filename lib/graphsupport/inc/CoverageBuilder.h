#ifndef _COVERAGE_BUILDER_H_
#define _COVERAGE_BUILDER_H_

#include <graph/inc/graph.h>
#include <boost/icl/interval_set.hpp>
#include <string>
#include <map>

namespace columbus {
namespace graphsupport {

struct Position;
class GraphIndexer;

namespace coverage  {

enum class CoverageType
{
    Covered,
    NotCovered,
};


class CoverageBuilder
{
  public:
    CoverageBuilder();
    /**
     * Add [line, line] closed interval.
     */
    void addCoverageInfo(const std::string& path, int line, CoverageType coverageType);
    /**
     * Add [startLine, endLine] closed interval.
     */
    void addCoverageInfo(const std::string& path, int startLine, int endLine, CoverageType coverageType);
    bool buildToGraph(graph::Graph& graph);
    size_t getAllRanges() const;
    size_t getNotIntersectionRanges() const;

  private:
    typedef std::map<const std::string, boost::icl::interval_set<int>> IntervalMap;

  private:
    void buildIntervalsToGraph(graph::Graph& graph, const GraphIndexer& graphIndexer, const IntervalMap& intervals, CoverageType coverageType);

  private:
    IntervalMap coveredLinesMap;
    IntervalMap notCoveredLinesMap;
    size_t notIntersectingRanges;
    size_t allRanges;

};

} // namespace coverage
} // namespace graphsupport
} // namespace columbus

#endif

