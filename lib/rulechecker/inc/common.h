#ifndef __RULECHECKER_COMMON_H__
#define __RULECHECKER_COMMON_H__

#include <java/inc/java.h>

namespace ASG = columbus::java::asg;
namespace ASG_Base = columbus::java::asg::base;

#define FACTORY_LOAD_INIT CsiHeader header;
#define FILTER_EXT ".fjsi"
#define CHECK_COMPONENT_ID if (!header.get(header.csih_OriginalLocation, componentID)) { \
      common::changePath(componentID, changepathfrom, changepathto); \
    }
#define FIND_NODE(node)



#endif