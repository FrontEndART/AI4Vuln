#ifndef _JAVA_ALGORITHMDEEPCOPY_H_
#define _JAVA_ALGORITHMDEEPCOPY_H_

#include "java/inc/java.h"

#include <map>
#include <set>

/**
* \file AlgorithmDeepCopy.h
* \brief Contains the class `AlgorithmDeepCopy' which implements deep-copying of an arbitary subtree of an ASG.
*/

namespace columbus { namespace java { namespace asg {
  /**
  * \brief Implements the deep-copying of a part of the ASG.
  */
  class AlgorithmDeepCopy: public Algorithm {
    private:
      /** \internal \brief The source factory of the ASG. */
      Factory& srcFact;
    private:
      /** \internal \brief The target factory of the ASG. */
      Factory& targetFact;
      /** \internal \brief The id of the node identifying the subtree to be copied. */
      NodeId what;
      /** \internal \brief The last NodeId which was returned by the Factory::createNode method.  */
      base::Base* lastNode;
      /** \internal \brief The cross-reference between the old nodes and the already copied ones. */
      std::map<const base::Base*,base::Base*>& mapped_nodes;
      std::set<NodeId> not_simple_types;
      /**
      * \brief Disable copy of object.
      */
      AlgorithmDeepCopy(const AlgorithmDeepCopy&);

      /**
      * \brief Disable copy of object.
      */
      AlgorithmDeepCopy& operator=(const AlgorithmDeepCopy&);

    public:
      /**
      * \brief Constructor.
      * \param what [in] The id of the node which is to be copied.
      * \param srcFact [in] The source factory belonging to the ASG.
      * \param targetFact [in] The target factory belonging to the ASG.
      * \param mapped_nodes [in] A map (NodeId->NodeId) to store the bijection of original and cloned nodes.
      */
      AlgorithmDeepCopy(NodeId what, Factory& srcFact, Factory& targetFact, std::map<const base::Base*, base::Base*>& mapped_nodes);

      /**
      * \brief Virtual destructor.
      */
      virtual ~AlgorithmDeepCopy();

      /**
      * \brief Executes the cloning algorithm. Returns the NodeId of the newly created copy of the required node
      */
      base::Base* clone();

