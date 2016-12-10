#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Outputs ---#
CPP_PLATFORM = Gcc
CPPUTEST_CXXFLAGS = -Wno-c++14-compat
CPPUTEST_USE_EXTENSIONS = Y

COMPONENT_NAME = roboCooler_LoopTests
CPPUTEST_OBJS_DIR = ./objs/tests/LoopTests

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \

SRC_FILES = \
	../../src/loop.cpp\

TEST_SRC_DIRS = \
	./\

TEST_SRC_FILES =\
	../AllTests.cpp\

INCLUDE_DIRS =\
  .\
  ../../src\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


