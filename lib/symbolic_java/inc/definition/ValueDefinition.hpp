#include "java/inc/java.h"

#ifndef _VALUE_DEFINITION_CPP_
#define _VALUE_DEFINITION_CPP_

#include <sstream>

#include "symbolic_java/inc/definition/ValueDefinition.h"
#include "symbolic_java/inc/definition/ByteValueDefinition.h"
#include "symbolic_java/inc/definition/ShortValueDefinition.h"
#include "symbolic_java/inc/definition/IntValueDefinition.h"
#include "symbolic_java/inc/definition/LongValueDefinition.h"
#include "symbolic_java/inc/definition/BooleanValueDefinition.h"
#include "symbolic_java/inc/definition/CharValueDefinition.h"
#include "symbolic_java/inc/definition/FloatValueDefinition.h"
#include "symbolic_java/inc/definition/DoubleValueDefinition.h"
#include "symbolic/inc/algorithms/SymbolicEngine.h"

namespace columbus { namespace symbolic {


   template<class T, typename VALUE_TYPE>
   ValueDefinition<T, VALUE_TYPE>::ValueDefinition(NodeId type, const Address& address, SymbolicEngine& _engine) : DefinitionDispatcher<T>(type, address, _engine), value(T::default_value), isSymbol(true) {
   }

	template<class T, typename VALUE_TYPE>
    ValueDefinition<T, VALUE_TYPE>::ValueDefinition(VALUE_TYPE _value, NodeId type, const Address& address, SymbolicEngine& _engine) : DefinitionDispatcher<T>(type, address, _engine), value(_value), isSymbol(false) {
    }
	
	template<class T, typename VALUE_TYPE>
    bool ValueDefinition<T, VALUE_TYPE>::getIsSymbol() const {
		return isSymbol;
	}

	template<class T, typename VALUE_TYPE>
    VALUE_TYPE ValueDefinition<T, VALUE_TYPE>::getValue() const {
		if (isSymbol)
			throw SymbolicColumbusException("Attempting to retrieve the value of a symbol");
		return value;
	}
}}

#endif
