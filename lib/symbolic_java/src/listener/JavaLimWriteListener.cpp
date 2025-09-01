#include "../../inc/common.h"
#include "graphsupport/inc/GraphConstants.h"
#include "graphsupport/inc/Metric.h"

using std::stringstream;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    JavaLimWriteListener::JavaLimWriteListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact, columbus::graph::Graph* _graph, WarningListener& wl) 
          : JavaStateListener(_fact, _cfgFact), m_graph(_graph), warningListener(wl) {
    }

    JavaLimWriteListener::~JavaLimWriteListener() {
    }

    void JavaLimWriteListener::setEngine(SymbolicEngine* engine) {
        this->engine = engine;
    }
 

    void JavaLimWriteListener::printOutStackTrace(StackTrace *st) {
        std::string repeated = "";
        if (st->getIsRepeated()) {
            repeated = "REPEATED ";
            return;
        }
        
        
        graph::AttributeComposite extraInfo;
        if (m_graph != NULL)
          extraInfo = m_graph->createAttributeComposite(graphsupport::graphconstants::ATTR_EXTRAINFO, graphsupport::graphconstants::CONTEXT_TRACE);


        LeaderPoint *lp = st->getLeaderPoint();
        std::string firstType = repeated + StackTrace::toString(st->getExceptionType());
        stringstream warningText;

        if (hasPositionInformation(lp->getOrigNodeId())) {
            stringstream sLeader;
            printPositionInformation(lp->getOrigNodeId(), sLeader);

            switch (lp->getLeaderPointType()) {
                case columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE: {
                    warningText << "Dereferenced null value: " << getLeaderNodeName(lp->getNamedNodeId());
                    break;
                }
                case columbus::symbolic::TYPECAST_LEADER_POINT_TYPE: {
                    TypeCastLeaderPoint *tlp = (TypeCastLeaderPoint*)lp;
                    warningText << "Cannot cast '" << getLeaderNodeName(tlp->getNamedNodeId()) << "' to type '" << getLeaderNodeName(tlp->getTypeRefId()) << "'";
                    break;
                }
                case columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE: {
                    IndexOutOfBoundsLeaderPoint *ilp = (IndexOutOfBoundsLeaderPoint*)lp;
                    warningText << "Array '" << getLeaderNodeName(ilp->getNamedNodeId()) << "' length: " << ilp->getArrayLength() << ", index: " << ilp->getIndex();
                    break;
                }
                case columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE: {
                    NegativeArraySizeLeaderPoint *nlp = (NegativeArraySizeLeaderPoint*)lp;
                    warningText << "New array with size: " << nlp->getArrayLength();
                    break;
                }
                case columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE: {
                    warningText << "'" << getLeaderNodeName(lp->getNamedNodeId()) << "' divided by 0";
                    break;
                }
                default:
                    //warningText << "(Unhandled leader point type: " << lp->getLeaderPointType() << ")";
                    break;
            }

        } else {
            warningText << "Unknown position information";
        }
        warningText << std::endl;

        const std::vector<TracePoint>& trace = st->getTrace();
        for (std::vector<TracePoint>::const_reverse_iterator cit = trace.rbegin(); cit != trace.rend(); ++cit) {
            if (hasPositionInformation(cit->nodeId)) {
                stringstream sStackTrace;
                printPositionInformation(cit->nodeId, sStackTrace);
                
                if (m_graph != NULL) {

                    java::asg::Range pos = dynamic_cast<java::asg::base::Positioned&>(factory.getRef(cit->nodeId)).getPosition();
                    if (cit->pointType == ENTRY) {
                        const java::asg::struc::MethodDeclaration &methodDecl = dynamic_cast<const java::asg::struc::MethodDeclaration&>(factory.getRef(cit->nodeId));
                        java::asg::Range paramPos = methodDecl.getParametersEndPosition();
                        graph::AttributeComposite sourceLink = graphsupport::createSourceLinkAttribute(*m_graph, pos.getPath(), pos.getWideLine(), pos.getWideCol(), paramPos.getWideEndLine(), paramPos.getWideEndCol());
                        sourceLink.addAttribute(m_graph->createAttributeInt(graphsupport::graphconstants::ATTR_CALLSTACKDEPTH, "", cit->callStackDept));
                        extraInfo.addAttribute(sourceLink);
                    } else if (Common::getIsMethodDeclaration(factory.getRef(cit->nodeId))) {
                        const java::asg::struc::MethodDeclaration &methodDecl = dynamic_cast<const java::asg::struc::MethodDeclaration&>(factory.getRef(cit->nodeId));
                        java::asg::Range namePos = methodDecl.getNamePosition();
                        graph::AttributeComposite sourceLink = graphsupport::createSourceLinkAttribute(*m_graph, pos.getPath(), namePos.getWideLine(), namePos.getWideCol(), namePos.getWideEndLine(), namePos.getWideEndCol());
                        sourceLink.addAttribute(m_graph->createAttributeInt(graphsupport::graphconstants::ATTR_CALLSTACKDEPTH, "", cit->callStackDept));
                        extraInfo.addAttribute(sourceLink);
                    } else {
                        graph::AttributeComposite sourceLink = graphsupport::createSourceLinkAttribute(*m_graph, pos.getPath(), pos.getWideLine(), pos.getWideCol(), pos.getWideEndLine(), pos.getWideEndCol());
                        sourceLink.addAttribute(m_graph->createAttributeInt(graphsupport::graphconstants::ATTR_CALLSTACKDEPTH, "", cit->callStackDept));
                        extraInfo.addAttribute(sourceLink);
                    }
                }
                
            } else {
                // TODO: lehet nem kell ezeket kiirni, mert pl. ki van filterezve
                // continue;
            }
        }

        std::string checkerId = "";
        if (st->getExceptionType() == NULLPOINTER_DEREFERENCE)
            checkerId = SYMBOLIC_NULL_POINTER_EXCEPTION_RULECHECKER_ID;
        else if (st->getExceptionType() == CLASSCAST_EXCEPTION)
            checkerId = SYMBOLIC_CLASS_CAST_EXCEPTION_RULECHECKER_ID;
        else if (st->getExceptionType() == INFINITE_LOOP)
            checkerId = SYMBOLIC_INFINITE_LOPP_RULECHECKER_ID;
        else if (st->getExceptionType() == DIVISION_BY_ZERO)
            checkerId = SYMBOLIC_DIVISION_BY_ZERO_RULECHECKER_ID;
        else if (st->getExceptionType() == INDEX_OUT_OF_BOUNDS)
            checkerId = SYMBOLIC_INDEX_OUT_OF_BOUNDS_EXCEPTION_RULECHECKER_ID;
        else if (st->getExceptionType() == NEGATIVE_ARRAY_SIZE)
            checkerId = SYMBOLIC_INDEX_NEGATIVE_ARRAY_SIZE_RULECHECKER_ID;
        warningText << std::endl;
        warningListener.addWarning(checkerId, lp->getOrigNodeId(), warningText.str(), &extraInfo);
    }


    // Exceptions
    //void JavaLimWriteListener::nullPointerDereferenced(columbus::NodeId nodeId, const State& state) {
    //    JavaStateListener::nullPointerDereferenced(nodeId, state);
    //    StackTrace *lastTrace = m_exceptions.back();
    //    printOutStackTrace(lastTrace);
    //}

    //void JavaLimWriteListener::classCastException(columbus::NodeId nodeId, const State& state) {
    //    JavaStateListener::classCastException(nodeId, state);
    //    StackTrace *lastTrace = m_exceptions.back();
    //    printOutStackTrace(lastTrace);
    //}

    //void JavaLimWriteListener::divisionByZero(columbus::NodeId nodeId, const State& state) {
    //    JavaStateListener::divisionByZero(nodeId, state);
    //    StackTrace *lastTrace = m_exceptions.back();
    //    printOutStackTrace(lastTrace);
    //}

    //void JavaLimWriteListener::indexOutOfBounds(columbus::NodeId nodeId, const State& state, int arrayLength, int index) {
    //    JavaStateListener::indexOutOfBounds(nodeId, state, arrayLength, index);
    //    StackTrace *lastTrace = m_exceptions.back();
    //    printOutStackTrace(lastTrace);
    //}

    //void JavaLimWriteListener::negativeArraySize(columbus::NodeId nodeId, const State& state, int arrayLength) {
    //    JavaStateListener::negativeArraySize(nodeId, state, arrayLength);
    //    StackTrace *lastTrace = m_exceptions.back();
    //    printOutStackTrace(lastTrace);
    //}
}}
