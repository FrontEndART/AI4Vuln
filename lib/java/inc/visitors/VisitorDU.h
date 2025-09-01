#ifndef _VISITORDU_JAVA_H
#define _VISITORDU_JAVA_H

/**
 * \file VisitorDU.h
 * \brief Contains the class VisitorDU which implements the visit functions for the ASG nodes.
 */

#include "java/inc/java.h"
#include "cfg/inc/cfg.h"

namespace columbus {
    namespace java {
        namespace asg {

            class VisitorDU : public VisitorAbstractNodes {
            protected:
                /**
                 * \brief ASG Factory.
                 */
                const columbus::java::asg::Factory *m_asgFactory;

                /**
                 * \brief CFG Factory.
                 */
                columbus::cfg::CFGFactory *m_cfgFactory;

                /** \brief The printer class. */
                const columbus::cfg::ASGNodePrinter& m_printer;

                /** \brief It stores the method ids, which has parameter(s).
                 *         The parameters will be post-processed,
                 *         because of find the definition outside the ICFG
                 */
                std::vector<columbus::NodeId> m_methodsWithParameters;

                /**
                 * \brief It checks if the DU info (nodeId) is an initialValue of its parent (Variable).
                 *        If yes, add the parentId to the defined set of duInfo.
                 * \param nodeId [in] The nodeId.
                 */
                void isInitialValue(columbus::NodeId nodeId) const;

                /**
                 * \brief It checks if the DU info (nodeId) is a true/false case of its parent (Conditional).
                 *        If yes, add the parentId to the defined set of duInfo.
                 * \param nodeId [in] The nodeId.
                 */
                void isConditionalValue(columbus::NodeId nodeId) const;

                /**
                 * \brief It checks if the DU info (nodeId) is already exists.
                 * \param nodeId [in] The nodeId.
                 * \return True if the DUInfo is exists, otherwise false.
                 */
                bool isDUInfoExists(const columbus::NodeId nodeId) const;

            public:
                /**
                 * \brief Constructor.
                 * \param asgFactory [in] The ASG Factory.
                 * \param cfgFactory [in] The CFG Factory.
                 */
                VisitorDU(columbus::java::asg::Factory* asgFactory, columbus::cfg::CFGFactory* cfgFactory, const columbus::cfg::ASGNodePrinter& printer);

                /**
                 * \brief Destructor.
                 */
                virtual ~VisitorDU();

                /** \brief Copy constructor. */
                VisitorDU(const VisitorDU& right);

                /** \brief Assignment operator. */
                VisitorDU& operator=(const VisitorDU& right);

                /**
                 * \brief It gets the method ids, which has parameter(s).
                 * \return The method ids vector.
                 */
                const std::vector<columbus::NodeId>& getMethodsWithParameters() const;

                /**
                 * \brief Visitor functions for the different ASG nodes.
                 * \param node [in] The node which is visited.
                 */
                // Unary
                virtual void visit(const expr::PostfixExpression& node, bool callVirtualBase);
                virtual void visitEnd(const expr::PostfixExpression& node, bool callVirtualBase);

                virtual void visit(const expr::PrefixExpression& node, bool callVirtualBase);
                virtual void visitEnd(const expr::PrefixExpression& node, bool callVirtualBase);

                virtual void visit(const expr::InstanceOf& node, bool callVirtualBase);
                virtual void visitEnd(const expr::InstanceOf& node, bool callVirtualBase);

                virtual void visit(const expr::TypeCast& node, bool callVirtualBase);
                virtual void visitEnd(const expr::TypeCast& node, bool callVirtualBase);

                virtual void visit(const expr::MethodInvocation& node, bool callVirtualBase);
                virtual void visitEnd(const expr::MethodInvocation& node, bool callVirtualBase);

                virtual void visit(const expr::ParenthesizedExpression& node, bool callVirtualBase);
                virtual void visitEnd(const expr::ParenthesizedExpression& node, bool callVirtualBase);

                // Binary
                virtual void visit(const expr::InfixExpression& node, bool callVirtualBase);
                virtual void visitEnd(const expr::InfixExpression& node, bool callVirtualBase);

                virtual void visit(const expr::Assignment& node, bool callVirtualBase);
                virtual void visitEnd(const expr::Assignment& node, bool callVirtualBase);

                virtual void visit(const expr::ArrayAccess& node, bool callVirtualBase);
                virtual void visitEnd(const expr::ArrayAccess& node, bool callVirtualBase);

                virtual void visit(const expr::FieldAccess& node, bool callVirtualBase);
                virtual void visitEnd(const expr::FieldAccess& node, bool callVirtualBase);

                // Identifier
                virtual void visit(const expr::Identifier& node, bool callVirtualBase);
                virtual void visitEnd(const expr::Identifier& node, bool callVirtualBase);

                // Literals
                virtual void visit(const expr::Literal& node, bool callVirtualBase);
                virtual void visitEnd(const expr::Literal& node, bool callVirtualBase);

                // Conditional
                virtual void visit(const expr::Conditional& node, bool callVirtualBase);
                virtual void visitEnd(const expr::Conditional& node, bool callVirtualBase);

                // Annotations
                virtual void visit(const expr::MarkerAnnotation& node, bool callVirtualBase);
                virtual void visitEnd(const expr::MarkerAnnotation& node, bool callVirtualBase);

                virtual void visit(const expr::SingleElementAnnotation& node, bool callVirtualBase);
                virtual void visitEnd(const expr::SingleElementAnnotation& node, bool callVirtualBase);

                virtual void visit(const expr::NormalAnnotation& node, bool callVirtualBase);
                virtual void visitEnd(const expr::NormalAnnotation& node, bool callVirtualBase);

                // NewClass
                virtual void visit(const expr::NewClass& node, bool callVirtualBase);
                virtual void visitEnd(const expr::NewClass& node, bool callVirtualBase);

                // NewArray
                virtual void visit(const expr::NewArray& node, bool callVirtualBase);
                virtual void visitEnd(const expr::NewArray& node, bool callVirtualBase);

                // Super, this
                virtual void visit(const expr::Super& node, bool callVirtualBase);
                virtual void visitEnd(const expr::Super& node, bool callVirtualBase);

                virtual void visit(const expr::This& node, bool callVirtualBase);
                virtual void visitEnd(const expr::This& node, bool callVirtualBase);

                // Class, Method
                virtual void visit(const struc::Class& node, bool callVirtualBase);
                virtual void visitEnd(const struc::Class& node, bool callVirtualBase);

                virtual void visit(const struc::AnonymousClass& node, bool callVirtualBase);
                virtual void visitEnd(const struc::AnonymousClass& node, bool callVirtualBase);

                virtual void visit(const struc::Method& node, bool callVirtualBase);
                virtual void visitEnd(const struc::Method& node, bool callVirtualBase);

                // VariableDeclarations
                virtual void visit(const struc::Variable& node, bool callVirtualBase);
                virtual void visitEnd(const struc::Variable& node, bool callVirtualBase);

                virtual void visit(const struc::Parameter& node, bool callVirtualBase);
                virtual void visitEnd(const struc::Parameter& node, bool callVirtualBase);

                // Return
                virtual void visit(const statm::Return& node, bool callVirtualBase);
                virtual void visitEnd(const statm::Return& node, bool callVirtualBase);

                // TODO: !
                virtual void visit(const struc::EnumConstant& node, bool callVirtualBase);
                virtual void visitEnd(const struc::EnumConstant& node, bool callVirtualBase);

#ifndef NDEBUG
                virtual void finishVisit();
#endif
            };
        }
    }
}

#endif
