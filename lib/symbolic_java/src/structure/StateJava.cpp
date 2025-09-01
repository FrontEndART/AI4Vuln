#include <map>

#include "cfg/inc/cfg.h"
#include "java/inc/java.h"

#include "symbolic/inc/structure/StateFactory.h"
#include "symbolic_java/inc/constraint/Z3Constraint.h"
#include "symbolic_java/inc/structure/StateJava.h"
//#include "symbolic_java/inc/definition/ReferenceValueDefinition.h"
#include "symbolic_java/inc/algorithms/SymbolicTypesPreVisitor.h"
#include "symbolic_java/inc/messages.h"
// Threading timeout
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace columbus::java::asg;

namespace columbus {
    namespace symbolic {

        StateJava::StateJava(const columbus::cfg::BasicBlock& bb, StateFactory& stateFactory) : State(bb, stateFactory), negatedConstraint(NULL) {
            /*context = stateFactory.getRootContext();
            // init heap
            SmartDefinitionProxy heap = (*context)[0];
            *heap = SmartDefinition(new ReferenceValueDefinition(Null(), SymbolicTypesPreVisitor::getNullTypeId()));*/
        }

        Solution StateJava::solve_wrapper(const string& accumulated, const std::set<std::shared_ptr<ConstraintSolverExpr>>& variables) {
            std::mutex m;
            std::condition_variable cv;
            Solution retValue;
            std::thread t([&cv, &retValue, this, &accumulated, &variables]()
                {
                    retValue = engine.getConstraintSolver()->solve(accumulated, variables);
                    cv.notify_one();
                });

            t.detach();

            {
                std::unique_lock<std::mutex> l(m);
                if (cv.wait_for(l, 20s) == std::cv_status::timeout)
                    throw std::runtime_error("Timeout");
            }

            return retValue;
        }

        std::string  StateJava::convertPathCondition() const{
            auto& deps = parent.getLastDependencies();
            std::string accumulated;


            int counter = 0;
            auto insertConditions = [&counter, &accumulated](const Constraint* c) {
                auto convertConstraint = [](const string& con) {
                    if (find(con.begin(), con.end(), ' ') != con.end()) {
                        string result("(");
                        result += con + ")";
                        return result;
                    }
                    return con;
                };
                if (counter++ == 0) {
                    //if (constraintSize > 1) {
                    accumulated = "(assert ";
                    accumulated += convertConstraint(*c);
                    accumulated += ")";
                    //}
                }
                else {
                    accumulated += " (assert ";
                    accumulated += convertConstraint(*c);
                    accumulated += ")";
                }
            };

            std::for_each(deps.second.begin(), deps.second.end(), insertConditions);
            std::for_each(pathCondition.begin(), pathCondition.end(), insertConditions);
            return accumulated;
        }

