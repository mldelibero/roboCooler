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

COMPONENT_NAME = roboCooler_Level_2
CPPUTEST_OBJS_DIR = ./objs/tests/Level_2

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	./mockFiles\

SRC_FILES = \
	../../src/drivers/ledStripDriver.cpp\
	../../src/drivers/CDriver.cpp\

TEST_SRC_DIRS = \
	./\

TEST_SRC_FILES = \
	../AllTests.cpp\
	../mockFiles/component.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_cortex.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_dma.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_gpio.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_usart.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_tim.cpp\
	../../src/leds/ledObj.cpp\
	../../src/drivers/ledStripDriver.cpp\
	../../src/drivers/timerDriver.cpp\
	../../src/timer.cpp\

INCLUDE_DIRS =\
	.\
	../mockFiles/stdlib\
	../../src\
	../../src/drivers\
	../../src/leds\
	../../prj/RTE/Device/STM32F407VGTx\
	../../prj/RTE/_Target_1\
	$(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


