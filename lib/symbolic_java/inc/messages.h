#ifndef _SYM_JAVA_MSG_H_
#define _SYM_JAVA_MSG_H_

// SymbolicExecutor.cpp
// Common
#define CMSG_SYM_EXEC_STACK_IS_EMPTY                      common::WriteMsg::mlDDebug, "  !!! Something went wrong, there is no definition on the stack\n"
#define CMSG_SYM_EXEC_LVALUE_FIND_STATIC                  common::WriteMsg::mlDDebug, "   Trying to find lValue in static blocks\n"
#define CMSG_SYM_EXEC_DYN_TYPE                            common::WriteMsg::mlDDebug, "   Reference staticTypeId: %d, dynamicTypeId: %d\n"

// Constructor
#define CMSG_SYM_EXEC_PREVISIT_START                      common::WriteMsg::mlDDebug, "Previsiting types started\n"
#define CMSG_SYM_EXEC_PREVISIT_END                        common::WriteMsg::mlDDebug, "Previsiting types finished\n"

// execute
#define CMSG_SYM_EXEC_EXECUTE_DEPTH                       common::WriteMsg::mlDDebug, "\nDepht: %d, nodeId: %d\n"
#define CMSG_SYM_EXEC_EXECUTE_VISITING                    common::WriteMsg::mlDDebug, "\nExecuting (visiting) node: %d, state: %s\n"

// execute
#define CMSG_SYM_EXEC_CALL_DIV_ENTER                      common::WriteMsg::mlDDebug, "=> entering getEntryBlocksForVirtualMethodInvocation methodInvocation: %d\n"
#define CMSG_SYM_EXEC_CALL_DIV_MI_INVOKES                 common::WriteMsg::mlDDebug, "   methodInvocation invokes: %d\n"
#define CMSG_SYM_EXEC_CALL_DIV_TYPES                      common::WriteMsg::mlDDebug, "   Method's classTypeId: %d, staticTypeId: %d, dynamicTypeId: %d\n"
#define CMSG_SYM_EXEC_CALL_DIV_SUPER                      common::WriteMsg::mlDDebug, "   Reference is a super-methodInvocation, superClassTypeId: %d, method's classTypeId: %d\n"
#define CMSG_SYM_EXEC_CALL_DIV_MI_ALL                     common::WriteMsg::mlDDebug, "   Not obviously the method call, executing for all overrides\n"
#define CMSG_SYM_EXEC_CALL_DIV_LEAVE                      common::WriteMsg::mlDDebug, "<= leaving getEntryBlocksForVirtualMethodInvocation methodInvocation: %d, methods: %s\n"

// makeCall
#define CMSG_SYM_EXEC_MAKECALL_ENTER                      common::WriteMsg::mlDDebug, "=> entering makeCall methodId: %d, calledICFG: %d\n"
#define CMSG_SYM_EXEC_MAKECALL_LEAVE                      common::WriteMsg::mlDDebug, "<= leaving  makeCall methodId: %d, calledICFG: %d\n"
#define CMSG_SYM_EXEC_MAKECALL_NEWCLASS                   common::WriteMsg::mlDDebug, "  NewClass call\n"
#define CMSG_SYM_EXEC_MAKECALL_NEWCLASS_ERRORTYPE         common::WriteMsg::mlDDebug, "  NewClass's typeId is ErrorType\n"
#define CMSG_SYM_EXEC_MAKECALL_NEWCLASS_NO_C_NO_PAR       common::WriteMsg::mlDDebug, "  NewClass's type is neither ClassType nor ParametrizedType\n"
#define CMSG_SYM_EXEC_MAKECALL_METHODINVOCATION           common::WriteMsg::mlDDebug, "  MethodInvocation call\n"
#define CMSG_SYM_EXEC_MAKECALL_NORMALMETHOD               common::WriteMsg::mlDDebug, "  Normalmethod id: %d, isStatic: %d, isToolGenerated: %d\n"
#define CMSG_SYM_EXEC_MAKECALL_METHODDECLARATION          common::WriteMsg::mlDDebug, "  MethodDeclaration id: %d, isStatic: %d, isToolGenerated: %d\n"
#define CMSG_SYM_EXEC_MAKECALL_REFERENCE_HAS_NOT_HEAP_OB  common::WriteMsg::mlDDebug, "  %s has not any heap object\n"
#define CMSG_SYM_EXEC_MAKECALL_DROP_PARAMETERS            common::WriteMsg::mlDDebug, "  Dropping %d parameters (methodInvocation: %d)\n"

// passingParameters
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_ENTER                  common::WriteMsg::mlDDebug, "=> entering passingParemters: normalmethod id: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_LEAVE                  common::WriteMsg::mlDDebug, "<= leaving  passingParemters: normalmethod id: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_PARAMETERS_NR          common::WriteMsg::mlDDebug, "    Number of method parameters: %d, number of invocation arguments: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_LAST_PARAM_IS_VARARG   common::WriteMsg::mlDDebug, "    Last parameter is vararg parameter: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_DROPPED_PARAMETERS     common::WriteMsg::mlDDebug, "    Dropped parameters: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_PASS_PARAMETER         common::WriteMsg::mlDDebug, "    Passing parameter: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_VARARG_PARAMETER       common::WriteMsg::mlDDebug, "    Parameter is vararg, dimension: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_ARRAY_PARAMETER_TYPE   common::WriteMsg::mlDDebug, "    Array componentTypeId: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_HASNOT_TYPE_EDGE       common::WriteMsg::mlWarning, "   Varargs (array) has no Type edge!\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_VARIABLE_VALUE         common::WriteMsg::mlDDebug, "    Value of the parameter: %s\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_NON_PARAMETER          common::WriteMsg::mlDDebug, "    Parameter is non-array, typeId: %d\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_INIT_NULL              common::WriteMsg::mlDDebug, "    InitValue is NULL\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_CLASS_PARAMETER        common::WriteMsg::mlDDebug, "    Class parameter\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_OBJECT_PARAMETER       common::WriteMsg::mlDDebug, "    Object parameter\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_INTEGER_BOXING         common::WriteMsg::mlDDebug, "    Boxing to Integer\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_DOUBLE_BOXING          common::WriteMsg::mlDDebug, "    Boxing to Double\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_FLOAT_BOXING           common::WriteMsg::mlDDebug, "    Boxing to Float\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_CHARACTER_BOXING       common::WriteMsg::mlDDebug, "    Boxing to Character\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_LONG_BOXING            common::WriteMsg::mlDDebug, "    Boxing to Long\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_SHORT_BOXING           common::WriteMsg::mlDDebug, "    Boxing to Short\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_BYTE_BOXING            common::WriteMsg::mlDDebug, "    Boxing to Byte\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_BOOLEAN_BOXING         common::WriteMsg::mlDDebug, "    Boxing to Boolean\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_OBJECT_BOXING          common::WriteMsg::mlDDebug, "    Boxing to Object\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_UNHANDLED_BOXING       common::WriteMsg::mlWarning, "    Unhandled boxing\n"
#define CMSG_SYM_EXEC_PASSINGPARAMETERS_UNHANDLED_UNBOXING     common::WriteMsg::mlWarning, "    Unhandled unboxing\n"
#define CMSG_SYM_EXEC_PASS_NONARRAY_PARAMETERS_ENTER           common::WriteMsg::mlDDebug, "    => entering passNonArrayParemters\n"
#define CMSG_SYM_EXEC_PASS_NONARRAY_PARAMETERS_LEAVE           common::WriteMsg::mlDDebug, "    <= leaving  passNonArrayParemters\n"

// makeCallReturn
#define CMSG_SYM_EXEC_MAKECALLRETURN_ENTER                  common::WriteMsg::mlDDebug, "=> entering makeCallReturn (callType: %d)\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_LEAVE                  common::WriteMsg::mlDDebug, "<= leaving  makeCallReturn (callType: %d)\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_NEWCLASS               common::WriteMsg::mlDDebug, "  call is a newClass\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD                 common::WriteMsg::mlDDebug, "  call is a method (method: %d)\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_GEN             common::WriteMsg::mlDDebug, "  call is a methodGeneric (method: %d)\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_UNHANDLED_METHODTYPE   common::WriteMsg::mlWarning, "  Unhandled methodType\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_IS_CONSTRUCTOR  common::WriteMsg::mlDDebug, "  Method is a constructor\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_WITHOUT_BODY    common::WriteMsg::mlDDebug, "  Method has not body\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_RETURN_VOID     common::WriteMsg::mlDDebug, "  Method returning void\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_HAS_RETURN      common::WriteMsg::mlDDebug, "  Method returning typeId: %d\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_THROW           common::WriteMsg::mlDDebug, "  Method is throwing an exception, pop the ReferenceValueDefinition\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHOD_DIFF_RET_TYPE   common::WriteMsg::mlDDebug, "  Different return types (method's return typeId: %d, topDefintion typeId: %d)\n"
#define CMSG_SYM_EXEC_MAKECALLRETURN_METHODINV_FILTERED     common::WriteMsg::mlDDebug, "  MethodInvocation is filtered out (methodId: %d)\n"

