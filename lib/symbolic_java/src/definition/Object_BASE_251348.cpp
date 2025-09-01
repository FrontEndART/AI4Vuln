#include "../../inc/common.h"

namespace columbus { namespace symbolic {

	Object::Object(columbus::NodeId _type, bool initialize, const Address& _address, SymbolicEngine& _engine) : DefinitionDispatcher<Object>(_type, _address, _engine), initialized(initialize) {}

	Address Object::getMemberAddress(columbus::NodeId nodeId) {
		std::map<columbus::NodeId, Address>::iterator iter=members.find(nodeId);
		if (iter==members.end()) 
			iter=members.insert(std::map<columbus::NodeId, Address>::value_type(nodeId, engine.getNextAddress())).first;
		return (*iter).second;		
	}

	Object& Object::getRawObject(SmartDefinition reference, SymbolicEngine& engine) {
		const Reference& rawReference=dynamic_cast<const Reference&>(*reference.get());
		SmartDefinitionProxy smartObject = engine.getCurrentState().getObjectByAddress(rawReference.getReferenceValue());

        if (smartObject->isNull()) {
		   /**
			*	No object at this address
			*/
			*smartObject=DefinitionFactory::createObjectWithoutReference(reference->getType(), rawReference.getReferenceValue(), false, engine);
		}

		//intentional const_cast at this point
		return const_cast<Object&>(dynamic_cast<const Object&>(*smartObject->getOwner()->operator columbus::symbolic::SmartDefinition().get()));
	}
}}
