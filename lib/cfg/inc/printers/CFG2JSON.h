#ifndef CG2JSON_H
#define	CG2JSON_H

#include "cfg/inc/cfg.h"
#include <fstream>

namespace columbus {  namespace cfg {

    class CFG2JSON {
      public:
        
        struct EdgeData {
            std::string from;
            std::string to;
            std::string label;
            bool exceptional;
        };

        void dump( const CFGFactory& cfgFactory, std::ofstream& out );

      private:

        std::string t( int num ) const;
        void collectEdges( BasicBlock::EdgesConstIterator iterator, std::vector<EdgeData>& container );
        void dumpEdges( const std::vector<EdgeData>& edges, std::ofstream& out ) const;

        std::vector<EdgeData> controlEdges;
        std::vector<EdgeData> callEdges;
    };

}}


#endif