#ifndef _SYM_MSG_H_
#define _SYM_MSG_H_

// State.cpp
#define CMSG_SYM_STATE_PUSH_DEFINITION                      common::WriteMsg::mlDDebug, "  \nPush definition on the stack (current stack size: %d, stateId: %d)\n"
#define CMSG_SYM_STATE_POP_DEFINITION                       common::WriteMsg::mlDDebug, "  \nPop definition from the stack (current stack size: %d, stateId: %d)\n"
#define CMSG_SYM_STATE_STACK_CONTENT                        common::WriteMsg::mlDDebug, "     %s\n"
#define CMSG_SYM_STATE_DEFINITION_HASLVALUE                 common::WriteMsg::mlDDebug, "   %s has%s lValue\n"
#define CMSG_SYM_STATE_GET_THIZ_OBJECT                      common::WriteMsg::mlDDebug, "   getThizObject(): %s\n"
#define CMSG_SYM_STATE_SET_THIZ_OBJECT                      common::WriteMsg::mlDDebug, "   setThizObject(): %s\n"
#define CMSG_SYM_STATE_UNREACHABLE                          common::WriteMsg::mlDDebug, "   Unreachable state: %s\n"
#define CMSG_SYM_STATE_FIRE_NPE                             common::WriteMsg::mlDDebug, "   NPE at nodeId: %d\n"
#define CMSG_SYM_STATE_FIRE_NPE_ENABLED                     common::WriteMsg::mlDDebug, "   NPE checker is enabled\n"
#define CMSG_SYM_STATE_FIRE_NPE_DISABLED                    common::WriteMsg::mlDDebug, "   NPE checker is disabled\n"
#define CMSG_SYM_STATE_FIRE_INFINITE                        common::WriteMsg::mlDDebug, "   INFINITE LOOP at nodeId: %d\n"
#define CMSG_SYM_STATE_FIRE_INFINITE_ENABLED                common::WriteMsg::mlDDebug, "   INFINITE LOOP checker is enabled\n"
#define CMSG_SYM_STATE_FIRE_INFINITE_DISABLED               common::WriteMsg::mlDDebug, "   INFINITE LOOP checker is disabled\n"
#define CMSG_SYM_STATE_FIRE_CCE                             common::WriteMsg::mlDDebug, "   CCE at nodeId: %d\n"
#define CMSG_SYM_STATE_FIRE_CCE_ENABLED                     common::WriteMsg::mlDDebug, "   CCE checker is enabled\n"
#define CMSG_SYM_STATE_FIRE_CCE_DISABLED                    common::WriteMsg::mlDDebug, "   CCE checker is disabled\n"
#define CMSG_SYM_STATE_FIRE_DIV_BY_ZERO                     common::WriteMsg::mlDDebug, "   DBZ at nodeId: %d\n"
#define CMSG_SYM_STATE_FIRE_DIV_BY_ZERO_ENABLED             common::WriteMsg::mlDDebug, "   DBZ checker is enabled\n"
#define CMSG_SYM_STATE_FIRE_DIV_BY_ZERO_DISABLED            common::WriteMsg::mlDDebug, "   DBZ checker is disabled\n"
#define CMSG_SYM_STATE_FIRE_IND_OUT_BOUNDS                  common::WriteMsg::mlDDebug, "   IOB at nodeId: %d (arrayLength: %d, index: %d)\n"
#define CMSG_SYM_STATE_FIRE_IND_OUT_BOUNDS_ENABLED          common::WriteMsg::mlDDebug, "   IOB checker is enabled\n"
#define CMSG_SYM_STATE_FIRE_IND_OUT_BOUNDS_DISABLED         common::WriteMsg::mlDDebug, "   IOB checker is disabled\n"
#define CMSG_SYM_STATE_FIRE_NEG_ARR_SIZE                    common::WriteMsg::mlDDebug, "   NAS at nodeId: %d (arrayLenght: %d)\n"
#define CMSG_SYM_STATE_FIRE_NEG_ARR_SIZE_ENABLED            common::WriteMsg::mlDDebug, "   NAS checker is enabled\n"
#define CMSG_SYM_STATE_FIRE_NEG_ARR_SIZE_DISABLED           common::WriteMsg::mlDDebug, "   NAS checker is disabled\n"
#define CMSG_SYM_STATE_FIRE_DEF_PUSH                        common::WriteMsg::mlDDebug, "   Definition push\n"
#define CMSG_SYM_STATE_FIRE_DEF_POP                         common::WriteMsg::mlDDebug, "   Definition pop\n"
#define CMSG_SYM_STATE_FIRE_USE_STATIC                      common::WriteMsg::mlDDebug, "   Using static variable (nodeId: %d)\n"


