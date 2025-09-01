#ifndef _JAVA_VISITORGRAPHML_H_
#define _JAVA_VISITORGRAPHML_H_

#include "java/inc/java.h"
#include "io/inc/GraphmlIO.h"

/**
* \file VisitorGraphml.h
* \brief Contains declaration of VisitorGraphml class.
*/

namespace columbus { namespace java { namespace asg {

  /**
  * \brief Exports the ASG to Graphml format.
  */
  class VisitorGraphml : public Visitor {
    public:
      typedef bool(*NodeCompareFunc)(const base::Base&);

      /**
      * \brief Constructor for VisitorGraphml.
      */
      VisitorGraphml(columbus::io::GraphmlIO& io, std::set< std::string>& edgeFilter, unsigned int maxDrawingDepth = 0);

      /**
      * \brief Destructor.
      */
      virtual ~VisitorGraphml();

      /**
      * \brief Give back to compare function
      */
      NodeCompareFunc getCompareFunctionToNode( std::string& nodeName);

      /**
      * \brief Create compare map
      */
      static std::map< std::string, NodeCompareFunc> create_map(){
        std::map< std::string, NodeCompareFunc> cmpTable;
        cmpTable.insert( std::make_pair( "BlockComment", &Common::getIsBlockComment));
        cmpTable.insert( std::make_pair( "Comment", &Common::getIsComment));
        cmpTable.insert( std::make_pair( "Commentable", &Common::getIsCommentable));
        cmpTable.insert( std::make_pair( "JavadocComment", &Common::getIsJavadocComment));
        cmpTable.insert( std::make_pair( "LineComment", &Common::getIsLineComment));
        cmpTable.insert( std::make_pair( "Named", &Common::getIsNamed));
        cmpTable.insert( std::make_pair( "NonJavadocComment", &Common::getIsNonJavadocComment));
        cmpTable.insert( std::make_pair( "Positioned", &Common::getIsPositioned));
        cmpTable.insert( std::make_pair( "PositionedWithoutComment", &Common::getIsPositionedWithoutComment));
        cmpTable.insert( std::make_pair( "AnnotatedTypeExpression", &Common::getIsAnnotatedTypeExpression));
        cmpTable.insert( std::make_pair( "Annotation", &Common::getIsAnnotation));
        cmpTable.insert( std::make_pair( "ArrayAccess", &Common::getIsArrayAccess));
        cmpTable.insert( std::make_pair( "ArrayTypeExpression", &Common::getIsArrayTypeExpression));
        cmpTable.insert( std::make_pair( "Assignment", &Common::getIsAssignment));
        cmpTable.insert( std::make_pair( "Binary", &Common::getIsBinary));
        cmpTable.insert( std::make_pair( "BooleanLiteral", &Common::getIsBooleanLiteral));
        cmpTable.insert( std::make_pair( "CharacterLiteral", &Common::getIsCharacterLiteral));
        cmpTable.insert( std::make_pair( "ClassLiteral", &Common::getIsClassLiteral));
        cmpTable.insert( std::make_pair( "Conditional", &Common::getIsConditional));
        cmpTable.insert( std::make_pair( "DoubleLiteral", &Common::getIsDoubleLiteral));
        cmpTable.insert( std::make_pair( "Erroneous", &Common::getIsErroneous));
        cmpTable.insert( std::make_pair( "ErroneousTypeExpression", &Common::getIsErroneousTypeExpression));
        cmpTable.insert( std::make_pair( "Expression", &Common::getIsExpression));
        cmpTable.insert( std::make_pair( "ExternalTypeExpression", &Common::getIsExternalTypeExpression));
        cmpTable.insert( std::make_pair( "FieldAccess", &Common::getIsFieldAccess));
        cmpTable.insert( std::make_pair( "FloatLiteral", &Common::getIsFloatLiteral));
        cmpTable.insert( std::make_pair( "FunctionalExpression", &Common::getIsFunctionalExpression));
        cmpTable.insert( std::make_pair( "Identifier", &Common::getIsIdentifier));
        cmpTable.insert( std::make_pair( "InfixExpression", &Common::getIsInfixExpression));
        cmpTable.insert( std::make_pair( "InstanceOf", &Common::getIsInstanceOf));
        cmpTable.insert( std::make_pair( "IntegerLiteral", &Common::getIsIntegerLiteral));
        cmpTable.insert( std::make_pair( "Lambda", &Common::getIsLambda));
        cmpTable.insert( std::make_pair( "Literal", &Common::getIsLiteral));
        cmpTable.insert( std::make_pair( "LongLiteral", &Common::getIsLongLiteral));
        cmpTable.insert( std::make_pair( "MarkerAnnotation", &Common::getIsMarkerAnnotation));
        cmpTable.insert( std::make_pair( "MemberReference", &Common::getIsMemberReference));
        cmpTable.insert( std::make_pair( "MethodInvocation", &Common::getIsMethodInvocation));
        cmpTable.insert( std::make_pair( "NewArray", &Common::getIsNewArray));
        cmpTable.insert( std::make_pair( "NewClass", &Common::getIsNewClass));
        cmpTable.insert( std::make_pair( "NormalAnnotation", &Common::getIsNormalAnnotation));
        cmpTable.insert( std::make_pair( "NullLiteral", &Common::getIsNullLiteral));
        cmpTable.insert( std::make_pair( "NumberLiteral", &Common::getIsNumberLiteral));
        cmpTable.insert( std::make_pair( "ParenthesizedExpression", &Common::getIsParenthesizedExpression));
        cmpTable.insert( std::make_pair( "PolyExpression", &Common::getIsPolyExpression));
        cmpTable.insert( std::make_pair( "PostfixExpression", &Common::getIsPostfixExpression));
        cmpTable.insert( std::make_pair( "PrefixExpression", &Common::getIsPrefixExpression));
        cmpTable.insert( std::make_pair( "PrimitiveTypeExpression", &Common::getIsPrimitiveTypeExpression));
        cmpTable.insert( std::make_pair( "QualifiedTypeExpression", &Common::getIsQualifiedTypeExpression));
        cmpTable.insert( std::make_pair( "SimpleTypeExpression", &Common::getIsSimpleTypeExpression));
        cmpTable.insert( std::make_pair( "SingleElementAnnotation", &Common::getIsSingleElementAnnotation));
        cmpTable.insert( std::make_pair( "StringLiteral", &Common::getIsStringLiteral));
        cmpTable.insert( std::make_pair( "Super", &Common::getIsSuper));
        cmpTable.insert( std::make_pair( "This", &Common::getIsThis));
        cmpTable.insert( std::make_pair( "TypeApplyExpression", &Common::getIsTypeApplyExpression));
        cmpTable.insert( std::make_pair( "TypeCast", &Common::getIsTypeCast));
        cmpTable.insert( std::make_pair( "TypeExpression", &Common::getIsTypeExpression));
        cmpTable.insert( std::make_pair( "TypeIntersectionExpression", &Common::getIsTypeIntersectionExpression));
        cmpTable.insert( std::make_pair( "TypeUnionExpression", &Common::getIsTypeUnionExpression));
        cmpTable.insert( std::make_pair( "Unary", &Common::getIsUnary));
        cmpTable.insert( std::make_pair( "WildcardExpression", &Common::getIsWildcardExpression));
        cmpTable.insert( std::make_pair( "Exports", &Common::getIsExports));
        cmpTable.insert( std::make_pair( "ModuleDirective", &Common::getIsModuleDirective));
        cmpTable.insert( std::make_pair( "Opens", &Common::getIsOpens));
        cmpTable.insert( std::make_pair( "Provides", &Common::getIsProvides));
        cmpTable.insert( std::make_pair( "Requires", &Common::getIsRequires));
        cmpTable.insert( std::make_pair( "Uses", &Common::getIsUses));
        cmpTable.insert( std::make_pair( "Assert", &Common::getIsAssert));
        cmpTable.insert( std::make_pair( "BasicFor", &Common::getIsBasicFor));
        cmpTable.insert( std::make_pair( "Block", &Common::getIsBlock));
        cmpTable.insert( std::make_pair( "Break", &Common::getIsBreak));
        cmpTable.insert( std::make_pair( "Case", &Common::getIsCase));
        cmpTable.insert( std::make_pair( "Continue", &Common::getIsContinue));
        cmpTable.insert( std::make_pair( "Default", &Common::getIsDefault));
        cmpTable.insert( std::make_pair( "Do", &Common::getIsDo));
        cmpTable.insert( std::make_pair( "Empty", &Common::getIsEmpty));
        cmpTable.insert( std::make_pair( "EnhancedFor", &Common::getIsEnhancedFor));
        cmpTable.insert( std::make_pair( "ExpressionStatement", &Common::getIsExpressionStatement));
        cmpTable.insert( std::make_pair( "For", &Common::getIsFor));
        cmpTable.insert( std::make_pair( "Handler", &Common::getIsHandler));
        cmpTable.insert( std::make_pair( "If", &Common::getIsIf));
        cmpTable.insert( std::make_pair( "Iteration", &Common::getIsIteration));
        cmpTable.insert( std::make_pair( "Jump", &Common::getIsJump));
        cmpTable.insert( std::make_pair( "LabeledStatement", &Common::getIsLabeledStatement));
        cmpTable.insert( std::make_pair( "Return", &Common::getIsReturn));
        cmpTable.insert( std::make_pair( "Selection", &Common::getIsSelection));
        cmpTable.insert( std::make_pair( "Statement", &Common::getIsStatement));
        cmpTable.insert( std::make_pair( "Switch", &Common::getIsSwitch));
        cmpTable.insert( std::make_pair( "SwitchLabel", &Common::getIsSwitchLabel));
        cmpTable.insert( std::make_pair( "Synchronized", &Common::getIsSynchronized));
        cmpTable.insert( std::make_pair( "Throw", &Common::getIsThrow));
        cmpTable.insert( std::make_pair( "Try", &Common::getIsTry));
        cmpTable.insert( std::make_pair( "While", &Common::getIsWhile));
        cmpTable.insert( std::make_pair( "AnnotatedElement", &Common::getIsAnnotatedElement));
        cmpTable.insert( std::make_pair( "AnnotationType", &Common::getIsAnnotationType));
        cmpTable.insert( std::make_pair( "AnnotationTypeElement", &Common::getIsAnnotationTypeElement));
        cmpTable.insert( std::make_pair( "AnonymousClass", &Common::getIsAnonymousClass));
        cmpTable.insert( std::make_pair( "Class", &Common::getIsClass));
        cmpTable.insert( std::make_pair( "ClassDeclaration", &Common::getIsClassDeclaration));
        cmpTable.insert( std::make_pair( "ClassGeneric", &Common::getIsClassGeneric));
        cmpTable.insert( std::make_pair( "CompilationUnit", &Common::getIsCompilationUnit));
        cmpTable.insert( std::make_pair( "Declaration", &Common::getIsDeclaration));
        cmpTable.insert( std::make_pair( "Enum", &Common::getIsEnum));
        cmpTable.insert( std::make_pair( "EnumConstant", &Common::getIsEnumConstant));
        cmpTable.insert( std::make_pair( "GenericDeclaration", &Common::getIsGenericDeclaration));
        cmpTable.insert( std::make_pair( "Import", &Common::getIsImport));
        cmpTable.insert( std::make_pair( "InitializerBlock", &Common::getIsInitializerBlock));
        cmpTable.insert( std::make_pair( "InstanceInitializerBlock", &Common::getIsInstanceInitializerBlock));
        cmpTable.insert( std::make_pair( "Interface", &Common::getIsInterface));
        cmpTable.insert( std::make_pair( "InterfaceDeclaration", &Common::getIsInterfaceDeclaration));
        cmpTable.insert( std::make_pair( "InterfaceGeneric", &Common::getIsInterfaceGeneric));
        cmpTable.insert( std::make_pair( "Member", &Common::getIsMember));
        cmpTable.insert( std::make_pair( "Method", &Common::getIsMethod));
        cmpTable.insert( std::make_pair( "MethodDeclaration", &Common::getIsMethodDeclaration));
        cmpTable.insert( std::make_pair( "MethodGeneric", &Common::getIsMethodGeneric));
        cmpTable.insert( std::make_pair( "Module", &Common::getIsModule));
        cmpTable.insert( std::make_pair( "ModuleDeclaration", &Common::getIsModuleDeclaration));
        cmpTable.insert( std::make_pair( "NamedDeclaration", &Common::getIsNamedDeclaration));
        cmpTable.insert( std::make_pair( "NormalMethod", &Common::getIsNormalMethod));
        cmpTable.insert( std::make_pair( "Package", &Common::getIsPackage));
        cmpTable.insert( std::make_pair( "PackageDeclaration", &Common::getIsPackageDeclaration));
        cmpTable.insert( std::make_pair( "Parameter", &Common::getIsParameter));
        cmpTable.insert( std::make_pair( "Scope", &Common::getIsScope));
        cmpTable.insert( std::make_pair( "StaticInitializerBlock", &Common::getIsStaticInitializerBlock));
        cmpTable.insert( std::make_pair( "TypeDeclaration", &Common::getIsTypeDeclaration));
        cmpTable.insert( std::make_pair( "TypeParameter", &Common::getIsTypeParameter));
        cmpTable.insert( std::make_pair( "Variable", &Common::getIsVariable));
        cmpTable.insert( std::make_pair( "VariableDeclaration", &Common::getIsVariableDeclaration));
        cmpTable.insert( std::make_pair( "ArrayType", &Common::getIsArrayType));
        cmpTable.insert( std::make_pair( "BooleanType", &Common::getIsBooleanType));
        cmpTable.insert( std::make_pair( "BoundedWildcardType", &Common::getIsBoundedWildcardType));
        cmpTable.insert( std::make_pair( "ByteType", &Common::getIsByteType));
        cmpTable.insert( std::make_pair( "CharType", &Common::getIsCharType));
        cmpTable.insert( std::make_pair( "ClassType", &Common::getIsClassType));
        cmpTable.insert( std::make_pair( "DoubleType", &Common::getIsDoubleType));
        cmpTable.insert( std::make_pair( "ErrorType", &Common::getIsErrorType));
        cmpTable.insert( std::make_pair( "FloatType", &Common::getIsFloatType));
        cmpTable.insert( std::make_pair( "IntType", &Common::getIsIntType));
        cmpTable.insert( std::make_pair( "IntersectionType", &Common::getIsIntersectionType));
        cmpTable.insert( std::make_pair( "LongType", &Common::getIsLongType));
        cmpTable.insert( std::make_pair( "LowerBoundedWildcardType", &Common::getIsLowerBoundedWildcardType));
        cmpTable.insert( std::make_pair( "MethodType", &Common::getIsMethodType));
        cmpTable.insert( std::make_pair( "ModuleType", &Common::getIsModuleType));
        cmpTable.insert( std::make_pair( "NoType", &Common::getIsNoType));
        cmpTable.insert( std::make_pair( "NullType", &Common::getIsNullType));
        cmpTable.insert( std::make_pair( "PackageType", &Common::getIsPackageType));
        cmpTable.insert( std::make_pair( "ParameterizedType", &Common::getIsParameterizedType));
        cmpTable.insert( std::make_pair( "PrimitiveType", &Common::getIsPrimitiveType));
        cmpTable.insert( std::make_pair( "ScopedType", &Common::getIsScopedType));
        cmpTable.insert( std::make_pair( "ShortType", &Common::getIsShortType));
        cmpTable.insert( std::make_pair( "Type", &Common::getIsType));
        cmpTable.insert( std::make_pair( "TypeVariable", &Common::getIsTypeVariable));
        cmpTable.insert( std::make_pair( "UnboundedWildcardType", &Common::getIsUnboundedWildcardType));
        cmpTable.insert( std::make_pair( "UnionType", &Common::getIsUnionType));
        cmpTable.insert( std::make_pair( "UpperBoundedWildcardType", &Common::getIsUpperBoundedWildcardType));
        cmpTable.insert( std::make_pair( "VoidType", &Common::getIsVoidType));
        cmpTable.insert( std::make_pair( "WildcardType", &Common::getIsWildcardType));
        return cmpTable;
      }