        StateJava::StateJava(State& parent, const columbus::cfg::BasicBlock& bb, int _edgeKind) : State(parent, bb, _edgeKind), negatedConstraint(NULL) {
            /*context = stateFactory.getProxyTree().createNewRootContext(SmartDefinition(), parent.getContext());
            SmartDefinitionProxy heap = (*context)[0];
            *heap = SmartDefinition(new ReferenceValueDefinition(Null(), SymbolicTypesPreVisitor::getNullTypeId()));*/

            // Add this to parent's children and set this weight and its siblings
            parent.addChild(this);
            recalculateWeight();
            try {
                buildPathCondition();
            }
            catch (const SymbolicColumbusException& e) {
                cout << e.what() << endl;
            }

            

//#define CONSTRAINT_BUILDING
#ifdef CONSTRAINT_BUILDING
            try {
                if (parent.getIsPcValid()) {
                    buildPathCondition();
                    
                    // solve and build back
                    if (parent.getBasicBlock().controlOutEdgesIterator().size() > 1) {
                        //std::set<Constraint*, ltDeref<Constraint*> >
                        string accumulated;

                        //todo ide beszurni a dependencyket
                        auto& deps = parent.getLastDependencies();
                        
                        
                        int counter = 0;
                        auto insertConditions = [&accumulated, &counter](const Constraint* c) {
                            auto convertConstraint = [](const string& con) {
                                if (find(con.begin(), con.end(), ' ') != con.end()) {
                                    string result("(");
                                    result += con + ")";
                                    return result;
                                }
                                return con;
                            };
                            if (counter++ == 0) {
                                //if (constraintSize > 1) {
                                accumulated = "(assert ";
                                accumulated += convertConstraint(*c);
                                accumulated += ")";
                                //}
                            }
                            else {
                                accumulated += " (assert ";
                                accumulated += convertConstraint(*c);
                                accumulated += ")";
                            }
                        };
                        for_each(deps.second.begin(), deps.second.end(), insertConditions);
                        for_each(pathCondition.begin(), pathCondition.end(), insertConditions);
                        Solution result;
                        bool timedout = false;
                        try {
                            result = engine.getConstraintSolver()->solve(accumulated, variables);//solve_wrapper(accumulated, variables);
                        }
                        catch (std::runtime_error& e) {

                            std::cout << e.what() << std::endl;
                            timedout = true;
                        }

                        if (timedout)
                            std::cout << "Timed out from outside." << std::endl;
                        if (result.hasSolution) {

                        }
                        else {
                            //setIsPcValid(false);
                            weight = 0.0;
                        }

                        //if (solution.hasSolution) {
                            //if (!solution.hasMoreSolutions) {
                                //for (auto::iterator it = solution.solutionMap.begin(); it != solution.solutionMap.end(); ++it) {
                                    //TODO: itt lehetne letarolni a konkret megoldast
                                    //(*(*context)[it->first]) = it->second;
                                    //common::WriteMsg::write(CMSG_SYM_CONST_DEFINITION_BUILT_BACK, it->first);
                                //}
                            //}
                       // } else {
                            //if (!solution.timeLimitReached) {
                            //	weight = 0.0;
                            //}
                    }
                }
                //}
            }
            catch (SymbolicColumbusException& ex) {
                //TODO hibauzenet
                //common::WriteMsg::write(CMSG_SYM_CONST_CANNOT_BUID_PC, ex.what(), stateId);
                isPcValid = false;
            }
#endif

        }

        StateJava::~StateJava() {
            delete negatedConstraint;

        }

        SmartDefinition StateJava::addNewHeapObject(SmartDefinition obj, columbus::NodeId referenceType) {
            /*if (common::WriteMsg::getMessageLevel() >= common::WriteMsg::mlDDebug) {
                stringstream ss0;
                if (obj.get() != NULL)
                    obj->operator<<(ss0);
                else
                    ss0 << "addNewHeapObject NULL";
                common::WriteMsg::write(CMSG_SYM_STATEJAVA_ADD_NEW_HEAPOBJECT, ss0.str().c_str());
            }
            // TODO
            SmartDefinition ref = SmartDefinition(new ReferenceValueDefinition(Reference(), referenceType));
            SmartDefinitionProxy heap = (*context)[0];
            const ReferenceValueDefinition *refDef = dynamic_cast<const ReferenceValueDefinition*>(ref.get());
            *(*heap)[refDef->operator columbus::symbolic::Reference()] = obj;
            return ref;*/
            return nullptr;
        }

        SmartDefinition StateJava::getHeapObject(SmartDefinition reference, columbus::NodeId nodeId) {
            /*if (common::WriteMsg::getMessageLevel() >= common::WriteMsg::mlDDebug) {
                stringstream ss0;
                if (reference.get() != NULL)
                    reference->operator<<(ss0);
                else
                    ss0 << "getHeapObject NULL";
                common::WriteMsg::write(CMSG_SYM_STATEJAVA_GET_HEAPOBJECT, ss0.str().c_str());
            }
            SmartDefinitionProxy heap = (*context)[0];
            const ReferenceValueDefinition *refDef = dynamic_cast<const ReferenceValueDefinition*>(reference.get());
            if (refDef != NULL && refDef->getValue().isNull()) {
                fireNullPointerDereferenced(nodeId);
                throw ExceptionalStateException();
            }
            return *(*heap)[refDef->operator columbus::symbolic::Reference()];*/
            return nullptr;
        }

        void StateJava::checkingNPE(SmartDefinition reference, NodeId nodeId) {
            if (isNullDerefenece(reference)) {
                fireNullPointerDereferenced(nodeId);
                //throw ExceptionalStateException();
            }
        }

        bool StateJava::isNullDerefenece(SmartDefinition reference) const {
            /*SmartDefinitionProxy heap = (*context)[0];
            const ReferenceValueDefinition *refDef = dynamic_cast<const ReferenceValueDefinition*>(reference.get());
            if (refDef != NULL && refDef->getValue().isNull()) {
                return true;
            }*/
            return false;
        }

