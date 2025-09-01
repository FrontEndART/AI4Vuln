#ifndef _JAVA_CSV_STATE_LISTENER_H_
#define _JAVA_CSV_STATE_LISTENER_H_

#include "JavaStateListener.h"
#include <io/inc/CsvIO.h>

namespace columbus { namespace symbolic {

    class CsvStateListener : public columbus::symbolic::JavaStateListener {
    private:
        io::CsvIO csv;

    protected:
        virtual void printOutStackTrace(StackTrace *st);

    public:
        CsvStateListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact);
        virtual ~CsvStateListener();
    };

}}

#endif
