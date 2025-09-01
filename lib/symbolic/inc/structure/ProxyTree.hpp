#ifndef _PROXY_TREE_CPP_
#define _PROXY_TREE_CPP_

#include "../../inc/common.h"

namespace columbus { namespace symbolic {

    template<class VTY, class ITY, class LESS>
    TreeElement<VTY, ITY, LESS>::TreeElement(const VTY _userObject) : userObject(_userObject), parent(NULL), container(NULL), elements() {
    }

    template<class VTY, class ITY, class LESS>
    TreeElement<VTY, ITY, LESS>::TreeElement(const TreeElement<VTY, ITY, LESS> &other) 
        : userObject(other.userObject), parent(other.parent), container(other.container), elements(other.elements) {
    }

    template<class VTY, class ITY, class LESS>
    TreeElement<VTY, ITY, LESS>::~TreeElement() {
        for (typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::const_iterator iter=elements.begin(); iter!=elements.end(); iter++)
            delete (*iter).second;
    }
    
    template<class VTY, class ITY, class LESS>
    TreeElement<VTY, ITY, LESS>& TreeElement<VTY, ITY, LESS>::operator=(const TreeElement<VTY, ITY, LESS>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        userObject = rhs.userObject;
        parent = rhs.parent;       // no deep copy here
        container = rhs.container; // no deep copy here
        elements = rhs.elements;
        
        return *this;
    } 

    template<class VTY, class ITY, class LESS>
    boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > TreeElement<VTY, ITY, LESS>::operator[](const ITY& index) {
        return (*boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >(new TreeElementProxy<VTY, ITY, LESS>(this, boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >(), index)))[index];
    }

    template<class VTY, class ITY, class LESS>
    void TreeElement<VTY, ITY, LESS>::collectUserObjects(std::vector<VTY>& vec) {
        vec.push_back(userObject);
        for (typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::const_iterator iter=elements.begin(); iter!=elements.end(); iter++) {
            (*iter).second->collectUserObjects(vec);
        }
    }

    template<class VTY, class ITY, class LESS>
    void TreeElement<VTY, ITY, LESS>::collectProxies(std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less>& proxies) {
        for (typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::const_iterator iter=elements.begin(); iter!=elements.end(); iter++) {
            operator[]((*iter).first)->collectProxies(proxies);
        }
    }

    template<class VTY, class ITY, class LESS>
    boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > TreeElementProxy<VTY, ITY, LESS>::operator[](const ITY& index) {
        typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::const_iterator iter = owner->elements.find(index);
        if (iter != owner->elements.end()) { // megvan a keresett
            return boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >(new TreeElementProxy<VTY, ITY, LESS>((*iter).second, this->shared_from_this(), index));
        } else if (owner->hasParent()) {   // a szulo TreeElementben keressuk
            return (*boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >(new TreeElementProxy<VTY, ITY, LESS>(owner->getParent(), this->shared_from_this(), key)))[index];
        }

        return boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >(new TreeElementProxy<VTY, ITY, LESS>(this->shared_from_this(), index)); // owner == NULL
    }

    template<class VTY, class ITY, class LESS>
    TreeElement<VTY, ITY, LESS>* TreeElementProxy<VTY, ITY, LESS>::obtainCopy() {
        if (context.get()!=NULL) {
            if (context->getParent()==owner) {
                //we have a lift at this point
                return context->obtainCopy();
            }
            TreeElement<VTY, ITY, LESS>* copyOfContext=context->obtainCopy();
            TreeElement<VTY, ITY, LESS>* newElement=NULL;
            if (copyOfContext!=context->owner) {
                //we have a new context at this point
                newElement=new TreeElement<VTY, ITY, LESS>(owner->userObject, owner, copyOfContext);
            } else {
                if (context->owner==owner->getContainer()) {
                    return owner->obtainCopy();
                } else {
                    //making a copy
                    newElement=new TreeElement<VTY, ITY, LESS>(owner->userObject, owner, context->owner);
                }
            }
            typename std::map<ITY, TreeElement<VTY, ITY, LESS>*,LESS>::iterator iter=copyOfContext->elements.find(key);
            if (iter!=copyOfContext->elements.end()) {
                delete (*iter).second;
                copyOfContext->elements.erase(iter);
            }
            copyOfContext->elements.insert(typename std::map<ITY, TreeElement<VTY, ITY, LESS>*,LESS>::value_type(key, newElement));  
            return newElement;
        } else {
            return owner;
        }
    }

