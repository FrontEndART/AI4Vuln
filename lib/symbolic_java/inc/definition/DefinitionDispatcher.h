#ifndef _DEFINITION_DISPATCHER_H_
#define _DEFINITION_DISPATCHER_H_

#include <symbolic/inc/definition/Definition.h>
#include <symbolic_java/inc/definition/DefinitionDispatcherTargetInterface.h>

namespace columbus { namespace symbolic {
	class SymbolicEngine;

    class MiddleDispatcher : public Definition, public DefinitionDispatcherTargetInterface {
    protected:
        MiddleDispatcher(columbus::NodeId type, SymbolicEngine& _engine) : Definition(type, _engine) { }
		MiddleDispatcher(columbus::NodeId type, const Address& address, SymbolicEngine& _engine) : Definition(type, address, _engine) { }

	protected:

        virtual SmartDefinition plus(const Definition& def) const = 0;
        virtual SmartDefinition minus(const Definition& def) const = 0;
        virtual SmartDefinition times(const Definition& def) const = 0;
        virtual SmartDefinition divide(const Definition& def) const = 0;
        virtual SmartDefinition remainder(const Definition& def) const = 0;
        virtual SmartDefinition leftShift(const Definition& def) const = 0;
        virtual SmartDefinition signedRightShift(const Definition& def) const = 0;
        virtual SmartDefinition unsignedRightShift(const Definition& def) const = 0;
        virtual SmartDefinition bitwiseAndLogicalAnd(const Definition& def) const = 0;
        virtual SmartDefinition bitwiseAndLogicalOr(const Definition& def) const = 0;
        virtual SmartDefinition bitwiseAndLogicalXor(const Definition& def) const = 0;
        virtual SmartDefinition less(const Definition& def) const = 0;
        virtual SmartDefinition greater(const Definition& def) const = 0;
        virtual SmartDefinition lessThanOrEqualTo(const Definition& def) const = 0;
        virtual SmartDefinition greaterThanOrEqualTo(const Definition& def) const = 0;
        virtual SmartDefinition equals(const Definition& def) const = 0;
        virtual SmartDefinition notEquals(const Definition& def) const = 0;
        virtual SmartDefinition conditionalAnd(const Definition& def) const = 0;
        virtual SmartDefinition conditionalOr(const Definition& def) const = 0;

        //a tipusok kulonboznhetnek!!! pl. int a=(double)b;
        virtual SmartDefinition assignValue(const Definition& def) const = 0;
        virtual SmartDefinition plusAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition minusAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition timesAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition divideAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition remainderAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition bitwiseAndAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition bitwiseOrAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition bitwiseXorAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition leftShiftAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition rightShiftAssignValue(const Definition &def) const = 0;
        virtual SmartDefinition unsignedRightShiftAssignValue(const Definition &def) const = 0;
    };

    template<class T>
    class DefinitionDispatcher : public MiddleDispatcher {
    protected:
        DefinitionDispatcher(columbus::NodeId type, SymbolicEngine& _engine) : MiddleDispatcher(type, _engine) {}
		DefinitionDispatcher(columbus::NodeId type, const Address& address, SymbolicEngine& _engine) : MiddleDispatcher(type, address, _engine) {}

    public:

        virtual SmartDefinition plus(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).plusImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition minus(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).minusImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition times(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).timesImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition divide(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).divideImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition remainder(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).remainderImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition leftShift(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).leftShiftImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition signedRightShift(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).signedRightShiftImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition unsignedRightShift(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).unsignedRightShiftImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition bitwiseAndLogicalAnd(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).bitwiseAndLogicalAndImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition bitwiseAndLogicalOr(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).bitwiseAndLogicalOrImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition bitwiseAndLogicalXor(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).bitwiseAndLogicalXorImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition less(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).lessImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition greater(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).greaterImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition lessThanOrEqualTo(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).lessThanOrEqualToImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition greaterThanOrEqualTo(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).greaterThanOrEqualToImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition equals(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).equalsImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition notEquals(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).notEqualsImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition conditionalAnd(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).conditionalAndImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition conditionalOr(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).conditionalOrImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition assignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).assignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition plusAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).plusAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition minusAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).minusAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition timesAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).timesAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition divideAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).divideAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition remainderAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).remainderAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition bitwiseAndAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).bitwiseAndAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition bitwiseOrAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).bitwiseOrAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition bitwiseXorAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).bitwiseXorAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition leftShiftAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).leftShiftAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition rightShiftAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).rightShiftAssignValueImpl(static_cast<const T&>(*this));
        }

        virtual SmartDefinition unsignedRightShiftAssignValue(const Definition& def) const {
            return static_cast<const MiddleDispatcher&>(def).unsignedRightShiftAssignValueImpl(static_cast<const T&>(*this));
        }
    };

}}

#endif
