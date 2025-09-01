#ifndef _ALGORITHM_COMPARE_H
#define _ALGORITHM_COMPARE_H

/**
 * \file AlgorithmCompare.h
 * \brief Contains the class `Compare' which implements algorithms for comparing DUInfos.
 */

#include "cfg/inc/cfg.h"

namespace columbus {
    namespace cfg {

        /** \brief Enumeration type for compare method */
        typedef enum {
            duCompareWithFieldAccess, duCompareWithoutFieldAccess
        } DUInfoCompareType;

        /** \brief Enumeration type for the result of compare */
        typedef enum {
            duCompareResultSameAddress, duCompareResultMaybeAddress, duCompareResultDifferentAddress, duCompareResultOverlap
        } DUInfoCompareResultType;

        /** \brief The variable container type, which stores variables list accessible from a node */
        typedef std::vector<columbus::cfg::Variable> VariableContainerType;

        /** \brief Unknown Node ID. Only for initial value! */
        static const unsigned int UNKNOWN_NODE_ID = 0;

        // Forward declaration.
        class AlgorithmDefUseChains;

        class AlgorithmCompare {
        protected:
            /** \brief CFG Factory. */
            const columbus::cfg::CFGFactory *m_cfgFactory;

            /** \brief The resolved variables. */
            std::map<columbus::NodeId, VariableContainerType> m_variables;

            /**
             * \brief It checks if the container has only AddressInfos.
             * \param variableContainer [in] The variableContainer.
             * \return True if the variableContainer has only AddressInfos.
             */
            bool isAllAddressInfoInTheList(const std::list<columbus::NodeId>& list) const;

            /**
             * \brief It compares two Variable lists.
             * \param leftList  [in] The left-side variable list.
             * \param rightList [in] The right-side variable list.
             * \return One of the following: same Address, maybe Address, different Address.
             */
            virtual DUInfoCompareResultType compareLists(const columbus::cfg::Variable& leftList, const columbus::cfg::Variable& rightList) const;

        public:
            /**
             * \brief Constructor.
             * \param cfgFactory [in] The CFG Factory.
             */
            AlgorithmCompare(const columbus::cfg::CFGFactory &cfgFactory);

            /** \brief Destructor. */
            virtual ~AlgorithmCompare();

            /** \brief Copy constructor. */
            AlgorithmCompare(const AlgorithmCompare&);

            /** \brief Assignment operator. */
            AlgorithmCompare operator=(const AlgorithmCompare&);

            /**
             * \brief The Compare mehtod. It compares two DUInfo object.
             * \param nodeIdLeft  [in] The left-side DUInfo belongs to nodeIdLeft.
             * \param nodeIdRight [in] The right-side DUInfo belongs to nodeIdRight.
             * \param compareType [in] Type of compare (with or without addressSelector).
             * \return One of the following: same Address, maybe Address, different Address.
             */
            virtual DUInfoCompareResultType compare(const columbus::NodeId nodeIdLeft, const columbus::NodeId nodeIdRight, const DUInfoCompareType compareType = duCompareWithoutFieldAccess);

            /**
             * \brief It resolves an AddressInfo.
             * \param addressInfo  [in]     The address info.
             * \return The variable set which are accessible from operationInfo.
             */
            virtual VariableContainerType& resolveInfo(const AddressInfo *addressInfo);

            /**
             * \brief It resolves an OperationInfo.
             * \param operationInfo [in]     The operation info.
             * \return The variable set which are accessible from operationInfo.
             */
            virtual VariableContainerType& resolveInfo(const OperationInfo *operationInfo);

            /**
             * \brief It finds if a nodeId is already resolved or not.
             * \param nodeId [in] The nodeId.
             * \return True if nodeId is already resolved, otherwise false.
             */
            bool isAddressInfoResolved(const columbus::NodeId nodeId) const;

            /**
             * \brief Gets the resolved variable list from nodeId.
             * \param nodeId   [in]  The nodeId.
             * \return Reference to VariableContainer set, which contains the accessible nodes from nodeId.
             */
            VariableContainerType& getResolvedVariables(const columbus::NodeId nodeId);
        };
    }
}

#endif
