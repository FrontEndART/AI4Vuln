#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    ByteValueDefinition::ByteValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<ByteValueDefinition, int8_t>(SymbolicTypesPreVisitor::getByteTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeByteVar(*this);
	}

	ByteValueDefinition::ByteValueDefinition(int8_t value, const Address& address, SymbolicEngine& engine) : ValueDefinition<ByteValueDefinition, int8_t>(value,  SymbolicTypesPreVisitor::getByteTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeByteValue(value);
	}  

	SmartDefinition ByteValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
	}

	SmartDefinition ByteValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition ByteValueDefinition::lessImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
	}
	SmartDefinition ByteValueDefinition::greaterImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
	}
	SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
	}
	SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
	}

    //plus

	SmartDefinition ByteValueDefinition::plusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition ByteValueDefinition::minusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition ByteValueDefinition::timesImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition ByteValueDefinition::divideImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}
    SmartDefinition ByteValueDefinition::plusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::plusImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::plusImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::plusImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::plusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::plusImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() + getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::plusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }
	SmartDefinition ByteValueDefinition::plusImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->plus(*this);
	}

    //minus
    SmartDefinition ByteValueDefinition::minusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::minusImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::minusImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::minusImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::minusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::minusImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::minusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }

	SmartDefinition ByteValueDefinition::minusImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->minus(*this);
	}

    //times
    SmartDefinition ByteValueDefinition::timesImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::timesImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::timesImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::timesImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::timesImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::timesImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::timesImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
	SmartDefinition ByteValueDefinition::timesImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->times(*this);
	}
    //divide
    SmartDefinition ByteValueDefinition::divideImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::divideImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::divideImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::divideImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::divideImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::divideImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::divideImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
	SmartDefinition ByteValueDefinition::divideImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->divide(*this);
	}
    //remainder
    SmartDefinition ByteValueDefinition::remainderImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::remainderImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::remainderImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::remainderImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::remainderImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::remainderImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->remainder(*this);
	}

	SmartDefinition ByteValueDefinition::remainderImpl(const DoubleValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}

	SmartDefinition ByteValueDefinition::remainderImpl(const FloatValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod(def.getValue(), getValue()), engine);
	}

    //bitwiseAndLogicalAnd
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { 
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
	SmartDefinition ByteValueDefinition::bitwiseAndLogicalAndImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalAnd(*this);
	}

    //bitwiseAndLogicalOr
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
	SmartDefinition ByteValueDefinition::bitwiseAndLogicalOrImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalOr(*this);
	}

    //bitwiseAndLogicalXor
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ByteValueDefinition::bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
	SmartDefinition ByteValueDefinition::bitwiseAndLogicalXorImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalXor(*this);
	}

	 //less
    SmartDefinition ByteValueDefinition::lessImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::lessImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->less(*this);
	}

	//greater
	SmartDefinition ByteValueDefinition::greaterImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::greaterImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greater(*this);
	}

	//lessThanOrEqualTo
	SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::lessThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->lessThanOrEqualTo(*this);
	}
		
	//greaterThanOrEqualTo
	SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greaterThanOrEqualTo(*this);
	}
		
	//equals
	SmartDefinition ByteValueDefinition::equalsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::equalsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::equalsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::equalsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::equalsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::equalsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::equalsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}
		
	//notEquals
	SmartDefinition ByteValueDefinition::notEqualsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::notEqualsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::notEqualsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}
		
    SmartDefinition ByteValueDefinition::assignValueImpl(const ByteValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createByte(engine);
        }
        return DefinitionFactory::createByte(getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::assignValueImpl(const ShortValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createShort(engine);
        }
        return DefinitionFactory::createShort(getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::assignValueImpl(const IntValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createInt(engine);
        }
        return DefinitionFactory::createInt(getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::assignValueImpl(const LongValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createLong(engine);
        }
        return DefinitionFactory::createLong(getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::assignValueImpl(const CharValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createChar(engine);
        }
        return DefinitionFactory::createChar(getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::assignValueImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createFloat(engine);
        }
        return DefinitionFactory::createFloat(getValue(), engine);
    }

    SmartDefinition ByteValueDefinition::assignValueImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createDouble(engine);
        }
        return DefinitionFactory::createDouble(getValue(), engine);
    }

	SmartDefinition ByteValueDefinition::assignValueImpl(const Reference& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!");};


	/**
	*	Unary operators
	*/
	SmartDefinition ByteValueDefinition::increment() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue()+1, engine);
	}
    SmartDefinition ByteValueDefinition::decrement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue()-1, engine);
	}
	SmartDefinition ByteValueDefinition::prePlus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(+getValue(), engine);
	}
    SmartDefinition ByteValueDefinition::preMinus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(-getValue(), engine);
	}
    
    SmartDefinition ByteValueDefinition::complement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(~getValue(), engine);
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition ByteValueDefinition::castToByte() const {
		return DefinitionFactory::createByte(getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToChar() const {
		return DefinitionFactory::createChar(getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToShort() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createShort(engine);
		}
		return DefinitionFactory::createShort(getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToInt() const {
		return DefinitionFactory::createInt(getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToLong() const {
		return DefinitionFactory::createLong(getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToFloat() const {
		return DefinitionFactory::createFloat((float)getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToDouble() const {
		return DefinitionFactory::createDouble((double)getValue(), engine);
	}
	SmartDefinition ByteValueDefinition::castToReference(columbus::NodeId toType) const {
		return DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(toType), true, engine);
	}
}}
