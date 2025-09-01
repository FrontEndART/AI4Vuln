#ifndef __COLUMBUS_SUPPRESSOR_H__
#define __COLUMBUS_SUPPRESSOR_H__

#include "common.h"
#include <strtable/inc/StrTable.h>

#include <string>
#include <set>
#include <boost/icl/split_interval_map.hpp>



namespace columbus { 
  
  
  class WarningSuppressor {

    public:
      typedef std::set<std::string> StringSet;

      WarningSuppressor(const ASG::Factory& factory) : factory(factory) { }
      void addLineSuppressionMarker(const std::string& commentText);
      virtual void buildSuppressionMap();
      const StringSet* getSuppressionMarkers(const std::string& file, int line, int column) const;
      
      virtual ~WarningSuppressor() { };
      
    protected:
      
      typedef std::pair<int, int> IntPair;
      typedef boost::icl::split_interval_map<IntPair, StringSet> IntervalStringSetMap;
      typedef std::map<columbus::Key, IntervalStringSetMap> StringIntervalStringSetMap;
      
      StringIntervalStringSetMap suppressionMarkerMap;
      StringSet lineSuppressionMarker;
      
      const ASG::Factory& factory;
      
      friend class SuppressionMarkerCollector;
  };
  



  class SuppressionMarkerCollector : public ASG::VisitorAbstractNodes {
    public:
      SuppressionMarkerCollector(WarningSuppressor* warningSuppressor) : warningSuppressor(warningSuppressor) { };

      virtual void visit(const ASG::struc::AnnotatedElement& node , bool callVirtualBase);
      virtual void visit(const ASG::base::LineComment& node , bool callVirtualBase);


    protected:
      WarningSuppressor* warningSuppressor;
  };
  

}



#endif
