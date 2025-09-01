#ifndef _LIM_Forwards_H_
#define _LIM_Forwards_H_

/**
* \file Forwards.h
* \brief Contains forward declarations of the classes.
*/

namespace columbus { namespace lim { namespace asg {

  class Algorithm;
  class AlgorithmPreorder;
  class ReverseEdges;

  class Visitor;
  class VisitorAbstractNodes;
  class VisitorGraphml;
  class VisitorLIMML;
  class VisitorFilter;
  class VisitorReverseEdges;
  class VisitorSave;

  template <typename T>
  class ListIterator;

  template <typename T>
  class ListIteratorAssocString;
  template <typename T>
  class ListIteratorAssocTypeArgumentConstraintKind;
  template <typename T>
  class ListIteratorAssocSourcePosition;
  template <typename T>
  class ListIteratorAssocParameterKind;

  class Factory;
  class Filter;

  class SourcePosition;
  namespace base {
    class Base;
    class Comment;
    class Component;
    class ControlFlowBlock;
    class Named;
  }

  namespace logical {
    class Attribute;
    class AttributeAccess;
    class Class;
    class ClassGeneric;
    class ClassGenericInstance;
    class ClassGenericSpec;
    class Friendship;
    class GenericParameter;
    class Member;
    class Method;
    class MethodCall;
    class MethodGeneric;
    class MethodGenericInstance;
    class MethodGenericSpec;
    class Package;
    class Parameter;
    class Scope;
  }

  namespace physical {
    class FSEntry;
    class File;
    class FileSystem;
    class Folder;
  }

  namespace type {
    class SimpleType;
    class Type;
    class TypeFormer;
    class TypeFormerArray;
    class TypeFormerMethod;
    class TypeFormerNonType;
    class TypeFormerPointer;
    class TypeFormerType;
  }


}}}

#endif

