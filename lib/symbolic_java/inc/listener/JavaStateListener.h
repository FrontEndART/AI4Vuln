#ifndef _JAVA_STATE_LISTENER_H_
#define _JAVA_STATE_LISTENER_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class JavaStateListener : public columbus::symbolic::StateListener {
    private:
        template <int LPT> LeaderPoint* calculateLeaderPoint(const columbus::NodeId nodeId, double propability) const;

    protected:
        columbus::java::asg::Factory& factory;
        columbus::cfg::CFGFactory& cfgFactory;

        virtual columbus::NodeId calculateLeaderNamedPoint(const columbus::NodeId nodeId, bool isComplexExpression = false) const;
        virtual void printOutStackTrace(StackTrace *st) {}

        const columbus::java::asg::Range getPosition(const columbus::NodeId nodeId) const;
        bool hasPositionInformation(const columbus::NodeId nodeId) const;
        void printPositionInformation(const columbus::NodeId nodeId, std::stringstream& out) const;
        void printJsonPositionInformation(const columbus::NodeId nodeId, std::stringstream& out) const;
        std::string getLeaderNodeName(const columbus::NodeId nodeId) const;

        //bool checkForRepeating(const columbus::NodeId nodeId, const columbus::NodeId leaderNodeId, const columbus::symbolic::State& currentState) const;
        //bool findDefinitionInCFG(const columbus::NodeId nodeId, const columbus::NodeId leaderNodeId, const columbus::symbolic::State& currentState, const StackTrace *existingStackTrace) const;
        //bool checkNodeIsADefinition(const columbus::NodeId nodeId, const columbus::NodeId leaderNodeId) const;

    public:
        JavaStateListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact);
        virtual ~JavaStateListener() {}

        // Exceptions
        virtual void nullPointerDereferenced(columbus::NodeId nodeId, const columbus::symbolic::State& state);
        virtual void classCastException(columbus::NodeId nodeId, const columbus::symbolic::State& state);
        virtual void divisionByZero(NodeId nodeId, const State& state);
        virtual void indexOutOfBounds(NodeId nodeId, const State& state, int arrayLength, int index);
        virtual void negativeArraySize(NodeId nodeId, const State& state, int arrayLength);

        // Other events
        virtual void stateCreated(const columbus::symbolic::State& state) {}
        virtual void definitionAdded(const columbus::symbolic::State& state, const columbus::symbolic::Definition& def) {}
        virtual void definitionPushed(const State& state, SmartDefinition definition) {}
        virtual void definitionPoped(const State& state, SmartDefinition definition) {}
    };

}}

#endif
