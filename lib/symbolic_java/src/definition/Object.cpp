#include "../../inc/common.h"

namespace columbus {
	namespace symbolic {

		const Address Object::default_value(0);

		Object::Object(columbus::NodeId _type, bool initialize, const Address& _address, SymbolicEngine& _engine, bool symbol) : ValueDefinition<Object, Address>(_type, _address, _engine), initialized(initialize) {
			isSymbol = symbol;
			value = default_value;
		}

		Address Object::getMemberAddress(columbus::NodeId nodeId) {
			std::map<columbus::NodeId, Address>::iterator iter = members.find(nodeId);
			if (iter == members.end())
				iter = members.insert(std::map<columbus::NodeId, Address>::value_type(nodeId, engine.getNextAddress())).first;
			return (*iter).second;
		}

		Object& Object::getRawObject(SmartDefinition reference, SymbolicEngine& engine) {
			const Reference* rawReference = dynamic_cast<const Reference*>(reference.get());
			if (!rawReference) {
				throw SymbolicColumbusException("Invalid reference!");
			}
			SmartDefinitionProxy smartObject = engine.getCurrentState().getObjectByAddress(rawReference->getReferenceValue());

			if (smartObject->isNull()) {
				/**
				 *	No object at this address
				 */
				*smartObject = DefinitionFactory::createObjectWithoutReference(reference->getType(), rawReference->getReferenceValue(), false, engine);
			}

			if (smartObject && smartObject->getOwner()) {
				auto def = smartObject->getOwner()->operator columbus::symbolic::SmartDefinition().get();
				if (def) {
					if (auto* obj = dynamic_cast<const Object*>(def)) {
						return const_cast<Object&>(*obj);
					}
					else {
						throw SymbolicColumbusException("bad dynamic_cast: def is not an Object.");
					}
				}
				else {
					throw SymbolicColumbusException("SmartDefinition().get() returned nullptr");
				}
			}
			else {
				throw SymbolicColumbusException("smartObject or smartObject->getOwner() null.");
			}
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
}}
