#include <symbolic/inc/common.h>
#include <symbolic_java/inc/common.h>
#include "../../inc/messages.h"
#include "../../inc/checker/JavaSymbolicChecker.h"
#include "../../inc/rules/SymbolicRuleChecker.h"

#include "../../inc/rules/JavaSymbolicNPEChecker.h"
#include "../../inc/rules/JavaSymbolicDBZChecker.h"
#include "../../inc/rules/JavaSymbolicCCEChecker.h"
#include "../../inc/rules/JavaSymbolicINFChecker.h"
#include "../../inc/rules/JavaSymbolicIOBChecker.h"
#include "../../inc/rules/JavaSymbolicNASChecker.h"
#include "java/inc/visitors/VisitorFinally.h"
#include "java/inc/algorithms/AlgorithmPreorderFinally.h"
#include <common/inc/Stat.h>

using namespace std;
using namespace columbus;
using namespace common;

namespace columbus { namespace symbolic {

JavaSymbolicChecker::JavaSymbolicChecker(const std::string& limFileName, const std::string& rulFileName, const std::string& rulConfig) :
    columbus::Checker(limFileName, rulFileName, rulConfig), m_cfgFactory(NULL), m_asgFactory(NULL), m_alreadyExecuted(false)
{}

void JavaSymbolicChecker::initNewAsg(java::asg::Factory* asgFactory, java::asg::AlgorithmPreorder* preorder, WarningSuppressor* warningSuppressor) {
    m_asgFactory = asgFactory;
    m_cfgFactory = new cfg::CFGFactory(asgFactory->size(), NULL);
    warningSuppressor->addLineSuppressionMarker("NORH");
    for (std::list<RuleChecker*>::const_iterator checkerIt = ruleCheckers.begin(); checkerIt != ruleCheckers.end(); ++checkerIt) {
      dynamic_cast<SymbolicRuleChecker*>(*checkerIt)->setWarningSuppressor(warningSuppressor);
    }
    m_alreadyExecuted = false;
}

std::set<std::string> methodlist(const string& filepath) {
    std::set<std::string> aimethods;
    std::ifstream infile(filepath);
    std::string line;
    while (std::getline(infile, line))
    {
        aimethods.insert(line);
    }
    return aimethods;
}

void JavaSymbolicChecker::startExecutor(bool doNotRerun) 
{
    if (m_alreadyExecuted && doNotRerun)
        return;

    m_alreadyExecuted = true;
    
    m_asgFactory->turnFilterOff();

    SymbolicTypesPreVisitor::init();
    

    

    map<NodeId, NodeId> trueFalseMap;
    columbus::java::asg::finallyBlockMap mapFinally;

    columbus::java::asg::VisitorFinally vFinally(*m_asgFactory, &mapFinally, &trueFalseMap);
    columbus::java::asg::AlgorithmPreorderFinally pre;
    pre.run(*m_asgFactory, vFinally);

    SymbolicTypesPreVisitor types(m_asgFactory);
    columbus::java::asg::AlgorithmPreorder ap;
    ap.run(*m_asgFactory, types);
    

    columbus::java::asg::AlgorithmCFG cfg(*m_asgFactory, columbus::java::asg::AlgorithmCalls::wmRTA, NULL, &mapFinally, &trueFalseMap);
    cfg.run(m_cfgFactory);
    

    Configuration *config = Configuration::getInstance();
    if (config->getDumpCfgGraphml()) {
        common::WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_CFG_DUMP_BEGIN);
        columbus::java::asg::JavaAsgNodePrinter *j = new columbus::java::asg::JavaAsgNodePrinter(*m_asgFactory);
        columbus::cfg::CFG2Graphml graphml;
        graphml.convertCFG2Graphml(*m_cfgFactory, config->getAsgFile() + "_cfg.graphml", j);
        common::WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_CFG_DUMP_END);
    }

   
    unsigned int currentICFGNr = 1;
    NodeId methodId = 0;
    const columbus::cfg::ICFGContainer& icfgs = m_cfgFactory->getICFGContainer();
    
    TxtOutputWriter* txtWriter = NULL;
    CsvStateListener* csvListener = NULL;
    JsonOutputWriter* jsonWriter = NULL;

    txtWriter = new TxtOutputWriter(*m_asgFactory, *m_cfgFactory);
    jsonWriter = new JsonOutputWriter(*m_asgFactory, *m_cfgFactory);
    if (!config->getOutCsvFile().empty()) {
        csvListener = new CsvStateListener (*m_asgFactory, *m_cfgFactory);
    }
        
