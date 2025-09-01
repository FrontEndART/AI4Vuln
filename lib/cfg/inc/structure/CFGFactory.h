#ifndef _CFGFACTORY_H
#define _CFGFACTORY_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    /**
    * \brief Type definition to store ICFG pointers with their method Ids. 
    */
    typedef std::map<ICFGid, ICFG*> ICFGContainer;

    /**
    * \brief Type definition to store DUInfo pointers. 
    */
    typedef std::map<columbus::NodeId, DUInfo*> DUInfoContainer;

    /**
    * \brief \internal A static default ASGNodePrinter, that will be used, if no ASGNodePrinter is given by the user. 
    */
    const static ASGNodePrinter defaultASGNodePrinter;

    class CFGFactory{
    private:
        /**
        * \brief \internal Storage for the method Id and ICFG pointer pairs. 
        */
        ICFGContainer icfgContainer;

        /**
        * \brief \internal Storage for BasicBlock pointers indexed with nodes NodeId. 
        */
        std::vector<BasicBlock*> nodeInBasicBlock;

        /**
        * \brief \internal Storage for terminator ICFGs. 
        */
        std::set<const ICFG*> terminatorICFGContainer;

        /**
        * \brief \internal Storage for allocator ICFGs. 
        */
        std::set<const ICFG*> allocatorICFGContainer;

        /**
        * \brief \internal Storage for terminator funtion names. 
        */
        std::set<std::string> terminatorNames;

        /**
        * \brief \internal Storage for allocator funtion names. 
        */
        std::set<std::string> allocatornNames;

        /**
        * \brief \internal ASGNodePrinter, that converts an ICFG method id to its corresponding ASG node mangled name string. 
        */
        const ASGNodePrinter* asgNode2String;

        /**
        * \brief \internal Storage for DUInfos. 
        */
        DUInfoContainer m_DUInfos;

        /**
        * \brief Visits the blocks through the control out edges until the firs node is not found.
        * \param block                 [in] The actual block, that control out edges targets needs to be visited.
        * \param node                  [in] The node Id which following node is needed.
        * \param nextNodesContainer    [in/out] The container that will contain the found nodes.
        * \param visitedBlocks         [in/out] The container, that contains the already visited nodes, to prevent the infinite recursion.
        */
        void visitNextBlock(const BasicBlock* block, const NodeId node, std::set<NodeId>& nextNodesContainer, std::set<const BasicBlock*>& visitedBlocks) const;

        /**
        * \brief Visits the blocks through the control in edges until the last node is not found.
        * \param block                 [in] The actual block, that control in edges targets needs to be visited.
        * \param node                  [in] The node Id which preceding node is needed.
        * \param nextNodesContainer    [in/out] The container that will contain the found nodes.
        * \param visitedBlocks         [in/out] The container, that contains the already visited nodes, to prevent the infinite recursion.
        * \param withCallEdges         [in] Visiting previous call in edges?  (default false)
        */
        void visitPrevBlock(const BasicBlock* block, const columbus::NodeId node, std::set<columbus::NodeId>& prevNodesContainer, std::set<const BasicBlock*>& visitedBlocks, bool withCallEdges = false) const;

        friend class BasicBlock;
        friend class AlgorithmCDG;
        friend class DUInfo;

    public:
        /**
        * \internal
        * \brief Constructor, that resizes the nodeInBasicBlock container.
        * \param size           [in] The number of ASG nodes.
        */
        CFGFactory(const unsigned int size, const ASGNodePrinter* asgNamed2String = NULL, const std::string& filename = "");

        CFGFactory(const columbus::cfg::CFGFactory& cfgFactory);

        CFGFactory& operator=(const columbus::cfg::CFGFactory& cfgFactory);

        /**
        * \brief Destructor, that will delete the ICFG pointers and clears the method Id and ICFG pointer pair container.
        */
        ~CFGFactory();

        void iterate(DUDecorator& duDecorator, ICFGid methodId);

        /**
        * \brief Gives back a pointer to the ICFG, indexed with method Id or creates a new ICFG without a BasickBlock and gives the pointer back.
        * \param methodId           [in] The method id that indexes an ICFG in the container.
        * \return Pointer to the ICFG indexed with method Id.
        */
        ICFG* getICFG(const ICFGid methodId);

        /**
        * \brief 
        * Creates a new basic block in the corresponding ICFG if there is any with the given method Id or 
        * creates a new ICFG with the method Id and then a new basic block within it.
        * \param methodId           [in] The method id that indexes an ICFG in the container or that needs to be added to the contsiner with a new ICFG.
        * \return Pointer to the new BasicBlock.
        */
        BasicBlock* createBlock(ICFGid methodId);

        /**
        * \brief Gives back a pointer to a BasicBlock that contains the given node with it's NodeId.
        * \param nodeId           [in] The NodeId which containing BasicBlock we are looking for.
        * \return Pointer to the BasicBlock indexed with nodeId or NULL pointer if no nodeId found in the nodeInBasicBlock container.
        */
        BasicBlock* getBasicBlock(NodeId nodeId) const;

        /**
        * \brief Gives back a reference to the icfgContainer.
        * \return Constant reference to the icfgContainer.
        */
        const ICFGContainer& getICFGContainer() const;

        /**
        * \brief Resizes the storage for BasicBlock pointers indexed with nodes NodeId.
        * \param size              [in] The size to resize the storage.
        */
        void resize(const size_t size);

        /**
        * \brief Gives back the number of nodes in the CFG.
        * \return unsigned int value.
        */
        const size_t getNumberOfNodes() const;

        /**
        * \brief Gives back the ICFG/s which is/are called from the given method Id's ICFG.
        * \param methodId          [in] The method Id, which ICFG call out edge targets are needed.
        * \param calledICFGs       [out] An ICFG pointer set to store the ICFG pointers.
        */
        void getCallsOfMethod(const ICFGid methodId, std::set<ICFG*>& calledICFGs) const;

        /**
        * \brief Gives back a container with the next nodes, that follows the given node in the CFG.
        * \param node              [in] The node which following node/s is/are needed.
        * \return Container of the node Id/s or empty container if no node is found.
        */
        void getNextNode(const NodeId node, std::set<NodeId>& nextNodesContainer) const {
            std::set<const BasicBlock*> visitedBlocks;
            getNextNode (node, visitedBlocks, nextNodesContainer);
        }

        /**
        * \brief Gives back a container with the next nodes, that follows the given node in the CFG.
        * \param node                  [in] The node which following node/s is/are needed.
        * \param visitedBlocks         [in/out] The container, that contains the already visited nodes, to prevent the infinite recursion.
        * \param nextNodesContainer    [out] A nodeId set to store the found node Ids.
        * \return Container of the node Id/s or empty container if no node is found.
        */
        void getNextNode(const NodeId node, std::set<const BasicBlock*>& visitedBlocks, std::set<NodeId>& nextNodesContainer) const;

        /**
        * \brief Gives back a container with the prev nodes, that precedes the given node in the CFG.
        * \param node              [in] The node which preceding node/s is/are needed.
        * \param withCallEdges     [in] Visiting previous call in edges? (default false)
        * \return Container of the node Id/s or empty container if no node is found.
        */
        void getPrevNode(const columbus::NodeId node, std::set<columbus::NodeId>& prevNodesContainer, bool withCallEdges = false) const {
            std::set<const BasicBlock*> visitedBlocks;
            getPrevNode(node, visitedBlocks, prevNodesContainer, withCallEdges);
        }

        /**
        * \brief Gives back a container with the next nodes, that precedes the given node in the CFG.
        * \param node                       [in] The node which preceding node/s is/are needed.
        * \param visitedBlocks              [in/out] The container, that contains the already visited nodes, to prevent the infinite recursion.
        * \param prevNodesContainer         [out] A nodeId set to store the found node Ids.
        * \param withCallEdges              [in] Visiting previous call in edges? (default false)
        * \param clearVisitedNodeContainer  [in] Has to clear visited nodes container? (default true)
        * \return Container of the node Id/s or empty container if no node is found.
        */
        void getPrevNode(const columbus::NodeId node, std::set<const BasicBlock*>& visitedBlocks, std::set<columbus::NodeId>& prevNodesContainer, bool withCallEdges = false, bool clearVisitedNodeContainer = true) const;

        /**
        * \brief It checks, if the node exists in the CFG.
        * \param nodeId       [in]  The nodeId.
        * \return True if the node is exists in the CFG, otherwise false.
        */
        bool isNodeExists(const columbus::NodeId nodeId) const;

        /**
        * \brief It checks, if the DUInfo for the node exists.
        * \param nodeId       [in]  The nodeId.
        * \return True if the DUInfo is exists, otherwise false.
        */
        bool isDUInfoExists(const columbus::NodeId nodeId) const;

        /**
        * \brief Gives back a pointer to an ICFG that is an auto generated SYSTEM function.
        * \return Pointer to the ICFG.
        */
        ICFG* getSystemICFG();

        /**
        * \brief Gives back a pointer to an ICFG that is an auto generated GLOBAL_START function.
        * \return Pointer to the ICFG.
        */
        ICFG* getGlobalStartICFG();

        /**
        * \brief Gives back a pointer to an ICFG that is an auto generated GLOBAL_END function.
        * \return Pointer to the ICFG.
        */
        ICFG* getGlobalEndICFG();

        /**
        * \brief Set the size of DUInfo container (=number of the ASG nodes).
        * \param size [in] The number of ASG nodes.
        */
        void resizeDUInfoContainer(const size_t size);

        /**
        * \brief Gets a pointer to DUInfo for a specified nodeId.
        *        Important: Before use this function you have to call isDuInfoExists(nodeId) - because return value may NULL!
        * \param size [in] nodeId.
        * \return A DUInfo pointer.
        */
        columbus::cfg::DUInfo* getDUInfoPointer(const columbus::NodeId nodeId) const;

        /**
        * \brief Gets a reference for DUInfoContainer.
        * \return A reference for the DUInfo container.
        */
        const DUInfoContainer& getDUInfoContainer() const;

        /**
        * \brief Dumps the content of the DU informations.
        */
        void textDumpDUInfos() const;


        /**
        * \brief Returns true if the str given by the parameter name is one of the terminator names
        */
        bool isTerminatorName(const std::string str) const {
            return terminatorNames.find(str) != terminatorNames.end();
        }

        /**
        * \brief Returns true if the str given by the parameter name is the name of the exit method
        */
        bool isExitFunctionName(const std::string str) const {
            return str == "exit";
        }

        /**
        * \brief Gets the static ICFG which contains the nodeId
        * \param nodeId [in] nodeId.
        * \return The static ICFG pointer.
        */
        ICFG* getStaticICFG(const columbus::NodeId nodeId) const;
    };

}}

#endif
