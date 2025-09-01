#ifndef __SYMBOLIC_JAVA_DEFINITION_FACTORY_H
#define __SYMBOLIC_JAVA_DEFINITION_FACTORY_H

#include "../common.h"

namespace columbus { namespace symbolic {

	class SymbolicEngine;
	
	class DefinitionFactory {
	private:
		static void checkType(columbus::NodeId typeId, SymbolicEngine& engine);

	public:
		static SmartDefinition createBoolean(bool value, SymbolicEngine& engine);
		static SmartDefinition createBoolean(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createBoolean(SymbolicEngine& engine);

		static SmartDefinition createByte(int8_t value, SymbolicEngine& engine);
		static SmartDefinition createByte(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createByte(SymbolicEngine& engine);

		static SmartDefinition createChar(wchar_t value, SymbolicEngine& engine);
		static SmartDefinition createChar(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createChar(SymbolicEngine& engine);

		static SmartDefinition createShort(short value, SymbolicEngine& engine);
		static SmartDefinition createShort(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createShort(SymbolicEngine& engine);
		
		static SmartDefinition createInt(int value, SymbolicEngine& engine);
		static SmartDefinition createInt(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createInt(SymbolicEngine& engine);

		static SmartDefinition createLong(long long value, SymbolicEngine& engine);
		static SmartDefinition createLong(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createLong(SymbolicEngine& engine);
		
		static SmartDefinition createDouble(double value, SymbolicEngine& engine);
		static SmartDefinition createDouble(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createDouble(SymbolicEngine& engine);

		static SmartDefinition createFloat(float value, SymbolicEngine& engine);
		static SmartDefinition createFloat(const Address& address, SymbolicEngine& engine);
		static SmartDefinition createFloat(SymbolicEngine& engine);	

		static SmartDefinition createReference(const Address& value, columbus::NodeId type, SymbolicEngine& engine, bool isSymbol = false);
        static SmartDefinition createReference(const Address& value, columbus::NodeId type, const Address& address, SymbolicEngine& engine, bool isSymbol = false);
		//static SmartDefinition createReference(columbus::NodeId type, SymbolicEngine& engine);
		//static SmartDefinition createReference(columbus::NodeId type, const Address& address, SymbolicEngine& engine);

		static SmartDefinition createString(SymbolicEngine& engine);
        

		static SmartDefinition createObject(columbus::NodeId type, bool initialize, SymbolicEngine& engine, bool returnSymbolReference = false);
		static SmartDefinition createObject(columbus::NodeId type, const Address& address, bool initialize, SymbolicEngine& engine, bool returnSymbolReference = false);
        static SmartDefinition createObjectWithoutReference(columbus::NodeId type, const Address& address, bool initialize, SymbolicEngine& engine);

		static SmartDefinition createArray(columbus::NodeId type, SmartDefinition size, bool initialize, SymbolicEngine& engine, bool returnSymbolReference = false);
		static SmartDefinition createArray(columbus::NodeId type, SmartDefinition size, const Address& address, bool initialize, SymbolicEngine& engine, bool returnSymbolReference = false);
        static SmartDefinition createArrayWithoutReference(columbus::NodeId type, SmartDefinition size, const Address& address, bool initialize, SymbolicEngine& engine);

		static SmartDefinition createSymbol(columbus::NodeId type, SymbolicEngine& engine);
		static SmartDefinition createSymbol(columbus::NodeId type, const Address& address, SymbolicEngine& engine);


		static SmartDefinition createDefaultInitializedDefinition(columbus::NodeId type, SymbolicEngine& engine);

		static SmartDefinition copy(SmartDefinition def, SymbolicEngine& engine); 

		static SmartDefinition createNegatedSymbol(SymbolicEngine& engine, const SymbolDefinition* original);
		static SmartDefinition createConditionalSymbol(SymbolicEngine& engine, const SymbolDefinition* original);
		
	};
}}

#endif