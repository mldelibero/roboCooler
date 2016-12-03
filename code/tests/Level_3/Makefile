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
COMPONENT_NAME = roboCooler_Level_3
CPPUTEST_CXXFLAGS = -Wno-c++14-compat

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	./mockFiles\
	../Level_2/mockFiles\
	../Level_1/mockFiles\
	../mockFiles/stdlib\

SRC_FILES = \
	../../src/lidMotor.cpp\
	../../src/limitSwitch.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/drivers/limitSwitchDriver.cpp\

TEST_SRC_DIRS = \
	./allTests\
	./mockFiles\
	../Level_2/mockFiles\
	../Level_1/mockFiles\
	../mockFiles/stdlib\

TEST_SRC_FILES = \

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../../src\
  ../../src/drivers\
  ../Level_2/mockFiles\
  ../Level_1/mockFiles\
  ../mockFiles/stdLib\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


