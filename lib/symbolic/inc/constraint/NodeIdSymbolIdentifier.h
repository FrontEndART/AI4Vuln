#ifndef NODEID_SYMBOLIDENTIFIER_H
#define NODEID_SYMBOLIDENTIFIER_H

#include <boost/shared_ptr.hpp>
#include "SymbolIdentifier.h"
//#include "../structure/SymbolicCommon.h"
#include <sstream>

namespace columbus { namespace symbolic {
    
class NodeIdSymbolIdentifier : public SymbolIdentifier {

private:
    NodeId nodeId;
    
public:
    NodeIdSymbolIdentifier(NodeId nodeId);
    virtual ~NodeIdSymbolIdentifier();
    
    virtual bool operator<(const SymbolIdentifier& rhs) const;
    virtual void buildBackDefinitionInToProxyTree(State& state, const SmartDefinition& definition) const { }
    virtual SmartDefinitionProxy serachInProxyTree(State& state) const { return SmartDefinitionProxy(); };

     virtual bool isNodeIdSymbolIdentifier() const { return true; }

    // getters
    virtual const NodeId getNodeId() const { return nodeId; }

    virtual std::string toString() const;


};


}}

#endif
