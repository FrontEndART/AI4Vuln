#ifndef _STACK_TRACE_JAVA_H
#define _STACK_TRACE_JAVA_H

#include <symbolic/inc/structure/StackTrace.h>

namespace columbus { namespace symbolic {

    class StackTraceJava : public columbus::symbolic::StackTrace {
    public:
        StackTraceJava(columbus::symbolic::ExceptionType _type);
        virtual ~StackTraceJava() {}
    };
}}

#endif
