#ifndef _REFDISTRIBUTORSTRTABLE_H
#define _REFDISTRIBUTORSTRTABLE_H
#include <map>
#include "strtable/inc/StrTable.h"

namespace columbus {
  class RefDistributorStrTable;

  class StringReference {
    public :
      Key getKey() const;
      const std::string& get() const;
      RefDistributorStrTable& getTable() const ;
      static void copy (const StringReference*& pLeft, const StringReference* pRight);
    protected:
      StringReference(RefDistributorStrTable& rStrTable, Key stringKey);
      RefDistributorStrTable& rStrTable;
      Key stringKey;
    friend class RefDistributorStrTable;
  };
  
  class RefDistributorStrTable :public StrTable {
    public:
      typedef std::map<Key,StringReference*> StringRefMap;

      RefDistributorStrTable(const unsigned buckets = 511);
      virtual ~RefDistributorStrTable();

      RefDistributorStrTable& operator=(const RefDistributorStrTable& rhs);

      // Inserts the given string into the string table and gives back a reference key.
      const StringReference* setStr(const std::string& s, StrType type = strDefault);

      //this function give back the reference the string WRNING if the key is not exsist it get back the invalid but refence. (but not NULL pointer)
      const StringReference* getRefByKey(Key strKey);

      // Loads the string table from the given file. All data exist in the current table will be lost.
      void load(columbus::io::BinaryIO& file);
      
      // Loads the string table from the given file but it keeps the former reference map!
      void loadWithKeepingTheRefMap(columbus::io::BinaryIO& file);

    protected:
       StringRefMap mapOfRef;
       StringReference emptyReference;
       void clearRefMap ();
  };
  
}
#endif
