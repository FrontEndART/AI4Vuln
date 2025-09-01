#ifndef _ALGORITHMPATHFINDER_H
#define _ALGORITHMPATHFINDER_H

/**
 * \file AlgorithmPathFinder.h
 * \brief Contains the class `AlgorithmPathFinder' which implements algorithms for finding def/use pathes from source nodes to target nodes without any checking of the source nodes
 */

#include "cfg/inc/cfg.h"
#include <set>
#include <vector>
#include <map>
#include <ctime>


namespace columbus { namespace cfg {
        class AlgorithmPathFinder {
        public:

            typedef std::vector<std::pair<columbus::NodeId, int> > NodeIdIntPairVector;
             
            class WarningListener {
            public:
                virtual void addWarning(columbus::NodeId, const NodeIdIntPairVector& warningTextParams = NodeIdIntPairVector()) = 0;
                virtual ~WarningListener() {}
            };

        protected:
            CFGFactory *cfgFactory;
            AlgorithmCompare *algCompare;

            std::set<columbus::NodeId> *targetNodes;
            const std::set<columbus::NodeId> *sourceNodes;

            std::vector<const columbus::cfg::BasicBlock*> callStack;

            bool findAllPath;
            bool findAllTarget;
            int depthLimit;
            int exitBlockEdgeIterLimit;

            std::set<WarningListener*> warningListeners;


            void addWarning(columbus::NodeId, const NodeIdIntPairVector& warningTextParams = NodeIdIntPairVector());

            std::set<columbus::NodeId> definitions;
            
            
            typedef std::set<const columbus::cfg::BasicBlock*> BBSet;
            typedef struct { 
              bool onPath; 
              bool targetOnPath;
              bool target;
              int  distance;
            } BasicBlockExtraFlags;
            
            typedef struct PrefilterInfo {
              unsigned long long prefilterCounter;
              NodeId sourceNodeId;
              BBSet targetOnPathSet;
              
              bool operator<(const struct PrefilterInfo& b) const { return prefilterCounter < b.prefilterCounter; }
            } PrefilterInfo;
            
            typedef std::map<const columbus::cfg::BasicBlock*, BasicBlockExtraFlags> BBExtraFlagsMap;
            typedef std::map<const columbus::cfg::BasicBlock*, std::set<const columbus::cfg::BasicBlock*> > BBSetMap;
            typedef std::list<PrefilterInfo> PrefilterInfoList;
            BBExtraFlagsMap bbExtraFlagsMap;
            PrefilterInfoList prefilterInfo;
            BBSetMap entryBlockInvocationPlaceMap;
            const BBSet* currentTargetOnPathSet;
            
            
            std::map<const columbus::cfg::BasicBlock*, std::set <columbus::NodeId> > definitionsOfBlocks;
            std::map<const columbus::cfg::BasicBlock*, std::set <columbus::NodeId> > erasedDefinitionsOfBlocks;
            columbus::NodeId actualSource;
            NodeIdIntPairVector pathInfo;

            std::size_t pushPathInformation();
            std::size_t popPathInformation(size_t size);
            void addPathInformation(columbus::NodeId, int callStackDepth);

            void addDefinitionsForBlock(const columbus::cfg::BasicBlock*, columbus::NodeId);
            void addErasedDefinitionsForBlock(const columbus::cfg::BasicBlock*, columbus::NodeId);
            bool isDefinitionOfBlock(const columbus::cfg::BasicBlock*, columbus::NodeId);
            void backTrackFromBlock(const columbus::cfg::BasicBlock*);

            bool traverseNodes(const columbus::cfg::BasicBlock*, columbus::cfg::BasicBlock::NodesConstIterator&, std::set<columbus::NodeId>&, bool*, bool*, int, int callStackDepth);
            bool traverseNextBlocks(const columbus::cfg::BasicBlock*, std::set<const columbus::cfg::BasicBlock*>*, std::vector<const columbus::cfg::BasicBlock*>&, int distance, int callStackDepth);
            bool analyzeNextBlock(const columbus::cfg::BasicBlock*, std::set<const columbus::cfg::BasicBlock*>*, std::vector<const columbus::cfg::BasicBlock*>&, int distance, int callStackDepth);

            std::map<std::pair<NodeId, NodeId>, columbus::cfg::DUInfoCompareResultType> compareSet;
            columbus::cfg::DUInfoCompareResultType compare(columbus::NodeId, columbus::NodeId);
            bool compareOperationInfo(columbus::NodeId, std::set<NodeId>* visitedOpInfo = NULL);

            bool usePrefilter;
            bool prefilterCFG(const cfg::BasicBlock* bb, std::vector<const cfg::BasicBlock*>& returnStack, int depth);
            unsigned long long prefilterCounter;
            
            void findPath();
            
            time_t timeout;
            bool timeoutReached;
            unsigned checkedSources;
            
        public:
            AlgorithmPathFinder() : 
               cfgFactory(NULL), 
               algCompare(NULL), 
               targetNodes(NULL), 
               sourceNodes(NULL), 
               findAllPath(true), 
               findAllTarget(true), 
               depthLimit(60), 
               definitions(), 
               currentTargetOnPathSet(NULL),
               definitionsOfBlocks(), 
               erasedDefinitionsOfBlocks(), 
               actualSource(0), 
               pathInfo(), 
               compareSet(),
               usePrefilter(true),
               prefilterCounter(0),
               timeout(0),
               timeoutReached(false),
               checkedSources(0) {}

            virtual ~AlgorithmPathFinder() {
                if (targetNodes)
                    delete targetNodes;
            }

            void setTargets(std::set<columbus::NodeId> *t) {
                if (targetNodes)
                    delete targetNodes;
                targetNodes = new std::set<columbus::NodeId>();
                std::set<columbus::NodeId>::const_iterator iter = t->begin();
                for ( ;iter != t->end(); ++iter)
                    targetNodes->insert(*iter);
            }

            void setSources(std::set<columbus::NodeId> *s) {
                sourceNodes = s;
            }

            virtual bool checkUse(columbus::NodeId) = 0;

            void findPaths();

            void setExitBlockEdgeIterLimit(int limit) {exitBlockEdgeIterLimit = limit;}
            void setAllPathFlag(bool flag) {findAllPath = flag;}
            void setAllTargetFlag(bool flag) {findAllTarget = flag;}
            void setDepthLimit(int limit) {depthLimit = limit;}
            void setUsePrefilter(bool flag) { usePrefilter = flag; }
            
            void setTimeout(time_t timeout) { 
              this->timeout =  timeout; 
              if (timeout != 0) 
                 timeoutReached = difftime(timeout, time(NULL)) < 0.0;  
            }
            
            void getPathFindStatus(bool& timeoutReached, unsigned& checkedSources) const {
              timeoutReached = this->timeoutReached;
              checkedSources = this->checkedSources;
            }
            
            
            virtual void printCFG2Graph(std::string) = 0;

            void addWarningListener(WarningListener* l) {warningListeners.insert(l);}
            void removeWarningListener(WarningListener* l) {warningListeners.erase(l);}
        };
}}

#endif
