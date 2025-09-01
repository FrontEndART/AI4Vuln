#ifndef _STACK_TRACE_H
#define _STACK_TRACE_H

#include "../common.h"

namespace columbus { namespace symbolic {

    enum ExceptionType {
        EXCEPTIONTYPE_BEGIN = 0,
        NULLPOINTER_DEREFERENCE = 0,
        CLASSCAST_EXCEPTION,
        INFINITE_LOOP,
        DIVISION_BY_ZERO,
        INDEX_OUT_OF_BOUNDS,
        NEGATIVE_ARRAY_SIZE,
        EXCEPTIONTYPE_END
    };

    enum TracePointType {
        CONTROL,
        CALL,
        CALL_RETURN,
        DEFINITION,
        EXCEPTION,
        FIRST_NODE,
        ENTRY,
        EMPTY
    };

    enum LeaderPointType {
        NULL_POINTER_LEADER_POINT_TYPE,
        TYPECAST_LEADER_POINT_TYPE,
        DIVISION_BY_ZERO_LEADER_POINT_TYPE,
        INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE,
        NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE
    };

    typedef struct TracePoint {
        columbus::NodeId nodeId;
        TracePointType   pointType;
        unsigned int     stateId;
        unsigned long    callStackDept;

        unsigned int getStateId() { return stateId; }
    } TracePoint;

    class LeaderPoint {
    protected:
        LeaderPointType  m_leaderPointType;
        unsigned int     m_line;
        unsigned int     m_col;
        columbus::NodeId m_origNodeId;
        columbus::NodeId m_namedNodeId;
        double           m_propability;

    public:
        LeaderPoint(LeaderPointType pt, columbus::NodeId nodeId, columbus::NodeId namedId, unsigned int line, unsigned int col, double prop) : m_leaderPointType(pt), m_line(line), m_col(col), m_origNodeId(nodeId), m_namedNodeId(namedId), m_propability(prop) {}
        virtual ~LeaderPoint() {}

        virtual bool operator<(const LeaderPoint* right) const {
            return m_origNodeId < right->m_origNodeId;
        }

        virtual bool operator==(const LeaderPoint* right) {
            if (m_leaderPointType != right->getLeaderPointType())
                return false;

            return m_origNodeId == right->m_origNodeId;
        }

        inline LeaderPointType getLeaderPointType() const { return m_leaderPointType; }
        inline columbus::NodeId getOrigNodeId() const { return m_origNodeId; }
        inline columbus::NodeId getNamedNodeId() const { return m_namedNodeId; }
        inline unsigned int getLine() const { return m_line; }
        inline unsigned int getCol() const { return m_col; }
        inline double getPropability() const { return m_propability; }
    };

    class NullPointerLeaderPoint : public LeaderPoint {
    public:
        NullPointerLeaderPoint(columbus::NodeId nodeId, columbus::NodeId namedId, unsigned int line, unsigned int col, double prop) : LeaderPoint(columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE, nodeId, namedId, line, col, prop) {}

        virtual bool operator<(const LeaderPoint* right)const override {
            const NullPointerLeaderPoint *r = (NullPointerLeaderPoint*)right;
            return m_namedNodeId < r->m_namedNodeId;
        }

        virtual bool operator==(const LeaderPoint* right) override {
            if (m_leaderPointType != right->getLeaderPointType())
                return false;

            const NullPointerLeaderPoint *r = (NullPointerLeaderPoint*)right;
            return m_namedNodeId == r->m_namedNodeId;
        }
    };

    class TypeCastLeaderPoint : public LeaderPoint {
    private:
        columbus::NodeId m_typeOperand;
        columbus::NodeId m_typeRef;

    public:
        TypeCastLeaderPoint(columbus::NodeId nodeId, columbus::NodeId namedId, unsigned int line, unsigned int col, columbus::NodeId typeOperand, columbus::NodeId typeRef, double prop) : LeaderPoint(columbus::symbolic::TYPECAST_LEADER_POINT_TYPE, nodeId, namedId, line, col, prop), m_typeOperand(typeOperand), m_typeRef(typeRef) {}

        inline columbus::NodeId getTypeOperandId() const { return m_typeOperand; }
        inline columbus::NodeId getTypeRefId() const { return m_typeRef; }

