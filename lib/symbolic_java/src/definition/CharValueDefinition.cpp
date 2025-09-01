#include "../../inc/common.h"

namespace columbus { namespace symbolic {

	/*CharValueDefinition::CharValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<CharValueDefinition, wchar_t>(SymbolicTypesPreVisitor::getCharTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeCharVar(*this);
	}*/

	CharValueDefinition::CharValueDefinition(char16_t value, const Address& address, SymbolicEngine& engine) : ValueDefinition<CharValueDefinition, char16_t>(value,  SymbolicTypesPreVisitor::getCharTypeId(), address, engine) { 
		csExpr = engine.getConstraintBuilder()->makeCharValue(value);
	}  

    //plus
    SmartDefinition CharValueDefinition::plusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition CharValueDefinition::plusImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition CharValueDefinition::plusImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition CharValueDefinition::plusImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition CharValueDefinition::plusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition CharValueDefinition::plusImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() + getValue(), engine);
    }

    SmartDefinition CharValueDefinition::plusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }
	SmartDefinition CharValueDefinition::plusImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->plus(*this);
	}

	SmartDefinition CharValueDefinition::plusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition CharValueDefinition::minusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition CharValueDefinition::timesImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition CharValueDefinition::divideImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition CharValueDefinition::remainderImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition CharValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
	}

	SmartDefinition CharValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition CharValueDefinition::lessImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);

	}
	SmartDefinition CharValueDefinition::greaterImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
	}
	SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
	}
	SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
	}

    //minus
    SmartDefinition CharValueDefinition::minusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition CharValueDefinition::minusImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition CharValueDefinition::minusImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition CharValueDefinition::minusImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition CharValueDefinition::minusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition CharValueDefinition::minusImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition CharValueDefinition::minusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }

	SmartDefinition CharValueDefinition::minusImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->minus(*this);
	}

    //times
    SmartDefinition CharValueDefinition::timesImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition CharValueDefinition::timesImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition CharValueDefinition::timesImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition CharValueDefinition::timesImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition CharValueDefinition::timesImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition CharValueDefinition::timesImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }

    SmartDefinition CharValueDefinition::timesImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
	SmartDefinition CharValueDefinition::timesImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->times(*this);
	}
    //divide
    SmartDefinition CharValueDefinition::divideImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition CharValueDefinition::divideImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition CharValueDefinition::divideImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition CharValueDefinition::divideImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition CharValueDefinition::divideImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition CharValueDefinition::divideImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition CharValueDefinition::divideImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
	SmartDefinition CharValueDefinition::divideImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->divide(*this);
	}
    //remainder
    SmartDefinition CharValueDefinition::remainderImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition CharValueDefinition::remainderImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition CharValueDefinition::remainderImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition CharValueDefinition::remainderImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition CharValueDefinition::remainderImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition CharValueDefinition::remainderImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->remainder(*this);
	}

	SmartDefinition CharValueDefinition::remainderImpl(const DoubleValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}

	SmartDefinition CharValueDefinition::remainderImpl(const FloatValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod(def.getValue(), getValue()), engine);
	}

    //bitwiseAndLogicalAnd
    SmartDefinition CharValueDefinition::bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { 
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
	SmartDefinition CharValueDefinition::bitwiseAndLogicalAndImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalAnd(*this);
	}

    //bitwiseAndLogicalOr
    SmartDefinition CharValueDefinition::bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
	SmartDefinition CharValueDefinition::bitwiseAndLogicalOrImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalOr(*this);
	}

    //bitwiseAndLogicalXor
    SmartDefinition CharValueDefinition::bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition CharValueDefinition::bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
	SmartDefinition CharValueDefinition::bitwiseAndLogicalXorImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalXor(*this);
	}

	 //less
    SmartDefinition CharValueDefinition::lessImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
	SmartDefinition CharValueDefinition::lessImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->less(*this);
	}

	//greater
	SmartDefinition CharValueDefinition::greaterImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
	SmartDefinition CharValueDefinition::greaterImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greater(*this);
	}

	//lessThanOrEqualTo
	SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
	SmartDefinition CharValueDefinition::lessThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->lessThanOrEqualTo(*this);
	}
		
	//greaterThanOrEqualTo
	SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
	SmartDefinition CharValueDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greaterThanOrEqualTo(*this);
	}
		
	//equals
	SmartDefinition CharValueDefinition::equalsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition CharValueDefinition::equalsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition CharValueDefinition::equalsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition CharValueDefinition::equalsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition CharValueDefinition::equalsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition CharValueDefinition::equalsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition CharValueDefinition::equalsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	SmartDefinition CharValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}
		
	//notEquals
	SmartDefinition CharValueDefinition::notEqualsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition CharValueDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition CharValueDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition CharValueDefinition::notEqualsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition CharValueDefinition::notEqualsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition CharValueDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition CharValueDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
	SmartDefinition CharValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}	
	
    //assignValue
    SmartDefinition CharValueDefinition::assignValueImpl(const ByteValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createByte(engine);
        }
        return DefinitionFactory::createByte(getValue(), engine);
    }

    SmartDefinition CharValueDefinition::assignValueImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createShort(engine);
        }
        return DefinitionFactory::createShort(getValue(), engine);
    }

    SmartDefinition CharValueDefinition::assignValueImpl(const IntValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createInt(engine);
        }
        return DefinitionFactory::createInt(getValue(), engine);
    }

    SmartDefinition CharValueDefinition::assignValueImpl(const LongValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createLong(engine);
        }
        return DefinitionFactory::createLong(getValue(), engine);
    }

    SmartDefinition CharValueDefinition::assignValueImpl(const CharValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createChar(engine);
        }
        return DefinitionFactory::createChar(getValue(), engine);
    }

    SmartDefinition CharValueDefinition::assignValueImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createFloat(engine);
        }
        return DefinitionFactory::createFloat(getValue(), engine);
    }

    SmartDefinition CharValueDefinition::assignValueImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createDouble(engine);
        }
        return DefinitionFactory::createDouble(getValue(), engine);
    }

	SmartDefinition CharValueDefinition::assignValueImpl(const Reference& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!");};

	/**
	*	Unary operators
	*/
	SmartDefinition CharValueDefinition::increment() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue()+1, engine);
	}
    SmartDefinition CharValueDefinition::decrement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue()-1, engine);
	}
	SmartDefinition CharValueDefinition::prePlus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(+getValue(), engine);
	}
    SmartDefinition CharValueDefinition::preMinus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(-getValue(), engine);
	}
    
    SmartDefinition CharValueDefinition::complement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(~getValue(), engine);
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition CharValueDefinition::castToByte() const {
		return DefinitionFactory::createByte(getValue() & 0xFF, engine);
	}
	SmartDefinition CharValueDefinition::castToChar() const {
		return DefinitionFactory::createChar(getValue(), engine);
	}
	SmartDefinition CharValueDefinition::castToShort() const {
		return DefinitionFactory::createShort(getValue(), engine);
	}
	SmartDefinition CharValueDefinition::castToInt() const {
		return DefinitionFactory::createInt(getValue(), engine);
	}
	SmartDefinition CharValueDefinition::castToLong() const {
		return DefinitionFactory::createLong(getValue(), engine);
	}
	SmartDefinition CharValueDefinition::castToFloat() const {
		return DefinitionFactory::createFloat((float)getValue(), engine);
	}
	SmartDefinition CharValueDefinition::castToDouble() const {
		return DefinitionFactory::createDouble((double)getValue(), engine);
	}
	SmartDefinition CharValueDefinition::castToReference(columbus::NodeId toType) const {
		return DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(toType), true, engine);
	}
}}
