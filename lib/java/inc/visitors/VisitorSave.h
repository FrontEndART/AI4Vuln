#ifndef _JAVA_VISITORSAVE_H_
#define _JAVA_VISITORSAVE_H_

#include "java/inc/java.h"

/**
* \file VisitorSave.h
* \brief Contains declaration of VisitorSave class.
*/

namespace columbus { namespace java { namespace asg {
  /**
  * \brief Visitor for saving the graph.
  */
  class VisitorSave : public VisitorAbstractNodes {
    protected:
      /**
      * \brief Constructor for Visitor.
      * \param io [in] The graph is save into this IO.
      */
      VisitorSave(io::BinaryIO &io);

    public:
      /**
      * \brief Visitor for saving node.
      * \param node [in] This node is being saved.
      */
      virtual void visitEnd(const base::Base &node , bool callVirtualBase = true);

    protected:
      /** \internal \brief Pointer to the "output". */
      io::BinaryIO &m_io;

      friend class Factory;
  }; // VisitorSave


}}}
#endif

