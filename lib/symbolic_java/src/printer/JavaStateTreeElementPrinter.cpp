#include "../../inc/common.h"

using namespace columbus;
using namespace std;
using namespace columbus::java::asg;

namespace columbus { namespace symbolic {

    const std::string JavaStateTreeElementPrinter::toString(const NodeId id) const {
        stringstream ss;
        if (m_asgFactory.getExist(id)) {
            const base::Base& base = m_asgFactory.getRef(id);
            stringstream other;

            if (Common::getIsNormalMethod(base)) {
                other << (dynamic_cast<const struc::NormalMethod&> (base)).getName();
            } else if (Common::getIsVariableDeclaration(base)) {
                other << (dynamic_cast<const struc::VariableDeclaration&> (base)).getName();
            } else if (Common::getIsIdentifier(base)) {
                other << (dynamic_cast<const expr::Identifier&> (base)).getName();
            } else if (Common::getIsNewClass(base)) {
                const expr::NewClass& cl = dynamic_cast<const expr::NewClass&> (base);
                if (cl.getConstructor() != NULL && cl.getConstructor()->getParent() != NULL) {
                    const base::Named& named = dynamic_cast<const base::Named&> (m_asgFactory.getRef(cl.getConstructor()->getParent()->getId()));
                    other << named.getName();
                }
            } else if (Common::getIsNewArray(base)) {
            } else if (Common::getIsClass(base)) {
                other << (dynamic_cast<const struc::Class &> (base)).getName();
            } else if (Common::getIsMethod(base)) {
                other << (dynamic_cast<const struc::Method &> (base)).getName();
            } else if (Common::getIsInterface(base)) {
                other << (dynamic_cast<const struc::Interface &> (base)).getName();
            } else if (Common::getIsEnum(base)) {
                other << (dynamic_cast<const struc::Enum &> (base)).getName();
            } else if (Common::getIsEnumConstant(base)) {
                other << (dynamic_cast<const struc::EnumConstant &> (base)).getName();
            } else {
                other << "not implemented yet!";
            }

            std::string sss = other.str();
            ss << "Name: " << sss << " (id: " << id << ")";
        }
        else {
            if (id != 0)
                ss << "(id: " << id << ")";
            else
                ss << "";
        }

        return ss.str();
    }

}}
