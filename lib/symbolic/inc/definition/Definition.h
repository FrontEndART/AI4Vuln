#ifndef _SYMBOLIC_DEFINITION_H_
#define _SYMBOLIC_DEFINITION_H_

//#include "../common.h"
#include "symbolic/inc/constraint/ConstraintSolverExpr.h"
#include "symbolic/inc/constraint/Constraint.h"

namespace columbus { namespace symbolic {

    class State;
    class Definition;
	class SymbolicEngine;

    class Definition {

		static unsigned long nextDefinitionId;

		unsigned long definitionId;
    
    protected:
		Address address;
        columbus::NodeId m_definitionType;
		SymbolicEngine& engine;
		
		mutable std::shared_ptr<ConstraintSolverExpr> csExpr;
        mutable ConstraintSet gatherdDependencies;

		Definition(columbus::NodeId _type, SymbolicEngine& _engine);
		Definition(const Definition& def) = delete;
		Definition& operator=(const Definition& def) = delete;
		Definition(columbus::NodeId _type, SymbolicEngine& _engine, ConstraintSolverExpr* csExpr);
        Definition(columbus::NodeId _type, const Address& _address, SymbolicEngine& _engine);
		virtual ~Definition();

    public:

		const std::shared_ptr<ConstraintSolverExpr> getCsExpr()const {
			return csExpr;
		}

		void setCsExpr(std::shared_ptr<ConstraintSolverExpr> csExpr_) const {
			//delete csExpr;
			csExpr = csExpr_;
		}

		void setDependencies(const ConstraintSet& deps) const {
			gatherdDependencies = deps;
		}

		const ConstraintSet& getGatherdDependencies() const {
			return gatherdDependencies;
		}

		virtual operator std::string()const {
			return "id_" + std::to_string(definitionId);
		}
		/**
		*	Binary operators
		*/
		virtual SmartDefinition plus(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition minus(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition times(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition divide(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition remainder(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition leftShift(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition signedRightShift(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition unsignedRightShift(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition bitwiseAndLogicalAnd(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition bitwiseAndLogicalOr(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition bitwiseAndLogicalXor(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition less(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition greater(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition lessThanOrEqualTo(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition greaterThanOrEqualTo(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition equals(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition notEquals(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition conditionalAnd(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };
		virtual SmartDefinition conditionalOr(const Definition& def) const { throw SymbolicColumbusException("Illegal dispatch!"); };

		/**
		*	Unary operators
		*/
		virtual SmartDefinition increment() const {throw SymbolicColumbusException("Cannot increment definition");}
        virtual SmartDefinition decrement() const {throw SymbolicColumbusException("Cannot increment definition");}
        virtual SmartDefinition prePlus() const {throw SymbolicColumbusException("Cannot pre-plus definition");}
        virtual SmartDefinition preMinus() const {throw SymbolicColumbusException("Cannot pre-minus definition");}
        virtual SmartDefinition negate() const {throw SymbolicColumbusException("Cannot negate definition");}
		virtual SmartDefinition complement() const {throw SymbolicColumbusException("Cannot complement definition");}

		/**
		*	Typecast operators
		*/
		virtual SmartDefinition castToBoolean() const = 0;
		virtual SmartDefinition castToByte() const = 0 ;
		virtual SmartDefinition castToChar() const = 0 ;
		virtual SmartDefinition castToShort() const = 0 ;
		virtual SmartDefinition castToInt() const = 0 ;
		virtual SmartDefinition castToLong() const = 0 ;
		virtual SmartDefinition castToFloat() const = 0 ;
		virtual SmartDefinition castToDouble() const = 0 ;
		virtual SmartDefinition castToReference(NodeId toType) const = 0;

       
        columbus::NodeId getType() const { return m_definitionType;}
		
        virtual bool isBooleanValueDefinition() const { return false;}
		virtual bool isByteValueDefinition() const { return false;}
		virtual bool isCharValueDefinition() const { return false;}
		virtual bool isShortValueDefinition() const { return false;}
		virtual bool isIntValueDefinition() const { return false;}
		virtual bool isLongValueDefinition() const { return false;}
		virtual bool isFloatValueDefinition() const { return false;}
		virtual bool isDoubleValueDefinition() const { return false;}
		virtual bool isReference() const { return false;}
		virtual bool isArray() const { return false;}

		virtual Address addressOf() const { return address; }
		virtual bool getIsSymbol() const = 0;
};

}}

#endif
