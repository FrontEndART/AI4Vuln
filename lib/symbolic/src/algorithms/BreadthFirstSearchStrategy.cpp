#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    void BreadthFirstSearchStrategy::initialize(State& state) {
        while (!queue.empty())
            queue.pop();
        queue.push(&state);
        getNextCalled = false;
    }

    State* BreadthFirstSearchStrategy::getNextState() {
        if (getNextCalled == false) {
            getNextCalled = true;
            return queue.front();
        }
        State* front = queue.front();
        queue.pop();
        std::vector<State*> children = expander.expandState(*front);
        for (std::vector<State*>::iterator iter = children.begin(); iter != children.end(); iter++)
            queue.push((*iter));
        if (queue.empty())
            return NULL;
        return queue.front();
    }

}}
