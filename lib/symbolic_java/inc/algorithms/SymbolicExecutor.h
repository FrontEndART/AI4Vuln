#ifndef _JAVA_SYMBOLIC_EXECUTOR_H_
#define _JAVA_SYMBOLIC_EXECUTOR_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class OverridesVisitor;

    class SymbolicExecutor : public columbus::symbolic::AbstractSymbolicExecutor, public columbus::java::asg::VisitorAbstractNodes {
    private:
        const columbus::java::asg::Factory& factory;
        std::map<columbus::NodeId, SmartDefinition> m_references;

        /** Node currently under exceution */
        NodeId currentNodeId;

        bool isSuperVisited;

        
        SmartDefinitionProxy getLocalVariable(const columbus::java::asg::expr::Identifier& identifier);
        SmartDefinitionProxy getLocalVariable(const columbus::java::asg::struc::Variable& variable, SmartDefinition init);

        SmartDefinitionProxy getClassMemberVariable(const SmartDefinition& reference, columbus::NodeId nodeId);

        SmartDefinitionProxy getArrayElement(const SmartDefinition& reference, const SmartDefinition& coord, bool initializedAtDecl = false, bool initializedAtStatic = false);

        NodeId getType(const java::asg::expr::Identifier &node, const NodeId variableId) const; 
        void passingParameters(columbus::java::asg::struc::NormalMethod *normalMethod, unsigned int invocationParameters, State *calledState, unsigned int *definitionPoped);
        //void passNonArrayParameter(Context *context, SmartDefinition nodeIdDef, SmartDefinition variableDef, SmartDefinition initValue);
        SmartDefinition initializeClass(columbus::NodeId classId, columbus::NodeId classTypeId, columbus::symbolic::State& state);

        columbus::NodeId findTypeDeclarationForMember(const columbus::NodeId memberId) const;

		SmartDefinition assign(SmartDefinition lhs, SmartDefinition rhs);

        const java::asg::struc::MethodDeclaration& getInvokedMethod(const java::asg::expr::MethodInvocation&);

        static bool isZero(SmartDefinition def);

        bool runIsInitedChecks(java::asg::expr::Expression* left) const;
        bool isInitedByAnnotation(java::asg::expr::Expression* left) const;
        bool isClass(java::asg::expr::Expression* left) const;
        bool checkConstructor(java::asg::expr::Identifier* left) const;
        bool checkConstructor(java::asg::expr::Expression* left) const;
        bool isFinalMember(java::asg::expr::Expression* left) const;
        bool isStaticMember(java::asg::expr::Expression* left) const;
        bool isFinalMember(java::asg::expr::Identifier* left) const;
        bool isStaticMember(java::asg::expr::Identifier* left) const;
        bool isInitedFinalMember(java::asg::expr::Identifier* left, bool onlyFinal) const;
        bool checkInitedAtDeclFinalMember(java::asg::expr::Expression* leftOperand, bool onlyFinal) const;
        bool checkInitedAtDeclMember(java::asg::expr::Expression* leftOperand) const;
        bool checkStaticInitBlock(java::asg::expr::Expression* leftOperand, bool onlyFinal) const;
        bool checkMemberInitedInStaticInitBlock(java::asg::expr::Expression* leftRefersTo, bool onlyFinal)const;
        bool checkMemberInitedInStaticInitBlock(const java::asg::expr::ArrayAccess& leftOperand, bool onlyFinal)const;
        bool checkMemberInitedAtDecl(const java::asg::expr::ArrayAccess& leftOperand)const;
        void executeStaticBlocks(java::asg::base::Base* memberClass);


    public:
        SymbolicExecutor(const columbus::java::asg::Factory& factor, columbus::symbolic::SymbolicEngine& engine);
        virtual ~SymbolicExecutor();

		const columbus::java::asg::Factory& getFactory() { return factory;}
        virtual void execute(columbus::NodeId asgNodeId);
        virtual void setupCalledState(columbus::symbolic::State& calledState, columbus::NodeId caller, columbus::NodeId calledICFG);
        virtual void makeCallReturn(columbus::symbolic::State& calledState);
        virtual BooleanInfixOperatorKind getParentOperatorKind(const columbus::NodeId currentNode, columbus::NodeId& parentNode) const;

        
        const NodeId& getCurrentNodeId() const {return currentNodeId;}

		bool getBooleanValueDefinitionValue(SmartDefinition);
		SmartDefinition createBooleanValueDefinition(bool);
        

        // For polimorphic functions
		virtual NodeId getScopeOrMethodDeclarationParent(NodeId nodeId);
		virtual void initializeThis(NodeId nodeId, State& state);

        // Visitors
        virtual void visit(const columbus::java::asg::base::Base& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::Identifier& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Variable& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Parameter& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Interface& node, bool callVirtualBase = true);
		virtual void visit(const columbus::java::asg::struc::EnumConstant& node, bool callVirtualBase = true);

        // Operators
        virtual void visit(const columbus::java::asg::expr::PostfixExpression& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::PrefixExpression& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::Assignment& node , bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::InfixExpression& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::NewClass& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::NewArray& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::ArrayAccess& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::FieldAccess& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::Conditional& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::InstanceOf& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::TypeCast& node, bool callVirtualBase = true);

        // Literals
        virtual void visit(const columbus::java::asg::expr::BooleanLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::CharacterLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::IntegerLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::LongLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::FloatLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::DoubleLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::NullLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::StringLiteral& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::ClassLiteral& node, bool callVirtualBase = true);

        // Other expressions
        virtual void visit(const columbus::java::asg::expr::This& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::Super& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::ParenthesizedExpression& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::MethodInvocation& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::statm::Synchronized& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::SingleElementAnnotation& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::MarkerAnnotation& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::expr::NormalAnnotation& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::statm::Block& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::statm::Assert& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Class& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::Enum& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::struc::MethodGeneric& node, bool callVirtualBase = true);
        virtual void visit(const columbus::java::asg::statm::Empty& node, bool callVirtualBase = true);

        virtual void visit(const columbus::java::asg::expr::Erroneous& node, bool callVirtualBase = true);

    };

}}

#endif
