#ifndef _VARIABLE_H
#define _VARIABLE_H

/**
 * \file Variable.h
 * \brief Contains the class `Variable' which is used by the DU compare method.
 */

#include "cfg/inc/cfg.h"

namespace columbus {
    namespace cfg {

        class Variable {
        private:

            /** \brief The nodeIds which are accessible from DUInfo belongs to nodeId. */
            std::list<columbus::NodeId> m_variableList;

            /** \brief The nodeIds which have to weak equal to an another nodeId.
             * a[i] ? a[j]: maybe same, but a.i ? a.j: different.
             * At creating the DUInfos the usedSet at AddressInfos determines the weak equals nodeIds.
             */
            std::list<columbus::NodeId> m_weakEqualList;

        public:

            /** \brief Default constructor. */
            Variable();

            /** \brief Destructor. */
            ~Variable();

            /** \brief Copy constructor. */
            Variable(const Variable& right);

            /** \brief Assignment operator. */
            columbus::cfg::Variable& operator=(const columbus::cfg::Variable& right);

            /**
             * \brief Gets the size of the variable list.
             * \return The size of the variable list.
             */
            std::list<columbus::NodeId>::size_type getSize() const;

            /**
             * \brief Gets the variable list.
             * \return The variable list.
             */
            const std::list<columbus::NodeId>& getList() const;

            /**
             * \brief Appends the nodeId to the back of variable list.
             * \param nodeId [in] The nodeId.
             */
            void append(const columbus::NodeId nodeId);

            /**
             * \brief Appends the nodeId to the back of weak equal list.
             * \param nodeId [in] The nodeId.
             */
            void appendWeak(const columbus::NodeId nodeId);
        };
    }
}

#endif
