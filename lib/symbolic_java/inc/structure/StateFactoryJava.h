#ifndef _STATE_FACTORY_JAVA_H_
#define _STATE_FACTORY_JAVA_H_

#include <symbolic/inc/structure/StateFactory.h>

namespace columbus { namespace symbolic {

    class StateFactoryJava : public StateFactory {
    public:
        StateFactoryJava(SymbolicEngine& _executor);
        virtual ~StateFactoryJava();
        virtual State* createState(const columbus::cfg::BasicBlock& bb);
        virtual State* createState(const columbus::cfg::BasicBlock& bb, State* parent, int edgeKind);
    };
}}

#endif
