#include "../../inc/common.h"
#include "symbolic_java/inc/constraint/Z3ConstraintExpression.h"

namespace columbus { namespace symbolic {

    ShortValueDefinition::ShortValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<ShortValueDefinition, int16_t>(SymbolicTypesPreVisitor::getShortTypeId(), address, engine) { 
		csExpr = engine.getConstraintBuilder()->makeShortVar(*this);
	}

	ShortValueDefinition::ShortValueDefinition(int16_t value, const Address& address, SymbolicEngine& engine) : ValueDefinition<ShortValueDefinition, int16_t>(value,  SymbolicTypesPreVisitor::getShortTypeId(), address, engine) { 
		csExpr = engine.getConstraintBuilder()->makeShortValue(value);
	}

	//plus
    SmartDefinition ShortValueDefinition::plusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::plusImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::plusImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::plusImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(getValue() + def.getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::plusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::plusImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() + getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::plusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }
	SmartDefinition ShortValueDefinition::plusImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->plus(*this);
	}

	SmartDefinition ShortValueDefinition::plusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, getType(), engine); //the result will be a float
	}

	SmartDefinition ShortValueDefinition::minusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition ShortValueDefinition::timesImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition ShortValueDefinition::divideImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

    //minus
    SmartDefinition ShortValueDefinition::minusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::minusImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::minusImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::minusImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() - getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::minusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::minusImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::minusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }

	SmartDefinition ShortValueDefinition::minusImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->minus(*this);
	}

    //times
    SmartDefinition ShortValueDefinition::timesImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::timesImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::timesImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::timesImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() * getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::timesImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::timesImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }

    SmartDefinition ShortValueDefinition::timesImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
	SmartDefinition ShortValueDefinition::timesImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->times(*this);
	}
    //divide
    SmartDefinition ShortValueDefinition::divideImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::divideImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::divideImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::divideImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() / getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::divideImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::divideImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::divideImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
	SmartDefinition ShortValueDefinition::divideImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->divide(*this);
	}
    //remainder
    SmartDefinition ShortValueDefinition::remainderImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }

	//TODO: Start - Itt eddig nullptr volt visszaadva
	SmartDefinition ShortValueDefinition::remainderImpl(const DoubleValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}

	SmartDefinition ShortValueDefinition::remainderImpl(const FloatValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}
	//TODO: End

    SmartDefinition ShortValueDefinition::remainderImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::remainderImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::remainderImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() % getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::remainderImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::remainderImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->remainder(*this);
	}

    //bitwiseAndLogicalAnd
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { 
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() & getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
	SmartDefinition ShortValueDefinition::bitwiseAndLogicalAndImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalAnd(*this);
	}

    //bitwiseAndLogicalOr
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() | getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
	SmartDefinition ShortValueDefinition::bitwiseAndLogicalOrImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalOr(*this);
	}

    //bitwiseAndLogicalXor
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition ShortValueDefinition::bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
	SmartDefinition ShortValueDefinition::bitwiseAndLogicalXorImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalXor(*this);
	}

	 //less
    SmartDefinition ShortValueDefinition::lessImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}

	SmartDefinition ShortValueDefinition::lessImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition ShortValueDefinition::greaterImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
	}

	SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
	}

	SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
	}

	SmartDefinition ShortValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition ShortValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
	}

    SmartDefinition ShortValueDefinition::lessImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::lessImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->less(*this);
	}

	//greater
	SmartDefinition ShortValueDefinition::greaterImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::greaterImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greater(*this);
	}

	//lessThanOrEqualTo
	SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::lessThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->lessThanOrEqualTo(*this);
	}
		
	//greaterThanOrEqualTo
	SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greaterThanOrEqualTo(*this);
	}
		
	//equals
	SmartDefinition ShortValueDefinition::equalsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::equalsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::equalsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::equalsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::equalsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::equalsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::equalsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}
		
	//notEquals
	SmartDefinition ShortValueDefinition::notEqualsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::notEqualsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::notEqualsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}
		
	/**
	*	Unary operators
	*/
	SmartDefinition ShortValueDefinition::increment() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createShort(engine);
		}
		return DefinitionFactory::createShort(getValue()+1, engine);
	}
    SmartDefinition ShortValueDefinition::decrement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createShort(engine);
		}
		return DefinitionFactory::createShort(getValue()-1, engine);
	}
	SmartDefinition ShortValueDefinition::prePlus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(+getValue(), engine);
	}
    SmartDefinition ShortValueDefinition::preMinus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(-getValue(), engine);
	}
    
    SmartDefinition ShortValueDefinition::complement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt(~getValue(), engine);
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition ShortValueDefinition::castToByte() const {
		return DefinitionFactory::createByte((int8_t)getValue() & 0xFF, engine);
	}
	SmartDefinition ShortValueDefinition::castToChar() const {
		return DefinitionFactory::createChar(getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::castToShort() const {
		return DefinitionFactory::createShort(getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::castToInt() const {
		return DefinitionFactory::createInt(getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::castToLong() const {
		return DefinitionFactory::createLong(getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::castToFloat() const {
		return DefinitionFactory::createFloat(getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::castToDouble() const {
		return DefinitionFactory::createDouble(getValue(), engine);
	}
	SmartDefinition ShortValueDefinition::castToReference(columbus::NodeId toType) const {
		return DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(toType), true, engine);
	}
}}
