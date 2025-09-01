#ifndef _STATE_LISTENER_H_
#define _STATE_LISTENER_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    // Defining the ruleChecker names
    #define SYMBOLIC_NULL_POINTER_EXCEPTION_RULECHECKER_ID             "RH_NPE"
    #define SYMBOLIC_DIVISION_BY_ZERO_RULECHECKER_ID                   "RH_DBZ"
    #define SYMBOLIC_INFINITE_LOPP_RULECHECKER_ID                      "RH_IL"
    #define SYMBOLIC_CLASS_CAST_EXCEPTION_RULECHECKER_ID               "RH_CCE"
    #define SYMBOLIC_INDEX_OUT_OF_BOUNDS_EXCEPTION_RULECHECKER_ID      "RH_IOB"
    #define SYMBOLIC_INDEX_NEGATIVE_ARRAY_SIZE_RULECHECKER_ID          "RH_NAS"

    class StateListener {
    protected:
        typedef std::set<StackTrace*, StackTrace_compare> FilteredExceptionSetType;
        std::vector<StackTrace*> m_exceptions;
        std::map<ExceptionType,  FilteredExceptionSetType> m_filteredExceptions;

        virtual columbus::NodeId calculateLeaderNamedPoint(const columbus::NodeId nodeId, bool isComplexExpression = false) const { return 0; }
        virtual void createStackTrace(ExceptionType type, LeaderPoint *leaderPoint, columbus::NodeId nodeId, const State& state);
        virtual bool createStackTraceForState(const columbus::symbolic::State& state, StackTrace *st, TracePointType tp, bool lastNode = false);
        virtual void checkForRepeating();
        virtual void processStackTraceForRepeating(StackTrace *st);

        virtual std::string getLeaderNodeName(const LeaderPoint* leader) const { return ""; };
        virtual std::string getLeaderNodeName(const columbus::NodeId nodeId) const { return ""; };
        virtual void printOutStackTrace(StackTrace *st) {}
        virtual bool hasPositionInformation(const LeaderPoint* leader) const { return false; }
        virtual bool hasPositionInformation(const columbus::NodeId nodeId) const { return false; }
        virtual void printPositionInformation(const LeaderPoint* leader, std::stringstream& out) const {}
        virtual void printPositionInformation(const columbus::NodeId nodeId, std::stringstream& out) const {}

    public:
        StateListener() : m_exceptions(), m_filteredExceptions() {}
        virtual ~StateListener();

        // Exceptions
        virtual void nullPointerDereferenced(NodeId nodeId, const State& state) {}
        virtual void infiniteLoop(NodeId nodeId, const State& state) {}
        virtual void classCastException(NodeId nodeId, const State& state) {}
        virtual void divisionByZero(NodeId nodeId, const State& state) {}
        virtual void indexOutOfBounds(NodeId nodeId, const State& state, int arrayLength, int index) {}
        virtual void negativeArraySize(NodeId nodeId, const State& state, int arrayLength) {}

        // Other events
        virtual void stateCreated(const State& state) {}
        virtual void definitionAdded(const State& state, SmartDefinition def) {}
        virtual void definitionPushed(const State& state, SmartDefinition definition) {}
        virtual void definitionPoped(const State& state, SmartDefinition definition) {}
        virtual void usedStaticVariable(const columbus::NodeId variableId, const std::vector<State*>& exitStates) {}

        virtual void printOutAllStackTrace();

        //virtual bool isAlreadyExistsLeaderNode(const columbus::NodeId nodeId) const;
        //virtual void getExistingStateIdsForLeaderNode(const columbus::NodeId nodeId, std::vector<StackTrace*>& existingStackTraces) const;
    };
}}

#endif