// initializeThis
#define CMSG_SYM_EXEC_INITIALIZE_THIS_ENTER                 common::WriteMsg::mlDDebug, "=> entering initializeThis (ICFG: %d)\n"
#define CMSG_SYM_EXEC_INITIALIZE_THIS_LEAVE                 common::WriteMsg::mlDDebug, "<= leaving  initializeThis (ICFG: %d)\n"
#define CMSG_SYM_EXEC_INITIALIZE_THIS_SEARCH_FOR_CLASS      common::WriteMsg::mlDDebug, "  Searching for class\n"
#define CMSG_SYM_EXEC_INITIALIZE_THIS_INTERFACE_FOUND       common::WriteMsg::mlDDebug, "  Found an interface class\n"
#define CMSG_SYM_EXEC_INITIALIZE_THIS_CLASS_TYPE_FOUND      common::WriteMsg::mlDDebug, "  Found a classType (classId: %d, typeId: %d)\n"
#define CMSG_SYM_EXEC_INITIALIZE_THIS_CLASS_TYPE_NOT_FOUND  common::WriteMsg::mlDDebug, "  ClassType was not found for classId: %d\n"
#define CMSG_SYM_EXEC_INITIALIZE_THIS_INIT_PARAMS           common::WriteMsg::mlDDebug, "  Initializing parameters (%d Symbols)\n"

// initializeStaticInitializer
#define CMSG_SYM_EXEC_INITIALIZE_STATIC_ENTER               common::WriteMsg::mlDDebug, "=> entering initializeStaticInitializer (ICFG: %d)\n"
#define CMSG_SYM_EXEC_INITIALIZE_STATIC_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  initializeStaticInitializer (ICFG: %d), returning %d\n"

// getClassDeclarationForMember
#define CMSG_SYM_EXEC_GET_CLASSDECLARATION_FOR_MEMBER_ENTER                 common::WriteMsg::mlDDebug, "=> entering getClassDeclarationForMember (variable nodeId: %d)\n"
#define CMSG_SYM_EXEC_GET_CLASSDECLARATION_FOR_MEMBER_LEAVE                 common::WriteMsg::mlDDebug, "<= leaving  getClassDeclarationForMember (variable nodeId: %d)\n"
#define CMSG_SYM_EXEC_GET_CLASSDECLARATION_FOR_MEMBER_PARENT_CLASS          common::WriteMsg::mlDDebug, "  Parent (nodeId: %d) is Class\n"
#define CMSG_SYM_EXEC_GET_CLASSDECLARATION_FOR_MEMBER_PARENT_METHOD         common::WriteMsg::mlDDebug, "  Parent (nodeId: %d) is Method\n"

// getEnumDeclarationForMember
#define CMSG_SYM_EXEC_GET_ENUMDECLARATION_FOR_MEMBER_ENTER                  common::WriteMsg::mlDDebug, "=> entering getEnumDeclarationForMember (variable nodeId: %d)\n"
#define CMSG_SYM_EXEC_GET_ENUMDECLARATION_FOR_MEMBER_LEAVE                  common::WriteMsg::mlDDebug, "<= leaving  getEnumDeclarationForMember (variable nodeId: %d)\n"
#define CMSG_SYM_EXEC_GET_ENUMDECLARATION_FOR_MEMBER_PARENT_ENUM            common::WriteMsg::mlDDebug, "  Parent (nodeId: %d) is Enum\n"
#define CMSG_SYM_EXEC_GET_ENUMDECLARATION_FOR_MEMBER_PARENT_METHOD          common::WriteMsg::mlDDebug, "  Parent (nodeId: %d) is Method\n"

// getInterfaceDeclarationForMember
#define CMSG_SYM_EXEC_GET_INTERFACEDECLARATION_FOR_MEMBER_ENTER             common::WriteMsg::mlDDebug, "=> entering getInterfaceDeclarationForMember (variable nodeId: %d)\n"
#define CMSG_SYM_EXEC_GET_INTERFACEDECLARATION_FOR_MEMBER_LEAVE             common::WriteMsg::mlDDebug, "<= leaving  getInterfaceDeclarationForMember (variable nodeId: %d)\n"
#define CMSG_SYM_EXEC_GET_INTERFACEDECLARATION_FOR_MEMBER_PARENT_CLASS      common::WriteMsg::mlDDebug, "  Parent (nodeId: %d) is Class\n"
#define CMSG_SYM_EXEC_GET_INTERFACEDECLARATION_FOR_MEMBER_PARENT_METHOD     common::WriteMsg::mlDDebug, "  Parent (nodeId: %d) is Method\n"

// initializeClass
#define CMSG_SYM_EXEC_INITIALIZE_CLASS_ENTER                  common::WriteMsg::mlDDebug, "=> entering initializeClass (classId: %d, classTypeId: %d)\n"
#define CMSG_SYM_EXEC_INITIALIZE_CLASS_LEAVE                  common::WriteMsg::mlDDebug, "<= leaving  initializeClass (classId: %d, classTypeId: %d) returning: %s\n"
#define CMSG_SYM_EXEC_INITIALIZE_CLASS_REFERENCE_STORED       common::WriteMsg::mlDDebug, "   Reference stored for classId: %d\n"

// visitor Base
#define CMSG_SYM_EXEC_BASE_ENTER                common::WriteMsg::mlWarning, "=> entering base::Base visitor: %d (kind: %s); this is not handled node\n"

// visitor Parameter
#define CMSG_SYM_EXEC_PARAMETER_ENTER           common::WriteMsg::mlDDebug, "=> entering struc::Parameter visitor: %d\n"
#define CMSG_SYM_EXEC_PARAMETER_LEAVE           common::WriteMsg::mlDDebug, "<= leaving  struc::Parameter visitor: %d\n"

// visitor Interface
#define CMSG_SYM_EXEC_INTERFACE_ENTER           common::WriteMsg::mlDDebug, "=> entering struc::Interface visitor: %d\n"
#define CMSG_SYM_EXEC_INTERFACE_LEAVE           common::WriteMsg::mlDDebug, "<= leaving  struc::Interface visitor: %d\n"

// visitor Variable
#define CMSG_SYM_EXEC_VARIABLE_ENTER                     common::WriteMsg::mlDDebug, "=> entering struc::Variable visitor: %d\n"
#define CMSG_SYM_EXEC_VARIABLE_LEAVE                     common::WriteMsg::mlDDebug, "<= leaving  struc::Variable visitor: %d\n"
#define CMSG_SYM_EXEC_VARIABLE_CLASSMEMBER               common::WriteMsg::mlDDebug, "  Variable is a class member\n"
#define CMSG_SYM_EXEC_VARIABLE_CLASSMEMBER_SYMBOL        common::WriteMsg::mlDDebug, "  Class member variable will be a SymbolDefinitoin with type: %d\n"
#define CMSG_SYM_EXEC_VARIABLE_LOCAL_VARIABLE            common::WriteMsg::mlDDebug, "  Variable is a local variable, hasInitialValue: %d\n"
#define CMSG_SYM_EXEC_VARIABLE_INIT_VALUE_NULL           common::WriteMsg::mlDDebug, "  Variable's init value is NULL, change its type from nullType (%d) to %d\n"
#define CMSG_SYM_EXEC_VARIABLE_HAS_HEAP_OBJECT           common::WriteMsg::mlDDebug, "  ThizObject has heap object, variable hasInitialValue: %d\n"
#define CMSG_SYM_EXEC_VARIABLE_HAS_NOT_HEAP_OBJECT       common::WriteMsg::mlWarning, "  ThizObject (%s) has not any heap object\n"
#define CMSG_SYM_EXEC_VARIABLE_NON_CLASS_PARAMETER       common::WriteMsg::mlDDebug, "    Non-class parameter (unboxing?)\n"
#define CMSG_SYM_EXEC_VARIABLE_CLASS_PARAMETER           common::WriteMsg::mlDDebug, "    Class parameter (boxing?)\n"
#define CMSG_SYM_EXEC_VARIABLE_OBJECT_PARAMETER          common::WriteMsg::mlDDebug, "    Object parameter\n"
#define CMSG_SYM_EXEC_VARIABLE_IS_STATIC                 common::WriteMsg::mlDDebug, "    Variable is static\n"
#define CMSG_SYM_EXEC_VARIABLE_VALUE                     common::WriteMsg::mlDDebug, "    Value of the variable: %s\n"

