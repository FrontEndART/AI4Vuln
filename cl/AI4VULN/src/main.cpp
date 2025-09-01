#define PROGRAM_NAME "AI4VULN"
#define EXECUTABLE_NAME PROGRAM_NAME

#include <string>
#include <iostream>

#include "MainCommon.h"
#include "common/inc/Arguments.h"
#include "common/inc/StringSup.h"
#include <common/inc/FileSup.h>
#include <common/inc/WriteMessage.h>
#include <common/inc/Stat.h>
#include "symbolic/inc/common.h"
#include <rulechecker/inc/Checker.h>


#include "../inc/messages.h"
#include "../inc/checker/JavaSymbolicChecker.h"
#include "../inc/rules/JavaSymbolicNPEChecker.h"
#include "../inc/rules/JavaSymbolicDBZChecker.h"
#include "../inc/rules/JavaSymbolicCCEChecker.h"
#include "../inc/rules/JavaSymbolicINFChecker.h"
#include "../inc/rules/JavaSymbolicIOBChecker.h"
#include "../inc/rules/JavaSymbolicNASChecker.h"

using namespace std;
using namespace columbus;
using namespace common;
using namespace columbus::symbolic;

string rulFileName = "AI4VULN.rul";
string limFileName;
string rulConfig = "Default";
string outputFileName;
string statFile;
string changepathfrom;
string changepathto;



static list<string> inputFileNames;     // the processed file list
bool   exportRul = false;

// callback functions for argument processing
static bool ppMaxState                                          ( const Option *o, char *argv[] )          { Configuration::getInstance()->setMaxState(str2int(argv[0]));      return true; }
static bool ppMaxDepth                                          ( const Option *o, char *argv[] )          { Configuration::getInstance()->setMaxDepth(str2int(argv[0]));      return true; }
static bool ppStateMatching                                     ( const Option *o, char *argv[] )          { Configuration::getInstance()->setStateMatching(true);             return true; }
static bool ppCFGDump                                           ( const Option *o, char *argv[] )          { Configuration::getInstance()->setDumpCfgGraphml(true);            return true; }
static bool ppSYMDump                                           ( const Option *o, char *argv[] )          { Configuration::getInstance()->setDumpStateTreeGraphml(true);      return true; }
static void ppFile                                              ( char *filename )                         { inputFileNames.push_back( filename );                                          }
static bool ppExportRul                                         ( const Option *o, char *argv[] )          { exportRul = true;                                                 return true; }
static bool ppRul                                               ( const common::Option *o, char *argv[] )  { rulFileName = argv[0];                                            return true; }
static bool ppRulConfig                                         ( const common::Option *o, char *argv[] )  { rulConfig = argv[0];                                              return true; }
static bool ppLimFile                                           ( const Option *o, char *argv[] )          { limFileName = argv[0];                                            return true; }
static bool ppList                                              ( const Option *o, char *argv[] )          { loadStringListFromFile(argv[0], inputFileNames);                  return true; }
static bool ppGraph                                             ( const Option *o, char *argv[] )          { outputFileName = argv[0];                                         return true; }
static bool ppOut                                               ( const Option *o, char *argv[] )          { Configuration::getInstance()->setOutTxtFile(argv[0]);             return true; }
static bool ppOutCsv                                            ( const Option *o, char *argv[] )          { Configuration::getInstance()->setOutCsvFile(argv[0]);             return true; }
static bool ppStat                                              ( const Option *o, char *argv[] )          { statFile = argv[0];                                               return true; }

static bool ppCsTimeLimit                                       ( const Option *o, char *argv[] )          {
    unsigned long timeLimit;
    if (str2unsignedlong(argv[0], timeLimit)) {
        Configuration::getInstance()->setCsTimeLimit(timeLimit);
        return true;
    } else {
        return false;
    }
}

static bool ppSearchStrategy                                    ( const Option *o, char *argv[] )          {
    Configuration::getInstance()->setSearchStrategy(string(argv[0]).compare("breadth-first") == 0 ? BREADTH_FIRST
                                                 : string(argv[0]).compare("depth-first") == 0 ? DEPTH_FIRST
                                                 : BREADTH_FIRST);
    return true;
}
static bool ppMethodFrom                                        ( const Option *o, char *argv[] )          { Configuration::getInstance()->setMethodFrom(str2int(argv[0]));       return true; }
static bool ppDisableCB                                         ( const Option *o, char *argv[] )          { Configuration::getInstance()->setDisableCB(true);                    return true; }
static bool ppDisablePcDecomp                                   ( const Option *o, char *argv[] )          { Configuration::getInstance()->setDisablePcDecomp(true);              return true; }
static bool ppDisableStaticInit                                 ( const Option *o, char *argv[] )          { Configuration::getInstance()->setDisableStaticInit(true);            return true; }


