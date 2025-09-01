#include "../../inc/common.h"
#include "symbolic_java/inc/constraint/Z3ConstraintExpression.h"
#include <cmath>

namespace columbus { namespace symbolic {

	const float FloatValueDefinition::default_value = 0.0f;


	// int alapján
    FloatValueDefinition::FloatValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<FloatValueDefinition, float>(SymbolicTypesPreVisitor::getFloatTypeId(), address, engine) { 
		csExpr = engine.getConstraintBuilder()->makeFloatVar(*this);
	}

	FloatValueDefinition::FloatValueDefinition(float value, const Address& address, SymbolicEngine& engine) : ValueDefinition<FloatValueDefinition, float>(value,  SymbolicTypesPreVisitor::getFloatTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeFloatValue(value);
	}

    //plus
    SmartDefinition FloatValueDefinition::plusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue() + def.getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::plusImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue() + def.getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::plusImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue() + def.getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::plusImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue() + def.getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::plusImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue() + def.getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::plusImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() + getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::plusImpl(const DoubleValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }
	SmartDefinition FloatValueDefinition::plusImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->plus(*this);
	}

	SmartDefinition FloatValueDefinition::plusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, getType(), engine); //the result will be a float
	}

	SmartDefinition FloatValueDefinition::minusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition FloatValueDefinition::timesImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition FloatValueDefinition::divideImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokRemainder, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const FloatValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod(def.getValue(), getValue()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const IntValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod((float)def.getValue(), getValue()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const LongValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod((float)def.getValue(), getValue()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const DoubleValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), (double)getValue()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const ShortValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod((float)def.getValue(), getValue()), engine);
	}

	SmartDefinition FloatValueDefinition::remainderImpl(const CharValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod((float)def.getValue(), getValue()), engine);
	}
	SmartDefinition FloatValueDefinition::remainderImpl(const ByteValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createFloat(fmod((float)def.getValue(), getValue()), engine);
	}

    //minus
    SmartDefinition FloatValueDefinition::minusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::minusImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::minusImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::minusImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::minusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::minusImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::minusImpl(const DoubleValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }

	SmartDefinition FloatValueDefinition::minusImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->minus(*this);
	}

    //times
    SmartDefinition FloatValueDefinition::timesImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::timesImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::timesImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::timesImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::timesImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::timesImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }

    SmartDefinition FloatValueDefinition::timesImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
	SmartDefinition FloatValueDefinition::timesImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->times(*this);
	}
    //divide
    SmartDefinition FloatValueDefinition::divideImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::divideImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::divideImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::divideImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::divideImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::divideImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition FloatValueDefinition::divideImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
	SmartDefinition FloatValueDefinition::divideImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->divide(*this);
	}

	 //less
    SmartDefinition FloatValueDefinition::lessImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::lessImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->less(*this);
	}

	SmartDefinition FloatValueDefinition::lessImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
	}


	SmartDefinition FloatValueDefinition::greaterImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
	}

	SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
	}

	SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
	}

	SmartDefinition FloatValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition FloatValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
	}

	//greater
	SmartDefinition FloatValueDefinition::greaterImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::greaterImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greater(*this);
	}

	//lessThanOrEqualTo
	SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::lessThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->lessThanOrEqualTo(*this);
	}
		
	//greaterThanOrEqualTo
	SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greaterThanOrEqualTo(*this);
	}
		
	//equals
	SmartDefinition FloatValueDefinition::equalsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::equalsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::equalsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::equalsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::equalsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::equalsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::equalsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}
		
	//notEquals
	SmartDefinition FloatValueDefinition::notEqualsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::notEqualsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::notEqualsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}

    //assignValue
    SmartDefinition FloatValueDefinition::assignValueImpl(const ByteValueDefinition& def) const {
        throw SymbolicColumbusException("Illegal dispatch: assignValueImp(ShortValueDefinition)!");
    }
    SmartDefinition FloatValueDefinition::assignValueImpl(const ShortValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(ShortValueDefinition)!");};
    SmartDefinition FloatValueDefinition::assignValueImpl(const IntValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(IntValueDefinition)!");};
    SmartDefinition FloatValueDefinition::assignValueImpl(const LongValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(LongValueDefinition)!");};
    SmartDefinition FloatValueDefinition::assignValueImpl(const BooleanValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(BooleanValueDefinition)!");};
    SmartDefinition FloatValueDefinition::assignValueImpl(const CharValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(CharValueDefinition)!");};
    SmartDefinition FloatValueDefinition::assignValueImpl(const FloatValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(FloatValueDefinition)!");};
    SmartDefinition FloatValueDefinition::assignValueImpl(const DoubleValueDefinition& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(DoubleValueDefinition)!");};
	SmartDefinition FloatValueDefinition::assignValueImpl(const Reference& def) const {throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!");};

	/**
	*	Unary operators
	*/
	SmartDefinition FloatValueDefinition::increment() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue()+1, engine);
	}
    SmartDefinition FloatValueDefinition::decrement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(getValue()-1, engine);
	}
	SmartDefinition FloatValueDefinition::prePlus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(+getValue(), engine);
	}
    SmartDefinition FloatValueDefinition::preMinus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(-getValue(), engine);
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition FloatValueDefinition::castToByte() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createByte(engine);
		}
		return DefinitionFactory::createByte((char)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToChar() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createChar(engine);
		}
		return DefinitionFactory::createChar((wchar_t)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToShort() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createShort(engine);
		}
		return DefinitionFactory::createShort((short)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToInt() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createInt(engine);
		}
		return DefinitionFactory::createInt((int)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToLong() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong((long long)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToFloat() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat((float)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToDouble() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble((double)getValue(), engine);
	}
	SmartDefinition FloatValueDefinition::castToReference(columbus::NodeId toType) const {
		return DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(toType), true, engine);
	}
    	
}}
