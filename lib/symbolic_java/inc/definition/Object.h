#ifndef __SYMBOLIC_JAVA_OBJECT_H
#define __SYMBOLIC_JAVA_OBJECT_H
#include <symbolic/inc/definition/Definition.h>
#include <symbolic/inc/definition/Address.h>

namespace columbus { namespace symbolic {
	class Object : public ValueDefinition<Object, Address> {
	private:
		std::map<columbus::NodeId, Address> members;

	protected:
		bool initialized;

	public:
		static const Address default_value;
        Object(columbus::NodeId _type, bool initialize, const Address& _address, SymbolicEngine& _engine, bool symbol = false);

		inline bool isInitialized() { return initialized; }

		Address getMemberAddress(columbus::NodeId nodeId);
		virtual bool getIsSymbol() const { return isSymbol; }

		static Object& getRawObject(SmartDefinition reference, SymbolicEngine& engine);

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
		virtual SmartDefinition castToBoolean() const { throw SymbolicColumbusException("Should not be happenning"); }

		virtual SmartDefinition equalsImpl(const Object& def) const;
		virtual SmartDefinition equalsImpl(const Reference& def) const;
	};
}}

#endif