#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: sxf
# @Date:   2015-12-20 18:37:22
# @Last Modified by:   sxf
# @Last Modified time: 2015-12-21 20:15:31

import os, sys
import commands

class TestRunner:
	def __init__(self):
		self.compile_error = []
		self.run_error = []
		self.output_error = []
		
	def walk_dir(self, path):
		for line in os.listdir(path):
			filepath = os.path.join(path,line)
			if os.path.isdir(filepath):
				print filepath
				ret = self.compile_path(filepath)
				if ret != 0:
					sys.exit(1)
				ret = self.run_file(filepath+'/build/test', filepath+'/test.out')
				if ret != 0:
					sys.exit(1)


	def compile_path(self, path):
		cmd = self.bin_path + ' -i ' + path + '/test.elite -d ' + path + '/build/'
		print cmd
		status, output = commands.getstatusoutput(cmd)
		print output
		if status != 0:  
			print '\033[1;31m'
			print '编译失败:', path
			print output
			print '\033[0m'
			self.compile_error.append(path)
		return status

	def run_file(self, filepath, output_file):
		status, output = commands.getstatusoutput(filepath)
		if status != 0:
			print '\033[1;31m'
			print '运行失败:', filepath
			print 'status:', status
			print output
			print '\033[0m'
			self.run_error.append(filepath)
			return status
		read_data = ''
		with open(output_file, 'rU') as f:
			read_data = f.read() 
		if read_data != output:
			print '\033[1;31m'
			print '执行结果错误：', filepath
			print output
			print '\033[0m'
			self.output_error.append(filepath)
			return 1
		return 0

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