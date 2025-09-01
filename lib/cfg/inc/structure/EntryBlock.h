#ifndef _ENTRYBLOCK_H
#define _ENTRYBLOCK_H

#include "BasicBlock.h"

#define ENTRY_BLOCK_ID 1

namespace columbus {  namespace cfg {

    /**
     * \brief The entry point of an ICFG, to there are no control in edge(s) from anothor block(s).
     */
    class EntryBlock : public BasicBlock{
    public:
        EntryBlock(ICFG *parent);
    };

}}

#endif