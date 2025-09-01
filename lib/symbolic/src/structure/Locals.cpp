#include "../../inc/common.h"

namespace columbus { namespace symbolic {

	Locals::Locals(SymbolicEngine& _engine) : TreeElement<Address, columbus::NodeId, std::less<columbus::NodeId> >(0, NULL, NULL), engine(_engine) {}
	Locals::Locals(Locals& parent) : TreeElement<Address, columbus::NodeId, std::less<columbus::NodeId> >(0, &parent, NULL), engine(parent.engine) {}

	Address Locals::getRefersToAddress(columbus::NodeId nodeId) {
		return *(*this)[nodeId];
	}

}}
