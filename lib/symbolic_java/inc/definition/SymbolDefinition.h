#ifndef _SYMBOL_DEFINITION_H_
#define _SYMBOL_DEFINITION_H_

#include <java/inc/Types.h>

#include "symbolic_java/inc/definition/DefinitionDispatcher.h"
#include "symbolic_java/inc/definition/DefinitionFactory.h"

namespace columbus { namespace symbolic {

    class SymbolDefinition : public DefinitionDispatcher<SymbolDefinition> {
		
		friend class DefinitionFactory; 

    public:
	
		virtual bool getIsSymbol() const override { return true; }
	
        virtual SmartDefinition plusImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition plusImpl(const Reference& def) const override;
        virtual SmartDefinition plusImpl(const SymbolDefinition& def) const override;
		
		virtual SmartDefinition minusImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition minusImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition minusImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition minusImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition minusImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition minusImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition minusImpl(const DoubleValueDefinition& def) const override;
		virtual SmartDefinition minusImpl(const Reference& def) const override;
		virtual SmartDefinition minusImpl(const SymbolDefinition& def) const override;
		
		virtual SmartDefinition timesImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition timesImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition timesImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition timesImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition timesImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition timesImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition timesImpl(const DoubleValueDefinition& def) const override;
		virtual SmartDefinition timesImpl(const Reference& def) const override;
		virtual SmartDefinition timesImpl(const SymbolDefinition& def) const override;
		
		virtual SmartDefinition divideImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition divideImpl(const Reference& def) const override;
		virtual SmartDefinition divideImpl(const SymbolDefinition& def) const override;

		virtual SmartDefinition remainderImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition remainderImpl(const Reference& def) const override;
        virtual SmartDefinition remainderImpl(const SymbolDefinition& def) const override;
	