        bool StateJava::hasheapObject(SmartDefinition reference) const {
            /*bool result = true;
            SmartDefinitionProxy heap = (*context)[0];
            const ReferenceValueDefinition *refDef = dynamic_cast<const ReferenceValueDefinition*>(reference.get());
            if (refDef == NULL)
                result = false;
            if (result) {
                if ((*heap)[refDef->operator columbus::symbolic::Reference()]->getOwner() == NULL) {
                    result = false;
                }
            }
            if (common::WriteMsg::getMessageLevel() >= common::WriteMsg::mlDDebug) {
                stringstream ss0;
                if (reference.get() != NULL)
                    reference->operator<<(ss0);
                else
                    ss0 << "hasheapObject NULL";
                common::WriteMsg::write(CMSG_SYM_STATEJAVA_HAS_HEAPOBJECT, ss0.str().c_str(), (int)result);
            }

            return result;*/
            return false;
        }


        void StateJava::buildPathCondition() {

            pathCondition = parent.getPathCondition();
            variables.insert(parent.getVariables().begin(), parent.getVariables().end());
            bool isFromSwitch = false;
            if (parent.getBasicBlock().nonExceptionalControlOutEdgeSize() > 1) { // if parent has more control-children
                NodeId constraintId = getLastBooleanExprId(parent, isFromSwitch);

                // what if LastBoolExpr is an Identifier? - Definition not created, so have to add the CsExpr to parent's state manually
                Factory& asgFactory = engine.getASGFactory();
                base::Base& constraintNode = asgFactory.getRef(constraintId);
                
                

                if (!topDefinition()->getIsSymbol() && topDefinition()->isBooleanValueDefinition()) {
                    const BooleanValueDefinition* lastCondition = dynamic_cast<const BooleanValueDefinition*>(topDefinition().get());
                    bool onTrue = onTrueBranch();
                    if (lastCondition->getValue() && !onTrue){
                        setWeight(0);
                    }
                    else if (!lastCondition->getValue() && onTrue) {
                        setWeight(0);
                    }
                }

                // if a CS expression built for the last boolean expression in parent
                else if (parent.getConstraintSolverExprs().find(constraintId) != parent.getConstraintSolverExprs().end()  /* && parent.getLastDependencies().first == constraintId*/) {

                    Constraint* lastCsExprConstraint;
                    if (onTrueBranch()) {
                        lastCsExprConstraint = engine.getConstraintBuilder()->makeConstraint(parent.getConstraintSolverExprs()[constraintId]);
                    }
                    else {
                        negatedConstraint = lastCsExprConstraint = engine.getConstraintBuilder()->makeNegatedConstraint(parent.getConstraintSolverExprs()[constraintId]);
                    }

                    // actual constraint
                    /*ConstraintSet& lastDependencies(parent.getLastDependencies().second);
                    ConstraintSet actualConstraints(lastDependencies.begin(), lastDependencies.end());
                    actualConstraints.insert(lastCsExprConstraint);*/

                    // add actualConstraints to PC (to parent's PC)
                    ConstraintSet actualConstraints;
                    actualConstraints.insert(lastCsExprConstraint);
                    pathCondition.insert(actualConstraints.begin(), actualConstraints.end());

                    // common::WriteMsg::write(CMSG_SYM_CONST_PC_BUILT, Constraint::constraints2String(pathCondition).c_str(), stateId);
                }
                else if (isFromSwitch) {
                    auto it = getBasicBlock().controlInEdgesIterator();
                    string strRep;
                    unsigned counter = 0;
                    while (it.hasNext()) {
                        auto l = it.next();
                        strRep = l->getLabel();
                        counter++;
                    }
                    
                    if (counter == 1 && strRep.length() > 0 && strRep != "default") {
                        SmartDefinition lastDefinition = parent.topDefinition();

                        if (!lastDefinition->getIsSymbol()) {
                            return;
                        }
                        Z3ConstraintExpression* z3ce = dynamic_cast<Z3ConstraintExpression*>(lastDefinition->getCsExpr().get());
                        shared_ptr<ConstraintSolverExpr> label = nullptr;
                        
                        if (z3ce->isByte()) {
                            try {
                                label = engine.getConstraintBuilder()->makeByteValue(stoi(strRep)); //TODO: hibakezelés
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeByteValue(0);
                            }
                        }
                        else if (z3ce->isString()) {
                            try{
                                label = engine.getConstraintBuilder()->makeStringValue(strRep);
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeStringValue("");
                            }
                        }
                        else if (z3ce->isDouble()) {
                            try {
                                label = engine.getConstraintBuilder()->makeDoubleValue(stod(strRep));
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeDoubleValue(0);
                            }
                        }
                        else if (z3ce->isFloat()) {
                            try{
                                label = engine.getConstraintBuilder()->makeFloatValue(stof(strRep));
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeFloatValue(0);
                            }
                        }
                        else if (z3ce->isInt()) {
                            try{
                                label = engine.getConstraintBuilder()->makeIntValue(stoi(strRep));
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeIntValue(0);
                            }
                        }
                        else if (z3ce->isShort()) {
                            try{
                                label = engine.getConstraintBuilder()->makeShortValue(stoi(strRep));
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeIntValue(0);
                            }
                        }
                        else if (z3ce->isLong()) {
                            try{
                                label = engine.getConstraintBuilder()->makeLongValue(stol(strRep));
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeLongValue(0);
                            }
                        }
                        else if (z3ce->isChar()) {
                            try{
                            label = engine.getConstraintBuilder()->makeCharValue(stoi(strRep));
                            }
                            catch (const std::exception& e) {
                                //label = engine.getConstraintBuilder()->makeCharValue(' ');
                            }
                        }


                       // produceLogicalSymbol(columbus::java::asg::InfixOperatorKind oper, const Definition & def, SymbolicEngine & engine) const {
                        if (label != nullptr) {
                            auto boolExpr = engine.getConstraintBuilder()->makeBoolExpr(lastDefinition->getCsExpr().get(), label.get(), iokEqualTo);
                            
                            auto lastCsExprConstraint = engine.getConstraintBuilder()->makeConstraint(boolExpr);

                            
                            ConstraintSet actualConstraints;
                            actualConstraints.insert(lastCsExprConstraint);
                            pathCondition.insert(actualConstraints.begin(), actualConstraints.end());
                        }

                        

                        
                        //lastCsExprConstraint = engine.getConstraintBuilder()->makeBoolExpr();
                        //shared_ptr<ConstraintSolverExpr> Z3ConstraintBuilder::makeBoolExpr(const Definition & left, const Definition & right, const InfixOperatorKind op, CastTypes cast)
                       // lastCsExprConstraint = engine.getConstraintBuilder()->makeConstraint(parent.getConstraintSolverExprs()[constraintId]);
                    }
                        
                }
                else if (Common::getIsIdentifier(constraintNode)) {

                    expr::Identifier& identifier = dynamic_cast<expr::Identifier&>(constraintNode);
                    NodeId refersTo;
                    if (identifier.getRefersTo() != NULL) {
                        refersTo = identifier.getRefersTo()->getId();
                    }
                    else {
                        columbus::java::asg::Factory::TurnFilterOffSafely sfact(asgFactory);
                        if (identifier.getRefersTo() != NULL) {
                            refersTo = identifier.getRefersTo()->getId();
                        }
                        else {
                            stringstream ss;
                            ss << "corresponding CS expression has not built for Identifier ";
                            ss << constraintId;
                            throw SymbolicColumbusException(ss.str());
                        }
                    }
                    //TODO: itt most nincs context
                    if (haslValue(refersTo)) {
                        SmartDefinitionProxy result = getlValue(refersTo);
                    }
                    else {
                        auto result = engine.getExecutor()->getLocalVariable(identifier);
                        if (!result->isNull()) {
                            const SmartDefinition& def = result->operator columbus::symbolic::SmartDefinition & ();
                            if (def->isReference() && def->getIsSymbol()) {
                                const Reference* r = dynamic_cast<const Reference*>(def.get());
                                auto val3 = r->unbox(*r, engine);
                                shared_ptr<ConstraintSolverExpr> label = val3->getCsExpr();
                                auto lastCsExprConstraint = engine.getConstraintBuilder()->makeConstraint(label);
                                ConstraintSet actualConstraints;
                                actualConstraints.insert(lastCsExprConstraint);
                                pathCondition.insert(actualConstraints.begin(), actualConstraints.end());
                            }

                        }
                    }

                }
                else {
                    stringstream ss;
                    ss << "corresponding CS expression has not built for NodeId ";
                    ss << constraintId;
                    throw SymbolicColumbusException(ss.str());
                }
            }
        }

