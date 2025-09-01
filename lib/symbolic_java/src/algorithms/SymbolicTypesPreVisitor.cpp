#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    columbus::NodeId SymbolicTypesPreVisitor::VOID_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::CHAR_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::BYTE_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::SHORT_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::INT_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::LONG_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::FLOAT_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::DOUBLE_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::BOOLEAN_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::NULL_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::ERROR_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::OBJECT_TYPE_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::OBJECT_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::INTEGER_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::BOOLEAN_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::FLOAT_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::DOUBLE_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::CHARACTER_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::LONG_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::BYTE_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::SHORT_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::STRING_CLASS_ID = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::STRING_TYPE_ID = UINT_MAX;

    columbus::NodeId SymbolicTypesPreVisitor::FLOAT_NAN = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::FLOAT_NEGATIVE_INFINITY = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::FLOAT_POSITIVE_INFINITY = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::DOUBLE_NAN = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::DOUBLE_NEGATIVE_INFINITY = UINT_MAX;
    columbus::NodeId SymbolicTypesPreVisitor::DOUBLE_POSITIVE_INFINITY = UINT_MAX;

    columbus::java::asg::Factory* SymbolicTypesPreVisitor::m_asgFactory;

    std::set<SymbolicTypesPreVisitor::TypesForSymbolic, SymbolicTypesPreVisitor::TypesForSymbolic_compare> SymbolicTypesPreVisitor::TYPES;
    std::set<SymbolicTypesPreVisitor::ClassForSymbolic, SymbolicTypesPreVisitor::ClassForSymbolic_compare> SymbolicTypesPreVisitor::CLASSES;
    std::set<SymbolicTypesPreVisitor::MethodForSymbolic, SymbolicTypesPreVisitor::MethodForSymbolic_compare> SymbolicTypesPreVisitor::METHODS;

    std::map<NodeId, std::set<NodeId> > SymbolicTypesPreVisitor::SUPER_CLASSES;

    SymbolicTypesPreVisitor::SymbolicTypesPreVisitor(columbus::java::asg::Factory *factory) {
        VOID_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkVoidType)->getId();
        CHAR_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkCharType)->getId();
        BYTE_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkByteType)->getId();
        SHORT_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkShortType)->getId();
        INT_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkIntType)->getId();
        LONG_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkLongType)->getId();
        FLOAT_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkFloatType)->getId();
        DOUBLE_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkDoubleType)->getId();
        BOOLEAN_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkBooleanType)->getId();
        NULL_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkNullType)->getId();
        ERROR_TYPE_ID = factory->getAPSpecNode(columbus::java::asg::ndkErrorType)->getId();
        m_asgFactory = factory;
    }

    void SymbolicTypesPreVisitor::init() {
        OBJECT_CLASS_ID = UINT_MAX;
        INTEGER_CLASS_ID = UINT_MAX;
        BOOLEAN_CLASS_ID = UINT_MAX;
        FLOAT_CLASS_ID = UINT_MAX;
        DOUBLE_CLASS_ID = UINT_MAX;
        STRING_CLASS_ID = UINT_MAX;
        CHARACTER_CLASS_ID = UINT_MAX;
        BYTE_CLASS_ID = UINT_MAX;
        SHORT_CLASS_ID = UINT_MAX;
        LONG_CLASS_ID = UINT_MAX;

        FLOAT_NAN = UINT_MAX;
        FLOAT_NEGATIVE_INFINITY = UINT_MAX;
        FLOAT_POSITIVE_INFINITY = UINT_MAX;
        DOUBLE_NAN = UINT_MAX;
        DOUBLE_NEGATIVE_INFINITY = UINT_MAX;
        DOUBLE_POSITIVE_INFINITY = UINT_MAX;

        clean();
    }

    void SymbolicTypesPreVisitor::clean() {
        for (TypesType::iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::METHOD_TYPE) {
                if (it->addInf.MethodType.parameterTypeSize != 0)
                    delete[] it->addInf.MethodType.parameterTypeIDs;
                if (it->addInf.MethodType.thrownTypeSize != 0)
                    delete[] it->addInf.MethodType.thrownTypeIDs;

            } else if (it->typeType == TypesForSymbolic::PARAMETRIZED_TYPE) {
                if (it->addInf.ParametrizedType.argumentTypeSize != 0)
                    delete[] it->addInf.ParametrizedType.argumentTypeIDs;

            } else if (it->typeType == TypesForSymbolic::TYPE_VARIABLE) {
                if (it->addInf.TypeVariable.boundTypeSize != 0)
                    delete[] it->addInf.TypeVariable.boundTypeIDs;
            }
        }
        TYPES.clear();

        for (ClassesType::iterator it = CLASSES.begin(); it != CLASSES.end(); ++it) {
            if (it->classType == ClassForSymbolic::CLASS) {
                if (it->addInf.Class.superInterfaceTypeSize != 0)
                    delete[] it->addInf.Class.superInterfaceTypeIDs;

            } else if (it->classType == ClassForSymbolic::CLASS_GENERIC) {
                if (it->addInf.ClassGeneric.superInterfaceTypeSize != 0)
                    delete[] it->addInf.ClassGeneric.superInterfaceTypeIDs;
                if (it->addInf.ClassGeneric.typeParameterSize != 0)
                    delete[] it->addInf.ClassGeneric.typeParameterIDs;

            } else if (it->classType == ClassForSymbolic::CLASS_GENERIC) {
                if (it->addInf.Enum.superInterfaceTypeSize != 0)
                    delete[] it->addInf.Enum.superInterfaceTypeIDs;

            } else if (it->classType == ClassForSymbolic::INTERFACE) {
                if (it->addInf.Interface.superInterfaceTypeSize != 0)
                    delete[] it->addInf.Interface.superInterfaceTypeIDs;

            } else if (it->classType == ClassForSymbolic::INTERFACE_GENERIC) {
                if (it->addInf.InterfaceGeneric.superInterfaceTypeSize != 0)
                    delete[] it->addInf.InterfaceGeneric.superInterfaceTypeIDs;
                if (it->addInf.InterfaceGeneric.typeParameterSize != 0)
                    delete[] it->addInf.InterfaceGeneric.typeParameterIDs;

            } else if (it->classType == ClassForSymbolic::ANONYMOUS_CLASS) {
            }
        }
        CLASSES.clear();

        METHODS.clear();

		SUPER_CLASSES.clear();
    }


    // Visitors
    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::ArrayType& node, bool callVirtualBase) {
        if (node.getComponentType() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::ARRAY_TYPE;
            ct.addInf.ArrayType.componentTypeId = node.getComponentType()->getId();
            ct.addInf.ArrayType.arraySize = node.getSize();
            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::ClassType& node, bool callVirtualBase) {
        if (node.getRefersTo() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::CLASS_TYPE;
            ct.addInf.ClassType.refersToId = node.getRefersTo()->getId();
            ct.addInf.ClassType.refersToName = &node.getRefersTo()->getName();
            TYPES.insert(ct);

            if (node.getRefersTo()->getBinaryName() == "java.lang.Object" && OBJECT_TYPE_ID == UINT_MAX) {
                OBJECT_TYPE_ID = node.getId();
            }

            if (node.getRefersTo()->getBinaryName() == "java.lang.String" && STRING_TYPE_ID == UINT_MAX) {
                STRING_TYPE_ID = node.getId();
            }
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::MethodType& node, bool callVirtualBase) {
        if (node.getReturnType() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::METHOD_TYPE;
            ct.addInf.MethodType.returnTypeId = node.getReturnType()->getId();

            // Iterate through parameters
            if (!node.getParameterTypesIsEmpty()) {
                std::stringstream par;
                ct.addInf.MethodType.parameterTypeSize = node.getParameterTypesSize();
                ct.addInf.MethodType.parameterTypeIDs = new columbus::NodeId[ct.addInf.MethodType.parameterTypeSize];
                unsigned int index = 0;
                for (java::asg::ListIterator<java::asg::type::Type> parIt = node.getParameterTypesListIteratorBegin(); parIt != node.getParameterTypesListIteratorEnd(); ++parIt, ++index) {
                    ct.addInf.MethodType.parameterTypeIDs[index] = parIt->getId();
                    par << parIt->getId() << ", ";
                }
            }

            // Iterate through throwns
            if (!node.getThrownTypesIsEmpty()) {
                std::stringstream thr;
                ct.addInf.MethodType.thrownTypeSize = node.getThrownTypesSize();
                ct.addInf.MethodType.thrownTypeIDs = new columbus::NodeId[ct.addInf.MethodType.thrownTypeSize];
                unsigned int index = 0;
                for (java::asg::ListIterator<java::asg::type::Type> thrIt = node.getThrownTypesListIteratorBegin(); thrIt != node.getThrownTypesListIteratorEnd(); ++thrIt, ++index) {
                    ct.addInf.MethodType.thrownTypeIDs[index] = thrIt->getId();
                    thr << thrIt->getId() << ", ";
                }
            }

            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::ParameterizedType& node, bool callVirtualBase) {
        if (node.getRawType() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::PARAMETRIZED_TYPE;
            ct.addInf.ParametrizedType.rawTypeId = node.getRawType()->getId();

            // Iterate through arguments
            if (!node.getArgumentTypesIsEmpty()) {
                std::stringstream arg;
                ct.addInf.ParametrizedType.argumentTypeSize = node.getArgumentTypesSize();
                ct.addInf.ParametrizedType.argumentTypeIDs = new columbus::NodeId[ct.addInf.ParametrizedType.argumentTypeSize];
                unsigned int index = 0;
                for (java::asg::ListIterator<java::asg::type::Type> argIt = node.getArgumentTypesListIteratorBegin(); argIt != node.getArgumentTypesListIteratorEnd(); ++argIt, ++index) {
                    ct.addInf.ParametrizedType.argumentTypeIDs[index] = argIt->getId();
                    arg << argIt->getId() << ", ";
                }
            }

            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::TypeVariable& node, bool callVirtualBase) {
        if (node.getRefersTo() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::TYPE_VARIABLE;
            ct.addInf.TypeVariable.refersToId = node.getRefersTo()->getId();

            java::asg::base::Base *typeParameterB = dynamic_cast<java::asg::base::Base*>(m_asgFactory->getPointer(ct.addInf.TypeVariable.refersToId));
            if (typeParameterB != NULL && java::asg::Common::getIsTypeParameter(*typeParameterB)) {
                java::asg::struc::TypeParameter *tp = dynamic_cast<java::asg::struc::TypeParameter*>(typeParameterB);
                if (!tp->getBoundsIsEmpty()) {
                    std::stringstream arg;
                    ct.addInf.TypeVariable.boundTypeSize = tp->getBoundsSize();
                    ct.addInf.TypeVariable.boundTypeIDs = new columbus::NodeId[ct.addInf.TypeVariable.boundTypeSize];
                    unsigned int index = 0;
                    for (java::asg::ListIterator<java::asg::expr::TypeExpression> argIt = tp->getBoundsListIteratorBegin(); argIt != tp->getBoundsListIteratorEnd(); ++argIt, ++index) {
                        if (argIt->getType() != NULL) {// FIXME
                            ct.addInf.TypeVariable.boundTypeIDs[index] = argIt->getType()->getId();
                            arg << ct.addInf.TypeVariable.boundTypeIDs[index] << ", ";
                        }
                    }
                }
            }

            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::UnboundedWildcardType& node, bool callVirtualBase) {
        if (node.getBound() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::UNBOUNDED_WILDCARD_TYPE;
            ct.addInf.UnboundedWildcardType.boundTypeId = node.getBound()->getId();
            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::UpperBoundedWildcardType& node, bool callVirtualBase) {
        if (node.getBound() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::UPPER_BOUNDED_WILDCARD_TYPE;
            ct.addInf.UpperBoundedWildcardType.boundTypeId = node.getBound()->getId();
            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::type::LowerBoundedWildcardType& node, bool callVirtualBase) {
        if (node.getBound() != NULL) {
            TypesForSymbolic ct = TypesForSymbolic();
            ct.typeId = node.getId();
            ct.typeType = TypesForSymbolic::LOWER_BOUNDED_WILDCARD_TYPE;
            ct.addInf.LowerBoundedWildcardType.boundTypeId = node.getBound()->getId();
            TYPES.insert(ct);
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::Class& node, bool callVirtualBase) {
        if (OBJECT_CLASS_ID == UINT_MAX && node.getName() == "Object") {
            OBJECT_CLASS_ID = node.getId();

        } else if (FLOAT_CLASS_ID == UINT_MAX && node.getName() == "Float") {
            FLOAT_CLASS_ID = node.getId();

        } else if (DOUBLE_CLASS_ID == UINT_MAX && node.getName() == "Double") {
            DOUBLE_CLASS_ID = node.getId();

        } else if (INTEGER_CLASS_ID == UINT_MAX && node.getName() == "Integer") {
            INTEGER_CLASS_ID = node.getId();

        } else if (BOOLEAN_CLASS_ID == UINT_MAX && node.getName() == "Boolean") {
            BOOLEAN_CLASS_ID = node.getId();

        } else if (STRING_CLASS_ID == UINT_MAX && node.getName() == "String") {
            STRING_CLASS_ID = node.getId();

        } else if (CHARACTER_CLASS_ID == UINT_MAX && node.getName() == "Character") {
            CHARACTER_CLASS_ID = node.getId();

        } else if (BYTE_CLASS_ID == UINT_MAX && node.getName() == "Byte") {
            BYTE_CLASS_ID = node.getId();

        } else if (SHORT_CLASS_ID == UINT_MAX && node.getName() == "Short") {
            SHORT_CLASS_ID = node.getId();

        } else if (LONG_CLASS_ID == UINT_MAX && node.getName() == "Long") {
            LONG_CLASS_ID = node.getId();
        }

        NodeId classId = node.getId();

        ClassForSymbolic ct = ClassForSymbolic();
        ct.classId = classId;
        ct.classType = ClassForSymbolic::CLASS;
        visitClassMembers(classId, &ct);

        // Get SuperClass
        if (node.getSuperClass() != NULL && node.getSuperClass()->getType() != NULL) {
            ct.addInf.Class.superClassTypeId = node.getSuperClass()->getType()->getId();
        }

        // Visiting superInterfaces
        if (!node.getSuperInterfacesIsEmpty()) {
            ct.addInf.Class.superInterfaceTypeSize = node.getSuperInterfacesSize();
            ct.addInf.Class.superInterfaceTypeIDs = new columbus::NodeId[ct.addInf.Class.superInterfaceTypeSize];
            std::stringstream superInterfaces;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::expr::TypeExpression> supIntIt = node.getSuperInterfacesListIteratorBegin(); supIntIt != node.getSuperInterfacesListIteratorEnd(); ++supIntIt, ++index) {
                if (supIntIt->getType() != NULL) {
                    ct.addInf.Class.superInterfaceTypeIDs[index] = supIntIt->getType()->getId();
                    superInterfaces << ct.addInf.Class.superInterfaceTypeIDs[index] << ", ";
                }
            }
        }
        CLASSES.insert(ct);

    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::ClassGeneric& node, bool callVirtualBase) {

        NodeId classId = node.getId();

        ClassForSymbolic ct = ClassForSymbolic();
        ct.classId = classId;
        ct.classType = ClassForSymbolic::CLASS_GENERIC;
        visitClassMembers(classId, &ct);

        // Get SuperClass
        if (node.getSuperClass() != NULL && node.getSuperClass()->getType() != NULL) {
            ct.addInf.ClassGeneric.superClassTypeId = node.getSuperClass()->getType()->getId();
        }

        // Visiting superInterfaces
        if (!node.getSuperInterfacesIsEmpty()) {
            ct.addInf.ClassGeneric.superInterfaceTypeSize = node.getSuperInterfacesSize();
            ct.addInf.ClassGeneric.superInterfaceTypeIDs = new columbus::NodeId[ct.addInf.ClassGeneric.superInterfaceTypeSize];
            std::stringstream superInterfaces;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::expr::TypeExpression> supIntIt = node.getSuperInterfacesListIteratorBegin(); supIntIt != node.getSuperInterfacesListIteratorEnd(); ++supIntIt, ++index) {
                if (supIntIt->getType() != NULL) {
                    ct.addInf.ClassGeneric.superInterfaceTypeIDs[index] = supIntIt->getType()->getId();
                    superInterfaces << ct.addInf.ClassGeneric.superInterfaceTypeIDs[index] << ", ";
                }
            }
        }

        // Visiting typeParameters
        if (!node.getTypeParametersIsEmpty()) {
            ct.addInf.ClassGeneric.typeParameterSize = node.getTypeParametersSize();
            ct.addInf.ClassGeneric.typeParameterIDs = new columbus::NodeId[ct.addInf.ClassGeneric.typeParameterSize];
            std::stringstream typeParameters;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::struc::TypeParameter> tpIt = node.getTypeParametersListIteratorBegin(); tpIt != node.getTypeParametersListIteratorEnd(); ++tpIt, ++index) {
                ct.addInf.ClassGeneric.typeParameterIDs[index] = tpIt->getId();
                typeParameters << ct.addInf.ClassGeneric.typeParameterIDs[index] << ", ";
            }
        }
        CLASSES.insert(ct);

    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::Interface& node, bool callVirtualBase) {

        NodeId classId = node.getId();

        ClassForSymbolic ct = ClassForSymbolic();
        ct.classId = classId;
        ct.classType = ClassForSymbolic::INTERFACE;
        visitClassMembers(classId, &ct);

        // Visiting superInterfaces
        if (!node.getSuperInterfacesIsEmpty()) {
            ct.addInf.Interface.superInterfaceTypeSize = node.getSuperInterfacesSize();
            ct.addInf.Interface.superInterfaceTypeIDs = new columbus::NodeId[ct.addInf.Interface.superInterfaceTypeSize];
            std::stringstream superInterfaces;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::expr::TypeExpression> supIntIt = node.getSuperInterfacesListIteratorBegin(); supIntIt != node.getSuperInterfacesListIteratorEnd(); ++supIntIt, ++index) {
                if (supIntIt->getType() != NULL) {
                    ct.addInf.Interface.superInterfaceTypeIDs[index] = supIntIt->getType()->getId();
                    superInterfaces << ct.addInf.Interface.superInterfaceTypeIDs[index] << ", ";
                }
            }
        }
        CLASSES.insert(ct);

    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::InterfaceGeneric& node, bool callVirtualBase) {

        NodeId classId = node.getId();

        ClassForSymbolic ct = ClassForSymbolic();
        ct.classId = classId;
        ct.classType = ClassForSymbolic::INTERFACE_GENERIC;
        visitClassMembers(classId, &ct);

        // Visiting superInterfaces
        if (!node.getSuperInterfacesIsEmpty()) {
            ct.addInf.InterfaceGeneric.superInterfaceTypeSize = node.getSuperInterfacesSize();
            ct.addInf.InterfaceGeneric.superInterfaceTypeIDs = new columbus::NodeId[ct.addInf.InterfaceGeneric.superInterfaceTypeSize];
            std::stringstream superInterfaces;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::expr::TypeExpression> supIntIt = node.getSuperInterfacesListIteratorBegin(); supIntIt != node.getSuperInterfacesListIteratorEnd(); ++supIntIt, ++index) {
                if (supIntIt->getType() != NULL) {
                    ct.addInf.InterfaceGeneric.superInterfaceTypeIDs[index] = supIntIt->getType()->getId();
                    superInterfaces << ct.addInf.InterfaceGeneric.superInterfaceTypeIDs[index] << ", ";
                }
            }
        }

        // Visiting typeParameters
        if (!node.getTypeParametersIsEmpty()) {
            ct.addInf.InterfaceGeneric.typeParameterSize = node.getTypeParametersSize();
            ct.addInf.InterfaceGeneric.typeParameterIDs = new columbus::NodeId[ct.addInf.InterfaceGeneric.typeParameterSize];
            std::stringstream typeParameters;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::struc::TypeParameter> tpIt = node.getTypeParametersListIteratorBegin(); tpIt != node.getTypeParametersListIteratorEnd(); ++tpIt, ++index) {
                ct.addInf.InterfaceGeneric.typeParameterIDs[index] = tpIt->getId();
                typeParameters << ct.addInf.InterfaceGeneric.typeParameterIDs[index] << ", ";
            }
        }
        CLASSES.insert(ct);

    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::AnonymousClass& node, bool callVirtualBase) {

        NodeId classId = node.getId();

        ClassForSymbolic ct = ClassForSymbolic();
        ct.classId = classId;
        ct.classType = ClassForSymbolic::CLASS;
        visitClassMembers(classId, &ct);

        // Get SuperClass
        if (node.getSuperClass() != NULL && node.getSuperClass()->getType() != NULL) {
            ct.addInf.Class.superClassTypeId = node.getSuperClass()->getType()->getId();
        }

        // Visiting superInterfaces
        if (!node.getSuperInterfacesIsEmpty()) {
            ct.addInf.Class.superInterfaceTypeSize = node.getSuperInterfacesSize();
            ct.addInf.Class.superInterfaceTypeIDs = new columbus::NodeId[ct.addInf.Class.superInterfaceTypeSize];
            std::stringstream superInterfaces;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::expr::TypeExpression> supIntIt = node.getSuperInterfacesListIteratorBegin(); supIntIt != node.getSuperInterfacesListIteratorEnd(); ++supIntIt, ++index) {
                if (supIntIt->getType() != NULL) {
                    ct.addInf.Class.superInterfaceTypeIDs[index] = supIntIt->getType()->getId();
                    superInterfaces << ct.addInf.Class.superInterfaceTypeIDs[index] << ", ";
                }
            }
        }
        CLASSES.insert(ct);

    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::Enum& node, bool callVirtualBase) {
        NodeId classId = node.getId();

        ClassForSymbolic ct = ClassForSymbolic();
        ct.classId = classId;
        ct.classType = ClassForSymbolic::ENUM;
        visitClassMembers(classId, &ct);

        // Get SuperClass
        if (node.getSuperClass() != NULL && node.getSuperClass()->getType() != NULL) {
            ct.addInf.Enum.superClassTypeId = node.getSuperClass()->getType()->getId();
        }

        // Visiting superInterfaces
        if (!node.getSuperInterfacesIsEmpty()) {
            ct.addInf.Enum.superInterfaceTypeSize = node.getSuperInterfacesSize();
            ct.addInf.Enum.superInterfaceTypeIDs = new columbus::NodeId[ct.addInf.Enum.superInterfaceTypeSize];
            std::stringstream superInterfaces;
            unsigned int index = 0;
            for (java::asg::ListIterator<java::asg::expr::TypeExpression> supIntIt = node.getSuperInterfacesListIteratorBegin(); supIntIt != node.getSuperInterfacesListIteratorEnd(); ++supIntIt, ++index) {
                if (supIntIt->getType() != NULL) {
                    ct.addInf.Enum.superInterfaceTypeIDs[index] = supIntIt->getType()->getId();
                    superInterfaces << ct.addInf.Enum.superInterfaceTypeIDs[index] << ", ";
                }
            }
        }
        CLASSES.insert(ct);
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::Variable& node, bool callVirtualBase) {
        if (node.getName() == "POSITIVE_INFINITY" && node.getParent() != NULL) {
            if (FLOAT_CLASS_ID != UINT_MAX && FLOAT_CLASS_ID == node.getParent()->getId()) {
                FLOAT_POSITIVE_INFINITY = node.getId();

            } else if (DOUBLE_CLASS_ID != UINT_MAX && DOUBLE_CLASS_ID == node.getParent()->getId()) {
                DOUBLE_POSITIVE_INFINITY = node.getId();

            } else {
                columbus::java::asg::struc::Class *parentClass = dynamic_cast<columbus::java::asg::struc::Class*>(node.getParent());
                if (parentClass != NULL) {
                    if (parentClass->getName() == "Float") {
                        FLOAT_CLASS_ID = parentClass->getId();
                        FLOAT_POSITIVE_INFINITY = node.getId();

                    } else if (parentClass->getName() == "Double") {
                        DOUBLE_CLASS_ID = parentClass->getId();
                        DOUBLE_POSITIVE_INFINITY = node.getId();
                    }
                }
            }
        } else if (node.getName() == "NEGATIVE_INFINITY" && node.getParent() != NULL) {
            if (FLOAT_CLASS_ID != UINT_MAX && FLOAT_CLASS_ID == node.getParent()->getId()) {
                FLOAT_NEGATIVE_INFINITY = node.getId();

            } else if (DOUBLE_CLASS_ID != UINT_MAX && DOUBLE_CLASS_ID == node.getParent()->getId()) {
                DOUBLE_NEGATIVE_INFINITY = node.getId();

            } else {
                columbus::java::asg::struc::Class *parentClass = dynamic_cast<columbus::java::asg::struc::Class*>(node.getParent());
                if (parentClass != NULL) {
                    if (parentClass->getName() == "Float") {
                        FLOAT_CLASS_ID = parentClass->getId();
                        FLOAT_NEGATIVE_INFINITY = node.getId();

                    } else if (parentClass->getName() == "Double") {
                        DOUBLE_CLASS_ID = parentClass->getId();
                        DOUBLE_NEGATIVE_INFINITY = node.getId();
                    }
                }
            }
        } else if (node.getName() == "NaN" && node.getParent() != NULL) {
            if (FLOAT_CLASS_ID != UINT_MAX && FLOAT_CLASS_ID == node.getParent()->getId()) {
                FLOAT_NAN = node.getId();

            } else if (DOUBLE_CLASS_ID != UINT_MAX && DOUBLE_CLASS_ID == node.getParent()->getId()) {
                DOUBLE_NAN = node.getId();

            } else {
                columbus::java::asg::struc::Class *parentClass = dynamic_cast<columbus::java::asg::struc::Class*>(node.getParent());
                if (parentClass != NULL) {
                    if (parentClass->getName() == "Float") {
                        FLOAT_CLASS_ID = parentClass->getId();
                        FLOAT_NAN = node.getId();

                    } else if (parentClass->getName() == "Double") {
                        DOUBLE_CLASS_ID = parentClass->getId();
                        DOUBLE_NAN = node.getId();
                    }
                }
            }
        }
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::Method& node, bool callVirtualBase) {
        visitMethods(node.getId());
    }

    void SymbolicTypesPreVisitor::visit(const columbus::java::asg::struc::MethodGeneric& node, bool callVirtualBase) {
        visitMethods(node.getId());
    }

    void SymbolicTypesPreVisitor::visitMethods(columbus::NodeId methodId) {
        java::asg::struc::NormalMethod& node = dynamic_cast<java::asg::struc::NormalMethod&>(m_asgFactory->getRef(methodId));
        if (m_asgFactory->getIsFiltered(&node)) {

        } else {
            columbus::java::asg::struc::Class *ct = dynamic_cast<columbus::java::asg::struc::Class *>(node.getParent());
            NodeId parentId = 0;
            if (ct != NULL) {
                parentId = ct->getId();

            } else {
                columbus::java::asg::struc::Interface *interf = dynamic_cast<columbus::java::asg::struc::Interface *>(node.getParent());
                if (interf != NULL) {
                    parentId = interf->getId();

                } else  {
                    columbus::java::asg::struc::InterfaceGeneric *interfg = dynamic_cast<columbus::java::asg::struc::InterfaceGeneric *>(node.getParent());
                    if (interfg != NULL) {
                        parentId = interfg->getId();

                    } else {
                        columbus::java::asg::struc::ClassGeneric *ctg = dynamic_cast<columbus::java::asg::struc::ClassGeneric *>(node.getParent());
                        if (ctg != NULL) {
                            parentId = ctg->getId();

                        } else {
                            columbus::java::asg::struc::AnonymousClass *ac = dynamic_cast<columbus::java::asg::struc::AnonymousClass *>(node.getParent());
                            if (ac != NULL) {
                                parentId = ac->getId();

                            } else {
                                columbus::java::asg::struc::Enum *ec = dynamic_cast<columbus::java::asg::struc::Enum *>(node.getParent());
                                if (ec != NULL) {
                                    parentId = ec->getId();
                                }
                            }
                        }
                    }
                }
            }
            if (parentId != 0) {
                MethodForSymbolic mt = MethodForSymbolic();
                mt.methodId = methodId;
                mt.classId = parentId;
                if (node.getMethodType() != NULL) {
                    mt.methodTypeID = node.getMethodType()->getId();
                }
                const java::asg::struc::MethodDeclaration& md = dynamic_cast<const java::asg::struc::MethodDeclaration&>(node);
                if (md.getReturnType() != NULL && md.getReturnType()->getType() != NULL) {
                    mt.returnTypeID = md.getReturnType()->getType()->getId();
                }

                // Visiting overrided methods
                std::vector<NodeId> overridesMethodIDsVector;
                if (!md.getOverridesIsEmpty()) {
                    std::stringstream overrided;
                    for (java::asg::ListIterator<java::asg::struc::MethodDeclaration> overIt = md.getOverridesListIteratorBegin(); overIt != md.getOverridesListIteratorEnd(); ++overIt) {
                        overridesMethodIDsVector.push_back(overIt->getId());
                        overrided << overIt->getId() << ", ";
                    }
                }
                mt.overridesMethodIDs = overridesMethodIDsVector;

                // Visiting parameters
                std::vector<NodeId> parameterIDsVector;
                if (!node.getParametersIsEmpty()) {
                    std::stringstream params;
                    for (java::asg::ListIterator<java::asg::struc::Parameter> paramIt = node.getParametersListIteratorBegin(); paramIt != node.getParametersListIteratorEnd(); ++paramIt) {
                        if (paramIt->getType() != NULL && paramIt->getType()->getType() != NULL) {
                            parameterIDsVector.push_back(paramIt->getType()->getType()->getId());
                            params << paramIt->getType()->getType()->getId() << ", ";
                        }
                    }
                }
                mt.parameterIDs = parameterIDsVector;

                // Visiting thrown types
                std::vector<NodeId> thrownTypeIDsVector;
                if (!node.getThrownExceptionsIsEmpty()) {
                    std::stringstream throws;
                    for (java::asg::ListIterator<java::asg::expr::TypeExpression> trIt = node.getThrownExceptionsListIteratorBegin(); trIt != node.getThrownExceptionsListIteratorEnd(); ++trIt) {
                        thrownTypeIDsVector.push_back(trIt->getId());
                        throws << trIt->getId() << ", ";
                    }
                }
                mt.thrownTypeIDs = thrownTypeIDsVector;

                if (java::asg::Common::getIsMethodGeneric(node)) {
                    mt.methodType = MethodForSymbolic::METHOD_GENERIC;
                    const java::asg::struc::MethodGeneric& mg = dynamic_cast<const java::asg::struc::MethodGeneric&>(node);

                    // Visiting typeParameters
                    std::vector<NodeId> typeParameterIDsVector;
                    if (!mg.getTypeParametersIsEmpty()) {
                        std::stringstream typeParams;
                        for (java::asg::ListIterator<java::asg::struc::TypeParameter> tpIt = mg.getTypeParametersListIteratorBegin(); tpIt != mg.getTypeParametersListIteratorEnd(); ++tpIt) {
                            typeParameterIDsVector.push_back(tpIt->getId());
                            typeParams << tpIt->getId() << ", ";
                        }
                    }
                    mt.typeParameterIDs = typeParameterIDsVector;

                } else {
                    mt.methodType = MethodForSymbolic::METHOD;
                }

                METHODS.insert(mt);

			} else {
			}
        }
    }

    void SymbolicTypesPreVisitor::visitClassMembers(NodeId classId, ClassForSymbolic *ct) {
        java::asg::base::Base& clazz = m_asgFactory->getRef(classId);
        if (java::asg::Common::getIsClassDeclaration(clazz)) {
            java::asg::struc::ClassDeclaration& cd = dynamic_cast<java::asg::struc::ClassDeclaration&>(clazz);

            // Visiting method members
            std::vector<NodeId> memberMethodIDsVector;
            if (!cd.getMembersIsEmpty()) {
                std::stringstream methods;
                for (java::asg::ListIterator<java::asg::struc::Member> memIt = cd.getMembersListIteratorBegin(); memIt != cd.getMembersListIteratorEnd(); ++memIt) {
                    if (java::asg::Common::getIsNormalMethod(*memIt)) {
                        java::asg::struc::NormalMethod& md = dynamic_cast<java::asg::struc::NormalMethod&>(m_asgFactory->getRef(memIt->getId()));
                        if (md.getMethodKind() != columbus::java::asg::mekNormal) {
                        } else {
                            memberMethodIDsVector.push_back(memIt->getId());
                            methods << memIt->getId() << ", ";
                        }
                    }
                }
            }
            ct->memberMethodIDs = memberMethodIDsVector;

        } else if (java::asg::Common::getIsInterfaceDeclaration(clazz)) {
            java::asg::struc::InterfaceDeclaration& cd = dynamic_cast<java::asg::struc::InterfaceDeclaration&>(clazz);

            // Visiting method members
            std::vector<NodeId> memberMethodIDsVector;
            if (!cd.getMembersIsEmpty()) {
                std::stringstream methods;
                for (java::asg::ListIterator<java::asg::struc::Member> memIt = cd.getMembersListIteratorBegin(); memIt != cd.getMembersListIteratorEnd(); ++memIt) {
                    if (java::asg::Common::getIsNormalMethod(*memIt)) {
                        java::asg::struc::NormalMethod& md = dynamic_cast<java::asg::struc::NormalMethod&>(m_asgFactory->getRef(memIt->getId()));
                        if (md.getMethodKind() != columbus::java::asg::mekNormal) {
                        } else {
                            memberMethodIDsVector.push_back(memIt->getId());
                            methods << memIt->getId() << ", ";
                        }
                    }
                }
            }
            ct->memberMethodIDs = memberMethodIDsVector;
        }
    }

    void SymbolicTypesPreVisitor::finishVisit() {
        for (MethodType::iterator it = METHODS.begin(); it != METHODS.end(); ++it) {
            calculateOverrides(*it, it->methodId);
        }

        if (common::WriteMsg::getMessageLevel() >= common::WriteMsg::mlDDebug) {
            for (MethodType::iterator it = METHODS.begin(); it != METHODS.end(); ++it) {
                if (!it->overridedByMethodIDs.empty()) {
                    std::stringstream overridedBys;
                    for (std::vector<NodeId>::const_iterator oit = it->overridedByMethodIDs.begin(); oit != it->overridedByMethodIDs.end(); ++oit) {
                        overridedBys << *oit << ", ";
                    }
                }
            }
        }
    }

    // Getters
    const SymbolicTypesPreVisitor::MethodForSymbolic SymbolicTypesPreVisitor::getOverridedBy(NodeId methodId) {
        MethodForSymbolic newMethod = MethodForSymbolic();
        newMethod.methodId = methodId;
        MethodType::const_iterator found = METHODS.find(newMethod);
        if (found != METHODS.end()) {
            newMethod = *found;
        } else {
            newMethod.methodId = 0;
        }
        return newMethod;
    }

    columbus::NodeId SymbolicTypesPreVisitor::getSuperClassId(const columbus::NodeId methodId) {
        java::asg::base::Base *base = m_asgFactory->getPointer(methodId);
        while (base != NULL) {
            if (java::asg::Common::getIsMethod(*base) || java::asg::Common::getIsNormalMethod(*base) || java::asg::Common::getIsMethodGeneric(*base))
                break;
            base = base->getParent();
        }

        if (base == NULL)
            return 0;

        MethodForSymbolic newMethod = MethodForSymbolic();
        newMethod.methodId = base->getId();

        MethodType::const_iterator found = METHODS.find(newMethod);
        if (found != METHODS.end()) {

            ClassForSymbolic superClass = ClassForSymbolic();
            superClass.classId = found->classId;
            ClassesType::const_iterator foundClass = CLASSES.find(superClass);
            if (foundClass != CLASSES.end()) {

                NodeId superClassTypeId = 0;
                if (foundClass->classType == ClassForSymbolic::CLASS) {
                    superClassTypeId = foundClass->addInf.Class.superClassTypeId;

                } else if (foundClass->classType == ClassForSymbolic::CLASS_GENERIC) {
                    superClassTypeId = foundClass->addInf.ClassGeneric.superClassTypeId;

                } else if (foundClass->classType == ClassForSymbolic::ENUM) {
                    superClassTypeId = foundClass->addInf.Enum.superClassTypeId;

                } else {
                    return 0;
                }

                TypesForSymbolic st = getType(superClassTypeId);
                if (st.typeId != 0) {
                    if (st.typeType == TypesForSymbolic::CLASS_TYPE) {
                        return st.addInf.ClassType.refersToId;

                    } else if (st.typeType == TypesForSymbolic::PARAMETRIZED_TYPE) {
                        do {
                            st = getType(st.addInf.ParametrizedType.rawTypeId);
                        } while (st.typeType == TypesForSymbolic::PARAMETRIZED_TYPE && st.typeId != 0);

                        return st.addInf.ClassType.refersToId;
                    }

                } else {
                    if (superClassTypeId == getErrorTypeId()) {
                        return superClassTypeId;
                    } else
                        return 0;
                }

            } else {
                return 0;
            }

        }
        return 0;
    }

    SymbolicTypesPreVisitor::TypesForSymbolic SymbolicTypesPreVisitor::getType(const NodeId typeId) {
        TypesForSymbolic ret = TypesForSymbolic();
        ret.typeId = typeId;
        TypesType::const_iterator it = TYPES.find(ret);
        if (it != TYPES.end())
            return *it;

        ret.typeId = 0;
        return ret;
    }

    NodeId SymbolicTypesPreVisitor::getClassType(const NodeId refersToId) {
        for (TypesType::const_iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::CLASS_TYPE && it->addInf.ClassType.refersToId == refersToId)
                return it->typeId;
        }
        return 0;
    }

    NodeId SymbolicTypesPreVisitor::getClassType(const string& refersToName) {
        for (TypesType::const_iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::CLASS_TYPE && *it->addInf.ClassType.refersToName == refersToName)
                return it->typeId;
        }
        throw SymbolicColumbusException("Type not found: " + refersToName);
    }


    NodeId SymbolicTypesPreVisitor::getClassId(const NodeId classTypeId) {
        NodeId result = 0;
        TypesForSymbolic ret = TypesForSymbolic();
        ret.typeId = classTypeId;
        TypesType::const_iterator found = TYPES.find(ret);
        if (found != TYPES.end()) {
            if (found->typeType == TypesForSymbolic::CLASS_TYPE) {
                result = found->addInf.ClassType.refersToId;
            }
        }
        return result;
    }

    std::set<NodeId> SymbolicTypesPreVisitor::getSuperClassTypeIDs(const NodeId forClassId) {
        std::set<NodeId> result;
        if (forClassId == BOOLEAN_TYPE_ID) {
            result.insert(BOOLEAN_TYPE_ID);
            return result;

        } else if (forClassId == NULL_TYPE_ID) {
            result.insert(NULL_TYPE_ID);
            return result;

        } else if (forClassId == VOID_TYPE_ID) {
            result.insert(VOID_TYPE_ID);
            return result;

        } else if (isPrimitiveType(forClassId)) {
            result.insert(BYTE_TYPE_ID);
            result.insert(CHAR_TYPE_ID);
            result.insert(SHORT_TYPE_ID);
            result.insert(INT_TYPE_ID);
            result.insert(LONG_TYPE_ID);
            result.insert(FLOAT_TYPE_ID);
            result.insert(DOUBLE_TYPE_ID);
            return result;
        }

        for (ClassesType::const_iterator it = CLASSES.begin(); it != CLASSES.end(); ++it) {
            if (it->classId == forClassId) {
                if (it->classType == ClassForSymbolic::CLASS) {
                    result.insert(it->addInf.Class.superClassTypeId);
                    for (unsigned int i = 0; i < it->addInf.Class.superInterfaceTypeSize; ++i)
                        result.insert(it->addInf.Class.superInterfaceTypeIDs[i]);

                } else if (it->classType == ClassForSymbolic::CLASS_GENERIC) {
                    result.insert(it->addInf.ClassGeneric.superClassTypeId);
                    for (unsigned int i = 0; i < it->addInf.ClassGeneric.superInterfaceTypeSize; ++i)
                        result.insert(it->addInf.ClassGeneric.superInterfaceTypeIDs[i]);

                } else if (it->classType == ClassForSymbolic::INTERFACE) {
                    for (unsigned int i = 0; i < it->addInf.Interface.superInterfaceTypeSize; ++i)
                        result.insert(it->addInf.Interface.superInterfaceTypeIDs[i]);

                } else if (it->classType == ClassForSymbolic::INTERFACE_GENERIC) {
                    for (unsigned int i = 0; i < it->addInf.InterfaceGeneric.superInterfaceTypeSize; ++i)
                        result.insert(it->addInf.InterfaceGeneric.superInterfaceTypeIDs[i]);

                } else if (it->classType == ClassForSymbolic::ANONYMOUS_CLASS) {

                }
                break;
            }
        }
        return result;
    }

    std::set<NodeId> SymbolicTypesPreVisitor::getSuperClassTypeIDsForTypeId(const NodeId typeId) {
        std::set<NodeId> result;
        TypesForSymbolic t = getType(typeId);
        if (t.typeId != 0) {
            if (t.typeId == TypesForSymbolic::CLASS_TYPE) {
                result = getSuperClassTypeIDs(t.addInf.ClassType.refersToId);
                std::set<NodeId> temp;
                for (std::set<NodeId>::const_iterator it = result.begin(); it != result.end(); ++it) {
                    std::set<NodeId> temp2 = getSuperClassTypeIDsForTypeId(*it);
                    temp.insert(temp2.begin(), temp2.end());
                }
                result.insert(temp.begin(), temp.end());
            }
        }
        return result;
    }

    NodeId SymbolicTypesPreVisitor::getTypeVariable(const NodeId refersToId) {
        for (TypesType::const_iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::TYPE_VARIABLE && it->addInf.TypeVariable.refersToId == refersToId)
                return it->typeId;
        }
        return 0;
    }

    NodeId SymbolicTypesPreVisitor::getUnboundedWildCardType(const NodeId boundTypeId) {
        for (TypesType::const_iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::UNBOUNDED_WILDCARD_TYPE && it->addInf.UnboundedWildcardType.boundTypeId == boundTypeId)
                return it->typeId;
        }
        return 0;
    }

    NodeId SymbolicTypesPreVisitor::getUpperBoundedWildCardType(const NodeId boundTypeId) {
        for (TypesType::const_iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::UPPER_BOUNDED_WILDCARD_TYPE && it->addInf.UpperBoundedWildcardType.boundTypeId == boundTypeId)
                return it->typeId;
        }
        return 0;
    }

    NodeId SymbolicTypesPreVisitor::getLowerBoundedWildCardType(const NodeId boundTypeId) {
        for (TypesType::const_iterator it = TYPES.begin(); it != TYPES.end(); ++it) {
            if (it->typeType == TypesForSymbolic::LOWER_BOUNDED_WILDCARD_TYPE && it->addInf.LowerBoundedWildcardType.boundTypeId == boundTypeId)
                return it->typeId;
        }
        return 0;
    }

    void SymbolicTypesPreVisitor::calculateOverrides(const SymbolicTypesPreVisitor::MethodForSymbolic& mt, NodeId methodId) {
        for (std::vector<NodeId>::const_iterator oit = mt.overridesMethodIDs.begin(); oit != mt.overridesMethodIDs.end(); ++oit) {
            if (*oit == methodId)
                continue;
            MethodForSymbolic newMethod;
            newMethod.methodId = *oit;
            MethodType::iterator found = METHODS.find(newMethod);
            if (found != METHODS.end()) {
                newMethod = *found;
                METHODS.erase(newMethod);
                newMethod.overridedByMethodIDs.push_back(methodId);
                METHODS.insert(newMethod);
                calculateOverrides(newMethod, methodId);
            }
        }
    }

    NodeId SymbolicTypesPreVisitor::mapPrimitiveTypeToBoxingType(const NodeId primitiveType) {
        NodeId result = 0;
        if (primitiveType == BOOLEAN_TYPE_ID)
            result = BOOLEAN_CLASS_ID;

        else if (primitiveType == BYTE_TYPE_ID)
            result = BYTE_CLASS_ID;

        else if (primitiveType == CHAR_TYPE_ID)
            result = CHARACTER_CLASS_ID;

        else if (primitiveType == SHORT_TYPE_ID)
            result = SHORT_CLASS_ID;

        else if (primitiveType == INT_TYPE_ID)
            result = INTEGER_CLASS_ID;

        else if (primitiveType == LONG_TYPE_ID)
            result = LONG_CLASS_ID;

        else if (primitiveType == FLOAT_TYPE_ID)
            result = FLOAT_CLASS_ID;

        else if (primitiveType == DOUBLE_TYPE_ID)
            result = DOUBLE_CLASS_ID;

        result = getClassType(result);
        return result;
    }

    bool SymbolicTypesPreVisitor::isBoxing(const NodeId classTypeId, const NodeId initValueTypeId, NodeId& toTypeId) {
        bool result = false;

        toTypeId = classTypeId;
        NodeId classId = getClassId(classTypeId);
        if (classId == getIntegerClassId() && initValueTypeId == getIntTypeId()) {
            result = true;

        } else if (classId == getBooleanClassId() && initValueTypeId == getBooleanTypeId()) {
            result = true;

        } else if (classId == getDoubleClassId() && initValueTypeId == getDoubleTypeId()) {
            result = true;

        }  else if (classId == getFloatClassId() && initValueTypeId == getFloatTypeId()) {
            result = true;

        } else if (classId == getCharacterClassId() && initValueTypeId == getCharTypeId()) {
            result = true;

        } else if (classId == getLongClassId() && initValueTypeId == getLongTypeId()) {
            result = true;

        } else if (classId == getShortClassId() && initValueTypeId == getShortTypeId()) {
            result = true;

        } else if (classId == getByteClassId() && initValueTypeId == getByteTypeId()) {
            result = true;

        } else if (classId == getObjectClassId() && (
                    initValueTypeId == getBooleanTypeId() || initValueTypeId == getIntTypeId() ||
                    initValueTypeId == getDoubleTypeId() || initValueTypeId == getCharTypeId() ||
                    initValueTypeId == getLongTypeId() || initValueTypeId == getShortTypeId() ||
                    initValueTypeId == getByteTypeId() || initValueTypeId == getFloatTypeId())) {
            toTypeId = mapPrimitiveTypeToBoxingType(initValueTypeId);
            result = true;
        }

        return result;
    }

    bool SymbolicTypesPreVisitor::isBoxingType(const NodeId typeId) {
        TypesForSymbolic ret = getType(typeId);
        if (ret.typeType == TypesForSymbolic::CLASS_TYPE) {
            if (ret.addInf.ClassType.refersToId == FLOAT_CLASS_ID || ret.addInf.ClassType.refersToId == DOUBLE_CLASS_ID ||
                ret.addInf.ClassType.refersToId == BYTE_CLASS_ID || ret.addInf.ClassType.refersToId == BOOLEAN_CLASS_ID ||
                ret.addInf.ClassType.refersToId == SHORT_CLASS_ID || ret.addInf.ClassType.refersToId == CHARACTER_CLASS_ID ||
                ret.addInf.ClassType.refersToId == INTEGER_CLASS_ID || ret.addInf.ClassType.refersToId == LONG_CLASS_ID) {
                return true;
            }
        }
        return false;
    }

    bool SymbolicTypesPreVisitor::isPrimitiveType(const NodeId typeId) {
        if (typeId == VOID_TYPE_ID || typeId == CHAR_TYPE_ID || typeId == BYTE_TYPE_ID || typeId == SHORT_TYPE_ID || typeId == INT_TYPE_ID || typeId == LONG_TYPE_ID ||
            typeId == FLOAT_TYPE_ID || typeId == DOUBLE_TYPE_ID || typeId == BOOLEAN_TYPE_ID || typeId == NULL_TYPE_ID) { // TODO: a null primitív typus??? quickfix: isPrimitiveTypeExcpetNull
            return true;
        }
        return false;
    }

    bool SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(const NodeId typeId) {
    	if (typeId == VOID_TYPE_ID || typeId == CHAR_TYPE_ID || typeId == BYTE_TYPE_ID || typeId == SHORT_TYPE_ID || typeId == INT_TYPE_ID || typeId == LONG_TYPE_ID ||
    			typeId == FLOAT_TYPE_ID || typeId == DOUBLE_TYPE_ID || typeId == BOOLEAN_TYPE_ID) {
    		return true;
    	}
    	return false;
    }

    bool SymbolicTypesPreVisitor::isPrimitiveNumericType(const NodeId typeId) {
        if (typeId == CHAR_TYPE_ID || typeId == BYTE_TYPE_ID || typeId == SHORT_TYPE_ID || typeId == INT_TYPE_ID || typeId == LONG_TYPE_ID)
            return true;
        return false;
    }

    bool SymbolicTypesPreVisitor::isReferenceType(const NodeId typeId) {
        // Find the typeId in the TYPES
        TypesForSymbolic t = TypesForSymbolic();
        t.typeId = typeId;
        TypesType::const_iterator found = TYPES.find(t);
        if (found != TYPES.end()) {
            if (found->typeType == TypesForSymbolic::CLASS_TYPE || found->typeType == TypesForSymbolic::ARRAY_TYPE)
                return true;
        }
        return false;
    }

    bool SymbolicTypesPreVisitor::isClassType(const columbus::NodeId typeId) {
        return getClassId(typeId) != 0;
    }

    std::set<NodeId> SymbolicTypesPreVisitor::getSubTypes(const NodeId typeId) {
        std::set<NodeId> result;
        //TypesForSymbolic t = getType(typeId);
        return result;
    }

    std::set<NodeId> SymbolicTypesPreVisitor::getSuperTypes(const NodeId typeId) {
        std::set<NodeId> result;

        if (isPrimitiveType(typeId)) {
            std::set<NodeId> sts = getSuperClassTypeIDs(typeId);
            result.insert(sts.begin(), sts.end());
            return result;
        }

        TypesForSymbolic t = getType(typeId);
        if (t.typeId != 0) {
            bool isUnhandled = false;
            NodeId superId = 0;
            if (t.typeType == TypesForSymbolic::CLASS_TYPE) {
                superId = t.addInf.ClassType.refersToId;

            } else if (t.typeType == TypesForSymbolic::PARAMETRIZED_TYPE) {
                superId = t.addInf.ParametrizedType.rawTypeId;

            } else if (t.typeType == TypesForSymbolic::ARRAY_TYPE) {
                superId = t.addInf.ArrayType.componentTypeId;

            } else if (t.typeType == TypesForSymbolic::TYPE_VARIABLE) {
                if (t.addInf.TypeVariable.boundTypeSize > 0)
                    superId = t.addInf.TypeVariable.boundTypeIDs[0];

            } else {
                isUnhandled = true;
            }

            if (isUnhandled) {
                std::cout << "getSuperTypes: Unhandled TYPE_TYPE: " << t.typeType << std::endl;

            } else {
                std::set<NodeId> sts = getSuperClassTypeIDs(superId);
                result.insert(sts.begin(), sts.end());
                for (std::set<NodeId>::const_iterator it = sts.begin(); it != sts.end(); ++it) {
                    std::set<NodeId> temp = getSuperTypes(*it);
                    result.insert(temp.begin(), temp.end());
                }
            }
        }
        return result;
    }

    bool SymbolicTypesPreVisitor::isSubType(const NodeId subTypeId, const NodeId superTypeId) {
        std::set<NodeId> subTypes = getSubTypes(superTypeId);
        if (subTypes.find(subTypeId) != subTypes.end())
            return true;
        return false;

    }

    bool SymbolicTypesPreVisitor::isSuperType(const NodeId superTypeId, const NodeId subTypeId) {
        std::set<NodeId> superTypes = getSuperTypes(subTypeId);
        if (superTypes.find(superTypeId) != superTypes.end())
            return true;
        return false;
    }

    bool SymbolicTypesPreVisitor::isCastable(const NodeId sourceTypeId, const NodeId targetTypeId) {
        // sourceTypeId castable to targetTypeId (sourceTypeId instanceOf targetTypeId)

        if (sourceTypeId == targetTypeId)
            return true;

        // TODO: generic types
        TypesForSymbolic source = getType(sourceTypeId);
        TypesForSymbolic target = getType(targetTypeId);

        // Casting to Object
        if (target.typeType == TypesForSymbolic::CLASS_TYPE && target.addInf.ClassType.refersToId == OBJECT_CLASS_ID)
            return true;

        // Casting Object -> Object[]
        if (source.typeType == TypesForSymbolic::CLASS_TYPE && OBJECT_CLASS_ID == source.addInf.ClassType.refersToId &&
            target.typeType == TypesForSymbolic::ARRAY_TYPE && target.addInf.ArrayType.componentTypeId == source.typeId)
            return true;

        // Check for Boxing conversion
        if (isPrimitiveType(sourceTypeId) && sourceTypeId != VOID_TYPE_ID && target.typeId != 0 &&
            target.typeType == TypesForSymbolic::CLASS_TYPE &&
            (target.addInf.ClassType.refersToId == OBJECT_CLASS_ID || target.addInf.ClassType.refersToId == mapPrimitiveTypeToBoxingType(sourceTypeId))) {
            return true;
        }

        if (source.typeId == 0 || target.typeId == 0)
            return false;

        else {
            if ((source.typeType == TypesForSymbolic::ARRAY_TYPE && target.typeType != TypesForSymbolic::ARRAY_TYPE) ||
                (source.typeType != TypesForSymbolic::ARRAY_TYPE && target.typeType == TypesForSymbolic::ARRAY_TYPE)) {
                return false;
            }

            NodeId sourceTId = 0;
            NodeId targetTId = 0;
            unsigned int ass = 0;
            unsigned int ats = 0;
            switch (source.typeType) {
                case TypesForSymbolic::CLASS_TYPE:
                    sourceTId = sourceTypeId;
                    break;
                case TypesForSymbolic::ARRAY_TYPE: {
                    sourceTId = source.addInf.ArrayType.componentTypeId;
                    ass = source.addInf.ArrayType.arraySize;
                    TypesForSymbolic acompType = getType(sourceTId);
                    if (acompType.typeType == TypesForSymbolic::TYPE_VARIABLE) {
                        if (acompType.addInf.TypeVariable.boundTypeSize > 0)
                            sourceTId = acompType.addInf.TypeVariable.boundTypeIDs[0];
                    }
                    break;
                }
                case TypesForSymbolic::PARAMETRIZED_TYPE:
                    sourceTId = source.addInf.ParametrizedType.rawTypeId;
                    break;
                case TypesForSymbolic::TYPE_VARIABLE:
                    if (target.addInf.TypeVariable.boundTypeSize > 0)
                        targetTId = target.addInf.TypeVariable.boundTypeIDs[0];
                    break;
                default:
                    break;
            }

            switch (target.typeType) {
                case TypesForSymbolic::CLASS_TYPE:
                    targetTId = targetTypeId;
                    break;
                case TypesForSymbolic::ARRAY_TYPE: {
                    targetTId = target.addInf.ArrayType.componentTypeId;
                    ats = target.addInf.ArrayType.arraySize;
                    TypesForSymbolic acompType = getType(targetTId);
                    if (acompType.typeType == TypesForSymbolic::TYPE_VARIABLE) {
                        if (acompType.addInf.TypeVariable.boundTypeSize > 0)
                            targetTId = acompType.addInf.TypeVariable.boundTypeIDs[0];
                    }
                    break;
                }
                case TypesForSymbolic::PARAMETRIZED_TYPE:
                    targetTId = target.addInf.ParametrizedType.rawTypeId;
                    break;
                case TypesForSymbolic::TYPE_VARIABLE:
                    if (target.addInf.TypeVariable.boundTypeSize > 0)
                        targetTId = target.addInf.TypeVariable.boundTypeIDs[0];
                    break;
                default:
                    break;
            }

            if (sourceTId == targetTId)
                return true;

            if (ass != ats)
                return false;

            NodeId stringTypeId = getClassType(getStringClassId());
            if (targetTId == stringTypeId && isBoxingType(sourceTId))
                return true;

            std::set<NodeId> sts = getSuperTypes(sourceTId);
            if (sts.find(targetTId) != sts.end())
                return true;
            else
                return false;
        }

        return false;
    }

    unsigned SymbolicTypesPreVisitor::typePromotionPrecedence(NodeId type) {
        if (type == BYTE_TYPE_ID) {
            return 1;
        } else if (type == CHAR_TYPE_ID) {
            return 2;
        } else if (type == SHORT_TYPE_ID) {
            return 3;
        } else if (type == INT_TYPE_ID) {
            return 4;
        } else if (type == LONG_TYPE_ID) {
            return 5;
        } else if (type == FLOAT_TYPE_ID) {
            return 6;
        } else if (type == DOUBLE_TYPE_ID) {
            return 7;
        } else {
            throw SymbolicColumbusException("typePromotionPrecedence: Cannot determine promotion precedence!");
        }
    }

    /*
     * Here are the Type Promotion Rules:
     *
     * All byte and short values are promoted to int.
     * If one operand is a long, the whole expression is promoted to long.
     * If one operand is a float, the entire expression is promoted to float.
     * If any of the operands is double, the result is double.
     */
    columbus::NodeId SymbolicTypesPreVisitor::getResultType(NodeId type1, NodeId type2) {
        try {
            if (type1 == BOOLEAN_TYPE_ID || type2 == BOOLEAN_TYPE_ID) {
                return type1;
            }
            else if (typePromotionPrecedence(type1) <= typePromotionPrecedence(INT_TYPE_ID) && typePromotionPrecedence(type1) <= typePromotionPrecedence(INT_TYPE_ID)) {
                return INT_TYPE_ID;
            }
            else if (typePromotionPrecedence(type1) >= typePromotionPrecedence(type2)) {
                return type1;
            }
            else if (typePromotionPrecedence(type1) < typePromotionPrecedence(type2)) {
                return type2;
            }
        }
        catch (const SymbolicColumbusException& e) {
            if (type1 == type2) {
                return type1;
            }
        }
        
        throw SymbolicColumbusException("getResultType: Result type cannot be determined!");
    }
}}
