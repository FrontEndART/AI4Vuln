#include "../../inc/common.h"

namespace columbus { namespace symbolic {

unsigned long SymbolIdentifier::nextId = 0;

SymbolIdentifier::SymbolIdentifier() : id(nextId++) {
}

SymbolIdentifier::~SymbolIdentifier() {
}

}}

