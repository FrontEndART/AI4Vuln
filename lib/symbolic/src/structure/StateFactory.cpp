#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    StateFactory::StateFactory(SymbolicEngine& _engine) : rootState(NULL), engine(_engine), states(), stateMap(), stateIdCounter(0) {
        stateIdCounter = 0;
    }

    StateFactory::~StateFactory() {
        for (std::vector<State*>::iterator iter = states.begin(); iter != states.end(); iter++) {
            State* state = (*iter);
            delete state;
        }
    }

    inline const AbstractSymbolicExecutor& StateFactory::getExecutor() const { return *engine.getExecutor(); }

    const columbus::rul::RulHandler* StateFactory::getRulHandler() { return engine.getRulHandler(); }
	
    void StateFactory::insertToStateMap(State& state) {
        std::map<NodeId, std::vector<State*> >::iterator iter = stateMap.find(state.getBasicBlock().getBlockId());
        if (iter != stateMap.end()) {
            std::vector<State*>& stateSet = (*iter).second;
            stateSet.push_back(&state);
        } else {
            std::map<NodeId, std::vector<State*> >::iterator iter2 = stateMap.insert(std::map<NodeId, std::vector<State*> >::value_type(state.getBasicBlock().getBlockId(), std::vector<State*>())).first;
            (*iter2).second.push_back(&state);
        }
    }

    const State* StateFactory::getState(unsigned int stateId) const {
        for (std::vector<State*>::const_iterator stateIter = states.begin(); stateIter != states.end(); stateIter++) {
            if ((*stateIter)->getStateId() == stateId)
                return *stateIter;
        }
        return NULL;
    }



}}
