#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    StateFactoryJava::StateFactoryJava(SymbolicEngine& _engine) : StateFactory(_engine) {
    }

    StateFactoryJava::~StateFactoryJava() {
    }

    /**
	*	This method is used to create root states only, otherwise it throws an exception
	*/
	State* StateFactoryJava::createState(const columbus::cfg::BasicBlock& bb) {
        if (rootState != NULL) {
			// this must be the root of all states
            throw SymbolicColumbusException("Illegal state creation attempt");
        } 
        rootState = new StateJava(bb, *this);

        states.push_back(rootState);
        insertToStateMap(*rootState);
        return rootState;
    }

	/**
	*	This method is used to create child states only. Parent must always be provided and root state must already exist
	*/
    State* StateFactoryJava::createState(const columbus::cfg::BasicBlock& bb, State* parent, int edgeKind) {
        
        if (parent == NULL || rootState == NULL) {
            throw SymbolicColumbusException("Illegal state creation attempt");
        }         

        State* state = new StateJava(*parent, bb, edgeKind);

		//here we should copy everything that new state must inherit immutably
        state->setThizObject(parent->getThizObject());


        states.push_back(state);
        insertToStateMap(*state);
        return state;
    }

}}
