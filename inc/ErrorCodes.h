#ifndef __ERRORCODES_H
#define __ERRORCODES_H

namespace common
{

enum ErrorCode
{
  // CAN
  retOk                    =  0,  // OK
  retAnalyzerError         =  1,  // Error during analysis
  retFileError             =  2,  // File system error
  retBadArgError           =  3,  // Bad command-line arguments

  // ASG
  dumpOK                   = 10,
  dumpError,
  retIncorrectCSIVersion,
  retCSIOpenError,
  retCSILoadError,

  // CANLink
  retStringTableOpenError  = 20,
  retStringTableLoadError,
  retStringTableLoadOK,
  retASGLoadError,
  retASGLoadWarning,
  retASGLoadOK,
  retASGSaveError,
  retASGSaveOK,
  retLinkingError,
  retLinkingOK,
  retOutOfMemoryError,

  // columbus::cpp
  retColumbusException     = 50,  // General columbus::cpp exception

  // Other
  retLicenceError          = 99,  // Bad or missing licence file
  retOtherError                   // Unspecified error
}; 

};

#endif /* __ERRORCODES_H */
