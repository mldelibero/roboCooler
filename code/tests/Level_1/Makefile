# CppUTest Makefile

#--- Inputs ----#
COMPONENT_NAME = roboCooler_Level_1
include ../settings/Makefile
CPPUTEST_CXXFLAGS += -DSTM32F407xx\

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

TEST_SRC_FILES += \
	../../src/leds/leds.cpp\
	../../src/leds/ledObj.cpp\
	../../src/drivers/ledDriver.cpp\

INCLUDE_DIRS += \
	./mockFiles\
	../../src/drivers\
	../../src/leds\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