static bool ppChangePathFrom (const Option *o, char *argv[]) {
#if defined(__linux__) || defined(__APPLE__)
  changepathfrom = argv[0];
#else
  changepathfrom = common::stringLower(argv[0]);
#endif
  return true;
}

static bool ppChangePathTo   (const Option *o, char *argv[]) {
  changepathto = argv[0];
  return true;
}

// list of valid options
const Option OPTIONS_OBJ [] =
{
    { false,  "-graph",             1,  "filename",    1, OT_WC,     ppGraph,             NULL,     "The output graph with the warnings."},
    { false,  "-out",               1,  "filename",    0, OT_WC,     ppOut,               NULL,     "Name of the human readable txt output file."},
    { true,   "-outcsv",            1,  "filename",    0, OT_WC,     ppOutCsv,            NULL,     "Name of the output CSV file"},
    { false,  "-maxstate",          1,  "number",      0, OT_WC,     ppMaxState,          NULL,     "Maximum number of states, default: 500" },
    { false,  "-maxdepth",          1,  "number",      0, OT_WC,     ppMaxDepth,          NULL,     "Maximum depth of the state tree, default: 200" },
    { true,   "-search-strategy",   1,  "name",        0, OT_WC,     ppSearchStrategy,    NULL,     "Search strategy of the state tree, possible values: breadth-first, depth-first, default: depth-first" },
    { true,   "-state-matching",    0,  "",            0, OT_NONE,   ppStateMatching,     NULL,     "Enable state matching, default: false" },
    { true,   "-dCFGGraphml",       0,  "",            0, OT_NONE,   ppCFGDump,           NULL,     "Create CFG graphml dump, default: false" },
    { true,   "-dSYMGraphml",       0,  "",            0, OT_NONE,   ppSYMDump,           NULL,     "Create State Tree graphml dump, default: false" },
    { true,   "-csTimeLimit",       1,  "number",      0, OT_NONE,   ppCsTimeLimit,       NULL,     "Constraint solver time limit to staisfy a PC in milliseconds" },
    { true,   "-methodFrom",        1,  "number",      0, OT_WC,     ppMethodFrom,        NULL,     "Execution starst with this" }, // TODO: for debugging
    { true,   "-disableCB",         0,  "",            0, OT_NONE,   ppDisableCB,         NULL,     "Disable constraint building" },
    { true,   "-disablePcDecomp",   0,  "",            0, OT_NONE,   ppDisablePcDecomp,   NULL,     "Disable path condition decomposition" },
    { true,   "-disableStaticInit", 0,  "",            0, OT_NONE,   ppDisableStaticInit, NULL,     "Disable static initializers. Default: true" },
    CL_STAT
    CL_LIM
    CL_RUL_AND_RULCONFIG("AI4VULN.rul")
    CL_EXPORTRUL
    CL_INPUT_LIST
    CL_CHANGEPATH
    COMMON_CL_ARGS
};

int main(int argc, char **argv) {
    //WriteMsg::setMessageLevel(WriteMsg::mlDDDDebug);
    WriteMsg::setAutomaticFlush(true);
    
    MAIN_BEGIN

    // processing command line arguments

    MainInit(argc, argv, "-");

    if (inputFileNames.empty()) {
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_MISSING_INPUT_FILE);
        clError();
    }

    if (limFileName.empty()) {
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_MISSING_LIM_FILE);
        clError();
    }

    if (outputFileName.empty()) {
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_MISSING_OUTPUT_FILE);
        clError();
    }

    const std::string& txtFileName = Configuration::getInstance()->getOutTxtFile();
    if (!txtFileName.empty()) {
      ofstream txtOutputStream(txtFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
      if(!txtOutputStream) {
        WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_CANT_OPEN, txtFileName.c_str());
        clError();
      }
    }


    Configuration *config = Configuration::getInstance();
    config->setAsgFile(*inputFileNames.begin());
    JavaSymbolicChecker javaSymbolicChecker(limFileName, rulFileName, rulConfig);

    JavaSymbolicCCEChecker cceChecker(javaSymbolicChecker);
    JavaSymbolicDBZChecker dbzChecker(javaSymbolicChecker);
    JavaSymbolicNPEChecker npeChecker(javaSymbolicChecker);
    JavaSymbolicIOBChecker iobChecker(javaSymbolicChecker);
    JavaSymbolicNASChecker nasChecker(javaSymbolicChecker);


    javaSymbolicChecker.executeCheck(inputFileNames, changepathfrom, changepathto);
    
    javaSymbolicChecker.saveResultGraph(outputFileName, false);
    
    writeMinimalStatFile(statFile);
    MAIN_END
    return 0;
}