// getStaticReference
#define CMSG_SYM_EXEC_GETSTATIC_REF_ENTER                      common::WriteMsg::mlDDebug, "=> entering getStaticReference() (expectedName: ASG error! There is no refersTo edge for Identifier%s)\n"
#define CMSG_SYM_EXEC_GETSTATIC_REF_LEAVE                      common::WriteMsg::mlDDebug, "<= leaving  getStaticReference() (expectedName: %s)\n"
#define CMSG_SYM_EXEC_GETSTATIC_FOUND_STATIC_ICFG              common::WriteMsg::mlDDebug, "  Static ICFG found (methodId: %d)\n"
#define CMSG_SYM_EXEC_GETSTATIC_NOT_FOUND_STATIC_ICFG          common::WriteMsg::mlDebug, "  Something went wrong: Static ICFG not found!\n"
#define CMSG_SYM_EXEC_GETSTATIC_ICFG_VISITED_BEFORE            common::WriteMsg::mlDDebug, "  Static ICFG visited before\n"

// startExecutorForStaticBlock
#define CMSG_SYM_EXEC_START_EXECUTOR_ENTER                     common::WriteMsg::mlDDebug, "=> entering startExecutorForStaticBlock() (methodId: %d)\n"
#define CMSG_SYM_EXEC_START_EXECUTOR_LEAVE                     common::WriteMsg::mlDDebug, "<= leaving  startExecutorForStaticBlock() (methodId: %d)\n"
#define CMSG_SYM_EXEC_START_EXECUTOR_INITING                   common::WriteMsg::mlDDebug, "  Static ICFG is under initialization\n"

// visitor Identifier
#define CMSG_SYM_EXEC_IDENTIFIER_ENTER                          common::WriteMsg::mlDDebug, "=> entering expr::Identifier visitor: %d\n"
#define CMSG_SYM_EXEC_IDENTIFIER_LEAVE                          common::WriteMsg::mlDDebug, "<= leaving  expr::Identifier visitor: %d\n"
#define CMSG_SYM_EXEC_IDENTIFIER_PARENT_FA                      common::WriteMsg::mlDDebug, "  Parent is FieldAccess (nodeId: %d)\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_FA_DESCRIPTOR               common::WriteMsg::mlDDebug, "  Identifier is a FieldAccess's descriptor\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_FA_SELECTOR                 common::WriteMsg::mlDDebug, "  Identifier is a FieldAccess's selector\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_FILTERED_OUT          common::WriteMsg::mlDDebug, "  Identifier refersTo is filtered out\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_NODEID                common::WriteMsg::mlDDebug, "  Identifier refersTo nodeId: %d\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_FLOAT_NAN             common::WriteMsg::mlDDebug, "  Identifier refersTo is Float NaN\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_FLOAT_NEG_INF         common::WriteMsg::mlDDebug, "  Identifier refersTo is Float Negative Infinite\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_FLOAT_POS_INF         common::WriteMsg::mlDDebug, "  Identifier refersTo is Float Positive Infinite\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_DOUBLE_NAN            common::WriteMsg::mlDDebug, "  Identifier refersTo is Double NaN\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_DOUBLE_NEG_INF        common::WriteMsg::mlDDebug, "  Identifier refersTo is Double Negative Infinite\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_DOUBLE_POS_INF        common::WriteMsg::mlDDebug, "  Identifier refersTo is Double Positive Infinite\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NO_REFERSTO_EDGE               common::WriteMsg::mlDebug, "  ASG error! There is no refersTo edge for Identifier\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_MI_OPERAND                  common::WriteMsg::mlDDebug, "  Identifier refersTo is a MethodInvocation's operand\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_METHOD                      common::WriteMsg::mlDDebug, "  Identifier refersTo is a Method (nodeId: %d)\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_METHOD_HAS_RETURN_TYPE      common::WriteMsg::mlDDebug, "  Identifier refersTo is a Method, which has return type\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_CLASS                       common::WriteMsg::mlDDebug, "  Identifier refersTo is a Class\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_ENUM                        common::WriteMsg::mlDDebug, "  Identifier refersTo is an Enum\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_ENUMCONSTANT                common::WriteMsg::mlDDebug, "  Identifier refersTo is an EnumConstant\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_INTERFACE                   common::WriteMsg::mlDDebug, "  Identifier refersTo is an Interface\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_CLASSGENERIC                common::WriteMsg::mlDDebug, "  Identifier refersTo is a ClassGeneric\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_VARIABLE                    common::WriteMsg::mlDDebug, "  Identifier refersTo is a Variable\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_PARAMETER                   common::WriteMsg::mlDDebug, "  Identifier refersTo is a Parameter\n"
#define CMSG_SYM_EXEC_IDENTIFIER_IS_VARARG_PARAMETER            common::WriteMsg::mlDDebug, "  Identifier refersTo is a VarArg parameter\n"
#define CMSG_SYM_EXEC_IDENTIFIER_VARIABLE_IS_CLASS_MEMBER       common::WriteMsg::mlDDebug, "  RefersTo variable is a class member\n"
#define CMSG_SYM_EXEC_IDENTIFIER_VARIABLE_IS_NOT_CLASS_MEMBER   common::WriteMsg::mlDDebug, "  RefersTo variable is not a Field Access\n"
#define CMSG_SYM_EXEC_IDENTIFIER_TRY_GET_FROM_THIZOBJECT        common::WriteMsg::mlDDebug, "  Try to get variable from thizObject\n"
#define CMSG_SYM_EXEC_IDENTIFIER_TRY_NOT_FOUND_IN_THIZOBJECT    common::WriteMsg::mlDDebug, "  Variable not found in thizObject, try to get from state context and heap\n"
#define CMSG_SYM_EXEC_IDENTIFIER_STATIC_VARIABLE                common::WriteMsg::mlDDebug, "  Static variable\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NON_STATIC_VARIABLE            common::WriteMsg::mlDDebug, "  Non Static variable\n"
#define CMSG_SYM_EXEC_IDENTIFIER_STATIC_VARIABLE_NOT_FOUND      common::WriteMsg::mlDDebug, "  Static variable has not owner, try to find it its classObject\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NON_STATIC_VARIABLE_NOT_FOUND  common::WriteMsg::mlDDebug, "  Non static variable has not owner\n"
#define CMSG_SYM_EXEC_IDENTIFIER_VARIABLE_NOT_FOUND             common::WriteMsg::mlDDebug, "  Variable has not owner\n"
#define CMSG_SYM_EXEC_IDENTIFIER_REFERSTO_IS_UNHANDLED          common::WriteMsg::mlWarning, "  Identifier refersTo is unhandled\n"
#define CMSG_SYM_EXEC_IDENTIFIER_VARIABLE_SEARCH_IN_CLASS       common::WriteMsg::mlDDebug, "  Searching variable in classId: %d\n"
#define CMSG_SYM_EXEC_IDENTIFIER_FOUND_VARIABLE                 common::WriteMsg::mlDDebug, "  Variable is found: %d\n"
#define CMSG_SYM_EXEC_IDENTIFIER_CHECK_REFERSTO_TYPE            common::WriteMsg::mlDDebug, "  Checking refersTo typeId: %d\n"
#define CMSG_SYM_EXEC_IDENTIFIER_CHECK_REFERSTO_TYPE_CLASS      common::WriteMsg::mlDDebug, "  RefersTo type is ClassType, creating new heap object\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NODE_NOT_FOUND                 common::WriteMsg::mlDDebug, "  RefersTo node not found in the Proxy tree, try to find it in static initializers\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NODE_FOUND_IN_ICFG             common::WriteMsg::mlDDebug, "  RefersTo node found in ICFG (nodeId: %d) static initializer\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NODE_NS_AND_NF                 common::WriteMsg::mlDDebug, "  RefersTo node neither static nor found in Proxy tree\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NON_STATIC_VARIABLE_FOUND      common::WriteMsg::mlDDebug, "  Non-static variable found\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NON_STATIC_VARIABLE_VISIT_INIT common::WriteMsg::mlDDebug, "  Static variable, visit the static initializer\n"
#define CMSG_SYM_EXEC_IDENTIFIER_NON_ENUM_VISIT_INIT            common::WriteMsg::mlDDebug, "  EnumConstant found, visit the enum initializer\n"

