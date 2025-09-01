#include "../../inc/common.h"

namespace columbus { namespace symbolic {

NodeIdSymbolIdentifier::NodeIdSymbolIdentifier(NodeId nodeId) : SymbolIdentifier(), nodeId(nodeId) {
}


NodeIdSymbolIdentifier::~NodeIdSymbolIdentifier() {
}

bool NodeIdSymbolIdentifier::operator<(const SymbolIdentifier& rhs) const {
    if (!rhs.isNodeIdSymbolIdentifier()) {
        return true;
    }

    const NodeIdSymbolIdentifier &identifier = dynamic_cast<const NodeIdSymbolIdentifier&>(rhs);
    return nodeId < identifier.nodeId;
}

std::string NodeIdSymbolIdentifier::toString() const {
    std::stringstream ss;
    ss << nodeId;
    return ss.str();
}

}}
