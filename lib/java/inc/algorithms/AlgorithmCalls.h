#ifndef _ALGORITHMCALLS_JAVA_H
#define _ALGORITHMCALLS_JAVA_H

/*! \file AlgorithmCalls.h
    \brief Contains the class `AlgorithmCalls' which contains algorithms in connection with function calls.
*/

#include "cfg/inc/cfg.h"

namespace columbus {  namespace java { namespace asg {

class CallsVisitor;

/**
* \en
* Contains algorithms in connection with function calls.
* Traverses the whole ASG and collects function calls. After that for each function the call
* nodes can be enumerated using the ::ConstIterator.
* (create iterator with function ::constIterator(NodeId function)).
* The nested class Relation represents a function call.
* The Algorithm does not modify the ASG. The edges are stored separately,
* they only points to appropriate nodes in the ASG.
* Therefore the Algorithm should be run once on the ASG and the collected information can be used after.
* Do not run the algorithm more times to get information on different functions.
* \_en
*
* \hu
* Fuggvenyhivasokat pontosito algoritmus kulonbozo heurisztikakra epitve. 
* \_hu
*/
class AlgorithmCalls : public Algorithm {
public:
  /**
  * \en
  * Nested class which represents a call-edge between the caller and called functions.
  * \_en
  *
  * \hu
  * A hivasi eleket reprezentalo beagyazott osztaly.
  * \_hu
  */
  class Relation {
    friend class AlgorithmCalls;
  public:
    /**
    * \en
    * .
    *
    * \param i ID of the called function.
    * \param n name of the relation.
    * \_en
    *
    * \hu
    * .
    * \_hu
    */
    Relation(NodeId i, const std::string& n) : to(i), name(n), weight(1)  {}
    /**
    * \en
    * Returns the ID of the called function.
    * \_en
    *
    * \hu
    * Returns the ID of the called function.
    * \_hu
    */
    NodeId getOtherEnd() const  {return to;}
    /**
    * \en
    * Returns the name of relation.
    * \_en
    *
    * \hu
    * .
    * \_hu
    */
    const std::string getName() const  {return name;}

    void incWeight(){weight++;}
    int getWeight() const {return weight;}

    bool operator==(const Relation& rel) const{
      return (to == rel.getOtherEnd());
    }
    bool operator<(const Relation& rel) const{
      return (to < rel.getOtherEnd());
    }

  private:
    NodeId to;
    std::string name;
    int weight;
  };

protected:
  typedef std::vector<Relation>   Calls;
  typedef std::map<NodeId,Calls>  Container;
  
  typedef std::set<NodeId> CallsSet;
  typedef std::map<NodeId, CallsSet> ContainerSet;

public:
  /**
  * \en
  * Nested class which enumerates the called functions of a function.
  * \_en
  *
  * \hu
  * Nested class which enumerates the called functions of a function.
  * \_hu
  */
    class ConstIterator {
        friend class AlgorithmCalls;
    private:
        ConstIterator(const Container* cont, const Factory* fact, NodeId function);
        ConstIterator(const Container* cont, const Factory* fact);
    public:
        struct State{
            static const int notCalledHasNextFunction;
            static const int notCalledHasNext;
        };
        /**
        * \en
        * Returns true if the next function call exist.
        * \_en
        *
        * \hu
        * Returns true if the next function call exist.
        * \_hu
        */
        bool hasNext() const;
        /**
        * \en
        * Returns the constant reference of the next funtion call (the Relation edge).
        * \_en
        *
        * \hu
        * Returns the constant reference of the next funtion call (the Relation edge).
        * \_hu
        */
        const Relation& next();

        bool hasNextFunction() const;
        NodeId nextFunction();
    private:
        const Container* container;
        const Factory* factory;
        int state;
        Container::const_iterator i;
        Calls::const_iterator j;
    };

