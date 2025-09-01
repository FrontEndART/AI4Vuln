#ifndef _COLUMBUS_EXCEPTION_H_
#define _COLUMBUS_EXCEPTION_H_

#include <common/inc/PlatformDependentDefines.h>
#include <string>

#define COLUMBUS_STRINGIFY(x) #x
#define COLUMBUS_TOSTRING(x) COLUMBUS_STRINGIFY(x)
#define COLUMBUS_LOCATION __FILE__ ":" COLUMBUS_TOSTRING(__LINE__)

namespace columbus {

/** 
* Class for exception handling, with location and error message.
*/  
class Exception {
public:
  /** 
  * Requires error message and location parameters.
  *
  * \param location the place where the error is occured
  * \param message errormessage
  */  
  Exception(const std::string &location, const std::string &message) : msg(message)
  {
    const auto dirdivpos = location.find_last_of(DIRDIVCHAR);
    if (dirdivpos != std::string::npos)
      loc = location.substr(dirdivpos + 1);
    else
      loc = location;
  }
  /**
  * Destructor.
  */  
  virtual ~Exception() {}
  /** 
  * Returns a readable string of the error.
  * \return exception class name, location of the error and te error message as string
  */  
  const std::string toString() const  {return getClassName() + "@" + getLocation() + ": " + getMessage();}
  /** 
  * Returns the class of exception.
  */  
  virtual const std::string getClassName() const  {return "columbus::Exception";}
  /** 
  * Returns the location of the error.
  * \return location of error
  */  
  const std::string& getLocation() const  {return loc;}
  /** 
  * Returns the message of the error.
  */  
  const std::string& getMessage() const  {return msg;}
private:
  std::string loc;
  std::string msg;
};

class IOException: public Exception {
  public:
    IOException(const std::string &location, const std::string &message) : Exception(location, message) {
    }
    
    virtual const std::string getClassName() const {
      return "columbus::IOException";
    }
};

}

#endif

