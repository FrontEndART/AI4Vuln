#ifndef _STATE_JAVA_H_
#define _STATE_JAVA_H_

#include "symbolic/inc/structure/State.h"
#include "symbolic/inc/constraint/ConstraintSolverExpr.h"
#include <map>
#include <vector>

namespace columbus { namespace symbolic {

        class StateJava : public State {
            friend class StateFactoryJava;

        private:
            /**
             * Because the negated actual constraint on a false branch created explicitly, have to store,
             * and delete the pointer explicitly. Deleted in destructor.
             */
            Constraint* negatedConstraint;

            void buildPathCondition();
            NodeId getLastBooleanExprId(const State& state, bool& isFromSwitch) const;
            std::string convertPathCondition() const;
        

        protected:
            StateJava(const columbus::cfg::BasicBlock& bb, StateFactory& stateFactory);
            StateJava(State& parent, const columbus::cfg::BasicBlock& bb, int _edgeKind);
            virtual ~StateJava();
            bool onTrueBranch() const;

        public:
            virtual SmartDefinition addNewHeapObject(SmartDefinition obj, columbus::NodeId referenceType);
            virtual SmartDefinition getHeapObject(SmartDefinition reference, columbus::NodeId nodeId);
            virtual bool hasheapObject(SmartDefinition reference) const;
            virtual void checkingNPE(SmartDefinition reference, columbus::NodeId nodeId);
            virtual bool isNullDerefenece(SmartDefinition reference) const;
            Solution solve_wrapper(const string& accumulated, const std::set<std::shared_ptr<ConstraintSolverExpr>>& variables);
            bool isPathValid() const override;
        };

}}

#endif
