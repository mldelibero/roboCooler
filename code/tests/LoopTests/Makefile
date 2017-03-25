# CppUTest Makefile

#--- Inputs ----#
COMPONENT_NAME = roboCooler_LoopTests
include ../settings/Makefile

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
	../mockFiles/stdlib/stm32f4xx_hal.cpp\
	../mockFiles/timer.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/init.cpp\
	../../src/loop.cpp\

TEST_SRC_DIRS += \
	./\

TEST_SRC_FILES += \
	../../src/leds/ledObj.cpp\
	../mockfiles/stdlib/stm32f4xx_hal_rcc.cpp\

INCLUDE_DIRS += \
	../../src/drivers\
	../../src/leds\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

