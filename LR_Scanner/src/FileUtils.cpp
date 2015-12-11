/* 
* @Author: sxf
* @Date:   2015-12-11 18:48:19
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-11 21:05:41
*/

#include "FileUtils.h"
#include <glibmm.h>
#include <giomm.h>
#include <iostream>

using namespace std;

using namespace Glib;
using namespace Gio;


bool FileUtils::isNeedUpdate(const std::string& cfg_path, const std::string& save_path) {
	Gio::init();
	RefPtr< File > file_save     = File::create_for_path(save_path);
	if (!(file_save->query_exists())) return true;
	RefPtr< File > file_cfg      = File::create_for_path(cfg_path);
	if (!(file_save->query_exists())) return true;
	TimeVal cfg_time, save_time;
	try{
		RefPtr< FileInfo > cfg_info  = file_cfg->query_info();
		RefPtr< FileInfo > save_info = file_save->query_info();
		// if (cfg_info == NULL || save_info == NULL) return true;
		cfg_time = cfg_info->modification_time();
		save_time = save_info->modification_time();
	} catch(const Glib::Error& err) {
		cerr << err.what() << endl;
	}
	if (save_time > cfg_time) return false;
	else return true;
}
