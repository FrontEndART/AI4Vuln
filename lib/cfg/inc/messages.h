#ifndef _CFG_MESSAGE_H
#define _CFG_MESSAGE_H

//Common messages
#define CMSG_PRINT_DEBUG_MSG            common::WriteMsg::mlDDebug, "%s\n"

//CFGFactory messages
#define CMSG_MISSING_DU_INFO            common::WriteMsg::mlDDebug, "    There is no DUInfo for node %d!\n"
#define CMSG_INVALID_NODEID             common::WriteMsg::mlDDebug, "    Invalid nodeId %d!\n"
#define CMSG_DUINFO_SIZE                common::WriteMsg::mlDDebug, "DUInfos: size "
#define CMSG_ICFG_NOT_FOUND             common::WriteMsg::mlError,  "No ICFG exist, with this method ID! (id%d)\n"

//CFGGraphml2CFG messages
#define CMSG_GROUP_NOT_FOUND            common::WriteMsg::mlError,  "No existing source or target Group found with the given Id!\n"

//AlgorithmDefUseChains messages
#define CMSG_PRINT_FOUND_DEFINITION     common::WriteMsg::mlDDebug, "    -> Node %d defined by node %d found in CFG (in block %d, @depth %d)\n"
#define CMSG_BB_DEFINITION_SEARCH_START common::WriteMsg::mlDDebug, "Finding the definition in BasicBlock %d (ICFG: %d) started...\n"
#define CMSG_BB_DEFINITION_SEARCH_END   common::WriteMsg::mlDDebug, "Finding the definition in BasicBlock %d (ICFG: %d) finished\n"
#define CMSG_DUINFO_SEARCH_START        common::WriteMsg::mlDDebug, "Finding the definition for DUInfo %d started (@depth %d, maxdepth %d)\n"
#define CMSG_DUINFO_SEARCH_END          common::WriteMsg::mlDDebug, "Finding the definition for DUInfo %d finished (@depth %d)\n"
#define CMSG_NODE_NOT_FOUND             common::WriteMsg::mlDDebug, "    The node %d doesn't exist inside the CFG!\n"
#define CMSG_NO_DEFINITION_BEFORE_USE   common::WriteMsg::mlDDebug, "    The definition %d doesn't take place before the use %d in the CFG!\n"

//AlgorithmPathFinder messages
#define CMSG_APF_SEARCH                 common::WriteMsg::mlDebug, "Start search from node %d.\n"
#define CMSG_APF_PREFILTER_BEGIN        common::WriteMsg::mlDebug, "Prefiltering source %d\n"
#define CMSG_APF_PREFILTER_DONE         common::WriteMsg::mlDebug, "Prefiltering is done. (marked BB: %u, prefilter counter: %llu)\n"
#define CMSG_APF_CLOSE_PATH             common::WriteMsg::mlDebug, "Close path because of checking.\n"
#define CMSG_APF_FIND_TARGET            common::WriteMsg::mlDebug, "Find target node(%d) for source %d.\n"
#define CMSG_APF_PFTIMECHECK            common::WriteMsg::mlDebug, "(pf(0xFFFFF:%lf)"
#define CMSG_APF_TIMECHECK              common::WriteMsg::mlDebug, "(find(0x3FF:%lf)"


//CGFactory messages
#define CMSG_CREATE_NODE                common::WriteMsg::mlDDebug, "    There is no node with ID %d, creating it...\n"
#define CMSG_CREATE_CGNODE              common::WriteMsg::mlDDebug, "    There is no node with CG ID %d, creating it...\n"

//Edge messages
#define CMSG_OUT_EDGE_ERROR             common::WriteMsg::mlError,  "No outgoing edge allowed from exit block!\n"
#define CMSG_WRONG_EDGE_TYPE            common::WriteMsg::mlError,  "Wrong Edge type!\n"
#define CMSG_CG_DUMP_HEADER             common::WriteMsg::mlDDebug, "\nCG factory dump\nSize (Variable nodes): %d\n\n"

//Exceptions' messages
#define CMSG_EX_CANNOT_OPEN_FILE        "Can't open file! "
#define CMSG_EX_INVALID_NODEID          "Invalid NodeId"
#define CMSG_EX_INVALID_BLOCKID         "Invalid BlockId"

#endif
