#ifndef _TREE_ELEMENT_INTERFACE_H_
#define _TREE_ELEMENT_INTERFACE_H_

#include "../common.h"

namespace columbus { namespace symbolic {

    class ProxyTreeException {};

    template<class VTY, class ITY, class LESS> class TreeElementProxy;
    template<class VTY, class ITY, class LESS> class ProxyTree;

    template<class VTY, class ITY, class LESS> class TreeElement  {
        friend class TreeElementProxy<VTY, ITY, LESS>;
        friend class ProxyTree<VTY, ITY, LESS>;

    protected:
        VTY userObject;
        TreeElement* parent;
        TreeElement* container;
        std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS> elements;

    public:
        TreeElement(const VTY _userObject);
        TreeElement(const VTY _userObject, TreeElement* _parent, TreeElement* _container) : userObject(_userObject), parent(_parent), container(_container), elements() {}
        TreeElement(const TreeElement<VTY, ITY, LESS>&);
        virtual ~TreeElement();

        virtual inline TreeElement* getParent() { return parent;}
        virtual inline TreeElement* getContainer() { return container;}
        inline void setParent(TreeElement* parent) { this->parent = parent; }
        inline void setContainer(TreeElement* container) { this->container = container; }
        virtual std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS> getElements() const { return elements;}

        virtual inline bool hasParent() const { return parent!=NULL;}
        virtual inline bool hasContainer() const { return container!=NULL;}

        boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > operator[](const ITY& index);
        virtual TreeElement* obtainCopy() {return this;};
        void collectUserObjects(std::vector<VTY>& vec);
        virtual operator VTY() {return userObject;}
        void collectProxies(std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less>& proxies);

    private:
        void setUserObject(const VTY _userObject) {userObject=_userObject;}
        TreeElement<VTY, ITY, LESS>& operator=(const TreeElement<VTY, ITY, LESS>&);
    };

    /*template<class VTY, class ITY>
    class CommonProxyInterface {
    public:
        virtual ~CommonProxyInterface<VTY, ITY>() {};
        virtual boost::shared_ptr<CommonProxyInterface<VTY, ITY> > operator=(const VTY obj) = 0;
        virtual operator VTY&() = 0;
        virtual bool isNull() const = 0;
        virtual std::vector<ITY> getSearchIndexes() const = 0; 
    };*/

    template<class VTY, class ITY, class LESS>
    class TreeElementProxy : public boost::enable_shared_from_this<TreeElementProxy<VTY, ITY, LESS> >/*, public CommonProxyInterface<VTY, ITY>*/ {

    private:
        TreeElement<VTY, ITY, LESS>* owner;
        boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > context;
        ITY key;
        int compare(const TreeElementProxy<VTY, ITY, LESS>& rhs) const;

    public:
        struct less : std::function<bool (boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >)> {
            bool operator() (boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > a, boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > b) const {
                return (*a)<(*b);
            };
        };

        TreeElementProxy(TreeElement<VTY, ITY, LESS>* _owner, boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > _context, const ITY& _key) : owner(_owner), context(_context), key(_key) {}
        TreeElementProxy(boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > _context, const ITY& _key) : owner(NULL), context(_context), key(_key) {}
        TreeElementProxy(const TreeElementProxy<VTY, ITY, LESS>&);
        TreeElementProxy<VTY, ITY, LESS>& operator=(const TreeElementProxy<VTY, ITY, LESS>&);
        virtual ~TreeElementProxy() {};

        virtual operator VTY&() {return owner->userObject;}
        virtual bool isEmpty() const {return false;}

        boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > operator[](const ITY& index);
        //boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > operator[](boost::shared_ptr<const IndexType> index) ;
        virtual bool isNull() const { return owner==NULL;}
        virtual boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > operator=(const VTY obj);
        virtual TreeElement<VTY, ITY, LESS>* obtainCopy() ;
        TreeElement<VTY, ITY, LESS>* getParent() { return owner->getParent();}
        TreeElement<VTY, ITY, LESS>* getOwner() { return owner;}

        bool operator<(const TreeElementProxy<VTY, ITY, LESS>& rhs) const;
        bool operator==(const TreeElementProxy<VTY, ITY, LESS>& rhs) const;
        void collectProxies(std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less>& proxies);
        //virtual std::vector<ITY> getSearchIndexes() const;
    };

    template<class VTY, class ITY, class LESS>
    class ProxyTree {
    protected:
        TreeElement<VTY, ITY, LESS>* root;
        std::vector<TreeElement<VTY, ITY, LESS>*> contexts;

    public:
        ProxyTree(VTY obj) : root(new TreeElement<VTY, ITY, LESS>(obj)), contexts() {contexts.push_back(root);}
        ProxyTree(const ProxyTree<VTY, ITY, LESS>&);
        ProxyTree<VTY, ITY, LESS>& operator=(const ProxyTree<VTY, ITY, LESS>&);
        virtual ~ProxyTree();

        TreeElement<VTY, ITY, LESS>* createNewRootContext(const VTY _userObject, TreeElement<VTY, ITY, LESS>* parent) {TreeElement<VTY, ITY, LESS>* tail=new TreeElement<VTY, ITY, LESS>(_userObject, parent, NULL);contexts.push_back(tail);return tail;}
        inline TreeElement<VTY, ITY, LESS>* getRoot() { return root;}
        bool isSameContext(const TreeElement<VTY, ITY, LESS>* lhs, const TreeElement<VTY, ITY, LESS>* rhs, const TreeElement<VTY, ITY, LESS>* meet) const ;
    };

}}

#endif
