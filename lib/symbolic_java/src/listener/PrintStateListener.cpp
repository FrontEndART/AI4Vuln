#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    PrintStateListener::PrintStateListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact) : JavaStateListener(_fact, _cfgFact) {}

    void PrintStateListener::printOutStackTrace(StackTrace *st) {
        std::string repeated = "";
        if (st->getIsRepeated()) {
            repeated = "REPEATED ";
            return;
        }

        LeaderPoint *lp = st->getLeaderPoint();
        std::string firstType = repeated + StackTrace::toString(st->getExceptionType());
        stringstream firstLine;
        firstLine << firstType << ";Probability: " << lp->getPropability() << ";";

        if (hasPositionInformation(lp->getOrigNodeId())) {
            stringstream sLeader, first;
            printPositionInformation(lp->getOrigNodeId(), sLeader);
            first << sLeader.str() << " ";

            switch (lp->getLeaderPointType()) {
                case columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE: {
                    first << "(Name: " << getLeaderNodeName(lp->getNamedNodeId()) << ")";
                    break;
                }
                case columbus::symbolic::TYPECAST_LEADER_POINT_TYPE: {
                    TypeCastLeaderPoint *tlp = (TypeCastLeaderPoint*)lp;
                    first << "(Cannot cast '" << getLeaderNodeName(tlp->getNamedNodeId()) << "' to type '" << getLeaderNodeName(tlp->getTypeRefId()) << "')";
                    break;
                }
                case columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE: {
                    IndexOutOfBoundsLeaderPoint *ilp = (IndexOutOfBoundsLeaderPoint*)lp;
                    first << "(Array '" << getLeaderNodeName(ilp->getNamedNodeId()) << "' length: " << ilp->getArrayLength() << ", index: " << ilp->getIndex() << ")";
                    break;
                }
                case columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE: {
                    NegativeArraySizeLeaderPoint *nlp = (NegativeArraySizeLeaderPoint*)lp;
                    first << "(new Array with size: " << nlp->getArrayLength() << ")";
                    break;
                }
                case columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE: {
                    first << "('" << getLeaderNodeName(lp->getNamedNodeId()) << "' divided by 0" << ")";
                    break;
                }
                default:
                    first << "(Unhandled leader point type: " << lp->getLeaderPointType() << ")";
                    break;
            }

            firstLine << first.str();

        } else {
            firstLine << "Unknown position information";
        }
        firstLine << std::endl;
        std::cout << firstLine.str();

        const std::vector<TracePoint>& trace = st->getTrace();
        for (std::vector<TracePoint>::const_iterator cit = trace.begin(); cit != trace.end(); ++cit) {
            stringstream line;
            line << ";" << StackTrace::toString(cit->pointType) << ";";
            if (hasPositionInformation(cit->nodeId)) {
                stringstream sStackTrace;
                printPositionInformation(cit->nodeId, sStackTrace);
                line << sStackTrace.str();
            } else {
                // TODO: lehet nem kell ezeket kiirni, mert pl. ki van filterezve
                // continue;
                stringstream posinf;
                posinf << "Unkown position information (nodeId: " << cit->nodeId << ")";
                line << posinf.str();
            }
            line << std::endl;
            std::cout << line.str();
        }
    }

}}
