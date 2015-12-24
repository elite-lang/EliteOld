/* 
* @Author: sxf
* @Date:   2015-12-24 20:14:08
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-24 20:16:57
*/

#ifndef ELITE_TOOLS_H
#define ELITE_TOOLS_H

#if defined(_WIN32)
#define ELITE_TOOLS_PATH "/tools/windows_x64"
#endif
#if defined(__linux__)
#define ELITE_TOOLS_PATH "/tools/linux_x64"
#endif
#if defined(__APPLE__) && defined(__MACH__)
#define ELITE_TOOLS_PATH "/tools/darwin_x64"
#endif

#endif // ELITE_TOOLS_H
