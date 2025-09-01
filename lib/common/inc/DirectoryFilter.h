#ifndef _COMMON_DIRFILTER_H_
#define _COMMON_DIRFILTER_H_

#include <string>
#include <list>
#include <map>

class DirectoryFilter {
public:
  DirectoryFilter();
  ~DirectoryFilter();
  /**
  * \brief Loads the filter file and sets filter_in and filter_out lists.
  * \param fltp       [in] The given filter file.
  */
  bool openFilterFile(std::string fltp);

  /**
  * \brief Determines if the given path is filtered or not. It depends on the given filter file.
  *        If the given directory path starts with "-" in the filter file or cannot be found in the filter file, and this path will be filtered.
  * \param path       [in] The given path.
  * \return           True, if the given path is filtered. Default is false.
  */
  bool isFilteredOut(const std::string& path) const;

  /**
  * \return           True, if the filter_list is empty, false otherwise.
  */
  bool isEmpty();

private:
  std::list<std::string> filter_list;
  mutable std::map<std::string, bool> filter_cache;
};

#endif
