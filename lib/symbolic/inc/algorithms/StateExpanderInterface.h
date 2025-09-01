#ifndef _STATE_EXPANDER_INTERFACE_
#define _STATE_EXPANDER_INTERFACE_

#include "../common.h"

namespace columbus { namespace symbolic {

    class StateExpanderInterface {
    public:
        virtual std::vector<State*> expandState(State& state) = 0;
        virtual ~StateExpanderInterface() {}
    };
}}

#endif
