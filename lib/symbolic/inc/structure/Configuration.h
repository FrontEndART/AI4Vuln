#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include "../common.h"

using namespace std;
using columbus::NodeId;

namespace columbus
{
namespace symbolic
{

enum SearchStrategyType {
    DEPTH_FIRST,
    BREADTH_FIRST
};

class Configuration
{
public:
	static const SearchStrategyType DEFAULT_STRATEGY;
	static const unsigned long DEFAULT_MAX_STATE;
	static const unsigned long DEFAULT_MAX_DEPTH;
	static const bool DEFAULT_STATE_MATCHING;
	static const bool DEFAULT_CFG_DUMP;
	static const bool DEFAULT_SYM_DUMP;
	static const unsigned long DEFAULT_CS_TIME_LIMIT;
	static const unsigned int DEFAULT_METHOD_FROM;
	static const bool DEFAULT_DISABLE_CB;
	static const bool DEFAULT_DISABLE_PC_DECOMP;
	static const bool DEFAULT_DISABLE_STATIC_INIT;

	static Configuration* getInstance();
	virtual ~Configuration();

	unsigned long getMaxDepth() const;
	void setMaxDepth(unsigned long maxDepth);
	unsigned long getMaxState() const;
	void setMaxState(unsigned long maxState);
	const SearchStrategyType& getSearchStrategy() const;
	void setSearchStrategy(const SearchStrategyType& searchStrategy);
	void setStateMatching(bool _stateMatching);
	bool isStateMatching() const;
	const string& getOutCsvFile() const;
	void setOutCsvFile(const string& outFile);
	const string& getOutTxtFile() const;
	void setOutTxtFile(const string& outTxtFile);
	const string& getAsgFile() const;
	void setAsgFile(const string& asgFile);
	const string& getAsgFilterFile() const;
	void setAsgFilterFile(const string& asgFilterFile);
	bool getDumpCfgGraphml() const;
	void setDumpCfgGraphml(bool dumpCfgGraphml);
	bool getDumpStateTreeGraphml() const;
	void setDumpStateTreeGraphml(bool dumpStateTreeGraphml);
	unsigned long getCsTimeLimit() const;
	void setCsTimeLimit(unsigned long csTimeLimit);
	unsigned int getMethodFrom() const;
	void setMethodFrom(unsigned int methodFrom);
	void setDisableCB(bool disableCB);
	void setDisablePcDecomp(bool disablePcDecomp);
	void setDisableStaticInit(bool disableStaticInit);
	inline bool getDisableCB() const { return disableCB; }
	inline bool getDisablePcDecomp() const {return disablePcDecomp; }
	inline bool getDisableStaticInit() const { return disableStaticInit; }
	

protected:
	Configuration();

private:
	static Configuration *instance;

	string asgFile;
	string asgFilterFile;
	string outCsvFile;
	string outTxtFile;
	SearchStrategyType searchStrategy;
	unsigned long maxState;
	unsigned long maxDepth;
	bool stateMatching;
	bool dumpCFGGraphml;
	bool dumpStateTreeGraphml;

	/** time limit (in milisec) for the constrant solver to satisfy the PC */
	unsigned long csTimeLimit;
        
    unsigned int methodFrom;

	/** is constraint building disabled */
	bool disableCB;

	/** is pc decomposition disabled */
	bool disablePcDecomp;

	/** disable static initializers*/
	bool disableStaticInit;

	void initConfigFile();
};

}
}

#endif
