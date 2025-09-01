#ifndef __SYMBOLIC_MEMORY_H
#define __SYMBOLIC_MEMORY_H

#include "../common.h"

namespace columbus { namespace symbolic {
	class Memory : public TreeElement<SmartDefinition, const Address, std::less<const Address> > {

	private:
		SymbolicEngine& engine;

	public:
		Memory(SymbolicEngine& engine);
		Memory(Memory& parent);

		SmartDefinitionProxy getDefinitionByAddress(const Address& address);
		Address allocate();
	};
}}

#endif