#ifndef _EDGE_H
#define _EDGE_H

#include "cfg/inc/cfg.h"

namespace columbus {  namespace cfg {

    typedef enum{CALL, CONTROL} EdgeType;

    class Edge{
    private:
        /**
         * \brief \internal A boolean attribute, that indicates, that the edge is exceptional or not. 
         */
        bool isExceptional;

        /**
         * \brief \internal The BasicBlock from the edge goes out. 
         */
        BasicBlock* from;

        /**
         * \brief \internal The BasicBlock to the edge goes in. 
         */
        BasicBlock* to;

        /**
         * \brief \internal The type of the edge. 
         */
        EdgeType edgeType;

        /**
         * \brief \internal The label of the edge. 
         */
        std::string label;

        /**
         * \internal
         * \brief Constructor, that sets the edge type, the edge endpoints and then sets trough the endpoints this edge as their edges.
         * \param from          [in/out] Pointer to a BasicBlock from the edge goes out.
         * \param to            [in/out] Pointer to a BasicBlock to the edge goes in.
         * \param type          [in] The edge type.
         * \param edgeLabel     [in] The edge label.
         */
        Edge(BasicBlock* from, BasicBlock* to, const EdgeType type, const std::string& edgeLabel = "");

    public:
        /**
         * \brief Creates a new Edge between from and to BasicBlocks with the given type and label.
         * \param from          [in/out] Pointer to a BasicBlock from the edge goes out.
         * \param to            [in/out] Pointer to a BasicBlock to the edge goes in.
         * \param type          [in] The edge type.
         * \param edgeLabel     [in] The edge label.
         */
        static void createEdge(BasicBlock* from, BasicBlock* to, const EdgeType type, const std::string& edgeLabel = "", bool isExceptional = false);

        /**
         * \brief Destructor, that will delete the ICFG pointers and clears the method Id and ICFG pointer pair container.
         */
        ~Edge();
        
        Edge(const Edge& edge);

        Edge& operator=(const Edge& edge);

        /**
         * \brief Gives back that the edge is exceptional or not.
         * \return Boolean value.bel
         */
        bool getIsExceptional() const;

        /**
         * \brief Set the edge to be exceptional edge.
         */
        void setIsExceptional() {isExceptional = true;};

        /**
         * \brief Gives back a pointer to a BasicBlock from this edge goes out.
         * \return Pointer to the BasicBlock.
         */
        const BasicBlock* getFrom() const;

        /**
         * \brief Gives back a pointer to a BasicBlock to this edge goes in.
         * \return Pointer to the BasicBlock.
         */
        const BasicBlock* getTo() const;

        /**
         * \brief Gives back the edge type.
         * \return EdgeType enum value.
         */
        const EdgeType getType() const;

        /**
         * \brief Gives back the edge label.
         * \return String value.
         */
        const std::string getLabel() const;
    };

}}

#endif