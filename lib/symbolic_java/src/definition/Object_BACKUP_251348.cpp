#include "../../inc/common.h"
#include <typeinfo>

namespace columbus {
	namespace symbolic {

		const Address Object::default_value(0);

		Object::Object(columbus::NodeId _type, bool initialize, const Address& _address, SymbolicEngine& _engine) : ValueDefinition<Object, Address>(_type, _address, _engine), initialized(initialize) {}

		Address Object::getMemberAddress(columbus::NodeId nodeId) {
			std::map<columbus::NodeId, Address>::iterator iter = members.find(nodeId);
			if (iter == members.end())
				iter = members.insert(std::map<columbus::NodeId, Address>::value_type(nodeId, engine.getNextAddress())).first;
			return (*iter).second;
		}

<<<<<<< HEAD
		Object& Object::getRawObject(SmartDefinition reference, SymbolicEngine& engine) {
			const Reference& rawReference = dynamic_cast<const Reference&>(*reference.get());
			SmartDefinitionProxy smartObject = engine.getCurrentState().getObjectByAddress(rawReference.getReferenceValue());

			if (smartObject->isNull()) {
				/**
				 *	No object at this address
				 */
				*smartObject = DefinitionFactory::createObjectWithoutReference(reference->getType(), rawReference.getReferenceValue(), false, engine);
			}

			//intentional const_cast at this point
			return const_cast<Object&>(dynamic_cast<const Object&>(*smartObject->getOwner()->operator columbus::symbolic::SmartDefinition().get()));
		}

		SmartDefinition Object::equalsImpl(const Object& def) const {
			if (getIsSymbol() || def.getIsSymbol()) {
				return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
			}
			return DefinitionFactory::createBoolean(def.addressOf() == addressOf(), engine);
		}

		SmartDefinition Object::equalsImpl(const Reference& def) const {
			if (getIsSymbol() || def.getIsSymbol()) {
				return produceLogicalSymbol(columbus::java::asg::iokNotEqualTo, def, engine);
			}
			return DefinitionFactory::createBoolean(def.getValue() == addressOf(), engine);
		}
=======
				if (smartObject && smartObject->getOwner()) {
				auto def = smartObject->getOwner()->operator columbus::symbolic::SmartDefinition().get();
				if (def) {
					if (auto* obj = dynamic_cast<const Object*>(def)) {						
						return const_cast<Object&>(*obj);
					}
					else {
					 	throw SymbolicColumbusException("dynamic_cast sikertelen: def nem Object típusú.");
					}
				}
				else {
					// Kezeljük a null pointer hibát
					throw SymbolicColumbusException("SmartDefinition().get() null pointert adott vissza.");
				}
			}
			else {
				// Kezeljük a null pointer hibát
				throw SymbolicColumbusException("smartObject vagy smartObject->getOwner() null.");
			}

			//intentional const_cast at this point
		//	return const_cast<Object&>(dynamic_cast<const Object&>(*smartObject->getOwner()->operator columbus::symbolic::SmartDefinition().get()));
		
	}
>>>>>>> 5b3ce85ff9 (better error handling in getObject)
}}
