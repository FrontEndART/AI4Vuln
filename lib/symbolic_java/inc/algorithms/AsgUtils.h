#ifndef _SYMBOLIC_JAVA_ASGUTILS_H_
#define _SYMBOLIC_JAVA_ASGUTILS_H_

#include "../common.h"

namespace columbus { namespace symbolic {

class AsgUtils {
public:
    //static NodeId getReturnType(const java::asg::Factory& factory, const java::asg::expr::MethodInvocation& methodInvoke, SmartDefinition thizObject);

    static bool isOverriddenBy(const java::asg::struc::MethodDeclaration& methodInChild, const java::asg::struc::MethodDeclaration& methodInParent);

    static bool isInsideAnnotation(const java::asg::base::Base& node);

    /**
    * Asg-ben, hogy a methodInvocation invokes éle rosszul van bekötve. Olyan eset
    * is elõfordulhat, hogy a hívás nyilvánvalóen egy statikus metódust hív, de a bekötött
    * metódus nem statikus. Ez akkor fordul elõ, amikor hibás maga a kód is.
    *
    * Ha ilyen van, ez a metódus SymbolicColumbusException-t dob.
    */
    static void checkBadStaticCall(const java::asg::struc::MethodDeclaration& mdecl, const java::asg::expr::MethodInvocation& methodInvoke);

private:

};

}}

#endif
