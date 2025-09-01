#ifndef _BASICBLOCK_H
#define _BASICBLOCK_H

#include "cfg/inc/cfg.h"

#define STATEMENT_BORDER_ID 3

namespace columbus {  namespace cfg {

    class CFGFactory;
    class ICFG;
    class Edge;

    /**
     * \brief Class template for the EdgeContainer less compare operator, with overloaded function call operator. 
     */
    template<class EdgeType, class BasicBlockType>
    class EdgeLess {
    public:
        bool operator()(const EdgeType* left, const EdgeType* right) const {
            if(left != 0 && right != 0){
                const BasicBlockType* leftBlock = left->getTo();
                const BasicBlockType* rightBlock = right->getTo();

                if (leftBlock == rightBlock) {
                    leftBlock = left->getFrom();
                    rightBlock = right->getFrom();
                }

                if(leftBlock != 0 && rightBlock != 0){
                    const unsigned int leftId = leftBlock->getBlockId();
                    const unsigned int rightId = rightBlock->getBlockId();

                    if(leftId != rightId)
                        return leftId < rightId;
                    else
                        return leftBlock->getParent()->getMethodId() < rightBlock->getParent()->getMethodId();
                }

            }
            return false;
        } 
    };

    /**
     * \brief Type definition to store NodeIds. 
     */
    typedef std::vector<NodeId> NodeContainer;

    class BasicBlock {
        friend class Edge;

        /**
         * \brief Type definition to store Edge pointers. 
         */
        typedef std::vector<Edge*> EdgeContainer;
    private:
        /**
         * \brief The block Id for the BasicBlock. 
         */
        unsigned int blockId;

        /**
         * \brief Storage for the node Ids. 
         */
        NodeContainer nodes;

        /**
         * \brief Storage for control type In edge pointers. 
         */
        EdgeContainer controlInEdges;

        /**
         * \brief Storage for control type Out edge pointers. 
         */
        EdgeContainer controlOutEdges;

        /**
         * \brief Storage for call type In edge pointers. 
         */
        EdgeContainer callInEdges;

        /**
         * \brief Storage for call type Out edge pointers. 
         */
        EdgeContainer callOutEdges;

        /**
         * \brief Pointer of the parent ICFG. 
         */
        ICFG *parent;

        /**
         * \brief Bool attribute to indicate, that the Block is static or not. 
         */
        bool isStaticInit;
    public:

        /**
         * \internal
         * \brief Constructor that sets the blockId with the given parameter.
         * \param id           [in] The block Id that indexes a BasicBlock in the container.
         */
        BasicBlock(ICFG *parent, const unsigned int id);

        /**
         * \brief Destructor, that will delete all edge pointers in all containers and than clears edge containers.
         */
        virtual ~BasicBlock();
        
        BasicBlock(const BasicBlock&);
        
        BasicBlock& operator=(const BasicBlock& basicBlock);

        /**
         * \brief Gives back the current block Id value.
         * \return Block Id value.
         */
        const unsigned int getBlockId() const;

        /**
         * \brief Sets the BasicBlock's blockId attribute.
         * \param id       [in] The value to set for id.
         */
        void setBlockId(const unsigned int id);

        /**
         * \brief Gives back that this block is static or not.
         * \return The boolean value.
         */
        const bool getIsStaticInit() const;

        /**
         * \brief Sets the BasicBlock's isStaticInit attribute, to indicate that this block is static or not.
         * \param isStatic          [in] The boolean value to set.
         */
        void setIsStaticInit(const bool isStatic);

        /**
         * \brief Adds a NodeId to the NodeId container.
         * \param nodeId            [in] The NodeId that needs to be added to the NodeId container.
         */
        void addNode(const NodeId nodeId);

        /**
         * \brief Adds a NodeId from a list to the NodeId container.
         * \param nodeList          [in] The NodeId list which elements needs to be added to the NodeId container.
         */
        void addNodes(const std::list<NodeId> &nodeIdList);

        /**
         * \brief Delete a node from this BasicBlock.
         * \param nodeId            [in] The node id which represented node needs to be delete.
         */
        void deleteNode(const NodeId nodeId);

        /**
         * \brief Gives back that this block is an EntryBlock or not.
         * \return The boolean value.
         */
        const bool isEntryBlock() const;

