
#ifndef _CFG_H
#define _CFG_H
#include <map>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <common/inc/WriteMessage.h>
#include <common/inc/StringSup.h>
#include <Exception.h>

#include "AsgCommon.h"
#include "printers/ASGNodePrinter.h"
#include "structure/EntryBlock.h"
#include "structure/ExitBlock.h"
#include "structure/BasicBlock.h"
#include "structure/ICFG.h"
#include "structure/DUDecorator.h"
#include "structure/DUInfo.h"
#include "structure/CFGFactory.h"
#include "structure/Edge.h"
#include "structure/Variable.h"
#include "structure/CGFactory.h"

#include "visitors/VisitorBasicBlock.h"

#include "algorithms/AlgorithmCDG.h"
#include "algorithms/AlgorithmCompare.h"
#include "algorithms/AlgorithmCGCompare.h"
#include "algorithms/AlgorithmDefUseChains.h"
#include "algorithms/AlgorithmDepthTraversal.h"
#include "algorithms/AlgorithmIterativeTraversal.h"
#include "algorithms/AlgorithmICCFG.h"
#include "algorithms/AlgorithmPathFinder.h"

#include "printers/CFG2Graphml.h"
#include "printers/CFG2JSON.h"
#include "printers/CG2Graphml.h"
#include "reader/CFGGraphml2CFG.h"

#endif