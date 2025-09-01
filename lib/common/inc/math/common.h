#ifndef COMMON_MATH_COMMON_H
#define COMMON_MATH_COMMON_H

#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cinttypes>

namespace common { namespace math { 

  /**
  * Checks whether the number is prime or not
  * Uses Miller-Rabin prime-test
  **/
  bool isPrime(uint32_t number);
  unsigned int editDistanceRec(const std::vector<int>& v1, unsigned int lastV1, const std::vector<int>& v2, unsigned int lastV2);
  size_t editDistance(const std::vector<int>& v1, const std::vector<int>& v2, unsigned int bound=std::numeric_limits<unsigned int>::max());
  size_t editDistance(const std::string& v1, const std::string& v2, unsigned int bound=std::numeric_limits<unsigned int>::max());

}}


#endif
