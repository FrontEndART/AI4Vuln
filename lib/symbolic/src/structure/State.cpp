#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    State::State(const columbus::cfg::BasicBlock& _bb, StateFactory& _stateFactory)
    : 
      parent(*this),
      caller(NULL),
      bb(_bb),
      edgeKind(NORMAL_EDGE),
      memory(_stateFactory.getEngine()), 
      locals (_stateFactory.getEngine()),
      exceptional(false),
      depth(0),
      stateFactory(_stateFactory),
      engine(_stateFactory.getEngine()),
	  stateId(_stateFactory.incrementStateIdCounter()),
	  isPcValid(true),
	  weight(1.0)
     {
        /**
        *	This state is the root of all other states
        */
    }

    State::State(State& _parent, const columbus::cfg::BasicBlock& _bb, int _edgeKind)
    : parent(_parent),
      bb(_bb),
      edgeKind(_edgeKind),
      memory(parent.memory), 
      locals(parent.locals),
      exceptional(false),
      depth(_parent.depth+1),
      stateFactory(_parent.stateFactory),
      engine(_parent.stateFactory.getEngine()),
	  stateId(_parent.stateFactory.incrementStateIdCounter()),
	  isPcValid(parent.getIsPcValid()),
	  weight(1.0)
    {
        if (edgeKind==NORMAL_EDGE) {
            /**
            *	We have a normal edge
            */
            caller=parent.caller;
            thiz=parent.thiz;
            definitionStack=parent.definitionStack;
            lValues=parent.lValues;
            calls=parent.calls;
        } else if (edgeKind==CALL_EDGE) {
            /**
            *	We have a call edge
            */
            caller=&parent;
            definitionStack=parent.definitionStack;
            calls=parent.calls;
        } else if (edgeKind==RETURN_EDGE) {
            /**
            *	We have a return edge
            */
            caller=parent.caller->caller;
            thiz=parent.caller->thiz;
            definitionStack=parent.caller->definitionStack;
            lValues=parent.caller->lValues;
            calls=parent.caller->calls;
        }
    }
    
    State::~State() {
        
    }

    void State::addVariable(shared_ptr<ConstraintSolverExpr> expr) {
        auto result = find_if(variables.begin(), variables.end(), [&expr](shared_ptr<ConstraintSolverExpr> elem) { return (*elem).operator==(*expr); });
        if (result == variables.end()) {
            variables.insert(expr);
        }
        
    }

    void State::pushDefinition(SmartDefinition definition) {
        definitionStack.push(definition);
    }

    SmartDefinition State::popDefinition() {
		// !!! TODO !!! This is just a quckfix against popping from empty stack. Should never happen on syntactically correct code.
		// see redmine issue 421
        if (definitionStack.empty()) throw SymbolicColumbusException("!!! ERROR !!! ATTEMPTING TO POP FROM EMPTY STACK");
        SmartDefinition ret = definitionStack.top();
        definitionStack.pop();
        return ret;
    }

    SmartDefinition State::getThizObject() {
        return thiz;
    }

    void State::setThizObject(SmartDefinition def) {
        thiz = def;
    }


    void State::pushCall(columbus::NodeId call) { calls.push_back(call); }
		
    columbus::NodeId State::topCall() { return calls.back(); }

	void State::popCall() { 
        calls.pop_back();
    }

    bool State::hasCall() const { return !calls.empty(); }


    const columbus::cfg::BasicBlock& State::getBasicBlock() const {
        return bb;
    }

    const State& State::getParent() const {
        return parent;
    }

    void State::setlValue(columbus::NodeId expressionId, SmartDefinitionProxy location) {
        lValues.erase(expressionId);
        lValues.insert(std::map<NodeId, SmartDefinitionProxy>::value_type(expressionId, location));
    }

    SmartDefinitionProxy State::getlValue(columbus::NodeId expressionId) {
        std::map<NodeId, SmartDefinitionProxy>::iterator iter = lValues.find(expressionId);
        return (*iter).second;
    }

    bool State::haslValue(NodeId expressionId) const {
        return lValues.find(expressionId)!=lValues.end();
    }

    void State::addNewCondition(Constraint* c){
        pathCondition.insert(c);
    }

    bool State::fireNullPointerDereferenced(NodeId nodeId) {
        if (!isPathValid()) {
            return false;
        }
       if (stateFactory.getRulHandler()->getIsEnabled(SYMBOLIC_NULL_POINTER_EXCEPTION_RULECHECKER_ID)) {
            //addWarning(SYMBOLIC_NULL_POINTER_EXCEPTION_RULECHECKER_ID, nodeId);
            engine.fireNullPointerDereferenced(nodeId, *this);
            return true;
            
        } else {
        }
       return false;
    }

    bool State::fireClassCastException(NodeId nodeId) {
        if (!isPathValid()) {
            return false;
        }
        if (stateFactory.getRulHandler()->getIsEnabled(SYMBOLIC_CLASS_CAST_EXCEPTION_RULECHECKER_ID)) {
           engine.fireClassCastException(nodeId, *this);
           return true;
        } else {
        }
        return false;
    }

    bool State::fireDivisionByZero(NodeId nodeId) {
        if (!isPathValid()) {
            return false;
        }
        if (stateFactory.getRulHandler()->getIsEnabled(SYMBOLIC_DIVISION_BY_ZERO_RULECHECKER_ID)) {
           engine.fireDivisionByZero(nodeId, *this);
           return true;
        } else {
        }
        return false;
    }

    bool State::fireIndexOutOfBounds(NodeId nodeId, int arrayLength, int index) {
        if (!isPathValid()) {
            return false;
        }
        if (stateFactory.getRulHandler()->getIsEnabled(SYMBOLIC_INDEX_OUT_OF_BOUNDS_EXCEPTION_RULECHECKER_ID)) {
           engine.fireIndexOutOfBounds(nodeId, arrayLength, index, *this);
           return true;
        } else {
        }
        return false;
    }

    bool State::fireNegativeArraySize(NodeId nodeId, int arrayLength) {
        if (!isPathValid()) {
            return false;
        }
        if (stateFactory.getRulHandler()->getIsEnabled(SYMBOLIC_INDEX_NEGATIVE_ARRAY_SIZE_RULECHECKER_ID)) {
            engine.fireNegativeArraySize(nodeId, arrayLength, *this);
            return true;
        } else {
        }
        return false;
    }


    SmartDefinitionProxy State::getObjectByAddress(const Address& address) {
        return memory[address];
    }    
    Address State::getAddressOfLocal(columbus::NodeId nodeId) {
        boost::shared_ptr<TreeElementProxy<Address, columbus::NodeId, std::less<columbus::NodeId> > > proxy=locals[nodeId];
        if (proxy->isNull()) {
            *proxy=memory.allocate();
        }
        return *proxy;
    }

    void State::addConstraintSolverExpr(NodeId nodeId, shared_ptr<ConstraintSolverExpr> expr) {
        constraintSolverExprs[nodeId] = expr;
    }

    void State::setLastBuildDependencies(NodeId nodeId, ConstraintSet dependencies) {
        if(dependencies.size() != 0) //todo ez hibalehetoseghez vezethet szerintem
            lastDependencies = std::pair<NodeId, ConstraintSet >(nodeId, dependencies);
    }

    bool State::isUnreachableState() const {
        return weight == 0.0;
    }
	
	void State::recalculateWeight(bool setZeroWeight) {
        // Add this to parent's children and set this weight and its siblings
        std::vector<State*>& childrens = parent.getChildren();
        size_t childrenNr = childrens.size();

        if (childrenNr == 1) {
            if (!setZeroWeight)
                weight = parent.getWeight();

        } else {
            unsigned int childrenWithNotZeroWeight = 0;
            for (std::vector<State*>::iterator it = childrens.begin(); it != childrens.end(); ++it) {
                State *child = *it;
                if (child->getWeight() != 0.0)
                    ++childrenWithNotZeroWeight;
            }

            if (childrenWithNotZeroWeight > 0) {
                double newWeight = parent.getWeight() / childrenWithNotZeroWeight;
                for (std::vector<State*>::iterator it = childrens.begin(); it != childrens.end(); ++it) {
                    State *child = *it;
                    if (child->getWeight() != 0.0)
                        child->setWeight(newWeight);
                }
            }
        }
    }
}}
