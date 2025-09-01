#ifndef _ALGORITHM_DEF_USE_CHAINS_H
#define _ALGORITHM_DEF_USE_CHAINS_H

/**
 * \file AlgorithmDefUseChains.h
 * \brief Contains the class `AlgorithmDefUseChains' which implements algorithms for searching definitions.
 */

#include "cfg/inc/cfg.h"
#include <limits>

namespace columbus {
    namespace cfg {

        class AlgorithmDefUseChains {
        protected:
            /** \brief CFG Factory. */
            const columbus::cfg::CFGFactory* m_cfgFactory;

            /** \brief The Compare class. */
            columbus::cfg::AlgorithmCompare* m_compareClass;

            /** \brief The printer class. */
            const columbus::cfg::ASGNodePrinter* m_printer;

            /**
             * \brief This is the search function for the definition.
             *        It searches for definition for the given DUInfo.
             * \param searchDefinitionForNode [in]  The given DUInfo.
             * \param resultSet               [out] A container contains the nodes which define searchDU.
             * \param fullVisitedBlocks       [in/out] Container to store the full visited blocks per nodeId.
             * \param partVisitedBlocks       [in/out] Container to store the partially visited blocks per nodeId.
             * \param notFoundSet             [out] Set contains nodeIds, for which has no definition was found.
             * \param searchDepth             [in]  The searching depth.
             * \param currentDepth            [in]  The current depth.
             * \param cumulateDefinitions     [in]  ResultSet should contain definitions from 0. depth to searchDepth.
             * \return True if at least one definition is found, otherwise false.
             */
            virtual bool findDefinitionForNode(const columbus::NodeId searchDefinitionForNode, std::set<columbus::NodeId>& resultSet, std::map<columbus::NodeId, std::set<unsigned int> >& fullVisitedBlocks, std::map<columbus::NodeId, std::set<unsigned int> >& partVisitedBlocks, std::set<columbus::NodeId> *notFoundSet = NULL, const unsigned int searchDepth = std::numeric_limits<unsigned int>::max(), const unsigned int currentDepth = 0, const bool cumulateDefinitions = true) const;

        public:

            /**
             * \brief Constructor.
             * \param cfgFactory   [in] The CFG Factory.
             * \param printer      [in] The Printer class.
             */
            AlgorithmDefUseChains(const columbus::cfg::CFGFactory& cfgFactory, const columbus::cfg::ASGNodePrinter& printer);

            /**
             * \brief Constructor.
             * \param cfgFactory   [in] The CFG Factory.
             */
            AlgorithmDefUseChains(const columbus::cfg::CFGFactory& cfgFactory);

            /** \brief Destructor. */
            virtual ~AlgorithmDefUseChains();

            /** \brief Copy constructor. */
            AlgorithmDefUseChains(const AlgorithmDefUseChains&);

            /** \brief Assignment operator. */
            AlgorithmDefUseChains operator=(const AlgorithmDefUseChains&);

            /**
             * \brief This is the search function for the definition.
             *        It searches for definition for the given DUInfo.
             * \param searchDefinitionForNode [in]  The given DUInfo.
             * \param resultSet               [out] A container contains the nodes which define searchDU.
             * \param searchDepth             [in]  The searching depth.
             * \param cumulateDefinitions     [in]  ResultSet should contain definitions from 0. depth to searchDepth.
             * \param notFoundSet             [out] Set contains nodeIds, for which has no definition was found.
             * \return True if at least one definition is found, otherwise false.
             */
            virtual bool findDefinitionForNode(const columbus::NodeId searchDefinitionForNode, std::set<columbus::NodeId>& resultSet, const unsigned int searchDepth = std::numeric_limits<unsigned int>::max(), const bool cumulateDefinitions = true, std::set<columbus::NodeId> *notFoundSet = NULL) const {
                std::map<columbus::NodeId, std::set<unsigned int> > fullVisit;
                std::map<columbus::NodeId, std::set<unsigned int> > partVisit;
                return findDefinitionForNode(searchDefinitionForNode, resultSet, fullVisit, partVisit, notFoundSet, searchDepth, 0, cumulateDefinitions);
            }

            /**
             * \brief It searches definitions in the given BasicBlock id, in the given ICFG id.
             * \param blockId    [in]  The BasicBlock id.
             * \param icfgID     [in]  The ICFG id.
             * \param resultSet  [out] A container contains the nodes which define searchDU.
             * \return True if at least a definition is found.
             */
            virtual bool findDefinitionsInBasicBlock(const unsigned int blockId, const columbus::cfg::ICFGid icfgID, std::set<columbus::NodeId>& resultSet) const;

            /**
             * \brief It checks, if the definition takes place before the use.
             * \param definition [in] nodeId of definition.
             * \param use        [in] nodeId of use.
             * \return True if the definition takes place before the use, otherwise false.
             */
            bool isDefinitionBeforeTheUse(const columbus::NodeId definition, const columbus::NodeId use) const;

            /**
             * \brief It checks, if the first node takes place before the second node in the CFG.
             * \param firstNode  [in] first nodeId.
             * \param secondNode [in] second nodeId.
             * \return True if the first node takes place before the second one, otherwise false.
             */
            bool isFirstNodeBeforeTheSecond(const columbus::NodeId firstNode, const columbus::NodeId secondNode) const;

            /**
             * \brief It checks, if the nodeId is inside the CFG.
             * \param nodeId [in] nodeId of the DUInfo.
             * \return True if the nodeId is inside the CFG, otherwise false.
             */
            bool isNodeInTheCFG(const columbus::NodeId nodeId) const;

            /**
             * \brief It gets the compare class.
             * \return The Compare class.
             */
            inline columbus::cfg::AlgorithmCompare* getCompareClass() const {
                return m_compareClass;
            }
        };
    }
}

#endif
