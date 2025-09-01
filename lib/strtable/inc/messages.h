#ifndef _STRTABLE_M_H_
#define _STRTABLE_M_H_

#define CMSG_BUCKET_IS_FULL                           common::WriteMsg::mlError, "Error: StrTable: Bucket (%d) is full\n"
#define CMSG_WRONG_FILE_FORMAT                        common::WriteMsg::mlError, "Error: StrTable::load(): Wrong file format\n"
#define CMSG_LOAD_ERROR                               common::WriteMsg::mlError, "Error: StrTable::load(): Memory allocation error\n"
#define CMSG_ERROR_MEMORY_ALLOCATION                  common::WriteMsg::mlError, "Error: StrTable: Memory allocation error\n"
#define CMSG_READ_ERR                                                            "Error: StrTable::load(): Error while reading\n"
#define CMSG_WRITE_ERR                                                           "Error: StrTable::save(): Error while writing\n"
#define CMSG_BUCKET_TOTAL_NUMBER                      common::WriteMsg::mlNormal,"Bucket:%u (total number:%zu)\n"
#define CMSG_TOTAL_COUNT                              common::WriteMsg::mlNormal,"Total Count: %zu\n"

#endif