    unsigned int stateNumber=0;
    unsigned int exceptionalStateNumber=0;
    unsigned int numOfNonFilteredICFGs = 0; // for percent calculation
    for (columbus::cfg::ICFGContainer::const_iterator it = icfgs.begin(); it != icfgs.end(); ++it) {
        if (m_asgFactory->getFilterState(it->first) != columbus::java::asg::Filter::Filtered) {
            ++numOfNonFilteredICFGs;   
        }
    }
    std::set<std::string> aimethods = methodlist("methods.list");
    const map<NodeId, string>& methodNamesToId = vFinally.getMethodId();


    JavaSymbolicCheckerWarningListener warningListener(*m_asgFactory, ruleCheckers, ruleCheckers.front()->getCheckerID());
    JavaLimWriteListener limListener(*m_asgFactory, *m_cfgFactory, &getResultGraph(), warningListener);
    unsigned lastLogged = 0;
    for (columbus::cfg::ICFGContainer::const_iterator it = icfgs.begin(); it != icfgs.end(); ++it) {
        methodId = it->first;
        auto method_ptr = m_asgFactory->getPointer(methodId);
        int maxDepth = -1;
        java::asg::struc::Method* m = dynamic_cast<java::asg::struc::Method*>(method_ptr);
        if (m == nullptr) {
            continue;
        }

        if (!aimethods.empty()) {
            auto mIt = methodNamesToId.find(m->getId());
            if (mIt != methodNamesToId.end() && aimethods.find(mIt->second) != aimethods.end()) {
                cout << "Max depth: 350" << endl;
                maxDepth = 350;
            }
        }
        else {
            cout << "Max depth: 250" << endl;
            maxDepth = 250;
        }
        
        /*auto k = m->getAccessibility();
        if (k != columbus::java::asg::AccessibilityKind::ackPublic) {
            continue;
        }*/

        try 
        {
            if (m_asgFactory->getFilterState(methodId)==columbus::java::asg::Filter::Filtered) {
               /**
               *	This method would have been filtered out if filter was turned on
               */
               continue;
            }

            if (Configuration::getInstance()->getMethodFrom()!=0 && methodId!=Configuration::getInstance()->getMethodFrom()) continue;

            if (currentICFGNr >= lastLogged + (numOfNonFilteredICFGs / 100))
            {
              common::WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_SYMBOLIC_EXECUTION, methodId, currentICFGNr, (double)(currentICFGNr) * 100.0 / numOfNonFilteredICFGs);
              lastLogged = currentICFGNr;
            }

            currentICFGNr++;
			
			//DummyConstraintBuilder dcb;
			Z3Solver z3("z3");
			Z3ConstraintBuilder builder;
            SymbolicEngine engine(*m_cfgFactory, *m_asgFactory, &getRulHandler(), &z3, &builder, maxDepth);
            builder.setSymbolicEngine(&engine);
                    
            if (csvListener) {
                engine.addStateListener(csvListener);
            }
            if (txtWriter) {
                engine.addStateListener(txtWriter);
            }
            if (jsonWriter) {
                engine.addStateListener(jsonWriter);
            }
            limListener.setEngine(&engine);
            engine.addStateListener(&limListener);
            //engine->setWarningListener(&warningListener);

            SymbolicExecutor executor(*m_asgFactory, engine);
            StateFactoryJava stFactory(engine);
                
            engine.run(&stFactory, methodId);
            stateNumber+=engine.getStateNumber();
            exceptionalStateNumber+=engine.getExceptionalStateNumber();

            memstat memory = getProcessUsedMemSize();
            common::WriteMsg::write(CMSG_STAT_PEAK_MEMORY_USAGE, memory.size / (1024 * 1024));
        } 
        catch (const SymbolicColumbusException& exception) 
        {
            common::WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_SYMBOLIC_EXCEPTION, exception.what());
        }
        catch (const columbus::Exception& exception) 
        {
            common::WriteMsg::write(CMSG_SYM_JAVA_SYMBOLIC_CHECKER_COLUMBUS_EXCEPTION, exception.toString().c_str());
        }
    }

    limListener.printOutAllStackTrace();
    if (csvListener) {
        csvListener->printOutAllStackTrace();
        delete csvListener;
    }
    if (txtWriter) {
        txtWriter->printOutAllStackTrace();
        delete txtWriter;
    }
    if (jsonWriter) {
        jsonWriter->printOutAllStackTrace();
        delete jsonWriter;
    }

    common::WriteMsg::write(common::WriteMsg::mlNormal, "Exceptional states: %d/%d\n", exceptionalStateNumber, stateNumber);
}

void JavaSymbolicChecker::releaseAsg() {
    delete m_cfgFactory;
    m_cfgFactory = NULL;
    m_asgFactory = NULL;
}

JavaSymbolicChecker::~JavaSymbolicChecker() {
    releaseAsg();
}

cfg::CFGFactory* JavaSymbolicChecker::getCFGFactory() const {
    return m_cfgFactory;
}

java::asg::Factory* JavaSymbolicChecker::getASGFactory() const {
    return m_asgFactory;
}

}}
