#include "../../inc/common.h"

namespace columbus { namespace symbolic {
    Memory::Memory(SymbolicEngine& _engine) : TreeElement<SmartDefinition, const Address, std::less<const Address> >(SmartDefinition(), NULL, NULL), engine(_engine) {}
	Memory::Memory(Memory& parent) : TreeElement<SmartDefinition, const Address, std::less<const Address> >(SmartDefinition(), &parent, NULL), engine(parent.engine) {}

	SmartDefinitionProxy Memory::getDefinitionByAddress(const Address& address) {
		return (*this)[address];
	}
	Address Memory::allocate() {
		return Address(engine.getNextAddress());
	}
}}