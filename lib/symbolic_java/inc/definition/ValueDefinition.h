#ifndef _VALUE_DEFINITION_H_
#define _VALUE_DEFINITION_H_

#include "DefinitionDispatcher.h"
#include "SymbolDefinition.h"
#include "symbolic_java/inc/constraint/Z3ConstraintExpression.h"
#include "symbolic_java/inc/constraint/Z3ConstraintBuilder.h"
#include <string>
#include <sstream>

namespace columbus { namespace symbolic {

	class SymbolicEngine;

    template<class T, typename VALUE_TYPE>
    class ValueDefinition : public DefinitionDispatcher<T> {
	public:
		static const VALUE_TYPE default_value;

    protected:
        VALUE_TYPE value;
		bool isSymbol;

        ValueDefinition(columbus::NodeId type, const Address& address, SymbolicEngine&);
		ValueDefinition(VALUE_TYPE _value, NodeId type, const Address& address, SymbolicEngine&);

        SmartDefinition produceLogicalSymbol(columbus::java::asg::InfixOperatorKind oper, const Definition& def, SymbolicEngine& engine) const {
            /*std::stringstream ss;
            ss << columbus::symbolic::Z3ConstraintBuilder::operatorToString(oper);
            ss << (std::string)def << " " << std::to_string(value);
            columbus::symbolic::Z3ConstraintExpression* expr = new columbus::symbolic::Z3ConstraintExpression(ss.str());*/
            auto symDef = columbus::symbolic::SymbolDefinition::makeSymbolDefinition(def, *this, oper, SymbolicTypesPreVisitor::getBooleanTypeId(), engine);
            //symDef->setCsExpr(expr);
            return symDef;
        }

    public:
        virtual ~ValueDefinition() {};
        virtual bool getIsSymbol() const;
        VALUE_TYPE getValue() const;

    };
}}

#endif
