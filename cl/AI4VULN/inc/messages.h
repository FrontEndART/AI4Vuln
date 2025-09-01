#ifndef _JAVA_SYMBOLIC_CHECKER_MESSAGES_H_
#define _JAVA_SYMBOLIC_CHECKER_MESSAGES_H_

// main.cpp
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_CFG_DUMP_BEGIN            common::WriteMsg::mlDDebug,  "Dumping CFG...\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_CFG_DUMP_END              common::WriteMsg::mlDDebug,  "Dumping CFG finished\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_STATE_TREE_DUMP_BEGIN     common::WriteMsg::mlDDebug,  "Dumping State tree...\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_STATE_TREE_DUMP_END       common::WriteMsg::mlDDebug,  "Dumping State tree finished\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_SYMBOLIC_EXECUTION        common::WriteMsg::mlNormal,  "SYMBOLIC EXECUTION STARTS for ICFG: %d (%d. ~ %3.2f%%)\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_SYMBOLIC_EXCEPTION        common::WriteMsg::mlWarning, "WARNING: a SymbolicColumbusException occoured: %s\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_COLUMBUS_EXCEPTION        common::WriteMsg::mlWarning, "WARNING: %s\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_FAIL                      common::WriteMsg::mlError,   "ERROR: Symbolic execution of ICFG %u failed.\n"
#define CMSG_STAT_PEAK_MEMORY_USAGE  common::WriteMsg::mlNormal,   "\tPeak memory usage  :%lu MByte\n"

#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_MISSING_INPUT_FILE        common::WriteMsg::mlError, "ERROR: No input file was given!\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_MISSING_OUTPUT_FILE       common::WriteMsg::mlError, "ERROR: No output file was given!\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_MISSING_LIM_FILE          common::WriteMsg::mlError, "ERROR: No lim file was given!\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_FAILED_TO_ADD_WARNING     common::WriteMsg::mlWarning, "WARNING: Unable to add warning for node (%u)!\n"
#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_ADD_WARNING     common::WriteMsg::mlNormal, "Added warning for node (%u)!\n"


#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_FREE_VERSION_MESSAGE      common::WriteMsg::mlNormal, "There is no valid license!\n"

#define CMSG_SYM_JAVA_SYMBOLIC_CHECKER_CANT_OPEN                 common::WriteMsg::mlError, "ERROR: Can not open file '%s' for writing!\n"
#endif
