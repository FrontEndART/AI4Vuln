#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    void DepthFirstSearchStrategy::initialize(State& state) {
        while (!stack.empty())
            stack.pop();
        stack.push(&state);
        getNextCalled=false;
    }

    State* DepthFirstSearchStrategy::getNextState() {
        if (getNextCalled==false) {
            getNextCalled=true;
            return stack.top();
        }
        State* front = stack.top();
        stack.pop();
        std::vector<State*> children=expander.expandState(*front);
        for (std::vector<State*>::iterator iter = children.begin(); iter != children.end(); iter++) {
            stack.push((*iter));
        }
        if (stack.empty())
            return NULL;
        return stack.top();
    }

}}
