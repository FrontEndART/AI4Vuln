#ifndef _BASE_INTERFACE_H_
#define _BASE_INTERFACE_H_

namespace columbus { namespace symbolic {

    class BaseInterface {
    public:
        virtual ~BaseInterface() {}

        template<class U>
        operator U&() {
            return dynamic_cast<U&>(*this);
        }

        template<class U>
        operator const U&() const {
            return dynamic_cast<const U&>(*this);
        }
    };
}}

#endif
