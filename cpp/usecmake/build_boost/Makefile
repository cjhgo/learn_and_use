CFLAGS = -Wall -g
LIBS  = -lm -lpthread
CXX=/usr/bin/g++-6
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,../../bin/cpp/build_boost/%,$(SRCS))

all: $(PROGS)

../../bin/cpp/build_boost/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)