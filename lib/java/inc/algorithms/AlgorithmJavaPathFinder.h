#ifndef _ALGORITHMJAVAPATHFINDER_H
#define _ALGORITHMJAVAPATHFINDER_H

/*! \file AlgorithmJavaPathFinder.h
    \brief Implements the language dependent part of the columbus::cfg::AlgorithmPathFinder algorithm.
*/
#include  <string>

namespace columbus { namespace java { namespace asg {
    class AlgorithmJavaPathFinder : public columbus::cfg::AlgorithmPathFinder {
        protected:
            const Factory& javaFact;
            columbus::cfg::CGFactory cgFactory;
            bool deleteMemberPointers;
            
        public:
            AlgorithmJavaPathFinder(Factory&);
            AlgorithmJavaPathFinder(Factory&, columbus::cfg::CFGFactory *, columbus::cfg::AlgorithmCompare *);
            virtual ~AlgorithmJavaPathFinder();
            virtual bool checkUse(columbus::NodeId);
            virtual void printCFG2Graph(std::string);
    };
}}}

#endif