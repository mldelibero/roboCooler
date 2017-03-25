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
CPPUTEST_CXXFLAGS = -Wno-c++14-compat -D_RTE_
CPPUTEST_USE_EXTENSIONS = Y

COMPONENT_NAME = roboCooler_Level_3
CPPUTEST_OBJS_DIR = ./objs/tests/Level_3

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \

SRC_FILES = \
	../mockFiles/component.cpp\
	../mockFiles/ledBehaviorMock.cpp\
	../../src/leds/scene.cpp\

TEST_SRC_DIRS = \
	./\

TEST_SRC_FILES = \
	../AllTests.cpp\
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/capTouchMock.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../mockFiles/limitSwitchMock.cpp\
	../mockFiles/lidMotorDriver.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/leds/scene.cpp\
	../../src/lidMotor.cpp\

INCLUDE_DIRS =\
	.\
	../mockFiles\
	../mockFiles/stdlib\
	../../prj/RTE/Device/STM32F407VGTx\
	../../prj/RTE/_Target_1\
	../../src\
	../../src/drivers\
	../../src/leds\
	$(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


