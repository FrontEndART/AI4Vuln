#include "../../inc/common.h"
#include "symbolic_java/inc/constraint/Z3ConstraintExpression.h"

namespace columbus { namespace symbolic {

	const double DoubleValueDefinition::default_value = 0.0f;

    DoubleValueDefinition::DoubleValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<DoubleValueDefinition, double>(SymbolicTypesPreVisitor::getDoubleTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeDoubleVar(*this);
	}

	DoubleValueDefinition::DoubleValueDefinition(double value, const Address& address, SymbolicEngine& engine) : ValueDefinition<DoubleValueDefinition, double>(value,  SymbolicTypesPreVisitor::getDoubleTypeId(), address, engine) { 
		csExpr = engine.getConstraintBuilder()->makeDoubleValue(value); 
	}

    //plus
    SmartDefinition DoubleValueDefinition::plusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue() + def.getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::plusImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue() + def.getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::plusImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue() + def.getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::plusImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue() + def.getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::plusImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue() + def.getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::plusImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::plusImpl(const DoubleValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }
	SmartDefinition DoubleValueDefinition::plusImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->plus(*this);
	}

	SmartDefinition DoubleValueDefinition::plusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, getType(), engine); //the result will be a float
	}

	SmartDefinition DoubleValueDefinition::minusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition DoubleValueDefinition::timesImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition DoubleValueDefinition::divideImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const FloatValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod((double)def.getValue(), getValue()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const IntValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod((double)def.getValue(), getValue()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const LongValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod((double)def.getValue(), getValue()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const DoubleValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const ShortValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod((double)def.getValue(), getValue()), engine);
	}

	SmartDefinition DoubleValueDefinition::remainderImpl(const CharValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod((double)def.getValue(), getValue()), engine);
	}
	SmartDefinition DoubleValueDefinition::remainderImpl(const ByteValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod((double)def.getValue(), getValue()), engine);
	}


    //minus
    SmartDefinition DoubleValueDefinition::minusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::minusImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::minusImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::minusImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::minusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::minusImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::minusImpl(const DoubleValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }

	SmartDefinition DoubleValueDefinition::minusImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->minus(*this);
	}

    //times
    SmartDefinition DoubleValueDefinition::timesImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::timesImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::timesImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::timesImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::timesImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::timesImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::timesImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
	SmartDefinition DoubleValueDefinition::timesImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->times(*this);
	}
    //divide
    SmartDefinition DoubleValueDefinition::divideImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::divideImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::divideImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::divideImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::divideImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::divideImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
    SmartDefinition DoubleValueDefinition::divideImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
	SmartDefinition DoubleValueDefinition::divideImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->divide(*this);
	}

	 //less
    SmartDefinition DoubleValueDefinition::lessImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::lessImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->less(*this);
	}
	SmartDefinition DoubleValueDefinition::lessImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
	}

	SmartDefinition DoubleValueDefinition::greaterImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
	}

	SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
	}

	SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
	}

	SmartDefinition DoubleValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition DoubleValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
	}


	//greater
	SmartDefinition DoubleValueDefinition::greaterImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::greaterImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greater(*this);
	}

	//lessThanOrEqualTo
	SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::lessThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->lessThanOrEqualTo(*this);
	}
		
	//greaterThanOrEqualTo
	SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greaterThanOrEqualTo(*this);
	}
		
	//equals
	SmartDefinition DoubleValueDefinition::equalsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::equalsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::equalsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::equalsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::equalsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::equalsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::equalsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}
		
	//notEquals
	SmartDefinition DoubleValueDefinition::notEqualsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::notEqualsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::notEqualsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}
	
    //assignValue
    SmartDefinition DoubleValueDefinition::assignValueImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createByte(engine);
        }
        return DefinitionFactory::createByte(getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::assignValueImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createShort(engine);
        }
        return DefinitionFactory::createShort(getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::assignValueImpl(const IntValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createInt(engine);
        }
        return DefinitionFactory::createInt(getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::assignValueImpl(const LongValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createLong(engine);
        }
        return DefinitionFactory::createLong(getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::assignValueImpl(const CharValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createChar(engine);
        }
        return DefinitionFactory::createChar(getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::assignValueImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createFloat(engine);
        }
        return DefinitionFactory::createFloat(getValue(), engine);
    }

    SmartDefinition DoubleValueDefinition::assignValueImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createDouble(engine);
        }
        return DefinitionFactory::createDouble(getValue(), engine);
    }

	SmartDefinition DoubleValueDefinition::assignValueImpl(const Reference& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!");};


	/**
	*	Unary operators
	*/
	SmartDefinition DoubleValueDefinition::increment() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue()+1, engine);
	}
    SmartDefinition DoubleValueDefinition::decrement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(getValue()-1, engine);
	}
	SmartDefinition DoubleValueDefinition::prePlus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(+getValue(), engine);
	}
    SmartDefinition DoubleValueDefinition::preMinus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(-getValue(), engine);
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition DoubleValueDefinition::castToByte() const {
		return DefinitionFactory::createByte(getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToChar() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createChar(engine);
		}
		return DefinitionFactory::createChar((wchar_t)getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToShort() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createShort(engine);
		}
		return DefinitionFactory::createShort((short)getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToInt() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt((int)getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToLong() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong((long long)getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToFloat() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat((float)getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToDouble() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble((double)getValue(), engine);
	}
	SmartDefinition DoubleValueDefinition::castToReference(columbus::NodeId toType) const {
		return DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(toType), true, engine);
	}
	
}}
