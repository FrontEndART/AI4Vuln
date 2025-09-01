#ifndef _SEARCHSTRATEGY_H_
#define _SEARCHSTRATEGY_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class SearchStrategy {
    protected:
        StateExpanderInterface& expander;

    public:
        SearchStrategy(StateExpanderInterface& _expander) : expander(_expander) {};
        virtual ~SearchStrategy() {}
        virtual State* getNextState() = 0;
        virtual void initialize(State& state) = 0;
    };

}}

#endif
