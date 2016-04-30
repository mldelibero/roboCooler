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
COMPONENT_NAME = roboCooler_Timer
#CPPUTEST_HOME = /usr/local/lib/cpputest/

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	../../src/timer\
	../../integration\

TEST_SRC_DIRS = \
	./allTests\
	../integration\
	../mockFiles/stdlib\

INCLUDE_DIRS =\
  .\
  ../mockFiles/stdlib\
  ../integration\
  ../../src/timer\
  ../../integration\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


