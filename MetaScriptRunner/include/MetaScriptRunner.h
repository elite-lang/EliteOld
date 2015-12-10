/* 
* @Author: sxf
* @Date:   2015-11-05 21:21:50
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-12 18:21:51
*/


#ifndef META_SCRIPT_RUNNER_H
#define META_SCRIPT_RUNNER_H

#include "ScriptRunner.h"

using namespace std;

namespace OOLUA {
	class Script;
}

class MetaScriptRunner : public ScriptRunner
{
public:
	virtual void Init();
    virtual Node* getRoot(); // 仅支持后端为RedApple的宏翻译系统，其余系统返回NULL
	virtual void Finished();
	static MetaScriptRunner* Create();

	bool run_file (string const &filename);
	bool load_file (string const &filename);
	bool load_chunk (string const &chunk);
	bool run_chunk (string const &chunk);

protected:
	OOLUA::Script* vm;
	Node* root;

	MetaScriptRunner();
	~MetaScriptRunner();
};





#endif // META_SCRIPT_RUNNER_H
