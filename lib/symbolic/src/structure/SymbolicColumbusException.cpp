#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    SymbolicColumbusException::SymbolicColumbusException(const char* _message) throw() : exception(), message(_message) {
    }

    SymbolicColumbusException::SymbolicColumbusException(const std::string _message) throw() : exception(), message(_message) {
    }

    SymbolicColumbusException::SymbolicColumbusException(const SymbolicColumbusException& def) : message(def.message) {
    }

    SymbolicColumbusException::~SymbolicColumbusException() throw() {
    }

    const char* SymbolicColumbusException::what() const throw() {
        return message.c_str();
    }

}
}

