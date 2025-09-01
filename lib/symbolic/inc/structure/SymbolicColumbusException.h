#ifndef _SYMBOLIC_COLUMBUS_EXCEPTION_H_
#define _SYMBOLIC_COLUMBUS_EXCEPTION_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class SymbolicColumbusException: public std::exception {
    public:
        SymbolicColumbusException(const char*) throw();
        SymbolicColumbusException(const std::string) throw();
        SymbolicColumbusException(const SymbolicColumbusException& def);
        virtual ~SymbolicColumbusException() throw();
        SymbolicColumbusException& operator=(const SymbolicColumbusException&) const;
        virtual const char* what() const throw();

    private:
        std::string message;
    };

}}

#endif