        /**
         * \brief Gives back that this block is an ExitBlock or not.
         * \return The boolean value.
         */
        const bool isExitBlock() const;

        /**
         * \brief Class for the nodes NodeContainer const iterator.
         */
        class NodesConstIterator {
            friend class BasicBlock;

        private:
            const NodeContainer& nodeContainer;
            NodeContainer::const_iterator iterator;
        public:
            /**
             * \internal
             * \brief Constructor, that initializes the NodesConstIterator iterator.
             * \param nodes           [in] A nodes container that needs to be visit.
             */
            NodesConstIterator(const NodeContainer& nodes) : nodeContainer(nodes), iterator(nodeContainer.begin()){
            }

            /**
             * \brief true if the next node exists, false otherwise.
             * \return bool value.
             */
            bool hasNext() const {
                if (iterator != nodeContainer.end())
                    return true;
                return false;
            }

            /**
             * \brief Returns the next constant NodeId
             * \return A NodeId.
             */
            const NodeId next(){
                return *iterator++;
            }

            /**
             * \brief Returns the size of the nodeContainer. 
             * \return The size of the container.
             */
            const size_t size (){
                return nodeContainer.size();
            }

            /**
             * \brief Returns true if the nodeContainer is empty. 
             * \return bool value
             */
            const bool isEmpty() const {
                return nodeContainer.empty();
            }

            /**
             * \brief Returns the last NodeId in the nodeContainer or 0 if the container is empty. 
             * \return NodeId or 0
             */
            const NodeId last() const {
                if (nodeContainer.size() > 0)
                    return nodeContainer.back();
                return 0;
            }

            /**
             * \brief Returns the first NodeId in the nodeContainer or 0 if the container is empty. 
             * \return NodeId or 0
             */
            const NodeId first() const {
                if (nodeContainer.size() > 0)
                    return nodeContainer.front();
                return 0;
            }
        };

        /**
         * \brief Class for the nodes NodeContainer reverse direction const iterator.
         */
        class NodesReverseConstIterator {
            friend class BasicBlock;

        private:
            const NodeContainer& nodeContainer;
            NodeContainer::const_reverse_iterator rev_iterator;

        public:
            /**
             * \internal
             * \brief Constructor, that initializes the NodesReverseConstIterator iterator.
             * \param nodes           [in] A nodes container that needs to be visit.
             */
            NodesReverseConstIterator(const NodeContainer& nodes) : nodeContainer(nodes), rev_iterator(nodeContainer.rbegin()){
            }

            /**
             * \brief true if the next node exists, false otherwise.
             * \return bool value.
             */
            bool hasNext() const{
                if (rev_iterator != nodeContainer.rend())
                    return true;
                return false;
            }

            /**
             * \brief Returns the next constant NodeId.
             * \return A NodeId.
             */
            const NodeId next(){
                return *rev_iterator++;
            }

            /**
             * \brief Returns the size of the nodeContainer. 
             * \return The size of the container.
             */
            const size_t size (){
                return nodeContainer.size();
            }

            /**
             * \brief Returns true if the nodeContainer is empty. 
             * \return bool value
             */
            const bool isEmpty(){
                return nodeContainer.empty();
            }

            /**
             * \brief Returns the last NodeId in the nodeContainer or 0 if the container is empty. 
             * \return NodeId or 0
             */
            const NodeId last(){
                if (nodeContainer.size() > 0)
                    return nodeContainer.front();
                return 0;
            }
        };

        /**
         * \brief Instantiates and gives back a NodesConstIterator iterator for the nodes container.
         * \return NodesConstIterator iterator.
         */
        NodesConstIterator nodesConstIterator() const {
            return NodesConstIterator(nodes);
        }

        /**
         * \brief Instantiates and gives back a NodesReverseConstIterator iterator for the nodes container.
         * \return NodesReverseConstIterator iterator.
         */
        NodesReverseConstIterator nodesReverseConstIterator() const {
            return NodesReverseConstIterator(nodes);
        }

        /**
         * \brief Class for the edges EdgeContainer const iterator.
         */
        class EdgesConstIterator {
            friend class BasicBlock;

        private:
            const EdgeContainer& edgeContainer;
            EdgeContainer::const_iterator iterator;

