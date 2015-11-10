/* 
* @Author: sxf
* @Date:   2015-11-05 21:21:50
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-07 13:57:14
*/


#ifndef META_SCRIPT_RUNNER_H
#define META_SCRIPT_RUNNER_H

#include "ScriptRunner.h"
#include "oolua/oolua.h"

using namespaces std;

class MetaScriptRunner : public ScriptRunner
{
public:
	virtual void Init();
	static MetaScriptRunner* Create();

	bool run_file (std::string const &filename);
	bool load_file (std::string const &filename);
	bool load_chunk (std::string const &chunk);
	bool run_chunk (std::string const &chunk);
protected:
	OOLUA::Script vm;

	MetaScriptRunner();
	~MetaScriptRunner();
};





#endif // META_SCRIPT_RUNNER_H
