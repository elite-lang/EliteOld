/* 
* @Author: sxf
* @Date:   2015-12-21 20:35:05
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-21 21:35:20
*/


#ifndef DEBUG_MSG_H
#define DEBUG_MSG_H

class DebugMsg_Private;
class DebugMsg
{
public:
	static DebugMsg_Private* getInstance();
private:
	static DebugMsg_Private* instance;
};



#endif // DEBUG_MSG_H
