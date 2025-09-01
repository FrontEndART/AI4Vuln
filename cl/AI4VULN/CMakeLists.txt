set (PROGRAM_NAME AI4VULN)

set (SOURCES
    src/checker/JavaSymbolicChecker.cpp
    src/listener/JavaSymbolicCheckerWarningListener.cpp
    src/main.cpp
    src/rules/JavaSymbolicCCEChecker.cpp
    src/rules/JavaSymbolicDBZChecker.cpp
    src/rules/JavaSymbolicINFChecker.cpp
    src/rules/JavaSymbolicIOBChecker.cpp
    src/rules/JavaSymbolicNASChecker.cpp
    src/rules/JavaSymbolicNPEChecker.cpp
    src/rules/SymbolicRuleChecker.cpp
    
    inc/checker/JavaSymbolicChecker.h
    inc/listener/JavaSymbolicCheckerWarningListener.h
    inc/messages.h
    inc/rules/JavaSymbolicCCEChecker.h
    inc/rules/JavaSymbolicDBZChecker.h
    inc/rules/JavaSymbolicINFChecker.h
    inc/rules/JavaSymbolicIOBChecker.h
    inc/rules/JavaSymbolicNASChecker.h
    inc/rules/JavaSymbolicNPEChecker.h
    inc/rules/SymbolicRuleChecker.h
)


add_executable(${PROGRAM_NAME} ${SOURCES})
add_dependencies(${PROGRAM_NAME} ${COLUMBUS_GLOBAL_DEPENDENCY})
target_link_libraries(${PROGRAM_NAME}  ${CMAKE_SOURCE_DIR}/lib/librulechecker_java.a ${CMAKE_SOURCE_DIR}/lib/liblim.a ${CMAKE_SOURCE_DIR}/lib/liblim2graph.a ${CMAKE_SOURCE_DIR}/lib/libgraphsupport.a ${CMAKE_SOURCE_DIR}/lib/libgraph.a ${CMAKE_SOURCE_DIR}/lib/libjava.a ${CMAKE_SOURCE_DIR}/lib/libcfg.a ${CMAKE_SOURCE_DIR}/lib/librul.a symbolic_java symbolic ${CMAKE_SOURCE_DIR}/lib/libcommon.a ${CMAKE_SOURCE_DIR}/lib/libcsi.a ${CMAKE_SOURCE_DIR}/lib/libstrtable.a ${CMAKE_SOURCE_DIR}/lib/libio.a z3 boost_filesystem boost_system ${CMAKE_SOURCE_DIR}/lib/libjsoncpp.a xerces-c md4c-html md4c boost_iostreams z)
target_compile_definitions(AI4VULN PUBLIC SCHEMA_JAVA)
add_copy_next_to_the_binary_dependency (${PROGRAM_NAME} AI4VULN.rul.md)

set(DEMO_DIR "${CMAKE_BINARY_DIR}/demo")

add_custom_command(TARGET ${PROGRAM_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "${DEMO_DIR}"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
          "$<TARGET_FILE:${PROGRAM_NAME}>"
          "${DEMO_DIR}/$<TARGET_FILE_NAME:${PROGRAM_NAME}>"
)
