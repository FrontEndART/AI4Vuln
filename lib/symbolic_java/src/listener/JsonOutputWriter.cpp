#include "../../inc/common.h"
#include <iomanip>

using std::stringstream;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    JsonOutputWriter::JsonOutputWriter(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact)
        : JavaStateListener(_fact, _cfgFact),
          outStream(
            (Configuration::getInstance()->getOutTxtFile().substr(0,Configuration::getInstance()->getOutTxtFile().length()-3) + "json").c_str(),
             std::ofstream::out | std::ofstream::trunc) 
    {
        stringstream starter;
        starter << "[";
        outStream << starter.str() << endl;
        eId = 0;
	}

    JsonOutputWriter::~JsonOutputWriter() {
        stringstream closing;
        closing << "]";
        outStream << closing.str() << endl;
        outStream.close();
    }

    void JsonOutputWriter::printOutStackTrace(StackTrace* st) {
        // repeated exceptions are not printed
        if (st->getIsRepeated()) {
            return;
        }

        LeaderPoint* lp = st->getLeaderPoint();
        if (hasPositionInformation(lp->getOrigNodeId())) {
            outStream << ((eId>0)?",":"") << "{" << endl;
			++eId;
			outStream <<
                "\"id\": " << "\"" << std::setfill('0') << std::setw(5) << eId << "\"" << "," << endl <<
                "\"name\": " << "\"" << StackTrace::toString(st->getExceptionType()) << "\"" << "," << endl <<
                "\"explanation\": \"";
            /*"\"patches\": [ ]," << endl <<
            "\"textRange\": {" << endl <<*/
            switch (lp->getLeaderPointType()) {
            case columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE: {
                outStream << "Null value dereferenced: " << getLeaderNodeName(lp->getNamedNodeId()) << "\"," << endl;
                break;
            }
            case columbus::symbolic::TYPECAST_LEADER_POINT_TYPE: {
                TypeCastLeaderPoint* tlp = (TypeCastLeaderPoint*)lp;
                outStream << "Cannot cast '" << getLeaderNodeName(tlp->getNamedNodeId()) << "' to type '" << getLeaderNodeName(tlp->getTypeRefId()) << "\"," << endl;
                break;
            }
            case columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE: {
                IndexOutOfBoundsLeaderPoint* ilp = (IndexOutOfBoundsLeaderPoint*)lp;
                outStream << "Array '" << getLeaderNodeName(ilp->getNamedNodeId()) << "' length: " << ilp->getArrayLength() << ", index: " << ilp->getIndex() << "\"," << endl;
                break;
            }
            case columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE: {
                NegativeArraySizeLeaderPoint* nlp = (NegativeArraySizeLeaderPoint*)lp;
                outStream << "New array with size: " << nlp->getArrayLength() << "\"," << endl;
                break;
            }
            case columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE: {
                outStream << "'" << getLeaderNodeName(lp->getNamedNodeId()) << "' divided by 0" << "\"," << endl;
                break;
            }
            default:
                outStream << "(Unhandled leader point type: " << lp->getLeaderPointType() << ")" << "\"," << endl;
                break;
            }
            outStream << "\"tags\": " << "\"CWE-XXXX\"" << "," << endl <<
                "\"items\": [" << endl <<
                "{" << endl <<
                "\"patches\": [ ]," << endl <<
                "\"textrange\": ";
            stringstream sLeader;
            printJsonPositionInformation(lp->getOrigNodeId(), sLeader);
            outStream << sLeader.str() << "," << endl;

        }
        else {
            outStream << "\"err\": \"Unknown position information\"";
            return;
        }

        stringstream trace;
        const std::vector<TracePoint>& tr = st->getTrace();
        for (std::vector<TracePoint>::const_reverse_iterator cit = tr.rbegin(); cit != tr.rend(); ++cit) {
            if (cit == tr.rbegin()) {
                trace << "\"trace\": [" << endl;
            }
                
            if (hasPositionInformation(cit->nodeId)) {
                stringstream sStackTrace;
                printJsonPositionInformation(cit->nodeId, sStackTrace);
                trace << sStackTrace.str() ;
                trace << "," << endl;
            }
            else {
                continue;
            }
        }



        if (hasPositionInformation(lp->getOrigNodeId())) {
            stringstream sLeader;
            printJsonPositionInformation(lp->getOrigNodeId(), sLeader);
            trace << sLeader.str() << endl;
        }
        trace << "]" << endl << "}" << endl << "]" << endl << "}";
        outStream << trace.str() << endl;
    }

}}
