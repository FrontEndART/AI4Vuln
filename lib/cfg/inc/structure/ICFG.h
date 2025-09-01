#ifndef _ICFG_H
#define _ICFG_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    /**
    * \brief Type definition of method Ids. 
    */
    typedef unsigned long ICFGid;

    /**
    * \brief Type definition to store BasicBlock pointers with their block Ids. 
    */
    typedef std::map<unsigned int, BasicBlock*> BasicBlockMap;

    /**
    * \brief Enum type definition to indicate auro generated methods. 
    */
    enum GeneratedICFG {SYSTEM, GLOBAL_START, GLOBAL_END};

    /**
    * \brief Interprocedural Control Flow Graph. 
    */
    class ICFG{
        friend class BasicBlock;
    private:
        struct IcfgFlags {
            /**
            * \brief Bool attribute to indicate, that the ICFG function terminates the program or not. 
            */
            unsigned int isTerminator : 1;

            /**
            * \brief Bool attribute to indicate, that the ICFG function allocates/deallocates memory or neither. 
            */
            unsigned int isAllocator : 1;

            /**
            * \brief Bool attribute to indicate, that the ICFG function is static or not. 
            */
            unsigned int isStaticInit : 1;

            /**
            * \brief Bool attribute to indicate, that the ICFG function is instance init or not. 
            */
            unsigned int isInstanceInit : 1;

            /**
            * \brief Bool attribute to indicate, that the ICFG function is auto generated or not. 
            */
            unsigned int isGenerated : 1;
        } flags;
        /**
        * \brief The method Id for the ICFG. 
        */
        ICFGid methodId;

        /**
        * \brief The EntryBlock pointer that points to an entry block. 
        */
        EntryBlock *entryBlock;

        /**
        * \brief The ExitBlock pointer that points to an exit block. 
        */
        ExitBlock *exitblock;

        /**
        * \brief \internal Storage for the block Id and BasicBlock pointer pairs. 
        */
        BasicBlockMap basicBlockContainer;

        /**
        * \brief Pointer of the CFGFactory. 
        */
        CFGFactory *cfgFact;

        /**
        * \brief ICFG name, that stores the corresponding ASG Named method node mangled or simple name, if no mangled name exists or empty, if the node is not Named. 
        */
        std::string name;
    public:
        /**
        * \internal
        * \brief Constructor that creates the entry and exit blocks for the ICFG and sets the methodId with the given parameter.
        * \param methodId           [in] The method Id that indexes an ICFG in the container.
        */
        ICFG(const ICFGid methodId, CFGFactory *cfgFact);

        static ICFG* createICFG(const ICFGid methodId, CFGFactory *cfgFact);

        /**
        * \brief Destructor, that will delete the entry and exit blocks pointers, the BasicBlock pointers in the container and clears the block Id and BasicBlock pointer pair container.
        */
        ~ICFG();

        ICFG(const ICFG& icfg);

        ICFG& operator=(const ICFG& icfg);

        /**
        * \brief Gives back the factory pointer.
        * \return CFGFactory pointer.
        */
        CFGFactory* getCFGFactory() const;

        /**
        * \brief Gives back the current method Id value.
        * \return Method Id value.
        */
        ICFGid getMethodId() const;

        /**
        * \brief Gives back the current EntryBlock in the ICFG.
        * \return Pointer to the ICFG's EntryBlock.
        */
        EntryBlock* getEntryBlock() const;

        /**
        * \brief Gives back the current ExitBlock in the ICFG.
        * \return Pointer to the ICFG's ExitBlock.
        */
        ExitBlock* getExitBlock() const;

        /**
        * \brief Gives back a pointer to the BasicBlock, indexed with block Id.
        * \param blockId           [in] The block id that indexes a BasicBlock in the container.
        * \return Pointer to the BasicBlock indexed with block Id or NULL pointer if no block Id found in the container.
        */
        BasicBlock* getBlock(const unsigned int blockId) const;

        /**
        * \brief Creates a new BasicBlock for the current ICFG with a new block Id and then gives it back.
        * \return Pointer to the new BasicBlock.
        */
        BasicBlock* createBasicBlock(const unsigned int blockId = 0);

        /**
        * \brief Gives back a reference to the basicBlockContainer.
        * \return BasicBlockMap reference.
        */
        const BasicBlockMap& getBasicBlockContainer() const;

        /**
        * \brief Gives back the basicBlockContainer size.
        * \return The number of blocks.
        */
        const size_t getNumberOfBlocks() const;

        /**
        * \brief Delete the given block from the ICFG with its edges too.
        * \param blockId               [in] The Block id that needs to be delete.
        */
        void deleteBlock(const unsigned int blockId);

        /**
        * \brief Sets the isTerminator attribute, to indicate that this ICFG represented node terminates the program or not.
        * \param terminatorAttrib      [in] The boolean attribute to set.
        */
        void setIsTerminator(const bool terminatorAttrib);

        /**
        * \brief Sets the isAllocator attribute, to indicate that this ICFG represented node allocates or deallocates memory or not.
        * \param allocatorAttrib       [in] The boolean attribute to set.
        */
        void setIsAllocator(const bool allocatorAttrib);

        /**
        * \brief Gives back that this ICFG represented node terminates the program or not size.
        * \return The number of blocks.
        */
        const bool getIsTerminator() const;

        /**
        * \brief Gives back that this ICFG represented node allocates or deallocates memory or not.
        * \return The number of blocks.
        */
        const bool getIsAllocator() const;

        /**
        * \brief Sets the ICFG name.
        * \param name       [in] The string value to set.
        */
        void setName(const std::string& name);

        /**
        * \brief Gives back the ICFG's name.
        * \return The string value.
        */
        const std::string getName() const;

        /**
        * \brief Reallocates the block id's in this ICFG, so the id numbers will follow each other in ascending line.
        */
        void reallocateBlockIds();

        /**
        * \brief Gives back that this ICFG is static or not.
        * \return The boolean value.
        */
        const bool getIsStaticInit() const;

        /**
        * \brief Sets the ICFG's isInstanceInit attribute, to indicate that this ICFG represented node is instance init or not.
        * \param isInstanceInit       [in] The boolean value to set.
        */
        void setIsInstanceInit(const bool isInstanceInit);

        /**
        * \brief Gives back that this ICFG is instance init or not.
        * \return The boolean value.
        */
        const bool getIsInstanceInit() const;

        /**
        * \brief Sets the ICFG's isStaticInit attribute, to indicate that this ICFG represented node is static or not.
        * \param isStatic       [in] The boolean value to set.
        */
        void setIsStaticInit(const bool isStatic);


        /**
        * \brief Sets the ICFG's isGenerated attribute, to indicate that this ICFG represented node is auto generated or not.
        * \param isGenerated   [in] The boolean value to set.
        */
        void setIsGenerated(const bool isGenerated);

        /**
        * \brief Gives back that this ICFG is auto generated or not.
        * \return The boolean value.
        */
        const bool getIsGenerated() const;

        /**
        * \brief It gets the previous blocks of a BasicBlock inside the ICFG.
        * \param blockId    [in]  The BasicBlock's id.
        * \param resultSet  [out] The previous block ids.
        */
        void getPrevBlocks(const unsigned int blockId, std::set<columbus::NodeId>& resultSet) const;

        /**
        * \brief It gets the next blocks of a BasicBlock inside the ICFG.
        * \param blockId    [in]  The BasicBlock's id.
        * \param resultSet  [out] The next block ids.
        */
        void getNextBlocks(const unsigned int blockId, std::set<columbus::NodeId>& resultSet) const;
    };

}}

#endif
