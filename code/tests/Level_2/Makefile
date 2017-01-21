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

COMPONENT_NAME = roboCooler_Level_2
CPPUTEST_OBJS_DIR = ./objs/tests/Level_2

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	./mockFiles\
	../Level_1/mockFiles\

SRC_FILES = \
	../../src/leds/leds.cpp\
	../../src/limitSwitch.cpp\
	../../src/drivers/CDriver.cpp\
	../mockFiles/component.cpp\

TEST_SRC_DIRS = \
	./\
	./mockFiles\
	../Level_1/mockFiles\
	../mockFiles/stdlib\

TEST_SRC_FILES = \
	../AllTests.cpp\
	../../src/leds/ledBehavior.cpp\
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/ledObjMock.cpp\
	../mockFiles/ledStripDriverMock.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../../src/capTouch.cpp\
	../../src/leds/leds.cpp\
	../../src/limitSwitch.cpp\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../Level_1/mockFiles\
  ../mockFiles\
  ../mockFiles/stdlib\
  ../../src\
  ../../src/drivers\
  ../../src/leds\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


