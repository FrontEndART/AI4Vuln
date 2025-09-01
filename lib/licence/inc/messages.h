#ifndef _LICENCE_LIB_MESSAGES_H_
#define _LICENCE_LIB_MESSAGES_H_

#define CMSG_LICENCE_INCORRECT           common::WriteMsg::mlError, "Error: Incorrect licence file\n"
#define CMSG_LICENCE_CANNOT_ACCESS       common::WriteMsg::mlError, "Error: Cannot access licence file [%s] (it might be read-only)\n"
#define CMSG_LICENCE_CANNOT_OPEN         common::WriteMsg::mlError, "Error: Cannot open license file\n"
#define CMSG_LICENCE_NOT_EXIST           common::WriteMsg::mlError, "Error: License file does not exist or it is empty\n"
#define CMSG_LICENCE_ERROR               common::WriteMsg::mlDebug, "Debug: Licence error!\n"
#define CMSG_LICENCE_LONG_MSG            common::WriteMsg::mlDebug, "Debug: The recieved message is too long!\n"
#define CMSG_LICENCE_CURL_PERFORM_FAILED common::WriteMsg::mlError, "Error: %s\n"
#define CMSG_LICENCE_CRYPTO_ERROR        common::WriteMsg::mlDebug, "Debug: Crypting error:%s\n"
#define CMSG_LICENCE_INVALID             common::WriteMsg::mlDebug, "Debug: valid=false\n"
#define CMSG_LICENCE_VALID               common::WriteMsg::mlDebug, "Debug: valid=true\n"
#define CMSG_LICENCE_WRONG_TIMESTAMP     common::WriteMsg::mlDebug, "Debug: Wrong timestamp\n"
#define CMSG_LICENCE_WRONG_UUID          common::WriteMsg::mlError, "Error: Invalid UUID!\n"
#define CMSG_FIRSTLINE_DATE_MSG          common::WriteMsg::mlNormal, "Modification:%s\n"
#define CMSG_WRONGLINE_MSG               common::WriteMsg::mlNormal, "Wrong format:%s\n"
#define CMSG_GLINE_MSG                   common::WriteMsg::mlNormal, "%s: %s %u %s %s\n"
#endif
