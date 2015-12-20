#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: sxf
# @Date:   2015-12-20 18:37:22
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-20 20:54:31

import os
import commands
from subprocess import Popen, PIPE

class TestRunner:
		
	def walk_dir(self, path):
		for line in os.listdir(path):
			filepath = os.path.join(path,line)
			if os.path.isdir(filepath):
				print filepath
				self.compile_path(filepath)

	def compile_path(self, path):
		cmd = self.bin_path + ' -i ' + path + '/test.elite -d ' + path + '/build/'
		status, output = commands.getstatusoutput(cmd)
		if status != 0:  
			print '\033[1;31m'
			print '编译失败:', path
			print output
			print '\033[0m'

	def main(self):
		print "测试开始"
		self.now_path = os.path.split(os.path.realpath(__file__))[0]
		self.bin_path = os.path.normpath(os.path.join(self.now_path, '..', '..', 'bin', 'elite'))
		self.elite_path = os.path.normpath(os.path.join(self.now_path, '..', '..'))
		print '\033[1;32m'
		print "now_path:", self.now_path
		print "bin_path:", self.bin_path
		print "elite_path:", self.elite_path
		print '\033[0m'
		os.environ['ELITE_HOME'] = self.elite_path # 设置临时环境变量
		self.walk_dir(self.now_path)
		return

if __name__ == '__main__':
	tr = TestRunner()
	tr.main()