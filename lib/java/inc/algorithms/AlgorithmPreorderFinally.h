#ifndef _JAVA_ALGORITHM_PREORDERFINALLY_H_
#define _JAVA_ALGORITHM_PREORDERFINALLY_H_

#include "java/inc/java.h"

namespace columbus { namespace java { namespace asg {
	
	class AlgorithmPreorderFinally : public AlgorithmPreorder {
		virtual void visit(const statm::Block& node, bool callVirtualBase = true);
	};
	
}}}

#endif
