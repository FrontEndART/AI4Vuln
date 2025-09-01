#ifndef GraphXmlHandlerGRAPH_H
#define GraphXmlHandlerGRAPH_H

#include <io/inc/IO.h>
#include <string>
#include <stack>
#include <map>
#include "graph/inc/BGraph.h"

/**
* \file GraphXmlHandler.h
* \brief Contains xmlheandler for loadXML declaration 
*/

namespace columbus {  namespace graph {

  class GraphXmlHandler : public io::SimpleXmlIO::XmlHandler {

    protected:

      // last container type 
      enum LastContainerType {
        lctNode,
        lctEdge,
        lctReverseEdge,
        lctAttributeCompositeNode,
        lctAttributeCompositeEdge,
        lctNone
      };

      Graph *graph;                             // pointer to the graph

      LastContainerType lastContainer;          // last readed container
      Edge activeEdge;                          // last readed edge
      Edge activeReverseEdge;                   // last readed reverse edge
      Node activeNode;                          // last readed node
      std::stack< std::pair<AttributeComposite*, int> > attrCompositeStack;
//      AttributeIntSet *activeAttributeIntSet;   // last readed attributeIntSet

    private:
      /**
      * \brief read attrributes from 'list'
      * \param list [in] attributes list
      */
      void readAttribute(const AttributeList &list); 

      /**
      * \brief constructor
      * \param g [in] the loader graph
      */
      GraphXmlHandler(Graph *g);                

      GraphXmlHandler(const columbus::graph::GraphXmlHandler&);
      GraphXmlHandler& operator=(const columbus::graph::GraphXmlHandler&);

    public:
      virtual ~GraphXmlHandler();

      /**
      * \brief Add attribute to active element
      * \param activeAttribute [in] attribute
      */
      void addAttributeToActiveElement(const Attribute& activeAttribute) ;

      /**
      * \breif read begin of a tag
      * \param name [in] the tag name
      * \param list [in] the attributes list
      */
      void beginTag(const std::string& name, const AttributeList& list);

      /**
      * \breif read end of a tag
      * \param name [in] the tag name
      */
      void endTag(const std::string& name);

    friend class Graph;
  };

}}

#endif

