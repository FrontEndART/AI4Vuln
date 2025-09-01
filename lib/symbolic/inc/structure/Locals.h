#ifndef __SYMBOLIC_LOCALS_H
#define __SYMBOLIC_LOCALS_H

#include "../common.h"

namespace columbus { namespace symbolic {
	class Locals : public TreeElement<Address, columbus::NodeId, std::less<columbus::NodeId> > {

	private:
		SymbolicEngine& engine;

	public:
		Locals(SymbolicEngine& engine);
		Locals(Locals& parent);

		Address getRefersToAddress(columbus::NodeId nodeId);

	};
}}

#endif