  /**
  * \en
  * Creates and returns an iterator which enumerates the called functions of a function.
  *
  * \param function The ID of the caller function.
  * \_en
  *
  * \hu
  * Letrehoz es visszater egy iteratorral, ami az adott fuggveny altal hivott fuggvenyeket kepes bejarni.
  *
  * \param a hivo fuggveny ID-je.
  * \_hu
  */
  ConstIterator constMethodIterator(NodeId function) const  { return ConstIterator(&methodContainer,factory,function); }
  ConstIterator constMethodIterator() const { return ConstIterator(&methodContainer,factory); }
  /**
  * \en
  * Creates and returns an iterator which enumerates the called at the node.
  *
  * \param function The ID of the caller function.
  * \_en
  *
  * \hu
  * Letrehoz es visszater egy iteratorral, ami az adott kifejezes altal hivott fuggvenyeket kepes bejarni.
  *
  * \param a hivo kifejezes ID-je.
  * \_hu
  */
  ConstIterator constCallerIterator(NodeId function) const  { return ConstIterator(&callerContainer,factory,function); }
  ConstIterator constCallerIterator() const  { return ConstIterator(&callerContainer,factory); }

  /**
  * \en
  * Returns true if there are no called functions.
  * \_en
  *
  * \hu
  * Visszateres igaz ertekkel, ha nincs hivott fuggveny.
  * \_hu
  */
  bool isEmpty() const  { return callerContainer.empty(); }
  /**
  * \en
  * Returns the number of called functions.
  * \_en
  *
  * \hu
  * Visszateres a hivott fuggvenyek szamaval.
  * \_hu
  */
  const int getSize() const  { return callerContainer.size(); }

  /**
   * \brief Returns the number of call edges.
   */
  const unsigned int getCallEdgesCount() const;

  /**
  * \brief It gets the caller container for compare propose.
  * \return The converted caller container (without the method name).
  */
  void convertCallerContainer(std::map<columbus::NodeId, std::vector<columbus::NodeId> >& container) const;

public:
    enum WorkingMethod {
        wmNormal,  //computing call edges according to the static type of the call site
        wmCHA,     // computing call edges with the potential dynamic types of the call sites
        wmRTA,     // computing call edges with the potential instantiated dynamic types of the call sites
        wmPTA      // computing call edges with the Constraint Graph
    };

public:
  /**
  * \en
  * Constructor of AlgorithmCalls.
  * \_en
  *
  * \hu
  * \_hu
  */
  AlgorithmCalls(Factory& fact, WorkingMethod wm = wmNormal, columbus::cfg::AlgorithmCGCompare *cgCompare = NULL);
  /**
  * \en
  * .
  * \_en
  *
  * \hu
  * \_hu
  */
  virtual ~AlgorithmCalls();

  /**
  * \en
  * Collects the function call edges in the ASG.
  *
  * \_en
  *
  * \hu
  * Osszegyujti a methodushivasokat.
  * \_hu
  */
  void run();
  void run(NodeId function);

protected:
  Container methodContainer;
  Container callerContainer;

  Factory           *factory;
  AlgorithmCreates  algCreates;
  CallsVisitor      *callsVisitor;
  bool              firstRun;

public:
  void getCallerNodeKeys(std::set<NodeId>& keySet) const {
      keySet.clear();
      for(Container::const_iterator iter = callerContainer.begin(); iter != callerContainer.end(); ++ iter)
          keySet.insert(iter->first);
  }

  void getCallerMethodKeys(std::set<NodeId>& keySet) const {
      keySet.clear();
      for(Container::const_iterator iter = methodContainer.begin(); iter != methodContainer.end(); ++ iter)
          keySet.insert(iter->first);
  }

  void getCalledKeys(std::set<NodeId>& keySet) const {
      keySet.clear();
      for(Container::const_iterator iter = methodContainer.begin(); iter != methodContainer.end(); ++ iter)
          keySet.insert(iter->first);
  }

private:
    AlgorithmCalls(const AlgorithmCalls&);
    AlgorithmCalls& operator=(const AlgorithmCalls&);
};

}}}

#endif
