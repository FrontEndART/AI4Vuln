#ifndef _ALGORITHMCG_JAVA_H
#define _ALGORITHMCG_JAVA_H

#include "java/inc/java.h"
#include <queue>

namespace columbus {
    namespace java {
        namespace asg {

            /**
             * \brief This is CG printer class.
             */
            class JavaCGNodePrinter : public columbus::cfg::ASGNodePrinter {
            public:
                columbus::java::asg::ASGFactory& m_asgFactory;
                columbus::cfg::CFGFactory &m_cfgFactory;

                JavaCGNodePrinter(columbus::java::asg::ASGFactory& asgFact, columbus::cfg::CFGFactory& cfgFact) : m_asgFactory(asgFact), m_cfgFactory(cfgFact) {
                }
                virtual const std::string toString(const NodeId) const;
            };

            class AlgorithmCG : public Algorithm {
                typedef enum {CG_NORMAL_SELECTOR, CG_ARRAY_SELECTOR, CG_NEW_SELECTOR} CGSelectorType;

            private:
            public:

                /**
                 * \brief Constructor.
                 * \param cfgFactory [in] The CFG Factory.
                 * \param asgFactory [in] The ASG Factory.
                 * \param cgFactory  [in] The CG Factory.
                 */
                AlgorithmCG(const columbus::cfg::CFGFactory* cfgFactory, columbus::java::asg::ASGFactory* asgFactory, columbus::cfg::CGFactory* cgFactory);

                /** \brief Destructor. */
                ~AlgorithmCG();

                /**
                 * \brief Creates the Constrain Graph from DU informations.
                 */
                void run();

                /**
                * \brief Checker function for the algorithm's memory usage
                */
                void updateMemoryStat();

                /**
                * \brief Returns the size of algorithm's used memory (actually this value should be divided by (1024*1024)
                *        to get the proper used memory size in MB).
                * \return size of the used memory
                */
                const uint64_t getMemoryPeak() const;

            private:
                /** \brief CFG Factory. */
                const columbus::cfg::CFGFactory *m_cfgFactory;

                /** \brief ASG Factory. */
                columbus::java::asg::ASGFactory *m_asgFactory;

                /** \brief CG Factory. */
                columbus::cfg::CGFactory *m_cgFactory;

                /** \brief The method newInstance ID - for creating ALOC. */
                columbus::NodeId m_reflectionNewInstanceMethodId;

                /** \brief The Field class ID - for UNKNOWN Node. */
                columbus::NodeId m_reflectionFieldClassId;

                /** \brief The Method class ID - for UNKNOWN Node. */
                columbus::NodeId m_reflectionMethodClassId;

                uint64_t memoryPeak;

            private:
                /** \brief Copy constructor. */
                AlgorithmCG(const AlgorithmCG& orig);

                /** \brief Assignment operator. */
                AlgorithmCG& operator=(const AlgorithmCG& orig);


                /**
                 * \brief Finds the class ID from the ASG of the given node ID.
                 * \param nodeId  [in] The node ID.
                 * \return The class ID.
                 */
                columbus::NodeId extractClassId(const columbus::NodeId nodeId) const;

                /**
                 * \brief Finds the class ID from the ASG of the given ASG node.
                 * \param asgNode  [in] The ASG ID.
                 * \return The class ID.
                 */
                columbus::NodeId extractClassId(const base::Base *asgNode) const;

                /**
                 * \brief It checks if the given nodeId is primitive type.
                 * \param nodeId  [in] The node ID.
                 * \return True if the ASG node (belongs to nodeId) is primitive type, otherwise false.
                 */
                bool isNodePrimitive(columbus::NodeId nodeId) const;

                /**
                 * \brief It checks if the given ASG node is primitive type.
                 * \param asgNode  [in] The ASG ID.
                 * \return True if the ASG node is primitive type, otherwise false.
                 */
                bool isNodePrimitive(const base::Base *asgNode) const;

