#include "../../inc/common.h"

namespace columbus { namespace symbolic {

	using namespace columbus::java::asg;

	Array::Array(columbus::NodeId _type, SmartDefinition size, bool initialize, const Address& _address, SymbolicEngine& _engine, bool symbol) : Object(_type, initialize, _address, _engine, symbol), size(size) {
		csExpr = engine.getConstraintBuilder()->makeBoolVar(*this);
	}

	NodeId Array::getElementType(NodeId arrayType, SymbolicEngine& engine) {
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		type::ArrayType& type=(type::ArrayType&)factory.getRef(arrayType);
		return type.getComponentType()->getId();
	}

	NodeId Array::getElementType() {
		return Array::getElementType(getType(), engine);
	}

	Address Array::getArrayElementAddress(SmartDefinition def) {
		if (def->getIsSymbol()) {
			/**
			*	TODO: constraints. We'll have to put constraint on the address of created symbol, which cannot be done yet
			*/
			return Address(engine.getNextAddress(), true);
		} else {
			IntValueDefinition& index=(IntValueDefinition&)(*def);
			std::map<unsigned int, Address>::iterator iter=indices.find(index.getValue());
			if (iter==indices.end()) {
				/**
				*	Don't have an address for this index yet. We'll create a symbol if the array has not been initialized;
				*/
				Address address(engine.getNextAddress());
				indices.insert(std::map<unsigned int, Address>::value_type(index.getValue(), address));
				return address;
			} else {
				/**
				*	We already have an address for the index. We'll get the object at that address
				*/
				return (*iter).second;
			}
		}
	}

	int Array::getArrayDimension(NodeId type, SymbolicEngine& engine) {
		const columbus::java::asg::Factory& factory=dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
		NodeId elementType=Array::getElementType(type, engine);
		if (Common::getIsArrayType(factory.getRef(elementType))) {
			return 1+Array::getArrayDimension(elementType, engine);
		}
		return 1;
	}

	int Array::getArrayDimension() {
		return Array::getArrayDimension(getType(), engine);
	}
	
	Array& Array::getRawArray(SmartDefinition reference, SymbolicEngine& engine, bool initializedAtDecl, bool initializedAtStatic) {
        // !!!TODO!!! see redmine issue 415
        // reference must be a Refence, this check is just a quckfix, would not be necessary 
        if (!reference->isReference()) throw SymbolicColumbusException("Bad cast error: Given SmartDefinition is not a reference.");

		const Reference& rawReference=dynamic_cast<const Reference&>(*reference.get());

		SmartDefinitionProxy smartArray=engine.getCurrentState().getObjectByAddress(rawReference.getReferenceValue());
		if (smartArray->isNull()) {
		   /**
			*	No array at this address
			*/

			*smartArray=DefinitionFactory::createArrayWithoutReference(reference->getType(), DefinitionFactory::createInt(engine), rawReference.getReferenceValue(), initializedAtDecl || initializedAtStatic, engine);
		}

        // !!!TODO!!! QUICK FIX!!!!!! see redmine issue 416
        // SmartArray must be an array at any conditions
        if (!smartArray->getOwner()->operator columbus::symbolic::SmartDefinition()->isArray()) throw SymbolicColumbusException("Bad cast error: There must be an array, but a not array object is present.");

		return const_cast<Array&>(dynamic_cast<const Array&>(*smartArray->getOwner()->operator columbus::symbolic::SmartDefinition().get()));
	}

}}
