#include "../../inc/algorithms/AbstractSymbolicExecutor.h"

namespace columbus { namespace symbolic {

    AbstractSymbolicExecutor::AbstractSymbolicExecutor(SymbolicEngine& _engine) : engine(_engine), lastIsSwitch(false) {
        engine.setExecutor(*this);
    }

}}
