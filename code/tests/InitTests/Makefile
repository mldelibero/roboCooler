# CppUTest Makefile

#--- Inputs ----#
COMPONENT_NAME = roboCooler_InitTests
include ../settings/Makefile

SRC_DIRS = \

SRC_FILES = \
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/capTouchMock.cpp\
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
	../mockFiles/timerDriverMock.cpp\
	../../src/init.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/limitSwitch.cpp\

TEST_SRC_DIRS += \
	./\
	./mockFiles\
	../mockFiles/stdlib\

TEST_SRC_FILES +=\
	../../src/leds/ledObj.cpp\
	../mockFiles/limitSwitchMock.cpp\

INCLUDE_DIRS +=\
	../../src/drivers\
	../../src/leds\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

