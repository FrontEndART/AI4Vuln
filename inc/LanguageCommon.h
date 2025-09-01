#ifndef LANGUAGECOMMON_H
#define LANGUAGECOMMON_H

#include <licence/inc/Licence.h>

#define HAS_LANGUAGE_CONFIG

#ifdef SCHEMA_CPP
  #define DEFAULT_LICENSE_LANG columbus::licence::langCPP
  #define LANGUAGE_STR "CPP"
#elif defined SCHEMA_JAVA
  #define DEFAULT_LICENSE_LANG columbus::licence::langJava
  #define LANGUAGE_STR "Java"
#elif defined SCHEMA_JAVASCRIPT
  #define DEFAULT_LICENSE_LANG columbus::licence::langJavaScript
  #define LANGUAGE_STR "JavaScript"
#elif defined SCHEMA_RPG
  #define DEFAULT_LICENSE_LANG columbus::licence::langRPG
  #define LANGUAGE_STR "RPG"
#elif defined SCHEMA_PYTHON
  #define DEFAULT_LICENSE_LANG columbus::licence::langPython
  #define LANGUAGE_STR "Python"
#elif defined SCHEMA_CSHARP
  #define DEFAULT_LICENSE_LANG columbus::licence::langCSharp
  #define LANGUAGE_STR "C#"
#else
  #define DEFAULT_LICENSE_LANG columbus::licence::langAny
  #define LANGUAGE_STR ""
  #undef HAS_LANGUAGE_CONFIG
#endif

#endif
