set (LIBNAME symbolic)

set (SOURCES
    src/algorithms/AbstractSymbolicExecutor.cpp
    src/algorithms/BreadthFirstSearchStrategy.cpp
    src/algorithms/DepthFirstSearchStrategy.cpp
    src/algorithms/SymbolicEngine.cpp
    src/algorithms/SymbolicEngineInterface.cpp
    src/common.cpp
    src/definition/Definition.cpp
    src/listener/StateListener.cpp
    src/structure/Configuration.cpp
    src/structure/Locals.cpp
    src/structure/Memory.cpp
    src/structure/StackTrace.cpp
    src/structure/State.cpp
    src/structure/StateFactory.cpp
    src/structure/SymbolicColumbusException.cpp
	
    src/constraint/Constraint.cpp
    src/constraint/ConstraintSolver.cpp
	src/constraint/ConstraintBuilder.cpp
    src/constraint/ConstraintSolverExpr.cpp
    inc/constraint/ConstraintSolver.h
	inc/constraint/Constraint.h
	inc/constraint/ConstraintBuilder.h
    inc/constraint/ConstraintSolverExpr.h

    inc/algorithms/AbstractSymbolicExecutor.h
    inc/algorithms/BreadthFirstSearchStrategy.h
    inc/algorithms/DepthFirstSearchStrategy.h
    inc/algorithms/SearchStrategy.h
    inc/algorithms/StateExpanderInterface.h
    inc/algorithms/SymbolicEngine.h
    inc/algorithms/SymbolicEngineInterface.h
    inc/common.h
    inc/definition/Address.h
    inc/definition/BaseInterface.h
    inc/definition/Definition.h
    inc/listener/StateListener.h
    inc/listener/WarningListener.h
    inc/messages.h
    inc/structure/Configuration.h
    inc/structure/ExceptionalStateException.h
    inc/structure/Locals.h
    inc/structure/Memory.h
    inc/structure/ProxyTree.h
    inc/structure/StackTrace.h
    inc/structure/StateFactory.h
    inc/structure/State.h
    inc/structure/SymbolicColumbusException.h
    inc/structure/SymbolicCommon.h
)

add_library (${LIBNAME} STATIC ${SOURCES})
add_dependencies (${LIBNAME} boost)
