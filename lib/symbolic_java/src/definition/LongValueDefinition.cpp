#include "../../inc/common.h"
#include "symbolic_java/inc/constraint/Z3ConstraintExpression.h"

namespace columbus { namespace symbolic {

    LongValueDefinition::LongValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<LongValueDefinition, int64_t>(SymbolicTypesPreVisitor::getLongTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeLongVar(*this);
	}

	LongValueDefinition::LongValueDefinition(int64_t value, const Address& address, SymbolicEngine& engine) : ValueDefinition<LongValueDefinition, int64_t>(value,  SymbolicTypesPreVisitor::getLongTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeLongValue(value);
	}


    //plus
    SmartDefinition LongValueDefinition::plusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition LongValueDefinition::plusImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition LongValueDefinition::plusImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition LongValueDefinition::plusImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition LongValueDefinition::plusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue() + def.getValue(), engine);
    }

    SmartDefinition LongValueDefinition::plusImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() + getValue(), engine);
    }

    SmartDefinition LongValueDefinition::plusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() + getValue(), engine);
    }
	SmartDefinition LongValueDefinition::plusImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->plus(*this);
	}

	SmartDefinition LongValueDefinition::plusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokPlus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition LongValueDefinition::minusImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokMinus, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition LongValueDefinition::timesImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokTimes, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition LongValueDefinition::divideImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition LongValueDefinition::remainderImpl(const SymbolDefinition& def) const {
		return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokDivide, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
	}

	SmartDefinition LongValueDefinition::remainderImpl(const DoubleValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}

	SmartDefinition LongValueDefinition::remainderImpl(const FloatValueDefinition& def) const {
		if (getValue() == 0) {
			//hiba 0-val osztas. Elobb kene kezelni?
		}
		return DefinitionFactory::createDouble(fmod(def.getValue(), getValue()), engine);
	}

    //minus
    SmartDefinition LongValueDefinition::minusImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition LongValueDefinition::minusImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition LongValueDefinition::minusImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition LongValueDefinition::minusImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition LongValueDefinition::minusImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() - getValue(), engine);
    }
    SmartDefinition LongValueDefinition::minusImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
        return DefinitionFactory::createFloat(def.getValue() - getValue(), engine);
    }
    SmartDefinition LongValueDefinition::minusImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
        return DefinitionFactory::createDouble(def.getValue() - getValue(), engine);
    }

	SmartDefinition LongValueDefinition::minusImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->minus(*this);
	}

    //times
    SmartDefinition LongValueDefinition::timesImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition LongValueDefinition::timesImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition LongValueDefinition::timesImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition LongValueDefinition::timesImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition LongValueDefinition::timesImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() * getValue(), engine);
    }
    SmartDefinition LongValueDefinition::timesImpl(const FloatValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() * getValue(), engine);
    }

    SmartDefinition LongValueDefinition::timesImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() * getValue(), engine);
    }
	SmartDefinition LongValueDefinition::timesImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->times(*this);
	}
    //divide
    SmartDefinition LongValueDefinition::divideImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition LongValueDefinition::divideImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition LongValueDefinition::divideImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition LongValueDefinition::divideImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition LongValueDefinition::divideImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() / getValue(), engine);
    }
    SmartDefinition LongValueDefinition::divideImpl(const FloatValueDefinition& def) const {
       if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createFloat(engine);
		}
		return DefinitionFactory::createFloat(def.getValue() / getValue(), engine);
    }
    SmartDefinition LongValueDefinition::divideImpl(const DoubleValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createDouble(engine);
		}
		return DefinitionFactory::createDouble(def.getValue() / getValue(), engine);
    }
	SmartDefinition LongValueDefinition::divideImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->divide(*this);
	}
    //remainder
    SmartDefinition LongValueDefinition::remainderImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition LongValueDefinition::remainderImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition LongValueDefinition::remainderImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition LongValueDefinition::remainderImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition LongValueDefinition::remainderImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() % getValue(), engine);
    }
    SmartDefinition LongValueDefinition::remainderImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->remainder(*this);
	}

    //bitwiseAndLogicalAnd
    SmartDefinition LongValueDefinition::bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { 
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() & getValue(), engine);
    }
	SmartDefinition LongValueDefinition::bitwiseAndLogicalAndImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalAnd(*this);
	}

    //bitwiseAndLogicalOr
    SmartDefinition LongValueDefinition::bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() | getValue(), engine);
    }
	SmartDefinition LongValueDefinition::bitwiseAndLogicalOrImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalOr(*this);
	}

    //bitwiseAndLogicalXor
    SmartDefinition LongValueDefinition::bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
    SmartDefinition LongValueDefinition::bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const {
        if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(def.getValue() ^ getValue(), engine);
    }
	SmartDefinition LongValueDefinition::bitwiseAndLogicalXorImpl(const Reference& def) const  {
		return Reference::unbox(def, engine)->bitwiseAndLogicalXor(*this);
	}

	SmartDefinition LongValueDefinition::lessImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThan, def, engine);
	}


	SmartDefinition LongValueDefinition::greaterImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThan, def, engine);
	}

	SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokGreaterThanOrEqualTo, def, engine);
	}

	SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokLessThanOrEqualTo, def, engine);
	}

	SmartDefinition LongValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokEqualTo, def, engine);
	}

	SmartDefinition LongValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
	}

	 //less
    SmartDefinition LongValueDefinition::lessImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() < getValue(), engine);
	}
	SmartDefinition LongValueDefinition::lessImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->less(*this);
	}

	//greater
	SmartDefinition LongValueDefinition::greaterImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() > getValue(), engine);
	}
	SmartDefinition LongValueDefinition::greaterImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greater(*this);
	}

	//lessThanOrEqualTo
	SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() <= getValue(), engine);
	}
	SmartDefinition LongValueDefinition::lessThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->lessThanOrEqualTo(*this);
	}
		
	//greaterThanOrEqualTo
	SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
    SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() >= getValue(), engine);
	}
	SmartDefinition LongValueDefinition::greaterThanOrEqualToImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->greaterThanOrEqualTo(*this);
	}
		
	//equals
	SmartDefinition LongValueDefinition::equalsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition LongValueDefinition::equalsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition LongValueDefinition::equalsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition LongValueDefinition::equalsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition LongValueDefinition::equalsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition LongValueDefinition::equalsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
    SmartDefinition LongValueDefinition::equalsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() == getValue(), engine);
	}
	SmartDefinition LongValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}
		
	//notEquals
	SmartDefinition LongValueDefinition::notEqualsImpl(const CharValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition LongValueDefinition::notEqualsImpl(const ByteValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition LongValueDefinition::notEqualsImpl(const ShortValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition LongValueDefinition::notEqualsImpl(const IntValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition LongValueDefinition::notEqualsImpl(const LongValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition LongValueDefinition::notEqualsImpl(const FloatValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
    SmartDefinition LongValueDefinition::notEqualsImpl(const DoubleValueDefinition& def) const {
		if (getIsSymbol() || def.getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		}
		return DefinitionFactory::createBoolean(def.getValue() != getValue(), engine);
	}
	SmartDefinition LongValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}

	/**
	*	Unary operators
	*/
	SmartDefinition LongValueDefinition::increment() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue()+1, engine);
	}
    SmartDefinition LongValueDefinition::decrement() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(getValue()-1, engine);
	}
	SmartDefinition LongValueDefinition::prePlus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(+getValue(), engine);
	}
    SmartDefinition LongValueDefinition::preMinus() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createLong(engine);
		}
		return DefinitionFactory::createLong(-getValue(), engine);
	}
    
    SmartDefinition LongValueDefinition::complement() const {
		return DefinitionFactory::createLong(~getValue(), engine);
	}

	/**
	*	Typecast operators
	*/
	SmartDefinition LongValueDefinition::castToByte() const {

		return DefinitionFactory::createByte(getValue() & 0xFF, engine);
	}
	SmartDefinition LongValueDefinition::castToChar() const {
		return DefinitionFactory::createChar(getValue() & 0xFFFF, engine);
	}
	SmartDefinition LongValueDefinition::castToShort() const {
		return DefinitionFactory::createShort(getValue() & 0xFFFF, engine);
	}
	SmartDefinition LongValueDefinition::castToInt() const {
		return DefinitionFactory::createInt(getValue() & 0xFFFFFFFF, engine);
	}
	SmartDefinition LongValueDefinition::castToLong() const {
		return DefinitionFactory::createLong(getValue(), engine);
	}
	SmartDefinition LongValueDefinition::castToFloat() const {
		return DefinitionFactory::createFloat((float)getValue(), engine);
	}
	SmartDefinition LongValueDefinition::castToDouble() const {
		return DefinitionFactory::createDouble((double)getValue(), engine);
	}
	SmartDefinition LongValueDefinition::castToReference(columbus::NodeId toType) const {
		return DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(toType), true, engine);
	}
		
	
}}
