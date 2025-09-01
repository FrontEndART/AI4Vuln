

#ifndef _LIM_VISITOR_OVERRIDE_H_
#define _LIM_VISITOR_OVERRIDE_H_

#include "lim/inc/lim.h"

namespace columbus{ namespace lim { namespace asg {


class VisitorOverride : public VisitorAbstractNodes {
public:

	VisitorOverride(const Factory&, OverrideRelations &);

	virtual void visit(const logical::Method&, bool callVirtualBase);


private:

	  bool _getIsOverride(const logical::Method&, const logical::Method&) const;

	  const Factory &_factory;
    OverrideRelations &_overrides;
};

}}}
#endif
