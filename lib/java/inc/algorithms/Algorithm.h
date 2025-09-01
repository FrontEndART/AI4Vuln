#ifndef _JAVA_ALGORITHM_H_
#define _JAVA_ALGORITHM_H_

#include "java/inc/java.h"

/**
* \file Algorithm.h
* \brief Contains declaration of Algorithm class.
*/

namespace columbus { namespace java { namespace asg {
  /**
  * \brief Common base class for all algorithm classes.
  */
  class Algorithm {
    public:
      /**
      * \internal
      * \brief The constructor.
      */
      Algorithm(){}

      /**
      * \internal
      * \brief The virtual destructor.
      */
      virtual ~Algorithm(){}

    protected:
      /**
      * \internal
      * \brief Increases the depth of the given visitor.
      * \param v [in] The visitor class.
      */
      void incVisitorDepth(Visitor& v);

      /**
      * \internal
      * \brief Decreases the depth of the given visitor.
      * \param v [in] The visitor class.
      */
      void decVisitorDepth(Visitor& v);

  }; // Algorithm


}}}
#endif

