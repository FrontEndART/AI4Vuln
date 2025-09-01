#ifndef __SYMBOLIC_JAVA_ARRAY_H
#define __SYMBOLIC_JAVA_ARRAY_H
#include "Object.h"

namespace columbus { namespace symbolic {

	class Array : public Object {
	private:
		std::map<unsigned int, Address> indices;
		SmartDefinition size;

	public:
		Array(columbus::NodeId _type, SmartDefinition size, bool initialize, const Address& _address, SymbolicEngine& _engine, bool symbol);

		inline void initialize() { initialized=true; }
		inline bool isInitialized() const { return initialized; }
		inline void setArraySize(SmartDefinition size) { this->size=size; }
		inline SmartDefinition getArraySize() const { return size; }
		int getArrayDimension();
		static int getArrayDimension(NodeId type, SymbolicEngine& engine);
		NodeId getElementType();
		static NodeId getElementType(NodeId type, SymbolicEngine& engine);

		virtual bool isArray() const { return true; }

		Address getArrayElementAddress(SmartDefinition def);

		static Array& getRawArray(SmartDefinition reference, SymbolicEngine& engine, bool initializedAtDecl = false, bool initializedAtStatic = false);

		/**
		*	Typecast operators
		*/
		virtual SmartDefinition castToByte() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToChar() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToShort() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToInt() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToLong() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToFloat() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToDouble() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToReference(NodeId toType) const { throw SymbolicColumbusException("Should not be happenning"); }
		
	};
}}

#endif