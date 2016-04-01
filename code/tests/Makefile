#---------
#
# CppUTest Examples Makefile
#
#----------

#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

#--- Inputs ----#
COMPONENT_NAME = roboCooler
#Uncomment in Makefile or put the next line in ~/.bashrc
#CPPUTEST_HOME = /usr/local/lib/cpputest
#export CPPUTEST_HOME=/usr/local/lib/cpputest

# Uncomment to temporarily allow warnings
#CPPUTEST_WARNINGFLAGS = -Wall

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc

# This line is overriding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
#CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include ExamplesNewOverrides.h
SRC_DIRS = \
	../src

TEST_SRC_DIRS = \
	./allTests\
	./mockFiles\

INCLUDE_DIRS =\
  .\
  ./mockFiles\
  ../src\
  $(CPPUTEST_HOME)/include\

include $(CPPUTEST_HOME)/build/MakefileWorker.mk


