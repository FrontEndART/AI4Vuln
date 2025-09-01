set (LIBNAME symbolic_java)

set (SOURCES
    src/algorithms
    src/algorithms/AsgUtils.cpp
    src/algorithms/SymbolicExecutor.cpp
    src/algorithms/SymbolicTypesPreVisitor.cpp
    src/common.cpp
    src/definition/Array.cpp
    src/definition/BooleanValueDefinition.cpp
    src/definition/ByteValueDefinition.cpp
    src/definition/CharValueDefinition.cpp
    src/definition/DefinitionFactory.cpp
    src/definition/DoubleValueDefinition.cpp
    src/definition/FloatValueDefinition.cpp
    src/definition/IntValueDefinition.cpp
    src/definition/LongValueDefinition.cpp
    src/definition/Object.cpp
    src/definition/Reference.cpp
    src/definition/ShortValueDefinition.cpp
	src/definition/SymbolDefinition.cpp
    src/listener/CsvStateListener.cpp
    src/listener/JavaLimWriteListener.cpp
    src/listener/JavaStateListener.cpp
    src/listener/PrintStateListener.cpp
    src/listener/TxtOutputWriter.cpp
    src/listener/JsonOutputWriter.cpp
    src/printer/JavaStateTreeElementPrinter.cpp
    src/structure/StackTraceJava.cpp
    src/structure/StateFactoryJava.cpp
    
    inc/algorithms/AsgUtils.h
    inc/algorithms/SymbolicExecutor.h
    inc/algorithms/SymbolicTypesPreVisitor.h
    inc/common.h
    inc/definition/Array.h
    inc/definition/BooleanValueDefinition.h
    inc/definition/ByteValueDefinition.h
    inc/definition/CharValueDefinition.h
    inc/definition/DefinitionDispatcher.h
    inc/definition/DefinitionDispatcherTargetInterface.h
    inc/definition/DefinitionFactory.h
    inc/definition/DoubleValueDefinition.h
    inc/definition/FloatValueDefinition.h
    inc/definition/IntValueDefinition.h
    inc/definition/LongValueDefinition.h
    inc/definition/Object.h
    inc/definition/Reference.h
    inc/definition/ShortValueDefinition.h
    inc/definition/ValueDefinition.h
	inc/definition/SymbolDefinition.h
    inc/listener/CsvStateListener.h
    inc/listener/JavaLimWriteListener.h
    inc/listener/JavaStateListener.h
    inc/listener/PrintStateListener.h
    inc/listener/TxtOutputWriter.h
    inc/listener/JsonOutputWriter.h
    inc/messages.h
    inc/SMTFunctionStrings.h
    inc/printer/JavaStateTreeElementPrinter.h
    inc/structure/StackTraceJava.h
    inc/structure/StateFactoryJava.h
	inc/structure/StateJava.h
	src/structure/StateJava.cpp
	

	inc/constraint/Z3Solver.h
	src/constraint/Z3Solver.cpp
	inc/constraint/Z3ConstraintBuilder.h
	src/constraint/Z3ConstraintBuilder.cpp
	inc/constraint/Z3ConstraintExpression.h
	src/constraint/Z3ConstraintExpression.cpp
	inc/constraint/Z3Constraint.h
	src/constraint/Z3Constraint.cpp
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_library (${LIBNAME} STATIC ${SOURCES})
add_dependencies (${LIBNAME} boost z3)
target_link_libraries(symbolic_java
    PRIVATE
        ${CMAKE_SOURCE_DIR}/lib/libjava.a
)


target_precompile_headers(${LIBNAME} PRIVATE inc/common.h)

