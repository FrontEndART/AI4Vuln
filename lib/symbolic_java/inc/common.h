#ifndef __SYMBOLIC_JAVA_COMMON_H
#define __SYMBOLIC_JAVA_COMMON_H

#include <boost/algorithm/string/predicate.hpp>

#include <java/inc/java.h>
#include <symbolic/inc/common.h>

namespace columbus { namespace symbolic {

	/**
	*	Forward declarations...
	*/
    

}}

#include "algorithms/SymbolicTypesPreVisitor.h"
#include "definition/DefinitionDispatcherTargetInterface.h"
#include "definition/DefinitionDispatcher.h"
#include "definition/ValueDefinition.h"
#include "definition/ValueDefinition.hpp"
#include "definition/BooleanValueDefinition.h"
#include "definition/ByteValueDefinition.h"
#include "definition/CharValueDefinition.h"
#include "definition/DoubleValueDefinition.h"
#include "definition/FloatValueDefinition.h"
#include "definition/IntValueDefinition.h"
#include "definition/LongValueDefinition.h"
#include "definition/ShortValueDefinition.h"
#include "definition/Reference.h"
#include "definition/Object.h"
#include "definition/Array.h"
#include "definition/SymbolDefinition.h"
#include "definition/DefinitionFactory.h"
#include "algorithms/SymbolicExecutor.h"

#include "printer/JavaStateTreeElementPrinter.h"

#include "structure/StateFactoryJava.h"
#include "listener/PrintStateListener.h"
#include "listener/JavaLimWriteListener.h"
#include "listener/CsvStateListener.h"
#include "listener/TxtOutputWriter.h"
#include "listener/JsonOutputWriter.h"

#include "structure/StackTraceJava.h"
#include "structure/StateJava.h"

#include "algorithms/AsgUtils.h"

#include "constraint/Z3Solver.h"
#include "constraint/Z3ConstraintBuilder.h"



#endif
