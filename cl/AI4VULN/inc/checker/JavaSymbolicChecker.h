#ifndef _JAVA_SYMBOLIC_CHECKER_H_
#define _JAVA_SYMBOLIC_CHECKER_H_

#include <rulechecker/inc/Checker.h>
#include <cfg/inc/cfg.h>
#include "symbolic/inc/algorithms/SymbolicEngine.h"
#include "symbolic_java/inc/algorithms/SymbolicExecutor.h"

namespace columbus { namespace symbolic {

class SymbolicRuleChecker;

class JavaSymbolicChecker : public columbus::Checker {

    public:
        JavaSymbolicChecker(const std::string& limFileName, const std::string& rulFileName, const std::string& rulConfig);
        virtual void initNewAsg(java::asg::Factory* asgFactory, java::asg::AlgorithmPreorder* preorder, WarningSuppressor* warningSuppressor);
        virtual void releaseAsg();
        virtual ~JavaSymbolicChecker();

        virtual cfg::CFGFactory* getCFGFactory() const;
        virtual java::asg::Factory* getASGFactory() const;

        void startExecutor(bool doNotRerun = false);
        void setEngine(SymbolicEngine& _engine) { engine=&_engine;}
        SymbolicEngine& getEngine() { return *engine;}

    protected:
        // Deliberately not implemented
        JavaSymbolicChecker(const JavaSymbolicChecker& c);

    protected:
        cfg::CFGFactory    *m_cfgFactory;
        java::asg::Factory *m_asgFactory;
        SymbolicEngine *    engine;
        bool                m_alreadyExecuted;
};

}}

#endif