      /**
      * \brief Returns the mapping between the original subtree and the cloned one.
      */
      std::map<const base::Base*,base::Base* >& getMapping();
    private:
      base::Base* createNode(const base::Base* oldNode, NodeKind ndk);
      base::Base* clone(const base::Base* old);
      base::Base* getMappedNode(const base::Base* old);
      void clone(base::Base* dest, const base::Base* src);
      void clone(base::BlockComment* dest, const base::BlockComment* src);
      void clone(base::Comment* dest, const base::Comment* src);
      void clone(base::Commentable* dest, const base::Commentable* src);
      void clone(base::JavadocComment* dest, const base::JavadocComment* src);
      void clone(base::LineComment* dest, const base::LineComment* src);
      void clone(base::Named* dest, const base::Named* src);
      void clone(base::NonJavadocComment* dest, const base::NonJavadocComment* src);
      void clone(base::Positioned* dest, const base::Positioned* src);
      void clone(base::PositionedWithoutComment* dest, const base::PositionedWithoutComment* src);
      void clone(expr::AnnotatedTypeExpression* dest, const expr::AnnotatedTypeExpression* src);
      void clone(expr::Annotation* dest, const expr::Annotation* src);
      void clone(expr::ArrayAccess* dest, const expr::ArrayAccess* src);
      void clone(expr::ArrayTypeExpression* dest, const expr::ArrayTypeExpression* src);
      void clone(expr::Assignment* dest, const expr::Assignment* src);
      void clone(expr::Binary* dest, const expr::Binary* src);
      void clone(expr::BooleanLiteral* dest, const expr::BooleanLiteral* src);
      void clone(expr::CharacterLiteral* dest, const expr::CharacterLiteral* src);
      void clone(expr::ClassLiteral* dest, const expr::ClassLiteral* src);
      void clone(expr::Conditional* dest, const expr::Conditional* src);
      void clone(expr::DoubleLiteral* dest, const expr::DoubleLiteral* src);
      void clone(expr::Erroneous* dest, const expr::Erroneous* src);
      void clone(expr::ErroneousTypeExpression* dest, const expr::ErroneousTypeExpression* src);
      void clone(expr::Expression* dest, const expr::Expression* src);
      void clone(expr::ExternalTypeExpression* dest, const expr::ExternalTypeExpression* src);
      void clone(expr::FieldAccess* dest, const expr::FieldAccess* src);
      void clone(expr::FloatLiteral* dest, const expr::FloatLiteral* src);
      void clone(expr::FunctionalExpression* dest, const expr::FunctionalExpression* src);
      void clone(expr::Identifier* dest, const expr::Identifier* src);
      void clone(expr::InfixExpression* dest, const expr::InfixExpression* src);
      void clone(expr::InstanceOf* dest, const expr::InstanceOf* src);
      void clone(expr::IntegerLiteral* dest, const expr::IntegerLiteral* src);
      void clone(expr::Lambda* dest, const expr::Lambda* src);
      void clone(expr::Literal* dest, const expr::Literal* src);
      void clone(expr::LongLiteral* dest, const expr::LongLiteral* src);
      void clone(expr::MarkerAnnotation* dest, const expr::MarkerAnnotation* src);
      void clone(expr::MemberReference* dest, const expr::MemberReference* src);
      void clone(expr::MethodInvocation* dest, const expr::MethodInvocation* src);
      void clone(expr::NewArray* dest, const expr::NewArray* src);
      void clone(expr::NewClass* dest, const expr::NewClass* src);
      void clone(expr::NormalAnnotation* dest, const expr::NormalAnnotation* src);
      void clone(expr::NullLiteral* dest, const expr::NullLiteral* src);
      void clone(expr::NumberLiteral* dest, const expr::NumberLiteral* src);
      void clone(expr::ParenthesizedExpression* dest, const expr::ParenthesizedExpression* src);
      void clone(expr::PolyExpression* dest, const expr::PolyExpression* src);
      void clone(expr::PostfixExpression* dest, const expr::PostfixExpression* src);
      void clone(expr::PrefixExpression* dest, const expr::PrefixExpression* src);
      void clone(expr::PrimitiveTypeExpression* dest, const expr::PrimitiveTypeExpression* src);
      void clone(expr::QualifiedTypeExpression* dest, const expr::QualifiedTypeExpression* src);
      void clone(expr::SimpleTypeExpression* dest, const expr::SimpleTypeExpression* src);
      void clone(expr::SingleElementAnnotation* dest, const expr::SingleElementAnnotation* src);
      void clone(expr::StringLiteral* dest, const expr::StringLiteral* src);
      void clone(expr::Super* dest, const expr::Super* src);
      void clone(expr::This* dest, const expr::This* src);
      void clone(expr::TypeApplyExpression* dest, const expr::TypeApplyExpression* src);
      void clone(expr::TypeCast* dest, const expr::TypeCast* src);
      void clone(expr::TypeExpression* dest, const expr::TypeExpression* src);
      void clone(expr::TypeIntersectionExpression* dest, const expr::TypeIntersectionExpression* src);
      void clone(expr::TypeUnionExpression* dest, const expr::TypeUnionExpression* src);
      void clone(expr::Unary* dest, const expr::Unary* src);
      void clone(expr::WildcardExpression* dest, const expr::WildcardExpression* src);
      void clone(module::Exports* dest, const module::Exports* src);
      void clone(module::ModuleDirective* dest, const module::ModuleDirective* src);
      void clone(module::Opens* dest, const module::Opens* src);
      void clone(module::Provides* dest, const module::Provides* src);
      void clone(module::Requires* dest, const module::Requires* src);
      void clone(module::Uses* dest, const module::Uses* src);
      void clone(statm::Assert* dest, const statm::Assert* src);
      void clone(statm::BasicFor* dest, const statm::BasicFor* src);
      void clone(statm::Block* dest, const statm::Block* src);
      void clone(statm::Break* dest, const statm::Break* src);
      void clone(statm::Case* dest, const statm::Case* src);
      void clone(statm::Continue* dest, const statm::Continue* src);
      void clone(statm::Default* dest, const statm::Default* src);
      void clone(statm::Do* dest, const statm::Do* src);
      void clone(statm::Empty* dest, const statm::Empty* src);
      void clone(statm::EnhancedFor* dest, const statm::EnhancedFor* src);
      void clone(statm::ExpressionStatement* dest, const statm::ExpressionStatement* src);
      void clone(statm::For* dest, const statm::For* src);
      void clone(statm::Handler* dest, const statm::Handler* src);
      void clone(statm::If* dest, const statm::If* src);
      void clone(statm::Iteration* dest, const statm::Iteration* src);
      void clone(statm::Jump* dest, const statm::Jump* src);
      void clone(statm::LabeledStatement* dest, const statm::LabeledStatement* src);
      void clone(statm::Return* dest, const statm::Return* src);
      void clone(statm::Selection* dest, const statm::Selection* src);
      void clone(statm::Statement* dest, const statm::Statement* src);
      void clone(statm::Switch* dest, const statm::Switch* src);
      void clone(statm::SwitchLabel* dest, const statm::SwitchLabel* src);
      void clone(statm::Synchronized* dest, const statm::Synchronized* src);
      void clone(statm::Throw* dest, const statm::Throw* src);
      void clone(statm::Try* dest, const statm::Try* src);
      void clone(statm::While* dest, const statm::While* src);
      void clone(struc::AnnotatedElement* dest, const struc::AnnotatedElement* src);
      void clone(struc::AnnotationType* dest, const struc::AnnotationType* src);
      void clone(struc::AnnotationTypeElement* dest, const struc::AnnotationTypeElement* src);
      void clone(struc::AnonymousClass* dest, const struc::AnonymousClass* src);
      void clone(struc::Class* dest, const struc::Class* src);
      void clone(struc::ClassDeclaration* dest, const struc::ClassDeclaration* src);
      void clone(struc::ClassGeneric* dest, const struc::ClassGeneric* src);
      void clone(struc::CompilationUnit* dest, const struc::CompilationUnit* src);
      void clone(struc::Declaration* dest, const struc::Declaration* src);
      void clone(struc::Enum* dest, const struc::Enum* src);
      void clone(struc::EnumConstant* dest, const struc::EnumConstant* src);
      void clone(struc::GenericDeclaration* dest, const struc::GenericDeclaration* src);
      void clone(struc::Import* dest, const struc::Import* src);
      void clone(struc::InitializerBlock* dest, const struc::InitializerBlock* src);
      void clone(struc::InstanceInitializerBlock* dest, const struc::InstanceInitializerBlock* src);
      void clone(struc::Interface* dest, const struc::Interface* src);
      void clone(struc::InterfaceDeclaration* dest, const struc::InterfaceDeclaration* src);
      void clone(struc::InterfaceGeneric* dest, const struc::InterfaceGeneric* src);
      void clone(struc::Member* dest, const struc::Member* src);
      void clone(struc::Method* dest, const struc::Method* src);
      void clone(struc::MethodDeclaration* dest, const struc::MethodDeclaration* src);
      void clone(struc::MethodGeneric* dest, const struc::MethodGeneric* src);
      void clone(struc::Module* dest, const struc::Module* src);
      void clone(struc::ModuleDeclaration* dest, const struc::ModuleDeclaration* src);
      void clone(struc::NamedDeclaration* dest, const struc::NamedDeclaration* src);
      void clone(struc::NormalMethod* dest, const struc::NormalMethod* src);
      void clone(struc::Package* dest, const struc::Package* src);
      void clone(struc::PackageDeclaration* dest, const struc::PackageDeclaration* src);
      void clone(struc::Parameter* dest, const struc::Parameter* src);
      void clone(struc::Scope* dest, const struc::Scope* src);
      void clone(struc::StaticInitializerBlock* dest, const struc::StaticInitializerBlock* src);
      void clone(struc::TypeDeclaration* dest, const struc::TypeDeclaration* src);
      void clone(struc::TypeParameter* dest, const struc::TypeParameter* src);
      void clone(struc::Variable* dest, const struc::Variable* src);
      void clone(struc::VariableDeclaration* dest, const struc::VariableDeclaration* src);
      void clone(type::ArrayType* dest, const type::ArrayType* src);
      void clone(type::BooleanType* dest, const type::BooleanType* src);
      void clone(type::BoundedWildcardType* dest, const type::BoundedWildcardType* src);
      void clone(type::ByteType* dest, const type::ByteType* src);
      void clone(type::CharType* dest, const type::CharType* src);
      void clone(type::ClassType* dest, const type::ClassType* src);
      void clone(type::DoubleType* dest, const type::DoubleType* src);
      void clone(type::ErrorType* dest, const type::ErrorType* src);
      void clone(type::FloatType* dest, const type::FloatType* src);
      void clone(type::IntType* dest, const type::IntType* src);
      void clone(type::IntersectionType* dest, const type::IntersectionType* src);
      void clone(type::LongType* dest, const type::LongType* src);
      void clone(type::LowerBoundedWildcardType* dest, const type::LowerBoundedWildcardType* src);
      void clone(type::MethodType* dest, const type::MethodType* src);
      void clone(type::ModuleType* dest, const type::ModuleType* src);
      void clone(type::NoType* dest, const type::NoType* src);
      void clone(type::NullType* dest, const type::NullType* src);
      void clone(type::PackageType* dest, const type::PackageType* src);
      void clone(type::ParameterizedType* dest, const type::ParameterizedType* src);
      void clone(type::PrimitiveType* dest, const type::PrimitiveType* src);
      void clone(type::ScopedType* dest, const type::ScopedType* src);
      void clone(type::ShortType* dest, const type::ShortType* src);
      void clone(type::Type* dest, const type::Type* src);
      void clone(type::TypeVariable* dest, const type::TypeVariable* src);
      void clone(type::UnboundedWildcardType* dest, const type::UnboundedWildcardType* src);
      void clone(type::UnionType* dest, const type::UnionType* src);
      void clone(type::UpperBoundedWildcardType* dest, const type::UpperBoundedWildcardType* src);
      void clone(type::VoidType* dest, const type::VoidType* src);
      void clone(type::WildcardType* dest, const type::WildcardType* src);
  }; // AlgorithmDeepCopy


}}}
#endif

