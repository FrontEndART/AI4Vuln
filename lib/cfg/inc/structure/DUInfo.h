#ifndef _DUINFO_H
#define _DUINFO_H

/**
 * \file DUInfo.h
 * \brief Contains declaration of DUInfo, AddressInfo and OperationInfo classes.
 */

#include "cfg/inc/cfg.h"

namespace columbus {
    namespace cfg {

        /** \brief Constant for "&" reference address descriptor. */
        static const columbus::NodeId cADDRESSDESCRIPTOR_REFERENCE = 1;

        /** \brief Type definition to store nodeIds in the used set. */
        typedef std::vector<columbus::NodeId> UsedContainer;

        /** \brief Type definition to store nodeIds in the defined set. */
        typedef std::vector<columbus::NodeId> DefinedContainer;

        /** \brief Type definition to store nodeIds in the kill set. */
        typedef std::vector<columbus::NodeId> KillContainer;

        /** \brief Enumeration type for type of DUInfo */
        typedef enum {
            duAddressInfo, duOperationInfo
        } DUInfoType;

        /** \brief Forward declarations. */
        class AddressInfo;
        class OperationInfo;

        class DUInfo {
        protected:
            /**
             * \brief nodeId which belongs to DUInfo. This is the ASG node ID.
             */
            const columbus::NodeId m_nodeId;

            /**
             * \brief It stores the nodeIds which are used by this.
             */
            UsedContainer m_usedContainer;

            /**
             * \brief It stores the nodeIs which are defined by this.
             */
            DefinedContainer m_definedContainer;

            /** \brief The type of DUInfo (AddressInfo/OperationInfo) */
            DUInfoType m_infoType;

            /**
             * \brief Constructor.
             * \param nodeId     [in] nodeId which belongs to DUInfo.
             * \param cfgFactory [in] the CFG Factory.
             */
            DUInfo(const columbus::NodeId nodeId, columbus::cfg::CFGFactory* cfgFactory, DUInfoType infoType);

        public:

            /**
             * \brief Destructor.
             */
            virtual ~DUInfo();

            /**
             * \brief Adds a nodeId to the used container.
             */
            void addNodeToUsedContainer(const columbus::NodeId nodeId);

            /**
             * \brief Adds a nodeId to the defined container.
             */
            void addNodeToDefinedContainer(const columbus::NodeId nodeId);

            /**
             * \brief Gives back the nodeId.
             * \return The nodeId.
             */
            const columbus::NodeId getNodeId() const;

            /**
             * \brief Gives back the used container.
             * \return The used container.
             */
            const UsedContainer& getUsedContainer() const;

            /**
             * \brief Gives back the defined container.
             * \return The defined container.
             */
            const DefinedContainer& getDefinedContainer() const;

            /**
             * \brief It decides if the DUInfo defines itself.
             *        The defined container contains the nodeId?
             * \return True if the DUInfo defines itself.
             */
            bool isDefinedByItself() const;

            /**
             * \brief It decides if the nodeId is in the used container.
             * \return True if the nodeId is in the used container.
             */
            bool isNodeInTheUsedContainer(const columbus::NodeId nodeId) const;

            /**
             * \brief Get an AddressInfo pointer.
             * \return The AddressInfo pointer.
             */
            const AddressInfo* toAddressInfo() const;

            /**
             * \brief Get an OperationInfo pointer.
             * \return The OperationInfo pointer.
             */
            const OperationInfo* toOperationInfo() const;

            /**
             * \brief Decides if the DUInfo is an AddressInfo.
             * \return true if it is an AddressInfo, otherwise false.
             */
            bool isAddressInfo() const;

            /**
             * \brief Decides if the DUInfo is an OperationInfo.
             * \return true if it is an OperationInfo, otherwise false.
             */
            bool isOperationInfo() const;

            /**
             * \brief Gives back the container's node ids.
             * \parameter [in] container: the container.
             * \return the container's node ids.
             */
            std::string toString(const std::vector<columbus::NodeId>& container) const;

            /**
             * \brief Print out the DU information.
             * \return The DUInfo text.
             */
            virtual std::string toString() const;
        };

