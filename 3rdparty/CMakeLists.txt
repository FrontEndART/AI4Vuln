include(ExternalProject)
set(BUILD_SHARED_LIBS OFF)

# All the external static library names should follow this naming convention:
# Linux:
#   lib<name>.a
# Windows:
#   <name>.lib


if(COMMAND cmake_policy)
	if (POLICY CMP0135)
		cmake_policy(SET CMP0135 NEW)
	endif()
endif()

file (MAKE_DIRECTORY ${COLUMBUS_3RDPARTY_INSTALL_DIR}/bin)
file (MAKE_DIRECTORY ${COLUMBUS_3RDPARTY_INSTALL_DIR}/lib)
file (MAKE_DIRECTORY ${COLUMBUS_3RDPARTY_INSTALL_DIR}/include)

# Disable warnings during building 3rdparty code
if (CMAKE_CXX_COMPILER_ID MATCHES GNU|Clang)
  add_compile_options("-w")
endif()


########################### zlib #########################

ExternalProject_Add(zlib
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/zlib
    PATCH_COMMAND git clean -x -d -f
          COMMAND git reset --hard
          COMMAND git apply --ignore-whitespace ${CMAKE_CURRENT_SOURCE_DIR}/CMake/zlib.patch
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${COLUMBUS_3RDPARTY_INSTALL_DIR} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}  -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
    LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_INSTALL 1
)


########################### boost ########################

if (CMAKE_CXX_COMPILER_ID STREQUAL MSVC)
  set (BOOST_TOOLSET toolset=msvc-14.3)
elseif (CMAKE_CXX_COMPILER_ID MATCHES GNU|Clang)
  set (BOOST_EXTRA_CXX_COMPILER_FLAGS cxxflags=-fPIC)
  set (BOOST_EXTRA_C_COMPILER_FLAGS cflags=-fPIC)
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (BOOST_TOOLSET toolset=gcc-${CMAKE_CXX_COMPILER_VERSION})
  elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set (BOOST_TOOLSET toolset=clang-${CMAKE_CXX_COMPILER_VERSION})
  endif()
endif ()

ExternalProject_Add(boost
    DEPENDS zlib
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/boost
    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND ${COMMAND_PREFIX}bootstrap${SCRIPT_EXT}
    BUILD_COMMAND ${COMMAND_PREFIX}b2 ${BOOST_EXTRA_CXX_COMPILER_FLAGS} ${BOOST_EXTRA_C_COMPILER_FLAGS} ${BOOST_TOOLSET} --reconfigure --build-dir=${CMAKE_CURRENT_BINARY_DIR}/boost-prefix --prefix=${COLUMBUS_3RDPARTY_INSTALL_DIR} -j8 --with-filesystem --with-system --with-date_time --with-iostreams --with-graph --with-regex --with-thread --with-math --layout=system variant=$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>  runtime-link=static architecture=x86  threading=multi address-model=64 link=static  -sZLIB_INCLUDE=${COLUMBUS_3RDPARTY_INSTALL_DIR}/include -sZLIB_LIBPATH=${COLUMBUS_3RDPARTY_INSTALL_DIR}/lib -sZLIB_BINARY=z -sNO_ZLIB=0 -sNO_BZIP2=1   headers
          COMMAND ${COMMAND_PREFIX}b2 ${BOOST_EXTRA_CXX_COMPILER_FLAGS} ${BOOST_EXTRA_C_COMPILER_FLAGS} ${BOOST_TOOLSET} --reconfigure --build-dir=${CMAKE_CURRENT_BINARY_DIR}/boost-prefix --prefix=${COLUMBUS_3RDPARTY_INSTALL_DIR} -j8 --with-filesystem --with-system --with-date_time --with-iostreams --with-graph --with-regex --with-thread --with-math --layout=system variant=$<$<CONFIG:Debug>:debug>$<$<CONFIG:Release>:release>  runtime-link=static architecture=x86  threading=multi address-model=64 link=static  -sZLIB_INCLUDE=${COLUMBUS_3RDPARTY_INSTALL_DIR}/include -sZLIB_LIBPATH=${COLUMBUS_3RDPARTY_INSTALL_DIR}/lib -sZLIB_BINARY=z -sNO_ZLIB=0 -sNO_BZIP2=1   install
    INSTALL_COMMAND ${CMAKE_COMMAND} -E echo "No sepearate installation step is needed."
    LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_INSTALL 1
)

