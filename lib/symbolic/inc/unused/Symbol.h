#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include "../definition/Definition.h"

namespace columbus { namespace symbolic {

    class Symbol : public Definition {
    };

    class BoolSymbol : public Symbol {
    };

    class NumericSymbol : public Symbol {
    };

    class StringSymbol : public Symbol {
    };

    class ReferenceSymbol : public Symbol {
    };

}}

#endif
