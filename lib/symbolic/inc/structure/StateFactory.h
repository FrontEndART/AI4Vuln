#ifndef _STATE_FACTORY_H_
#define _STATE_FACTORY_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class State;

    class StateFactory {
    protected:
        State* rootState;
        SymbolicEngine& engine;
        std::vector<State*> states;
        std::map<NodeId, std::vector<State*> > stateMap;
        unsigned int stateIdCounter;

    public:
        StateFactory(SymbolicEngine& _engine);
        StateFactory(const StateFactory&);
        StateFactory& operator=(const StateFactory&) const;
        virtual ~StateFactory();
        virtual State* createState(const columbus::cfg::BasicBlock& bb) = 0;
        virtual State* createState(const columbus::cfg::BasicBlock& bb, State* parent, int edgeKind) = 0;
        inline const AbstractSymbolicExecutor& getExecutor() const;
		inline SymbolicEngine& getEngine() { return engine;}
        inline int getNumberOfStates() const { return states.size();}
        inline State* getRootState() const { return rootState;}      
        const std::vector<State*>& getStates() const {return states;}
        unsigned int incrementStateIdCounter() {
            return ++stateIdCounter;
        }
		const columbus::rul::RulHandler* getRulHandler();
        const State* getState(unsigned int stateId) const;

    protected:
        void insertToStateMap(State& state);
    };

}}

#endif
