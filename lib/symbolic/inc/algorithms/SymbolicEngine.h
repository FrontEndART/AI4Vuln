#ifndef _SYMBOLICENGINE_H_
#define _SYMBOLICENGINE_H_

//#include "../common.h"
#include "../constraint/ConstraintSolver.h"
#include "../constraint/ConstraintBuilder.h"

namespace columbus { namespace cfg { class CFGFactory; } }
namespace columbus { namespace symbolic { class AbstractSymbolicExecutor; } }
namespace columbus { namespace symbolic { class SearchStrategy; } }
namespace columbus { namespace symbolic { class SymbolicEngineInterface; } }
namespace columbus { class Checker; class RuleChecker; }

using namespace std;

namespace columbus { namespace symbolic {


    class SymbolicEngine : public StateExpanderInterface {
    public:
       
        SymbolicEngine(columbus::cfg::CFGFactory& _cfgFactory, columbus::java::asg::ASGFactory& asgFact,const columbus::rul::RulHandler* _rulHandler, ConstraintSolver* solver, ConstraintBuilder* builder, int optionalDepth = -1);
        SymbolicEngine(const SymbolicEngine&);
        SymbolicEngine& operator=(const SymbolicEngine&);
        virtual ~SymbolicEngine();

        void run(StateFactory *_stateFactory, columbus::NodeId nodeId = 0);
        inline State& getCurrentState() {return *currentState;}

        void setCurrentState(State *_state) {
            currentState = _state;
        }

        void setExecutor(AbstractSymbolicExecutor& executor);

        columbus::cfg::CFGFactory& getCFGFactory() const { return cfgFactory;}

		columbus::java::asg::ASGFactory& getASGFactory() const { return asgFactory;}

        StateFactory* getStateFactory() const { return stateFactory;}

        AbstractSymbolicExecutor* getExecutor() const { return executor; }

		const columbus::rul::RulHandler* getRulHandler() { return rulHandler; }
		
		ConstraintBuilder* getConstraintBuilder() const { return constraintBuilder; }
        ConstraintSolver* getConstraintSolver() const { return constraintSolver; }

		inline unsigned int getNextSymbolIdentifier() { return symbolIdentifierCounter++;}
		inline unsigned int getNextDefinitionIdentifier() { return definitionCounter++; }
		inline unsigned int getNextAddress() { return heapPointer++; }
		void addStateListener(StateListener *listener) { listeners.push_back(listener); }
		void fireNullPointerDereferenced(NodeId nodeId, const State& state);
		void fireInfiniteLoop(NodeId nodeId, const State& state);
		void fireClassCastException(NodeId nodeId, const State& state);
		void fireDivisionByZero(NodeId nodeId, const State& state);
		void fireIndexOutOfBounds(NodeId nodeId, int arrayLength, int index, const State& state);
		void fireNegativeArraySize(NodeId nodeId, int arrayLength, const State& state);

		void fireDefinitionPushed(SmartDefinition definition, const State& state);
		void fireDefinitionPoped(SmartDefinition definition, const State& state) ;
		void fireUsedStaticVariable(const NodeId variableId, const std::vector<State*>& exitStates, const State& state);

		unsigned int getStateNumber() { return m_stateNumber;}
		unsigned int getExceptionalStateNumber() { return m_exceptionalStateNumber;}


        void setWarningListener(WarningListener* wl) { warningListener = wl; }
        void addWarning(std::string checkerId, columbus::NodeId nodeId, const std::list<columbus::NodeId>& warningTextParams = std::list<columbus::NodeId>());
        void addWarning(std::string checkerId, columbus::NodeId nodeId, const std::string& warningText, const columbus::graph::AttributeComposite* extraInfo = NULL);
		
		

    private:
        /** State, which is currently under execution. */
        State *currentState;

        /** cfg */
        columbus::cfg::CFGFactory& cfgFactory;
		columbus::java::asg::ASGFactory& asgFactory;

        AbstractSymbolicExecutor* executor;

        SearchStrategy *strategy;

		StateFactory *stateFactory;
		

        unsigned long maxState;
        unsigned long maxDepth;
        unsigned long m_stateNumber;
		unsigned long m_exceptionalStateNumber;

		const columbus::rul::RulHandler* rulHandler;

		//number of symbol identifiers
		unsigned int symbolIdentifierCounter;

		//number of definitions
		unsigned int definitionCounter;

		//next address
		unsigned int heapPointer;

        void search(StateFactory& stateFactory);

        /**
        * Determines weather a sort of limit has reached during the execution.
        * e.g. maxdepth
        * @return true, if a sort of limit has reached, false otherwise
        */
        bool limitReached();


        /**
        * Expands a symbolic state. While no branching according to the cfg
        * executes the actual asg node. If there are more next asg nodes creates
        * the next states.
        * @param state  State which will be expanded.
        * @return       The next states in a vector.
        */
        virtual std::vector<State*> expandState(State& state);

		/**
		*	Listeners to state events
		*/
		std::vector<StateListener*> listeners;

        WarningListener* warningListener;

        void executeState(State& state);
        bool isNodeIdBefore(const columbus::NodeId before, const columbus::NodeId last) const;
		
		ConstraintSolver *constraintSolver;
        ConstraintBuilder *constraintBuilder;
    };

}}

#endif
