#ifndef __SYMBOLIC_ADDRESS_H
#define __SYMBOLIC_ADDRESS_H

//#include "../common.h"

namespace columbus { namespace symbolic {
	class Address {
	private:
		int address;

	public:
		Address(unsigned int _address, bool isSymbol=false) : address(isSymbol ? -(signed int)_address : _address) {}
		operator int() const { return address; }
		bool isSymbol() { return address<0; }
		bool operator<(const Address& rhs) const { return address<rhs.address; }
		bool operator!=(const Address& rhs) const { return address!=rhs.address; }
        bool operator==(const Address& rhs) const { return address==rhs.address; }
		Address& operator=(const Address& rhs) { address=rhs.address; return *this;}
		//operator std::string()const {
		//	return "addr_" + std::to_string(address);
		//}
	};
}}
#endif