        virtual bool operator<(const LeaderPoint* right) const override {
            const TypeCastLeaderPoint *r = (TypeCastLeaderPoint*)right;
            //if (m_namedNodeId < r->m_namedNodeId)
            if (m_namedNodeId != r->m_namedNodeId)
                return m_namedNodeId < r->m_namedNodeId;
            else
                return m_typeRef < r->m_typeRef;
        }

        virtual bool operator==(const LeaderPoint* right) override {
            if (m_leaderPointType != right->getLeaderPointType())
                return false;

            const TypeCastLeaderPoint *r = (TypeCastLeaderPoint*)right;
            return m_typeRef == r->m_typeRef && m_namedNodeId == r->m_namedNodeId;
        }
    };

    class DivisionByZeroLeaderPoint : public LeaderPoint {
    public:
        DivisionByZeroLeaderPoint(columbus::NodeId nodeId, columbus::NodeId namedId, unsigned int line, unsigned int col, double prop) : LeaderPoint(columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE, nodeId, namedId, line, col, prop) {}
    };

    class NegativeArraySizeLeaderPoint : public LeaderPoint {
    private:
        int m_arrayLength;

    public:
        NegativeArraySizeLeaderPoint(columbus::NodeId nodeId, columbus::NodeId namedId, unsigned int line, unsigned int col, double prop) : LeaderPoint(columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE, nodeId, namedId, line, col, prop), m_arrayLength(0) {}

        inline int getArrayLength() const { return m_arrayLength; }
        inline void setArrayLenght(int length) { m_arrayLength = length; }
    };

    class IndexOutOfBoundsLeaderPoint : public LeaderPoint {
    private:
        int m_arrayLength;
        int m_index;

    public:
        IndexOutOfBoundsLeaderPoint(columbus::NodeId nodeId, columbus::NodeId namedId, unsigned int line, unsigned int col, double prop) : LeaderPoint(columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE, nodeId, namedId, line, col, prop), m_arrayLength(0), m_index(0) {}

        inline int getArrayLength() const { return m_arrayLength; }
        inline void setArrayLenght(int length) { m_arrayLength = length; }
        inline int getIndex() const { return m_index; }
        inline void setIndex(int index) { m_index = index; }
    };

    class StackTrace {
    protected:
        ExceptionType m_exceptionType;
        bool m_isRepeated;
        std::vector<TracePoint> m_trace;
        LeaderPoint *m_leaderPoint;

    public:
        StackTrace(ExceptionType _type);
        virtual ~StackTrace();

        inline void setIsRepeated(bool _rep) { m_isRepeated = _rep; }
        inline bool getIsRepeated() const { return m_isRepeated; }
        inline ExceptionType getExceptionType() const { return m_exceptionType; }
        inline LeaderPoint* getLeaderPoint() const { return m_leaderPoint; }
        inline void setLeaderPoint(LeaderPoint* leader) { m_leaderPoint = leader;}
        inline void addTracePoint(const TracePoint tracePoint) { m_trace.push_back(tracePoint); }
        const std::vector<TracePoint>& getTrace() const { return m_trace; }
        std::vector<TracePoint>& getTrace() { return m_trace; }

        static std::string toString(TracePointType t);
        static std::string toString(ExceptionType t);
        bool operator<(const StackTrace& rhs) const;
        bool operator==(const StackTrace& rhs) const;
    };

    struct StackTrace_compare {
        bool operator() (const StackTrace *l, const StackTrace *r) const {
            return l->getLeaderPoint()->operator<(r->getLeaderPoint());
        }
    };

    struct StackTrace_compare_by_Probability {
        bool operator() (const StackTrace *l, const StackTrace *r) const {
            // Sort descending by probability
            if (l->getLeaderPoint()->getPropability() > r->getLeaderPoint()->getPropability())
                return true;
            else if (l->getLeaderPoint()->getPropability() < r->getLeaderPoint()->getPropability())
                return false;
            else {
                // Sort ascending by trace length
                if (l->getTrace().size() < r->getTrace().size())
                    return true;
                return false;
            }
        }
    };

}}

#endif
