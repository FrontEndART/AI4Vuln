#include "../../inc/common.h"

using std::stringstream;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    TxtOutputWriter::TxtOutputWriter(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact) 
        : JavaStateListener(_fact, _cfgFact),
          outStream(Configuration::getInstance()->getOutTxtFile().c_str(), std::ofstream::out | std::ofstream::trunc) 
    {
	}

    TxtOutputWriter::~TxtOutputWriter() {
        outStream.close();
    }

    void TxtOutputWriter::printOutStackTrace(StackTrace *st) {
        // repeated exceptions are not printed
        if (st->getIsRepeated()) {
            return;
        }

        LeaderPoint *lp = st->getLeaderPoint();
        if (hasPositionInformation(lp->getOrigNodeId())) {

            switch (lp->getLeaderPointType()) {
                case columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE: {
                    outStream << "Null value dereferenced: " << getLeaderNodeName(lp->getNamedNodeId()) << endl;
                    break;
                }
                case columbus::symbolic::TYPECAST_LEADER_POINT_TYPE: {
                    TypeCastLeaderPoint *tlp = (TypeCastLeaderPoint*)lp;
                    outStream << "Cannot cast '" << getLeaderNodeName(tlp->getNamedNodeId()) << "' to type '" << getLeaderNodeName(tlp->getTypeRefId()) << endl;
                    break;
                }
                case columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE: {
                    IndexOutOfBoundsLeaderPoint *ilp = (IndexOutOfBoundsLeaderPoint*)lp;
                    outStream << "Array '" << getLeaderNodeName(ilp->getNamedNodeId()) << "' length: " << ilp->getArrayLength() << ", index: " << ilp->getIndex() << endl;
                    break;
                }
                case columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE: {
                    NegativeArraySizeLeaderPoint *nlp = (NegativeArraySizeLeaderPoint*)lp;
                    outStream << "New array with size: " << nlp->getArrayLength() << endl;
                    break;
                }
                case columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE: {
                    outStream << "'" << getLeaderNodeName(lp->getNamedNodeId()) << "' divided by 0" << endl;
                    break;
                }
                default:
                    outStream << "(Unhandled leader point type: " << lp->getLeaderPointType() << ")" << endl;
                    break;
            }
            stringstream sLeader;
            outStream << "Position:" << endl;
            printPositionInformation(lp->getOrigNodeId(), sLeader);
            outStream << sLeader.str() << endl;

        } else {
            outStream << "Unknown position information";
        }

        outStream << "Trace: " << endl;
        stringstream trace;
        const std::vector<TracePoint>& tr = st->getTrace();
        for (std::vector<TracePoint>::const_reverse_iterator cit = tr.rbegin(); cit != tr.rend(); ++cit) {
            if (hasPositionInformation(cit->nodeId)) {
                stringstream sStackTrace;
                printPositionInformation(cit->nodeId, sStackTrace);
                trace << sStackTrace.str();
                if (cit->pointType != columbus::symbolic::EMPTY) {
                    trace << "[" << StackTrace::toString(cit->pointType) << "]";
                } else { 
                    trace << "[CONTROL]";
                } 
            } else {
                continue;
            }
            trace << endl;
        }

        if (hasPositionInformation(lp->getOrigNodeId())) {
            stringstream sLeader;
            printPositionInformation(lp->getOrigNodeId(), sLeader);
            trace << sLeader.str() << endl;
        }

        outStream << trace.str() << endl;
    }

}}
