#ifndef _GRAPHSUPPORT_MESSAGES_H_
#define _GRAPHSUPPORT_MESSAGES_H_

#define CMSG_EX_GRAPH_NOT_EXIST                       ": Graph does not exist"
#define CMSG_EX_FOUND_MORE_METRIC_ATTRIBUTE( ATTRNAME, UID) "Found 2 or more " + ATTRNAME + " metric attributes in " + UID + " node"
#define CMSG_EX_WRONG_ATTRIBUTE_TYPE                  "Wrong attribute type!"
#define CMSG_EX_UNHANDLED_ASG_TYPE(ASG)               "Unhandled ASG type (" + ASG + ")"
#define CMSG_EX_INVALID_PRIORITY_VALUE(VAL)           "Invalid priority value:" + VAL


#define CMSG_STAT_HEADER_IMPACTED                     "Impacted"
#define CMSG_STAT_HEADER_NAME                         "Name"
#define CMSG_STAT_HEADER_PATH                         "Path"
#define CMSG_STAT_HEADER_LINE                         "Line"
#define CMSG_STAT_HEADER_DESCRIPTION                  "Description"

#define CMSG_SARIF_OUT_OF_DATE(UID, ATYPE, NAME, CONTEXT)   "Tried to get '" + NAME + "' attribute with conxtext of '" + CONTEXT + "' and a type of '" + ATYPE + "' in " + UID + " node|Attribute"

#endif