// visitor Postfix
#define CMSG_SYM_EXEC_POSTFIX_ENTER             common::WriteMsg::mlDDebug, "=> entering expr::PostfixExpression visitor: %d (kind: %s)\n"
#define CMSG_SYM_EXEC_POSTFIX_LEAVE             common::WriteMsg::mlDDebug, "<= leaving  expr::PostfixExpression visitor: %d\n"

// visitor Prefix
#define CMSG_SYM_EXEC_PREFIX_ENTER              common::WriteMsg::mlDDebug, "=> entering expr::PrefixExpression visitor: %d (kind: %s)\n"
#define CMSG_SYM_EXEC_PREFIX_LEAVE              common::WriteMsg::mlDDebug, "<= leaving  expr::PrefixExpression visitor: %d\n"

// visitor Assignment
#define CMSG_SYM_EXEC_ASSIGNMENT_ENTER          common::WriteMsg::mlDDebug, "=> entering expr::Assignment visitor: %d (kind: %s)\n"
#define CMSG_SYM_EXEC_ASSIGNMENT_BOXING         common::WriteMsg::mlDDebug, "   Boxing to typeId %d from typeId %d\n"
#define CMSG_SYM_EXEC_ASSIGNMENT_UNBOXING       common::WriteMsg::mlDDebug, "   Unoxing to typeId %d from typeId %d\n"
#define CMSG_SYM_EXEC_ASSIGNMENT_LEAVE          common::WriteMsg::mlDDebug, "<= leaving  expr::Assignment visitor: %d\n"

// visitor Infix
#define CMSG_SYM_EXEC_INFIX_ENTER               common::WriteMsg::mlDDebug, "=> entering expr::InfixExpression visitor: %d (kind: %s)\n"
#define CMSG_SYM_EXEC_INFIX_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  expr::InfixExpression visitor: %d\n"

// visitor NewClass
#define CMSG_SYM_EXEC_NEWCLASS_ENTER                   common::WriteMsg::mlDDebug, "=> entering expr::NewClass visitor: %d\n"
#define CMSG_SYM_EXEC_NEWCLASS_LEAVE                   common::WriteMsg::mlDDebug, "<= leaving  expr::NewClass visitor: %d\n"
#define CMSG_SYM_EXEC_NEWCLASS_CONSTRUCTOR_FILTERED    common::WriteMsg::mlDDebug, "  NewClass's constructor is filtered out\n"
#define CMSG_SYM_EXEC_NEWCLASS_DROP_PARAMETERS         common::WriteMsg::mlDDebug, "  Dropping %d parameters\n"
#define CMSG_SYM_EXEC_NEWCLASS_BOXING_SYMBOL           common::WriteMsg::mlDDebug, "  Creating new Symbol for boxing class (typeId: %d)\n"
#define CMSG_SYM_EXEC_NEWCLASS_STRING_SYMBOL           common::WriteMsg::mlDDebug, "  Creating new Symbol for String object (typeId: %d)\n"
#define CMSG_SYM_EXEC_NEWCLASS_NEW_HEAP_OBJECT         common::WriteMsg::mlDDebug, "  Creating new heapObject with typeId: %d\n"
#define CMSG_SYM_EXEC_NEWCLASS_PARENT_THROW            common::WriteMsg::mlDDebug, "  NewClass's parent is statm::Throw (%d)\n"
#define CMSG_SYM_EXEC_NEWCLASS_PARENT_THROW_METHODID   common::WriteMsg::mlDDebug, "  Throw methodId: %d\n"
#define CMSG_SYM_EXEC_NEWCLASS_PARENT_ENUMCONSTANT     common::WriteMsg::mlDDebug, "  NewClass's parent is EnumConstant (enumClassId: %d, enumConstantId: %d)\n"
#define CMSG_SYM_EXEC_NEWCLASS_FOUND_ENUMCLASSID       common::WriteMsg::mlDDebug, "  EnumClassId found in stored references, replace it\n"

// visitor NewArray
#define CMSG_SYM_EXEC_NEWARRAY_ENTER                   common::WriteMsg::mlDDebug, "=> entering expr::NewArray visitor: %d\n"
#define CMSG_SYM_EXEC_NEWARRAY_PREFS                   common::WriteMsg::mlDDebug, "   NewArray's dimensionSize: %d, initializerSize: %d\n"
#define CMSG_SYM_EXEC_NEWARRAY_WITH_INIT               common::WriteMsg::mlDDebug, "   NewArray with initializer\n"
#define CMSG_SYM_EXEC_NEWARRAY_WITHOUT_INIT            common::WriteMsg::mlDDebug, "   NewArray without initializer\n"
#define CMSG_SYM_EXEC_NEWARRAY_WITHOUT_INIT_DIMS       common::WriteMsg::mlDDebug, "   %d. dimension: %d\n"
#define CMSG_SYM_EXEC_NEWARRAY_WITHOUT_INIT_COMPS      common::WriteMsg::mlDDebug, "   %d. component typeId: %d\n"
#define CMSG_SYM_EXEC_NEWARRAY_WITHOUT_INIT_NO_COMP    common::WriteMsg::mlDDebug, "   There is no componentTypeId at %d. dimension\n"
#define CMSG_SYM_EXEC_NEWARRAY_DIM_INVALID             common::WriteMsg::mlDDebug, "   Invalid dimension size: %d\n"
#define CMSG_SYM_EXEC_NEWARRAY_TYPE_ID                 common::WriteMsg::mlDDebug, "   array typeId: %d\n"
#define CMSG_SYM_EXEC_NEWARRAY_HASNOT_TYPE_EDGE        common::WriteMsg::mlWarning, "   NewArray has no Type edge!\n"
#define CMSG_SYM_EXEC_NEWARRAY_LEAVE                   common::WriteMsg::mlDDebug, "<= leaving  expr::NewArray visitor: %d\n"

// visitor ArrayAccess
#define CMSG_SYM_EXEC_ARRAYACCESS_ENTER                common::WriteMsg::mlDDebug, "=> entering expr::ArrayAccess visitor: %d\n"
#define CMSG_SYM_EXEC_ARRAYACCESS_COM_TYPE             common::WriteMsg::mlDDebug, "  componentTypeId: %d\n"
#define CMSG_SYM_EXEC_ARRAYACCESS_SIZE                 common::WriteMsg::mlDDebug, "  length of Array: %s\n"
#define CMSG_SYM_EXEC_ARRAYACCESS_COORD_SYM            common::WriteMsg::mlDDebug, "  coord is a Symbol\n"
#define CMSG_SYM_EXEC_ARRAYACCESS_SEL_VARIABLE         common::WriteMsg::mlDDebug, "  ArrayAccess's selector is a Variable (%d)\n"
#define CMSG_SYM_EXEC_ARRAYACCESS_SEL_NOT_VARIABLE     common::WriteMsg::mlDDebug, "  ArrayAccess's selector is not a Variable (%d)\n"
#define CMSG_SYM_EXEC_ARRAYACCESS_LEAVE                common::WriteMsg::mlDDebug, "<= leaving  expr::ArrayAccess visitor: %d\n"

