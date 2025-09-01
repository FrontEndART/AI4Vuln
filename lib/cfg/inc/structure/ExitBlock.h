#ifndef _EXITBLOCK_H
#define _EXITBLOCK_H

#include "BasicBlock.h"

#define EXIT_BLOCK_ID 2

namespace columbus {  namespace cfg {

    /**
     * \brief The exit point of an ICFG, from there are no more control out edge(s) to anothor block(s). 
     */
    class ExitBlock : public BasicBlock{
    public:
        ExitBlock(ICFG *parent);
    };
}}

#endif