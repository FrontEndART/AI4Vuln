#ifndef _BOOLEAN_VALUE_DEFINITION_H_
#define _BOOLEAN_VALUE_DEFINITION_H_

#include "ValueDefinition.h"

namespace columbus { namespace symbolic {

   class BooleanValueDefinition : public ValueDefinition<BooleanValueDefinition, bool> {
	   friend class DefinitionFactory;

   public: 
	   static const bool default_value=true;

   private:
		BooleanValueDefinition(const Address& address, SymbolicEngine& engine);
		BooleanValueDefinition(bool value, const Address& address, SymbolicEngine& engine);

    public:
        virtual bool isBooleanValueDefinition() const { return true; }
		
		//equals
        virtual SmartDefinition equalsImpl(const BooleanValueDefinition& def) const ;
        virtual SmartDefinition equalsImpl(const Reference& def) const ;
		virtual SmartDefinition equalsImpl(const SymbolDefinition& def) const;

        //notEquals
        virtual SmartDefinition notEqualsImpl(const BooleanValueDefinition& def) const ;
        virtual SmartDefinition notEqualsImpl(const Reference& def) const ;
		virtual SmartDefinition notEqualsImpl(const SymbolDefinition& def) const;

		 //conditionalAnd
        virtual SmartDefinition conditionalAndImpl(const BooleanValueDefinition& def) const ;
        virtual SmartDefinition conditionalAndImpl(const Reference& def) const ;
        
		//conditionalOr
        virtual SmartDefinition conditionalOrImpl(const BooleanValueDefinition& def) const ;
        virtual SmartDefinition conditionalOrImpl(const Reference& def) const ;

        // assignment
        virtual SmartDefinition assignValueImpl(const BooleanValueDefinition& def) const;


		/**
		*	Unary operators
		*/
		virtual SmartDefinition negate() const ;

		/**
		*	Typecast operators
		*/
		virtual SmartDefinition castToBoolean() const;
		virtual SmartDefinition castToByte() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToChar() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToShort() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToInt() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToLong() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToFloat() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToDouble() const { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToReference(NodeId toType) const { throw SymbolicColumbusException("Should not be happenning"); }
    };
}}

#include "..//definition/ValueDefinition.hpp"

#endif
