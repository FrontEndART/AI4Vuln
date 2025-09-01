#include "../../inc/common.h"


namespace columbus { namespace symbolic {


    ConstraintBuilder::ConstraintBuilder() {
    }

    ConstraintBuilder::~ConstraintBuilder(void) {
    }

    void ConstraintBuilder::setSymbolicEngine(SymbolicEngine* eng) {
        engine = eng;
    }


}}

