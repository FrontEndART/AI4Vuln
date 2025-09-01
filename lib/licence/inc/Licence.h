#ifndef _LICENCE_H
#define _LICENCE_H

/*******************************************************************************
* File: Licence.h                                                              *
*                                                                              *
* Created by  : Andras Csaba Toth  29.07.2009.                                 *
*                                                                              *
* Short description:                                                           *
*     This file contains the function declarations for licencing.              *
*******************************************************************************/
#define CURL_STATICLIB

#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <boost/filesystem.hpp>

namespace columbus {

  namespace licence {

    enum LicenseType {
      licenseFree,
      licenseCommercial
    };
    
    enum Language {
      langAny, 
      langCPP,
      langJava,
      langJavaScript,
      langPython,
      langRPG,
      langCSharp
    };
    
    class Licence {
    public:

        /**
         * Returns a licence code depending on the program name and LOC limit valid until the given endDate.
         * The licese format: RRRR YYYYMMDD RR PPPPPPPP RR SSSSS R CCCC RRRR
         */
        static std::string createLicence(const std::string& programName, unsigned locLimit, const std::string& endDate, Language lang);

        /**
         * Checks whether the given licence string is valid with the actual date, program name, language and LOC.
         * It returns False if the license is not valid or the license format is wrong.
         */
        static bool checkLicence(const std::string& programName, unsigned loc, Language lang, const std::string& licenseString, std::string& validUntil);
                
        /** 
         * It appends a license string determined by the parameters to the end of the file given in fileName parameter.
         */
        static void writeLicenceFile(const std::string& programName, unsigned locLimit, const std::string& endDate, Language lang, const boost::filesystem::path& fileName);

        /**
         * It writes the license to the output stream.
         */
        static void writeLicenceToStream(const std::string& programName, unsigned locLimit, const std::string& endDate, Language lang, std::ostream& output);


        /**
         * Checks whether the licence file given in fileName parameter contains any valid code for the the given program and LOC.
         * It re-writes the first line of the licence file (date of the last usage) according to the actual date (if the check of the first line was ok).
         * Date checks:
         *      - If the date of last usage minus 5 minutes is greater than the actual time the licence is expired.
         */
        static bool checkLicenceFile(const std::string& programName, unsigned loc, Language lang, const boost::filesystem::path& fileName, std::string& validUntil);

        /* Checks whether the license file in the path of executable contains a valid code for the given program and LOC.
         * If does not found a valid one it checks for valid licence codes in the defaultLicenseDirectory.
         */
        static bool checkLicenceFile(const std::string& programName, unsigned loc, Language lang, std::string& validUntil);
        
        static bool checkLicenceNET(const std::string& URL, const std::string& language, const std::string& version, const std::string& uuid, long timeout, int retry);
        
        static LicenseType checkProgramLicense(const std::string& programName, unsigned loc, Language);
        
        static bool getLicenseInfo(const std::vector<std::string>& programNames, const boost::filesystem::path& fileName);

      public:
        static std::string createHash(const std::string& programName);
        static std::string getRandomChars(int numberOfChars);
        static std::string checkEndDate(const std::string& endDate);
        
        static void fillCodeTable();
        static std::string encode (const std::string& str, int shift);
        static std::string decode (const std::string& str, int shift);
        static std::string getCRC (const std::string& str);
        static std::string getCurrentTime();
        static std::string generateFirstLine();
        static std::string insertDashes (const std::string& str);
        static std::string removeDashes (const std::string& str);
        static bool checkLicenceFormat (const std::string licence);
        static bool checkFirstLineDate(const std::string& decodedTime);
        static std::string encodeBase62(unsigned i);
        static unsigned decodeBase62(const std::string& str);
        
        static std::string encryptAES(const std::string& plaintext);
        static std::string decryptAES(const std::string& encryptedtext);
        static bool sendPostRequest(const std::string& URL, const std::string& sendBody, std::string& recvHeader, std::string& recvBody, long timeout);
        
        static int encode_index;
    };
 
  }//namespace licence
}//namespace columbus

#endif
