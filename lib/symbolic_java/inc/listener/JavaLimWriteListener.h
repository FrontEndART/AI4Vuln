#ifndef _SYMBOLIC_JAVA_LIM_WRITE_LISTENER_H_
#define _SYMBOLIC_JAVA_LIM_WRITE_LISTENER_H_

#include "JavaStateListener.h"
#include <graph/inc/graph.h>


namespace columbus { namespace symbolic {

    class JavaLimWriteListener : public columbus::symbolic::JavaStateListener {
    protected:
        virtual void printOutStackTrace(StackTrace *st);
        columbus::graph::Graph* m_graph;

        SymbolicEngine* engine;

        WarningListener& warningListener;
		
    public:
        JavaLimWriteListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact, columbus::graph::Graph* _graph, WarningListener& wl);
        virtual ~JavaLimWriteListener();

        void setEngine(SymbolicEngine* engine);


        // Exceptions
        //virtual void nullPointerDereferenced(columbus::NodeId nodeId, const columbus::symbolic::State& state);
        //virtual void classCastException(columbus::NodeId nodeId, const columbus::symbolic::State& state);
        //virtual void divisionByZero(NodeId nodeId, const State& state);
        //virtual void indexOutOfBounds(NodeId nodeId, const State& state, int arrayLength, int index);
        //virtual void negativeArraySize(NodeId nodeId, const State& state, int arrayLength);
    };

}}

#endif
