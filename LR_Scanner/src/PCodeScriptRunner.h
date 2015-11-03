/* 
* @Author: sxf
* @Date:   2015-11-02 18:56:35
* @Last Modified by:   sxf
* @Last Modified time: 2015-11-02 19:59:18
*/
#ifndef P_CODE_SCRIPT_RUNNER_H
#define P_CODE_SCRIPT_RUNNER_H

#include "Grammer_Node.h"
#include "idtable.h"
#include "codegenerator.h"
#include "ScriptRunner.h"

class PCodeScriptRunner : public ScriptRunner
{
public:
	PCodeScriptRunner();
	~PCodeScriptRunner();
	virtual void Init();
	virtual void Finished();
protected:
	IDTable* id_table;
    CodeGenerator* code_generator;
};

#endif // P_CODE_SCRIPT_RUNNER_H
