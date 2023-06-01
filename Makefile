RELVERSION  = $(shell cat .release)

ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

MakefileFullPath = $(abspath $(lastword $(MAKEFILE_LIST)))
MakefileDirFullPath = $(shell dirname $(MakefileFullPath))
INSTALLDIR = $(MakefileDirFullPath)/install.$(RELVERSION)/

CXX  = g++
CXX += -I./

CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated
CXXFLAGS += $(ROOTCFLAGS)
CXXFLAGS += $(ROOTLIBS)
CXXFLAGS += $(ROOTGLIBS)
CXXFLAGS += -std=c++14
CXXFLAGS += -fconcepts

OUTLIB = ./obj/

#----------------------------------------------------#

all: makedir convert_simtel_log

makedir:
	mkdir -p $(OUTLIB);

.PHONY: printmakehelp_and_reminder
printmakehelp_and_reminder: convert_simtel_log.cpp Makefile
	$(info  /******************************************************************************/)
	$(info  * task --> printmakehelp_and_reminder: convert_simtel_log.cpp Makefile        *)
	$(info  * $$@ ----> $@                                         *)
	$(info  * $$< --------------------------------> $<                 *)
	$(info  * $$^ --------------------------------> $^        *)
	$(info  /******************************************************************************/)

convert_simtel_log: convert_simtel_log.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

install: makedir obj/libconvert_simtel_log.so
	mkdir -p $(INSTALLDIR);
	cp $(OUTLIB)libconvert_simtel_log.so $(INSTALLDIR)libconvert_simtel_log.so
	cp src/*.hh $(INSTALLDIR).

cleaninstall:
	rm -rf $(INSTALLDIR)

clean:
	rm -f convert_simtel_log
	rm -f *~
	rm -f .*~
	rm -f $(OUTLIB)*.o
	rm -f $(OUTLIB)*.so
