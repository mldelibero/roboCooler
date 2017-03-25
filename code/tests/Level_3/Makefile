# CppUTest Makefile

#--- Inputs ----#
COMPONENT_NAME = roboCooler_Level_3
include ../settings/Makefile

SRC_DIRS = \

SRC_FILES = \
	../mockFiles/component.cpp\
	../mockFiles/ledBehaviorMock.cpp\
	../../src/leds/scene.cpp\

TEST_SRC_DIRS += \
	./\

TEST_SRC_FILES += \
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/capTouchMock.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../mockFiles/limitSwitchMock.cpp\
	../mockFiles/lidMotorDriver.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../../src/drivers/CDriver.cpp\
	../../src/leds/scene.cpp\
	../../src/lidMotor.cpp\

INCLUDE_DIRS +=\
	../../src/drivers\
	../../src/leds\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

