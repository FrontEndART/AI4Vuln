#ifndef _STATE_H_
#define _STATE_H_

#include "../common.h"

using namespace std;

namespace columbus { namespace symbolic {

    class State;
    class StateFactory;
	class SymbolicEngine;

    class State {
        friend class StateFactory;

	public:
		static const int NORMAL_EDGE=0;
		static const int CALL_EDGE=1;
		static const int RETURN_EDGE=2;

    protected:
		
		State& parent;
		State* caller;
		const columbus::cfg::BasicBlock& bb;
		int edgeKind;

        SmartDefinition thiz;
		Memory memory;
		Locals locals;
		bool exceptional;
		std::stack<SmartDefinition> definitionStack;
        std::map<columbus::NodeId, SmartDefinitionProxy> lValues;
		std::vector<columbus::NodeId> calls;
		std::vector<State*> children;
		unsigned int depth;
		
	
		StateFactory& stateFactory;
		SymbolicEngine& engine;
		unsigned int stateId;
		ConstraintSet pathCondition;
        std::set<std::shared_ptr<ConstraintSolverExpr>> variables;
        bool isPcValid;
        double weight;
        virtual void recalculateWeight(bool setZeroWeight = false);
    //path condition
        std::string accumulated;

    public:
		State(const columbus::cfg::BasicBlock& bb, StateFactory& stateFactory);
        State(State& parent, const columbus::cfg::BasicBlock& bb, int _edgeKind);
        virtual ~State();

		inline Memory& getMemory() { return memory; }

        virtual SmartDefinitionProxy getObjectByAddress(const Address& address) ;
		virtual Address getAddressOfLocal(columbus::NodeId nodeId) ;
        virtual bool isPathValid() const { return true; }

        SmartDefinition getThizObject();
        void setThizObject(SmartDefinition def);

		void pushCall(columbus::NodeId call);
		
        columbus::NodeId topCall();

		void popCall();
		
		const ConstraintSet& getPathCondition() const { return pathCondition; }

		inline unsigned int getCallDepth() const { return calls.size(); }
		inline unsigned int getDepth() const { return depth; }
		inline State* getCallerState() { return caller; }

        void pushDefinition(SmartDefinition definition);
        SmartDefinition popDefinition();
        inline SmartDefinition topDefinition() const {return definitionStack.top();}
		inline bool isStackEmpty() const { return definitionStack.empty(); }
		void setlValue(columbus::NodeId expressionId, SmartDefinitionProxy location);
        SmartDefinitionProxy getlValue(NodeId def);
        bool haslValue(columbus::NodeId expressionId) const;

        const columbus::cfg::BasicBlock& getBasicBlock() const;
        inline StateFactory& getStateFactory() const {return stateFactory;}
        inline bool hasParent() const {return this != &parent;}
        const State& getParent() const ;

        unsigned int getStateId() const { return stateId;}
        int getEdgeKind() const { return edgeKind; }
        

        std::vector<State*>& getChildren() { return children; }

        void setExceptional() { exceptional = true;}
        bool isExceptional() { return exceptional;}

        bool hasCall() const;
		
        bool isUnreachableState() const;
		inline const double getWeight() const { return weight; }
        inline void setWeight(const double w) {
            weight = w;
            if (weight == 0.0)
                recalculateWeight(true);
        }
		
		bool getIsPcValid() const { return isPcValid; }
        void setIsPcValid(bool isPcValid) {  this->isPcValid = isPcValid;  }
		
		void addChild(State *child) { children.push_back(child); }
        void addVariable(std::shared_ptr<ConstraintSolverExpr> expr);
        const std::set<std::shared_ptr<ConstraintSolverExpr>>& getVariables() const {
            return variables;
        }

		// Runtime exceptions
        bool fireNullPointerDereferenced(NodeId nodeId);
        bool fireClassCastException(NodeId nodeId);
        bool fireDivisionByZero(NodeId nodeId);
        bool fireIndexOutOfBounds(NodeId nodeId, int arrayLength, int index);
        bool fireNegativeArraySize(NodeId nodeId, int arrayLength);

        std::map<NodeId, std::shared_ptr<ConstraintSolverExpr>>& getConstraintSolverExprs() { return constraintSolverExprs; }
        void addConstraintSolverExpr(const NodeId nodeId, std::shared_ptr<ConstraintSolverExpr> expr);
        void setLastBuildDependencies(NodeId nodeId, ConstraintSet dependencies);
        std::pair<NodeId, ConstraintSet>& getLastDependencies() { return lastDependencies; }
        void addNewCondition(Constraint* c);


    private:
		

		/**
         * dependencies of the last expression built in state
        */
        std::pair<NodeId, ConstraintSet> lastDependencies;
        std::map<NodeId, std::shared_ptr<ConstraintSolverExpr>> constraintSolverExprs;
};

    std::ostream& operator<<(std::ostream& out, const columbus::symbolic::State& state);

}}

#endif
