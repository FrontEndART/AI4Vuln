#ifndef _HEADERDATA_H
#define _HEADERDATA_H

#include <string>
#include <io/inc/ZippedIO.h>

namespace columbus {
   enum HeaderDataTypeKind {
      hdkPropertyData,
      hdkIntervalData,
      hdkAnalysisData,
      hdkLinkerCompilationData,
      hdkLimOrigin,
      hdkOverride,
      hdkSymbolTable
  };
  
  class HeaderData {
  public:
    virtual ~HeaderData(){}

    /**
     * @brief Saves the header data to the given file.
     */
    virtual void save(io::BinaryIO &binIo) const = 0;

    /** 
     *@brief loading the header data
     *
     */
    virtual void load(io::BinaryIO &binIo) = 0;

    /**
     * @brief get headerdata type
     * @return the type of the header
     */
    virtual HeaderDataTypeKind getType() const = 0;
    
    /**
     * @brief Returns a string representation of the header data.
     */
    virtual std::string toString() const = 0;
  };

  
}

#endif
