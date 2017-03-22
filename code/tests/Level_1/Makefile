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
# <__STM32_HAL_LEGACY> stops the redefinition of some defines
# <DSTM32F407xx> allows stm32f4xx.h to compile
# <_RTE_> allows stm32f4xx_hal_conf.h to include RTE header files
CPPUTEST_CXXFLAGS = -Wno-c++14-compat -DSTM32F407xx -fmax-errors=5 -D_RTE_
CPPUTEST_USE_EXTENSIONS = Y

COMPONENT_NAME = roboCooler_Level_1
CPPUTEST_OBJS_DIR = ./objs/tests/Level_1

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \

SRC_FILES = \
	../../src/component.cpp\
	../../src/timer.cpp\
	../../src/drivers/timerDriver.cpp\
	../../src/leds/leds.cpp\
	../../src/leds/ledObj.cpp\

TEST_SRC_DIRS = \
	./\
	./mockFiles\
	../mockFiles/stdlib\

TEST_SRC_FILES = \
	../AllTests.cpp\
	../../src/leds/leds.cpp\
	../../src/leds/ledObj.cpp\
	../../src/drivers/ledDriver.cpp\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../mockFiles/stdlib\
  ../../src\
  ../../src/drivers\
  ../../src/leds\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

