#ifndef _JSON_OUTPUT_WRITER_H_
#define _JSON_OUTPUT_WRITER_H_

#include "JavaStateListener.h"

namespace columbus { namespace symbolic {

    class JsonOutputWriter : public columbus::symbolic::JavaStateListener {
    private:
        ofstream outStream;
        int eId;

    protected:
        virtual void printOutStackTrace(StackTrace *st);

    public:
        JsonOutputWriter(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact);
        virtual ~JsonOutputWriter();
    };

}}

#endif