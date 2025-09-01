#ifndef __SYMBOLIC_COMMON_H
#define __SYMBOLIC_COMMON_H

#include <queue>

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>


namespace columbus { namespace symbolic {
    /**
    *	Forward declarations
    */
    class AbstractSymbolicExecutor;
    class SearchStrategy;
    class BreadthFirstSearchStrategy;
    class DepthFirstSearchStrategy;
    class StateExpanderInterface;
    class SymbolicEngine;

    class Address;
    class Definition;

    class StateListener;
    class WarningListener;

    /*class Configuration;
    template<class VTY, class ITY, class LESS>
    class ProxyTree;
    template<class VTY, class ITY, class LESS>
    class TreeElement;
    template<class VTY, class ITY, class LESS>
    class TreeElementProxy;
    template<class VTY, class ITY>
    class CommonProxyInterface;*/
    class StackTrace;
    class State;
    class StateFactory;
    class SymbolicColumbusException;

    //typedef boost::shared_ptr<const Definition> SmartDefinition;
    //typedef boost::shared_ptr<TreeElementProxy<SmartDefinition, const Address, std::less<const Address> > > SmartDefinitionProxy;
    //typedef TreeElement<SmartDefinition, const Address, std::less<const Address> > Context;

    enum CallType {
        NewClass,
        MethodCall,
        NoCall
    };

    enum BooleanInfixOperatorKind {
        biokNONE,
        biokLOGICAL_OR,
        biokLOGICAL_AND
    };

    enum CastTypes { NONE, TO_INT, TO_CHAR, TO_BYTE, TO_FLOAT, TO_DOUBLE, TO_SHORT, TO_LONG, TO_REFERENCE };
}}

/**
*	Common includes
*/

#include <cfg/inc/cfg.h>
#include <rul/inc/RulHandler.h>
#include <graph/inc/graph.h>
#include "structure/SymbolicCommon.h"

#include "constraint/NodeIdSymbolIdentifier.h"
#include "constraint/SymbolIdentifier.h"
#include "constraint/Constraint.h"

#include "structure/SymbolicColumbusException.h"
#include "structure/ProxyTree.h"
#include "structure/ProxyTree.hpp"
#include "algorithms/AbstractSymbolicExecutor.h"
#include "algorithms/SearchStrategy.h"
#include "algorithms/BreadthFirstSearchStrategy.h"
#include "algorithms/DepthFirstSearchStrategy.h"
#include "algorithms/StateExpanderInterface.h"


#include "definition/Address.h"
#include "definition/Definition.h"

#include "structure/StackTrace.h"
#include "listener/StateListener.h"
#include "listener/WarningListener.h"

#include "structure/Configuration.h"

#include "structure/Memory.h"
#include "structure/Locals.h"
#include "structure/State.h"
#include "structure/StateFactory.h"

#include "algorithms/SymbolicEngine.h"


//#include "constraint/ConstraintSolverExpr.h"


namespace columbus { namespace symbolic {

    

}}

#endif
