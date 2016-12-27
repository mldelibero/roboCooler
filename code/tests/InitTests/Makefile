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

COMPONENT_NAME = roboCooler_InitTests
CPPUTEST_OBJS_DIR = ./objs/tests/InitTests

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \

SRC_FILES = \
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/capTouchMock.cpp\
	../mockFiles/component.cpp\
	../mockFiles/leds.cpp\
	../mockFiles/ledObjMock.cpp\
	../mockFiles/ledStripMock.cpp\
	../mockFiles/ledStripDriverMock.cpp\
	../mockFiles/lidMotorMock.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../mockFiles/limitSwitchMock.cpp\
	../mockFiles/sceneMock.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../mockFiles/timer.cpp\
	../mockFiles/timerDriverMock.cpp\
	../../src/init.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/limitSwitch.cpp\

TEST_SRC_DIRS = \
	./\
	./mockFiles\
	../mockFiles/stdlib\

TEST_SRC_FILES =\
	../AllTests.cpp\
	../mockFiles/limitSwitchMock.cpp\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../mockFiles\
  ../../src\
  ../../src/drivers\
  ../../src/leds\
  ../mockFiles/stdLib\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


