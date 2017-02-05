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
CPPUTEST_CXXFLAGS = -Wno-c++14-compat -DIN_TEST_MODE
CPPUTEST_USE_EXTENSIONS = Y

COMPONENT_NAME = roboCooler_LoopTests
CPPUTEST_OBJS_DIR = ./objs/tests/LoopTests

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \

SRC_FILES = \
	../mockFiles/capTouchMock.cpp\
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/component.cpp\
	../mockFiles/leds.cpp\
	../mockFiles/ledBehaviorMock.cpp\
	../mockFiles/ledBehaviorChildrenMock.cpp\
	../mockFiles/ledStripMock.cpp\
	../mockFiles/ledStripDriverMock.cpp\
	../mockFiles/lidMotorMock.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../mockFiles/limitSwitchMock.cpp\
	../mockFiles/sceneMock.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../mockFiles/timer.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/init.cpp\
	../../src/loop.cpp\

TEST_SRC_DIRS = \
	./\

TEST_SRC_FILES =\
	../AllTests.cpp\
	../../src/leds/ledObj.cpp\

INCLUDE_DIRS =\
  .\
  ../mockfiles\
  ../mockFiles/stdlib\
  ../../src\
  ../../src/drivers\
  ../../src/leds\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