        NodeId StateJava::getLastBooleanExprId(const State& state, bool& isFromSwitch) const {
            cfg::BasicBlock::NodesReverseConstIterator revIt = state.getBasicBlock().nodesReverseConstIterator();
            while (revIt.hasNext()) {
                NodeId currentId = revIt.next();
                Factory& asgFactory = engine.getASGFactory();
                base::Base& currentNode = asgFactory.getRef(currentId);
                if (!Common::getIsParenthesizedExpression(currentNode) && Common::getIsExpression(currentNode)) {
                    expr::Expression& e = dynamic_cast<expr::Expression&>(currentNode);
                    if (e.getType() == NULL) {
                        columbus::java::asg::Factory::TurnFilterOffSafely sfact(asgFactory);
                        if (e.getType() == NULL)
                            throw SymbolicColumbusException("boolean expression not found in parent state");
                        if (Common::getIsBooleanType(*e.getType())) {
                            return currentId;
                        }
                    }
                    else {
                        if (Common::getIsBooleanType(*e.getType())) {
                            return currentId;
                        }
                    }
                }
                else if (Common::getIsParenthesizedExpression(currentNode) && currentNode.getParent() != nullptr && Common::getIsSwitch(*(currentNode.getParent()))) {
                    /*auto it = state.getBasicBlock().controlOutEdgesIterator();
                    cout << "getLastBoolId" << endl;
                    while (it.hasNext()) {
                        auto ed = it.next()->getLabel();
                        cout << ed << endl;
                    }*/
                    expr::ParenthesizedExpression& pe = dynamic_cast<expr::ParenthesizedExpression&>(currentNode);
                    isFromSwitch = true;
                    return pe.getOperand()->getId();
                    //throw SymbolicColumbusException("boolean expression not found in parent state");
                }
                /*else if (Common::getIsParenthesizedExpression(currentNode) && currentNode.getParent() != nullptr && Common::getIsParenthesizedExpression(*(currentNode.getParent()))) {
                    expr::ParenthesizedExpression* pe = dynamic_cast<expr::ParenthesizedExpression*>(currentNode.getParent());
                
                }*/

                else if (Common::getIsParenthesizedExpression(currentNode) && currentNode.getParent() != nullptr && Common::getIsIf(*(currentNode.getParent()))) {
                    expr::ParenthesizedExpression& pe = dynamic_cast<expr::ParenthesizedExpression&>(currentNode);
                    expr::Expression* oper = pe.getOperand();
                    while (oper && Common::getIsParenthesizedExpression(asgFactory.getRef(oper->getId()))) {
                        expr::ParenthesizedExpression* peo = dynamic_cast<expr::ParenthesizedExpression*>(oper);
                        oper = peo->getOperand();
                    }

                    if (oper) {
                        return oper->getId();
                    }
                        
                }
            }
            throw SymbolicColumbusException("boolean expression not found in parent state");
        }

