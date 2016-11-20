#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = roboCooler_Level_1
CPPUTEST_CXXFLAGS = -Wno-c++14-compat

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	../../src\
	../../src/drivers\

TEST_SRC_DIRS = \
	./allTests\
	./mockFiles\
	../mockFiles/stdlib\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../mockFiles/stdlib\
  ../integration\
  ../../src\
  ../../src/drivers\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

