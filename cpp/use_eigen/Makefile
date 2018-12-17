CFLAGS = -Wall -g -I/home/chen/workspace/PowerGraph/deps/local/include
LIBS  = -lm
CXX=/usr/bin/g++-6
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,../../bin/cpp/use_eigen/%,$(SRCS))

all: $(PROGS)

../../bin/cpp/use_eigen/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)