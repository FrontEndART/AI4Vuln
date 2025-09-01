#ifndef _LIM_ListIteratorAssocCD_H_
#define _LIM_ListIteratorAssocCD_H_

#include "lim/inc/lim.h"


namespace columbus { namespace lim { namespace asg {

  class ListIteratorAssocACDEdge : public ListIteratorAssoc<base::Base, acdLinkInfo>
  {

  public:
    ListIteratorAssocACDEdge (const ListIteratorAssocACDEdge& iterator);
    virtual ~ListIteratorAssocACDEdge();
    short getLowMul() ;
    short getHighMul() ;
    const std::string& getName() ;

  protected:
    //Container::iterator it;

    //ListIteratorAssocACDEdge(AssocContainer *assocContainer, AssocIteratorContainer *aitContainer, const Factory* factory);
    ListIteratorAssocACDEdge(const Container *container, const Factory* factory, bool createAsBegin);

    // ez szerintem felesleges, mert "nem lehet elrontani", es az ellenorzest a bellitasnal kell csinalni
    // elvegzi a szukseges ellenorzeseket mielott visszaadna egy asszociacios erteket
    // a ListIteratorAssocUShort::getAssocClass is elvegzi ezeket az ellenorzeseket,
    // en csak kiraktam ezt egy kulon metodusba, hogy elkeruljem a copy-pastinget
    void selfTest() const;

    StrTable& _stable;
    
    friend class ClassDiagram;
  };


}}}
#endif

