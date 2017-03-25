
# CppUTest Makefile

#--- Inputs ----#
COMPONENT_NAME = roboCooler_Level_4
include ../settings/Makefile

SRC_DIRS = \
	./mockFiles\

SRC_FILES = \
	../../src/leds/ledStrip.cpp\
	../mockFiles/ledStripDriverMock.cpp\

TEST_SRC_DIRS += \
	./\

TEST_SRC_FILES += \
	../mockFiles/capTouchMock.cpp\
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/component.cpp\
	../mockFiles/ledStripDriverMock.cpp\
	../mockFiles/limitSwitchMock.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../mockFiles/sceneMock.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/leds/ledObj.cpp\
	../../src/leds/ledStrip.cpp\

INCLUDE_DIRS +=\
	../../src/drivers\
	../../src/leds\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