        virtual SmartDefinition leftShiftImpl(const CharValueDefinition& def) const  override;
        virtual SmartDefinition leftShiftImpl(const ByteValueDefinition& def) const  override;
        virtual SmartDefinition leftShiftImpl(const ShortValueDefinition& def) const  override;
        virtual SmartDefinition leftShiftImpl(const IntValueDefinition& def) const  override;
        virtual SmartDefinition leftShiftImpl(const LongValueDefinition& def) const  override;
        virtual SmartDefinition leftShiftImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftImpl(const Reference& def)  const override;
		virtual SmartDefinition leftShiftImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition signedRightShiftImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition signedRightShiftImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition signedRightShiftImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition signedRightShiftImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition signedRightShiftImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition signedRightShiftImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition signedRightShiftImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition signedRightShiftImpl(const Reference& def)  const override;
		virtual SmartDefinition signedRightShiftImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition unsignedRightShiftImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition unsignedRightShiftImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition unsignedRightShiftImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition unsignedRightShiftImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition unsignedRightShiftImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition unsignedRightShiftImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftImpl(const Reference& def)  const override;
		virtual SmartDefinition unsignedRightShiftImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndLogicalAndImpl(const Reference& def) const override;
		virtual SmartDefinition bitwiseAndLogicalAndImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const Reference& def) const override;
        virtual SmartDefinition bitwiseAndLogicalOrImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const Reference& def) const override;
        virtual SmartDefinition bitwiseAndLogicalXorImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition lessImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition lessImpl(const Reference& def) const override;
        virtual SmartDefinition lessImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition greaterImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition greaterImpl(const Reference& def) const override;
        virtual SmartDefinition greaterImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition lessThanOrEqualToImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const Reference& def) const override;
        virtual SmartDefinition lessThanOrEqualToImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition greaterThanOrEqualToImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const Reference& def) const override;
        virtual SmartDefinition greaterThanOrEqualToImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition equalsImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition equalsImpl(const Reference& def) const override;
        virtual SmartDefinition equalsImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition notEqualsImpl(const CharValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const ByteValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const ShortValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const LongValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const FloatValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const DoubleValueDefinition& def) const override;
        virtual SmartDefinition notEqualsImpl(const Reference& def) const override;
        virtual SmartDefinition notEqualsImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition conditionalAndImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const BooleanValueDefinition& def) const override;
        virtual SmartDefinition conditionalAndImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalAndImpl(const SymbolDefinition& def) const override;
		
        virtual SmartDefinition conditionalOrImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition conditionalOrImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition conditionalOrImpl(const BooleanValueDefinition& def) const override;
		
        //assignValue
        virtual SmartDefinition assignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition assignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition assignValueImpl(const SymbolDefinition& def) const override;

        //plusAssign
        virtual SmartDefinition plusAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition plusAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition plusAssignValueImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition plusAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition plusAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition plusAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition plusAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition plusAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition plusAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition plusAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //minusAssign
        virtual SmartDefinition minusAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition minusAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition minusAssignValueImpl(const IntValueDefinition& def) const override;
        virtual SmartDefinition minusAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition minusAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition minusAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition minusAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition minusAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition minusAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition minusAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //timesAssign
        virtual SmartDefinition timesAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition timesAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition timesAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition timesAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //divideAssign
        virtual SmartDefinition divideAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition divideAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition divideAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition divideAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //remainderAssign
        virtual SmartDefinition remainderAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition remainderAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition remainderAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition remainderAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //bitwiseAndAssignValue
        virtual SmartDefinition bitwiseAndAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition bitwiseAndAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseAndAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }


        //bitwiseOrAssignValue
        virtual SmartDefinition bitwiseOrAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseOrAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition bitwiseOrAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition bitwiseOrAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }


        //bitwiseXorAssignValue
        virtual SmartDefinition bitwiseXorAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition bitwiseXorAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition bitwiseXorAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition bitwiseXorAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //leftShiftAssignValue
        virtual SmartDefinition leftShiftAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition leftShiftAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition leftShiftAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition leftShiftAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        //rightShiftAssignValue
        virtual SmartDefinition rightShiftAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition rightShiftAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition rightShiftAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition rightShiftAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }


        //unsignedRightShiftAssignValue
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const ByteValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const ShortValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const IntValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const LongValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const BooleanValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const CharValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const FloatValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition unsignedRightShiftAssignValueImpl(const DoubleValueDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition unsignedRightShiftAssignValueImpl(const Reference& def) const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition unsignedRightShiftAssignValueImpl(const SymbolDefinition& def) const override { throw SymbolicColumbusException("Should not be happenning"); }

        virtual SmartDefinition negate() const override;


        //a tipusok kulonboznhetnek!!! pl. int a=(double)b;
        SymbolDefinition(columbus::NodeId _type, const Address& addr, SymbolicEngine& engine, bool setCsExpr = true);

        SymbolDefinition(columbus::NodeId _type, const Address& addr, SymbolicEngine& engine, std::shared_ptr<ConstraintSolverExpr> expr, const ConstraintSet& constraints = ConstraintSet());

        virtual ~SymbolDefinition();

        virtual bool isValueDefinition() const {return false; }
        virtual bool isSymbolDefinition() const {return true; }
        virtual std::ostream& print(std::ostream& out) const;
		
		//todo -> tipus alapjan?
		virtual SmartDefinition castToByte() const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToChar() const override { throw SymbolicColumbusException("Should not be happenning");  }
        virtual SmartDefinition castToShort() const override;
        virtual SmartDefinition castToInt() const override;
        virtual SmartDefinition castToLong() const override;
		virtual SmartDefinition castToFloat() const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToDouble() const override { throw SymbolicColumbusException("Should not be happenning"); }
		virtual SmartDefinition castToReference(NodeId toType) const override { throw SymbolicColumbusException("Should not be happenning"); }
        virtual SmartDefinition castToBoolean() const override;

        virtual SmartDefinition increment() const override;
        virtual SmartDefinition decrement() const override;

    private:
            SmartDefinition castIntegralType() const;

    public:
        /**
         * Creates a SymbolDefinition with a CSExpression and with its dependencies. At least on of the 2 Derinition parameters
         * should be SymbolDefinition.
         *
         * @param left Left-side operand
         * @param right Right-side operand
         * @param operation The infix operation
         * @param type The type of the SymbolDef to be create
         * @return SmartDefinition that points to the created SymbolDef
         */
        static SmartDefinition makeSymbolDefinition(const Definition& left, const Definition& right, columbus::java::asg::InfixOperatorKind operation, NodeId type, SymbolicEngine& engine);
        static SmartDefinition makeSymbolDefinition(const Definition& operand, columbus::java::asg::PrefixOperatorKind operation, NodeId type, SymbolicEngine& engine);

        /** Creates the new SymboldDefinition with the additional constraint related to the assignment */
        static SmartDefinition makeSymbolDefinitionForAssignment(const Definition& left, const Definition& right, columbus::java::asg::AssignmentOperatorKind assignmentType, SymbolicEngine& engine);

        
        SmartDefinition produceLogicalSymbol(columbus::java::asg::InfixOperatorKind oper, const Definition& def, SymbolicEngine& engine) const {
            //std::stringstream ss;
            //ss << columbus::symbolic::Z3ConstraintBuilder::operatorToString(oper);
            //ss << (std::string)def << " " << this->getCsExpr()->getStrRep();
            //columbus::symbolic::Z3ConstraintExpression* expr = new columbus::symbolic::Z3ConstraintExpression(ss.str());
            auto symDef = columbus::symbolic::SymbolDefinition::makeSymbolDefinition(def, *this, oper, SymbolicTypesPreVisitor::getBooleanTypeId(), engine);
            //symDef->setCsExpr(expr);
            return symDef;
        }

        virtual bool isNegated() const {
            return false;
        }

        SmartDefinition conditionalExpr() const;
        
        
     };

     class NegatedSymbolDefinition : public SymbolDefinition {
         friend class DefinitionFactory;

         const SymbolDefinition* original;
         bool negated;

     public:

         NegatedSymbolDefinition(const Address& addr, SymbolicEngine& engine, const SymbolDefinition* original, bool neg);

         const SymbolDefinition* getOriginal() const {
             return original;
         }
         virtual bool isNegated() const override{
             return negated;
         }
         virtual operator std::string()const override{
             return "cond" + Definition::operator std::string();
         }





     };
 } }

#endif
