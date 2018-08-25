CFLAGS = -Wall -g
LIBS  = -lm -lpthread
CXX=/usr/bin/g++-6
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,../../bin/cpp/atomics/%,$(SRCS))

all: $(PROGS)

../../bin/cpp/atomics/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)