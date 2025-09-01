#ifndef SYMBOLIDENTIFIER_H
#define SYMBOLIDENTIFIER_H

#include <boost/shared_ptr.hpp>
#include "../structure/SymbolicCommon.h"
//#include "../common.h"


namespace columbus { namespace symbolic {

class State;
    
class SymbolIdentifier {

private:
    static unsigned long nextId;
    unsigned long id;
    
public:
    SymbolIdentifier();
    virtual ~SymbolIdentifier();
    
    virtual bool operator<(const SymbolIdentifier& rhs) const = 0;
    virtual void buildBackDefinitionInToProxyTree(State& state, const SmartDefinition& definition) const = 0;
    virtual SmartDefinitionProxy serachInProxyTree(State& state) const = 0;
    virtual std::string toString() const = 0; 

    virtual bool isNodeIdSymbolIdentifier() const { return false; }
    virtual bool isLocalSymbolLocation() const { return false; }
    virtual bool isHeapSymbolLocation() const { return false; }
    virtual bool isStaticSymbolLocation() const { return false; }

    // getters
    const unsigned long& getId() const { return id; }
   
    friend std::ostream& operator<<(std::ostream& ostream, const SymbolIdentifier& id) {
        std::string s(id.toString());
        return ostream << id.toString();
    }

};

typedef boost::shared_ptr<const SymbolIdentifier> SmartSymbolIdentifier;

struct SymbolIdLess {
    bool operator()(SmartSymbolIdentifier s0, SmartSymbolIdentifier s1) const { return s0->getId() < s1->getId(); }
};

typedef std::set<SmartSymbolIdentifier, SymbolIdLess > SymbolIdentifierSet;

}}

#endif // SYMBOLIDENTIFIER_H
