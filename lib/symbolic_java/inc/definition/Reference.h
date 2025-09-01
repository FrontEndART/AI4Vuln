#ifndef __SYMBOLIC_JAVA_REFERENCE_H
#define __SYMBOLIC_JAVA_REFERENCE_H
#include "ValueDefinition.h"

namespace columbus { namespace symbolic {



    // Alapvetõen nem létezik referencia szimbólum, mert a referencia mindig mutat valahova
    // Ez az érték a getReferenceValue metódussal kérhetõ le. isSymbol akkor igaz, ha a referencia
    // értékét nem a kód állítja be (new, egyéb értékadás), hanem a végrehajtás közben kell
    // létrehozni (pl szimbolikusan kezelendõ paraméter)

	class Reference : public ValueDefinition<Reference,Address> {
		friend class DefinitionFactory;
	public:
		static const Address default_value;

	private:
		Reference(const Address& value, columbus::NodeId _type, const Address& address, SymbolicEngine& engine, bool isSymbol = false);
		Reference(columbus::NodeId _type, const Address& address, SymbolicEngine& engine);


	public:

        Address getReferenceValue() const {
            return value;
        }

		inline bool isNull() const { return (int)value==0; }
        virtual bool isReference() const { return true; }
		static SmartDefinition unbox(const Reference& ref, SymbolicEngine& engine) ;

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

        //times
        virtual SmartDefinition timesImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition timesImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition timesImpl(const Reference& def) const;

        //divide
        virtual SmartDefinition divideImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition divideImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition divideImpl(const Reference& def) const;

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

		//greater
		virtual SmartDefinition greaterImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition greaterImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition greaterImpl(const Reference& def) const;

		//lessThanOrEqualTo
		virtual SmartDefinition lessThanOrEqualToImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition lessThanOrEqualToImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition lessThanOrEqualToImpl(const Reference& def) const;
		
		//greaterThanOrEqualTo
		virtual SmartDefinition greaterThanOrEqualToImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition greaterThanOrEqualToImpl(const Reference& def) const;
		
		//equals
		virtual SmartDefinition equalsImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition equalsImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition equalsImpl(const Reference& def) const;
        virtual SmartDefinition equalsImpl(const Object& def) const;
		
		//notEquals
		virtual SmartDefinition notEqualsImpl(const CharValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const ByteValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const ShortValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const IntValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const LongValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const FloatValueDefinition& def) const;
        virtual SmartDefinition notEqualsImpl(const DoubleValueDefinition& def) const;
		virtual SmartDefinition notEqualsImpl(const Reference& def) const;
        virtual SmartDefinition notEqualsImpl(const Object& def) const;

		//conditionalAnd
        virtual SmartDefinition conditionalAndImpl(const BooleanValueDefinition& def) const ;
        virtual SmartDefinition conditionalAndImpl(const Reference& def) const ;
        
		//conditionalOr
        virtual SmartDefinition conditionalOrImpl(const BooleanValueDefinition& def) const ;
        virtual SmartDefinition conditionalOrImpl(const Reference& def) const ;

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
#endif