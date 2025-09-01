#ifndef _SARIFEXPORTER_H
#define _SARIFEXPORTER_H

#include <graph/inc/graph.h>
#include <string>
#include <common/inc/Stat.h>

namespace columbus {
    namespace graphsupport {

        /**
        * \brief load the graph, iterates it, and write the result into the sarif file
        * \param graph [in], graph from file
        * \param filename [in]
        */
        void exportToSarif(graph::Graph& graph, const std::string& filename, const std::string& sarifSeverityLevel);

    }
}
#endif