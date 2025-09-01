#ifndef _LIM_VisitorClassDiagram_H_
#define _LIM_VisitorClassDiagram_H_

#include "lim/inc/lim.h"

namespace columbus { namespace lim { namespace asg {

  class VisitorClassDiagram : public VisitorAbstractNodes {

  public:

    // Constructs a new instance of the VisitorClassDiagram class
    VisitorClassDiagram(const Factory& fact, ClassDiagram& cd);

    // Visits a node of type Class&
    virtual void visit(const logical::Class& node, bool callVirtualBase);
    virtual void visit(const logical::Package& node, bool callVirtualBase);

    // Finalizes the gathered data - must be called when all Class& object has been visited
    // Processes the methodcalls and puts association connection between classes containing
    // the methods
    void postProcess();

  protected:

    void checkForInheritance(const logical::Class& node);
    void checkForAggrComp(const logical::Class& node);
    void checkForAssoc(const logical::Class& node);

    void processMethod(const logical::Method& node, NodeId classid);
    void postProcessMethod(const NodeId mid, const NodeId cid);
    void getMethodsFromClass(const logical::Class& node);
    void getAttributesFromClass(const logical::Class& node);

    const Factory& _fact;
    ClassDiagram& _cd;
    std::map<NodeId, NodeId> _methmap;

  };

}}} // columbus::lim::asg

#endif
