/*
 * Z3Constraint.h
 *
 *  Created on: 2013.08.28.
 *      Author: ktorpi
 */

#ifndef Z3CONSTRAINT_H_
#define Z3CONSTRAINT_H_

#include <map>
#include <string>
#include <symbolic/inc/constraint/Constraint.h>
#include "../constraint/Z3ConstraintExpression.h"


namespace columbus {
namespace symbolic {

class Z3Constraint : public Constraint {
private:
    Z3ConstraintExpression Z3Expr;

public:
    Z3Constraint(const Z3ConstraintExpression& expr);
    Z3Constraint(const Z3Constraint& other);
    virtual ~Z3Constraint();

    operator string() const override{
        return Z3Expr.getStrRep();
    }

   

    /*const Z3IntSymbolMap& getIntSymbols() const  { return Z3Expr.getIntSymbols(); }
    const Z3BoolSymbolMap& getBoolSymbols() const { return Z3Expr.getBoolSymbols(); }
    const Z3FloatSymbolMap& getFloatSymbols() const { return Z3Expr.getFloatSymbols(); }
    virtual const std::string stringRep() const { return Z3Expr.getStrRep(); }

    virtual SymbolIdentifierSet getSymbolIdentifiers() const;*/

};

} /* namespace symbolic */
} /* namespace columbus */
#endif /* Z3CONSTRAINT_H_ */
