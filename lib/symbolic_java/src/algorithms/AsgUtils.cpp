#include "../../inc/common.h"
#include <stack>

using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

//NodeId AsgUtils::getReturnType(const Factory& factory, const expr::MethodInvocation& methodInvoke, SmartDefinition thizObject) {
//    struc::MethodDeclaration* methodDecl = methodInvoke.getInvokes();
//    expr::TypeExpression* returnTypeExpr = methodDecl->getReturnType();
//    type::Type* returnType=returnTypeExpr->getType();
//    if (Common::getIsTypeVariable(*returnType)) {
//        // Method returns a type parameter, we have to find out the concrete type argument
//
//        // get the name of the formal type parameter
//        const string& typeParamName = dynamic_cast<type::TypeVariable&>(*returnType).getRefersTo()->getName();
//
//        bool typeParamNameFound = false;
//        if (Common::getIsMethodGeneric(*methodDecl)) {
//            // generic method and its return type is one of its type parameters
//            struc::MethodGeneric& genericMethod = dynamic_cast<struc::MethodGeneric&>(*methodDecl);
//            int posOfParam = 0;
//            for (ListIterator<struc::TypeParameter> it = genericMethod.getTypeParametersListIteratorBegin(); it != genericMethod.getTypeParametersListIteratorEnd(); ++it, ++posOfParam) {
//                if (it->getName().compare(typeParamName) == 0) {
//                    typeParamNameFound = true;
//                    break;
//                }
//            }
//            if (typeParamNameFound) {
//                int pos = 0;
//                for (ListIterator<expr::TypeExpression> it = methodInvoke.getTypeArgumentsListIteratorBegin(); it != methodInvoke.getTypeArgumentsListIteratorEnd(); ++it, ++pos) {
//                    if (pos == posOfParam) {
//                        return it->getType()->getId();
//                    }
//                }
//            }
//        }
//
//        if (!typeParamNameFound) {
//            // search for type parameter in the container class
//            base::Base* parent = Common::getScopeOrMethodDeclarationParent(*methodDecl);
//            if (Common::getIsGenericDeclaration(*parent)) {
//                struc::GenericDeclaration& genericDecl = dynamic_cast<struc::GenericDeclaration&>(*parent);
//                int posOfParam = 0;    
//                for (ListIterator<struc::TypeParameter> it = genericDecl.getTypeParametersListIteratorBegin(); it != genericDecl.getTypeParametersListIteratorEnd(); ++it, ++posOfParam) {
//                    if (it->getName().compare(typeParamName) == 0) {
//                        typeParamNameFound = true;
//                        break;
//                    }
//                }
//
//                if (typeParamNameFound) {
//
//                    type::Type& typeOfThis = dynamic_cast<type::Type&>(factory.getRef(thizObject->getType()));
//                    std::stack<type::Type*> superStack;
//                    superStack.push(&typeOfThis);
//
//                    while (!superStack.empty()) {
//                        type::Type* type = superStack.top();
//                        superStack.pop();
//
//                        struc::TypeDeclaration *typeDecl;
//                        if (Common::getIsParameterizedType(*type)) {
//                            type::ParameterizedType& parametrizedType = dynamic_cast<type::ParameterizedType&>(*type);
//                            typeDecl = dynamic_cast<type::ClassType&>(*parametrizedType.getRawType()).getRefersTo();
//                            if (typeDecl->getId() == genericDecl.getId()) { // we found that type declaration in which we found the type parameter
//                                int posOfArg = 0;
//                                for (ListIterator<type::Type> it = parametrizedType.getArgumentTypesListIteratorBegin(); it != parametrizedType.getArgumentTypesListIteratorEnd(); ++it, ++posOfArg) {
//                                    if (posOfArg == posOfParam) {
//                                        return it->getId();
//                                    }
//                                }
//                            }
//                        } else { // ClassType
//                            typeDecl = dynamic_cast<type::ClassType&>(*type).getRefersTo();
//                        }
//                        
//                        if (typeDecl->getSuperClass() != NULL) {
//                            superStack.push(typeDecl->getSuperClass()->getType());
//                        }
//                        for (ListIterator<expr::TypeExpression> it = typeDecl->getSuperInterfacesListIteratorBegin(); it != typeDecl->getSuperInterfacesListIteratorEnd(); ++it) {
//                            superStack.push(it->getType());
//                        }
//                    }
//
//                }
//            }
//        }
//    }
//    return returnType->getId();
//}

bool AsgUtils::isOverriddenBy(const struc::MethodDeclaration& methodInChild, const struc::MethodDeclaration& methodInParent) {

    std::stack<const struc::MethodDeclaration*> stack;
    for (ListIterator<struc::MethodDeclaration> it = methodInChild.getOverridesListIteratorBegin(); it != methodInChild.getOverridesListIteratorEnd(); ++it) {
        const struc::MethodDeclaration& methodDecl = *it;
        stack.push(&methodDecl);
    }

    while (!stack.empty()) {
        const struc::MethodDeclaration* m = stack.top();
        stack.pop();
        if (m->getId() == methodInParent.getId()) {
            return true;
        } else {
            for (ListIterator<struc::MethodDeclaration> it = m->getOverridesListIteratorBegin(); it != m->getOverridesListIteratorEnd(); ++it) {
                const struc::MethodDeclaration& methodDecl = *it;
                stack.push(&methodDecl);
            }
        }
    }

    return false;
}

bool AsgUtils::isInsideAnnotation(const java::asg::base::Base& node) {
    base::Base* parent=node.getParent();
    while (parent!=NULL) {
        if (Common::getIsAnnotation(*parent)) {
            return true;
        }
        parent=parent->getParent();
    }

    return false;
}

void AsgUtils::checkBadStaticCall(const struc::MethodDeclaration& mdecl, const expr::MethodInvocation& methodInvoke) {
    if (!mdecl.getIsStatic()) {
        if (methodInvoke.getOperand() != nullptr && Common::getIsFieldAccess(*methodInvoke.getOperand())) {
            expr::FieldAccess& fa = dynamic_cast<expr::FieldAccess&>(*methodInvoke.getOperand());
            if (Common::getIsIdentifier(*fa.getLeftOperand())) {
                expr::Identifier& leftIdentifier = dynamic_cast<expr::Identifier&>(*fa.getLeftOperand());
                if (Common::getIsClass(*leftIdentifier.getRefersTo())) {
                    throw SymbolicColumbusException("Error in ASG!");
                }
            }
        }
    }

}


}}