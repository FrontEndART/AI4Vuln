#include "../../inc/common.h"
#include <regex>

using std::stringstream;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    JavaStateListener::JavaStateListener(columbus::java::asg::Factory& _fact, columbus::cfg::CFGFactory& _cfgFact) : factory(_fact), cfgFactory(_cfgFact) {}

    std::string JavaStateListener::getLeaderNodeName(const columbus::NodeId nodeId) const {
        std::string result = "Not implemented yet";

        if (nodeId == 0)
            return "Filtered out";

        base::Base *node = factory.getPointer(nodeId);
        if (node == NULL)
            return result;

        if (Common::getIsNamed(*node)) {
            return (dynamic_cast<base::Named&>(*node)).getName();

        } else {
            if (Common::getIsFieldAccess(*node)) {
                expr::FieldAccess& fa = dynamic_cast<expr::FieldAccess&>(*node);
                if (fa.getLeftOperand() != NULL)
                    return getLeaderNodeName(fa.getLeftOperand()->getId());
                else
                    return "Unknown";

            } else if (Common::getIsArrayAccess(*node)) {
                expr::ArrayAccess& aa = dynamic_cast<expr::ArrayAccess&>(*node);
                if (aa.getLeftOperand() != NULL)
                    return getLeaderNodeName(aa.getLeftOperand()->getId());
                else
                    return "Unknown";

            } else if (Common::getIsMethodInvocation(*node)) {
                expr::MethodInvocation& mi = dynamic_cast<expr::MethodInvocation&>(*node);
                if (mi.getOperand() != NULL)
                    return getLeaderNodeName(mi.getOperand()->getId());
                else
                    return "Unknown";

            } else if (Common::getIsIdentifier(*node)) {
                expr::Identifier& id = dynamic_cast<expr::Identifier&>(*node);
                if (id.getRefersTo() != NULL)
                    return getLeaderNodeName(id.getRefersTo()->getId());
                else
                    return "Unknown";

            } else if (Common::getIsSuper(*node)) {
                base::Base *parent = node->getParent();
                if (Common::getIsMethodInvocation(*parent))
                    return "super " + getLeaderNodeName(SymbolicTypesPreVisitor::getSuperClassId(parent->getId()));
                else
                    return "super";

            } else if (Common::getIsLiteral(*node)) {
                return "Literal";

            } else if (Common::getIsNullType(*node)) {
                return "NULL";

            // TODO: a tobbi primitiv tipusra is!
            } else if (Common::getIsLongType(*node)) {
                return "long";

            } else if (Common::getIsErrorType(*node)) {
                return "ErrorType";

            }
        }

        return result;
    }

    template <> LeaderPoint* JavaStateListener::calculateLeaderPoint<columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE>(const NodeId nodeId, double prop) const {
        columbus::java::asg::Factory::TurnFilterOffSafely sfact(factory);
        NodeId namedId = calculateLeaderNamedPoint(nodeId);
        const columbus::java::asg::Range& range = getPosition(nodeId);
        NullPointerLeaderPoint *result = new NullPointerLeaderPoint(nodeId, namedId, range.getLine(), range.getCol(), prop);
        return result;
    }

    template <> LeaderPoint* JavaStateListener::calculateLeaderPoint<columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE>(const NodeId nodeId, double prop) const {
        columbus::java::asg::Factory::TurnFilterOffSafely sfact(factory);
        NodeId namedId = calculateLeaderNamedPoint(nodeId);
        const columbus::java::asg::Range& range = getPosition(nodeId);
        IndexOutOfBoundsLeaderPoint *result = new IndexOutOfBoundsLeaderPoint(nodeId, namedId, range.getLine(), range.getCol(), prop);
        return result;
    }

    template <> LeaderPoint* JavaStateListener::calculateLeaderPoint<columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE>(const NodeId nodeId, double prop) const {
        //columbus::java::asg::Factory::TurnFilterOffSafely sfact(factory);
        NodeId namedId = 0;//calculateLeaderNamedPoint(nodeId);
        const columbus::java::asg::Range& range = getPosition(nodeId);
        NegativeArraySizeLeaderPoint *result = new NegativeArraySizeLeaderPoint(nodeId, namedId, range.getLine(), range.getCol(), prop);
        return result;
    }

    template <> LeaderPoint* JavaStateListener::calculateLeaderPoint<columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE>(const NodeId nodeId, double prop) const {
        columbus::java::asg::Factory::TurnFilterOffSafely sfact(factory);
        NodeId namedId = 0;

        base::Base *base = factory.getPointer(nodeId);
        if (Common::getIsInfixExpression(*base)) {
            expr::InfixExpression *infix = dynamic_cast<expr::InfixExpression*>(base);
            if (infix->getLeftOperand() != NULL)
                namedId = calculateLeaderNamedPoint(infix->getLeftOperand()->getId());

        } else if (Common::getIsAssignment(*base)) {
            expr::Assignment *ass = dynamic_cast<expr::Assignment*>(base);
            if (ass->getLeftOperand() != NULL)
                namedId = calculateLeaderNamedPoint(ass->getLeftOperand()->getId());
        }

        const columbus::java::asg::Range& range = getPosition(nodeId);
        DivisionByZeroLeaderPoint *result = new DivisionByZeroLeaderPoint(nodeId, namedId, range.getLine(), range.getCol(), prop);
        return result;
    }

    template <> LeaderPoint* JavaStateListener::calculateLeaderPoint<columbus::symbolic::TYPECAST_LEADER_POINT_TYPE>(const NodeId nodeId, double prop) const {
        columbus::java::asg::Factory::TurnFilterOffSafely sfact(factory);
        NodeId namedId = 0;
        NodeId typeOperand = 0;
        NodeId typeRef = 0;

        base::Base *base = factory.getPointer(nodeId);
        if (Common::getIsTypeCast(*base)) {
            namedId = calculateLeaderNamedPoint(nodeId);
            expr::TypeCast *tc = dynamic_cast<expr::TypeCast*>(base);
            if (tc->getTypeOperand() != NULL) {
                if (tc->getTypeOperand()->getType() != NULL)
                    typeOperand = tc->getTypeOperand()->getType()->getId();

                else {
                    // Type is filtered
                }
            }

        } else if (Common::getIsParameter(*base)) {
            struc::Parameter *par = dynamic_cast<struc::Parameter*>(base);
            if (par->getType() != NULL) {
                if (par->getType()->getType() != NULL) {
                    typeOperand = par->getType()->getType()->getId();

                } else {
                    // Type is filtered
                }
            }

        } else if (Common::getIsAssignment(*base)) {
            expr::Assignment *ass = dynamic_cast<expr::Assignment*>(base);
            if (ass->getRightOperand() != NULL)
                namedId = calculateLeaderNamedPoint(ass->getRightOperand()->getId());

            if (ass->getLeftOperand() != NULL) {
                expr::Expression *left = ass->getLeftOperand();
                if (left->getType() != NULL) {
                    typeOperand = left->getType()->getId();

                } else {
                    // Type is filtered
                }
            }
        }

        if (typeOperand != 0)
            typeRef = calculateLeaderNamedPoint(typeOperand);

        const columbus::java::asg::Range& range = getPosition(nodeId);
        TypeCastLeaderPoint *result = new TypeCastLeaderPoint(nodeId, namedId, range.getLine(), range.getCol(), typeOperand, typeRef, prop);
        return result;
    }

    NodeId JavaStateListener::calculateLeaderNamedPoint(const columbus::NodeId nodeId, bool isComplexExpression) const {
        NodeId result = 0;

        base::Base *base = factory.getPointer(nodeId);
        if (base != NULL) {
            if (Common::getIsIdentifier(*base)) {
                expr::Identifier *id = dynamic_cast<expr::Identifier*>(base);
                if (id->getRefersTo() != NULL) {
                    result = id->getRefersTo()->getId();

                } else {
                    // refersTo is filtered
                }

            } else if (Common::getIsMethodInvocation(*base)) {
                expr::MethodInvocation *mi = dynamic_cast<expr::MethodInvocation*>(base);
                if (mi->getInvokes() != NULL) {
                    result = mi->getInvokes()->getId();

                } else {
                    // invokes is filtered
                }

            } else if (Common::getIsFieldAccess(*base)) {
                expr::FieldAccess *fa = dynamic_cast<expr::FieldAccess*>(base);
                expr::Expression* expr = NULL;
                if (isComplexExpression)
                    expr = fa->getRightOperand();
                else
                    expr = fa->getLeftOperand();

                if (expr != NULL)
                    result = calculateLeaderNamedPoint(expr->getId(), true);

            } else if (Common::getIsTypeCast(*base)) {
                expr::TypeCast *tc = dynamic_cast<expr::TypeCast*>(base);
                expr::Expression *operand = tc->getOperand();
                if (operand != NULL)
                    result = calculateLeaderNamedPoint(operand->getId());

            } else if (Common::getIsParameter(*base)) {
                result = base->getId();

            } else if (Common::getIsArrayAccess(*base)) {
                expr::ArrayAccess *aa = dynamic_cast<expr::ArrayAccess*>(base);
                expr::Expression *left = aa->getLeftOperand();
                if (left != NULL)
                    result = calculateLeaderNamedPoint(left->getId(), true);

            } else if (Common::getIsClassType(*base)) {
                type::ClassType *ct = dynamic_cast<type::ClassType*>(base);
                if (ct->getRefersTo() != NULL)
                    result = ct->getRefersTo()->getId();

            } else if (Common::getIsTypeVariable(*base)) {
                type::TypeVariable* tv = dynamic_cast<type::TypeVariable*>(base);
                if (tv->getRefersTo() != NULL)
                    result = tv->getRefersTo()->getId();

            } else if (Common::getIsNewClass(*base)) {
                expr::NewClass *nc = dynamic_cast<expr::NewClass*>(base);
                if (nc->getType() != NULL)
                    result = calculateLeaderNamedPoint(nc->getType()->getId());

            } else if (Common::getIsParameterizedType(*base)) {
                type::ParameterizedType *pt = dynamic_cast<type::ParameterizedType*>(base);
                if (pt->getRawType() != NULL)
                    result = calculateLeaderNamedPoint(pt->getRawType()->getId());

            } else if (Common::getIsParenthesizedExpression(*base)) {
                expr::ParenthesizedExpression *pe = dynamic_cast<expr::ParenthesizedExpression*>(base);
                if (pe->getType() != NULL)
                    result = calculateLeaderNamedPoint(pe->getType()->getId());

            } else if (Common::getIsErrorType(*base)) {
                result = nodeId;

            } else if (Common::getIsNullLiteral(*base)) {
                expr::NullLiteral *nl = dynamic_cast<expr::NullLiteral*>(base);
                if (nl->getType() != NULL)
                    result = nl->getType()->getId();

            } else if (Common::getIsLiteral(*base)) {
                return nodeId;

            } else if (Common::getIsArrayType(*base)) {
                type::ArrayType *at = dynamic_cast<type::ArrayType*>(base);
                if (at->getComponentType() != NULL)
                    result = calculateLeaderNamedPoint(at->getComponentType()->getId());

            } else if (Common::getIsThis(*base)) {
                expr::This *thiz = dynamic_cast<expr::This*>(base);
                if (thiz->getType() != NULL)
                    result = calculateLeaderNamedPoint(thiz->getType()->getId());

            // TODO: a tobbi primitiv tipusra is!
            } else if (Common::getIsLongType(*base)) {
                result = base->getId();

            } else {
                // Unhandled nodeKind
            }
        }
        return result;
    }

    bool JavaStateListener::hasPositionInformation(NodeId nodeId) const {
        columbus::java::asg::base::Base& base = factory.getRef(nodeId);
        if (!columbus::java::asg::Common::getIsPositioned(base))
            return false;

        const columbus::java::asg::Range& range = getPosition(nodeId);
        if (range.getLine() == 0 && range.getCol() == 0 && range.getEndLine() == 0 && range.getEndCol() == 0)
            return false;

        return true;
    }

    const columbus::java::asg::Range JavaStateListener::getPosition(const columbus::NodeId nodeId) const {
        columbus::java::asg::base::Base& base = factory.getRef(nodeId);
        columbus::java::asg::base::Positioned& pos = dynamic_cast<columbus::java::asg::base::Positioned&>(base);
        return pos.getPosition();
    }

    void JavaStateListener::printPositionInformation(NodeId nodeId, stringstream& out) const {
        if (!hasPositionInformation(nodeId))
            return;

        const columbus::java::asg::Range& range = getPosition(nodeId);
        if (range.getLine() == 0 && range.getCol() == 0 && range.getEndLine() == 0 && range.getEndCol() == 0) {
            base::Base *base = factory.getPointer(nodeId);
            if (base != NULL && Common::getIsNamed(*base)) {
                if (Common::getIsNormalMethod(*base)) {
                    struc::NormalMethod* md = dynamic_cast<struc::NormalMethod*>(base);
                    if (md->getMethodKind() == mekConstructor)
                        out << (dynamic_cast<base::Named*>(base))->getName() << " (Constructor, no line info, nodeId: " << nodeId << ")";
                    else if (md->getMethodKind() == mekGeneratedDefaultConstructor)
                        out << (dynamic_cast<base::Named*>(base))->getName() << " (Generated default constructor, no line info, nodeId: " << nodeId << ")";
                    else if (md->getMethodKind() == mekGeneratedAnonymousClassConstructor)
                        out << (dynamic_cast<base::Named*>(base))->getName() << " (Generated anonymous class constructor, no line info, nodeId: " << nodeId << ")";
                    else if (md->getMethodKind() == mekNormal)
                        out << (dynamic_cast<base::Named*>(base))->getName() << " (method, no line info, nodeId: " << nodeId << ")";
                } else
                    out << (dynamic_cast<base::Named*>(base))->getName() << " (no line info, nodeId: " << nodeId << ")";

            } else {
                out << getLeaderNodeName(nodeId) << " (no line info, nodeId: " << nodeId << ")";
            }
            return;
        }

        out << range.getPath() << "(" << range.getLine() << "):" << " [" << range.getLine() << ":" << range.getCol() << "-" << range.getEndLine() << ":" << range.getEndCol() << "]";
    }

    std::string replaceBackslashes(const std::string& input) {
        std::regex backslash_regex("\\\\"); 
        return std::regex_replace(input, backslash_regex, "\\\\");
    }

    void JavaStateListener::printJsonPositionInformation(NodeId nodeId, stringstream& out) const {
        if (!hasPositionInformation(nodeId)){
            return;
        }
        const columbus::java::asg::Range& range = getPosition(nodeId);
        out << "{" << endl << 
            "\"file\": \"" << replaceBackslashes(range.getPath()) << "\"," << endl <<
            "\"endLine\": " << range.getEndLine() << "," << endl <<
            "\"endColumn\": " << range.getEndCol() << "," << endl <<
            "\"startColumn\": " << range.getCol() << "," << endl <<
            "\"startLine\": " << range.getLine() << endl <<
            "}";
    }

    // Exceptions
    void JavaStateListener::nullPointerDereferenced(columbus::NodeId nodeId, const State& state) {
        LeaderPoint *lp = calculateLeaderPoint<columbus::symbolic::NULL_POINTER_LEADER_POINT_TYPE>(nodeId, 1);
        createStackTrace(columbus::symbolic::NULLPOINTER_DEREFERENCE, lp, nodeId, state);
    }

    void JavaStateListener::classCastException(columbus::NodeId nodeId, const State& state) {
        LeaderPoint *lp = calculateLeaderPoint<columbus::symbolic::TYPECAST_LEADER_POINT_TYPE>(nodeId, 1);
        createStackTrace(columbus::symbolic::CLASSCAST_EXCEPTION, lp, nodeId, state);
    }

    void JavaStateListener::divisionByZero(columbus::NodeId nodeId, const State& state) {
        LeaderPoint *lp = calculateLeaderPoint<columbus::symbolic::DIVISION_BY_ZERO_LEADER_POINT_TYPE>(nodeId, 1);
        createStackTrace(columbus::symbolic::DIVISION_BY_ZERO, lp, nodeId, state);
    }

    void JavaStateListener::indexOutOfBounds(columbus::NodeId nodeId, const State& state, int arrayLength, int index) {
        IndexOutOfBoundsLeaderPoint *lp = (IndexOutOfBoundsLeaderPoint*)(calculateLeaderPoint<columbus::symbolic::INDEX_OUT_OF_BOUNDS_LEADER_POINT_TYPE>(nodeId, 1));
        lp->setArrayLenght(arrayLength);
        lp->setIndex(index);
        createStackTrace(columbus::symbolic::INDEX_OUT_OF_BOUNDS, lp, nodeId, state);
    }

    void JavaStateListener::negativeArraySize(columbus::NodeId nodeId, const State& state, int arrayLength) {
        NegativeArraySizeLeaderPoint *lp = (NegativeArraySizeLeaderPoint*)(calculateLeaderPoint<columbus::symbolic::NEGATIVE_ARRAY_SIZE_LEADER_POINT_TYPE>(nodeId, 1));
        lp->setArrayLenght(arrayLength);
        createStackTrace(columbus::symbolic::NEGATIVE_ARRAY_SIZE, lp, nodeId, state);
    }

}}
