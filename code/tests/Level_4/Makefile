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

SRC_FILES = \
	../../src/init.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/limitSwitch.cpp\
	../../tests/Level_2/mockFiles/capTouch.cpp\
	../../tests/Level_2/mockFiles/component.cpp\
	../../tests/Level_2/mockFiles/limitSwitchDriverMock.cpp\
	../../tests/Level_3/mockFiles/limitSwitchMock.cpp\
	../../tests/mockFiles/stdlib/stm32f4xx.cpp\

TEST_SRC_DIRS = \
	./\
	./mockFiles\
	../mockFiles/stdlib\

TEST_SRC_FILES =\
	../AllTests.cpp\
	../../tests/Level_3/mockFiles/limitSwitchMock.cpp\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../../src\
  ../../src/drivers\
  ../Level_3/mockFiles\
  ../Level_2/mockFiles\
  ../Level_1/mockFiles\
  ../mockFiles/stdLib\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


