#ifndef _LIM2graph_GRAPHCONVERTER_H_
#define _LIM2graph_GRAPHCONVERTER_H_

#include "lim/inc/lim.h"
#include "graph/inc/graph.h"

/**
* \file GraphConverter.h
* \brief Contains declaration of graph converter functions.
*/

namespace columbus { namespace lim2graph { 
      /**
      * \brief Function to convert the ASG to graph .
      * \param factory [in] The factory of the ASG.
      * \param graph   [in] The graph into the ASG will be converted.
      */
      void convertBaseGraph(lim::asg::Factory& factory, graph::Graph& graph, bool edges, bool attributes, bool components, bool variants, bool instances = false);

      /**
      * \brief Function to convert RPG spool info into the graph.
      * \param factory   [in] The factory of the ASG.
      * \param limOrigin [in] The lim origin.
      * \param graph     [in] The graph.
      */
      void convertRPGSpoolInfo(lim::asg::Factory& factory, LimOrigin& limOrigin, graph::Graph& graph);


}}
#endif