      /**
      * \brief Filter node types by matching substring in qualified name
      */
      static const std::set< std::string> getNodeTypeSet(){
        std::set< std::string> types;
        types.insert( "base::Base");
        types.insert( "base::BlockComment");
        types.insert( "base::Comment");
        types.insert( "base::Commentable");
        types.insert( "base::JavadocComment");
        types.insert( "base::LineComment");
        types.insert( "base::Named");
        types.insert( "base::NonJavadocComment");
        types.insert( "base::Positioned");
        types.insert( "base::PositionedWithoutComment");
        types.insert( "expr::AnnotatedTypeExpression");
        types.insert( "expr::Annotation");
        types.insert( "expr::ArrayAccess");
        types.insert( "expr::ArrayTypeExpression");
        types.insert( "expr::Assignment");
        types.insert( "expr::Binary");
        types.insert( "expr::BooleanLiteral");
        types.insert( "expr::CharacterLiteral");
        types.insert( "expr::ClassLiteral");
        types.insert( "expr::Conditional");
        types.insert( "expr::DoubleLiteral");
        types.insert( "expr::Erroneous");
        types.insert( "expr::ErroneousTypeExpression");
        types.insert( "expr::Expression");
        types.insert( "expr::ExternalTypeExpression");
        types.insert( "expr::FieldAccess");
        types.insert( "expr::FloatLiteral");
        types.insert( "expr::FunctionalExpression");
        types.insert( "expr::Identifier");
        types.insert( "expr::InfixExpression");
        types.insert( "expr::InstanceOf");
        types.insert( "expr::IntegerLiteral");
        types.insert( "expr::Lambda");
        types.insert( "expr::Literal");
        types.insert( "expr::LongLiteral");
        types.insert( "expr::MarkerAnnotation");
        types.insert( "expr::MemberReference");
        types.insert( "expr::MethodInvocation");
        types.insert( "expr::NewArray");
        types.insert( "expr::NewClass");
        types.insert( "expr::NormalAnnotation");
        types.insert( "expr::NullLiteral");
        types.insert( "expr::NumberLiteral");
        types.insert( "expr::ParenthesizedExpression");
        types.insert( "expr::PolyExpression");
        types.insert( "expr::PostfixExpression");
        types.insert( "expr::PrefixExpression");
        types.insert( "expr::PrimitiveTypeExpression");
        types.insert( "expr::QualifiedTypeExpression");
        types.insert( "expr::SimpleTypeExpression");
        types.insert( "expr::SingleElementAnnotation");
        types.insert( "expr::StringLiteral");
        types.insert( "expr::Super");
        types.insert( "expr::This");
        types.insert( "expr::TypeApplyExpression");
        types.insert( "expr::TypeCast");
        types.insert( "expr::TypeExpression");
        types.insert( "expr::TypeIntersectionExpression");
        types.insert( "expr::TypeUnionExpression");
        types.insert( "expr::Unary");
        types.insert( "expr::WildcardExpression");
        types.insert( "module::Exports");
        types.insert( "module::ModuleDirective");
        types.insert( "module::Opens");
        types.insert( "module::Provides");
        types.insert( "module::Requires");
        types.insert( "module::Uses");
        types.insert( "statm::Assert");
        types.insert( "statm::BasicFor");
        types.insert( "statm::Block");
        types.insert( "statm::Break");
        types.insert( "statm::Case");
        types.insert( "statm::Continue");
        types.insert( "statm::Default");
        types.insert( "statm::Do");
        types.insert( "statm::Empty");
        types.insert( "statm::EnhancedFor");
        types.insert( "statm::ExpressionStatement");
        types.insert( "statm::For");
        types.insert( "statm::Handler");
        types.insert( "statm::If");
        types.insert( "statm::Iteration");
        types.insert( "statm::Jump");
        types.insert( "statm::LabeledStatement");
        types.insert( "statm::Return");
        types.insert( "statm::Selection");
        types.insert( "statm::Statement");
        types.insert( "statm::Switch");
        types.insert( "statm::SwitchLabel");
        types.insert( "statm::Synchronized");
        types.insert( "statm::Throw");
        types.insert( "statm::Try");
        types.insert( "statm::While");
        types.insert( "struc::AnnotatedElement");
        types.insert( "struc::AnnotationType");
        types.insert( "struc::AnnotationTypeElement");
        types.insert( "struc::AnonymousClass");
        types.insert( "struc::Class");
        types.insert( "struc::ClassDeclaration");
        types.insert( "struc::ClassGeneric");
        types.insert( "struc::CompilationUnit");
        types.insert( "struc::Declaration");
        types.insert( "struc::Enum");
        types.insert( "struc::EnumConstant");
        types.insert( "struc::GenericDeclaration");
        types.insert( "struc::Import");
        types.insert( "struc::InitializerBlock");
        types.insert( "struc::InstanceInitializerBlock");
        types.insert( "struc::Interface");
        types.insert( "struc::InterfaceDeclaration");
        types.insert( "struc::InterfaceGeneric");
        types.insert( "struc::Member");
        types.insert( "struc::Method");
        types.insert( "struc::MethodDeclaration");
        types.insert( "struc::MethodGeneric");
        types.insert( "struc::Module");
        types.insert( "struc::ModuleDeclaration");
        types.insert( "struc::NamedDeclaration");
        types.insert( "struc::NormalMethod");
        types.insert( "struc::Package");
        types.insert( "struc::PackageDeclaration");
        types.insert( "struc::Parameter");
        types.insert( "struc::Scope");
        types.insert( "struc::StaticInitializerBlock");
        types.insert( "struc::TypeDeclaration");
        types.insert( "struc::TypeParameter");
        types.insert( "struc::Variable");
        types.insert( "struc::VariableDeclaration");
        types.insert( "type::ArrayType");
        types.insert( "type::BooleanType");
        types.insert( "type::BoundedWildcardType");
        types.insert( "type::ByteType");
        types.insert( "type::CharType");
        types.insert( "type::ClassType");
        types.insert( "type::DoubleType");
        types.insert( "type::ErrorType");
        types.insert( "type::FloatType");
        types.insert( "type::IntType");
        types.insert( "type::IntersectionType");
        types.insert( "type::LongType");
        types.insert( "type::LowerBoundedWildcardType");
        types.insert( "type::MethodType");
        types.insert( "type::ModuleType");
        types.insert( "type::NoType");
        types.insert( "type::NullType");
        types.insert( "type::PackageType");
        types.insert( "type::ParameterizedType");
        types.insert( "type::PrimitiveType");
        types.insert( "type::ScopedType");
        types.insert( "type::ShortType");
        types.insert( "type::Type");
        types.insert( "type::TypeVariable");
        types.insert( "type::UnboundedWildcardType");
        types.insert( "type::UnionType");
        types.insert( "type::UpperBoundedWildcardType");
        types.insert( "type::VoidType");
        types.insert( "type::WildcardType");
        return types;
      }

