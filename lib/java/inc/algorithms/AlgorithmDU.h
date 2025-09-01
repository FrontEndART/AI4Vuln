#ifndef _ALGORITHMDU_JAVA_H
#define _ALGORITHMDU_JAVA_H

/**
 * \file AlgorithmDU.h
 * \brief Contains the class `AlgorithmDU' which implements .
 *        Contains the JavaDUAsgNodePrinter class, which prints out a DUInfo.
 */

#include "java/inc/java.h"

namespace columbus {
namespace java {
namespace asg {

/**
 * \brief This is DUInfo printer class.
 */
class JavaDUAsgNodePrinter: public columbus::cfg::ASGNodePrinter {
    friend class VisitorDU;
    public:
    columbus::java::asg::ASGFactory& m_asgFactory;
    columbus::cfg::CFGFactory &m_cfgFactory;
    JavaDUAsgNodePrinter(columbus::java::asg::ASGFactory& asgFact, columbus::cfg::CFGFactory& cfgFact) :
            m_asgFactory(asgFact), m_cfgFactory(cfgFact) {
    }
    virtual const std::string toString(const NodeId) const;
};

/**
 * \brief Class for visit the MethodInvocations, for determining the function parameter's definitions.
 */
class VisitorParameters: public VisitorAbstractNodes {
protected:
    /**
     * \brief ASG Factory.
     */
    const columbus::java::asg::Factory *m_asgFactory;

    /**
     * \brief CFG Factory.
     */
    columbus::cfg::CFGFactory *m_cfgFactory;

    /** \brief It stores the method ids, which has parameter(s).
     *         The parameters will be post-processed,
     *         because of find the definition outside the ICFG
     */
    const std::vector<columbus::NodeId>& m_methods;

public:
    /**
     * \brief Constructor.
     * \param asgFactory [in] The ASG Factory.
     * \param cfgFactory [in] The CFG Factory.
     */
    VisitorParameters(columbus::java::asg::Factory* asgFactory, columbus::cfg::CFGFactory* cfgFactory, const std::vector<columbus::NodeId>& params);

    /**
     * \brief Destructor.
     */
    ~VisitorParameters();

    /** \brief Copy constructor. */
    VisitorParameters(const VisitorParameters& right);

    /** \brief Assignment operator. */
    VisitorParameters& operator=(const VisitorParameters& right);

    virtual void visit(const expr::MethodInvocation& node, bool callVirtualBase);
};

class AlgorithmDU: public Algorithm {
private:
    /** \brief ASG Factory. */
    columbus::java::asg::Factory *m_asgFactory;

    /** \brief CFG Factory. */
    columbus::cfg::CFGFactory *m_cfgFactory;

    /** \brief The printer class. */
    columbus::cfg::ASGNodePrinter m_printer;

    uint64_t memoryPeak;
    public:
    /**
     * \brief Constructor.
     * \param asgFactory [in] The ASG Factory.
     * \param cfgFactory [in] The CFG Factory.
     * \param duChains   [in] The AlgorithmDefUseChains class.
     */
    AlgorithmDU(columbus::java::asg::Factory &m_asgFactory, columbus::cfg::CFGFactory &cfgFactory);

    /** \brief Destructor. */
    ~AlgorithmDU();

    /** \brief Copy constructor. */
    AlgorithmDU(const AlgorithmDU& right);

    /** \brief Assignment operator. */
    AlgorithmDU& operator=(const AlgorithmDU& right);

    /**
     * \brief Creates the DU Informations from the ASG graph.
     * \param function [in] The nodeId from the colleting starts.
     */
    void run(const columbus::NodeId function = 0);
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

};

}
}
}

#endif
