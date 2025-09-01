#ifndef COMMON_SA_PROBLEM_H
#define COMMON_SA_PROBLEM_H
#include<boost/nondet_random.hpp>
#include<boost/random.hpp>
#include<boost/random/bernoulli_distribution.hpp>

namespace columbus { namespace math {
  class SimulatedAnnealingState {
  };

  class SimulatedAnnealingProblem {
    protected:
    SimulatedAnnealingState* currentState;
    double currentValue;
    double T;
    boost::mt19937 rng;

  public:
    SimulatedAnnealingProblem(const SimulatedAnnealingProblem& sa);
    SimulatedAnnealingProblem& operator=(const SimulatedAnnealingProblem& sa);
    virtual SimulatedAnnealingState* getNeighbour() = 0;
    virtual double Energy(SimulatedAnnealingState* state) = 0;
    virtual ~SimulatedAnnealingProblem() {};

    SimulatedAnnealingProblem(SimulatedAnnealingState* _currentState, double _T);
    bool makeTransition() {
      SimulatedAnnealingState* neighbour=getNeighbour();
      double nextValue=Energy(neighbour);
      bool step=false;
      if (nextValue<currentValue) {
        boost::bernoulli_distribution<> B(1);                              
        boost::variate_generator<boost::mt19937&, boost::bernoulli_distribution<> >
           die(rng, B);  
        step=die();
      } else {
        boost::bernoulli_distribution<> B(exp((currentValue-nextValue)/T));                              
        boost::variate_generator<boost::mt19937&, boost::bernoulli_distribution<> >
           die(rng, B);  
        step=die();
        step=false;
      }
      if (step) {
        std::cout << ";T" << std::endl;
        currentState=neighbour;
        currentValue=nextValue;
        return true;
      } else {
        std::cout << ";F" << std::endl;
      }
      return false;
    }
    void run() {
      currentValue=Energy(currentState);
      while (true) {
        makeTransition();
        T=T-1;
        if (T<0)
          T=0;
        std::cerr << "Temp=" << T << std::endl;
      }
    }
  };
}}

#endif