// SymbolicEngine.cpp
// run
#define CMSG_SYM_ENGINE_RUN_ENTER                           common::WriteMsg::mlDDebug, "\n=> entering SymbolicEngine::run (methodId: %d)\n"
#define CMSG_SYM_ENGINE_RUN_LEAVE                           common::WriteMsg::mlDDebug, "\n<= leaving  SymbolicEngine::run (methodId: %d)\n"
#define CMSG_SYM_ENGINE_RUN_ENTER2                          common::WriteMsg::mlDDebug, "=> STATIC INIT entering SymbolicEngine::run (methodId: %d)\n"
#define CMSG_SYM_ENGINE_RUN_LEAVE2                          common::WriteMsg::mlDDebug, "<= STATIC INIT leaving  SymbolicEngine::run (methodId: %d)\n"
#define CMSG_SYM_ENGINE_RUN_COULD_NOT_INITIALIZE            common::WriteMsg::mlDDebug, "  Could not initialize method\n"
#define CMSG_SYM_EXEC_START_EXECUTOR_INITING                common::WriteMsg::mlDDebug, "  Static ICFG is under initialization\n"
#define CMSG_SYM_ENGINE_RUN_STATIC_INITIALIZED_BEFORE       common::WriteMsg::mlDDebug, "  Static block initialized before\n"

// search
#define CMSG_SYM_ENGINE_SEARCH_STATENR                      common::WriteMsg::mlDDebug, "  Current state: %d, max state: %d\n"

// makeCall
#define CMSG_SYM_ENGINE_MAKECALL_ENTER                      common::WriteMsg::mlDDebug, "  => entering SymbolicEngine::makeCall (callerState: %s, calledState: %s, callType: %d)\n"
#define CMSG_SYM_ENGINE_MAKECALL_LEAVE                      common::WriteMsg::mlDDebug, "  <= leaving  SymbolicEngine::makeCall (callerState: %s, calledState: %s, callType: %d)\n"

// makeCallReturn
#define CMSG_SYM_ENGINE_MAKECALL_RETURN_ENTER               common::WriteMsg::mlDDebug, "  => entering SymbolicEngine::makeCallReturn (callerState: %s, calledState: %s)\n"
#define CMSG_SYM_ENGINE_MAKECALL_RETURN_LEAVE               common::WriteMsg::mlDDebug, "  <= leaving  SymbolicEngine::makeCallReturn (callerState: %s, calledState: %s)\n"

// executeState
#define CMSG_SYM_ENGINE_EXEC_STATE_ENTER                    common::WriteMsg::mlDDebug, "  => entering SymbolicEngine::executeState (state: %s)\n"
#define CMSG_SYM_ENGINE_EXEC_STATE_LEAVE                    common::WriteMsg::mlDDebug, "  <= leaving  SymbolicEngine::executeState (state: %s)\n"
#define CMSG_SYM_ENGINE_EXEC_BB                             common::WriteMsg::mlDDebug, "    BB id: %d, nodes in BB: %d\n"
#define CMSG_SYM_ENGINE_EXEC_NEXT_NODEID                    common::WriteMsg::mlDDebug, "    SymbolicEngine::executeState() next nodeId: %d\n"
#define CMSG_SYM_ENGINE_EXEC_SKIP_NODE                      common::WriteMsg::mlDDebug, "    Skipping nodeId %d (to %d), because expression won't be evaluate\n"
#define CMSG_SYM_ENGINE_EXEC_STATEMENT_BORDER               common::WriteMsg::mlDDebug, "    Statement border, empty the stack\n"

