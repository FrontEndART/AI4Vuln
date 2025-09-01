#ifndef _ABSTRACT_SYMBOLIC_EXECUTOR_H_
#define _ABSTRACT_SYMBOLIC_EXECUTOR_H_

#include "../common.h"

namespace columbus {

    namespace java {
        namespace asg {
            namespace expr {
                class Identifier;
            }
        }
    }
    
    
    namespace symbolic {

    class SymbolicEngine;
	class ConstraintSolverExpr;
    

    class AbstractSymbolicExecutor {
    protected:
        SymbolicEngine& engine;
        bool lastIsSwitch;

    public:
        AbstractSymbolicExecutor(SymbolicEngine& _engine);
        virtual ~AbstractSymbolicExecutor() {}
        virtual void execute(NodeId asgNodeId) = 0;
        virtual void setupCalledState(columbus::symbolic::State& calledState, columbus::NodeId caller, columbus::NodeId calledICFG) = 0;
        virtual void makeCallReturn(State& calledState) = 0;
        virtual BooleanInfixOperatorKind getParentOperatorKind(const columbus::NodeId currentNode, columbus::NodeId& parentNode) const = 0;
        inline SymbolicEngine& getEngine() const {
            return engine;
        }
        inline bool getLastIsSwitch() const { return lastIsSwitch; }
        inline void setLastIsSwitch(bool _s) { lastIsSwitch = _s; }

		virtual bool getBooleanValueDefinitionValue(SmartDefinition definition) = 0;
		virtual SmartDefinition createBooleanValueDefinition(bool) = 0;

		virtual NodeId getScopeOrMethodDeclarationParent(NodeId nodeId) = 0;
		virtual void initializeThis(NodeId nodeId, State& state) = 0;

        virtual const NodeId& getCurrentNodeId() const = 0;

        virtual SmartDefinitionProxy getLocalVariable(const columbus::java::asg::expr::Identifier& identifier) = 0;

    };

}}

#endif
