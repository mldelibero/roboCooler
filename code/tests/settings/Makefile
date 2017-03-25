# CppUTest Makefile -- Common Settings for all test Makefiles
# Put this line in your Makefile:
# include ../settings/Makefile

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
CPPUTEST_CXXFLAGS = -fmax-errors=5 -Wno-c++14-compat -D_RTE_ -g
CPPUTEST_OBJS_DIR = ./objs/tests/$(COMPONENT_NAME)
#
CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# Your version of these files should have += to append to these
TEST_SRC_FILES = \
../AllTests.cpp\

INCLUDE_DIRS =\
	.\
	../mockFiles\
	../mockFiles/stdLib\
	../../prj/RTE/Device/STM32F407VGTx\
	../../prj/RTE/_Target_1\
	../../src\
	$(CPPUTEST_HOME)/include\

