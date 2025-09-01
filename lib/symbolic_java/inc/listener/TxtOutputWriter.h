#ifndef _TXT_OUTPUT_WRITER_H_
#define _TXT_OUTPUT_WRITER_H_

#include "JavaStateListener.h"

namespace columbus { namespace symbolic {

    class TxtOutputWriter : public columbus::symbolic::JavaStateListener {
    private:
        ofstream outStream;

    protected:
        virtual void printOutStackTrace(StackTrace *st);

    public:
        TxtOutputWriter(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact);
        virtual ~TxtOutputWriter();
    };

}}

#endif