#ifndef _FLOAT_VALUE_DEFINITION_H_
#define _FLOAT_VALUE_DEFINITION_H_

#include <symbolic/inc/structure/State.h>

namespace columbus { namespace symbolic {

    class FloatValueDefinition : public ValueDefinition<FloatValueDefinition, float> {
	
		friend class DefinitionFactory;

    public:

		static const float default_value;

	private:

        FloatValueDefinition(const Address& address, SymbolicEngine& engine);
		FloatValueDefinition(float value, const Address& address, SymbolicEngine& engine);

	public:
        virtual bool isFloatValueDefinition() const { return true; }

        //plus
        virtual SmartDefinition plusImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition plusImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition plusImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition plusImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition plusImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition plusImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition plusImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition plusImpl(const Reference& def) const;
        virtual SmartDefinition plusImpl(const SymbolDefinition& def) const;

        //minus
        virtual SmartDefinition minusImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition minusImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition minusImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition minusImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition minusImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition minusImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition minusImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition minusImpl(const Reference& def) const;
        virtual SmartDefinition minusImpl(const SymbolDefinition& def) const;

        //times
        virtual SmartDefinition timesImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition timesImpl(const Reference& def) const;
        virtual SmartDefinition timesImpl(const SymbolDefinition& def) const;

        virtual SmartDefinition remainderImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const DoubleValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const SymbolDefinition& def) const;

        //divide
        virtual SmartDefinition divideImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition divideImpl(const Reference& def) const;
        virtual SmartDefinition divideImpl(const SymbolDefinition& def) const;

		 //less
        virtual SmartDefinition lessImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition lessImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition lessImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition lessImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition lessImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition lessImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition lessImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition lessImpl(const Reference& def) const;
        virtual SmartDefinition lessImpl(const SymbolDefinition& def) const;

		//greater
		virtual SmartDefinition greaterImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition greaterImpl(const Reference& def) const;
        virtual SmartDefinition greaterImpl(const SymbolDefinition& def) const;

		//lessThanOrEqualTo
		virtual SmartDefinition lessThanOrEqualToImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition lessThanOrEqualToImpl(const Reference& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const SymbolDefinition& def) const;
		
		//greaterThanOrEqualTo
		virtual SmartDefinition greaterThanOrEqualToImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition greaterThanOrEqualToImpl(const Reference& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const SymbolDefinition& def) const;
		
		//equals
		virtual SmartDefinition equalsImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition equalsImpl(const Reference& def) const;
        virtual SmartDefinition equalsImpl(const SymbolDefinition& def) const;
		
		//notEquals
		virtual SmartDefinition notEqualsImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition notEqualsImpl(const Reference& def) const;
        virtual SmartDefinition notEqualsImpl(const SymbolDefinition& def) const;
		
        //assignValue
        virtual SmartDefinition assignValueImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const BooleanValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition assignValueImpl(const Reference& def) const;

		/**
		*	Unary operators
		*/
		virtual SmartDefinition increment() const ;
        virtual SmartDefinition decrement() const ;
        virtual SmartDefinition prePlus() const ;
        virtual SmartDefinition preMinus() const ;

		/**
		*	Typecast operators
		*/
		virtual SmartDefinition castToByte() const ;
		virtual SmartDefinition castToChar() const ;
		virtual SmartDefinition castToShort() const ;
		virtual SmartDefinition castToInt() const ;
		virtual SmartDefinition castToLong() const ;
		virtual SmartDefinition castToFloat() const ;
		virtual SmartDefinition castToDouble() const ;
		virtual SmartDefinition castToReference(NodeId toType) const ;
        virtual SmartDefinition castToBoolean() const { throw SymbolicColumbusException("Should not be happenning"); }
    };
}}

#include "..//definition/ValueDefinition.hpp"

#endif
