#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    unsigned long  Definition::nextDefinitionId = 0;
	
    Definition::Definition(columbus::NodeId _type, SymbolicEngine& _engine)
    	: definitionId(nextDefinitionId++), address(_engine.getNextAddress()), m_definitionType(_type), engine(_engine), csExpr(nullptr) {}

    Definition::Definition(columbus::NodeId _type, SymbolicEngine& _engine, ConstraintSolverExpr* csExpr)
        : definitionId(nextDefinitionId++), address(_engine.getNextAddress()), m_definitionType(_type), engine(_engine), csExpr(csExpr) {}


		  
    Definition::Definition(columbus::NodeId _type, const Address& _address, SymbolicEngine& _engine)
    	: definitionId(nextDefinitionId++), address(_address), m_definitionType(_type), engine(_engine), csExpr(nullptr) {}


    Definition::~Definition() {
        for (ConstraintSet::iterator it = gatherdDependencies.begin(); it != gatherdDependencies.end(); ++it) {
            delete* it;
        }
    }

}}
