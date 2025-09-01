#include "../../inc/common.h"

using namespace common;

namespace columbus {
namespace symbolic {

const SearchStrategyType Configuration::DEFAULT_STRATEGY = DEPTH_FIRST;
const unsigned long Configuration::DEFAULT_MAX_STATE = 500;
const unsigned long Configuration::DEFAULT_MAX_DEPTH = 100;
const bool Configuration::DEFAULT_STATE_MATCHING = false;
const bool Configuration::DEFAULT_CFG_DUMP = false;
const bool Configuration::DEFAULT_SYM_DUMP = false;
const unsigned long Configuration::DEFAULT_CS_TIME_LIMIT = 1000;
const unsigned int Configuration::DEFAULT_METHOD_FROM = 0;
const bool Configuration::DEFAULT_DISABLE_CB = false;
const bool Configuration::DEFAULT_DISABLE_PC_DECOMP = false;
const bool Configuration::DEFAULT_DISABLE_STATIC_INIT = true;

Configuration *Configuration::instance = 0;

Configuration::Configuration() :
        asgFile(),
        asgFilterFile(),
        outCsvFile(),
        searchStrategy(Configuration::DEFAULT_STRATEGY),
        maxState(Configuration::DEFAULT_MAX_STATE),
        maxDepth(Configuration::DEFAULT_MAX_DEPTH),
        stateMatching(Configuration::DEFAULT_STATE_MATCHING),
        dumpCFGGraphml(DEFAULT_CFG_DUMP),
        dumpStateTreeGraphml(DEFAULT_SYM_DUMP),
        csTimeLimit(DEFAULT_CS_TIME_LIMIT),
        methodFrom(DEFAULT_METHOD_FROM),
		disableCB(DEFAULT_DISABLE_CB),
		disablePcDecomp(DEFAULT_DISABLE_PC_DECOMP), disableStaticInit(DEFAULT_DISABLE_STATIC_INIT)
{ }

Configuration* Configuration::getInstance() {
    if (instance == 0) {
        instance = new Configuration();
    }
    return instance;
}


unsigned long Configuration::getMaxDepth() const {
    return maxDepth;
}

void Configuration::setMaxDepth(unsigned long maxDepth) {
    this->maxDepth = maxDepth;
}

unsigned long Configuration::getMaxState() const {
    return maxState;
}

void Configuration::setMaxState(unsigned long maxState) {
    this->maxState = maxState;
}

const SearchStrategyType& Configuration::getSearchStrategy() const {
    return searchStrategy;
}

void Configuration::setSearchStrategy(const SearchStrategyType& searchStrategy) {
    this->searchStrategy = searchStrategy;
}

void Configuration::setStateMatching(bool _stateMatching) {
    stateMatching = _stateMatching;
}

bool Configuration::isStateMatching() const {
    return stateMatching;
}

Configuration::~Configuration() {
}

const string& Configuration::getOutCsvFile() const {
  return outCsvFile;
}

void Configuration::setOutCsvFile(const string& outcsvFile) {
    this->outCsvFile = outcsvFile;
}

const string& Configuration::getOutTxtFile() const {
  return outTxtFile;
}

void Configuration::setOutTxtFile(const string& outTxtFile) {
    this->outTxtFile = outTxtFile;
}

const string& Configuration::getAsgFile() const {
	if (asgFile.empty()) throw SymbolicColumbusException("Asg file not set in configuration!");
    return asgFile;
}

void Configuration::setAsgFile(const string& asgFile) {
    this->asgFile = asgFile;
}

const string& Configuration::getAsgFilterFile() const {
	if (asgFilterFile.empty()) throw SymbolicColumbusException("Asg filter file not set in configuration!");
    return asgFilterFile;
}

void Configuration::setAsgFilterFile(const string& asgFilterFile) {
    this->asgFilterFile = asgFilterFile;
}

bool Configuration::getDumpCfgGraphml() const {
    return dumpCFGGraphml;
}

void Configuration::setDumpCfgGraphml(bool dumpCfgGraphml) {
    dumpCFGGraphml = dumpCfgGraphml;
}

bool Configuration::getDumpStateTreeGraphml() const {
    return dumpStateTreeGraphml;
}

void Configuration::setDumpStateTreeGraphml(bool dumpStateTreeGraphml) {
    this->dumpStateTreeGraphml = dumpStateTreeGraphml;
}

unsigned long Configuration::getCsTimeLimit() const {
    return csTimeLimit;
}

void Configuration::setCsTimeLimit(unsigned long csTimeLimit) {
    this->csTimeLimit = csTimeLimit;
}

unsigned int Configuration::getMethodFrom() const {
    return methodFrom;
}

void Configuration::setMethodFrom(unsigned int methodFrom) {
    this->methodFrom = methodFrom;
}

void Configuration::setDisableCB(bool disableCB) {
	this->disableCB = disableCB;
}
void Configuration::setDisablePcDecomp(bool disablePcDecomp) {
	this->disablePcDecomp = disablePcDecomp;
}

void Configuration::setDisableStaticInit(bool disableStaticInit) {
	this->disableStaticInit = disableStaticInit;
}
}
}

