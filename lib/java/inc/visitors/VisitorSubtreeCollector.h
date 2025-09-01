#ifndef _JAVA_VISITORSUBTREECOLLECTOR_H_
#define _JAVA_VISITORSUBTREECOLLECTOR_H_

#include "java/inc/java.h"

/**
* \file VisitorSubtreeCollector.h
* \brief Contains declaration of VisitorSubtreeCollector class.
*/

namespace columbus { namespace java { namespace asg {
  /**
  * \brief Visitor ...
  */
  class VisitorSubtreeCollector : public VisitorAbstractNodes {
    public:
      /**
      * \brief Constructor for Visitor.
      * \param nodelist [in, out] The list where the id of the visited nodes are inserted.
      */
      VisitorSubtreeCollector(std::list< NodeId> &nodelist);

      /**
      * \brief Visitor for all nodes.
      * \param node [in] This node is being visited.
      */
      virtual void visit(const base::Base &node, bool callVirtualBase = true);

    protected:
      /** \internal \brief Reference to the list where the ids will be collected. */
      std::list<NodeId> &nodelist;

  }; // VisitorSave


}}}
#endif

