#ifndef _ALGORITHM_CG_COMPARE_H
#define _ALGORITHM_CG_COMPARE_H

/**
 * \file AlgorithmCGCompare.h
 * \brief Contains the class `CGCompare' which implements algorithms for comparing DUInfos according to the Constraint Graph.
 */

#include "cfg/inc/cfg.h"

namespace columbus {
    namespace cfg {

        /** \brief Type definition for ALOC container. */
        typedef std::map<unsigned int, std::vector<unsigned int> > ALOCContainer;

        class AlgorithmCGCompare : public columbus::cfg::AlgorithmCompare {
        protected:
            /** \brief CG Factory. */
            columbus::cfg::CGFactory *m_cgFactory;

            /** \brief It stores the calculated alocs for a node. For speeding up. */
            ALOCContainer m_ALOCForNode;

        public:
            /**
             * \brief Constructor.
             * \param cfgFactory [in] The CFG Factory.
             * \param cgFactory  [in] The CG Factory.
             */
            AlgorithmCGCompare(const columbus::cfg::CFGFactory& cfgFactory, columbus::cfg::CGFactory& cgFactory);

            /** \brief Copy constructor. */
            AlgorithmCGCompare(const AlgorithmCGCompare& orig);

            /** \brief Destructor. */
            virtual ~AlgorithmCGCompare();

            /** \brief Assignment operator. */
            AlgorithmCGCompare operator=(const AlgorithmCGCompare&);

            /**
             * \brief The Compare mehtod. It compares two DUInfo object.
             * \param nodeIdLeft  [in] The left-side DUInfo belongs to nodeIdLeft.
             * \param nodeIdRight [in] The right-side DUInfo belongs to nodeIdRight.
             * \param compareType [in] Type of compare (with or without addressSelector).
             * \return One of the following: same Address, maybe Address, different Address.
             */
            virtual columbus::cfg::DUInfoCompareResultType compare(const columbus::NodeId nodeIdLeft, const columbus::NodeId nodeIdRight, const columbus::cfg::DUInfoCompareType compareType = columbus::cfg::duCompareWithoutFieldAccess);

            void getClassCGNodes(columbus::NodeId nodeId, std::vector<columbus::NodeId>& classs);

        private:

            /**
             * \brief Finds the ALOCs accessible from a CG Node through constraint edges.
             * \param fromNode     [in] The CG Node.
             * \param alocs       [out] The ALOCs.
             * \param visited  [in/out] The visited CG node ids.
             */
            void findAccessibleALOCs(const columbus::cfg::CGNode& fromNode, std::vector<unsigned int>& alocs, std::vector<unsigned int>& visited);

            /**
             * \brief Create an intersection for the given vectors.
             * \param alocs1         [in] The first vector.
             * \param alocs2         [in] The second vector.
             * \param intersection  [out] The intersection.
             */
            void generateIntersection(std::vector<unsigned int>& alocs1, std::vector<unsigned int>& alocs2, std::vector<unsigned int>& intersection) const;

            /**
             * \brief Create an intersection for the given edges.
             * \param alocs1         [in] The first edge container.
             * \param alocs2         [in] The second edge container.
             * \param intersection  [out] The intersection.
             */
            void generateEdgeIntersection(columbus::cfg::CGEdgeContainer& edges1, columbus::cfg::CGEdgeContainer& edges2, std::vector<unsigned int>& intersection) const;

            /**
             * \brief Create an intersection for the given CGNode's member-edges and the overlap-edges.
             * \param CGNode         [in] The CGNode.
             * \param overlaps         [in] The overlap edges.
             * \param intersection  [out] The intersection of CGNode's member-edges-targets and overlap-edges targets.
             */
            void generateNodesIntersection(const columbus::cfg::CGNode& CGNode, const columbus::cfg::CGEdgeContainer& overlaps, std::vector<unsigned int>& intersection) const;

            /**
             * \brief It decides if the first parameter contains all of the elements of alocs2.
             * \param alocs1   [in] The first vector.
             * \param alocs2   [in] The second vector.
             * \return True if alocs1 contains aloc2, otherwise false.
             */
            bool isSubset(std::vector<unsigned int>& alocs1, std::vector<unsigned int>& alocs2) const;

