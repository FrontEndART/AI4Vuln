/*
 * Constraint.h
 *
 *  Created on: 2013.08.28.
 *      Author: ktorpi
 */

#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_

#include <string>
#include <boost/uuid/uuid.hpp>

#include "../common.h"
//#include "SymbolIdentifier.h"


namespace columbus { namespace symbolic {

class Constraint {
public:
    Constraint();
    Constraint(const Constraint& other);
    virtual ~Constraint();

    bool operator==( const Constraint& rhs) const;
    bool operator<( const Constraint& rhs) const;

    virtual operator std::string() const = 0;
    /*virtual const std::string stringRep() const = 0;

    virtual SymbolIdentifierSet getSymbolIdentifiers() const = 0;
    
    static std::string constraints2String(const ConstraintSet& constraitns);
    static std::string constraints2String(const std::vector<ConstraintSet>& pathCondition);
    static std::string constraintSetVector2String(const std::vector<ConstraintSet>& constraintSetVector);

    static ConstraintSet pathCondition2ConstraintSet(const std::vector<ConstraintSet>& pc);*/

    const boost::uuids::uuid& getId() const { return id; }

private:
    /** unique id for every constraint */
    boost::uuids::uuid id;
};

}}
#endif /* CONSTRAINT_H_ */
