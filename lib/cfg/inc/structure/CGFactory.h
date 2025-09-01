#ifndef CG_H
#define	CG_H

/**
 * \file CGFactory.h
 * \brief Contains declaration of Constraint Grap (CG) class for PointerAnalysis.
 */

#include "cfg/inc/cfg.h"

namespace columbus {
    namespace cfg {

        /** \brief Enumeration type for node types */
        typedef enum {
            cgAbstractLocation, cgVariable, cgClassSpecial, cgArraySpecial
        } CGNodeType;

        /** \brief Enumeration type for edge types */
        typedef enum {
            cgConstraintEdge, cgOverlapConstraintEdge, cgMemberConstraintEdge
        } CGEdgeType;

        /** \brief Type definition for edge container */
        typedef std::vector<columbus::NodeId> CGEdgeContainer;

        /**
         * \brief CGNode class.
         * This class represents a node in the CG. It stores the edges from.
         */
        class CGNode {
            friend class CGFactory;
        private:
            /** \brief nodeId which identifies a graph node inside the CG. */
            columbus::NodeId m_nodeId;

            /** \brief The type of the node. */
            CGNodeType m_nodeType;

            /** \brief The constraint edges from the current node. */
            CGEdgeContainer m_constraintEdges;

            /** \brief The overlap constraint edges from the current node. */
            CGEdgeContainer m_overlapConstraintEdges;

            /** \brief The member constraint edges from the current node. */
            CGEdgeContainer m_memberConstraintEdges;

            /** \brief Unique identifier for CGNodes. */
            unsigned int m_cgId;

            /** \brief CGNode is static? */
            bool m_isStatic;

        public:
            /**
             * \brief Constructor.
             * \param nodeType  [in] type of CG-node.
             * \param nodeId    [in] nodeId of CG-node.
             */
            CGNode(const CGNodeType nodeType, const columbus::NodeId nodeId, const unsigned int cgid);

            /**
             * \brief Copy constructor.
             */
            CGNode(const CGNode& orig);

            /**
             * \brief operator "=" overloading.
             */
            CGNode& operator=(const CGNode& node);

            /**
             * \brief Destructor.
             */
            virtual ~CGNode();

            /**
             * \brief Gives back the nodeId of CG-node.
             * \return The nodeId.
             */
            const columbus::NodeId getNodeId() const;

            /**
             * \brief Gives back the CG ID of CG-node.
             * \return The CG ID.
             */
            const unsigned int getId() const;

            /**
             * \brief Gives back the type of CG-node.
             * \return The node type.
             */
            const CGNodeType getNodeType() const;

            std::string toString() const;

            /**
             * \brief Gives back the constraint edges.
             * \return The constraint edges.
             */
            const CGEdgeContainer& getConstraintEdges() const {
                return m_constraintEdges;
            }

            /**
             * \brief Gives back the overlap constraint edges.
             * \return The overlap constraint edges.
             */
            const CGEdgeContainer& getOverlapConstraintEdges() const {
                return m_overlapConstraintEdges;
            }

            /**
             * \brief Gives back the member constraint edges.
             * \return The member constraint edges.
             */
            const CGEdgeContainer& getMemberConstraintEdges() const {
                return m_memberConstraintEdges;
            }

            /**
             * \brief Set the CGNode's static property.
             * \param isStatic [in] Is the CGNode static or not.
             */
            void setIsStatic(bool isStatic);

            /**
             * \brief Gives back if the CGNode belongs to a static node.
             * \return The CGNode is static or not?
             */
            bool getIsStatic() const;
        };

        /** \brief Type definition for node container. */
        typedef std::vector<CGNode*> CGNodeContainer;

        /**
         * \brief CGFactory class.
         * This class stores the nodes of the CG. It creates new nodes and edges.
         */
        class CGFactory {
        public:
            /**
             * \brief Constructor.
             */
            CGFactory();

            /**
             * \brief Copy constructor.
             */
            CGFactory(const CGFactory& orig);

            /**
             * \brief operator "=" overloading.
             */
            CGFactory& operator=(const CGFactory& node);

            /**
             * \brief Destructor.
             */
            virtual ~CGFactory();

            /**
             * \brief Creates a new node with the given nodeId and stores it in the node container.
             * \param nodeType  [in] The type of the node.
             * \param nodeId    [in] The nodeId.
             * \return Reference to the created node.
             */
            CGNode& createNode(const CGNodeType nodeType, columbus::NodeId nodeId = 0);

            /**
             * \brief Creates a new edge and stores it in the edge container of the node.
             * \param edgeType [in] The type of the edge.
             * \param fromNode [in] Source nodeId of edge.
             * \param toNode   [in] Target nodeId of edge.
             * \param nodeType  [in] The type of the source node.
             * \param nodeType  [in] The type of the target node.
             */
            void createEdge(const CGEdgeType edgeType, const columbus::NodeId fromNode, const columbus::NodeId toNode, const CGNodeType sourceNodeType, const CGNodeType targetNodeType);

