#ifndef _LIM_VISITORFILTER_H_
#define _LIM_VISITORFILTER_H_

#include "lim/inc/lim.h"

/**
* \file VisitorFilter.h
* \brief Contains declaration of VisitorFilter class.
*/

namespace columbus { namespace lim { namespace asg {
  /**
  * \brief VisitorFilter class filters out nodes from the ASG.
  */
  class VisitorFilter : public Visitor {
    protected:
      /** \internal \brief Pointer to the set(Not)FilteredThisNodeOnly() method. */
      void (Factory::*selector)(NodeId id);

    public:
      /**
      * \brief Constructor for VisitorFilter.
      * \param filter [in] If this parameter is true then the visitor will filter the nodes out. If it is false then it set the nodes to not filtered.
      */
      VisitorFilter(bool filter = true);

      /**
      * \brief Destructor.
      */
      virtual ~VisitorFilter();

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const base::Comment& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const base::Component& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const base::ControlFlowBlock& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::Attribute& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::AttributeAccess& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::Class& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::ClassGeneric& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::ClassGenericInstance& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::ClassGenericSpec& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::Friendship& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::GenericParameter& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::Method& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::MethodCall& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::MethodGeneric& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::MethodGenericInstance& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::MethodGenericSpec& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::Package& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const logical::Parameter& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const physical::File& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const physical::FileSystem& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const physical::Folder& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::SimpleType& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::Type& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::TypeFormerArray& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::TypeFormerMethod& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::TypeFormerNonType& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::TypeFormerPointer& node , bool callVirtualBase = true);

      /**
      * \brief Deselects the actual node (and only this).
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::TypeFormerType& node , bool callVirtualBase = true);

  }; // VisitorFilter


}}}
#endif

