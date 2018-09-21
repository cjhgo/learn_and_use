CFLAGS = -Wall -g
LIBS  = -lm -lpthread
CXX=/usr/bin/g++-6
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,../../bin/cpp/stl/%,$(SRCS))

all: $(PROGS)

../../bin/cpp/stl/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)