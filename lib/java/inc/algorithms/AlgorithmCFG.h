#ifndef _ALGORITHMCFG_JAVA_H
#define _ALGORITHMCFG_JAVA_H

#include "java/inc/java.h"
#include "cfg/inc/cfg.h"
#include <unordered_map>

namespace columbus { namespace java { namespace asg {

typedef std::map<NodeId, std::vector<NodeId>> finallyBlockMap;
typedef std::set <NodeId> Collection;
typedef std::map<NodeId, Collection>  Container;
typedef columbus::java::asg::Factory ASGFactory;

class JavaAsgNodePrinter : public columbus::cfg::ASGNodePrinter {
    friend class VisitorCFG;
public: 
    const ASGFactory& m_asgFact;
    JavaAsgNodePrinter(const ASGFactory& asgFact) : m_asgFact(asgFact){}
    virtual const std::string toString (const NodeId) const;
};

class AlgorithmCFG : public Algorithm {
private:
    finallyBlockMap *mapFinally;
    std::map<NodeId, NodeId> *trueFalseMap;
public:
    static const std::string STATIC_INIT_POST_NAME;
    static const std::string INSTANCE_INIT_POST_NAME;
    static const std::string ENUM_INIT_POST_NAME;

    /**
    * \brief Constructor for AlgorithmCFG
    * \param asgFact            [in] ASG
    * \param workingMethod      [in] for function call collecting
    */
	AlgorithmCFG(ASGFactory& fact, AlgorithmCalls::WorkingMethod wm = AlgorithmCalls::wmRTA, columbus::cfg::AlgorithmCGCompare *cgCompare = NULL, finallyBlockMap *mapFinally = nullptr, std::map<NodeId, NodeId> *trueFalseMap = nullptr);
    virtual ~AlgorithmCFG ();
    /**
    * \brief Returns the calls of the methods and expressions.
    * \return const pointer to AlgorithmCalls
    */
    const AlgorithmCalls* getAlgorithmCalls(){ return m_algCalls; }
    /**
    * \brief Creates the CFG from the input node
    * \param cfgFact    [in-out] factory for the CFG
    * \param node       [in] starting node of the algorithm (0=root)
    */
    void run(columbus::cfg::CFGFactory *_cfgFact, NodeId method = 0);
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

    /**
    * \brief It set the printStatementBorder member variable. If it is set, the statements begin with special node id (STATEMENT_BEGIN_ID)
             will be printed out into the CFG.
    * \param _set [in] Value of printStatementBorder.
    */
    void setPrintStatementBorder(bool _set);
	
private:
    ASGFactory                    &m_asgFactory;
    columbus::cfg::CFGFactory     *m_cfgFactory;
    AlgorithmCalls                *m_algCalls;
    uint64_t                      memoryPeak;
    bool                          m_printStatementBorder;

private:
    AlgorithmCFG(AlgorithmCFG&);
    AlgorithmCFG& operator=(const AlgorithmCFG&);
};
}}}
#endif