// expandState
#define CMSG_SYM_ENGINE_EXPAND_STATE_ENTER                           common::WriteMsg::mlDDebug, "\n  => entering SymbolicEngine::expandState (state: %s, BB id: %d)\n"
#define CMSG_SYM_ENGINE_EXPAND_STATE_LEAVE                           common::WriteMsg::mlDDebug, "  <= leaving  SymbolicEngine::expandState (state: %s)\n\n"
#define CMSG_SYM_ENGINE_EXPAND_DEPTH                                 common::WriteMsg::mlDDebug, "    Current state depth: %d, max state depth: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_RETURN                                common::WriteMsg::mlDDebug, "    returning state: %s\n"
#define CMSG_SYM_ENGINE_EXPAND_IS_EXCEPTIONAL                        common::WriteMsg::mlDDebug, "    An Exception was occoured\n"
#define CMSG_SYM_ENGINE_EXPAND_BB_EXIT                               common::WriteMsg::mlDDebug, "    BB is EXIT\n"
#define CMSG_SYM_ENGINE_EXPAND_NEW_STATE                             common::WriteMsg::mlDDebug, "    We have a new state\n"
#define CMSG_SYM_ENGINE_EXPAND_RESTORING_ORIGINAL                    common::WriteMsg::mlDDebug, "    Restoring original context\n"
#define CMSG_SYM_ENGINE_EXPAND_CALLERSTATE_NULL                      common::WriteMsg::mlDDebug, "    CallerState is NULL\n"
#define CMSG_SYM_ENGINE_EXPAND_CONTROL_OUT_EDGE                      common::WriteMsg::mlDDebug, "    Control out edge from BB: %d to BB: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_NO_CONTROL_OUT_EDGE                   common::WriteMsg::mlDDebug, "    Returning from a call, but no control out edge exists\n"
#define CMSG_SYM_ENGINE_EXPAND_SKIP_CALL                             common::WriteMsg::mlDDebug, "    Skipping call, because expression won't be evaluate\n"
#define CMSG_SYM_ENGINE_EXPAND_SKIP_STATIC_CALL                      common::WriteMsg::mlDDebug, "    Skipping static initializer, because it has already initialized (methodId: %d)\n"
#define CMSG_SYM_ENGINE_EXPAND_CALL_OUT_EDGE                         common::WriteMsg::mlDDebug, "    Call out edge from BB: %d to BB: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_CALL_OUT_EDGE_NOT_EXIT                common::WriteMsg::mlDDebug, "    Call out edge from is not EXIT, we have a call\n"
#define CMSG_SYM_ENGINE_EXPAND_CALL_OUT_EDGE_TO_NOT_ENTRY            common::WriteMsg::mlDDebug, "    Call out edge to is not ENTRY\n"
#define CMSG_SYM_ENGINE_EXPAND_CALL_OUT_EDGE_WITHOUT_CONTROL_EDGE    common::WriteMsg::mlDDebug, "    Call out edge without control edge\n"
#define CMSG_SYM_ENGINE_EXPAND_BB_EMPTY                              common::WriteMsg::mlDDebug, "    BB %d has not any nodes in the container\n"
#define CMSG_SYM_ENGINE_EXPAND_STACK_IS_EMPTY                        common::WriteMsg::mlDDebug, "    State's stack is empty: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_CONTROL_OUT_EDGES_NUMBER              common::WriteMsg::mlDDebug, "    Number of control out edges: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_LAST_DEFINITION                       common::WriteMsg::mlDDebug, "    Last definition: %s\n"
#define CMSG_SYM_ENGINE_EXPAND_BOOLEAN_VALUE                         common::WriteMsg::mlDDebug, "    BooleanDefinition value: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_SYMBOL_VALUE                          common::WriteMsg::mlDDebug, "    SymbolDefinition value: %d\n"
#define CMSG_SYM_ENGINE_EXPAND_DIRECT_CONTROL_FLOW                   common::WriteMsg::mlDDebug, "    Direct control flow\n"
#define CMSG_SYM_ENGINE_EXPAND_SWITCH                                common::WriteMsg::mlDDebug, "    Switch control\n"
#define CMSG_SYM_ENGINE_EXPAND_LAST_DEF_IS_INTEGRAL                  common::WriteMsg::mlDDebug, "    Last definition is IntegralValueDefiniton\n"
#define CMSG_SYM_ENGINE_EXPAND_LAST_DEF_IS_SYMBOL                    common::WriteMsg::mlDDebug, "    Last definition is SymbolValueDefinition\n"
#define CMSG_SYM_ENGINE_EXPAND_LAST_DEF_IS_ENUM_CONSTANT             common::WriteMsg::mlDDebug, "    Last definition is EnumConstantValueDefiniton\n"
#define CMSG_SYM_ENGINE_EXPAND_EXPECTED_SWITCH_LABEL                 common::WriteMsg::mlDDebug, "    Expected switch label: %s (current label: %s)\n"
#define CMSG_SYM_ENGINE_EXPAND_SWITCH_DEFAULT                        common::WriteMsg::mlDDebug, "    Default switch case\n"


// StateListener
#define CMSG_SYM_STACK_TRACE_CHECK_FOR_REPEAT                        common::WriteMsg::mlDDebug, "  Check for repeating...\n"
#define CMSG_SYM_STACK_TRACE_PRINTOUT                                common::WriteMsg::mlDDebug, "  Printing out the stack trace...\n"

#endif