// visitor FieldAccess
#define CMSG_SYM_EXEC_FIELDACCESS_ENTER                             common::WriteMsg::mlDDebug, "=> entering expr::FieldAccess visitor: %d\n"
#define CMSG_SYM_EXEC_FIELDACCESS_LEAVE                             common::WriteMsg::mlDDebug, "<= leaving  expr::FieldAccess visitor: %d\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR                        common::WriteMsg::mlDDebug, "  Descriptor id: %d\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_FILTERED_OUT           common::WriteMsg::mlDDebug, "  Descriptor's refersTo is filtered out\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_FILTERED_OUT_NO_TYPE   common::WriteMsg::mlWarning, "  Filtered out refersTo has no Type Edge\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESC_FILTERED_OUT_NORMALMETHOD    common::WriteMsg::mlDDebug, "  Filtered refersTo is normalMethod (%d)\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_IS_STATIC_VARIABLE     common::WriteMsg::mlDDebug, "  Descriptor is a static variable\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_IS_NOT_STATIC_VARIABLE common::WriteMsg::mlDDebug, "  Descriptor isn't a static variable\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_FILTERED_NO_REFERSTO   common::WriteMsg::mlDDebug, "  Filtered out descriptor has no refersTo edge\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DROP_PARAMETERS                   common::WriteMsg::mlDDebug, "  Dropping %d parameters (methodInvocation: %d)\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_ID                     common::WriteMsg::mlDDebug, "  Descriptor refersTo nodeId: %d\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_NORMALMETHOD           common::WriteMsg::mlDDebug, "  Descriptor is NormalMethod\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESCRIPTOR_ENUMCONSTANT           common::WriteMsg::mlDDebug, "  Descriptor is EnumConstant\n"
#define CMSG_SYM_EXEC_FIELDACCESS_CLASSREF_HASHEAP_OBJECT           common::WriteMsg::mlDDebug, "  Class reference has heap Object\n"
#define CMSG_SYM_EXEC_FIELDACCESS_CLASSREF_HASNT_HEAP_OBJECT        common::WriteMsg::mlDDebug, "  Class reference hasn't any heap Object\n"
#define CMSG_SYM_EXEC_FIELDACCESS_CLASSREF_HASNT_OWNER              common::WriteMsg::mlDDebug, "  Class reference hasn't any Owner, creating it\n"
#define CMSG_SYM_EXEC_FIELDACCESS_CLASSREF_MEMBER_TYPE              common::WriteMsg::mlDDebug, "  Member (%d) has typeId: %d\n"
#define CMSG_SYM_EXEC_FIELDACCESS_NO_REFERSTO_EDGE                  common::WriteMsg::mlWarning, "  ASG error! There is no refersTo edge for FieldAccess's descriptor\n"
#define CMSG_SYM_EXEC_FIELDACCESS_CHECK_REFERSTO_TYPE               common::WriteMsg::mlDDebug, "  Checking return typeId: %d\n"
#define CMSG_SYM_EXEC_FIELDACCESS_CHECK_REFERSTO_TYPE_CLASS         common::WriteMsg::mlDDebug, "  Return type is ClassType, creating new heap object\n"
#define CMSG_SYM_EXEC_FIELDACCESS_DESC_METHODDECLARATION            common::WriteMsg::mlDDebug, "  refersTo is methodDeclaration (%d)\n"
#define CMSG_SYM_EXEC_FIELDACCESS_PARENT_METHODINVOCATION           common::WriteMsg::mlDDebug, "  FieldAccess's parent is methodInvocation (nodeId: %d)\n"
#define CMSG_SYM_EXEC_FIELDACCESS_IS_METHODINVOCATION_OPERAND       common::WriteMsg::mlDDebug, "  FieldAccess is a methodInvocation's operand\n"

// visitor Conditional
#define CMSG_SYM_EXEC_CONDITIONAL_ENTER                             common::WriteMsg::mlDDebug, "=> entering expr::Conditional visitor: %d\n"
#define CMSG_SYM_EXEC_CONDITIONAL_LEAVE                             common::WriteMsg::mlDDebug, "<= leaving  expr::Conditional visitor: %d\n"

// visitor InstanceOf
#define CMSG_SYM_EXEC_INSTANCEOF_ENTER                                common::WriteMsg::mlDDebug, "=> entering expr::InstanceOf visitor: %d\n"
#define CMSG_SYM_EXEC_INSTANCEOF_LEAVE                                common::WriteMsg::mlDDebug, "<= leaving  expr::InstanceOf visitor: %d\n"
#define CMSG_SYM_EXEC_INSTANCEOF_OPERAND_IS_NULL                      common::WriteMsg::mlDDebug, "   Operand is null\n"
#define CMSG_SYM_EXEC_INSTANCEOF_NO_TYPE_OPERAND                      common::WriteMsg::mlWarning, "   There is not any type operand\n"
#define CMSG_SYM_EXEC_INSTANCEOF_TYPES                                common::WriteMsg::mlDDebug, "   %d instanceof %d ?\n"


// visitor Typecast
#define CMSG_SYM_EXEC_TYPECAST_ENTER                                  common::WriteMsg::mlDDebug, "=> entering expr::Typecast visitor: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_LEAVE                                  common::WriteMsg::mlDDebug, "<= leaving  expr::Typecast visitor: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_NO_TYPE_OPERAND                        common::WriteMsg::mlWarning, "  There is not any type operand\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_TO                                common::WriteMsg::mlDDebug, "  Trying cast to Type (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_UNKNOWN_DYNAMIC_TYPE                   common::WriteMsg::mlDDebug, "  Unknown dynamic type\n"
#define CMSG_SYM_EXEC_TYPECAST_OPERAND_PRIMITIVE                      common::WriteMsg::mlDDebug, "  Operand has primitiveTypeId %d\n"
#define CMSG_SYM_EXEC_TYPECAST_UNHANDLED_OPERAND_PRIMITIVE            common::WriteMsg::mlWarning, "  Unhandled oprandType\n"
#define CMSG_SYM_EXEC_TYPECAST_NOT_CASTABLE                           common::WriteMsg::mlDDebug, "  TypeId %d is not castable to typeId %d, CCE\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_CHAR_TYPE                         common::WriteMsg::mlDDebug, "  Trying cast to CharType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_BYTE_TYPE                         common::WriteMsg::mlDDebug, "  Trying cast to ByteType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_SHORT_TYPE                        common::WriteMsg::mlDDebug, "  Trying cast to ShortType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_INT_TYPE                          common::WriteMsg::mlDDebug, "  Trying cast to IntType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_LONG_TYPE                         common::WriteMsg::mlDDebug, "  Trying cast to LongType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_FLOAT_TYPE                        common::WriteMsg::mlDDebug, "  Trying cast to FloatType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_DOUBLE_TYPE                       common::WriteMsg::mlDDebug, "  Trying cast to DoubleType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_ERROR_TYPE                        common::WriteMsg::mlDDebug, "  Trying cast to ErrorType (typeId: %d) from typeId: %d\n"
#define CMSG_SYM_EXEC_TYPECAST_CAST_UNKNOWN_TYPE                      common::WriteMsg::mlWarning, "  Unhandled cast to typeId: %d\n"

// Literals
#define CMSG_SYM_EXEC_BOOLEAN_LITERAL           common::WriteMsg::mlDDebug, "Boolean literal (%d), value: %d\n"
#define CMSG_SYM_EXEC_CHARACTER_LITERAL         common::WriteMsg::mlDDebug, "Character literal (%d), value: %c\n"
#define CMSG_SYM_EXEC_INTEGER_LITERAL           common::WriteMsg::mlDDebug, "Integer literal (%d), value: %d\n"
#define CMSG_SYM_EXEC_LONG_LITERAL              common::WriteMsg::mlDDebug, "Long literal (%d), value: %ld\n"
#define CMSG_SYM_EXEC_FLOAT_LITERAL             common::WriteMsg::mlDDebug, "Float literal (%d), value: %f\n"
#define CMSG_SYM_EXEC_DOUBLE_LITERAL            common::WriteMsg::mlDDebug, "Double literal (%d), value: %f\n"
#define CMSG_SYM_EXEC_NULL_LITERAL              common::WriteMsg::mlDDebug, "Null literal (%d)\n"
#define CMSG_SYM_EXEC_STRING_LITERAL            common::WriteMsg::mlDDebug, "String literal (%d)\n"
#define CMSG_SYM_EXEC_CLASS_LITERAL             common::WriteMsg::mlDDebug, "Class literal (%d), typeId: %d\n"

// visitor This
#define CMSG_SYM_EXEC_THIS_ENTER                common::WriteMsg::mlDDebug, "=> entering expr::This visitor: %d\n"
#define CMSG_SYM_EXEC_THIS_LEAVE                common::WriteMsg::mlDDebug, "<= leaving  expr::This visitor: %d\n"
#define CMSG_SYM_EXEC_THIS_FA_DESCRIPTOR        common::WriteMsg::mlDDebug, "  expr::This is a descriptor of a FieldAccess (%d)\n"

// visitor Super
#define CMSG_SYM_EXEC_SUPER_ENTER               common::WriteMsg::mlDDebug, "=> entering expr::Super visitor: %d\n"
#define CMSG_SYM_EXEC_SUPER_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  expr::Super visitor: %d\n"

// visitor ParenthesizedExpression
#define CMSG_SYM_EXEC_PARENTHESIZED_ENTER       common::WriteMsg::mlDDebug, "=> entering expr::ParenthesizedExpression visitor: %d\n"
#define CMSG_SYM_EXEC_PARENTHESIZED_PA_SWITCH   common::WriteMsg::mlDDebug, "  Parent node is a switch statement\n"
#define CMSG_SYM_EXEC_PARENTHESIZED_LEAVE       common::WriteMsg::mlDDebug, "<= leaving  expr::ParenthesizedExpression visitor: %d\n"

