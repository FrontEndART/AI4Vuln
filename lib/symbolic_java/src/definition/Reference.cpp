#include "../../inc/common.h"

using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

	const Address Reference::default_value(0);

	Reference::Reference(columbus::NodeId _type, const Address& address, SymbolicEngine& engine) : ValueDefinition<Reference,Address> (_type, address, engine) {
		csExpr = engine.getConstraintBuilder()->makeReferenceVar(*this);
	}
	
    
    Reference::Reference(const Address& value, columbus::NodeId _type, const Address& address, SymbolicEngine& engine, bool isSymbol) : ValueDefinition<Reference,Address> (value, _type, address, engine) {
        this->isSymbol = isSymbol;
		if (!isSymbol) {
			csExpr = engine.getConstraintBuilder()->makeReferenceValue(value);
		}
		else {
			csExpr = engine.getConstraintBuilder()->makeReferenceVar(*this);
		}
		
    }

	SmartDefinition Reference::unbox(const Reference& ref, SymbolicEngine& engine) {
		SmartDefinition result;
		auto unboxer = [&result, &engine](NodeId toInvestigate) -> bool {
			if (SymbolicTypesPreVisitor::getBooleanClassId() == toInvestigate) {
				result = DefinitionFactory::createBoolean(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getByteClassId() == toInvestigate) {
				result = DefinitionFactory::createByte(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getCharacterClassId() == toInvestigate) {
				result = DefinitionFactory::createChar(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getShortClassId() == toInvestigate) {
				result = DefinitionFactory::createShort(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getIntegerClassId() == toInvestigate) {
				result = DefinitionFactory::createInt(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getLongClassId() == toInvestigate) {
				result = DefinitionFactory::createLong(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getFloatClassId() == toInvestigate) {
				result = DefinitionFactory::createFloat(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getDoubleClassId() == toInvestigate) {
				result = DefinitionFactory::createDouble(engine);
				return true;
			}
			else if (SymbolicTypesPreVisitor::getStringClassId() == toInvestigate) {
				result = DefinitionFactory::createString(engine);
				return true;
			}
			return false;
		
		};
		if (unboxer(ref.getType())) {
			return result;
		}
		else {
			columbus::java::asg::base::Base& b = engine.getASGFactory().getRef(ref.getType());
			if (Common::getIsClassType(b)) {
				
				type::ClassType& casted = dynamic_cast<type::ClassType&>(b);
				columbus::java::asg::Factory::TurnFilterOffSafely sfact(engine.getASGFactory());
				if (casted.getRefersTo() != nullptr) {
					NodeId value = casted.getRefersTo()->getId();
					if (unboxer(value)) {
						return result;
					}
				}
			}
			throw SymbolicColumbusException("Attempting to unbox an unknown type");
			
		}
			
	}

	    //plus
    SmartDefinition Reference::plusImpl(const CharValueDefinition& def) const {
		return def.plus(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::plusImpl(const ByteValueDefinition& def) const {
		return def.plus(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::plusImpl(const ShortValueDefinition& def) const {
		return def.plus(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::plusImpl(const IntValueDefinition& def) const {
		return def.plus(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::plusImpl(const LongValueDefinition& def) const {
        return def.plus(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::plusImpl(const FloatValueDefinition& def) const {
		return def.plus(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::plusImpl(const DoubleValueDefinition& def) const {
        return def.plus(*Reference::unbox(*this, engine));
    }
	SmartDefinition Reference::plusImpl(const Reference& def) const {
		return def.plus(*Reference::unbox(*this, engine));
	}

	SmartDefinition Reference::plusImpl(const SymbolDefinition& def) const {
		//if(def.isS)
		return DefinitionFactory::createString(engine);
	}

    //minus
    SmartDefinition Reference::minusImpl(const CharValueDefinition& def) const {
		return def.minus(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::minusImpl(const ByteValueDefinition& def) const {
        return def.minus(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::minusImpl(const ShortValueDefinition& def) const {
        return def.minus(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::minusImpl(const IntValueDefinition& def) const {
        return def.minus(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::minusImpl(const LongValueDefinition& def) const {
        return def.minus(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::minusImpl(const FloatValueDefinition& def) const {
        return def.minus(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::minusImpl(const DoubleValueDefinition& def) const {
        return def.minus(*Reference::unbox(*this, engine));
    }

	SmartDefinition Reference::minusImpl(const Reference& def) const  {
		return def.minus(*Reference::unbox(*this, engine));
	}

    //times
    SmartDefinition Reference::timesImpl(const CharValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::timesImpl(const ByteValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::timesImpl(const ShortValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::timesImpl(const IntValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::timesImpl(const LongValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::timesImpl(const FloatValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }

    SmartDefinition Reference::timesImpl(const DoubleValueDefinition& def) const {
        return def.times(*Reference::unbox(*this, engine));
    }
	SmartDefinition Reference::timesImpl(const Reference& def) const  {
		return def.times(*Reference::unbox(*this, engine));
	}

    //divide
    SmartDefinition Reference::divideImpl(const CharValueDefinition& def) const {
		return def.divide(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::divideImpl(const ByteValueDefinition& def) const {
        return def.divide(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::divideImpl(const ShortValueDefinition& def) const {
        return def.divide(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::divideImpl(const IntValueDefinition& def) const {
        return def.divide(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::divideImpl(const LongValueDefinition& def) const {
        return def.divide(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::divideImpl(const FloatValueDefinition& def) const {
       return def.divide(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::divideImpl(const DoubleValueDefinition& def) const {
        return def.divide(*Reference::unbox(*this, engine));
    }
	SmartDefinition Reference::divideImpl(const Reference& def) const  {
		return def.divide(*Reference::unbox(*this, engine));
	}

    //remainder
    SmartDefinition Reference::remainderImpl(const CharValueDefinition& def) const {
		return def.remainder(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::remainderImpl(const ByteValueDefinition& def) const {
        return def.remainder(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::remainderImpl(const ShortValueDefinition& def) const {
        return def.remainder(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::remainderImpl(const IntValueDefinition& def) const {
        return def.remainder(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::remainderImpl(const LongValueDefinition& def) const {
        return def.remainder(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::remainderImpl(const Reference& def) const  {
		return def.remainder(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::remainderImpl(const FloatValueDefinition& def) const {
		return def.remainder(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::remainderImpl(const DoubleValueDefinition& def) const {
		return def.remainder(*Reference::unbox(*this, engine));
	}

    //bitwiseAndLogicalAnd
    SmartDefinition Reference::bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { 
		return def.bitwiseAndLogicalAnd(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const {
        return def.bitwiseAndLogicalAnd(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const {
        return def.bitwiseAndLogicalAnd(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const {
        return def.bitwiseAndLogicalAnd(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const {
        return def.bitwiseAndLogicalAnd(*Reference::unbox(*this, engine));
    }
	SmartDefinition Reference::bitwiseAndLogicalAndImpl(const Reference& def) const  {
		return def.bitwiseAndLogicalAnd(*Reference::unbox(*this, engine));
	}

    //bitwiseAndLogicalOr
    SmartDefinition Reference::bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const {
        return def.bitwiseAndLogicalOr(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const {
        return def.bitwiseAndLogicalOr(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const {
        return def.bitwiseAndLogicalOr(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const {
        return def.bitwiseAndLogicalOr(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const {
        return def.bitwiseAndLogicalOr(*Reference::unbox(*this, engine));
    }
	SmartDefinition Reference::bitwiseAndLogicalOrImpl(const Reference& def) const  {
		return def.bitwiseAndLogicalOr(*Reference::unbox(*this, engine));
	}

    //bitwiseAndLogicalXor
    SmartDefinition Reference::bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const {
        return def.bitwiseAndLogicalXor(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const {
        return def.bitwiseAndLogicalXor(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const {
        return def.bitwiseAndLogicalXor(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const {
        return def.bitwiseAndLogicalXor(*Reference::unbox(*this, engine));
    }
    SmartDefinition Reference::bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const {
        return def.bitwiseAndLogicalXor(*Reference::unbox(*this, engine));
    }
	SmartDefinition Reference::bitwiseAndLogicalXorImpl(const Reference& def) const  {
		return def.bitwiseAndLogicalXor(*Reference::unbox(*this, engine));
	}

	 //less
    SmartDefinition Reference::lessImpl(const CharValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessImpl(const ByteValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessImpl(const ShortValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessImpl(const IntValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessImpl(const LongValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessImpl(const FloatValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessImpl(const DoubleValueDefinition& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::lessImpl(const Reference& def) const {
		return def.less(*Reference::unbox(*this, engine));
	}

	//greater
	SmartDefinition Reference::greaterImpl(const CharValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterImpl(const ByteValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterImpl(const ShortValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterImpl(const IntValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterImpl(const LongValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterImpl(const FloatValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterImpl(const DoubleValueDefinition& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::greaterImpl(const Reference& def) const {
		return def.greater(*Reference::unbox(*this, engine));
	}

	//lessThanOrEqualTo
	SmartDefinition Reference::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::lessThanOrEqualToImpl(const Reference& def) const {
		return def.lessThanOrEqualTo(*Reference::unbox(*this, engine));
	}
		
	//greaterThanOrEqualTo
	SmartDefinition Reference::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::greaterThanOrEqualToImpl(const Reference& def) const {
		return def.greaterThanOrEqualTo(*Reference::unbox(*this, engine));
	}
		
	//equals
	SmartDefinition Reference::equalsImpl(const CharValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::equalsImpl(const ByteValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::equalsImpl(const ShortValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::equalsImpl(const IntValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::equalsImpl(const LongValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::equalsImpl(const FloatValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::equalsImpl(const DoubleValueDefinition& def) const {
		return def.equals(*Reference::unbox(*this, engine));
	}
	SmartDefinition Reference::equalsImpl(const Reference& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
		}
        return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	
	SmartDefinition Reference::equalsImpl(const Object& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
		}
		return DefinitionFactory::createBoolean(def.addressOf() == getValue(), engine);
	}
		
	//notEquals
	SmartDefinition Reference::notEqualsImpl(const CharValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::notEqualsImpl(const ByteValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::notEqualsImpl(const ShortValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::notEqualsImpl(const IntValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::notEqualsImpl(const LongValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::notEqualsImpl(const FloatValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::notEqualsImpl(const DoubleValueDefinition& def) const {
		return def.notEquals(*Reference::unbox(*this, engine));
		
	}
	
	SmartDefinition Reference::notEqualsImpl(const Object& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
		}
		return DefinitionFactory::createBoolean(def.addressOf() != getValue(), engine);
	}
	
	SmartDefinition Reference::notEqualsImpl(const Reference& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
		}
        return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}

	//conditionalAnd
    SmartDefinition Reference::conditionalAndImpl(const BooleanValueDefinition& def) const {
		return def.conditionalAnd(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::conditionalAndImpl(const Reference& def) const {
		return def.conditionalAnd(*Reference::unbox(*this, engine));
	}
        
	//conditionalOr
    SmartDefinition Reference::conditionalOrImpl(const BooleanValueDefinition& def) const {
		return def.conditionalOr(*Reference::unbox(*this, engine));
	}
    SmartDefinition Reference::conditionalOrImpl(const Reference& def) const {
		return def.conditionalOr(*Reference::unbox(*this, engine));
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition Reference::castToByte() const {
		return DefinitionFactory::createByte(engine);
	}
	SmartDefinition Reference::castToChar() const {
		return DefinitionFactory::createChar(engine);
	}
	SmartDefinition Reference::castToShort() const {
		return DefinitionFactory::createShort(engine);
	}
	SmartDefinition Reference::castToInt() const {
		return DefinitionFactory::createInt(engine);
	}
	SmartDefinition Reference::castToLong() const {
		return DefinitionFactory::createLong(engine);
	}
	SmartDefinition Reference::castToFloat() const {
		return DefinitionFactory::createFloat(engine);
	}
	SmartDefinition Reference::castToDouble() const {
		return DefinitionFactory::createDouble(engine);
	}
	SmartDefinition Reference::castToReference(columbus::NodeId toTypeId) const {
        const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		java::asg::base::Base& toType=factory.getRef(toTypeId);

        if (/*getType()==SymbolicTypesPreVisitor::getObjectTypeId() && */columbus::java::asg::Common::getIsArrayType(toType)) {
            // here we cast Object to array...
            return DefinitionFactory::createArray(toTypeId, DefinitionFactory::createSymbol(SymbolicTypesPreVisitor::getIntTypeId(), engine), true, engine, this->isSymbol);
        }
        return DefinitionFactory::createReference(this->value, toTypeId, engine, this->isSymbol);
	}

}}