      /** \internal \brief It contains a table to node names and compare functions */
      static const std::map< std::string, NodeCompareFunc> compareTable;

      /**
      * \brief Set startpoint
      */
      void setStartPoint( NodeId startPoint);

      /**
      * \brief Set it is white color node or not
      */
      void setIsWhiteColor( bool isWhite);

      /**
      * \brief Set it is need to grouping tree nodes or not
      */
      void setIsGroupingTreeNodes( bool groupingTreeNodes);

      /**
      * \brief Set it is enabled to draw cross edges or not
      */
      void setIsEnableCrossEdge( bool isVisitCrossEdge);

      /**
      * \brief Set node type names to show attributes only of these types 
      */
      void addToFilterNodeTypeAttributes( std::string type);

      /**
      * \brief Set node type names to filtering
      */
      void addToFilterNodeType( std::string type);

      /**
      * \brief Set node type names to filtering
      */
      void filterNodeTypeMatch( std::string pattern);

      /**
      * \brief Writes the Graphml representation of the base::BlockComment node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const base::BlockComment& node, bool callVirtualBase = true);

      /**
      * \brief Converts the base::BlockComment node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const base::BlockComment& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the base::JavadocComment node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const base::JavadocComment& node, bool callVirtualBase = true);

      /**
      * \brief Converts the base::JavadocComment node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const base::JavadocComment& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the base::LineComment node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const base::LineComment& node, bool callVirtualBase = true);

      /**
      * \brief Converts the base::LineComment node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const base::LineComment& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::AnnotatedTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::AnnotatedTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::AnnotatedTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::AnnotatedTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::ArrayAccess node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::ArrayAccess& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::ArrayAccess node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::ArrayAccess& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::ArrayTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::ArrayTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::ArrayTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::ArrayTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::Assignment node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::Assignment& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::Assignment node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::Assignment& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::BooleanLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::BooleanLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::BooleanLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::BooleanLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::CharacterLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::CharacterLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::CharacterLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::CharacterLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::ClassLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::ClassLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::ClassLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::ClassLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::Conditional node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::Conditional& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::Conditional node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::Conditional& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::DoubleLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::DoubleLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::DoubleLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::DoubleLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::Erroneous node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::Erroneous& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::Erroneous node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::Erroneous& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::ErroneousTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::ErroneousTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::ErroneousTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::ErroneousTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::ExternalTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::ExternalTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::ExternalTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::ExternalTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::FieldAccess node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::FieldAccess& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::FieldAccess node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::FieldAccess& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::FloatLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::FloatLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::FloatLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::FloatLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::Identifier node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::Identifier& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::Identifier node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::Identifier& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::InfixExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::InfixExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::InfixExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::InfixExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::InstanceOf node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::InstanceOf& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::InstanceOf node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::InstanceOf& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::IntegerLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::IntegerLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::IntegerLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::IntegerLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::Lambda node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::Lambda& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::Lambda node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::Lambda& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::LongLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::LongLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::LongLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::LongLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::MarkerAnnotation node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::MarkerAnnotation& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::MarkerAnnotation node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::MarkerAnnotation& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::MemberReference node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::MemberReference& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::MemberReference node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::MemberReference& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::MethodInvocation node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::MethodInvocation& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::MethodInvocation node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::MethodInvocation& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::NewArray node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::NewArray& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::NewArray node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::NewArray& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::NewClass node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::NewClass& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::NewClass node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::NewClass& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::NormalAnnotation node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::NormalAnnotation& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::NormalAnnotation node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::NormalAnnotation& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::NullLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::NullLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::NullLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::NullLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::ParenthesizedExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::ParenthesizedExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::ParenthesizedExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::ParenthesizedExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::PostfixExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::PostfixExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::PostfixExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::PostfixExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::PrefixExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::PrefixExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::PrefixExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::PrefixExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::PrimitiveTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::PrimitiveTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::PrimitiveTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::PrimitiveTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::QualifiedTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::QualifiedTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::QualifiedTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::QualifiedTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::SimpleTypeExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::SimpleTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::SimpleTypeExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::SimpleTypeExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::SingleElementAnnotation node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::SingleElementAnnotation& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::SingleElementAnnotation node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::SingleElementAnnotation& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::StringLiteral node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::StringLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::StringLiteral node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::StringLiteral& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::Super node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::Super& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::Super node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::Super& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::This node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::This& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::This node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::This& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::TypeApplyExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::TypeApplyExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::TypeApplyExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::TypeApplyExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::TypeCast node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::TypeCast& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::TypeCast node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::TypeCast& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::TypeIntersectionExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::TypeIntersectionExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::TypeIntersectionExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::TypeIntersectionExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::TypeUnionExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::TypeUnionExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::TypeUnionExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::TypeUnionExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the expr::WildcardExpression node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const expr::WildcardExpression& node, bool callVirtualBase = true);

      /**
      * \brief Converts the expr::WildcardExpression node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const expr::WildcardExpression& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the module::Exports node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const module::Exports& node, bool callVirtualBase = true);

      /**
      * \brief Converts the module::Exports node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const module::Exports& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the module::Opens node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const module::Opens& node, bool callVirtualBase = true);

      /**
      * \brief Converts the module::Opens node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const module::Opens& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the module::Provides node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const module::Provides& node, bool callVirtualBase = true);

      /**
      * \brief Converts the module::Provides node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const module::Provides& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the module::Requires node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const module::Requires& node, bool callVirtualBase = true);

      /**
      * \brief Converts the module::Requires node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const module::Requires& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the module::Uses node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const module::Uses& node, bool callVirtualBase = true);

      /**
      * \brief Converts the module::Uses node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const module::Uses& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Assert node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Assert& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Assert node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Assert& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::BasicFor node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::BasicFor& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::BasicFor node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::BasicFor& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Block node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Block& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Block node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Block& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Break node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Break& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Break node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Break& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Case node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Case& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Case node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Case& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Continue node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Continue& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Continue node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Continue& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Default node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Default& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Default node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Default& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Do node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Do& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Do node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Do& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Empty node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Empty& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Empty node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Empty& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::EnhancedFor node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::EnhancedFor& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::EnhancedFor node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::EnhancedFor& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::ExpressionStatement node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::ExpressionStatement& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::ExpressionStatement node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::ExpressionStatement& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Handler node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Handler& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Handler node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Handler& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::If node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::If& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::If node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::If& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::LabeledStatement node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::LabeledStatement& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::LabeledStatement node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::LabeledStatement& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Return node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Return& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Return node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Return& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Switch node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Switch& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Switch node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Switch& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Synchronized node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Synchronized& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Synchronized node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Synchronized& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Throw node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Throw& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Throw node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Throw& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::Try node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::Try& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::Try node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::Try& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the statm::While node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const statm::While& node, bool callVirtualBase = true);

      /**
      * \brief Converts the statm::While node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const statm::While& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::AnnotationType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::AnnotationType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::AnnotationType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::AnnotationType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::AnnotationTypeElement node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::AnnotationTypeElement& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::AnnotationTypeElement node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::AnnotationTypeElement& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::AnonymousClass node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::AnonymousClass& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::AnonymousClass node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::AnonymousClass& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Class node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Class& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Class node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Class& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::ClassGeneric node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::ClassGeneric& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::ClassGeneric node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::ClassGeneric& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::CompilationUnit node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::CompilationUnit& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::CompilationUnit node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::CompilationUnit& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Enum node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Enum& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Enum node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Enum& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::EnumConstant node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::EnumConstant& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::EnumConstant node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::EnumConstant& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Import node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Import& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Import node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Import& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::InstanceInitializerBlock node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::InstanceInitializerBlock& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::InstanceInitializerBlock node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::InstanceInitializerBlock& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Interface node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Interface& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Interface node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Interface& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::InterfaceGeneric node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::InterfaceGeneric& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::InterfaceGeneric node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::InterfaceGeneric& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Method node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Method& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Method node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Method& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::MethodGeneric node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::MethodGeneric& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::MethodGeneric node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::MethodGeneric& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Module node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Module& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Module node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Module& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::ModuleDeclaration node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::ModuleDeclaration& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::ModuleDeclaration node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::ModuleDeclaration& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Package node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Package& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Package node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Package& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::PackageDeclaration node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::PackageDeclaration& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::PackageDeclaration node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::PackageDeclaration& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Parameter node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Parameter& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Parameter node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Parameter& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::StaticInitializerBlock node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::StaticInitializerBlock& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::StaticInitializerBlock node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::StaticInitializerBlock& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::TypeParameter node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::TypeParameter& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::TypeParameter node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::TypeParameter& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the struc::Variable node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const struc::Variable& node, bool callVirtualBase = true);

      /**
      * \brief Converts the struc::Variable node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const struc::Variable& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ArrayType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ArrayType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ArrayType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ArrayType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::BooleanType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::BooleanType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::BooleanType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::BooleanType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ByteType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ByteType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ByteType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ByteType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::CharType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::CharType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::CharType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::CharType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ClassType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ClassType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ClassType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ClassType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::DoubleType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::DoubleType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::DoubleType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::DoubleType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ErrorType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ErrorType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ErrorType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ErrorType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::FloatType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::FloatType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::FloatType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::FloatType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::IntType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::IntType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::IntType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::IntType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::IntersectionType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::IntersectionType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::IntersectionType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::IntersectionType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::LongType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::LongType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::LongType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::LongType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::LowerBoundedWildcardType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::LowerBoundedWildcardType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::LowerBoundedWildcardType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::LowerBoundedWildcardType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::MethodType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::MethodType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::MethodType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::MethodType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ModuleType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ModuleType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ModuleType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ModuleType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::NoType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::NoType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::NoType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::NoType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::NullType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::NullType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::NullType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::NullType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::PackageType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::PackageType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::PackageType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::PackageType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ParameterizedType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ParameterizedType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ParameterizedType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ParameterizedType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::ShortType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::ShortType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::ShortType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::ShortType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::TypeVariable node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::TypeVariable& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::TypeVariable node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::TypeVariable& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::UnboundedWildcardType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::UnboundedWildcardType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::UnboundedWildcardType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::UnboundedWildcardType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::UnionType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::UnionType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::UnionType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::UnionType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::UpperBoundedWildcardType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::UpperBoundedWildcardType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::UpperBoundedWildcardType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::UpperBoundedWildcardType& node, bool callVirtualBase = true);

      /**
      * \brief Writes the Graphml representation of the type::VoidType node into the output file.
      * \param node [in] The node which is visited.
      */
      virtual void visit(const type::VoidType& node, bool callVirtualBase = true);