// visitor MethodInvocation
#define CMSG_SYM_EXEC_METHODINVOCATION_ENTER                       common::WriteMsg::mlDDebug, "=> entering expr::MethodInvocation visitor: %d\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_LEAVE                       common::WriteMsg::mlDDebug, "<= leaving  expr::MethodInvocation visitor: %d\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_THROWS_NEWCLASS             common::WriteMsg::mlDDebug, "   MethodInvocation throws a newClass\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_NULL_RETURN_TYPE            common::WriteMsg::mlDDebug, "   MethodDeclaration (nodeId: %d) has not return type! Try to find it in methodType\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_METHOD_TYPE                 common::WriteMsg::mlDDebug, "   MethodDeclaration's type: nodeId: %d\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_METHOD_RETURN_TYPE          common::WriteMsg::mlDDebug, "   MethodDeclaration's returnType: nodeId: %d\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_METHOD_RETURN_TYPEID        common::WriteMsg::mlDDebug, "   Method's return typeId: %d\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_METHOD_RETURN_IS_ERROR_TYPE common::WriteMsg::mlDDebug, "   Method's return typeId is Error Type\n"
#define CMSG_SYM_EXEC_METHODINVOCATION_METHOD_RETURN_IS_NOT_VOID   common::WriteMsg::mlDDebug, "   Method's return typeId is not void\n"

// visitor Synchronized
#define CMSG_SYM_EXEC_SYNCHRONIZED_ENTER        common::WriteMsg::mlDDebug, "=> entering statm::Synchronized visitor: %d\n"
#define CMSG_SYM_EXEC_SYNCHRONIZED_LEAVE        common::WriteMsg::mlDDebug, "<= leaving  statm::Synchronized visitor: %d\n"

// visitor SingleElementAnnotation
#define CMSG_SYM_EXEC_SINGLEELEMENTANNOTATION_ENTER    common::WriteMsg::mlDDebug, "=> entering expr::SingleElementAnnotation visitor: %d\n"
#define CMSG_SYM_EXEC_SINGLEELEMENTANNOTATION_LEAVE    common::WriteMsg::mlDDebug, "<= leaving  expr::SingleElementAnnotation visitor: %d\n"

// visitor MarkerAnnotation
#define CMSG_SYM_EXEC_MARKERANNOTATION_ENTER    common::WriteMsg::mlDDebug, "=> entering expr::MarkerAnnotation visitor: %d\n"
#define CMSG_SYM_EXEC_MARKERANNOTATION_LEAVE    common::WriteMsg::mlDDebug, "<= leaving  expr::MarkerAnnotation visitor: %d\n"

// visitor NormalAnnotation
#define CMSG_SYM_EXEC_NORMALANNOTATION_ENTER    common::WriteMsg::mlDDebug, "=> entering expr::NormalAnnotation visitor: %d\n"
#define CMSG_SYM_EXEC_NORMALANNOTATION_LEAVE    common::WriteMsg::mlDDebug, "<= leaving  expr::NormalAnnotation visitor: %d\n"

// visitor Block
#define CMSG_SYM_EXEC_BLOCK_ENTER               common::WriteMsg::mlDDebug, "=> entering statm::Block visitor: %d\n"
#define CMSG_SYM_EXEC_BLOCK_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  statm::Block visitor: %d\n"

// visitor Assert
#define CMSG_SYM_EXEC_ASSERT_ENTER              common::WriteMsg::mlDDebug, "=> entering statm::Assert visitor: %d\n"
#define CMSG_SYM_EXEC_ASSERT_LEAVE              common::WriteMsg::mlDDebug, "<= leaving  statm::Assert visitor: %d\n"

// visitor Class
#define CMSG_SYM_EXEC_CLASS_ENTER               common::WriteMsg::mlDDebug, "=> entering struc::Class visitor: %d\n"
#define CMSG_SYM_EXEC_CLASS_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  struc::Class visitor: %d\n"

// visitor Enum
#define CMSG_SYM_EXEC_ENUM_ENTER                common::WriteMsg::mlDDebug, "=> entering struc::Enum visitor: %d\n"
#define CMSG_SYM_EXEC_ENUM_LEAVE                common::WriteMsg::mlDDebug, "<= leaving  struc::Enum visitor: %d\n"

// visitor MethodGeneric
#define CMSG_SYM_EXEC_METHOD_GENERIC_ENTER      common::WriteMsg::mlDDebug, "=> entering struc::MethodGeneric visitor: %d\n"
#define CMSG_SYM_EXEC_METHOD_GENERIC_LEAVE      common::WriteMsg::mlDDebug, "<= leaving  struc::MethodGeneric visitor: %d\n"

// visitor Empty
#define CMSG_SYM_EXEC_EMPTY_ENTER               common::WriteMsg::mlDDebug, "=> entering statm::Empty visitor: %d\n"
#define CMSG_SYM_EXEC_EMPTY_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  statm::Empty visitor: %d\n"


// StateJava.cpp
#define CMSG_SYM_STATEJAVA_ADD_NEW_HEAPOBJECT   common::WriteMsg::mlDDebug, "  Add new heap object for %s\n"
#define CMSG_SYM_STATEJAVA_GET_HEAPOBJECT       common::WriteMsg::mlDDebug, "  Get heap object for %s\n"
#define CMSG_SYM_STATEJAVA_HAS_HEAPOBJECT       common::WriteMsg::mlDDebug, "  %s has heap object: %d\n"


// StateFactoryJava.cpp
#define CMSG_SYM_STATEJAVA_FACTORY_CREATESTATE1_ENTER     common::WriteMsg::mlDDebug, "  => entering createState (BasicBlock: %d, currentMethod: %d)\n"
#define CMSG_SYM_STATEJAVA_FACTORY_CREATESTATE1_LEAVE     common::WriteMsg::mlDDebug, "  <= leaving  createState (BasicBlock: %d, currentMethod: %d)\n"
#define CMSG_SYM_STATEJAVA_FACTORY_CREATESTATE_RESULT     common::WriteMsg::mlDDebug, "    createState result: newState: %d, state: %s\n"
#define CMSG_SYM_STATEJAVA_FACTORY_CREATESTATE2_ENTER     common::WriteMsg::mlDDebug, "  => entering createState (BasicBlock: %d, parent state: %s)\n"
#define CMSG_SYM_STATEJAVA_FACTORY_CREATESTATE2_LEAVE     common::WriteMsg::mlDDebug, "  <= leaving  createState (BasicBlock: %d, parent state: %s)\n"


