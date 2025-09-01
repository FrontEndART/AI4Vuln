#include "../../inc/common.h"

using std::stringstream;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    CsvStateListener::CsvStateListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact) : JavaStateListener(_fact, _cfgFact),
            csv(Configuration::getInstance()->getOutCsvFile(), io::IOBase::omWrite) {
        csv.writeColumn("\"Type\"");
        csv.writeColumn("\"Probability\"");
        csv.writeColumn("\"Trace\"");
        csv.writeNewLine();
	}

    CsvStateListener::~CsvStateListener() {
        csv.flush();
        csv.close();
    }

    void CsvStateListener::printOutStackTrace(StackTrace *st) {
        std::string repeated = "";
        if (st->getIsRepeated()) {
            repeated = "REPEATED ";
            return;
        }

        LeaderPoint *lp = st->getLeaderPoint();
        std::string firstType = "\"" + repeated + StackTrace::toString(st->getExceptionType()) + "\"";
        csv.writeColumn(firstType);

        stringstream w;
        w << "\"" << lp->getPropability() << "\"";
        csv.writeColumn(w.str());

        stringstream trace;
        trace << "\"";
        if (hasPositionInformation(lp->getOrigNodeId())) {
            stringstream sLeader;
            printPositionInformation(lp->getOrigNodeId(), sLeader);
            trace << sLeader.str() << " ";

            switch (lp->getLeaderPointType()) {
                case columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE: {
                    trace << "(Name: " << getLeaderNodeName(lp->getNamedNodeId()) << ")";
                    break;
                }
                case columbus::symbolic::TYPECAST_LEADER_POINT_TYPE: {
                    TypeCastLeaderPoint *tlp = (TypeCastLeaderPoint*)lp;
                    trace << "(Cannot cast '" << getLeaderNodeName(tlp->getNamedNodeId()) << "' to type '" << getLeaderNodeName(tlp->getTypeRefId()) << "')";
                    //first << " orig: " << lp->getOrigNodeId() << " named: " << lp->getNamedNodeId() << " typeOp: " << tlp->getTypeOperandId() << " typeRef: " << tlp->getTypeRefId();
                    break;
                }
                case columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE: {
                    IndexOutOfBoundsLeaderPoint *ilp = (IndexOutOfBoundsLeaderPoint*)lp;
                    trace << "(Array '" << getLeaderNodeName(ilp->getNamedNodeId()) << "' length: " << ilp->getArrayLength() << ", index: " << ilp->getIndex() << ")";
                    break;
                }
                case columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE: {
                    NegativeArraySizeLeaderPoint *nlp = (NegativeArraySizeLeaderPoint*)lp;
                    trace << "(new Array with size: " << nlp->getArrayLength() << ")";
                    break;
                }
                case columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE: {
                    trace << "('" << getLeaderNodeName(lp->getNamedNodeId()) << "' divided by 0" << ")";
                    break;
                }
                default:
                    trace << "(Unhandled leader point type: " << lp->getLeaderPointType() << ")";
                    break;
            }

        } else {
            trace << "Unknown position information";
        }

        const std::vector<TracePoint>& tr = st->getTrace();
        for (std::vector<TracePoint>::const_iterator cit = tr.begin(); cit != tr.end(); ++cit) {
            if (hasPositionInformation(cit->nodeId)) {
                trace << std::endl;
                if (cit->pointType != columbus::symbolic::EMPTY)
                    trace << StackTrace::toString(cit->pointType) << ": ";

                stringstream sStackTrace;
                printPositionInformation(cit->nodeId, sStackTrace);
                trace << sStackTrace.str();
            } else {
                // TODO: lehet nem kell ezeket kiirni, mert pl. ki van filterezve
                continue;
                /*stringstream posinf;
                posinf << "Unkown position information (nodeId: " << cit->nodeId << ")";
                trace << posinf.str();*/
            }
        }

        trace << "\"";

        csv.writeColumn(trace.str());
        csv.writeNewLine();
        csv.flush();
    }

}}
