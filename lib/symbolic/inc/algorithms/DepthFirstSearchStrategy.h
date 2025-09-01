#ifndef _DEPTHFISRT_H_
#define _DEPTHFISRT_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class DepthFirstSearchStrategy: public SearchStrategy {
    private:
        bool getNextCalled;
        std::stack<State*> stack;

    public:
        DepthFirstSearchStrategy(StateExpanderInterface& expander) : SearchStrategy(expander), getNextCalled(false), stack() {};
        State* getNextState();
        void initialize(State& state);
    };

}}

#endif