        bool StateJava::onTrueBranch() const {
            //TODO: bb legyen protected
            cfg::BasicBlock::EdgesConstIterator edgeIt = bb.controlInEdgesIterator();
            if (edgeIt.hasNext()) {
                const cfg::Edge* edge = edgeIt.next();
                return edge->getLabel().compare("true") == 0;
            }
            //unsigned bbId = bb.getBlockId(); 1-es bb id eseten. Mi az 1-es bb id?
            return false;
        }

        bool StateJava::isPathValid() const {
            try {
                // solve and build back
     //           if (parent.getBasicBlock().controlOutEdgesIterator().size() > 1) {
                    //std::set<Constraint*, ltDeref<Constraint*> >
                    string accumulated = convertPathCondition();
                    Solution result;
                    bool timedout = false;
                    try {
                        result = engine.getConstraintSolver()->solve(accumulated, variables);//solve_wrapper(accumulated, variables);
                    }
                    catch (std::runtime_error& e) {

                        std::cout << e.what() << std::endl;
                        timedout = true;
                    }

                    if (timedout)
                        std::cout << "Timed out from outside." << std::endl;
                    if (result.hasSolution) {
                        return true;
                    }
                    else {

                        return false;
                    }


                
            }
            catch (SymbolicColumbusException& ex) {
                //TODO hibauzenet
                //common::WriteMsg::write(CMSG_SYM_CONST_CANNOT_BUID_PC, ex.what(), stateId);
                return false;
            }
            return false;
        }
        

    }
}
