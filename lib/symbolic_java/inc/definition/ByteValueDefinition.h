#ifndef _BYTE_VALUE_DEFINITION_H_
#define _BYTE_VALUE_DEFINITION_H_

#include <symbolic/inc/structure/State.h>
#include <cstdint>

namespace columbus { namespace symbolic {

    class StringValueDefinition : public ValueDefinition<StringValueDefinition, std::string> {
        friend class DefinitionFactory;

    private:

        StringValueDefinition(const Address& address, SymbolicEngine& engine);
        StringValueDefinition(const std::string& value, const Address& address, SymbolicEngine& engine);

    public:

        //plus
        virtual SmartDefinition plusImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition plusImpl(const SymbolDefinition& def) const { return nullptr; }


        //minus
        virtual SmartDefinition minusImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition minusImpl(const SymbolDefinition& def) const { return nullptr; }

        //times
        virtual SmartDefinition timesImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition timesImpl(const SymbolDefinition& def) const { return nullptr; }

        //divide
        virtual SmartDefinition divideImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition divideImpl(const SymbolDefinition& def) const { return nullptr; }

        //remainder
        virtual SmartDefinition remainderImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition remainderImpl(const Reference& def) const { return nullptr; }

        //bitwiseAndLogicalAndImpl
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const Reference& def) const { return nullptr; }


        //bitwiseAndLogicalOrImpl
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const Reference& def) const { return nullptr; }

        //bitwiseAndLogicalXorImpl
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const Reference& def) const { return nullptr; }

        //less
        virtual SmartDefinition lessImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition lessImpl(const SymbolDefinition& def) const { return nullptr; }

        //greater
        virtual SmartDefinition greaterImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition greaterImpl(const SymbolDefinition& def) const { return nullptr; }


        //lessThanOrEqualTo
        virtual SmartDefinition lessThanOrEqualToImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition lessThanOrEqualToImpl(const SymbolDefinition& def) const { return nullptr; }


        //greaterThanOrEqualTo
        virtual SmartDefinition greaterThanOrEqualToImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition greaterThanOrEqualToImpl(const SymbolDefinition& def) const { return nullptr; }


        //equals
        virtual SmartDefinition equalsImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition equalsImpl(const SymbolDefinition& def) const { return nullptr; }


        //notEquals
        virtual SmartDefinition notEqualsImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const Reference& def) const { return nullptr; }
        virtual SmartDefinition notEqualsImpl(const SymbolDefinition& def) const { return nullptr; }

        // assign
        virtual SmartDefinition assignValueImpl(const ByteValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const ShortValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const IntValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const LongValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const CharValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const FloatValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const DoubleValueDefinition& def) const { return nullptr; }
        virtual SmartDefinition assignValueImpl(const Reference& def) const { return nullptr; }

        /**
        * Unary operators
        */
        virtual SmartDefinition increment() const { return nullptr; }
        virtual SmartDefinition decrement() const { return nullptr; }
        virtual SmartDefinition prePlus() const { return nullptr; }
        virtual SmartDefinition preMinus() const { return nullptr; }
        virtual SmartDefinition complement() const { return nullptr; }

        /**
        * Typecast operators
        */
        virtual SmartDefinition castToByte() const { return nullptr; }
        virtual SmartDefinition castToChar() const { return nullptr; }
        virtual SmartDefinition castToShort() const { return nullptr; }
        virtual SmartDefinition castToInt() const { return nullptr; }
        virtual SmartDefinition castToLong() const { return nullptr; }
        virtual SmartDefinition castToFloat() const { return nullptr; }
        virtual SmartDefinition castToDouble() const { return nullptr; }
        virtual SmartDefinition castToReference(NodeId toType) const { return nullptr; }
        virtual SmartDefinition castToBoolean() const { throw SymbolicColumbusException("Should not be happenning"); }
    };

    class ByteValueDefinition : public ValueDefinition<ByteValueDefinition, int8_t> {

		friend class DefinitionFactory;

    public:
		static const int8_t default_value=0;

	private:

        ByteValueDefinition(const Address& address, SymbolicEngine& engine);
		ByteValueDefinition(int8_t value, const Address& address, SymbolicEngine& engine);

	public:
        virtual bool isByteValueDefinition() const { return true; }

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

        //remainder
        virtual SmartDefinition remainderImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition remainderImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition remainderImpl(const Reference& def) const;

        //bitwiseAndLogicalAndImpl
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const;
		virtual SmartDefinition bitwiseAndLogicalAndImpl(const Reference& def) const;
		

        //bitwiseAndLogicalOrImpl
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const;
		virtual SmartDefinition bitwiseAndLogicalOrImpl(const Reference& def) const;

        //bitwiseAndLogicalXorImpl
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const;
		virtual SmartDefinition bitwiseAndLogicalXorImpl(const Reference& def) const;

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
		
        // assign
        virtual SmartDefinition assignValueImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition assignValueImpl(const LongValueDefinition& def) const;
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
        virtual SmartDefinition complement() const ;

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