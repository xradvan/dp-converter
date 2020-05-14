#!/usr/bin/python3
import os
import sys
import shutil
import subprocess

def usage():
	print("Run './configure' to create build directory and './configure clean' to clean it ")

# base dir
os.chdir(os.path.dirname(os.path.realpath(__file__)))

# create build folder
BUILDDIR = '.build'

# clean build folder
if len(sys.argv) > 1 and sys.argv[1] == '-h':
	usage()
	exit(0)

if len(sys.argv) > 1 and sys.argv[1] == 'clean':
	if os.path.exists(BUILDDIR):
		print('Removing {0} directory'.format(BUILDDIR))
		shutil.rmtree(BUILDDIR, ignore_errors=True)
	else:
		print('Directory {0} does not exist. Run "configure.py" first.'.format(BUILDDIR))
	exit(0)

# check if build dir exists
if os.path.exists(BUILDDIR):
	print('Error: Build directory already exists. Run "configure.py clean" first.')
	exit(1)

print('Configuring .build directory')
os.mkdir(BUILDDIR)

# run cmake
CMAKE = ['cmake', '../']
if subprocess.call(CMAKE, cwd=BUILDDIR) == 0:
	# print success
	print('\n\nBuild directory created successfully. Now run "make" in {0} directory'.format(BUILDDIR))
else:
	print('\n\nError: Failed to create build directory. Run "configure.py clean" and guess why it happend...')