#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    StackTrace::StackTrace(ExceptionType _type) : m_exceptionType(_type), m_isRepeated(false), m_trace(), m_leaderPoint(NULL) {}

    StackTrace::~StackTrace() {
        if (m_leaderPoint != NULL) {
            delete m_leaderPoint;
            m_leaderPoint = NULL;
        }
    }

    bool StackTrace::operator<(const StackTrace& rhs) const {
        return this->m_trace.size() < rhs.m_trace.size();
    }

    bool StackTrace::operator==(const StackTrace& rhs) const {
        if (this->m_exceptionType == rhs.m_exceptionType && this->getLeaderPoint() == rhs.getLeaderPoint())
            return true;

        return false;
    }

    std::string StackTrace::toString(TracePointType t) {
        std::string tracePointType = "UNKNOWN";
        switch (t) {
            case ENTRY:
                tracePointType = "ENTRY";
                break;
            case CONTROL:
                tracePointType = "CONTROL";
                break;
            case CALL:
                tracePointType = "CALL";
                break;
            case CALL_RETURN:
                tracePointType = "CALL_RETURN";
                break;
            case DEFINITION:
                tracePointType = "DEFINITION";
                break;
            case EXCEPTION:
                tracePointType = "EXCEPTION";
                break;
            case FIRST_NODE:
                tracePointType = "";
                break;
            case EMPTY:
                tracePointType = "";
                break;
            default:
                break;
        }
        return tracePointType;
    }

    std::string StackTrace::toString(ExceptionType t) {
        std::string exceptionType = "UNKNOWN";
        switch (t) {
            case NULLPOINTER_DEREFERENCE:
                exceptionType = "NULL POINTER DEREFERENCE";
                break;
            case CLASSCAST_EXCEPTION:
                exceptionType = "CLASSCAST EXCEPTION";
                break;
            case INFINITE_LOOP:
                exceptionType = "INFINITE LOOP";
                break;
            case DIVISION_BY_ZERO:
                exceptionType = "DIVISION BY ZERO";
                break;
            case INDEX_OUT_OF_BOUNDS:
                exceptionType = "INDEX OUT OF BOUNDS";
                break;
            case NEGATIVE_ARRAY_SIZE:
                exceptionType = "NEGATIVE ARRAY SIZE";
                break;
            default:
                break;
        }
        return exceptionType;
    }

}}
