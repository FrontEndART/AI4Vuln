#ifndef _ASGNODEPrinter_H
#define _ASGNODEPrinter_H

#include <common/inc/StringSup.h>

namespace columbus {  namespace cfg {

    /**
     * \brief Converter class, which default converts an ASG NodeId to a string. It can also be inherited and override toString method to convert to something else. 
     */
    class ASGNodePrinter {
    public: 
        ASGNodePrinter() {}
        virtual const std::string toString (const NodeId id) const{
            return common::toString(id);
        }

        virtual ~ASGNodePrinter() {}
    };
}}

#endif