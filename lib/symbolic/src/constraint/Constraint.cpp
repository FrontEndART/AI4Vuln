/*
 * Constraint.cpp
 *
 *  Created on: 2013.08.28.
 *      Author: ktorpi
 */

#include "../../inc/common.h"

#include <string>
#include <sstream>
#include <boost/uuid/uuid_generators.hpp>

using namespace std;

namespace columbus {
namespace symbolic {

Constraint::Constraint() : id(boost::uuids::random_generator()()) {
}

Constraint::Constraint(const Constraint& other) : id(other.id) {
}

Constraint::~Constraint() {
    // TODO Auto-generated destructor stub
}


bool Constraint::operator==(const Constraint& rhs) const {
    return id == rhs.id;
}

bool Constraint::operator<(const Constraint& rhs) const {
    return id < rhs.id;
}

/*string Constraint::constraints2String(const ConstraintSet& constraints) {
    stringstream ss;
    vector<string> constraintVector;
    for (ConstraintSet::const_iterator it = constraints.begin(); it != constraints.end(); ++it) {
        constraintVector.push_back((**it).stringRep());
    }
    sort(constraintVector.begin(), constraintVector.end());
    for (vector<string>::iterator it = constraintVector.begin(); it != constraintVector.end(); ++it) {
        ss << "(" << *it << ")" << ((it == constraintVector.end() - 1) ? "" : " && ");
    }
    return ss.str();
}

string Constraint::constraints2String(const vector<ConstraintSet>& pathCondition) {
    ConstraintSet cs = pathCondition2ConstraintSet(pathCondition);
    return constraints2String(cs);
}

string Constraint::constraintSetVector2String(const vector<ConstraintSet>& constraintSetVector) {
    stringstream ss;
    for (vector<ConstraintSet>::const_iterator it = constraintSetVector.begin(); it != constraintSetVector.end(); ++it) {
        ss << constraints2String(*it) << ((it == constraintSetVector.end() - 1) ? "" : "   |   ");
    }
    return ss.str();
}

ConstraintSet Constraint::pathCondition2ConstraintSet(const vector<ConstraintSet>& pc) {
    ConstraintSet set;
    for (vector<ConstraintSet>::const_iterator it = pc.begin(); it != pc.end(); ++it) {
        set.insert(it->begin(), it->end());
    }
    return set;
}*/



} /* namespace symbolic */
} /* namespace columbus */
