#include "../../inc/common.h"

using namespace columbus;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    bool handleClass(base::Base* memberClass, NodeId leftRefersTo);

    SymbolicExecutor::SymbolicExecutor(const columbus::java::asg::Factory& _factory, SymbolicEngine& engine) :
            AbstractSymbolicExecutor(engine), factory(_factory), currentNodeId(0), isSuperVisited(false) {
    }

    SymbolicExecutor::~SymbolicExecutor() {}

    void SymbolicExecutor::execute(NodeId asgNodeId) {
        currentNodeId = asgNodeId;
        factory.getRef(asgNodeId).accept(*this);
    }

    bool SymbolicExecutor::isFinalMember(java::asg::expr::Expression* left) const {
        if (Common::getIsIdentifier(*left)) {
            return isFinalMember(dynamic_cast<expr::Identifier*>(left));
        }
        if (Common::getIsFieldAccess(*left)) {
            expr::FieldAccess* fa = dynamic_cast<expr::FieldAccess*>(left);
            if (fa->getLeftOperand()) {
                return isFinalMember(fa->getLeftOperand());
            }
        }
        return false;
    }

    bool SymbolicExecutor::checkConstructor(java::asg::expr::Expression* left) const {
        if (Common::getIsIdentifier(*left)) {
            return checkConstructor(dynamic_cast<expr::Identifier*>(left));
        }
        else if (Common::getIsFieldAccess(*left)) {
            expr::FieldAccess* fa = dynamic_cast<expr::FieldAccess*>(left);
            if (fa->getLeftOperand()) {
                return checkConstructor(fa->getLeftOperand());
            }
        }
        else if (Common::getIsMethodInvocation(*left)) {
            expr::MethodInvocation* mifa = dynamic_cast<expr::MethodInvocation*>(left);
            if (mifa->getOperand()) {
                return checkConstructor(mifa->getOperand());
            }
        }
        return false;
    }

    bool SymbolicExecutor::isStaticMember(java::asg::expr::Expression* left) const {
        if (Common::getIsIdentifier(*left)) {
            return isStaticMember(dynamic_cast<expr::Identifier*>(left));
        }
        if (Common::getIsFieldAccess(*left)) {
            expr::FieldAccess* fa = dynamic_cast<expr::FieldAccess*>(left);
            if (fa->getLeftOperand()) {
                return isStaticMember(fa->getLeftOperand());
            }
        }
        return false;
    }

    bool SymbolicExecutor::isStaticMember(java::asg::expr::Identifier* left) const {
        base::Named* refersTo = left->getRefersTo();
        if (refersTo == NULL || !Common::getIsVariable(*refersTo)) {
            return false;
        }

        struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*refersTo);
        return leftVariable.getIsStatic();
    }

    bool SymbolicExecutor::isFinalMember(java::asg::expr::Identifier* left) const {
        base::Named* refersTo = left->getRefersTo();
        if (refersTo == NULL || !Common::getIsVariable(*refersTo)) {
            return false;
        }

        struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*refersTo);
        return leftVariable.getIsFinal();

    }

    bool SymbolicExecutor::isClass(java::asg::expr::Expression* left) const {
        if (Common::getIsFieldAccess(*left)) {
            expr::FieldAccess* fa = dynamic_cast<expr::FieldAccess*>(left);
            if (Common::getIsIdentifier(*fa->getRightOperand())) {
                expr::Identifier* rid = dynamic_cast<expr::Identifier*>(fa->getRightOperand());
                if (rid->getRefersTo() && Common::getIsTypeDeclaration(*rid->getRefersTo())) {
                    return true;
                }
            }
        }
        return false;
    }

    bool SymbolicExecutor::checkConstructor(java::asg::expr::Identifier* left)const {
        base::Named* refersTo = left->getRefersTo();
        if (refersTo == NULL || !Common::getIsVariable(*refersTo)) {
            return false;
        }

        struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*refersTo);
        NodeId cls = findTypeDeclarationForMember(leftVariable.getId());
        if (cls == 0)
            return false;
        const struc::TypeDeclaration* aCls = dynamic_cast<const struc::TypeDeclaration*>(factory.getPointer(cls));
        if (aCls == nullptr)
            return false;
        for (auto it = aCls->getMembersListIteratorBegin(); it != aCls->getMembersListIteratorEnd(); ++it) {
            base::Base* mem = factory.getPointer(it->getId());
            if (Common::getIsMethod(*mem)) {
                const struc::Method* meth = dynamic_cast<const struc::Method*>(mem);
                if (meth->getMethodKind() == mekConstructor) {
                    return true;
                }

            }
        }
        return false;
    }

    bool SymbolicExecutor::runIsInitedChecks(java::asg::expr::Expression* left) const {
        return isClass(left) || isStaticMember(left) || isFinalMember(left) || isInitedByAnnotation(left) || checkConstructor(left) || checkStaticInitBlock(left, false) || checkInitedAtDeclFinalMember(left, true) || checkInitedAtDeclMember(left);
    }

    bool SymbolicExecutor::isInitedByAnnotation(java::asg::expr::Expression* left) const {
        if (Common::getIsIdentifier(*left)) {
            expr::Identifier* idi = dynamic_cast<expr::Identifier*>(left);
            base::Named* refersTo = idi->getRefersTo();
            if (refersTo == NULL || !Common::getIsVariable(*refersTo)) {
                return false;
            }
            struc::Variable& variable = dynamic_cast<struc::Variable&>(*refersTo);
            for (auto it = variable.getAnnotationsListIteratorBegin(); it != variable.getAnnotationsListIteratorEnd(); ++it) {
                const expr::TypeExpression* annotName = it->getAnnotationName();
                if (Common::getIsSimpleTypeExpression(*annotName)) {
                    const expr::SimpleTypeExpression* expr = dynamic_cast<const expr::SimpleTypeExpression*>(annotName);
                    if (expr->getName() == "UiField") {
                        return true;
                    }
                }
            }
        }
        
        return false;

    }

    bool  SymbolicExecutor::isInitedFinalMember(expr::Identifier* left, bool onlyFinal) const {
        base::Named* refersTo = left->getRefersTo();
        if (refersTo == NULL || !Common::getIsVariable(*refersTo)) {
            return false;
        }

        struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*refersTo);
        if (!onlyFinal || (onlyFinal && leftVariable.getIsFinal())) {
            return leftVariable.getInitialValue() != nullptr && (!Common::getIsNullLiteral(*(leftVariable.getInitialValue())));

        }

        return false;

    }

    bool SymbolicExecutor::checkInitedAtDeclMember(java::asg::expr::Expression* leftOperand) const {
        if (Common::getIsIdentifier(*leftOperand)) {
            expr::Identifier* left = dynamic_cast<expr::Identifier*>(leftOperand);
            
            base::Named* refersTo = left->getRefersTo();
            if (refersTo == NULL || !Common::getIsVariable(*refersTo)) {
                return false;
            }
            
            struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*refersTo);
            bool isMemberVariable = findTypeDeclarationForMember(leftVariable.getId()) != 0;
            return isMemberVariable && leftVariable.getInitialValue() != nullptr && (!Common::getIsNullLiteral(*(leftVariable.getInitialValue())));

        }
        return false;
    }

    bool SymbolicExecutor::checkInitedAtDeclFinalMember(expr::Expression* leftOperand, bool onlyFinal) const {
        if (Common::getIsMethodInvocation(*leftOperand)) {
            expr::MethodInvocation* methodInvoc = dynamic_cast<expr::MethodInvocation*>(leftOperand);
            struc::MethodDeclaration* methodDecl = methodInvoc->getInvokes();

            if (Common::getIsMethod(*methodDecl)) {
                struc::Method* method = dynamic_cast<struc::Method*>(methodDecl);
                statm::Block* methodBody = method->getBody();
                ListIterator<statm::Statement> iterator = methodBody->getStatementsListIteratorBegin();
                ListIterator<statm::Statement> iterator_end = methodBody->getStatementsListIteratorEnd();
                for (; iterator != iterator_end; ++iterator) {
                    if (Common::getIsReturn(*iterator)) {
                        const statm::Return& returnStatm = dynamic_cast<const statm::Return&>(*iterator);
                        expr::Expression* returnExpr = returnStatm.getExpression();
                        if (Common::getIsIdentifier(*returnExpr)) {
                            bool res = isInitedFinalMember(dynamic_cast<expr::Identifier*>(returnExpr), true);
                            if (onlyFinal) {
                                if (!res) {
                                    return isFinalMember(dynamic_cast<expr::Identifier*>(returnExpr));
                                }
                                return true;
                            }
                            else {
                                return res;
                            }
                        }
                    }
                }
            }
            return false;
        }
        else if (Common::getIsIdentifier(*leftOperand)) {
            bool res = isInitedFinalMember(dynamic_cast<expr::Identifier*>(leftOperand), onlyFinal);
            if (onlyFinal) {
                if (!res) {
                    return isFinalMember(dynamic_cast<expr::Identifier*>(leftOperand));
                }
                return true;
            }
            else {
                return res;
            }
        }
        else if (Common::getIsArrayAccess(*leftOperand)) {
            expr::ArrayAccess* aa = dynamic_cast<expr::ArrayAccess*>(leftOperand);
            if (aa->getLeftOperand() && Common::getIsIdentifier(*aa->getLeftOperand())) {
                bool res = isInitedFinalMember(dynamic_cast<expr::Identifier*>(aa->getLeftOperand()), onlyFinal);
                if (onlyFinal) {
                    if (!res) {
                        return isFinalMember(dynamic_cast<expr::Identifier*>(aa->getLeftOperand()));
                    }
                    return true;
                }
                else {
                    return res;
                }
            }
        }
        return false;
    }


    bool SymbolicExecutor::checkStaticInitBlock(expr::Expression* leftOperand, bool onlyFinal) const{
        if (Common::getIsMethodInvocation(*leftOperand)) {
            expr::MethodInvocation* methodInvoc = dynamic_cast<expr::MethodInvocation*>(leftOperand);
            struc::MethodDeclaration* methodDecl = methodInvoc->getInvokes();

            if (!methodDecl->getIsStatic()) {
                return false;
            }
            if (Common::getIsMethod(*methodDecl)) {
                struc::Method* method = dynamic_cast<struc::Method*>(methodDecl);
                statm::Block* methodBody = method->getBody();
                ListIterator<statm::Statement> iterator = methodBody->getStatementsListIteratorBegin();
                ListIterator<statm::Statement> iterator_end = methodBody->getStatementsListIteratorEnd();
                for (; iterator != iterator_end; ++iterator) {
                    if (Common::getIsReturn(*iterator)) {
                        const statm::Return& returnStatm = dynamic_cast<const statm::Return&>(*iterator);
                        expr::Expression* returnExpr = returnStatm.getExpression();
                        if (Common::getIsIdentifier(*returnExpr)) {
                            return checkMemberInitedInStaticInitBlock(returnExpr, onlyFinal);
                        }
                        break;
                    }
                }
            }
            return false;
        }
        else if (Common::getIsIdentifier(*leftOperand)) {
            return checkMemberInitedInStaticInitBlock(leftOperand, onlyFinal);
        }
        else if (Common::getIsFieldAccess(*leftOperand)) {
            expr::FieldAccess* facc = dynamic_cast<expr::FieldAccess*>(leftOperand);
            auto right = facc->getRightOperand();
            if (right && Common::getIsIdentifier(*right)) {
                return checkMemberInitedInStaticInitBlock(right, onlyFinal);
            }
        }
        return false;
    }


    bool SymbolicExecutor::checkMemberInitedAtDecl(const expr::ArrayAccess& acc) const{
        auto leftOperand = acc.getLeftOperand();
        if (leftOperand){
            if (Common::getIsIdentifier(*leftOperand)) {
                expr::Identifier* leftIdentifier = dynamic_cast<expr::Identifier*>(leftOperand);
                base::Named* leftRefersTo = leftIdentifier->getRefersTo();
                if (leftRefersTo && Common::getIsVariable(*leftRefersTo)) {
                    struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*leftRefersTo);
                    if (leftVariable.getIsFinal()) {
                        return leftVariable.getInitialValue() != nullptr && (!Common::getIsNullLiteral(*(leftVariable.getInitialValue())));

                    }
                }
            }
            else if(Common::getIsArrayAccess(*leftOperand)){
                return checkMemberInitedAtDecl(dynamic_cast<const expr::ArrayAccess&>(*leftOperand));
            }
        }
        return false;
    }

    bool SymbolicExecutor::checkMemberInitedInStaticInitBlock(const java::asg::expr::ArrayAccess& acc, bool onlyFinal)const {
        auto leftOperand = acc.getLeftOperand();
        if (leftOperand) {
            if (Common::getIsIdentifier(*leftOperand)) {
                expr::Identifier* leftIdentifier = dynamic_cast<expr::Identifier*>(leftOperand);
                base::Named* leftRefersTo = leftIdentifier->getRefersTo();
                if (leftRefersTo && Common::getIsVariable(*leftRefersTo)) {
                    struc::Variable& leftVariable = dynamic_cast<struc::Variable&>(*leftRefersTo);
                    bool isMemberVariable = findTypeDeclarationForMember(leftVariable.getId()) != 0;
                    if (isMemberVariable && leftVariable.getIsStatic() && (!onlyFinal || leftVariable.getIsFinal())) {
                        base::Base* memberClass = leftVariable.getParent();
                        if (Common::getIsClass(*memberClass)) {
                            return handleClass(memberClass, leftVariable.getId());
                        }
                    }

                }
            }
            else if (Common::getIsArrayAccess(*leftOperand)) {
                return checkMemberInitedInStaticInitBlock(dynamic_cast<const expr::ArrayAccess&>(*leftOperand), onlyFinal);
            }
        }
        return false;
    }

    void SymbolicExecutor::executeStaticBlocks(base::Base* memberClass) {
        struc::Class& memberClassAsClass = dynamic_cast<struc::Class&>(*memberClass);


        ListIterator<struc::Member> iterator = memberClassAsClass.getMembersListIteratorBegin();
        ListIterator<struc::Member> iterator_end = memberClassAsClass.getMembersListIteratorEnd();

        //loop class members
        for (; iterator != iterator_end; ++iterator) {
            const struc::Member& actual_member = *iterator;
            if (Common::getIsStaticInitializerBlock(actual_member)) {
                execute(actual_member.getId());
            }
        }
    }


    bool handleClass(base::Base* memberClass, NodeId leftRefersTo) {
        struc::Class& memberClassAsClass = dynamic_cast<struc::Class&>(*memberClass);


        ListIterator<struc::Member> iterator = memberClassAsClass.getMembersListIteratorBegin();
        ListIterator<struc::Member> iterator_end = memberClassAsClass.getMembersListIteratorEnd();

        //loop class members
        for (; iterator != iterator_end; ++iterator) {
            const struc::Member& actual_member = *iterator;
            if (Common::getIsStaticInitializerBlock(actual_member)) {
                const struc::StaticInitializerBlock& staticInit = dynamic_cast<const struc::StaticInitializerBlock&>(actual_member);
                const statm::Block* staticInitBody = staticInit.getBody();

                ListIterator<statm::Statement> iteratorStatement = staticInitBody->getStatementsListIteratorBegin();
                ListIterator<statm::Statement> iteratorStatementEnd = staticInitBody->getStatementsListIteratorEnd();
                //loop static init block
                auto handleExpression = [&leftRefersTo](const statm::ExpressionStatement& staticInitExpr) -> bool{
                    if (Common::getIsAssignment(*(staticInitExpr.getExpression()))) {
                        const expr::Assignment& staticInitAssign = dynamic_cast<const expr::Assignment&>(*(staticInitExpr.getExpression()));
                        expr::Expression* leftOfAssign = staticInitAssign.getLeftOperand();
                        //is current variable initialized in static init?
                        if (Common::getIsIdentifier(*leftOfAssign)) {
                            const expr::Identifier& assignedIdentifier = dynamic_cast<const expr::Identifier&>(*leftOfAssign);
                            if (assignedIdentifier.getRefersTo()->getId() == leftRefersTo) {
                                if (!Common::getIsNullLiteral(*(staticInitAssign.getRightOperand())) && !Common::getIsNullType(*(staticInitAssign.getRightOperand())))
                                    return true;
                            }
                        }
                    }
                    return false;
                };
                for (; iteratorStatement != iteratorStatementEnd; ++iteratorStatement) {
                    if (Common::getIsTry(*iteratorStatement)) {
                        const statm::Try& tryBlock = dynamic_cast<const statm::Try&>(*iteratorStatement);
                        const statm::Block* tryBody = tryBlock.getBlock();
                        ListIterator<statm::Statement> stBegin = tryBody->getStatementsListIteratorBegin();
                        ListIterator<statm::Statement> stEnd = tryBody->getStatementsListIteratorEnd();
                        for (; stBegin != stEnd; ++stBegin) {
                            if (Common::getIsExpressionStatement(*stBegin)) {
                                const statm::ExpressionStatement& staticInitExpr = dynamic_cast<const statm::ExpressionStatement&>(*stBegin);
                                if (handleExpression(staticInitExpr))
                                    return true;
                            }
                        }
                    }
                    if (Common::getIsIf(*iteratorStatement)) {
                        const statm::If& ifBlock = dynamic_cast<const statm::If&>(*iteratorStatement);
                        const statm::Statement* ifBody = ifBlock.getSubstatement();
                        if (ifBody != nullptr && Common::getIsBlock(*ifBody)) {
                            const statm::Block& block = dynamic_cast<const statm::Block&>(*ifBody);
                            ListIterator<statm::Statement> stBegin = block.getStatementsListIteratorBegin();
                            ListIterator<statm::Statement> stEnd = block.getStatementsListIteratorEnd();
                            for (; stBegin != stEnd; ++stBegin) {
                                if (Common::getIsExpressionStatement(*stBegin)) {
                                    const statm::ExpressionStatement& staticInitExpr = dynamic_cast<const statm::ExpressionStatement&>(*stBegin);
                                    if (handleExpression(staticInitExpr))
                                        return true;
                                }
                            }
                        }
                    }
                    if (Common::getIsExpressionStatement(*iteratorStatement)) {
                        const statm::ExpressionStatement& staticInitExpr = dynamic_cast<const statm::ExpressionStatement&>(*iteratorStatement);
                        if (handleExpression(staticInitExpr))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    bool SymbolicExecutor::checkMemberInitedInStaticInitBlock(expr::Expression* leftOperand, bool onlyFinal) const{
        if (Common::getIsIdentifier(*leftOperand)) {
            expr::Identifier* leftIdentifier = dynamic_cast<expr::Identifier*>(leftOperand);
            base::Named* leftRefersTo = leftIdentifier->getRefersTo();
            if (Common::getIsVariableDeclaration(*leftRefersTo)) {
                struc::VariableDeclaration& leftVariable = dynamic_cast<struc::VariableDeclaration&>(*leftRefersTo);
                bool isMemberVariable = findTypeDeclarationForMember(leftVariable.getId()) != 0;
                if (isMemberVariable && leftVariable.getIsStatic() && (!onlyFinal || leftVariable.getIsFinal())) {
                    base::Base* memberClass = leftVariable.getParent();
                    if (Common::getIsClass(*memberClass)) {
                        return handleClass(memberClass, leftVariable.getId());
                    }
                }
            }

        }
        
       return false;

    }


    bool SymbolicExecutor::isZero(SmartDefinition def) {
        if (def->isByteValueDefinition()) {
            const ByteValueDefinition* byteVal = dynamic_cast<const ByteValueDefinition*>(def.get());
            return byteVal->getValue() == 0;
        } else if (def->isShortValueDefinition()) {
            const ShortValueDefinition* shortVal = dynamic_cast<const ShortValueDefinition*>(def.get());
            return shortVal->getValue() == 0;
        } else if (def->isIntValueDefinition()) {
            const IntValueDefinition* intVal = dynamic_cast<const IntValueDefinition*>(def.get());
            return intVal->getValue() == 0;
        } else if (def->isLongValueDefinition()) {
            const LongValueDefinition* longVal = dynamic_cast<const LongValueDefinition*>(def.get());
            return longVal->getValue() == 0;
        } else if (def->isCharValueDefinition()) {
            const CharValueDefinition* charVal = dynamic_cast<const CharValueDefinition*>(def.get());
            return charVal->getValue() == 0;
        } else if (def->isFloatValueDefinition()) {
            const FloatValueDefinition* floatVal = dynamic_cast<const FloatValueDefinition*>(def.get());
            return floatVal->getValue() == 0.0;
        } else if (def->isDoubleValueDefinition()) {
            const DoubleValueDefinition* doubleVal = dynamic_cast<const DoubleValueDefinition*>(def.get());
            return doubleVal->getValue() == 0.0;
        } else {
            return false;
        }
    }

    bool SymbolicExecutor::getBooleanValueDefinitionValue(SmartDefinition definition) {
        return ((const BooleanValueDefinition*)definition.get())->getValue();
    }

	SmartDefinition SymbolicExecutor::createBooleanValueDefinition(bool value) {
		return DefinitionFactory::createBoolean(value, engine);
	}

    void SymbolicExecutor::setupCalledState(State& calledState, NodeId caller, NodeId calledICFG) {
        
        State& state = engine.getCurrentState();
        base::Base* base = factory.getPointer(caller);

        if (Common::getIsNewClass(*base)) {

            // We will encounter a newClass in the next BB. We have to make a call to BB.
            expr::NewClass* newClass = dynamic_cast<expr::NewClass*>(base);

            // This is a workaround for handling wrong anonymous constructor linkage in asg
            if (newClass->getAnonymousClass()!= NULL && newClass->getAnonymousClass()->getMembersIsEmpty()) {
                throw SymbolicColumbusException("Error in ASG!");
            }

            NodeId typeId = SymbolicTypesPreVisitor::getType(newClass->getType()->getId()).typeId != 0
                                ? SymbolicTypesPreVisitor::getType(newClass->getType()->getId()).typeId
                                : SymbolicTypesPreVisitor::getObjectTypeId();
            SmartDefinition newClassRef=DefinitionFactory::createObject(typeId, true, engine);
            calledState.setThizObject(newClassRef);
        } else if (Common::getIsMethodInvocation(*base)) {
            
            expr::MethodInvocation* methodInvoke = dynamic_cast<expr::MethodInvocation*>(base);
            struc::MethodDeclaration* mdecl = dynamic_cast<struc::MethodDeclaration*>(factory.getPointer(calledICFG));
            
            // handling asg error: bad method linked to the method invocation
            // invocation and the method both must return void or both non-void
            if (methodInvoke->getType() != NULL && mdecl->getReturnType() != NULL && mdecl->getReturnType()->getType() != NULL) {
                if ( ! ((Common::getIsVoidType(*methodInvoke->getType()) && Common::getIsVoidType(*mdecl->getReturnType()->getType())) 
                    || (!Common::getIsVoidType(*methodInvoke->getType()) && !Common::getIsVoidType(*mdecl->getReturnType()->getType()))) ) {
                    throw SymbolicColumbusException("Error in ASG!");
                }
            }
            
            if (boost::algorithm::ends_with(mdecl->getName(), "_instanceInit")) {
                /**
                *	If we have an instanceInit function call, we need to use the same this object
                *	It is not on the heap as no signs before the invocation exist
                */
                calledState.setThizObject(state.getThizObject());
            } else if (!mdecl->getIsStatic()) {
                AsgUtils::checkBadStaticCall(*mdecl, *methodInvoke);

                /**
                *	Otherwise, if we are dealing with a non-static method call, this object is always on the stack
                */
                calledState.setThizObject(calledState.popDefinition());
            }
        }
        calledState.pushCall(caller);
    }
 
    void SymbolicExecutor::makeCallReturn(State& returningState) {
        State& state = engine.getCurrentState();
        if (!state.hasCall()) {
            return;
        }

        NodeId theCall=state.topCall();
        base::Base* base = factory.getPointer(theCall);

        if (Common::getIsNewClass(*base)) {
            expr::NewClass* newClass = dynamic_cast<expr::NewClass*>(base);
            // pop constructor call arguments
            for (unsigned int i=0; i<newClass->getArgumentsSize(); i++) {
                returningState.popDefinition();
            }
            // "return value" of the constructor, the created object
            returningState.pushDefinition(state.getThizObject());
        } else if (Common::getIsMethodInvocation(*base)) {
            expr::MethodInvocation* invocation = dynamic_cast<expr::MethodInvocation*>(base);
            const struc::MethodDeclaration& mdecl = *invocation->getInvokes(); //getInvokedMethod(*invocation);

            if (!boost::algorithm::ends_with(mdecl.getName(), "_instanceInit") && !mdecl.getIsStatic()) {
                returningState.popDefinition(); // pop this
            }

            // pop the arguments
            for (unsigned i = 0; i < invocation->getArgumentsSize(); ++i) {
                returningState.popDefinition();
            }

            type::Type* returnType = invocation->getType();
            if (returnType==NULL || Common::getIsVoidType(*returnType) 
                || (Common::getIsErrorType(*returnType) && Common::getIsVoidType(*mdecl.getReturnType()->getType())) ) {
                // TODO: itt lehetnek gondok az ErrorType-os visszatéréssel
                // mert nem biztos, hogy jól van bekötve asg-ben az invocation-höz tartozó method,
                // Pántos Jani szerint ezt nem is lehet jól bekötni
                /**
                *	The method does not return anything....nothing to do
                */
            } else {
                /**
                *	We have to return something
                */
                struc::NormalMethod& method=(struc::NormalMethod&)(mdecl);
                if (method.getBody() == NULL) {
                    // putting a symbol if there is not body
                    // TODO: bizonyos esetekben a
                    //  returnType lehet TypeVariable, ilyenkor Object típusra állítjuk
                    //       vissza kellene majd keresni a megfelelõ típust (ha lehetésges)
                    NodeId returnTypeId = !Common::getIsErrorType(*returnType)
                        && !Common::getIsTypeVariable(*returnType)
                        ? returnType->getId()
                        : SymbolicTypesPreVisitor::getObjectTypeId();
                    
                    returningState.pushDefinition(DefinitionFactory::createSymbol(returnTypeId, engine));
                } else {
                    // placing back the return value
                    returningState.pushDefinition(state.popDefinition());
                }
            }
        }
    }

    const struc::MethodDeclaration& SymbolicExecutor::getInvokedMethod(const expr::MethodInvocation& methodInvoke) {
        struc::MethodDeclaration* methodDecl = methodInvoke.getInvokes(); // methodDecl from static type of "this"

        if (methodDecl->getIsStatic()) {
            return *methodDecl;
        }

        SmartDefinition thizObject = engine.getCurrentState().getThizObject();
        type::Type* thizType = &dynamic_cast<type::Type&>(factory.getRef(thizObject->getType()));
        
        std::stack<type::Type*> superStack;
        superStack.push(thizType);

        while (!superStack.empty()) {
            type::Type* topType = superStack.top();
            superStack.pop();

            struc::TypeDeclaration* typeDecl;
            if (Common::getIsClassType(*topType)) {
                typeDecl = dynamic_cast<type::ClassType&>(*topType).getRefersTo();
            } else if (Common::getIsParameterizedType(*topType)) {
                type::Type* rawType = dynamic_cast<type::ParameterizedType&>(*topType).getRawType();
                typeDecl = dynamic_cast<type::ClassType&>(*rawType).getRefersTo();
            } else {
                continue;
            }
            for (ListIterator<struc::Member> it = typeDecl->getMembersListIteratorBegin(); it != typeDecl->getMembersListIteratorEnd(); ++it) {
                if (Common::getIsMethodDeclaration(*it)) {
                    const struc::MethodDeclaration& methodDeclInThizObject = dynamic_cast<const struc::MethodDeclaration&>(*it);
                    if (methodDeclInThizObject.getName() == methodDecl->getName() 
                                && methodDeclInThizObject.getMethodType()->getParameterTypesSize() == methodDecl->getMethodType()->getParameterTypesSize()
                                && AsgUtils::isOverriddenBy(methodDeclInThizObject, *methodDecl) ) {
                        return methodDeclInThizObject;
                    }
                    
                }
            }
            
            expr::TypeExpression* superClass = typeDecl->getSuperClass();
            if (superClass != NULL)
                superStack.push(superClass->getType());
            for (ListIterator<expr::TypeExpression> it = typeDecl->getSuperInterfacesListIteratorBegin(); it != typeDecl->getSuperInterfacesListIteratorEnd(); ++it) {
                superStack.push(it->getType());
            }
        }

        return *methodDecl;
    }

    NodeId SymbolicExecutor::getScopeOrMethodDeclarationParent(NodeId nodeId) {
        base::Base& base = factory.getRef(nodeId);
        return columbus::java::asg::Common::getScopeOrMethodDeclarationParent(base)->getId();
    }

    void SymbolicExecutor::initializeThis(NodeId nodeId, State& state) {
        SmartDefinition thiz=DefinitionFactory::createObject(SymbolicTypesPreVisitor::getClassType(nodeId), true, engine);
        state.setThizObject(thiz);
    }

    BooleanInfixOperatorKind SymbolicExecutor::getParentOperatorKind(const NodeId currentNode, NodeId& parentNode) const {
        BooleanInfixOperatorKind result = columbus::symbolic::biokNONE;

        State& state = engine.getCurrentState();
        bool isStackEmpty = state.isStackEmpty();
        if (!isStackEmpty) {
            SmartDefinition lastDefinition = state.topDefinition();
            if (lastDefinition.get() != NULL && lastDefinition->isBooleanValueDefinition()) {
                base::Base *parent = factory.getPointer(currentNode);
                while (parent != NULL) {
                    if (Common::getIsInfixExpression(*parent)) {
                        expr::InfixExpression *infix = dynamic_cast<expr::InfixExpression*>(parent);
                        if (infix->getLeftOperand()->getId() == currentNode) {
                            if (infix->getOperator() == iokConditionalOr) {
                                parentNode = parent->getId();
                                result = columbus::symbolic::biokLOGICAL_OR;
                                break;
                            } else if (infix->getOperator() == iokConditionalAnd) {
                                parentNode = parent->getId();
                                result = columbus::symbolic::biokLOGICAL_AND;
                                break;
                            }
                        }
                    }
                    parent = parent->getParent();
                }
            }
        }

        return result;
    }

    NodeId SymbolicExecutor::findTypeDeclarationForMember(const NodeId memberId) const {
        base::Base *base = factory.getPointer(memberId);
        base::Base *parent=base->getParent();
        if (parent!=NULL && Common::getIsTypeDeclaration(*parent))
            return parent->getId();
        return 0;
    }
    
    NodeId SymbolicExecutor::getType(const java::asg::expr::Identifier &node, const NodeId variableId) const {
        NodeId typeId = 0;
        if (node.getType() != NULL)
            typeId = node.getType()->getId();
        else {
            base::Base *base = factory.getPointer(variableId);
            if (base != NULL && Common::getIsVariable(*base)) {
                struc::Variable *variableNode = dynamic_cast<struc::Variable*>(base);
                typeId = variableNode->getType()->getId();
            }
        }
        
        type::Type *t = NULL;
        base::Base *typeBase = factory.getPointer(typeId);
        if (typeBase != NULL && Common::getIsTypeApplyExpression(*typeBase)) {
            expr::TypeApplyExpression *tae = dynamic_cast<expr::TypeApplyExpression*>(typeBase);
            t = tae->getType();
        } else {
            t = dynamic_cast<type::Type*>(factory.getPointer(typeId));
        }
        
        return t == NULL ? 0 : t->getId();
    }
    
    SmartDefinitionProxy SymbolicExecutor::getLocalVariable(const expr::Identifier& identifier) {
        State& state=engine.getCurrentState();
        Address address=state.getAddressOfLocal(identifier.getRefersTo()->getId());
        SmartDefinitionProxy proxy=state.getObjectByAddress(address);
        if (proxy->isNull()) 
            return *proxy=DefinitionFactory::createSymbol(identifier.getType()->getId(), engine);
        else
            return proxy;
        
    }
    
    SmartDefinitionProxy SymbolicExecutor::getLocalVariable(const struc::Variable& variable, SmartDefinition init) {
        State& state=engine.getCurrentState();
        Address address=state.getAddressOfLocal(variable.getId());
        SmartDefinitionProxy proxy=state.getObjectByAddress(address);
        
        if (proxy->isNull()) {
            if (variable.getType() == NULL || variable.getType()->getType() == NULL) throw SymbolicColumbusException("Missing variable type!"); // FIXME
            if (variable.getInitialValue() == nullptr) {
                return *proxy = DefinitionFactory::createSymbol(variable.getType()->getType()->getId(), engine);
            }
            else {
                //kapja meg paraméterben az initet?
                return *proxy = init;
                //auto csExpr = engine.getConstraintBuilder()->makeBoolExpr(*proxy->operator columbus::symbolic::SmartDefinition & (), *init, iokEqualTo);
                //init->setCsExpr(csExpr);
                //return *proxy = init;
            }
        } else
            return proxy;
    }

    SmartDefinitionProxy SymbolicExecutor::getClassMemberVariable(const SmartDefinition& reference, columbus::NodeId nodeId) {
        State& state=engine.getCurrentState();
        Object& object=Object::getRawObject(reference, engine);
        Address address=object.getMemberAddress(nodeId);
        SmartDefinitionProxy proxy=state.getObjectByAddress(address);
        if (proxy->isNull()) {
            struc::VariableDeclaration& decl=dynamic_cast<struc::VariableDeclaration&>(factory.getRef(nodeId));
            if (decl.getType() == NULL) throw SymbolicColumbusException("Cannot find declaration type!");
            return *proxy=DefinitionFactory::createSymbol(decl.getType()->getType()->getId(), engine);
        } else
            return proxy;
    }

    SmartDefinitionProxy SymbolicExecutor::getArrayElement(const SmartDefinition& reference, const SmartDefinition& coord, bool initializedAtDecl, bool initAtStatic) {
        State& state=engine.getCurrentState();
        Array& rawArray=Array::getRawArray(reference, engine, initializedAtDecl, initAtStatic);

        // it is possible to index an array with other than int (byte, char, etc...) thus need to cast
        SmartDefinition intCoord = !coord->isIntValueDefinition() ? coord->castToInt() : coord;

        // check ArrayIndexOutOfBounds
        SmartDefinition arrSize = rawArray.getArraySize();
        if (!arrSize->getIsSymbol() && !coord->getIsSymbol()) {
            const IntValueDefinition& size=dynamic_cast<const IntValueDefinition&>(*arrSize);
            const IntValueDefinition& intValueCoord=dynamic_cast<const IntValueDefinition&>(*intCoord);
            if (intValueCoord.getValue()>=size.getValue() || intValueCoord.getValue()<0) {
                if(state.fireIndexOutOfBounds(currentNodeId, size.getValue(), intValueCoord.getValue()))
                    throw SymbolicColumbusException("ArrayIndexOutOfBoundsException found! Execution does not continue on this path.");
                else
                    throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
            }
        }

        Address address=rawArray.getArrayElementAddress(intCoord);
        SmartDefinitionProxy proxy=state.getObjectByAddress(address);
        if (proxy->isNull()) {
            /**
            *	We are using the address we got (it may also be a symbol address)
            * 
            */
            base::Base& base = factory.getRef(rawArray.getElementType());
            type::Type& typeRef = dynamic_cast<type::Type&>(base);
            
            if (rawArray.isInitialized() || initializedAtDecl) {
                
                //const columbus::java::asg::Factory& factory = dynamic_cast<SymbolicExecutor*>(engine.getExecutor())->getFactory();
                //base::Base& base = factory.getRef(rawArray.getElementType());
                //type::Type& typeRef = (type::Type&)base;

                if (rawArray.getIsSymbol()) {
                    *proxy = DefinitionFactory::createSymbol(rawArray.getElementType(), address, engine);
                }
                else if (Common::getIsArrayType(typeRef) || Common::getIsScopedType(typeRef) || Common::getIsNullType(typeRef) || Common::getIsParameterizedType(typeRef) || Common::getIsWildcardType(typeRef) || Common::getIsTypeVariable(typeRef)) {
                    *proxy = DefinitionFactory::createReference(Reference::default_value, rawArray.getElementType(), engine);
                }
                else {
                    *proxy = DefinitionFactory::createSymbol(rawArray.getElementType(), address, engine);
                }
            }
            else {
                if (Common::getIsClassType(typeRef)) {
                    type::ClassType& ctype = dynamic_cast<type::ClassType&>(typeRef);
                    if (Common::getIsEnum(*(ctype.getRefersTo()))) {
                        //enum eseten ne dobjunk kivetelt
                        *proxy = DefinitionFactory::createReference(Reference::default_value, rawArray.getElementType(), engine);
                        return proxy;
                    }
                }
                if (reference->getIsSymbol()) {
                    *proxy = DefinitionFactory::createSymbol(rawArray.getElementType(), address, engine);
                }
                else {
                    if(state.fireNullPointerDereferenced(currentNodeId))
                        throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                    else
                        throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                }
               //*proxy = DefinitionFactory::createReference(Reference::default_value, rawArray.getElementType(), engine);
            }
            return state.getObjectByAddress(address);
        } else {
            return proxy;
        }
    }
    
    // Visitors
    void SymbolicExecutor::visit(const columbus::java::asg::base::Base& node, bool callVirtualBase) {
        stringstream ss;
        ss << "There is no visitor function for the node: " << node.getId() << " (nodeKind: " << Common::toString(node.getNodeKind()) << ")!";
        throw SymbolicColumbusException(ss.str().c_str());
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::Identifier& node, bool callVirtualBase) {
        //NodeId id = node.getId();
        // check whether we are inside an annotation
        if (AsgUtils::isInsideAnnotation(node)) return;

        bool nonInited = false;
        State& state = engine.getCurrentState();
        NodeId refersTo = 0;

        bool mayPushToStack=true;
        if (node.getParent() != NULL && Common::getIsFieldAccess(*node.getParent()) && dynamic_cast<expr::FieldAccess&>(*node.getParent()).getLeftOperand()->getId() == node.getId()) {
            /**
            *	If we are standing at the lhs of a field access
            */
            expr::Expression* leftOperand=dynamic_cast<expr::FieldAccess&>(*node.getParent()).getLeftOperand();
            expr::Expression* rightOperand=dynamic_cast<expr::FieldAccess*>(node.getParent())->getRightOperand();
            if (Common::getIsIdentifier(*rightOperand)) {
                /**
                *	The operand standing at the right of this field access is an identifier
                */
                expr::Identifier& rightIdentifier=dynamic_cast<expr::Identifier&>(*rightOperand);
                
                if (leftOperand->getType() != NULL && Common::getIsArrayType(*leftOperand->getType()) && rightIdentifier.getName()=="length") {
                    /**
                    *	We have an array.length, we can push the array reference at this point, as length is handled sepatatelly below
                    */

                } else if (rightIdentifier.getRefersTo()==NULL) {
                    /**
                    *	...that does not refer to anything
                    *	We must not push anything on the stack, as it will not be popped in the next round
                    */
                    mayPushToStack=false;
                }
            }
        }


        if (node.getParent() != NULL && Common::getIsFieldAccess(*node.getParent()) && dynamic_cast<expr::FieldAccess&>(*node.getParent()).getRightOperand()->getId() == node.getId()) {
            
           /**
            *	We have an identifier at the right-hand-side of a field access: parent.node
            */
            if (node.getRefersTo()==NULL) {
               /**
                *	We don't know that in on the right-hand-side
                *	
                */
                //we'll deal with array.length separatelly
                expr::Expression* leftOperand=dynamic_cast<expr::FieldAccess&>(*node.getParent()).getLeftOperand();
                if (leftOperand->getType() != NULL && Common::getIsArrayType(*leftOperand->getType()) && node.getName()=="length") {
                    /**
                    *	We have an array.length here...we must have the reference of the array at the top of stack
                    */
                    SmartDefinition referenceToArray=state.popDefinition();
                    Array& rawArray=Array::getRawArray(referenceToArray, engine);
                    state.pushDefinition(rawArray.getArraySize());
                } else if (mayPushToStack) {
                    /*
                    *	It would be appropriate to put at least a symbol on the stack....even if it was not neceassary
                    *	We should pop the lhs only if it is on the stack already. But only if we may do that
                    */
                    state.pushDefinition(DefinitionFactory::createSymbol(node.getType() == NULL ? SymbolicTypesPreVisitor::getObjectTypeId() : node.getType()->getId(), engine));
                }
                return;
            }
                        
            NodeId refersTo = node.getRefersTo()->getId();
            expr::Expression* leftOperand=dynamic_cast<expr::FieldAccess&>(*node.getParent()).getLeftOperand();
            

            if (Common::getIsVariableDeclaration(*node.getRefersTo())) {
                /**
                *	We have a variable declaration, i.e. Variable or EnumConstant (we cannot have a paramerer at the rhs of a field selection
                */
                
                base::Base& refersToNode = *node.getRefersTo();
                bool interfaceMember=false;
                bool enumConstant=false;
                bool isAnnotationMember = false;
                if (refersToNode.getParent() != NULL && Common::getIsInterfaceDeclaration(*refersToNode.getParent())) {
                    /**
                    *	We have a member of an interface...in this case all the member variables are static and final by definition
                    */
                    interfaceMember=true;
                } else if (Common::getIsEnumConstant(*node.getRefersTo())) {
                    /**
                    *	We have an enum constant at this point which does not really differ from a static final variable
                    */
                    enumConstant=true;
                } else if ( refersToNode.getParent() != NULL && Common::getIsAnnotationType(*refersToNode.getParent()) ) {
                    isAnnotationMember = true;
                }

                //in this case the top element on the stack was the reference to the class object
                SmartDefinition toStack;
                SmartDefinitionProxy member;
                

                struc::VariableDeclaration& variableNode = dynamic_cast<struc::VariableDeclaration&>(refersToNode);
                if (variableNode.getIsStatic() || interfaceMember || enumConstant || isAnnotationMember) {
                    /**
                    *	We are referring to a static variable...
                    */
                    Address address=state.getAddressOfLocal(refersTo);
                    member = state.getObjectByAddress(address);

                    if (member->isNull()) {
                       /**
                        *	...that has not been seen yet
                        */
                        if (variableNode.getIsFinal() || interfaceMember || enumConstant || isAnnotationMember) {
                            /**
                            *	Initializing a static final variable
                            */
                            execute(variableNode.getId());
                            Address address=state.getAddressOfLocal(refersTo);
                            member = state.getObjectByAddress(address);
                            if (enumConstant) {
                                struc::EnumConstant& enumConstant = dynamic_cast<struc::EnumConstant&>(variableNode);
                                *member = DefinitionFactory::createReference(address, enumConstant.getType()->getType()->getId(), engine);
                            }
                        } else { 
                            /**
                            *	Initializing a static non-final variable
                            */
                            base::Base* refers = factory.getPointer(refersTo);
                            if (Common::getIsVariable(*refers)) {
                                struc::Variable* var = dynamic_cast<struc::Variable*>(refers);
                                if (var->getInitialValue() == nullptr || Common::getIsNullLiteral(*var->getInitialValue())) {
                                    nonInited = true;
                                    *member = DefinitionFactory::createReference(Reference::default_value, node.getType() != NULL ? node.getType()->getId() : 0, engine);
                                }
                            }
                            if (!nonInited) {
                                toStack = DefinitionFactory::createSymbol((node.getType() != NULL ? node.getType()->getId() : 0), engine);
                                *member = toStack;
                            }
                            
                        }
                    }
                } else {            
                    /**
                    *	We have a non-static variable (we are still in handling field access only)
                    */
                    SmartDefinition classRef=state.popDefinition();
                    try {
                        member = getClassMemberVariable(classRef, refersTo);
                    }
                    catch (const SymbolicColumbusException& ex) {
                        if (string(ex.what()) == "NullType") {
                            state.fireNullPointerDereferenced(node.getParent()->getId());
                            throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                        }
                        else {
                            throw;
                        }
                    }
                    
                }
                    
                if ((member && !member->isNull()) || (member && nonInited)) {
                    /**
                    *	We we found an existing member, we will put it on stack...in this case toStack was null, so we aren't loosing anything
                    */
                    state.setlValue(node.getParent()->getId(), member);
                    toStack = *member;
                }
                if (mayPushToStack)
                    state.pushDefinition(toStack);
            } else if (Common::getIsTypeDeclaration(*node.getRefersTo()) || Common::getIsPackage(*node.getRefersTo())) {
                /**
                *	We have something like "com.apache" or A.B
                */
            } else if (Common::getIsMethodDeclaration(*node.getRefersTo())) {
                /**
                *	We have a normal method referred to at the rhs of a field access: Common::getIsNormalMethod(*node.getRefersTo()) is true
                *	We are also handling here the AnnotationTypeElements
                *	Nothing to do
                */
                if (Common::getIsIdentifier(*leftOperand)) {
                    expr::Identifier& leftId=dynamic_cast<expr::Identifier&>(*leftOperand);
                    if (!dynamic_cast<struc::MethodDeclaration&>(*node.getRefersTo()).getIsStatic() && !Common::getIsTypeDeclaration(*leftId.getRefersTo())) {
                        /**
                        *	If we have a non-static method call, we must push this object....but we are not doing it, as it must already be on the top
                        */
                        //state.pushDefinition(state.popDefinition());
                    }
                } else {
                    /**
                    *	LHS is not an identifier, for example "new String().toString()";
                    */
                    //state.pushDefinition(state.popDefinition());
                }
            } else {
                /**
                *	Donno what this could be
                */
                throw SymbolicColumbusException("Should not be happenning");
            }
        } else {

            /**
            *	The case when we neither have a field access nor method invocation
            */
            if (node.getRefersTo()==NULL) {
                /**
                *	It refers to something that is out of current codebase. For example: BasicConfigurator class of apache.log4j
                *	We don't even know its type
                */
                if (mayPushToStack)
                    state.pushDefinition(DefinitionFactory::createSymbol(SymbolicTypesPreVisitor::getErrorTypeId(), engine));
                return;
            }
            refersTo = node.getRefersTo()->getId();

            base::Base *refers = factory.getPointer(refersTo);
            if (Common::getIsMethodDeclaration(*refers)) {
                if (!dynamic_cast<struc::MethodDeclaration&>(*node.getRefersTo()).getIsStatic()) {
                    /**
                    *	If we have a non-static method call, we must push this object....but we are not doing it, as it must already be on the top
                    */
                    if (mayPushToStack)
                        state.pushDefinition(state.getThizObject());
                }
            } else if (Common::getIsTypeDeclaration(*refers) || Common::getIsPackage(*refers)) {
                /**
                *	We have a reference to a package, for example "com"
                *	We don't do anything at this point
                */			
                
            } else if (Common::getIsVariableDeclaration(*refers)) {

                    /**
                    *	Identifier refers to a variable, e.g. local variable
                    */
                base::Base& refersToNode = *node.getRefersTo();
                bool interfaceMember=false;
                bool enumConstant=false;
                if (refersToNode.getParent() != NULL && Common::getIsInterfaceDeclaration(dynamic_cast<base::Base&>(*refersToNode.getParent()))) {
                    /**
                    *	We have a member of an interface...in this case all the member variables are static and final by definition
                    */
                    interfaceMember=true;
                }
                if (Common::getIsEnumConstant(*node.getRefersTo())) {
                    /**
                    *	We have an enum constant at this point which does not really differ from a static final variable
                    */
                    enumConstant=true;
                }

                SmartDefinitionProxy member;
                bool isMemberVariable = findTypeDeclarationForMember(refersTo) != 0;
                bool inConditional = false;

                SmartDefinition toStack;
                if (isMemberVariable) {
                    /**
                    *	Variable is a member of some class, it it is not a local variable
                    */
                    struc::VariableDeclaration& variableNode = dynamic_cast<struc::VariableDeclaration&>(*refers);
                    if (variableNode.getIsStatic() || interfaceMember || enumConstant) {
                        Address address=state.getAddressOfLocal(refersTo);
                        member = state.getObjectByAddress(address);
                        /**
                        *	We are referring to a static variable...
                        */
                        if (member->isNull()) {
                            /**
                            *	...that has not been seen yet
                            */
                            if (variableNode.getIsFinal() || interfaceMember || enumConstant) {
                                /**
                                *	Initializing a static final variable
                                */

                                execute(variableNode.getId());
                                if (variableNode.getIsFinal()) {
                                    base::Base* memberClass = variableNode.getParent();
                                    if (Common::getIsClass(*memberClass)) {
                                        executeStaticBlocks(memberClass);
                                    }
                                }
                                Address address=state.getAddressOfLocal(refersTo);
                                member = state.getObjectByAddress(address);
                            }
                            else {
                                /**
                                *	Initializing a static non-final variable
                                */
                                if (Common::getIsVariable(*refers)) {
                                    struc::Variable* var = dynamic_cast<struc::Variable*>(refers);
                                    if (var->getInitialValue() == nullptr || Common::getIsNullLiteral(*var->getInitialValue())) {
                                        nonInited = true;
                                        *member = DefinitionFactory::createReference(Reference::default_value, node.getType() != NULL ? node.getType()->getId() : 0, engine);
                                    }
                                }
                                if (!nonInited){
                                    *member = DefinitionFactory::createSymbol((node.getType() != NULL ? node.getType()->getId() : 0), engine);
                                }
                                
                            }
                        }
                    } else {
                        /**
                        *	Non-static class member variable
                        */
                        member = getClassMemberVariable(state.getThizObject(), refersTo);
                    }
                } else {
                    /**
                    *	Identifier refers to a local variable or a parameter
                    */
                    Address address=state.getAddressOfLocal(refersTo);
                    member = state.getObjectByAddress(address);

                    if (!member->isNull()) { //if(identifier)?
                        auto par = node.getParent();

                        enum { DEFAULT, FOUND_PARENTHISED_EXPR} status;

                        status = DEFAULT;

                        while (par != nullptr) {
                            if (Common::getIsIf(*par)) {
                                if (status == FOUND_PARENTHISED_EXPR) {
                                    inConditional = true;
                                }
                                break;
                            }
                            else if (Common::getIsParenthesizedExpression(*par)) {
                                status = FOUND_PARENTHISED_EXPR;
                            }
                            else if (/*Common::getIsMethodDeclaration(*par) || Common::getIsInfixExpression(*par) ||*/ Common::getIsExpression(*par)) {
                                break;
                            }
                            else {
                                status = DEFAULT;
                            }
                            par = par->getParent();
                        }
                    }

                   
                }
                        
                if ((member && !member->isNull()) || (member && nonInited)) {
                    /**
                    *	If we found the identifier in the proxy tree, we will push it to the stack
                    *	Otherwise we push a new SmartDefinition that did not exist earlier
                    */
                    state.setlValue(node.getId(), member);
                    toStack = *member;
                } else {
                    *member = DefinitionFactory::createSymbol((node.getType() != NULL ? node.getType()->getId() : 0), engine);
                    toStack = *member;
                }
                if (inConditional && toStack->getIsSymbol()) {
                    if (toStack->isReference()) {
                        const Reference* reff = dynamic_cast<const Reference*>(toStack.get());
                        SmartDefinition sd = Reference::unbox(*reff, engine);
                        if (sd->isBooleanValueDefinition() && sd->getIsSymbol()) {
                            const SymbolDefinition* sym = dynamic_cast<const SymbolDefinition*>(sd.get());
                            toStack = sym->conditionalExpr();
                        }
                    }
                    else {
                        const SymbolDefinition* sym = dynamic_cast<const SymbolDefinition*>(toStack.get());
                        toStack = sym->conditionalExpr();
                    }

                    
                }
                if (mayPushToStack)
                    state.pushDefinition(toStack);
            } else if (Common::getIsPackage(*refers)) {
                /**
                *	We have a package identifier....nothing to do
                */
            } else {
                /**
                *	Donno what this could be. This can also happen due to 
                */
                throw SymbolicColumbusException("Should not be happenning");
            }
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::EnumConstant& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;

        State& state = engine.getCurrentState();
        Address address = state.getAddressOfLocal(node.getId());
        Memory& memory = state.getMemory();
        *(memory[address]) = SmartDefinition(new Object(node.getType()->getType()->getId(), true, address, engine));
        //string str = node.getName();
        DefinitionFactory::createReference(address, node.getType()->getType()->getId(), engine);
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::Variable& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
//        NodeId id = node.getId();
        State& state = engine.getCurrentState();

        expr::Expression* expr = node.getInitialValue();
        if (findTypeDeclarationForMember(node.getId()) != 0) {
            /**
            * We have a member variable at this point
            */
            SmartDefinitionProxy member;
            SmartDefinition init;

            bool interfaceMember=false;
            bool enumConstant=false;
            bool isAnnotationType = false;
            if ( node.getParent() != NULL && Common::getIsInterfaceDeclaration(*node.getParent()) ) {
                /**
                *	We have a member of an interface...in this case all the member variables are static and final by definition
                */
                interfaceMember=true;
            }
            if (Common::getIsEnumConstant(node)) {
                /**
                *	We have an enum constant at this point which does not really differ from a static final variable
                */
                enumConstant=true;
            }
            if ( node.getParent() != NULL && Common::getIsAnnotationType(*node.getParent()) ) {
                isAnnotationType = true;
            }

            if (node.getIsStatic() || interfaceMember || enumConstant || isAnnotationType) {
                /**
                *	We are dealing with a static member variable
                */
                if (!node.getIsFinal() && !interfaceMember && !enumConstant && !isAnnotationType) 
                    throw SymbolicColumbusException("Visiting a non-final static variable. This should not be happenning");
                if (expr==NULL) {
                    /**
                    *	This can only happen if we don't have the code of the particular class....reflection does not build in initializers in this case
                    */
                    init = DefinitionFactory::createSymbol((node.getType() != NULL ? node.getType()->getType()->getId() : 0), engine);
                } else if (Common::getIsLiteral(*expr) || Common::getIsIdentifier(*expr)) {
                    /**
                    *	We are doing the initialization only if we deal with literals or variables....we are not dealing with NewClass-es (redmine issue  #178)
                    */
                    execute(expr->getId());
                    init = state.popDefinition();
                } 
                //the member is referrenced directly by its id from the current state, as it is static
                member=state.getObjectByAddress(state.getAddressOfLocal(node.getId()));
            } else {
                /**
                *	We have a non-static class member variable, here
                */
                SmartDefinition thizObject = state.getThizObject();
                
                member = getClassMemberVariable(thizObject, node.getId());
                if (expr != NULL) {
                    /**
                    *	We have an initializer for the current non-static member variable. It has already been executed when the class was instantiated
                    */
                    init = state.popDefinition();
                }
            }
            if (!init) {
                /**
                *	For some reason we were not able to obtain an init value for the variable
                */
                NodeId typeId = node.getType()->getType()->getId();
                init = DefinitionFactory::createSymbol(typeId, engine);
            }
            *member = init;
        } else {
            /**
            *	We have a local variable
            */
            
            if (expr != NULL) {
                SmartDefinition init;
                try {
                    init = state.popDefinition();
                }
                catch (const SymbolicColumbusException& ex) {
                    init = DefinitionFactory::createSymbol(node.getType()->getType()->getId(), engine);
                }
                getLocalVariable(node, init);
                
                //*proxy=init;
            } else {
                SmartDefinitionProxy proxy = getLocalVariable(node, nullptr);
                *proxy = DefinitionFactory::createSymbol(node.getType()->getType()->getId(), engine);//DefinitionFactory::createDefaultInitializedDefinition(node.getType()->getType()->getId(), engine);
            }
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::Parameter& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        //NodeId id = node.getId();
        State& state = engine.getCurrentState();

        type::Type& paramType = (node.getType()->getType() != NULL)
                                    ? *node.getType()->getType()
                                    : dynamic_cast<type::Type&>(factory.getRef(SymbolicTypesPreVisitor::getObjectTypeId()));

        // TODO: enhanced for loop not handled
        if (Common::getIsEnhancedFor(*node.getParent())) {
            *state.getObjectByAddress(state.getAddressOfLocal(node.getId())) = DefinitionFactory::createSymbol(paramType.getId(), engine);
            return;
        }

        if (state.getCallDepth()==0) {
            /**
            *	When we are at the top of the call stack, we need to assign symbols to parameters
            */

            // if the type of the parameter is type variable (thus the concrete type cannot be determined), we create symbol with Object type
            NodeId type = Common::getIsTypeVariable(paramType)
                ? SymbolicTypesPreVisitor::getObjectTypeId()
                : paramType.getId();

            *state.getObjectByAddress(state.getAddressOfLocal(node.getId())) = DefinitionFactory::createSymbol(type, engine);
        } else {
            /**
            *	Otherwise we'll pop arguments from the stack
            */
            if (!node.getIsVarargs()) {
                /**
                *	We have a non-vararg parameter
                */
                // check whether param is an Enum constructor parmeter
                // need to check because the Enum class constructor has 2 implicit params that are
                // not in the CFG, thus aren't visited and pushed onto the stack
                bool isEnumConstructorParam = false;
                if (Common::getIsMethod(*node.getParent())) {
                    struc::Method *method = dynamic_cast<struc::Method*>(node.getParent());
                    if (method->getName().compare("Enum") == 0) {
                        isEnumConstructorParam = true;
                    }
                }
                if (isEnumConstructorParam) {
                    // use symbol because its not in the CFG, thus not pushed onto the stack
                    *state.getObjectByAddress(state.getAddressOfLocal(node.getId()))=DefinitionFactory::createSymbol(paramType.getId(), engine);
                } else {
                    // normal parameter
                    SmartDefinition arg=state.popDefinition();
                    if (arg->getType() == SymbolicTypesPreVisitor::getObjectTypeId() && paramType.getId() != SymbolicTypesPreVisitor::getObjectTypeId()) {
                        /*
                         * It is possible that the type of the argument was error type or type variable. In such case we set Object type.
                         * The sourcecode may make more punctual the type by the type of the parameters, e.g.:
                         * 
                         *  class A<T> {
                         *    void method(T param) { ... }
                         *  }  
                         * 
                         *  class B extends A<Integer> {
                         *    @Override
                         *    void method(Integer param) { ... } 
                         *  }
                         *
                         *  class C<T> {
                         *     A<T> member;
                         *     ...
                         *     void m() {
                         *       T t = new T();
                         *       member.method(t); // here method can invoke A<T>.method(T) and B.method(Integer) too where Object (actually T, which is unkonwn) need to cast to Integer
                         *     }
                         *  }
                         *
                         * TODO: maybe need to handle in case of vararg too. It would be also necessary to chack that the type of the argument was
                         * set to Object by hand (in case of ErrorType or TypeVariable), but in other cases its a compilation error.
                         */
                        SmartDefinition castedArg = arg->castToReference(paramType.getId());
                        *state.getObjectByAddress(state.getAddressOfLocal(node.getId())) = castedArg;
                    } else {
                        auto cpy = DefinitionFactory::copy(arg, engine);
                        if (cpy->getIsSymbol()) {
                           ConstraintSet dependencies = engine.getConstraintBuilder()->makeDependenciesSimple(*arg.get());
                           auto expr = engine.getConstraintBuilder()->makeBoolExpr(*cpy, *arg, iokEqualTo);
                           Constraint* assignmentConstraint = engine.getConstraintBuilder()->makeConstraint(expr);
                           dependencies.insert(assignmentConstraint);
                           cpy->setDependencies(dependencies);
                           state.addNewCondition(assignmentConstraint);
                        }
                        *state.getObjectByAddress(state.getAddressOfLocal(node.getId())) = cpy;
                    }
                }
            } else {
                /*
                *	We have a vararg parameter...it's type should already be an array type
                */
                columbus::NodeId topCall=state.topCall();

                base::Base* base = factory.getPointer(topCall);
                unsigned int argumentListSize=0;

                /**
                *	First we'll determint the number of arguments at the point when the call occurred
                */
                if (Common::getIsNewClass(*base)) {
                    expr::NewClass* newClass = dynamic_cast<expr::NewClass*>(base);
                    argumentListSize=newClass->getArgumentsSize();
                } else if (Common::getIsMethodInvocation(*base)) {
                    expr::MethodInvocation& invocation = dynamic_cast<expr::MethodInvocation&>(*base);
                    argumentListSize=invocation.getArgumentsSize();
                }

                /**
                *	The number of parameters at the other side of the call
                */
                struc::NormalMethod* decl=dynamic_cast<struc::NormalMethod*>(node.getParent());
                unsigned int parameterListSize=decl->getParametersSize();

                /**
                *	Creating the array that will hold the arguments
                */
                SmartDefinition arrayRef=DefinitionFactory::createArray(paramType.getId(), DefinitionFactory::createInt(argumentListSize-parameterListSize+1, engine), false, engine);
                Array& rawArray=Array::getRawArray(arrayRef, engine);

                //for (unsigned int i=0; i<argumentListSize-parameterListSize+1; i++) {
                for (int i=argumentListSize-parameterListSize; i>=0; --i) {
                    /**
                    *	Filling the vararg array with elements
                    */
                    Address address=rawArray.getArrayElementAddress(DefinitionFactory::createInt(i, engine));
                    *state.getObjectByAddress(address)=state.popDefinition();
                }

                //	Making the parameter to hold the reference to the array
                *state.getObjectByAddress(state.getAddressOfLocal(node.getId()))=arrayRef;
            }
        }		
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::Interface& node, bool callVirtualBase) {
    }

    // Operators
    void SymbolicExecutor::visit(const columbus::java::asg::expr::PostfixExpression& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;

        State& state = engine.getCurrentState();
        SmartDefinition def = state.topDefinition();
        NodeId operandId=node.getOperand()->getId();
        SmartDefinitionProxy lValueProxy;

        if (state.haslValue(operandId)) {
            lValueProxy = state.getlValue(operandId);
            state.setlValue(node.getId(), lValueProxy);
        } else 
            throw SymbolicColumbusException("Should not be happenning");

        SmartDefinition result;
        PostfixOperatorKind kind = node.getOperator();
        if (kind == pookIncrement) {
            result = def->increment();
        } else if (kind == pookDecrement) {
            result = def->decrement();
        } else
            throw SymbolicColumbusException("Unknown postfix operator kind");

        //engine.getCurrentState().pushDefinition(result);
        if (kind == pookDecrement || kind == pookIncrement) {
            *lValueProxy = result;
            state.setlValue(node.getId(), lValueProxy);
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::PrefixExpression& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;

        State& state = engine.getCurrentState();
        SmartDefinition def = state.popDefinition();
        PrefixOperatorKind kind = node.getOperator();
        NodeId operandId=node.getOperand()->getId();
        SmartDefinitionProxy lValueProxy;

        if (state.haslValue(operandId)) {
            lValueProxy = state.getlValue(operandId);
            state.setlValue(node.getId(), lValueProxy);
        } else if (kind == peokDecrement || kind == peokIncrement)
            throw SymbolicColumbusException("Should not be happenning");

        SmartDefinition result;
        
        if (kind == peokPlus) {
            result = def->prePlus();
        } else if (kind == peokMinus) {
            result = def->preMinus();
        } else if (kind == peokNot) {
            result = def->negate();
        } else if (kind == peokComplement) {
            result = def->complement();
        } else if (kind == peokIncrement) {
            result = def->increment();
        } else if (kind == peokDecrement) {
            result = def->decrement();
        } else
            throw SymbolicColumbusException("Unknown prefix operator kind");

        engine.getCurrentState().pushDefinition(result);
        if (kind == peokDecrement || kind == peokIncrement) {
            *lValueProxy=result;
        }
    }

    SmartDefinition SymbolicExecutor::assign(SmartDefinition lhs, SmartDefinition rhs) {
        State& state = engine.getCurrentState();
        Address address=lhs->addressOf();

        if (lhs->getIsSymbol() || rhs->getIsSymbol()) {
            return SymbolDefinition::makeSymbolDefinitionForAssignment(*lhs, *rhs, askAssign, engine);
        }

        /**
        *	At this point we may need to cast the rhs to lhs
        */
        return *(*state.getObjectByAddress(address)=rhs);
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::Assignment& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;

        State& state = engine.getCurrentState();
        SmartDefinition right = state.popDefinition();
        SmartDefinition left = state.popDefinition();
        NodeId leftOperandId=node.getLeftOperand()->getId();
        SmartDefinitionProxy lValueProxy;

        
        if (state.haslValue(leftOperandId)) {
            lValueProxy = state.getlValue(leftOperandId);
            state.setlValue(node.getId(), lValueProxy);
        } else {
            /**
            *	This should only happen if we are inside an annotation, e.g.  @Resource(name = "backendDatasource"), as this is currently not handled
            *	First we'll find out if we are inside an annotation or not
            */
            throw SymbolicColumbusException("Should not be happenning");
        }


        

        // at this point either we are inside an annotation or we have a valid lValue

        SmartDefinition result;


        // Checking for boxing
        NodeId toTypeId = 0;
        if (SymbolicTypesPreVisitor::isBoxing(left->getType(), right->getType(), toTypeId)) {
            result = DefinitionFactory::createSymbol(toTypeId, engine);

        } else {
            AssignmentOperatorKind opKind = node.getOperator();
            switch (opKind) {
                case askAssign:
                    result = assign(left, right); break;

                case askPlusAssign:
                    result = assign(left, left->plus(*right)); break;

                case askMinusAssign:
                    result = assign(left, left->minus(*right)); break;

                case askTimesAssign:
                    result = assign(left, left->times(*right)); break;

                case askDivideAssign:
                    // Division by zero?
                    if (isZero(right)) {
                        if(state.fireDivisionByZero(node.getId()))
                            throw SymbolicColumbusException("Division by zero! Execution does not continue on this path!");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                    }
                    result = assign(left, left->divide(*right));
                    break;

                case askRemainderAssign:
                    // Division by zero?
                    if (isZero(right)) {
                        if(state.fireDivisionByZero(node.getId()))
                            throw SymbolicColumbusException("Division by zero! Execution does not continue on this path!");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                    }
                    result = assign(left, left->remainder(*right));
                    break;

                case askAndAssign:
                    result = assign(left, left->bitwiseAndLogicalAnd(*right)); break;

                case askOrAssign:
                    result = assign(left, left->bitwiseAndLogicalOr(*right)); break;

                case askXorAssign:
                    result = assign(left, left->bitwiseAndLogicalXor(*right)); break;

                case askLeftShiftAssign:
                    result = assign(left, left->leftShift(*right)); break;

                case askSignedRightShiftAssign:
                    result = assign(left, left->signedRightShift(*right)); break;

                case askUnsignedRightShiftAssign:
                    result = assign(left, left->unsignedRightShift(*right)); break;

                default:
                    throw SymbolicColumbusException("Unknown assignment operator kind");
                    break;
            }
        }
       

        engine.getCurrentState().pushDefinition(result);
        
        if (lValueProxy) {
            *lValueProxy=result;  
        } 
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::InfixExpression& node, bool callVirtualBase) {
        //NodeId id = node.getId();
        if (AsgUtils::isInsideAnnotation(node)) return;

        State& state = engine.getCurrentState();
        SmartDefinition result;
        SmartDefinition right=state.popDefinition();
        SmartDefinition left=state.popDefinition();
        

        bool isNull = false;
        

        if (!isNull) {
            InfixOperatorKind kind = node.getOperator();
            if (kind == iokPlus) {
                result = left->plus(*right.get());

            } else if (kind == iokMinus) {
                result = left->minus(*right.get());

            } else if (kind == iokTimes) {
                result = left->times(*right.get());

            } else if (kind == iokDivide) {
                //Division by zero?
                if (isZero(right)) {
                    if(state.fireDivisionByZero(node.getId()))
                        throw SymbolicColumbusException("DivisionByZeroEyception found! Execution does not continue on this path.");
                    else
                        throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                } else {
                    result = left->divide(*right.get());
                }
            } else if (kind == iokRemainder) {
                //Division by zero?
                if (isZero(right)) {
                    if(state.fireDivisionByZero(node.getId()))
                        throw SymbolicColumbusException("DivisionByZero found! Execution does not continue on this path.");
                    else
                        throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                } else {
                    result = left->remainder(*right.get());
                }
            } else if (kind == iokLeftShift) {
                result = left->leftShift(*right.get());

            } else if (kind == iokSignedRightShift) {
                result = left->signedRightShift(*right.get());

            } else if (kind == iokUnsignedRightShift) {
                result = left->unsignedRightShift(*right.get());

            } else if (kind == iokBitwiseAndLogicalAnd) {
                result = left->bitwiseAndLogicalAnd(*right.get());

            } else if (kind == iokBitwiseAndLogicalOr) {
                result = left->bitwiseAndLogicalOr(*right.get());

            } else if (kind == iokBitwiseAndLogicalXor) {
                result = left->bitwiseAndLogicalXor(*right.get());

            } else if (kind == iokLessThan) {
                result = left->less(*right.get());
            } else if (kind == iokGreaterThan) {
                    result = left->greater(*right.get()); 
            } else if (kind == iokLessThanOrEqualTo) {
                    result = left->lessThanOrEqualTo(*right.get()); 
            } else if (kind == iokGreaterThanOrEqualTo) {
                    result = left->greaterThanOrEqualTo(*right.get()); 
            } else if (kind == iokEqualTo) {
                    result = left->equals(*right.get()); 
            } else if (kind == iokNotEqualTo) {
                    result = left->notEquals(*right.get()); 
            } else if (kind == iokConditionalAnd) {
                result = left->conditionalAnd(*right.get());
            } else if (kind == iokConditionalOr) {
                result = left->conditionalOr(*right.get());
            }
        }
        state.pushDefinition(result);
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::NewClass& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        //NodeId id = node.getId();
        struc::NormalMethod* constructor=node.getConstructor();
        if (constructor==NULL) {
            /**cpy
            *	We are getting back from a constructor invocation which actually did not even happen
            *	as we don't have the reference to the called constructor...we may need to put something on the stack
            *	We are not loosing anything if we put something on the stack even if the return type would have been void
            */
            State& state = engine.getCurrentState();

            //first we pop something that is always put on the top of stack when refersTo is NULL
            //state.popDefinition();

            //we need to pop the arguments of the call
            for (unsigned int i=0; i<node.getArgumentsSize(); i++)
                state.popDefinition();

            //than we place something as a return value...provided that we can have one
            state.pushDefinition(DefinitionFactory::createSymbol(node.getType() != NULL ? node.getType()->getId() : SymbolicTypesPreVisitor::getObjectTypeId(), engine));
           
        } else {
           /**
            *	Otherwise, the returned object is already on the stack
            */
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::NewArray& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;

        State& state = engine.getCurrentState();
        SmartDefinition topArrayReference;

        // Get the array properties
        type::Type *arrayType = NULL;
        columbus::java::asg::Factory::TurnFilterOffSafely sfact(factory);
        if (node.getType() != NULL) {
            arrayType = node.getType();
        }

        unsigned int arrayDimensionSize = node.getDimensionsSize();
        unsigned int arrayInitializerSize = node.getInitializersSize();

        if (arrayDimensionSize == 0) {
            SmartDefinition arrayLength = DefinitionFactory::createInt(arrayInitializerSize, engine);

            // Don't need to check for negative array size, because of initializer is always >= 0
            if (arrayType != NULL) {
                // Create an ArrayValueDefinition and add a heap object
                topArrayReference = DefinitionFactory::createArray(arrayType->getId(), arrayLength, arrayInitializerSize > 0, engine);

                type::Type& componentType = *dynamic_cast<type::ArrayType*>(arrayType)->getComponentType();

                // Assign the initial values
                for (unsigned int i = arrayInitializerSize; i > 0; --i) {
                    SmartDefinition initializer = state.popDefinition();
                    if (SymbolicTypesPreVisitor::isPrimitiveTypeExcpetNull(initializer->getType()) 
                            && SymbolicTypesPreVisitor::isReferenceType(componentType.getId())) {
                        // need to box primitive initial value
                        // TODO: save and handle the value into the boxed object, see redmine issue #294
                        initializer = DefinitionFactory::createObject(componentType.getId(), false, engine);
                    }
                    SmartDefinitionProxy arrayProxy = getArrayElement(topArrayReference, DefinitionFactory::createInt(i-1, engine));
                    *arrayProxy = initializer;
                }

            } else {
                topArrayReference = DefinitionFactory::createSymbol(0, engine);
            }

        } else {

            std::stack<SmartDefinition> arrayLengthSDStack;
            std::stack<int> arrayLengthStack;
            for (unsigned int i = 0; i < arrayDimensionSize; i++) {
                int length = -1;
                SmartDefinition dim = state.popDefinition();
                if (dim->isIntValueDefinition()) {
                    const IntValueDefinition& fivd = static_cast<const IntValueDefinition&>(*dim.get());
                    length = fivd.getValue();
                } else if (dim->getIsSymbol()) {
                    //length = DefinitionFactory::createInt(engine);
                }

                // !!!TODO!!! QUICKFIX!!!, see redmine issue 418
                // handling situations like: final byte[][] tooLarge = new byte[1000000000][1000000000];
                // create symbol length array insted of the concrete huge value
                if (length >= 10000000) {
                    length = -1;
                    dim = DefinitionFactory::createInt(engine);
                }

                arrayLengthSDStack.push(dim);
                arrayLengthStack.push(length);
            }

            try {
                // Get the arrayType of the array
                if (arrayType != NULL) {
                    std::queue<type::Type*> arrayTypesQueue;
                    arrayTypesQueue.push(arrayType);
                    type::Type *currentType = arrayType;
                    SymbolicTypesPreVisitor::TypesForSymbolic currentComponentType = SymbolicTypesPreVisitor::getType(currentType->getId());
                    for (unsigned int i = 0; i < arrayDimensionSize; i++) {

                        NodeId componentTypeId = 0;
                        if (currentComponentType.typeType == SymbolicTypesPreVisitor::TypesForSymbolic::ARRAY_TYPE) {
                            componentTypeId = currentComponentType.addInf.ArrayType.componentTypeId;
                        }

                        if (componentTypeId == 0) {
                            return;
                        }

                        currentType = dynamic_cast<type::Type*>(factory.getPointer(componentTypeId));
                        arrayTypesQueue.push(currentType);
                        currentComponentType = SymbolicTypesPreVisitor::getType(currentType->getId());
                    }

                    // Create an ArrayValueDefinition and add a heap object
                    SmartDefinition firstArrayLengthSD = arrayLengthSDStack.top();
                    arrayLengthSDStack.pop();
                    int firstArrayLength = arrayLengthStack.top();
                    arrayLengthStack.pop();

                    // Check for negative array size
                    if (firstArrayLength < 0 && !firstArrayLengthSD->getIsSymbol()) {
                        if(state.fireNegativeArraySize(node.getId(), firstArrayLength))
                            throw SymbolicColumbusException("NegativeArraySizeException found! Execution does not continue on this path.");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                        /*type::Type *currentArrayType = arrayTypesQueue.front();
                        if (currentArrayType != NULL)
                            topArrayReference = DefinitionFactory::createSymbol(currentArrayType->getId(), engine);

                        else {
                            topArrayReference = DefinitionFactory::createSymbol(0, engine);
                        }*/

                    } else {

                        type::Type* currentArrayType = arrayTypesQueue.front();
                        arrayTypesQueue.pop();

                        if (firstArrayLength == -1 && firstArrayLengthSD->getIsSymbol()) {
                            topArrayReference = DefinitionFactory::createArray(currentArrayType->getId(), firstArrayLengthSD, true, engine, true);
                        }

                        else {
                            topArrayReference = DefinitionFactory::createArray(currentArrayType->getId(), firstArrayLengthSD, true, engine, false);
                        }

                        std::vector<SmartDefinition> mainArrayReferences;
                        mainArrayReferences.push_back(topArrayReference);

                        while (!arrayLengthStack.empty()) {
                            SmartDefinition nextArrayLengthSD = arrayLengthSDStack.top();
                            arrayLengthSDStack.pop();
                            int nextArrayLength = arrayLengthStack.top();
                            arrayLengthStack.pop();

                            // Check for negative array size
                            if (nextArrayLength < 0 && !nextArrayLengthSD->getIsSymbol()) {
                                if(state.fireNegativeArraySize(node.getId(), nextArrayLength))
                                    throw SymbolicColumbusException("NegativeArraySizeException found! Execution doues not continue on this path.");
                                else
                                    throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                                /*if (topArrayType != NULL)
                                    topArrayReference = DefinitionFactory::createSymbol(topArrayType->getId(), engine);
                                else {
                                    topArrayReference = DefinitionFactory::createSymbol(0, engine);
                                }
                                break;*/
                            }

                            if (nextArrayLength == 0) {
                                // Print out a warning
                            }

                            currentArrayType = arrayTypesQueue.front();
                            arrayTypesQueue.pop();
                            std::vector<SmartDefinition> tempSubArrayReferences;
                            for (int i = 0; i < firstArrayLength; i++) {
                                for (unsigned int j = 0; j < mainArrayReferences.size(); j++) {
                                    SmartDefinition subArrayReference = DefinitionFactory::createArray(currentArrayType->getId(), nextArrayLengthSD, true, engine, firstArrayLengthSD->getIsSymbol());
                                    tempSubArrayReferences.push_back(subArrayReference);
                                    SmartDefinition mainRef = mainArrayReferences[j];
                                    SmartDefinitionProxy arrayProxy = getArrayElement(mainRef, DefinitionFactory::createInt(i, engine));
                                    (*arrayProxy) = subArrayReference;
                                }
                            }


                            mainArrayReferences.clear();
                            mainArrayReferences = tempSubArrayReferences;
                            firstArrayLength = nextArrayLength;
                        }
                        
                        
                    }
                } else {
                    topArrayReference = DefinitionFactory::createSymbol(0, engine);
                }
            } catch (const std::bad_alloc&) {
                // happens when allocating a large array
                throw SymbolicColumbusException("Out of memory error when creating an array!");
            }
        }

        // Add to the stack the newArray
        state.pushDefinition(topArrayReference);
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::ArrayAccess& node, bool callVirtualBase) {
        State& state = engine.getCurrentState();
        SmartDefinition coord = state.popDefinition();
        SmartDefinition arrayRef = state.popDefinition();
        bool resDecl = checkMemberInitedAtDecl(node);
        bool resStatic = checkMemberInitedInStaticInitBlock(node, false);
        try {
            SmartDefinitionProxy proxy=getArrayElement(arrayRef, coord, resDecl, resStatic);
            
            state.setlValue(node.getId(), proxy);
            state.pushDefinition(*proxy);
        }
        catch (const SymbolicColumbusException& e) {
            if (string(e.what()) == "NullType") {
                state.fireNullPointerDereferenced(node.getId());
                throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
            }
            else {
                throw;
            }
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::FieldAccess& node, bool callVirtualBase) {
        //NodeId id = node.getId();
        // check if we inside an annotation
        if (AsgUtils::isInsideAnnotation(node)) return;

        expr::Expression * leftOperand=node.getLeftOperand();
        State &state = engine.getCurrentState();
        expr::Expression *rightOperand = node.getRightOperand();

        // need to handle EnumName.ENUM_CONSTANT separately
        // Thats because every time an EnumName is writen CFG generates an enum_init call
        // and actually the right side of the field access is a MethodInvocation. (Is it right?)
        if (Common::getIsIdentifier(*rightOperand)) {
            expr::Identifier *rightIdentifier = dynamic_cast<expr::Identifier*>(rightOperand);
            base::Named* rightRefersTo = rightIdentifier->getRefersTo();
            if (rightRefersTo != NULL && Common::getIsEnumConstant(*rightRefersTo)) {
                return;
            }
        }

        if (Common::getIsIdentifier(*rightOperand) && Common::getIsIdentifier(*leftOperand)) {
            /**
            *	We have identifiers on both sides
            */
            expr::Identifier *rightIdentifier = dynamic_cast<expr::Identifier*>(rightOperand);             
            expr::Identifier *leftIdentifier = dynamic_cast<expr::Identifier*>(leftOperand);     
            base::Named* refersTo=rightIdentifier->getRefersTo();
            if (refersTo==NULL) {
                /**
                *	This can happen, for example "array.length". In this case length does not refer to anything
                */
                // check for NPE
                base::Named* leftRefersTo = leftIdentifier->getRefersTo();
                if (leftRefersTo != nullptr && !Common::getIsTypeDeclaration(*leftRefersTo) && !Common::getIsPackage(*leftRefersTo)) {
                    if (node.getParent() && Common::getIsMethodInvocation(*node.getParent())) {
                        const expr::MethodInvocation& mi = dynamic_cast<const expr::MethodInvocation&>(*node.getParent());
                        for (auto it = mi.getArgumentsListIteratorBegin(); it!= mi.getArgumentsListIteratorEnd(); ++it) {
                            if (!state.isStackEmpty()) {
                                state.popDefinition();
                                }
                            }
                    }
                    if (!state.isStackEmpty()) {
                    SmartDefinition smartReference = state.topDefinition();
                    if (smartReference->isReference()) {
                        const Reference& reference = dynamic_cast<const Reference&>(*smartReference.get());
                        if (reference.isNull() && !runIsInitedChecks(leftOperand)) {

                            if(state.fireNullPointerDereferenced(node.getId()))
                                throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                            else
                                throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                        }
                    }
                }
                    
                }
            } else if (Common::getIsMethodDeclaration(*refersTo)) {
                // We don't need to do anything... this object is at the top of stack already
                struc::MethodDeclaration *method = dynamic_cast<struc::MethodDeclaration*>(refersTo);
                if (!method->getIsStatic() && !Common::getIsTypeDeclaration(*leftIdentifier->getRefersTo())) {
                    // check for NPE
                    SmartDefinition smartReference = state.topDefinition();
                    if (!smartReference->isReference()) {
                        if (smartReference->getIsSymbol()) {
                            throw SymbolicColumbusException("Cannot cast SmartDefinition to reference.");
                        }
                        else {
                            return;
                        }
                    }
                    const Reference& reference = dynamic_cast<const Reference&>(*smartReference.get());
                    if (!reference.getIsSymbol() && reference.isNull()) {
                        if (!runIsInitedChecks(leftOperand)) {
                            if(state.fireNullPointerDereferenced(node.getId()))
                                throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                            else
                                throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                        }
                    }
                }
            } else if (Common::getIsTypeDeclaration(*refersTo) || Common::getIsPackage(*refersTo)) {
                /**
                *	Nothing to do here....we'll pop the lhs when visiting this identifier
                */                
            } else if (Common::getIsVariableDeclaration(*refersTo)) {
                struc::VariableDeclaration& rhsVariableDecl=dynamic_cast<struc::VariableDeclaration&>(*refersTo);
                if (!rhsVariableDecl.getIsStatic() && !Common::getIsTypeDeclaration(*leftIdentifier->getRefersTo())) {
                    /**
                    *	If the variable is not a static one, we'll check for NPE
                    */
                    // checkfor NPE
                    SmartDefinition smartReference = state.topDefinition();
                    if (!smartReference->isReference()) throw SymbolicColumbusException("Cannot cast SmartDefinition to reference.");
                    const Reference& reference = dynamic_cast<const Reference&>(*smartReference.get());
                    if (!reference.getIsSymbol() && reference.isNull()) {
                        if (!runIsInitedChecks(leftIdentifier)) {
                            if(state.fireNullPointerDereferenced(node.getId()))
                                throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                            else
                                throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                        }
                    }
                }
            } else {
                throw SymbolicColumbusException("This should not be happenning!");
            }
        } else if ((Common::getIsMethodInvocation(*leftOperand) && Common::getIsIdentifier(*rightOperand)) ||
            (Common::getIsArrayAccess(*leftOperand) && Common::getIsIdentifier(*rightOperand)) ||
            (Common::getIsFieldAccess(*leftOperand) && Common::getIsIdentifier(*rightOperand))) {
            if (!state.isStackEmpty()) {      
                if (Common::getIsFieldAccess(*leftOperand) && Common::getIsIdentifier(*rightOperand)) {
                    expr::Identifier* rId = dynamic_cast<expr::Identifier*>(rightOperand);
                    if (rId && rId->getRefersTo()) {
                        if (Common::getIsPackage(*rId->getRefersTo()) || Common::getIsClass(*rId->getRefersTo())) {
                            return;
                        }
                    }
                }
                // checkfor NPE
                SmartDefinition smartReference = state.topDefinition();
                if (!smartReference->isReference()) throw SymbolicColumbusException("Cannot cast SmartDefinition to reference.");
                const Reference& reference = dynamic_cast<const Reference&>(*smartReference.get());
                if (!reference.getIsSymbol() && reference.isNull()) {
                    if (!runIsInitedChecks(leftOperand)) {
                        if(state.fireNullPointerDereferenced(node.getId()))
                            throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                    }
                }
            }
        } 
    
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::Conditional& node, bool callVirtualBase) {
        // At this point we have at least 3 definition on the stack: true/false value, and the condition. We remove the condtion.
        State& state = engine.getCurrentState();

        SmartDefinition push = state.popDefinition();
        state.popDefinition();
        state.pushDefinition(push);

    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::InstanceOf& node, bool callVirtualBase) {
        State& state = engine.getCurrentState();
        SmartDefinition operand = state.popDefinition();

        // check if operand is symbol
        if (operand->getIsSymbol()) {
            state.pushDefinition(DefinitionFactory::createSymbol(SymbolicTypesPreVisitor::getBooleanTypeId(), engine));
            return;
        }

        // Checking if operand is null
        if (operand->isReference()) {
            const Reference *def = dynamic_cast<const Reference*>(operand.get());
            if (def->isNull()) {
                state.pushDefinition(DefinitionFactory::createBoolean(false, engine));
                return;
            }
        }

        if (node.getTypeOperand()->getType() == NULL) throw SymbolicColumbusException("Missing instanceof type!"); // FIXME
        NodeId leftType = operand->getType();
        NodeId rightType = node.getTypeOperand()->getType()->getId();
        if (leftType == rightType || SymbolicTypesPreVisitor::isSuperType(rightType, leftType)) {
            state.pushDefinition(DefinitionFactory::createBoolean(true, engine));
        } else {
            state.pushDefinition(DefinitionFactory::createBoolean(false, engine));
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::TypeCast& node, bool callVirtualBase) {
        State& state = engine.getCurrentState();

        // operand should be a ReferenceValueDefinition or a PrimitiveDefinition
        SmartDefinition operand = state.popDefinition();

        type::Type *toType = node.getTypeOperand()->getType();

        if (toType == NULL) {
            throw SymbolicColumbusException("There is no 'toType' in TypeCast!");
        }

        if (Common::getIsByteType(*toType)) {
            state.pushDefinition(operand->castToByte());
        } else if (Common::getIsCharType(*toType)) {
            state.pushDefinition(operand->castToChar());
        } else if (Common::getIsShortType(*toType)) {
            state.pushDefinition(operand->castToShort());
        } else if (Common::getIsIntType(*toType)) {
            state.pushDefinition(operand->castToInt());
        } else if (Common::getIsLongType(*toType)) {
            state.pushDefinition(operand->castToLong());
        } else if (Common::getIsFloatType(*toType)) {
            state.pushDefinition(operand->castToFloat());
        }
        else if (Common::getIsBooleanType(*toType)) {
            if (operand->getType() == SymbolicTypesPreVisitor::getBooleanTypeId()) {
                state.pushDefinition(operand->castToBoolean());
            }
            else {
                throw SymbolicColumbusException("Invalid cast to boolean");
            }
        }
        else if (Common::getIsDoubleType(*toType)) {
            state.pushDefinition(operand->castToDouble());
        } else if (Common::getIsScopedType(*toType) || Common::getIsArrayType(*toType)  || Common::getIsParameterizedType(*toType) || Common::getIsWildcardType(*toType)) {
            // check class cast exception
            if (toType->getId() != operand->getType() && SymbolicTypesPreVisitor::getNullTypeId() != operand->getType()) {
                if ((Common::getIsPrimitiveType(*toType) && SymbolicTypesPreVisitor::isBoxingType(operand->getType())) || (Common::getIsPrimitiveType(*factory.getPointer(operand->getType())) && SymbolicTypesPreVisitor::isBoxingType(toType->getId()))) {
                    NodeId boxingId = 0, primitiveId = 0;
                    if (Common::getIsPrimitiveType(*toType) && SymbolicTypesPreVisitor::isBoxingType(operand->getType())) {
                        primitiveId = toType->getId();
                        boxingId = operand->getType();
                    }
                    else if (Common::getIsPrimitiveType(*factory.getPointer(operand->getType())) && SymbolicTypesPreVisitor::isBoxingType(toType->getId())) {
                        boxingId = toType->getId();
                        primitiveId = operand->getType();
                    }
                    NodeId allowedClsId = SymbolicTypesPreVisitor::mapPrimitiveTypeToBoxingType(primitiveId);
                    if (allowedClsId != boxingId) {
                        if(state.fireClassCastException(node.getId()))
                            throw SymbolicColumbusException("ClassCastException found! Execution does not continue on this path.");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                    }
                }
                else if (!SymbolicTypesPreVisitor::isSuperType(toType->getId(), operand->getType()) && SymbolicTypesPreVisitor::getObjectTypeId() != toType->getId()) {
                    // not symbol and not castable
                    if (!operand->getIsSymbol()) {
                        if(state.fireClassCastException(node.getId()))
                            throw SymbolicColumbusException("ClassCastException found! Execution does not continue on this path.");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                    }
                    
                }
            } 
            state.pushDefinition(operand->castToReference(toType->getId()));
        } else
            throw SymbolicColumbusException("Should not be happenning");

    }

    // Literals
    void SymbolicExecutor::visit(const columbus::java::asg::expr::BooleanLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createBoolean(node.getBooleanValue(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::CharacterLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createChar(node.getCharValue(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::IntegerLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createInt(node.getIntValue(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::LongLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createLong(node.getLongValue(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::FloatLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createFloat(node.getFloatValue(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::DoubleLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createDouble(node.getDoubleValue(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::NullLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createReference(Address(0), SymbolicTypesPreVisitor::getNullTypeId(), engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::StringLiteral& node, bool callVirtualBase) {
        if (AsgUtils::isInsideAnnotation(node)) return;
        engine.getCurrentState().pushDefinition(DefinitionFactory::createObject(SymbolicTypesPreVisitor::getStringTypeId(), false, engine));
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::ClassLiteral& node, bool callVirtualBase) {
        /**
        *	Here we should have Class type for the type
        */
        if (AsgUtils::isInsideAnnotation(node)) return;
        NodeId typeId = node.getComponentType()->getType() != NULL 
            ? node.getComponentType()->getType()->getId() 
            : SymbolicTypesPreVisitor::getObjectTypeId();
        engine.getCurrentState().pushDefinition(DefinitionFactory::createObject(typeId, false, engine));
    }

    // Other expressions
    void SymbolicExecutor::visit(const columbus::java::asg::expr::This& node, bool callVirtualBase) {
        State& state = engine.getCurrentState();

        // Check if This is a descriptor - in this case we don't need to push thizObject onto the stack
    /*    if (node.getParent() != NULL && Common::getIsFieldAccess(*node.getParent())) {
            expr::FieldAccess *fa = dynamic_cast<expr::FieldAccess*>(factory.getPointer(node.getParent()->getId()));
            if (fa != NULL && fa->getRightOperand() != NULL && fa->getRightOperand()->getId() == node.getId()) {
                common::WriteMsg::write(CMSG_SYM_EXEC_THIS_FA_DESCRIPTOR, fa->getId());
                return;
            }
        }*/
        state.pushDefinition(state.getThizObject());
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::Super& node, bool callVirtualBase) {
        State& state = engine.getCurrentState();
        state.pushDefinition(state.getThizObject());
        isSuperVisited = true;
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::ParenthesizedExpression& node, bool callVirtualBase) {
        if (node.getParent() != nullptr && Common::getIsSwitch(*node.getParent())) {
            lastIsSwitch = true;
        }
        State& state=engine.getCurrentState();
        if (node.getOperand() != nullptr && state.haslValue(node.getOperand()->getId())) {
            if (node.getParent() != nullptr && Common::getIsIf(*node.getParent())) {
                SmartDefinitionProxy prx = state.getlValue(node.getOperand()->getId());
                SmartDefinition def = prx->operator columbus::symbolic::SmartDefinition & ();
                if (def->isReference()) {
                    const Reference* r = dynamic_cast<const Reference*>(def.get());
                    if (r->isNull() && !runIsInitedChecks(node.getOperand())) {
                        if(state.fireNullPointerDereferenced(node.getOperand()->getId()))
                            throw SymbolicColumbusException("NullPointerException found! Execution does not continue on this path.");
                        else
                            throw SymbolicColumbusException("Unsatisifiable path! Execution does not continue on this path.");
                    }
                }
            }
            
            state.setlValue(node.getId(), state.getlValue(node.getOperand()->getId()));
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::MethodInvocation& node, bool callVirtualBase) {
        //NodeId id = node.getId();
        expr::Expression* operand=node.getOperand();
        if (node.getInvokes()==NULL) {
            /**
            *	We are getting back from a method invocation which actually did not even happen
            *	as we don't have the reference to the called method...we may need to put something on the stack
            *	We are not loosing anything if we put something on the stack even if the return type would have been void
            */
            State& state = engine.getCurrentState();

            if (state.getEdgeKind() != State::RETURN_EDGE) {
                /*
                 * we reached a methodinvocation without going through a call. This coused by erronous sourcecode.
                 */
                throw SymbolicColumbusException("No call happend but it should have.");
            }

            if (!state.isStackEmpty()) {


                //first we pop something that is always put on the top of stack when refersTo is NULL
                state.popDefinition();

                //we need to pop the arguments of the call, because there are no parameter visits
                for (unsigned int i = 0; i < node.getArgumentsSize(); i++)
                    state.popDefinition();

                
            }
            if (!Common::getIsSuper(*operand)) {
                // than we place something as a return value...provided that we can have one
                // Somtimes there is no type edge in asg, using Object in this case
                NodeId type = node.getType() != NULL ? node.getType()->getId() : SymbolicTypesPreVisitor::getObjectTypeId();
                state.pushDefinition(DefinitionFactory::createSymbol(type, engine));
            }
            
        } else {
            /**
            *	Otherwise, the returned object is already on the stack
            */
        }
    }

    void SymbolicExecutor::visit(const columbus::java::asg::statm::Synchronized& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::SingleElementAnnotation& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::MarkerAnnotation& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::NormalAnnotation& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::statm::Block& node, bool callVirtualBase) {
    }
    void SymbolicExecutor::visit(const columbus::java::asg::statm::Assert& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::Class& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::Enum& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::struc::MethodGeneric& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::statm::Empty& node, bool callVirtualBase) {
    }

    void SymbolicExecutor::visit(const columbus::java::asg::expr::Erroneous& node, bool callVirtualBase) {
        throw SymbolicColumbusException("Error in ASG!");
    }

    
}} // end of namespaces
