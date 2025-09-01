#include "../../inc/common.h"

namespace columbus { namespace symbolic {

	BooleanValueDefinition::BooleanValueDefinition(const Address& address, SymbolicEngine& engine) : ValueDefinition<BooleanValueDefinition, bool>(SymbolicTypesPreVisitor::getBooleanTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeBoolVar(*this);
	}
	
	BooleanValueDefinition::BooleanValueDefinition(bool value, const Address& address, SymbolicEngine& engine) : ValueDefinition<BooleanValueDefinition, bool>(value, SymbolicTypesPreVisitor::getBooleanTypeId(), address, engine) {
		csExpr = engine.getConstraintBuilder()->makeBoolValue(value);
	}

	//equals
    SmartDefinition BooleanValueDefinition::equalsImpl(const BooleanValueDefinition& def) const {
		if (def.getIsSymbol() || getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		} else 
			return DefinitionFactory::createBoolean(value==def.value, engine);
	}

    SmartDefinition BooleanValueDefinition::equalsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->equals(*this);
	}

    //notEquals
    SmartDefinition BooleanValueDefinition::notEqualsImpl(const BooleanValueDefinition& def) const {
		if (def.getIsSymbol() || getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		} else 
			return DefinitionFactory::createBoolean(value!=def.value, engine);
	}

    SmartDefinition BooleanValueDefinition::notEqualsImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->notEquals(*this);
	}

	SmartDefinition BooleanValueDefinition::notEqualsImpl(const SymbolDefinition& def) const {
		if (def.getType() == SymbolicTypesPreVisitor::getBooleanTypeId()) {
			return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokNotEqualTo, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
		}
		throw SymbolicColumbusException("Symbolic value is not boolean");
	}

	SmartDefinition BooleanValueDefinition::equalsImpl(const SymbolDefinition& def) const {
		if (def.getType() == SymbolicTypesPreVisitor::getBooleanTypeId()) {
			return SymbolDefinition::makeSymbolDefinition(def, *this, columbus::java::asg::iokEqualTo, SymbolicTypesPreVisitor::getResultType(this->getType(), def.getType()), engine);
		}
		throw SymbolicColumbusException("Symbolic value is not boolean");
	}

	//conditionalAnd
	SmartDefinition BooleanValueDefinition::conditionalAndImpl(const BooleanValueDefinition& def) const {
		if (def.getIsSymbol() && getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		} else if (!def.getIsSymbol() && def.getValue() == false) {   // if one of the sides is false the result is false
			return DefinitionFactory::createBoolean(false, engine);
		} else if (!getIsSymbol() && getValue() == false) {           // if one of the sides is false the result is false
			return DefinitionFactory::createBoolean(false, engine);
		} else {
			return DefinitionFactory::createBoolean(value && def.value, engine);
		}
	}

    SmartDefinition BooleanValueDefinition::conditionalAndImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->conditionalAnd(*this);
	}
        
	//conditionalOr
    SmartDefinition BooleanValueDefinition::conditionalOrImpl(const BooleanValueDefinition& def) const {
		if (def.getIsSymbol() || getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		} else if (!def.getIsSymbol() && def.getValue()) {
			return DefinitionFactory::createBoolean(true, engine);   // if one of the sides is true the result is true
		} else if (!getIsSymbol() && getValue()) {
			return DefinitionFactory::createBoolean(true, engine);   // if one of the sides is true the result is true
		} else {
			return DefinitionFactory::createBoolean(value || def.value, engine);
		}
	}

    SmartDefinition BooleanValueDefinition::conditionalOrImpl(const Reference& def) const {
		return Reference::unbox(def, engine)->conditionalOr(*this);
	}


    SmartDefinition BooleanValueDefinition::assignValueImpl(const BooleanValueDefinition& lhs) const {
        if (getIsSymbol()) {
            return DefinitionFactory::createBoolean(engine);
        }
        return DefinitionFactory::createBoolean(getValue(), engine);
    }


	/**
	*	Unary operators
	*/
	SmartDefinition BooleanValueDefinition::negate() const {
		if (getIsSymbol()) {
			//TODO constraint
			return DefinitionFactory::createBoolean(engine);
		} else 
			return DefinitionFactory::createBoolean(!value, engine);
	}

	SmartDefinition BooleanValueDefinition::castToBoolean() const {
		return DefinitionFactory::createBoolean(getValue(), engine);
	}

}}