// JavaSymbolicCommon.cpp
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_PARAM_IS_NULL       common::WriteMsg::mlError, "    getDefaultInitializedValueDefinition(): Type parameter is NULL!\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_NULL                common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of null (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_BYTE                common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of byte (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_SHORT               common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of short (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_CHAR                common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of char (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_INT                 common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of int (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_LONG                common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of long (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_FLOAT               common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of float (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_DOUBLE              common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of double (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_BOOLEAN             common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of boolean (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_ARRAY               common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of Array (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_CLASS               common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of Class (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_CLASS_STRING        common::WriteMsg::mlDDebug, "    ClassType is String (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_TYPEAPPLY           common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of typeApply (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_PARAMETRIZED        common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of parametrized (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_VARAIBLE            common::WriteMsg::mlDDebug, "    getDefaultInitializedValueDefinition(): Type parameter is type of typeVariable (%d)\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_ERROR               common::WriteMsg::mlWarning, "    getDefaultInitializedValueDefinition(): Type parameter is type of Error (%d)!\n"
#define CMSG_SYM_SYMBOLIC_COMMON_TYPE_UNKNOWN             common::WriteMsg::mlWarning, "    getDefaultInitializedValueDefinition(): Type parameter is UNKNOWN (%d)!\n"

// Constraint builder = CB
#define CMSG_SYM_CONST_CREATING_VALUE_EXPR                 common::WriteMsg::mlDebug,   " <CB>    creating CS value for NodeId: %d, strRep: %s \n"
#define CMSG_SYM_CONST_CREATING_VAR_EXPR                   common::WriteMsg::mlDebug,   " <CB>    creating CS variable for NodeId: %d, strRep: %s \n"
#define CMSG_SYM_CONST_CREATING_EXPR                       common::WriteMsg::mlDebug,   " <CB>    creating CS expression for NodeId: %d, strRep: %s \n"
#define CMSG_SYM_CONST_CREATING_CONSTRAINT                 common::WriteMsg::mlDebug,   " <CB>    creating constraint for NodeId: %d\n"
#define CMSG_SYM_CONST_CREATED_CONSTRAINT                  common::WriteMsg::mlDebug,   " <CB>  created constraint: %s\n"
#define CMSG_SYM_CONST_PC_SOLVED                           common::WriteMsg::mlDebug,   " <CB> Path Condition solved\n"
#define CMSG_SYM_CONST_PC_NOT_SOLVED                       common::WriteMsg::mlDebug,   " <CB> Path Condition not solved\n"
#define CMSG_SYM_CONST_PC_BUILT                            common::WriteMsg::mlDebug,   " <CB> Path Condition in state %d: %s\n"
#define CMSG_SYM_CONST_PC_DECOMPOSED                       common::WriteMsg::mlDebug,   " <CB> Path Condition decomposed in state %d: %s\n"
#define CMSG_SYM_CONST_CANNOT_BUID_ACTUAL_CONSTRAINTS      common::WriteMsg::mlDebug,   " <CB>  Cannot build actual constraints in state %d: %s\n"
#define CMSG_SYM_CONST_ACTUAL_CONSTRAINTS_BULT             common::WriteMsg::mlDebug,   " <CB>  Actual constraints succesfully built in state %d: %s\n"
#define CMSG_SYM_CONST_CANNOT_BUILD_DEFINITION             common::WriteMsg::mlDebug,   " <CB> Cannot build definition: %s (%s)\n"
#define CMSG_SYM_CONST_DEFINITION_BUILT_BACK               common::WriteMsg::mlDebug,   " <CB> ValueDefinition has built back to proxy tree (%s)\n"
#define CMSG_SYM_CONST_DEFINITION_BUILT_BACK               common::WriteMsg::mlDebug,   " <CB> ValueDefinition has built back to proxy tree (%s)\n"
#define CMSG_SYM_CONST_LATEST_SYMBOL_NOT_FOUND             common::WriteMsg::mlDDDebug, " <CB>      Symbol not found in latestSymbols: %s \n"
#define CMSG_SYM_CONST_CREATING_BOOL_EXPRESSION            common::WriteMsg::mlWarning,   " <CB>   cretaing bool expression failed\n"



// SymbolicTypesPreVisitor.cpp
// visitor ArrayType
#define CMSG_SYM_PREVISIT_ARRAYTYPE_ENTER         common::WriteMsg::mlDDebug, "=> entering type::ArrayType visitor: %d\n"
#define CMSG_SYM_PREVISIT_ARRAYTYPE_INSERTED      common::WriteMsg::mlDDebug, "   Inserted ArrayType (typeId: %d) with componentTypeId: %d\n"
#define CMSG_SYM_PREVISIT_ARRAYTYPE_LEAVE         common::WriteMsg::mlDDebug, "<= leaving  type::ArrayType visitor: %d\n"

// visitor ClassType
#define CMSG_SYM_PREVISIT_CLASSTYPE_ENTER         common::WriteMsg::mlDDebug, "=> entering type::ClassType visitor: %d\n"
#define CMSG_SYM_PREVISIT_CLASSTYPE_INSERTED      common::WriteMsg::mlDDebug, "   Inserted ClassType (typeId: %d) with refersToId: %d\n"
#define CMSG_SYM_PREVISIT_CLASSTYPE_LEAVE         common::WriteMsg::mlDDebug, "<= leaving  type::ClassType visitor: %d\n"

// visitor MethodType
#define CMSG_SYM_PREVISIT_METHODTYPE_ENTER        common::WriteMsg::mlDDebug, "=> entering type::MethodType visitor: %d\n"
#define CMSG_SYM_PREVISIT_METHODTYPE_INSERTED     common::WriteMsg::mlDDebug, "   Inserted MethodType (typeId: %d) with returnTypeId: %d\n"
#define CMSG_SYM_PREVISIT_METHODTYPE_INSERTED_PAR common::WriteMsg::mlDDebug, "   Inserted MethodType (typeId: %d) with parameterTypeIds: %s\n"
#define CMSG_SYM_PREVISIT_METHODTYPE_INSERTED_THR common::WriteMsg::mlDDebug, "   Inserted MethodType (typeId: %d) with thrownTypeIds: %s\n"
#define CMSG_SYM_PREVISIT_METHODTYPE_LEAVE        common::WriteMsg::mlDDebug, "<= leaving  type::MethodType visitor: %d\n"

// visitor ParameterizedType
#define CMSG_SYM_PREVISIT_PARAMTYPE_ENTER         common::WriteMsg::mlDDebug, "=> entering type::ParameterizedType visitor: %d\n"
#define CMSG_SYM_PREVISIT_PARAMTYPE_INSERTED      common::WriteMsg::mlDDebug, "   Inserted ParameterizedType (typeId: %d) with rawTypeId: %d\n"
#define CMSG_SYM_PREVISIT_PARAMTYPE_INSERTED_ARG  common::WriteMsg::mlDDebug, "   Inserted ParameterizedType (typeId: %d) with argumentTypeIds: %s\n"
#define CMSG_SYM_PREVISIT_PARAMTYPE_LEAVE         common::WriteMsg::mlDDebug, "<= leaving  type::ParameterizedType visitor: %d\n"

// visitor TypeVariable
#define CMSG_SYM_PREVISIT_TYPEVARIABLE_ENTER      common::WriteMsg::mlDDebug, "=> entering type::TypeVariable visitor: %d\n"
#define CMSG_SYM_PREVISIT_TYPEVARIABLE_INSERTED   common::WriteMsg::mlDDebug, "   Inserted TypeVariable (typeId: %d) with refersToId: %d\n"
#define CMSG_SYM_PREVISIT_PARAMTYPE_INSERTED_TP   common::WriteMsg::mlDDebug, "   Inserted TypeVariable (typeId: %d) with boundTypeIDs: %s\n"
#define CMSG_SYM_PREVISIT_TYPEVARIABLE_LEAVE      common::WriteMsg::mlDDebug, "<= leaving  type::TypeVariable visitor: %d\n"

// visitor UnboundedWildcardType
#define CMSG_SYM_PREVISIT_UNBOUND_ENTER           common::WriteMsg::mlDDebug, "=> entering type::UnboundedWildcardType visitor: %d\n"
#define CMSG_SYM_PREVISIT_UNBOUND_INSERTED        common::WriteMsg::mlDDebug, "   Inserted UnboundedWildcardType (typeId: %d) with boundTypeId: %d\n"
#define CMSG_SYM_PREVISIT_UNBOUND_LEAVE           common::WriteMsg::mlDDebug, "<= leaving  type::UnboundedWildcardType visitor: %d\n"

// visitor UpperBoundedWildcardType
#define CMSG_SYM_PREVISIT_UPPERBOUND_ENTER        common::WriteMsg::mlDDebug, "=> entering type::UpperBoundedWildcardType visitor: %d\n"
#define CMSG_SYM_PREVISIT_UPPERBOUND_INSERTED     common::WriteMsg::mlDDebug, "   Inserted UpperBoundedWildcardType (typeId: %d) with boundTypeId: %d\n"
#define CMSG_SYM_PREVISIT_UPPERBOUND_LEAVE        common::WriteMsg::mlDDebug, "<= leaving  type::UpperBoundedWildcardType visitor: %d\n"

// visitor LowerBoundedWildcardType
#define CMSG_SYM_PREVISIT_LOWERBOUND_ENTER        common::WriteMsg::mlDDebug, "=> entering type::LowerBoundedWildcardType visitor: %d\n"
#define CMSG_SYM_PREVISIT_LOWERBOUND_INSERTED     common::WriteMsg::mlDDebug, "   Inserted LowerBoundedWildcardType (typeId: %d) with boundTypeId: %d\n"
#define CMSG_SYM_PREVISIT_LOWERBOUND_LEAVE        common::WriteMsg::mlDDebug, "<= leaving  type::LowerBoundedWildcardType visitor: %d\n"

// visitor Method and MethodGeneric
#define CMSG_SYM_PREVISIT_METHOD_ENTER            common::WriteMsg::mlDDebug, "=> entering struc::Method visitor: %d\n"
#define CMSG_SYM_PREVISIT_METHOD_FILTERED         common::WriteMsg::mlDDebug, "   Method is filtered out\n"
#define CMSG_SYM_PREVISIT_METHOD_NOT_NORMAL       common::WriteMsg::mlDDebug, "   Method is not a NormalMethod (type is: %s)\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_CLASS        common::WriteMsg::mlDDebug, "   Method is a Class member (classId: %d)\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_CLASSG       common::WriteMsg::mlDDebug, "   Method is a ClassGeneric member (classId: %d)\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_INTERF       common::WriteMsg::mlDDebug, "   Method is an Interface member (interfaceId: %d)\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_INTERFG      common::WriteMsg::mlDDebug, "   Method is an InterfaceGeneric member (interfaceId: %d)\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_ANON         common::WriteMsg::mlDDebug, "   Method is an AnonymousClass member (interfaceId: %d)\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_ENUM         common::WriteMsg::mlDDebug, "   Method is an Enum member (interfaceId: %d)\n"
#define CMSG_SYM_PREVISIT_METHOD_TYPEID           common::WriteMsg::mlDDebug, "   Method's typeId: %d\n"
#define CMSG_SYM_PREVISIT_METHOD_RET_TYPE         common::WriteMsg::mlDDebug, "   Method's returnTypeId: %d\n"
#define CMSG_SYM_PREVISIT_METHOD_OVERED_METH      common::WriteMsg::mlDDebug, "   Method's overrides methodIDs: %s\n"
#define CMSG_SYM_PREVISIT_METHOD_PARAMS           common::WriteMsg::mlDDebug, "   Method's parameterTypeIDs: %s\n"
#define CMSG_SYM_PREVISIT_METHOD_THROWN_TYPES     common::WriteMsg::mlDDebug, "   Method's thrownTypeIDs: %s\n"
#define CMSG_SYM_PREVISIT_METHOD_TYPE_PARS        common::WriteMsg::mlDDebug, "   Method's typeParameterIDs: %s\n"
#define CMSG_SYM_PREVISIT_METHOD_PAR_UNHANDLED    common::WriteMsg::mlWarning, "   Method belongs to an UNHANDLED parent (parentId: %d, parentType: %s)\n"
#define CMSG_SYM_PREVISIT_METHOD_LEAVE            common::WriteMsg::mlDDebug, "<= leaving  struc::Method visitor: %d\n"
#define CMSG_SYM_PREVISIT_METHODG_ENTER           common::WriteMsg::mlDDebug, "=> entering struc::MethodGeneric visitor: %d\n"
#define CMSG_SYM_PREVISIT_METHODG_LEAVE           common::WriteMsg::mlDDebug, "<= leaving  struc::MethodGeneric visitor: %d\n"

// visitor Variable
#define CMSG_SYM_PREVISIT_VAR_ENTER               common::WriteMsg::mlDDebug, "=> entering struc::Variable visitor: %d\n"
#define CMSG_SYM_PREVISIT_VAR_FLOAT_NEG_INF       common::WriteMsg::mlDDebug, "   Float Negative Infinity nodeId: %d\n"
#define CMSG_SYM_PREVISIT_VAR_FLOAT_POS_INF       common::WriteMsg::mlDDebug, "   Float Positive Infinity nodeId: %d\n"
#define CMSG_SYM_PREVISIT_VAR_DOUBLE_NEG_INF      common::WriteMsg::mlDDebug, "   Double Negative Infinity nodeId: %d\n"
#define CMSG_SYM_PREVISIT_VAR_DOUBLE_POS_INF      common::WriteMsg::mlDDebug, "   Double Positive Infinity nodeId: %d\n"
#define CMSG_SYM_PREVISIT_VAR_FLOAT_NAN           common::WriteMsg::mlDDebug, "   Float NaN nodeId: %d\n"
#define CMSG_SYM_PREVISIT_VAR_DOUBLE_NAN          common::WriteMsg::mlDDebug, "   Double NaN nodeId: %d\n"
#define CMSG_SYM_PREVISIT_VAR_LEAVE               common::WriteMsg::mlDDebug, "<= leaving  struc::Variable visitor: %d\n"

// visitor Class
#define CMSG_SYM_PREVISIT_CLASS_ENTER             common::WriteMsg::mlDDebug, "=> entering struc::Class visitor: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_OBJECT_CLASS      common::WriteMsg::mlDDebug, "   Object classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_FLOAT_CLASS       common::WriteMsg::mlDDebug, "   Float classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_DOUBLE_CLASS      common::WriteMsg::mlDDebug, "   Double classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_INTEGER_CLASS     common::WriteMsg::mlDDebug, "   Integer classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_BOOLEAN_CLASS     common::WriteMsg::mlDDebug, "   Boolean classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_STRING_CLASS      common::WriteMsg::mlDDebug, "   String classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_BYTE_CLASS        common::WriteMsg::mlDDebug, "   Byte classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_SHORT_CLASS       common::WriteMsg::mlDDebug, "   Short classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_LONG_CLASS        common::WriteMsg::mlDDebug, "   Long classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_CHARACTER_CLASS   common::WriteMsg::mlDDebug, "   Character classId: %d\n"
#define CMSG_SYM_PREVISIT_CLASS_LEAVE             common::WriteMsg::mlDDebug, "<= leaving  struc::Class visitor: %d\n"

// visitor ClassGeneric
#define CMSG_SYM_PREVISIT_CLASSG_ENTER            common::WriteMsg::mlDDebug, "=> entering struc::ClassGeneric visitor: %d\n"
#define CMSG_SYM_PREVISIT_CLASSG_LEAVE            common::WriteMsg::mlDDebug, "<= leaving  struc::ClassGeneric visitor: %d\n"

// visitor Interface
#define CMSG_SYM_PREVISIT_INTERF_ENTER            common::WriteMsg::mlDDebug, "=> entering struc::Interface visitor: %d\n"
#define CMSG_SYM_PREVISIT_INTERF_LEAVE            common::WriteMsg::mlDDebug, "<= leaving  struc::Interface visitor: %d\n"

// visitor InterfaceGeneric
#define CMSG_SYM_PREVISIT_INTERFG_ENTER           common::WriteMsg::mlDDebug, "=> entering struc::InterfaceGeneric visitor: %d\n"
#define CMSG_SYM_PREVISIT_INTERFG_LEAVE           common::WriteMsg::mlDDebug, "<= leaving  struc::InterfaceGeneric visitor: %d\n"

// visitor AnonymousClass
#define CMSG_SYM_PREVISIT_ANONC_ENTER             common::WriteMsg::mlDDebug, "=> entering struc::AnonymousClass visitor: %d\n"
#define CMSG_SYM_PREVISIT_ANONC_LEAVE             common::WriteMsg::mlDDebug, "<= leaving  struc::AnonymousClass visitor: %d\n"

// instanceOf
#define CMSG_SYM_PREVISIT_INOF_UNHANDLED          common::WriteMsg::mlDDebug, "   Unhandled typeIds (source: %d, target: %d)\n"

// common
#define CMSG_SYM_PREVISIT_COMMON_SC               common::WriteMsg::mlDDebug, "   Stored SuperClass (superClassTypeId: %d, classId: %d)\n"
#define CMSG_SYM_PREVISIT_COMMON_SI               common::WriteMsg::mlDDebug, "   Stored SuperInterfaces (superInterfaceTypeIDs: %s, classId: %d)\n"
#define CMSG_SYM_PREVISIT_COMMON_TP               common::WriteMsg::mlDDebug, "   Stored TypeParameters (typeParameterIDs: %s, classId: %d)\n"
#define CMSG_SYM_PREVISIT_COMMON_METHOD_CL        common::WriteMsg::mlDDebug, "   Stored methods (methodIDs: %s, classId: %d)\n"
#define CMSG_SYM_PREVISIT_COMMON_MET_NOT_NORMAL   common::WriteMsg::mlDDebug, "   Method is not a NormalMethod (methodId: %d, type is: %s)\n"
#define CMSG_SYM_PREVISIT_COMMON_MET_OVRS         common::WriteMsg::mlDDebug, "   Method (methodId: %d) overrided by methodIDs: %s\n"


// CsvStateListener.cpp
#define CMSG_SYM_STACK_TRACE_UNHANDLED_LEADER           common::WriteMsg::mlWarning, "  Unhandled leader node kind (%s), nodeId: %d\n"
#define CMSG_SYM_STACK_TRACE_FILTERED_IDENTIFIER        common::WriteMsg::mlWarning, "  Filtered Identifier (ID nodeId: %d)\n"
#define CMSG_SYM_STACK_TRACE_FILTERED_MI                common::WriteMsg::mlWarning, "  Filtered MethodInvocation's invokes (MI nodeId: %d)\n"
#define CMSG_SYM_STACK_TRACE_FILTERED_ASS_LEFT_TYPE     common::WriteMsg::mlWarning, "  Filtered Assignment's left operand's type (left operandId: %d)\n"
#define CMSG_SYM_STACK_TRACE_FILTERED_TC_TYPE_OP        common::WriteMsg::mlWarning, "  Filtered TypeCast's type operand (type operandId: %d)\n"
#define CMSG_SYM_STACK_TRACE_FILTERED_PAR_TYPE_OP       common::WriteMsg::mlWarning, "  Filtered Parameter's type operand (type operandId: %d)\n"

#endif