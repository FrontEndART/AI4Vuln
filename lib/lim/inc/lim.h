#ifndef _LIM_H_
#define _LIM_H_

/**
* \file LIM.h
* \brief Header can be used for precompiled header.
*/
/*********** Options *************************
 *  SchemaGenerator384dcf302c
 *  IndentInNamespace = 1
 *  IndentInClass = 1
 *  IndentUnderPubProtPri = 1
 *  UseShortRange = true
 *  ACommonGetIsForLeaf = true
 *  AlgPreorderSafeMode = true
 *  GenerateInOutForComment = true
 *  GenerateFilter = true
 *  GenerateReverseEdges = true
 *  GenerateAsgStat = false
 *  GenerateSpecFilterVisitor = false
 *  GenerateSpecXml = false
 *  GenerateDOT = false
 *  GenerateGraphml = true
 *  GenerateJSON = false
 *  GenerateSerialize = false
 *  GenerateParentEdge = true
 *  FactoryModes = 
 *  APIVersion = 3.0.31
 *  BinaryVersion = 3.0.31
 *  CSIHeaderText = LanguageIndependentModel
 *********************************************/
#include <list>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <boost/crc.hpp>

#include "csi/inc/HeaderData.h" 
#include "csi/inc/PropertyData.h" 
#include <stack>

#include "Forwards.h"

// externals
#include "AsgCommon.h"
#include "strtable/inc/RefDistributorStrTable.h"
#include "csi/inc/csi.h"
#include "Exception.h"

#include "Constant.h"
#include "Types.h"
#include "LimException.h"
#include "ListIterator.h"
#include "ListIteratorAssoc.h"
#include "Common.h"
#include "ReverseEdges.h"

#include "SourcePosition.h"

 /***********************NODES******************/
#include "base/Base.h"
#include "base/Comment.h"
#include "base/ControlFlowBlock.h"
#include "base/Named.h"
#include "logical/AttributeAccess.h"
#include "logical/Friendship.h"
#include "logical/MethodCall.h"
#include "type/SimpleType.h"
#include "type/Type.h"
#include "type/TypeFormer.h"
#include "base/Component.h"
#include "logical/GenericParameter.h"
#include "logical/Member.h"
#include "logical/Parameter.h"
#include "physical/FSEntry.h"
#include "physical/FileSystem.h"
#include "type/TypeFormerArray.h"
#include "type/TypeFormerMethod.h"
#include "type/TypeFormerNonType.h"
#include "type/TypeFormerPointer.h"
#include "type/TypeFormerType.h"
#include "logical/Attribute.h"
#include "logical/Scope.h"
#include "physical/File.h"
#include "physical/Folder.h"
#include "logical/Class.h"
#include "logical/Method.h"
#include "logical/Package.h"
#include "logical/ClassGeneric.h"
#include "logical/ClassGenericInstance.h"
#include "logical/MethodGeneric.h"
#include "logical/MethodGenericInstance.h"
#include "logical/ClassGenericSpec.h"
#include "logical/MethodGenericSpec.h"


#include "Filter.h"
#include "Factory.h"

#include "visitors/Visitor.h"
#include "visitors/VisitorAbstractNodes.h"
#include "visitors/VisitorGraphml.h"
#include "visitors/VisitorLIMML.h"
#include "visitors/VisitorFilter.h"
#include "visitors/VisitorReverseEdges.h"
#include "visitors/VisitorSave.h"
#include "visitors/VisitorSubtreeCollector.h"
#include "visitors/VisitorSimpleEdge.h"

#include "algorithms/Algorithm.h"
#include "algorithms/AlgorithmPreorder.h"
#include "algorithms/AlgorithmDeepCopy.h"
#include "ClassDiagram.h"
#include "visitors/VisitorClassDiagram.h"
#include "ListIteratorClassDiagram.h"
#include "OverrideRelations.h"
#include "visitors/VisitorOverride.h"
#include "LimOrigin.h"

#endif

