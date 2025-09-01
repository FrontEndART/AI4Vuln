#ifndef _SYMBOLIC_COMMON_H_
#define _SYMBOLIC_COMMON_H_

#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <functional>
#include <boost/config.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include "../structure/ExceptionalStateException.h"
#include "../definition/Address.h"
//#include "../common.h"

namespace columbus { namespace symbolic {
    //forwards
    class Definition;
    class StateListener;

    template<class T_PTR> struct ltDeref {
        bool operator()(T_PTR p0,T_PTR p1) const { return *p0 < *p1; }
    };

    /*template<class VTY, class ITY, class LESS> class TreeElementProxy;
    template<class VTY, class ITY, class LESS> class ProxyTree;
    template<class VTY, class ITY, class LESS> class TreeElement;
    template<class VTY, class ITY> class CommonProxyInterface;*/
	class Configuration;
    template<class VTY, class ITY, class LESS>
    class ProxyTree;
    template<class VTY, class ITY, class LESS>
    class TreeElement;
    template<class VTY, class ITY, class LESS>
    class TreeElementProxy;
    template<class VTY, class ITY>
    class CommonProxyInterface;

    typedef boost::shared_ptr<const Definition> SmartDefinition;
    typedef boost::shared_ptr<TreeElementProxy<SmartDefinition, const Address, std::less<const Address> > > SmartDefinitionProxy;
    //typedef boost::shared_ptr<CommonProxyInterface<SmartDefinition, SmartDefinition> > SmartDefinitionCommonProxy;

    //typedef boost::shared_ptr<TreeElementProxy<SmartDefinition, SmartDefinition, ArrayIndexLess> > SmartDefinitionArrayProxy;
    //typedef boost::shared_ptr<TreeElementProxy<SmartDefinition, NodeId, std::less<NodeId> > > SmartDefinitionClassProxy;
    //typedef TreeElement<SmartDefinition, SmartDefinition, ltDeref<SmartDefinition> > Context;
    //typedef TreeElement<SmartDefinition, SmartDefinition, ArrayIndexLess> ArrayContext;    

    //typedef IType<columbus::NodeId> NodeIdIDX;
    //typedef IType<const Definition*> DefinitionIDX;

    static const unsigned int MAGIC_HASH = 1299709;

    class Constraint;
    typedef std::set<Constraint*, ltDeref<Constraint*> > ConstraintSet;


    class SymbolicCommon {
    public:
        virtual NodeId smartDefinitionToNodeId(const SmartDefinition& def) const = 0;
        virtual ~SymbolicCommon() { }
    };

}}

#endif
