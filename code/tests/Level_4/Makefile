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

COMPONENT_NAME = roboCooler_Level_4
CPPUTEST_OBJS_DIR = ./objs/tests/Level_4

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	./mockFiles\

SRC_FILES = \
../../src/ledStrip.cpp\

TEST_SRC_DIRS = \
	./\

TEST_SRC_FILES = \
	../AllTests.cpp\
	../mockFiles/component.cpp\
	../../src/ledStrip.cpp\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../mockFiles\
  ../mockFiles/stdLib\
  ../../src\
  ../../src/drivers\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


