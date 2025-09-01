#ifndef _JAVA_STATE_TREE_ELEMENT_PRINTER_H_
#define _JAVA_STATE_TREE_ELEMENT_PRINTER_H_

#include <sstream>
#include <cfg/inc/cfg.h>
#include <java/inc/java.h>

namespace columbus { namespace symbolic {
    /**
    * \brief This is the State-Tree element printer class.
    */
    class JavaStateTreeElementPrinter : public columbus::cfg::ASGNodePrinter {
    public:
        columbus::java::asg::ASGFactory& m_asgFactory;
        columbus::cfg::CFGFactory &m_cfgFactory;

        JavaStateTreeElementPrinter(columbus::java::asg::ASGFactory& asgFact, columbus::cfg::CFGFactory& cfgFact) : m_asgFactory(asgFact), m_cfgFactory(cfgFact) {
        }

        virtual const std::string toString(const NodeId) const;
    };

}}

#endif