            /**
             * \brief Creates a new edge and stores it in the edge container of the node.
             * \param edgeType [in] The type of the edge.
             * \param fromNode [in] Source node of edge.
             * \param toNode   [in] Target node of edge.
             */
            void createEdge(const CGEdgeType edgeType, CGNode& fromNode, const CGNode& toNode);

            /**
             * \brief Gives back constraint edge container of the given nodeId.
             * \param forNode [in] nodeId.
             * \param nodeType  [in] The type of the node.
             * \return The constraint edge container.
             */
            const CGEdgeContainer& getConstraintEdges(const columbus::NodeId forNode, const CGNodeType nodeType = cgVariable);

            /**
             * \brief Gives back constraint edge container of the given nodeId.
             * \param forNode [in] CGNode.
             * \return The constraint edge container.
             */
            const CGEdgeContainer& getConstraintEdges(const CGNode& forNode);

            /**
             * \brief Gives back overlap constraint edge container of the given nodeId.
             * \param forNode   [in] nodeId.
             * \param nodeType  [in] The type of the node.
             * \return The overlap constraint edge container.
             */
            const CGEdgeContainer& getOverlapConstraintEdges(const columbus::NodeId forNode, const CGNodeType nodeType = cgVariable);

            /**
             * \brief Gives back overlap constraint edge container of the given nodeId.
             * \param forNode   [in] CGNode.
             * \param nodeType  [in] The type of the node.
             * \return The overlap constraint edge container.
             */
            const CGEdgeContainer& getOverlapConstraintEdges(const CGNode& forNode);

            /**
             * \brief Gives back member constraint edge container of the given nodeId.
             * \param forNode   [in] nodeId.
             * \param nodeType  [in] The type of the node.
             * \return The member constraint edge container.
             */
            const CGEdgeContainer& getMemberConstraintEdges(const columbus::NodeId forNode, const CGNodeType nodeType = cgVariable);

            /**
             * \brief Gives back member constraint edge container of the given nodeId.
             * \param forNode [in] CGNode.
             * \return The member constraint edge container.
             */
            const CGEdgeContainer& getMemberConstraintEdges(const CGNode& forNode);

            /**
             * \brief Gives back a node for the given nodeId.
             * \param nodeId    [in] CGNode.
             * \param nodeType  [in] The type of the node.
             * \return Reference to the node.
             */
            CGNode& getNode(const columbus::NodeId nodeId, const CGNodeType nodeType = cgVariable);

            /**
             * \brief Gives back a node for the given CGId.
             * \param cgId    [in] CG id.
             * \return Pointer to the node.
             */
            CGNode* getNodeFromCGId(const unsigned int cgId) const;

            /**
             * \brief Gives back the node container of the CG.
             * \return Reference to the container.
             */
            const CGNodeContainer& getNodes() const;

            /**
             * \brief Gives back the UNKNOWN node.
             * \return Reference to the UNKNOWN node.
             */
            const CGNode& getUNKNOWNode() const;

            /**
             * \brief It decides if a node is already exists in the CG.
             * \param nodeId    [in]  The nodeId.
             * \param nodeType  [in]  The type of the node.
             * \return True if exists otherwise false.
             */
            bool isExistsNode(const columbus::NodeId nodeId, const CGNodeType nodeType = cgVariable) const {
                unsigned int i = 0;
                return isExistsNode(nodeId, nodeType, &i);
            }

            /**
             * \brief It decides if a CG ID is already exists in the CG.
             * \param cgId    [in]  The nodeId.
             * \return True if exists otherwise false.
             */
            bool isExistsCGId(const unsigned int cgId) const {
                return cgId < m_nodes.size();
            }

            void textDumpCG() const;

        private:
            /** \brief Mapping for CGId to m_nodes index, for speeding up. */
            std::map<unsigned int, unsigned int> m_CGIdMapping;

            /** \brief Mapping for NodeId and NodeType to m_nodes index, for speeding up. */
            std::map<std::pair<columbus::NodeId, CGNodeType>, unsigned int> m_nodeIdMapping;

            /** \brief A counter for unique identifing the CGNodes. */
            unsigned int m_cgId;

            /** \brief The container which holds the nodes of the CG. */
            CGNodeContainer m_nodes;

            /** \brief The UNKNOWN node with nodeId 0. */
            CGNode *m_UNKNOWNNode;

            /**
             * \brief It decides if a node is already exists in the CG.
             * \param nodeId    [in]  The nodeId.
             * \param nodeType  [in]  The type of the node.
             * \param index     [out] The index in nodes container, which holds the CGNode.
             * \return True if exists otherwise false.
             */
            bool isExistsNode(const columbus::NodeId nodeId, const CGNodeType nodeType, unsigned int *index) const;
        };
    }
}

#endif