                /**
                 * \brief It checks if the given type expression is primitive type.
                 * \param typeExpression  [in] The node ID.
                 * \return True if the type expression is primitive type, otherwise false.
                 */
                bool isNodePrimitive(const expr::TypeExpression *typeExpression) const;

                /**
                 * \brief It checks if the given nodeId is static.
                 * \param nodeId  [in] The node ID.
                 * \return True if the ASG node (belongs to nodeId) is static type, otherwise false.
                 */
                bool isNodeStatic(columbus::NodeId nodeId) const;

                /**
                 * \brief This function must be run before the visitNode. It collects the required informations for Reflection.
                 * For example the Method/Field class ID, newInstance method ID. This function is required for UNKNOWN Node.
                 */
                void findReflections();

                /**
                 * \brief It creates nodes, edges and ALOCs for the given ASG. This is invoked by newClass and newArray.
                 * \param asgNode  [in] The ASG node.
                 * \param nodeKind [in] ndkNewClass or ndkNewArray.
                 */
                columbus::cfg::CGNode& processNew(const base::Base *asgNode, const columbus::java::asg::NodeKind nodeKind) const;

                /**
                 * \brief It creates nodes and edges for the given ASG Class node and its members.
                 * \param asgNode  [in] The ASG class node.
                 */
                void processClassMembers(const base::Base *asgNode) const;

                /**
                 * \brief It creates nodes and edges between a CG Node and a DU Info. The second parameter (toDUInfo) maybe is a complex expression,
                 * so edges will be created to descriptor, selectors, ... of the second parameter.
                 * \param fromNode      [in] The start point of edges.
                 * \param toDUInfo      [in] The end point of edges.
                 * \param fullContains  [in] The first edges has to be constraint edges.
                 */
                void CGNodeToDU(columbus::cfg::CGNode& fromNode, columbus::cfg::DUInfo *toDUInfo, const bool fullContains) const;

                /**
                 * \brief It creates nodes and edges between two DU Infos. The first parameter (left) maybe is a complex expression,
                 * so edges will be created from descriptor, selectors, ... of the first parameter. It invokes the CGNodeToDU function.
                 * \param left      [in] The start point of edges.
                 * \param right     [in] The end point of edges.
                 */
                void DUToDU(columbus::cfg::DUInfo *left, columbus::cfg::DUInfo *right) const;

                /**
                 * \brief It creates nodes and edges between a DU Info and a CG Node. The first parameter (left) maybe is a complex expression,
                 * so edges will be created from descriptor, selectors, ... of the first parameter.
                 * \param left      [in] The start point of edges.
                 * \param toNode    [in] The end point of edges.
                 */
                void DUToCGNode(columbus::cfg::DUInfo *left, columbus::cfg::CGNode& toNode) const;

                /**
                 * \brief It gets the descriptor of a DU Info. The descriptor is at the most deeper descriptor in the ASG (for example it is a Variable's descriptor).
                 * \param duInfo   [in] The DU Info.
                 * \return A node id, which is the descriptor of the duInfo.
                 */
                columbus::cfg::DUInfo* getDefinedNode(const columbus::cfg::DUInfo *duInfo) const;

                /**
                 * \brief It gets a DU Info which is an AddressInfo and defined by the duInfo parameter.
                 * \param duInfo   [in] The DU Info.
                 * \return A DU Info (AddressInfo), which is defined by the parameter.
                 */
                columbus::NodeId getDescriptor(columbus::cfg::DUInfo *du) const;

                /**
                 * \brief It gets the order of node ids of a DU Info. First the descriptor, then the first select backwards, ...
                 * \param selector    [in] The DU Info.
                 * \param order      [out] The order of node ids.
                 */
                void getSelectorOrder(columbus::cfg::DUInfo *selector, std::queue<std::pair<columbus::NodeId, CGSelectorType> >& order) const;

                /**
                 * \brief This function visit a DU Info, and invokes the corresponding function to create the Constraint Graph.
                 * \param duInfo   [in] The DU info.
                 */
                void visitNode(columbus::cfg::DUInfo *duInfo) const;
            };
        }
    }
} //End of namespaces
#endif
