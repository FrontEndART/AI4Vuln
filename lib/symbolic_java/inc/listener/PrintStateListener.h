#ifndef _JAVA_PRINT_STATE_LISTENER_H_
#define _JAVA_PRINT_STATE_LISTENER_H_

#include "JavaStateListener.h"

namespace columbus { namespace symbolic {

    class PrintStateListener : public columbus::symbolic::JavaStateListener {
    protected:
        virtual void printOutStackTrace(StackTrace *st);

    public:
        PrintStateListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact);
        virtual ~PrintStateListener() {}

    };

}}

#endif