        class AddressInfo : public DUInfo {
        private:
        protected:
            /**
             * \brief It stores the address selector.
             */
            columbus::NodeId m_addressSelector;

            /**
             * \brief It stores the nodes which have special meanings.
             */
            columbus::NodeId m_special;

            /**
             * \brief It stores the address descriptor.
             */
            columbus::NodeId m_addressDescriptor;

            /**
             * \brief It indicates if this AddressInfo is at ICFG-scope-border.
             */
            bool m_isICFGScopeBorder;

            /**
             * \brief It indicates if this AddressInfo belongs to a function parameter.
             */
            bool m_isParameter;

        public:
            /**
             * \brief Constructor.
             * \param nodeId            [in] nodeId which belongs to DUInfo.
             * \param cfgFactory        [in] The CFG Factory.
             * \param isICFGScopeBorder [in] Is it ICFG-scope-border?
             */
            AddressInfo(const columbus::NodeId nodeId, columbus::cfg::CFGFactory *cfgFactory, bool isICFGScopeBorder = false);

            /**
             * \brief Destructor.
             */
            ~AddressInfo();

            /**
             * \brief Set the addressSelector.
             */
            void setAddressSelector(const columbus::NodeId addressSelector);

            /**
             * \brief Gives back the address selector.
             * \return The address selector.
             */
            const columbus::NodeId getAddressSelector() const;

            /**
             * \brief Set the special.
             */
            void setSpecial(const columbus::NodeId special);

            /**
             * \brief Gives back the special.
             * \return The special.
             */
            const columbus::NodeId getSpecial() const;

            /**
             * \brief Set the addressdescriptor.
             */
            void setAddressDescriptor(const columbus::NodeId addressDescriptor);

            /**
             * \brief Gives back the addressdescriptor.
             * \return The addressDescriptor.
             */
            const columbus::NodeId getAddressDescriptor() const;

            /**
             * \brief Set the parameter indicator.
             */
            void setIsParameter(const bool isParameter);

            /**
             * \brief Gives back the parameter indicator.
             * \return The parameter indicator.
             */
            const bool getIsParameter() const;

            /**
             * \brief It decides if the nodeId is in the special.
             * \return True if the nodeId is in the special.
             */
            bool isNodeSpecial(const columbus::NodeId nodeId) const;

            /**
             * \brief Gives back if the addressDescriptor was set.
             * \return true if the addressDescriptor was set.
             */
            bool getIsSetAddressDescriptor() const;

            /**
             * \brief Gives back if the addressDescriptor is at ICFG-scope-border.
             * \return true if the addressDescriptor is at ICFG-scope-border.
             */
            bool getIsICFGScopeBorder() const;

            /**
             * \brief Print out the DU information.
             * \return The DUInfo text.
             */
            virtual std::string toString() const;
        };

        class OperationInfo : public DUInfo {
        protected:
            /**
             * \brief It stores the kill set.
             */
            KillContainer m_killContainer;

            /**
             * \brief It stores the fake address selector.
             * It is used by CG constructing.
             */
            columbus::NodeId m_fakeAddressSelector;

        public:
            /**
             * \brief Constructor.
             * \param nodeId     [in] nodeId which belongs to DUInfo.
             * \param cfgFactory [in] The CFG Factory.
             */
            OperationInfo(const columbus::NodeId nodeId, columbus::cfg::CFGFactory* cfgFactory);

            /**
             * \brief Destructor.
             */
            ~OperationInfo();

            /**
             * \brief Adds a nodeId to the kill container.
             */
            void addNodeToKillContainer(const columbus::NodeId nodeId);

            /**
             * \brief Gives back the kill container.
             * \return The kill container.
             */
            const KillContainer& getKillContainer() const;

            /**
             * \brief Set the fake address selector.
             * \param   [in] The fake address selector.
             */
            void setFakeAddressSelector(const columbus::NodeId fake);

            /**
             * \brief Gives back the fake address selector.
             * \return The fake address selector.
             */
            const columbus::NodeId getFakeAddressSelector() const;

            /**
             * \brief Print out the DU information.
             * \return The DUInfo text.
             */
            virtual std::string toString() const;
        };

    }
}

#endif