            /**
             * \brief It gets the next selector from the CG to the given node in the given depth.
             * The CG contains overlap and member-constraint edges. The result will be these two edges intersection.
             * \param nodeId     [in] The nodeId.
             * \param selectors [out] The next selectors.
             * \param depth      [in] The selector's depth.
             */
            void getNextSelectorsFromCG(const columbus::NodeId nodeId, std::vector<columbus::NodeId>& selectors, const unsigned int depth) const;

            /**
             * \brief Helper function for the base compare method. It compares two CGNodes.
             * \param leftCGNode  [in] The first CGNode.
             * \param rightCGNode [in] The another CGNode.
             * \return The compare result.
             */
            columbus::cfg::DUInfoCompareResultType compareInCG(const columbus::cfg::CGNode& leftCGNode, const columbus::cfg::CGNode& rightCGNode);

            /**
             * \brief Helper function for the base compare method. It compares two nodeIDs.
             * \param nodeIdLeft  [in] The first CGNode.
             * \param nodeIdRight [in] The another CGNode.
             * \param compareType [in] Type of compare (with or without addressSelector).
             * \return The compare result.
             */
            columbus::cfg::DUInfoCompareResultType compareNodeIDs(const columbus::NodeId nodeIdLeft, const columbus::NodeId nodeIdRight, const columbus::cfg::DUInfoCompareType compareType = columbus::cfg::duCompareWithoutFieldAccess);

            /**
             * \brief It gets the base descriptor (the most deeper descriptor) of a given DUInfo.
             * \param nodeId     [in] The nodeId.
             * \return The base descriptor.
             */
            columbus::NodeId getBaseDescriptor(const columbus::NodeId nodeId) const;

            /**
             * \brief It gets the next selector from the DUInfo in the given depth.
             * \param nodeId     [in] The nodeId.
             * \param depth      [in] The selector's depth.
             * \return The next selector in the given depth.
             */
            columbus::NodeId getNextSelector(const columbus::NodeId nodeId, const unsigned int depth) const;

            /**
             * \brief It decides if the given node belongs to an array or not. If yes, gives back its selector.
             * \param nodeId     [in] The nodeId.
             * \param selector  [out] The pointer to array's selector.
             * \return True if the nodeId belongs to an array (for example an ArrayAccess), otherwise false.
             */
            bool isArraySpecial(const columbus::NodeId nodeId, columbus::NodeId *selector) const;

            /**
             * \brief It decides if the given CGnode is static or not.
             * \param nodeId     [in] The nodeId.
             * \return True if CGNode is static, otherwise false.
             */
            bool isNodeStatic(const columbus::NodeId nodeId) const;

            /**
             * \brief It makes a node searching. The starting point the fromNode, and try to find the findNode on all routes starting from fromNode (through constrain edges).
             * \param fromNode           [in] The starting node.
             * \param toNode             [in] The node for find.
             * \param visitedNodes   [in/out] The visited nodes (for preventing circulation).
             * \return True if the findNode was found on all routes from fromNode through constraint edges, otherwise false. If one the route doesn't contains findNode it returns false.
             */
            bool findCGNodeOnRoute(const columbus::cfg::CGNode& fromNode, const columbus::cfg::CGNode& findNode, std::vector<unsigned int>& visitedNodes) const;

            /**
             * \brief It gets the next selectors from the nodeId from the given depth, from the CG.
             * If the expression is complex, get the next selector, backwards from descriptor. Else try to find from the CG with the help of
             * overlap and member constraint edges.
             * \param nodeId           [in] The nodeId.
             * \param isComplex        [in] Is the node a complex expression (for example. a.b)?
             * \param depth            [in] The selector's depth.
             * \param nextSelectors   [out] The next selectors.
             */
            void getNextSelecotrs(const columbus::NodeId nodeId, bool isComplex, unsigned int depth, std::vector<columbus::NodeId>& nextSelectors) const;

            bool isComplex(const columbus::NodeId nodeId, columbus::NodeId *selector = NULL, columbus::NodeId *descriptor = NULL) const;

            bool findClassForALOC(columbus::cfg::CGNode& aloc, unsigned int *classCG) const;

        };

    }
}
#endif  /* ALGORITHMCGCOMPARE_H */
