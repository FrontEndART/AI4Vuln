#ifndef _SYMBOLIC_ENGINE_INTERFACE_H_
#define _SYMBOLIC_ENGINE_INTERFACE_H_

#include "../structure/SymbolicCommon.h"

namespace columbus { namespace symbolic {

    class SymbolicEngineInterface {
    public:
        SymbolicEngineInterface() {}
        virtual ~SymbolicEngineInterface() {}
        virtual SmartDefinition getNullReferenceValueDefinition() const { return SmartDefinition(); }
        virtual bool getBooleanValueDefinitionValue(SmartDefinition definition) const { return false; }
    };

}}

#endif
