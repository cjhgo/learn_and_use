CFLAGS = -Wall -g
LIBS  = -lm -lpthread
CXX=/usr/bin/g++-6
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,../../bin/cpp/pthread/%,$(SRCS))

all: $(PROGS)

../../bin/cpp/pthread/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)