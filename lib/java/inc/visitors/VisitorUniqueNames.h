#include "java/inc/java.h"

namespace columbus { namespace java { namespace asg {

class VisitorUniqueNames: public VisitorAbstractNodes {
public:
  void visit(const struc::TypeDeclaration &, bool callVirtualBase);
  void visit(const struc::Package &, bool);
  void visit(const struc::MethodDeclaration &, bool);
  void visit(const type::Type &node , bool callVirtualBase);
};

}}}