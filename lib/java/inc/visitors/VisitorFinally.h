#ifndef _JAVA_VISITORFINALLY_H_
#define _JAVA_VISITORFINALLY_H_

#include "java/inc/java.h"
#include <unordered_map>

namespace columbus { namespace java { namespace asg {

class VisitorFinally : public VisitorAbstractNodes {
private:
    ASGFactory &fact;


    std::map<NodeId, bool> ignoreList;
    std::vector<NodeId> finallyStack;
    std::vector<Collection> handlerStack;
    Collection handlers;

    std::map<std::string, NodeId>        labels;


    // vector needed, because one finally could be cloned more times
    // key: original node id value: vector of cloned finallies
	//std::map<NodeId, std::vector<NodeId>> *mapped_nodes;
    finallyBlockMap *mapped_nodes;

    std::map<NodeId, NodeId> *trueFalseMap;

    std::vector<std::string> package;

    std::string packagename, classname;

    std::string  getPackage() const;

    std::map<NodeId, std::string> methodToId;


	//typedef std::unordered_map<NodeId, std::vector<NodeId>> finallyBlockMap;
    // may be deprecated, mapped_nodes is better solution

public:
    VisitorFinally(ASGFactory& fact, std::map<NodeId, std::vector<NodeId>> *mapped_nodes);
    VisitorFinally(ASGFactory& fact, std::map<NodeId, std::vector<NodeId>> *mapped_nodes, std::map<NodeId, NodeId> *trueFalseMap);

    virtual ~VisitorFinally() {}

    /*
     * check if the the node with the given id is inside a try. if yes give back all the try nodes the contains the node
     * if found given NodeKind then stop.
     * @param id id of node that we want to check
     * @param stop at stop NodeKind when checking parents, needed for contiune, stop if parent for
     * 
     * @return vector containing the try nodes, in the order they would be excecuted
     */
    std::vector<statm::Try*> getTryBlocksIfInOne(NodeId id, std::set<NodeKind> stop); 

    NodeId popMappedClone(NodeId id);

    void copy(NodeId id, std::set<NodeKind> stop);

    const std::map<NodeId, std::string>& getMethodId()const;

   /*
    * @param id id of node that has finallies 
    * @id_finally id of finally to clone
    */
    void clone(NodeId id, NodeId id_finally);

    void visit(const statm::Continue& n, bool callVirtualBase);

    void visit(const statm::Break& n, bool callVirtualBase);

    void visit(const statm::Throw& n, bool callVirtualBase);

    void visit(const statm::Try& n, bool callVirtualBase);

    void visit(const statm::Return& n, bool callVirtualBase); 

    void visit(const statm::Handler& n, bool callVirtualBase);

    void visit(const struc::NormalMethod& n, bool callVirtualBase);

    void visit(const struc::CompilationUnit& n, bool callVirtualBase);
    void visitEnd(const struc::CompilationUnit& n, bool callVirtualBase);

    void visit(const struc::Package& n, bool callVirtualBase);
    void visitEnd(const struc::Package& n, bool callVirtualBase);

    void visit(const struc::TypeDeclaration& n, bool callVirtualBase);
    void visitEnd(const struc::TypeDeclaration& n, bool callVirtualBase);

    void visitEnd(const statm::Try& n, bool callVirtualBase);

    void visit(const expr::InfixExpression& n, bool callVirtualBase);

    void visit(const statm::LabeledStatement& n, bool callVirtualBase);

	void visitEnd(const statm::LabeledStatement& n, bool callVirtualBase);

    void finishVisit();
    
};

} } }

#endif