      /**
      * \brief Converts the type::VoidType node.
      * \param node [in] The node which is visited.
      */
      virtual void visitEnd(const type::VoidType& node, bool callVirtualBase = true);

      /**
      * \brief Edge visitor for comments edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCommentable_Comments(const base::Commentable& begin, const base::Comment& end);

      /**
      * \brief Edge  visitor for hasAnnotations edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAnnotatedTypeExpression_HasAnnotations(const expr::AnnotatedTypeExpression& begin, const expr::Annotation& end);

      /**
      * \brief Edge  visitor for hasUnderlyingType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAnnotatedTypeExpression_HasUnderlyingType(const expr::AnnotatedTypeExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasAnnotationName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAnnotation_HasAnnotationName(const expr::Annotation& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasComponentType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitArrayTypeExpression_HasComponentType(const expr::ArrayTypeExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasLeftOperand edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitBinary_HasLeftOperand(const expr::Binary& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasRightOperand edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitBinary_HasRightOperand(const expr::Binary& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasComponentType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitClassLiteral_HasComponentType(const expr::ClassLiteral& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasCondition edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitConditional_HasCondition(const expr::Conditional& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasTrueExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitConditional_HasTrueExpression(const expr::Conditional& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasFalseExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitConditional_HasFalseExpression(const expr::Conditional& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasErrors edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitErroneous_HasErrors(const expr::Erroneous& begin, const base::Positioned& end);

      /**
      * \brief Edge  visitor for hasErrors edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitErroneousTypeExpression_HasErrors(const expr::ErroneousTypeExpression& begin, const base::Positioned& end);

      /**
      * \brief Edge visitor for type edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitExpression_Type(const expr::Expression& begin, const type::Type& end);

      /**
      * \brief Edge visitor for target edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitFunctionalExpression_Target(const expr::FunctionalExpression& begin, const type::Type& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitIdentifier_RefersTo(const expr::Identifier& begin, const base::Named& end);

      /**
      * \brief Edge  visitor for hasTypeOperand edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitInstanceOf_HasTypeOperand(const expr::InstanceOf& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasParameters edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitLambda_HasParameters(const expr::Lambda& begin, const struc::Parameter& end);

      /**
      * \brief Edge  visitor for hasBody edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitLambda_HasBody(const expr::Lambda& begin, const base::Positioned& end);

      /**
      * \brief Edge  visitor for hasQualifierExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMemberReference_HasQualifierExpression(const expr::MemberReference& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasTypeArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMemberReference_HasTypeArguments(const expr::MemberReference& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge visitor for referredMethod edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMemberReference_ReferredMethod(const expr::MemberReference& begin, const struc::MethodDeclaration& end);

      /**
      * \brief Edge  visitor for hasTypeArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodInvocation_HasTypeArguments(const expr::MethodInvocation& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodInvocation_HasArguments(const expr::MethodInvocation& begin, const expr::Expression& end);

      /**
      * \brief Edge visitor for invokes edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodInvocation_Invokes(const expr::MethodInvocation& begin, const struc::MethodDeclaration& end);

      /**
      * \brief Edge  visitor for hasComponentType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewArray_HasComponentType(const expr::NewArray& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasDimensions edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewArray_HasDimensions(const expr::NewArray& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasInitializers edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewArray_HasInitializers(const expr::NewArray& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasEnclosingExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewClass_HasEnclosingExpression(const expr::NewClass& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasTypeArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewClass_HasTypeArguments(const expr::NewClass& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasTypeName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewClass_HasTypeName(const expr::NewClass& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewClass_HasArguments(const expr::NewClass& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasAnonymousClass edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewClass_HasAnonymousClass(const expr::NewClass& begin, const struc::AnonymousClass& end);

      /**
      * \brief Edge visitor for constructor edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNewClass_Constructor(const expr::NewClass& begin, const struc::NormalMethod& end);

      /**
      * \brief Edge  visitor for hasArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNormalAnnotation_HasArguments(const expr::NormalAnnotation& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasQualifierType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitQualifiedTypeExpression_HasQualifierType(const expr::QualifiedTypeExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasSimpleType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitQualifiedTypeExpression_HasSimpleType(const expr::QualifiedTypeExpression& begin, const expr::SimpleTypeExpression& end);

      /**
      * \brief Edge  visitor for hasArgument edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitSingleElementAnnotation_HasArgument(const expr::SingleElementAnnotation& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasRawType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeApplyExpression_HasRawType(const expr::TypeApplyExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasTypeArguments edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeApplyExpression_HasTypeArguments(const expr::TypeApplyExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasTypeOperand edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeCast_HasTypeOperand(const expr::TypeCast& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasBounds edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeIntersectionExpression_HasBounds(const expr::TypeIntersectionExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasAlternatives edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeUnionExpression_HasAlternatives(const expr::TypeUnionExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasOperand edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitUnary_HasOperand(const expr::Unary& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasBound edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitWildcardExpression_HasBound(const expr::WildcardExpression& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasPackageName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitExports_HasPackageName(const module::Exports& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasModuleNames edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitExports_HasModuleNames(const module::Exports& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasPackageName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitOpens_HasPackageName(const module::Opens& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasModuleNames edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitOpens_HasModuleNames(const module::Opens& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasServiceName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitProvides_HasServiceName(const module::Provides& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasImplementationNames edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitProvides_HasImplementationNames(const module::Provides& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasModuleName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitRequires_HasModuleName(const module::Requires& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasServiceName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitUses_HasServiceName(const module::Uses& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasCondition edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAssert_HasCondition(const statm::Assert& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasDetail edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAssert_HasDetail(const statm::Assert& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasInitializers edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitBasicFor_HasInitializers(const statm::BasicFor& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasCondition edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitBasicFor_HasCondition(const statm::BasicFor& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasUpdates edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitBasicFor_HasUpdates(const statm::BasicFor& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasStatements edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitBlock_HasStatements(const statm::Block& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCase_HasExpression(const statm::Case& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasCondition edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitDo_HasCondition(const statm::Do& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasParameter edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitEnhancedFor_HasParameter(const statm::EnhancedFor& begin, const struc::Parameter& end);

      /**
      * \brief Edge  visitor for hasExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitEnhancedFor_HasExpression(const statm::EnhancedFor& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitExpressionStatement_HasExpression(const statm::ExpressionStatement& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasParameter edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitHandler_HasParameter(const statm::Handler& begin, const struc::Parameter& end);

      /**
      * \brief Edge  visitor for hasBlock edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitHandler_HasBlock(const statm::Handler& begin, const statm::Block& end);

      /**
      * \brief Edge  visitor for hasSubstatement edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitIf_HasSubstatement(const statm::If& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasFalseSubstatement edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitIf_HasFalseSubstatement(const statm::If& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasSubstatement edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitIteration_HasSubstatement(const statm::Iteration& begin, const statm::Statement& end);

      /**
      * \brief Edge visitor for target edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitJump_Target(const statm::Jump& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasStatement edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitLabeledStatement_HasStatement(const statm::LabeledStatement& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitReturn_HasExpression(const statm::Return& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasCondition edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitSelection_HasCondition(const statm::Selection& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasCases edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitSwitch_HasCases(const statm::Switch& begin, const statm::SwitchLabel& end);

      /**
      * \brief Edge  visitor for hasStatements edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitSwitchLabel_HasStatements(const statm::SwitchLabel& begin, const statm::Statement& end);

      /**
      * \brief Edge  visitor for hasLock edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitSynchronized_HasLock(const statm::Synchronized& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasBlock edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitSynchronized_HasBlock(const statm::Synchronized& begin, const statm::Block& end);

      /**
      * \brief Edge  visitor for hasExpression edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitThrow_HasExpression(const statm::Throw& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasResources edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTry_HasResources(const statm::Try& begin, const base::Base& end);

      /**
      * \brief Edge  visitor for hasBlock edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTry_HasBlock(const statm::Try& begin, const statm::Block& end);

      /**
      * \brief Edge  visitor for hasHandlers edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTry_HasHandlers(const statm::Try& begin, const statm::Handler& end);

      /**
      * \brief Edge  visitor for hasFinallyBlock edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTry_HasFinallyBlock(const statm::Try& begin, const statm::Block& end);

      /**
      * \brief Edge  visitor for hasCondition edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitWhile_HasCondition(const statm::While& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasAnnotations edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAnnotatedElement_HasAnnotations(const struc::AnnotatedElement& begin, const expr::Annotation& end);

      /**
      * \brief Edge  visitor for hasDefaultValue edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitAnnotationTypeElement_HasDefaultValue(const struc::AnnotationTypeElement& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasPackageDeclaration edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCompilationUnit_HasPackageDeclaration(const struc::CompilationUnit& begin, const struc::PackageDeclaration& end);

      /**
      * \brief Edge  visitor for hasImports edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCompilationUnit_HasImports(const struc::CompilationUnit& begin, const struc::Import& end);

      /**
      * \brief Edge  visitor for hasOthers edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCompilationUnit_HasOthers(const struc::CompilationUnit& begin, const base::Positioned& end);

      /**
      * \brief Edge  visitor for hasModuleDeclaration edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCompilationUnit_HasModuleDeclaration(const struc::CompilationUnit& begin, const struc::ModuleDeclaration& end);

      /**
      * \brief Edge visitor for typeDeclarations edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCompilationUnit_TypeDeclarations(const struc::CompilationUnit& begin, const struc::TypeDeclaration& end);

      /**
      * \brief Edge visitor for isInModule edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitCompilationUnit_IsInModule(const struc::CompilationUnit& begin, const struc::Module& end);

      /**
      * \brief Edge  visitor for hasNewClass edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitEnumConstant_HasNewClass(const struc::EnumConstant& begin, const expr::NewClass& end);

      /**
      * \brief Edge  visitor for hasTypeParameters edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitGenericDeclaration_HasTypeParameters(const struc::GenericDeclaration& begin, const struc::TypeParameter& end);

      /**
      * \brief Edge  visitor for hasTarget edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitImport_HasTarget(const struc::Import& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasBody edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitInitializerBlock_HasBody(const struc::InitializerBlock& begin, const statm::Block& end);

      /**
      * \brief Edge  visitor for hasReturnType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodDeclaration_HasReturnType(const struc::MethodDeclaration& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge visitor for methodType edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodDeclaration_MethodType(const struc::MethodDeclaration& begin, const type::MethodType& end);

      /**
      * \brief Edge visitor for overrides edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodDeclaration_Overrides(const struc::MethodDeclaration& begin, const struc::MethodDeclaration& end);

      /**
      * \brief Edge visitor for packages edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitModule_Packages(const struc::Module& begin, const struc::Package& end);

      /**
      * \brief Edge  visitor for hasName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitModuleDeclaration_HasName(const struc::ModuleDeclaration& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasDirectives edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitModuleDeclaration_HasDirectives(const struc::ModuleDeclaration& begin, const module::ModuleDirective& end);

      /**
      * \brief Edge visitor for moduleType edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitModuleDeclaration_ModuleType(const struc::ModuleDeclaration& begin, const type::ModuleType& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitModuleDeclaration_RefersTo(const struc::ModuleDeclaration& begin, const struc::Module& end);

      /**
      * \brief Edge  visitor for hasParameters edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNormalMethod_HasParameters(const struc::NormalMethod& begin, const struc::Parameter& end);

      /**
      * \brief Edge  visitor for hasBody edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNormalMethod_HasBody(const struc::NormalMethod& begin, const statm::Block& end);

      /**
      * \brief Edge  visitor for hasThrownExceptions edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitNormalMethod_HasThrownExceptions(const struc::NormalMethod& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasCompilationUnits edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitPackage_HasCompilationUnits(const struc::Package& begin, const struc::CompilationUnit& end);

      /**
      * \brief Edge visitor for isInModule edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitPackage_IsInModule(const struc::Package& begin, const struc::Module& end);

      /**
      * \brief Edge  visitor for hasPackageName edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitPackageDeclaration_HasPackageName(const struc::PackageDeclaration& begin, const expr::Expression& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitPackageDeclaration_RefersTo(const struc::PackageDeclaration& begin, const struc::Package& end);

      /**
      * \brief Edge  visitor for hasMembers edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitScope_HasMembers(const struc::Scope& begin, const struc::Member& end);

      /**
      * \brief Edge  visitor for hasSuperClass edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeDeclaration_HasSuperClass(const struc::TypeDeclaration& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasSuperInterfaces edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeDeclaration_HasSuperInterfaces(const struc::TypeDeclaration& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasOthers edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeDeclaration_HasOthers(const struc::TypeDeclaration& begin, const base::Positioned& end);

      /**
      * \brief Edge visitor for isInCompilationUnit edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeDeclaration_IsInCompilationUnit(const struc::TypeDeclaration& begin, const struc::CompilationUnit& end);

      /**
      * \brief Edge visitor for isInModule edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeDeclaration_IsInModule(const struc::TypeDeclaration& begin, const struc::Module& end);

      /**
      * \brief Edge  visitor for hasBounds edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeParameter_HasBounds(const struc::TypeParameter& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge  visitor for hasInitialValue edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitVariable_HasInitialValue(const struc::Variable& begin, const expr::Expression& end);

      /**
      * \brief Edge  visitor for hasType edge which is called when the subtree of this edge is started.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitVariableDeclaration_HasType(const struc::VariableDeclaration& begin, const expr::TypeExpression& end);

      /**
      * \brief Edge visitor for componentType edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitArrayType_ComponentType(const type::ArrayType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitClassType_RefersTo(const type::ClassType& begin, const struc::TypeDeclaration& end);

      /**
      * \brief Edge visitor for bounds edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitIntersectionType_Bounds(const type::IntersectionType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for returnType edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodType_ReturnType(const type::MethodType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for parameterTypes edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodType_ParameterTypes(const type::MethodType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for thrownTypes edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitMethodType_ThrownTypes(const type::MethodType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitModuleType_RefersTo(const type::ModuleType& begin, const struc::Module& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitPackageType_RefersTo(const type::PackageType& begin, const struc::Package& end);

      /**
      * \brief Edge visitor for rawType edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitParameterizedType_RawType(const type::ParameterizedType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for argumentTypes edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitParameterizedType_ArgumentTypes(const type::ParameterizedType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for owner edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitScopedType_Owner(const type::ScopedType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for refersTo edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitTypeVariable_RefersTo(const type::TypeVariable& begin, const struc::TypeParameter& end);

      /**
      * \brief Edge visitor for alternatives edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitUnionType_Alternatives(const type::UnionType& begin, const type::Type& end);

      /**
      * \brief Edge visitor for bound edge which.
      * \param begin [in] The reference of the node the edge starts from.
      * \param end   [in] The reference of the node the edge points to.
      */
      virtual void visitWildcardType_Bound(const type::WildcardType& begin, const type::Type& end);