# This extra rename step is needed on windows to rename the libraries to be compatible with the CMake library naming convention.
if (CMAKE_SYSTEM_NAME STREQUAL Windows)
  set (BOOST_LIBRARY_NAMES_TO_RENAME
    iostreams
    graph
    date_time
    chrono
    math_c99
    math_c99f
    math_c99l
    math_tr1
    math_tr1f
    math_tr1l
    regex
    system
    filesystem
    thread
  )

  foreach (LIB ${BOOST_LIBRARY_NAMES_TO_RENAME})
    set (BOOST_RENAME_COMMAND ${BOOST_RENAME_COMMAND} COMMAND ${CMAKE_COMMAND} -E rename "${COLUMBUS_3RDPARTY_INSTALL_DIR}/lib/libboost_${LIB}.lib" "${COLUMBUS_3RDPARTY_INSTALL_DIR}/lib/boost_${LIB}.lib")
  endforeach()
  
  ExternalProject_Add_Step (boost rename
    DEPENDEES BUILD INSTALL
    ${BOOST_RENAME_COMMAND}
    LOG 1
  )
endif ()

########################### xerces-c #########################

if (CMAKE_SYSTEM_NAME STREQUAL Linux OR CMAKE_SYSTEM_NAME STREQUAL Darwin)
  ExternalProject_Add( xerces-c
      URL https://archive.apache.org/dist/xerces/c/3/sources/xerces-c-3.1.4.tar.gz
      URL_HASH MD5=21bb097b711a513275379b59757cba4c
      BUILD_IN_SOURCE 1
      CONFIGURE_COMMAND ./reconf
                COMMAND ./configure --disable-shared -disable-network --disable-transcoder-icu --prefix=${COLUMBUS_3RDPARTY_INSTALL_DIR} --disable-dependency-tracking
      BUILD_COMMAND make -j8 all
      INSTALL_COMMAND make install
      LOG_DOWNLOAD 1
      LOG_UPDATE 1
      LOG_CONFIGURE 1
      LOG_BUILD 1
      LOG_INSTALL 1
  )

elseif (CMAKE_SYSTEM_NAME STREQUAL Windows)
  
  ExternalProject_Add( xerces-c
      URL https://archive.apache.org/dist/xerces/c/3/sources/xerces-c-3.1.4.zip
      URL_HASH MD5=6fcd8ec268f6bfe11d8ce2cd7d25a185
      BUILD_IN_SOURCE 1
      CONFIGURE_COMMAND ${CMAKE_COMMAND} -E echo "No configuration is required."
      BUILD_COMMAND msbuild projects/Win32/VC14/xerces-all/xerces-all.sln /m /t:XercesLib "/p:Configuration=Static $<CONFIG>" /p:Platform=${VS_PLATFORM} /p:PlatformToolset=${CMAKE_VS_PLATFORM_TOOLSET}
      INSTALL_COMMAND ${CMAKE_COMMAND} "-DCOPY_SOURCE=${CMAKE_CURRENT_BINARY_DIR}/xerces-c-prefix/src/xerces-c/src/xercesc/" "-DCOPY_TARGET=${COLUMBUS_3RDPARTY_INSTALL_DIR}/include/xercesc" -DCOPY_PATTERN=*.hpp -P ${CMAKE_CURRENT_SOURCE_DIR}/CMake/SearchAndCopyFiles.cmake
              COMMAND ${CMAKE_COMMAND} "-DCOPY_SOURCE=${CMAKE_CURRENT_BINARY_DIR}/xerces-c-prefix/src/xerces-c/src/xercesc/" "-DCOPY_TARGET=${COLUMBUS_3RDPARTY_INSTALL_DIR}/include/xercesc" -DCOPY_PATTERN=*.c -P ${CMAKE_CURRENT_SOURCE_DIR}/CMake/SearchAndCopyFiles.cmake
              COMMAND ${CMAKE_COMMAND} -E copy "Build/Win64/VC14/Static $<CONFIG>/xerces-c_static_3$<$<CONFIG:Debug>:d>.lib" ${COLUMBUS_3RDPARTY_INSTALL_DIR}/lib/xerces-c.lib
      LOG_DOWNLOAD 1
      LOG_CONFIGURE 1
      LOG_BUILD 1
      LOG_INSTALL 1
  )
endif ()

########################### md4c #########################
ExternalProject_Add(md4c
  GIT_REPOSITORY https://github.com/mity/md4c
  GIT_TAG release-0.4.8
  GIT_SHALLOW 1
  UPDATE_DISCONNECTED 1
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${COLUMBUS_3RDPARTY_INSTALL_DIR} -DBUILD_SHARED_LIBS=OFF
  BUILD_IN_SOURCE 1
  LOG_DOWNLOAD 1
  LOG_CONFIGURE 1
  LOG_BUILD 1
  LOG_INSTALL 1
)

  ######################## z3 #################################
  
  ExternalProject_Add( z3
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/z3
	CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${COLUMBUS_3RDPARTY_INSTALL_DIR} -DZ3_BUILD_LIBZ3_SHARED=OFF -DZ3_SINGLE_THREADED=OFF -DZ3_BUILD_LIBZ3_MSVC_STATIC=ON -DCMAKE_MSVC_RUNTIME_LIBRARY=MultiThreadedDebug
	BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR> --config $<CONFIG> -j ${PHYSICAL_CORES}
	LOG_CONFIGURE 1
    LOG_BUILD 1
    LOG_INSTALL 1      
  )
