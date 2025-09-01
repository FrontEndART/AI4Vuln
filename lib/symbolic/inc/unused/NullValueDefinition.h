#ifndef _NULL_VALUE_DEFINITION_H_
#define _NULL_VALUE_DEFINITION_H_

namespace columbus { namespace symbolic {

    class NullValueDefinition: public DefinitionDispatcher<NullValueDefinition> {
    public:
        NullValueDefinition() : DefinitionDispatcher<NullValueDefinition> (11 % MAGIC_HASH) {}
        virtual bool isValueDefinition() const {return false;}

        virtual operator std::string() const { return "null"; }
        virtual bool opEqualImpl(const NullValueDefinition& def) const {return true;};
    };
}}

#endif