    protected:

      /**
      * \internal
      * \brief Converts the attributes of the base::Base node.
      */
      void addAttributeToContent(const base::Base& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::BlockComment node.
      */
      void addAttributeToContent(const base::BlockComment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::Comment node.
      */
      void addAttributeToContent(const base::Comment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::Commentable node.
      */
      void addAttributeToContent(const base::Commentable& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::JavadocComment node.
      */
      void addAttributeToContent(const base::JavadocComment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::LineComment node.
      */
      void addAttributeToContent(const base::LineComment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::Named node.
      */
      void addAttributeToContent(const base::Named& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::NonJavadocComment node.
      */
      void addAttributeToContent(const base::NonJavadocComment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::Positioned node.
      */
      void addAttributeToContent(const base::Positioned& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the base::PositionedWithoutComment node.
      */
      void addAttributeToContent(const base::PositionedWithoutComment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::AnnotatedTypeExpression node.
      */
      void addAttributeToContent(const expr::AnnotatedTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Annotation node.
      */
      void addAttributeToContent(const expr::Annotation& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::ArrayAccess node.
      */
      void addAttributeToContent(const expr::ArrayAccess& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::ArrayTypeExpression node.
      */
      void addAttributeToContent(const expr::ArrayTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Assignment node.
      */
      void addAttributeToContent(const expr::Assignment& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Binary node.
      */
      void addAttributeToContent(const expr::Binary& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::BooleanLiteral node.
      */
      void addAttributeToContent(const expr::BooleanLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::CharacterLiteral node.
      */
      void addAttributeToContent(const expr::CharacterLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::ClassLiteral node.
      */
      void addAttributeToContent(const expr::ClassLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Conditional node.
      */
      void addAttributeToContent(const expr::Conditional& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::DoubleLiteral node.
      */
      void addAttributeToContent(const expr::DoubleLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Erroneous node.
      */
      void addAttributeToContent(const expr::Erroneous& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::ErroneousTypeExpression node.
      */
      void addAttributeToContent(const expr::ErroneousTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Expression node.
      */
      void addAttributeToContent(const expr::Expression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::ExternalTypeExpression node.
      */
      void addAttributeToContent(const expr::ExternalTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::FieldAccess node.
      */
      void addAttributeToContent(const expr::FieldAccess& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::FloatLiteral node.
      */
      void addAttributeToContent(const expr::FloatLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::FunctionalExpression node.
      */
      void addAttributeToContent(const expr::FunctionalExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Identifier node.
      */
      void addAttributeToContent(const expr::Identifier& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::InfixExpression node.
      */
      void addAttributeToContent(const expr::InfixExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::InstanceOf node.
      */
      void addAttributeToContent(const expr::InstanceOf& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::IntegerLiteral node.
      */
      void addAttributeToContent(const expr::IntegerLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Lambda node.
      */
      void addAttributeToContent(const expr::Lambda& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Literal node.
      */
      void addAttributeToContent(const expr::Literal& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::LongLiteral node.
      */
      void addAttributeToContent(const expr::LongLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::MarkerAnnotation node.
      */
      void addAttributeToContent(const expr::MarkerAnnotation& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::MemberReference node.
      */
      void addAttributeToContent(const expr::MemberReference& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::MethodInvocation node.
      */
      void addAttributeToContent(const expr::MethodInvocation& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::NewArray node.
      */
      void addAttributeToContent(const expr::NewArray& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::NewClass node.
      */
      void addAttributeToContent(const expr::NewClass& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::NormalAnnotation node.
      */
      void addAttributeToContent(const expr::NormalAnnotation& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::NullLiteral node.
      */
      void addAttributeToContent(const expr::NullLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::NumberLiteral node.
      */
      void addAttributeToContent(const expr::NumberLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::ParenthesizedExpression node.
      */
      void addAttributeToContent(const expr::ParenthesizedExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::PolyExpression node.
      */
      void addAttributeToContent(const expr::PolyExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::PostfixExpression node.
      */
      void addAttributeToContent(const expr::PostfixExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::PrefixExpression node.
      */
      void addAttributeToContent(const expr::PrefixExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::PrimitiveTypeExpression node.
      */
      void addAttributeToContent(const expr::PrimitiveTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::QualifiedTypeExpression node.
      */
      void addAttributeToContent(const expr::QualifiedTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::SimpleTypeExpression node.
      */
      void addAttributeToContent(const expr::SimpleTypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::SingleElementAnnotation node.
      */
      void addAttributeToContent(const expr::SingleElementAnnotation& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::StringLiteral node.
      */
      void addAttributeToContent(const expr::StringLiteral& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Super node.
      */
      void addAttributeToContent(const expr::Super& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::This node.
      */
      void addAttributeToContent(const expr::This& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::TypeApplyExpression node.
      */
      void addAttributeToContent(const expr::TypeApplyExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::TypeCast node.
      */
      void addAttributeToContent(const expr::TypeCast& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::TypeExpression node.
      */
      void addAttributeToContent(const expr::TypeExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::TypeIntersectionExpression node.
      */
      void addAttributeToContent(const expr::TypeIntersectionExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::TypeUnionExpression node.
      */
      void addAttributeToContent(const expr::TypeUnionExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::Unary node.
      */
      void addAttributeToContent(const expr::Unary& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the expr::WildcardExpression node.
      */
      void addAttributeToContent(const expr::WildcardExpression& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the module::Exports node.
      */
      void addAttributeToContent(const module::Exports& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the module::ModuleDirective node.
      */
      void addAttributeToContent(const module::ModuleDirective& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the module::Opens node.
      */
      void addAttributeToContent(const module::Opens& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the module::Provides node.
      */
      void addAttributeToContent(const module::Provides& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the module::Requires node.
      */
      void addAttributeToContent(const module::Requires& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the module::Uses node.
      */
      void addAttributeToContent(const module::Uses& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Assert node.
      */
      void addAttributeToContent(const statm::Assert& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::BasicFor node.
      */
      void addAttributeToContent(const statm::BasicFor& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Block node.
      */
      void addAttributeToContent(const statm::Block& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Break node.
      */
      void addAttributeToContent(const statm::Break& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Case node.
      */
      void addAttributeToContent(const statm::Case& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Continue node.
      */
      void addAttributeToContent(const statm::Continue& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Default node.
      */
      void addAttributeToContent(const statm::Default& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Do node.
      */
      void addAttributeToContent(const statm::Do& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Empty node.
      */
      void addAttributeToContent(const statm::Empty& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::EnhancedFor node.
      */
      void addAttributeToContent(const statm::EnhancedFor& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::ExpressionStatement node.
      */
      void addAttributeToContent(const statm::ExpressionStatement& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::For node.
      */
      void addAttributeToContent(const statm::For& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Handler node.
      */
      void addAttributeToContent(const statm::Handler& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::If node.
      */
      void addAttributeToContent(const statm::If& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Iteration node.
      */
      void addAttributeToContent(const statm::Iteration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Jump node.
      */
      void addAttributeToContent(const statm::Jump& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::LabeledStatement node.
      */
      void addAttributeToContent(const statm::LabeledStatement& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Return node.
      */
      void addAttributeToContent(const statm::Return& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Selection node.
      */
      void addAttributeToContent(const statm::Selection& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Statement node.
      */
      void addAttributeToContent(const statm::Statement& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Switch node.
      */
      void addAttributeToContent(const statm::Switch& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::SwitchLabel node.
      */
      void addAttributeToContent(const statm::SwitchLabel& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Synchronized node.
      */
      void addAttributeToContent(const statm::Synchronized& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Throw node.
      */
      void addAttributeToContent(const statm::Throw& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::Try node.
      */
      void addAttributeToContent(const statm::Try& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the statm::While node.
      */
      void addAttributeToContent(const statm::While& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::AnnotatedElement node.
      */
      void addAttributeToContent(const struc::AnnotatedElement& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::AnnotationType node.
      */
      void addAttributeToContent(const struc::AnnotationType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::AnnotationTypeElement node.
      */
      void addAttributeToContent(const struc::AnnotationTypeElement& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::AnonymousClass node.
      */
      void addAttributeToContent(const struc::AnonymousClass& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Class node.
      */
      void addAttributeToContent(const struc::Class& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::ClassDeclaration node.
      */
      void addAttributeToContent(const struc::ClassDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::ClassGeneric node.
      */
      void addAttributeToContent(const struc::ClassGeneric& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::CompilationUnit node.
      */
      void addAttributeToContent(const struc::CompilationUnit& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Declaration node.
      */
      void addAttributeToContent(const struc::Declaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Enum node.
      */
      void addAttributeToContent(const struc::Enum& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::EnumConstant node.
      */
      void addAttributeToContent(const struc::EnumConstant& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::GenericDeclaration node.
      */
      void addAttributeToContent(const struc::GenericDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Import node.
      */
      void addAttributeToContent(const struc::Import& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::InitializerBlock node.
      */
      void addAttributeToContent(const struc::InitializerBlock& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::InstanceInitializerBlock node.
      */
      void addAttributeToContent(const struc::InstanceInitializerBlock& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Interface node.
      */
      void addAttributeToContent(const struc::Interface& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::InterfaceDeclaration node.
      */
      void addAttributeToContent(const struc::InterfaceDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::InterfaceGeneric node.
      */
      void addAttributeToContent(const struc::InterfaceGeneric& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Member node.
      */
      void addAttributeToContent(const struc::Member& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Method node.
      */
      void addAttributeToContent(const struc::Method& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::MethodDeclaration node.
      */
      void addAttributeToContent(const struc::MethodDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::MethodGeneric node.
      */
      void addAttributeToContent(const struc::MethodGeneric& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Module node.
      */
      void addAttributeToContent(const struc::Module& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::ModuleDeclaration node.
      */
      void addAttributeToContent(const struc::ModuleDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::NamedDeclaration node.
      */
      void addAttributeToContent(const struc::NamedDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::NormalMethod node.
      */
      void addAttributeToContent(const struc::NormalMethod& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Package node.
      */
      void addAttributeToContent(const struc::Package& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::PackageDeclaration node.
      */
      void addAttributeToContent(const struc::PackageDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Parameter node.
      */
      void addAttributeToContent(const struc::Parameter& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Scope node.
      */
      void addAttributeToContent(const struc::Scope& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::StaticInitializerBlock node.
      */
      void addAttributeToContent(const struc::StaticInitializerBlock& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::TypeDeclaration node.
      */
      void addAttributeToContent(const struc::TypeDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::TypeParameter node.
      */
      void addAttributeToContent(const struc::TypeParameter& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::Variable node.
      */
      void addAttributeToContent(const struc::Variable& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the struc::VariableDeclaration node.
      */
      void addAttributeToContent(const struc::VariableDeclaration& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ArrayType node.
      */
      void addAttributeToContent(const type::ArrayType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::BooleanType node.
      */
      void addAttributeToContent(const type::BooleanType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::BoundedWildcardType node.
      */
      void addAttributeToContent(const type::BoundedWildcardType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ByteType node.
      */
      void addAttributeToContent(const type::ByteType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::CharType node.
      */
      void addAttributeToContent(const type::CharType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ClassType node.
      */
      void addAttributeToContent(const type::ClassType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::DoubleType node.
      */
      void addAttributeToContent(const type::DoubleType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ErrorType node.
      */
      void addAttributeToContent(const type::ErrorType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::FloatType node.
      */
      void addAttributeToContent(const type::FloatType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::IntType node.
      */
      void addAttributeToContent(const type::IntType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::IntersectionType node.
      */
      void addAttributeToContent(const type::IntersectionType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::LongType node.
      */
      void addAttributeToContent(const type::LongType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::LowerBoundedWildcardType node.
      */
      void addAttributeToContent(const type::LowerBoundedWildcardType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::MethodType node.
      */
      void addAttributeToContent(const type::MethodType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ModuleType node.
      */
      void addAttributeToContent(const type::ModuleType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::NoType node.
      */
      void addAttributeToContent(const type::NoType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::NullType node.
      */
      void addAttributeToContent(const type::NullType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::PackageType node.
      */
      void addAttributeToContent(const type::PackageType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ParameterizedType node.
      */
      void addAttributeToContent(const type::ParameterizedType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::PrimitiveType node.
      */
      void addAttributeToContent(const type::PrimitiveType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ScopedType node.
      */
      void addAttributeToContent(const type::ScopedType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::ShortType node.
      */
      void addAttributeToContent(const type::ShortType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::Type node.
      */
      void addAttributeToContent(const type::Type& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::TypeVariable node.
      */
      void addAttributeToContent(const type::TypeVariable& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::UnboundedWildcardType node.
      */
      void addAttributeToContent(const type::UnboundedWildcardType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::UnionType node.
      */
      void addAttributeToContent(const type::UnionType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::UpperBoundedWildcardType node.
      */
      void addAttributeToContent(const type::UpperBoundedWildcardType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::VoidType node.
      */
      void addAttributeToContent(const type::VoidType& node, std::string& content, bool callVirtualBase);

      /**
      * \internal
      * \brief Converts the attributes of the type::WildcardType node.
      */
      void addAttributeToContent(const type::WildcardType& node, std::string& content, bool callVirtualBase);

      /** \internal \brief The ofstream into the DOT graph will be written. */
      columbus::io::GraphmlIO &io;

      /** \internal \brief Internal counter for generating edges. */
      long long edgeCounter;

    private:

      /** \internal \brief It contains ids of the drawed nodes */
      std::map< NodeId, bool> idsToDrawedNodes;

      /** \internal \brief How many edges are should be draw */
      unsigned int maxDrawingDepth;

      /** \internal \brief Edges names to filtering */
      std::set< std::string> edgeFilter;

      /** \internal \brief The contains is not enable to draw */
      std::set< NodeId> nodeFilter;

      /** \internal \brief The contains is not enable to draw */
      bool visitCrossEdge;

      /** \internal \brief It is need to draw into white */
      bool isColorWhite;

      /** \internal \brief Show attributes only of these node types. If it is empty then show all attributes. */
      std::set< std::string> nodeTypeAttributeFilter;

      /** \internal \brief Helper variable for determine is the actual node groupNode it visitEnd */
      NodeId lastVisitedNodeId;

      /** \internal \brief Helper variable for edgeKind grouping */
      std::list<EdgeKind> edgeKindStack;

      /** \internal \brief Helper variable for edgeKind grouping */
      std::list<NodeId> parentNodeStack;

      /** \internal \brief It is need to grouping tree nodes */
      bool isGroupingTreeNodes;

      /** \internal \brief Node type names to filtering out */
      std::set< std::string> nodeTypeFilter;

  }; // VisitorGraphml


}}}
#endif