    template<class VTY, class ITY, class LESS>
    boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > TreeElementProxy<VTY, ITY, LESS>::operator=(const VTY obj) {
       
        if (context.get()==NULL) {
            owner->setUserObject(obj);
        } else {
            TreeElement<VTY, ITY, LESS>* copycontext=context->obtainCopy();
            typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::iterator iter=copycontext->elements.find(key);
            if (iter!=copycontext->elements.end()) {
                //we already have this key....we just rewrite the value
                (*iter).second->setUserObject(obj);
            } else {
                //the key does not exist yet
                TreeElement<VTY, ITY, LESS>* newElement = new TreeElement<VTY, ITY, LESS>(obj, owner, copycontext);
                copycontext->elements.insert(typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::value_type(key, newElement));
                owner=newElement;
            }
        }
        return this->shared_from_this();
    }

    template<class VTY, class ITY, class LESS>
    int TreeElementProxy<VTY, ITY, LESS>::compare(const TreeElementProxy<VTY, ITY, LESS>& rhs) const {
        if (context==NULL && rhs.context==NULL)
            return 0;
        if (context==NULL && rhs.context!=NULL)
            return -1;
        if (context!=NULL && rhs.context==NULL)
            return +1;
        int compareContext=context->compare(*rhs.context);
        if (compareContext<0)
            return -1;
        if (compareContext>0)
            return +1;
        if (!LESS().operator()(key,rhs.key) && !LESS().operator()(rhs.key, key)) //TODO: ide majd egyenloseg operetorra lesz szukseg....teljes rendezes van feltetelezve
            return 0;
        if (LESS().operator()(key,rhs.key))
            return -1;
        return +1;
    }

    template<class VTY, class ITY, class LESS>
    bool TreeElementProxy<VTY, ITY, LESS>::operator<(const TreeElementProxy<VTY, ITY, LESS>& rhs) const {
        return compare(rhs)<0;
    }
    template<class VTY, class ITY, class LESS>
    bool TreeElementProxy<VTY, ITY, LESS>::operator==(const TreeElementProxy<VTY, ITY, LESS>& rhs) const {
        if (compare(rhs)!=0) return false;
        return owner->userObject==rhs.owner->userObject;
    }

    template<class VTY, class ITY, class LESS>
    void TreeElementProxy<VTY, ITY, LESS>::collectProxies(std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less>& proxies) {
        proxies.insert(this->shared_from_this());
        for (typename std::map<ITY, TreeElement<VTY, ITY, LESS>*, LESS>::const_iterator iter=owner->elements.begin(); iter!=owner->elements.end(); iter++) {
            operator[]((*iter).first)->collectProxies(proxies);
        }
    }

    /*template<class VTY, class ITY, class LESS>
    std::vector<ITY> TreeElementProxy<VTY, ITY, LESS>::getSearchIndexes() const {
        std::vector<ITY> indexes;
        indexes.push_back(key);
        boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > nextContext = context;
        while (nextContext) {
            ITY& key = nextContext->key;
            if (indexes.back() != key) { // in case of SmartDefinitions compare the pointer inside
                indexes.push_back(key);
            }
            nextContext = nextContext->context;
        }

        return indexes;
    }*/

    template<class VTY, class ITY, class LESS>
    bool ProxyTree<VTY, ITY, LESS>::isSameContext(const TreeElement<VTY, ITY, LESS>* lhs, const TreeElement<VTY, ITY, LESS>* rhs, const TreeElement<VTY, ITY, LESS>* meet) const {
        
        typename std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less> lProxies;
        typename std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less> rProxies;
        TreeElement<VTY, ITY, LESS>* temp=const_cast<TreeElement<VTY, ITY, LESS>*>(lhs);
        while (temp!=NULL /*&& temp!=meet*/) {
            temp->collectProxies(lProxies);
            temp=temp->getParent();
        }
        temp=const_cast<TreeElement<VTY, ITY, LESS>*>(rhs);
        while (temp!=NULL /*&& temp!=meet*/) {
            temp->collectProxies(rProxies);
            temp=temp->getParent();
        }
        for (typename std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less>::iterator iter=lProxies.begin(); iter!=lProxies.end(); iter++) {
            boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > lProxy=(*iter);
            typename std::set<boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> >, typename TreeElementProxy<VTY, ITY, LESS>::less>::iterator searchIter=rProxies.find(lProxy);
            if (searchIter==rProxies.end())
                return false;
            boost::shared_ptr<TreeElementProxy<VTY, ITY, LESS> > rProxy=(*searchIter);
            VTY& lValue=*lProxy;
            VTY& rValue=*rProxy;

            if (!(*lValue==*rValue))
                return false;
            rProxies.erase(searchIter);
        }
        if (!rProxies.empty())
            return false;
        return true;
    }

    template<class VTY, class ITY, class LESS>
    ProxyTree<VTY, ITY, LESS>::~ProxyTree() {
        for (typename std::vector<TreeElement<VTY, ITY, LESS>*>::iterator iter=contexts.begin(); iter!=contexts.end(); iter++)
            delete (*iter);
    }

}}

#endif
