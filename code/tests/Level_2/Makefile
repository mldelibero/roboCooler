# CppUTest Makefile

#--- Inputs ----#
COMPONENT_NAME = roboCooler_Level_2
include ../settings/Makefile
CPPUTEST_CXXFLAGS += -DSTM32F407xx\

SRC_DIRS = \

SRC_FILES = \
	../../src/drivers/ledStripDriver.cpp\
	../../src/drivers/CDriver.cpp\

TEST_SRC_DIRS = \
	./\

TEST_SRC_FILES += \
	../mockFiles/component.cpp\
	../mockFiles/capTouchDriverMock.cpp\
	../mockFiles/ledDriver.cpp\
	../mockFiles/limitSwitchDriverMock.cpp\
	../mockFiles/stdlib/stm32f4xx.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_cortex.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_dma.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_gpio.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_usart.cpp\
	../mockFiles/stdlib/stm32f4xx_hal_tim.cpp\
	../../src/capTouch.cpp\
	../../src/drivers/ledStripDriver.cpp\
	../../src/drivers/timerDriver.cpp\
	../../src/leds/ledObj.cpp\
	../../src/leds/leds.cpp\
	../../src/leds/ledBehavior.cpp\
	../../src/leds/ledBehaviorChildren.cpp\
	../../src/limitSwitch.cpp\
	../../src/timer.cpp\

INCLUDE_DIRS += \
	../../src/drivers\
	../../src/leds\
	$(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk

