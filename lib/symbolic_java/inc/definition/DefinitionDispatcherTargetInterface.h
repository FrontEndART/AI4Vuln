#ifndef _DEFINITION_DISPATCHER_TARGET_INTERFACE_H_
#define _DEFINITION_DISPATCHER_TARGET_INTERFACE_H_

#include <symbolic/inc/definition/Definition.h>
#include <symbolic/inc/structure/State.h>
#include <symbolic/inc/structure/SymbolicColumbusException.h>

namespace columbus {
    namespace symbolic {

        class SymbolDefinition;
        class BooleanValueDefinition;
        class ByteValueDefinition;
        class CharValueDefinition;
        class DoubleValueDefinition;
        class FloatValueDefinition;
        class IntValueDefinition;
        class LongValueDefinition;
        class ShortValueDefinition;
        class StringValueDefinition;
        class Object;
        class Reference;
        class State;

        class DefinitionDispatcherTargetInterface {
        public:
            virtual ~DefinitionDispatcherTargetInterface() {};

            //plus
            virtual SmartDefinition plusImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(IntValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(LongValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(CharValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition plusImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(Symbol)!"); };
            virtual SmartDefinition plusImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(Symbol)!"); };
            virtual SmartDefinition plusImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(Symbol)!"); };
            virtual SmartDefinition plusImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };

          //  virtual SmartDefinition plusImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusImpl(Symbol)!"); };


            //minus
            virtual SmartDefinition minusImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(IntValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(LongValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(CharValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition minusImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(Symbol)!"); };
            virtual SmartDefinition minusImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(Symbol)!"); };
            virtual SmartDefinition minusImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusImpl(Symbol)!"); };
            virtual SmartDefinition minusImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //times
            virtual SmartDefinition timesImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(IntValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(LongValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(CharValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition timesImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(Symbol)!"); };
            virtual SmartDefinition timesImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(Symbol)!"); };
            virtual SmartDefinition timesImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesImpl(Symbol)!"); };
            virtual SmartDefinition timesImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //divide
            virtual SmartDefinition divideImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(IntValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(LongValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(CharValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition divideImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(Symbol)!"); };
            virtual SmartDefinition divideImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(Symbol)!"); };
            virtual SmartDefinition divideImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideImpl(Symbol)!"); };
            virtual SmartDefinition divideImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //remainder
            virtual SmartDefinition remainderImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(IntValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(LongValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(CharValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition remainderImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(Symbol)!"); };
            virtual SmartDefinition remainderImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(Symbol)!"); };
            virtual SmartDefinition remainderImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderImpl(Symbol)!"); };
            virtual SmartDefinition remainderImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //leftShift
            virtual SmartDefinition leftShiftImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(IntValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(LongValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(CharValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition leftShiftImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(Symbol)!"); };
            virtual SmartDefinition leftShiftImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(Symbol)!"); };
            virtual SmartDefinition leftShiftImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftImpl(Symbol)!"); };
            virtual SmartDefinition leftShiftImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //signedRightShift
            virtual SmartDefinition signedRightShiftImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(IntValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(LongValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(CharValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition signedRightShiftImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(Symbol)!"); };
            virtual SmartDefinition signedRightShiftImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(Symbol)!"); };
            virtual SmartDefinition signedRightShiftImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: signedRightShiftImpl(Symbol)!"); };
            virtual SmartDefinition signedRightShiftImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //unsignedRightShift
            virtual SmartDefinition unsignedRightShiftImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(IntValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(LongValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(CharValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(Symbol)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(Symbol)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftImpl(Symbol)!"); };
            virtual SmartDefinition unsignedRightShiftImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //bitwiseAndLogicalAnd
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(IntValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(LongValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(CharValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalAndImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalAndImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //bitwiseAndLogicalOr
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(IntValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(LongValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(CharValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalOrImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalOrImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //bitwiseAndLogicalXor
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(IntValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(LongValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(CharValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndLogicalXorImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndLogicalXorImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //less
            virtual SmartDefinition lessImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(IntValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(LongValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(CharValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition lessImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(Symbol)!"); };
            virtual SmartDefinition lessImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(Symbol)!"); };
            virtual SmartDefinition lessImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessImpl(Symbol)!"); };
            virtual SmartDefinition lessImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //greater;
            virtual SmartDefinition greaterImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(IntValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(LongValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(CharValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition greaterImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(Symbol)!"); }
            virtual SmartDefinition greaterImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(Symbol)!"); }
            virtual SmartDefinition greaterImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterImpl(Symbol)!"); }
            virtual SmartDefinition greaterImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //lessThanOrEqualTo
            virtual SmartDefinition lessThanOrEqualToImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(IntValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(LongValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(CharValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(Symbol)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(Symbol)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: lessThanOrEqualToImpl(Symbol)!"); };
            virtual SmartDefinition lessThanOrEqualToImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //greaterThanOrEqualToImpl
            virtual SmartDefinition greaterThanOrEqualToImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(IntValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(LongValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(CharValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(Symbol)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(Symbol)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: greaterThanOrEqualToImpl(Symbol)!"); };
            virtual SmartDefinition greaterThanOrEqualToImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //equals
            virtual SmartDefinition equalsImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(IntValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(LongValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(CharValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition equalsImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(Symbol)!"); };
            virtual SmartDefinition equalsImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(Symbol)!"); };
            virtual SmartDefinition equalsImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: equalsImpl(Symbol)!"); };
            virtual SmartDefinition equalsImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //notEquals
            virtual SmartDefinition notEqualsImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(IntValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(LongValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(CharValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition notEqualsImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(Symbol)!"); };
            virtual SmartDefinition notEqualsImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(Symbol)!"); };
            virtual SmartDefinition notEqualsImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: notEqualsImpl(Symbol)!"); };
            virtual SmartDefinition notEqualsImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //conditionalAnd
            virtual SmartDefinition conditionalAndImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(IntValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(LongValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(CharValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition conditionalAndImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(Symbol)!"); };
            virtual SmartDefinition conditionalAndImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(Symbol)!"); };
            virtual SmartDefinition conditionalAndImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalAndImpl(Symbol)!"); };
            virtual SmartDefinition conditionalAndImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //conditionalOr
            virtual SmartDefinition conditionalOrImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(IntValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(LongValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(CharValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition conditionalOrImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(Symbol)!"); };
            virtual SmartDefinition conditionalOrImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(Symbol)!"); };
            virtual SmartDefinition conditionalOrImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: conditionalOrImpl(Symbol)!"); };
            virtual SmartDefinition conditionalOrImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //assignValue
            virtual SmartDefinition assignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(ByteValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(ShortValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(IntValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(LongValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(BooleanValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(CharValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(FloatValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(DoubleValueDefinition)!"); };
            virtual SmartDefinition assignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!"); };
            virtual SmartDefinition assignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!"); };
            virtual SmartDefinition assignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: assignValueImp(Reference)!"); };
            virtual SmartDefinition assignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //plusAssign
            virtual SmartDefinition plusAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition plusAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(Reference)!"); };
            virtual SmartDefinition plusAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(Reference)!"); };
            virtual SmartDefinition plusAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: plusAssignValueImpl(Reference)!"); };
            virtual SmartDefinition plusAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //minusAssign
            virtual SmartDefinition minusAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition minusAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition minusAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition minusAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: minusAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition minusAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //timesAssign
            virtual SmartDefinition timesAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition timesAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition timesAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition timesAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: timesAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition timesAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //divideAssign
            virtual SmartDefinition divideAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition divideAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition divideAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition divideAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: divideAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition divideAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //remainderAssign
            virtual SmartDefinition remainderAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: remainderAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition remainderAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //bitwiseAndAssignValue
            virtual SmartDefinition bitwiseAndAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseAndAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseAndAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //bitwiseOrAssignValue
            virtual SmartDefinition bitwiseOrAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseOrAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseOrAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //bitwiseXorAssignValue
            virtual SmartDefinition bitwiseXorAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: bitwiseXorAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition bitwiseXorAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //leftShiftAssignValue
            virtual SmartDefinition leftShiftAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition leftShiftAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: leftShiftAssignValueImpl(Symbol)!"); };


            //rightShiftAssignValue
            virtual SmartDefinition rightShiftAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition rightShiftAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: rightShiftAssignValueImpl(Symbol)!"); };


            //unsignedRightShiftAssignValue
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const ByteValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(ByteValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const ShortValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(ShortValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const IntValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(IntValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const LongValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(LongValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const BooleanValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(BooleanValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const CharValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(CharValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const FloatValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(FloatValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const DoubleValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(DoubleValueDefinition)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const Reference& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const SymbolDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const StringValueDefinition& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(Symbol)!"); };
            virtual SmartDefinition unsignedRightShiftAssignValueImpl(const Object& def) const { throw SymbolicColumbusException("Illegal dispatch: unsignedRightShiftAssignValueImpl(Symbol)!"); };

        };

    }
}

#endif
