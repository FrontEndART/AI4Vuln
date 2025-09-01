#include "../../inc/common.h"

namespace columbus { namespace symbolic {
	
	using namespace columbus::java::asg;

	void DefinitionFactory::checkType(columbus::NodeId typeId, SymbolicEngine& engine) {
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		if (typeId==0) {
			throw SymbolicColumbusException("Attempting to create a definition with type 0");
		} 
		base::Base& base=factory.getRef(typeId);
		if (!Common::getIsType(base)) {
			throw SymbolicColumbusException("A non-type node provided when creating a definition");
		} 
	}
	
	SmartDefinition DefinitionFactory::createBoolean(bool value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new BooleanValueDefinition(value, address, engine))); 
	}

	SmartDefinition DefinitionFactory::createBoolean(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new BooleanValueDefinition(address, engine))); 
		return *(*(memory[address])=SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getBooleanTypeId(), address, engine))); 
	}

	SmartDefinition DefinitionFactory::createBoolean(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getBooleanTypeId(), address, engine)));
		//return *(*(memory[address])=SmartDefinition(new BooleanValueDefinition(address, engine))); 
	}

	SmartDefinition DefinitionFactory::createByte(int8_t value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new ByteValueDefinition(value, address, engine))); 
	}

	SmartDefinition DefinitionFactory::createByte(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new ByteValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getByteTypeId(), address, engine)));

	}

	SmartDefinition DefinitionFactory::createByte(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new ByteValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getByteTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createChar(wchar_t value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new CharValueDefinition(value, address, engine))); 
	}

	SmartDefinition DefinitionFactory::createChar(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new CharValueDefinition(address, engine))); 
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getCharTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createChar(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new CharValueDefinition(address, engine))); 
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getCharTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createInt(int value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new IntValueDefinition(value, address, engine)));
	}

	SmartDefinition DefinitionFactory::createInt(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new IntValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getIntTypeId(), address, engine)));

	}
	
	SmartDefinition DefinitionFactory::createInt(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new IntValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getIntTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createLong(long long value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new LongValueDefinition(value, address, engine)));
	}

	SmartDefinition DefinitionFactory::createLong(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new LongValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getLongTypeId(), address, engine)));
	}
		
	SmartDefinition DefinitionFactory::createLong(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new LongValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getLongTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createShort(short value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new ShortValueDefinition(value, address, engine)));
	}

	SmartDefinition DefinitionFactory::createShort(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new ShortValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getShortTypeId(), address, engine)));

	}
	
	SmartDefinition DefinitionFactory::createShort(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new ShortValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getShortTypeId(), address, engine)));

	}

	SmartDefinition DefinitionFactory::createDouble(double value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new DoubleValueDefinition(value, address, engine)));
	}

	SmartDefinition DefinitionFactory::createDouble(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new DoubleValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getDoubleTypeId(), address, engine)));

	}

	SmartDefinition DefinitionFactory::createDouble(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new DoubleValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getDoubleTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createString(SymbolicEngine& engine) {
		State& state = engine.getCurrentState();
		Memory& memory = state.getMemory();
		Address address = memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new DoubleValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getStringTypeId(), address, engine)));
	}

	SmartDefinition DefinitionFactory::createFloat(float value, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new FloatValueDefinition(value, address, engine)));
	}

	SmartDefinition DefinitionFactory::createFloat(const Address& address, SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		//return *(*(memory[address])=SmartDefinition(new FloatValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getFloatTypeId(), address, engine)));

	}

	SmartDefinition DefinitionFactory::createFloat(SymbolicEngine& engine) {
		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		//return *(*(memory[address])=SmartDefinition(new FloatValueDefinition(address, engine)));
		return *(*(memory[address]) = SmartDefinition(new SymbolDefinition(SymbolicTypesPreVisitor::getFloatTypeId(), address, engine)));
	}
	
	SmartDefinition DefinitionFactory::createReference(const Address& value, columbus::NodeId type, SymbolicEngine& engine, bool isSymbol) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

        if (!Common::getIsArrayType(typeRef)  && !Common::getIsScopedType(typeRef) && !Common::getIsNullType(typeRef) && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef) && !Common::getIsTypeVariable(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating a reference");
		}

		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();
		return *(*(memory[address])=SmartDefinition(new Reference(value, type, address, engine, isSymbol)));
	}
	
	//SmartDefinition DefinitionFactory::createReference(columbus::NodeId type, SymbolicEngine& engine) {
	//	checkType(type, engine);
	//	const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
	//	base::Base& base=factory.getRef(type);
	//	type::Type& typeRef=(type::Type&)base;

 //       if (!Common::getIsArrayType(typeRef)  && !Common::getIsScopedType(typeRef)
 //           && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef)) {
	//		throw SymbolicColumbusException("Invalid type when creating a reference");
	//	}

	//	State& state=engine.getCurrentState();
	//	Memory& memory=state.getMemory();
	//	Address address=memory.allocate();
	//	return *(*(memory[address])=SmartDefinition(new Reference(type, address, engine)));
	//}

	//SmartDefinition DefinitionFactory::createReference(columbus::NodeId type, const Address& address, SymbolicEngine& engine) {
	//	checkType(type, engine);
	//	const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
	//	base::Base& base=factory.getRef(type);
	//	type::Type& typeRef=(type::Type&)base;

	//	if (!Common::getIsArrayType(typeRef)  && !Common::getIsScopedType(typeRef) && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef)) {
	//		throw SymbolicColumbusException("Invalid type when creating a reference");
	//	}

	//	State& state=engine.getCurrentState();
	//	Memory& memory=state.getMemory();
	//	return *(*(memory[address])=SmartDefinition(new Reference(type, address, engine)));
	//}

    SmartDefinition DefinitionFactory::createReference(const Address& value, columbus::NodeId type, const Address& address, SymbolicEngine& engine, bool isSymbol) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (!Common::getIsArrayType(typeRef)  && !Common::getIsScopedType(typeRef) && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating a reference");
		}

		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		return *(*(memory[address])=SmartDefinition(new Reference(value, type, address, engine, isSymbol)));
	}



	SmartDefinition DefinitionFactory::createObject(columbus::NodeId type, bool initialize, SymbolicEngine& engine, bool returnSymbolReference) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

        if (!Common::getIsScopedType(typeRef) && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating an Object");
		}

		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();

		*(memory[address])=SmartDefinition(new Object(type, initialize, address, engine));
		return createReference(address, type, engine, returnSymbolReference);		
	}

	SmartDefinition DefinitionFactory::createObject(columbus::NodeId type, const Address& address, bool initialize, SymbolicEngine& engine, bool returnSymbolReference) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (!Common::getIsScopedType(typeRef) && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating an Object");
		}

		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();

		*(memory[address])=SmartDefinition(new Object(type, initialize, address, engine));
		return createReference(address, type, engine, returnSymbolReference);		
	}

    SmartDefinition DefinitionFactory::createObjectWithoutReference(columbus::NodeId type, const Address& address, bool initialize, SymbolicEngine& engine) {
        checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (Common::getIsNullType(typeRef)) {
			throw SymbolicColumbusException("NullType");
		}

		if (!Common::getIsScopedType(typeRef) && !Common::getIsParameterizedType(typeRef) && !Common::getIsWildcardType(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating an Object");
		}

         return SmartDefinition(new Object(type, initialize, address, engine));
    }

	SmartDefinition DefinitionFactory::createArray(columbus::NodeId type, SmartDefinition size, bool initialize, SymbolicEngine& engine, bool isSymbol) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (!Common::getIsArrayType(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating an Array");
		}

		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();
		Address address=memory.allocate();

		*(memory[address])=SmartDefinition(new Array(type, size, initialize, address, engine, isSymbol));
		return createReference(address, type, engine, false);		
	}

	SmartDefinition DefinitionFactory::createArray(columbus::NodeId type, SmartDefinition size, const Address& address, bool initialize, SymbolicEngine& engine, bool returnSymbolReference) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (!Common::getIsArrayType(typeRef)) {
			throw SymbolicColumbusException("Invalid type when creating an Array");
		}

		State& state=engine.getCurrentState();
		Memory& memory=state.getMemory();

		*(memory[address])=SmartDefinition(new Array(type, size, initialize, address, engine, returnSymbolReference));
		return createReference(address, type, engine, false);		
	}

    SmartDefinition DefinitionFactory::createArrayWithoutReference(columbus::NodeId type, SmartDefinition size, const Address& address, bool initialize, SymbolicEngine& engine) {
        checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (!Common::getIsArrayType(typeRef)) {
			if (Common::getIsNullType(typeRef)) {
				if(!initialize)
					throw SymbolicColumbusException("NullType");
				else
					throw SymbolicColumbusException("Inited NullType");
			}
			throw SymbolicColumbusException("Invalid type when creating an Array");
		}
        return SmartDefinition(new Array(type, size, initialize, address, engine, false));
    }

	SmartDefinition DefinitionFactory::createDefaultInitializedDefinition(columbus::NodeId type, SymbolicEngine & engine) {
		checkType(type, engine);
		const columbus::java::asg::Factory & factory = dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base & base = factory.getRef(type);
		type::Type & typeRef = (type::Type&)base;
		if (Common::getIsBooleanType(typeRef))
			return createBoolean(BooleanValueDefinition::default_value, engine);
		else if (Common::getIsByteType(typeRef))
			return createByte(ByteValueDefinition::default_value, engine);
		else if (Common::getIsCharType(typeRef))
			 return createChar(CharValueDefinition::default_value, engine);
		else if (Common::getIsShortType(typeRef))
			 return createShort(ShortValueDefinition::default_value, engine);
		else if (Common::getIsIntType(typeRef))
			 return createInt(IntValueDefinition::default_value, engine);
		else if (Common::getIsLongType(typeRef))
			 return createLong(LongValueDefinition::default_value, engine);
		else if (Common::getIsFloatType(typeRef))
			 return createFloat(FloatValueDefinition::default_value, engine);
		else if (Common::getIsDoubleType(typeRef))
			 return createDouble(DoubleValueDefinition::default_value, engine);
		else if (Common::getIsArrayType(typeRef)) {
			return createReference(Reference::default_value, type, engine);
		}
		else if (Common::getIsScopedType(typeRef)
			|| Common::getIsParameterizedType(typeRef)
			|| Common::getIsWildcardType(typeRef)) {
			return createReference(Reference::default_value, type, engine);
			
		} if (Common::getIsErrorType(typeRef)) {
				return createReference(Reference::default_value, SymbolicTypesPreVisitor::getObjectTypeId(), engine);
			}
		else
		throw SymbolicColumbusException("Illegal type argument!");
	}

	SmartDefinition DefinitionFactory::createNegatedSymbol(SymbolicEngine& engine, const SymbolDefinition* original) {
		State& state = engine.getCurrentState();
		Memory& memory = state.getMemory();
		Address address = memory.allocate();
		return *(*(memory[address]) = SmartDefinition(new NegatedSymbolDefinition(address, engine, original, true)));
	}

	SmartDefinition DefinitionFactory::createConditionalSymbol(SymbolicEngine& engine, const SymbolDefinition* original) {
		State& state = engine.getCurrentState();
		Memory& memory = state.getMemory();
		Address address = memory.allocate();
		return *(*(memory[address]) = SmartDefinition(new NegatedSymbolDefinition(address, engine, original, false)));
	}


	SmartDefinition DefinitionFactory::createSymbol(columbus::NodeId type, SymbolicEngine& engine) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;

		if (Common::getIsBooleanType(typeRef))
			return createBoolean(engine);
		else if (Common::getIsByteType(typeRef))
			return createByte(engine);
		else if (Common::getIsCharType(typeRef))
			return createChar(engine);
		else if (Common::getIsShortType(typeRef))
			return createShort(engine);
		else if (Common::getIsIntType(typeRef))
			return createInt(engine);
		else if (Common::getIsLongType(typeRef))
			return createLong(engine);
		else if (Common::getIsFloatType(typeRef))
			return createFloat(engine);
		else if (Common::getIsDoubleType(typeRef))
			return createDouble(engine);
		else if (Common::getIsStringLiteral(typeRef))
			return createString(engine);
        else if (Common::getIsArrayType(typeRef)) {
            State& state=engine.getCurrentState();
		    Memory& memory=state.getMemory();
		    Address refValue=memory.allocate();
            return createReference(refValue, type, engine, true);
        } else if (Common::getIsScopedType(typeRef)
                || Common::getIsParameterizedType(typeRef)
                || Common::getIsWildcardType(typeRef) || Common::getIsTypeVariable(typeRef) || Common::getIsEnum(typeRef)) {
            State& state=engine.getCurrentState();
		    Memory& memory=state.getMemory();
		    Address refValue=memory.allocate();
            return createReference(refValue, type, engine, true);
        } else if (Common::getIsErrorType(typeRef)) {
            // if type is error type, we create symbol with type of Object
            State& state=engine.getCurrentState();
		    Memory& memory=state.getMemory();
		    Address refValue=memory.allocate();
            return createReference(refValue, SymbolicTypesPreVisitor::getObjectTypeId(), engine, true);
        }
		else if (Common::getIsNullType(typeRef)) {
			return createReference(Reference::default_value, SymbolicTypesPreVisitor::getObjectTypeId(), engine, true);
		}
		else {
            throw SymbolicColumbusException("Illegal type argument!");
        }
	}

	SmartDefinition DefinitionFactory::createSymbol(columbus::NodeId type, const Address& address, SymbolicEngine& engine) {
		checkType(type, engine);
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		base::Base& base=factory.getRef(type);
		type::Type& typeRef=(type::Type&)base;
		if (Common::getIsBooleanType(typeRef))
			return createBoolean(address, engine);
		else if (Common::getIsByteType(typeRef))
			return createByte(address, engine);
		else if (Common::getIsCharType(typeRef))
			return createChar(address, engine);
		else if (Common::getIsShortType(typeRef))
			return createShort(address, engine);
		else if (Common::getIsIntType(typeRef))
			return createInt(address, engine);
		else if (Common::getIsLongType(typeRef))
			return createLong(address, engine);
		else if (Common::getIsFloatType(typeRef))
			return createFloat(address, engine);
		else if (Common::getIsDoubleType(typeRef))
			return createDouble(address, engine);
		else if (Common::getIsStringLiteral(typeRef))
			return createString(engine);
        else if (Common::getIsArrayType(typeRef)) {
            State& state=engine.getCurrentState();
		    Memory& memory=state.getMemory();
		    Address refValue=memory.allocate();
            return createReference(refValue, type, address, engine, true);
        } else if (Common::getIsScopedType(typeRef)
                || Common::getIsParameterizedType(typeRef)
                || Common::getIsWildcardType(typeRef)) {
			State& state=engine.getCurrentState();
		    Memory& memory=state.getMemory();
		    Address refValue=memory.allocate();
            return createReference(refValue, type, address, engine, true);
        } else if (Common::getIsErrorType(typeRef)) {
            State& state=engine.getCurrentState();
		    Memory& memory=state.getMemory();
		    Address refValue=memory.allocate();
			return createReference(refValue, SymbolicTypesPreVisitor::getObjectTypeId(), address, engine, true);
        } else {
            throw SymbolicColumbusException("Illegal type argument!");
        }
	}

	//TODO!!!!
	SmartDefinition DefinitionFactory::copy(SmartDefinition def, SymbolicEngine& engine) {
        if (def->getIsSymbol() && !def->isReference()) // because symbol references have a value
			return createSymbol(def->getType(), engine);

		NodeId type=def->getType();
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		type::Type& typeRef=(type::Type&)factory.getRef(type);
		if (Common::getIsBooleanType(typeRef))
			return createBoolean(((BooleanValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsByteType(typeRef))
			return createByte(((ByteValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsCharType(typeRef))
			return createChar(((CharValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsShortType(typeRef))
			return createShort(((ShortValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsIntType(typeRef))
			return createInt(((IntValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsLongType(typeRef))
			return createLong(((LongValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsFloatType(typeRef))
			return createFloat(((FloatValueDefinition&)(*def)).getValue(), engine);
		else if (Common::getIsDoubleType(typeRef))
			return createDouble(((DoubleValueDefinition&)(*def)).getValue(), engine);
        else if (Common::getIsArrayType(typeRef)) {
            return createReference(((Reference&)(*def)).getReferenceValue(), type, engine, def->getIsSymbol());
        } else if (Common::getIsScopedType(typeRef)
                || Common::getIsParameterizedType(typeRef)
                || Common::getIsWildcardType(typeRef)) {
			return createReference(((Reference&)(*def)).getReferenceValue(), type, engine, def->getIsSymbol());
        } 
		else if (Common::getIsNullType(typeRef)) {
			return createReference(Address(0), SymbolicTypesPreVisitor::getNullTypeId(), engine, false);
		}
		else 
			throw SymbolicColumbusException("Illegal type argument!"); 
		
	}

}}