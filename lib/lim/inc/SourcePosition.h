#ifndef _LIM_SourcePosition_H_
#define _LIM_SourcePosition_H_

#include "lim/inc/lim.h"

/**
* \file SourcePosition.h
* \brief Contains declaration of the SourcePosition class.
* \brief The it get atributes from 
*/

namespace columbus { namespace lim { namespace asg {
  /**
  * \brief SourcePosition class, which represents the SourcePosition node.
  */
  class SourcePosition  {
    public:

      // ---------- constructors  ----------

      SourcePosition (  RealizationLevel p_realizationLevel ,  unsigned p_line ,  unsigned p_column ,  unsigned p_endLine ,  unsigned p_endColumn) ;

      SourcePosition ();

      // ---------- Attribute getter function(s) ----------

      RealizationLevel getRealizationLevel() const ;
      unsigned getLine() const ;
      unsigned getColumn() const ;
      unsigned getEndLine() const ;
      unsigned getEndColumn() const ;

      // ---------- Attribute setter function(s) ----------

      void setRealizationLevel(RealizationLevel p_realizationLevel); 
      void setLine(unsigned p_line); 
      void setColumn(unsigned p_column); 
      void setEndLine(unsigned p_endLine); 
      void setEndColumn(unsigned p_endColumn); 
      /**
      * \internal
      * \brief Calculate SourcePosition type similarity.
      * \param nodeIf [in] The other node.
      */
      double getSimilarity(const SourcePosition& other) const;

      /**
      * \internal
      * \brief Calculate SourcePosition type hash.
      */
      NodeHashType getHash() const;
      // ---------- save function(s) ----------

      void save(io::BinaryIO &binIo) const ;
      // ---------- load function(s) ----------

      void load(io::BinaryIO &binIo);
      bool operator==(const SourcePosition& other) const;
      bool operator!=(const SourcePosition& other) const;
    protected:
       RealizationLevel m_realizationLevel;
       unsigned m_line;
       unsigned m_column;
       unsigned m_endLine;
       unsigned m_endColumn;
  };


}}}
#endif

