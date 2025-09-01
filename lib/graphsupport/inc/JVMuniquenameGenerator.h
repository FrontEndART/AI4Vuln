#ifndef _JVMUNIQUENAME_GENERATOR_H
#define _JVMUNIQUENAME_GENERATOR_H

#include <vector>
#include <string>

namespace columbus { namespace graphsupport {

  void stringTokenizer(std::vector<std::string>& tokenlist, const std::string& str, char separator);
  std::string generateName(const std::string& nametoken);
  std::string generateReturnAndParam(const std::string& token);
  std::string generateGenericType(const std::string& token);
  std::string generateJVMnameForJavaGraph(const std::string& uniquename);

}}
#endif