        public:
            /**
             * \internal
             * \brief Constructor, that initializes the EdgesConstIterator iterator.
             * \param egdes           [in] An edge container that needs to be visit.
             */
            EdgesConstIterator(const EdgeContainer& edges) : edgeContainer(edges), iterator(edgeContainer.begin()) {
            }
              
            /**
             * \brief true if the next Edge pointer exists, false otherwise.
             * \return bool value.
             */
            bool hasNext() const {
                if (iterator != edgeContainer.end())
                    return true;
                return false;
            }

            /**
             * \brief Returns a pointer to the next constant Edge.
             * \return A pointer to constant Edge.
             */
            const Edge* next(){
                return *iterator++;
            }

            /**
             * \brief Returns the size of the edge container. 
             * \return The size of the container.
             */
            const size_t size() const {
                return edgeContainer.size();
            }

            /**
             * \brief Returns true if the edgeContainer is empty. 
             * \return bool value.
             */
            const bool isEmpty() const {
                return edgeContainer.empty();
            }
        };

        /**
         * \brief Instantiates and gives back an EdgesConstIterator iterator for the controlInEdges container.
         * \return EdgesConstIterator iterator.
         */
        EdgesConstIterator controlInEdgesIterator() const {
            return EdgesConstIterator(controlInEdges);
        }

        /**
         * \brief Instantiates an EdgesConstIterator iterator for the controlOutEdges container.
         * \return EdgesConstIterator iterator.
         */
        EdgesConstIterator controlOutEdgesIterator() const {
            return EdgesConstIterator(controlOutEdges);
        }

        unsigned nonExceptionalControlOutEdgeSize() const;

        /**
         * \brief Instantiates an EdgesConstIterator iterator for the callInEdges container.
         * \return EdgesConstIterator iterator.
         */
        EdgesConstIterator callInEdgesIterator() const {
            return EdgesConstIterator(callInEdges);
        }

        /**
         * \brief Instantiates an EdgesConstIterator iterator for the callInEdges container.
         * \return EdgesConstIterator iterator.
         */
        EdgesConstIterator callOutEdgesIterator() const {
            return EdgesConstIterator(callOutEdges);
        }

        /**
         * \brief Gives back a pointer to the parent ICFG.
         * \return Pointer to the ICFG.
         */
        ICFG* getParent() const;

    private:
        /**
         * \brief Adds control in typed edge to the container that stores control in edges.
         * \param edge           [in] The edge that needs to be add to the container that stores control in edges.
         */
        void addControlInEdge(Edge* edge);

        /**
         * \brief Adds control out typed edge to the container that stores control out edges.
         * \param edge           [in] The edge that needs to be add to the container that stores control out edges.
         */
        void addControlOutEdge(Edge* edge);

        /**
         * \brief Adds call in typed edge to the container that stores call in edges.
         * \param edge           [in] The edge that needs to be add to the container that stores call in edges.
         */
        void addCallInEdge(Edge* edge);

        /**
         * \brief Adds call in typed edge to the container that stores call out edges.
         * \param edge           [in] The edge that needs to be add to the container that stores call out edges.
         */
        void addCallOutEdge(Edge* edge);

        /**
         * \brief Deletes a control in typed edge from the container that stores control in edges.
         * \param edge           [in] The edge that needs to be remove from the container that stores control in edges.
         */
        void deleteControlInEdge(Edge* edge);

        /**
         * \brief Deletes a control out typed edge from the container that stores control out edges.
         * \param edge           [in] The edge that needs to be remove from the container that stores control out edges.
         */
        void deleteControlOutEdge(Edge* edge);

        /**
         * \brief Deletes a call in typed edge from the container that stores call in edges.
         * \param edge           [in] The edge that needs to be remove from the container that stores call in edges.
         */
        void deleteCallInEdge(Edge* edge);

        /**
         * \brief Deletes a call out typed edge from the container that stores call out edges.
         * \param edge           [in] The edge that needs to be remove from the container that stores call out edges.
         */
        void deleteCallOutEdge(Edge* edge);

    public:
        /**
         * \brief Deletes a control in typed edges.
         */

        void deleteControlInEdges();
        /**
         * \brief Deletes a control out typed edges.
         */
        void deleteControlOutEdges();

        /**
         * \brief Deletes a call in typed edges.
         */
        void deleteCallInEdges();

        /**
         * \brief Deletes a call out typed edges.
         */
        void deleteCallOutEdges();
    };

}}

#endif