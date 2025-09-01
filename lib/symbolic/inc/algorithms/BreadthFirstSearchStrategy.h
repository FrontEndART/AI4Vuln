#ifndef _BREADTHFISRT_H_
#define _BREADTHFISRT_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class BreadthFirstSearchStrategy: public SearchStrategy {
    private:
        bool getNextCalled;
        std::queue<State*> queue;  // FIFO queue

    public:
        BreadthFirstSearchStrategy(StateExpanderInterface& expander) : SearchStrategy(expander), getNextCalled(false), queue() {};
        State* getNextState();
        void initialize(State& state);
    };

}}

#endif
