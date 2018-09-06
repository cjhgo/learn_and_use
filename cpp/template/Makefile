CFLAGS = -Wall -g 
#-I/home/chen/ict/ParallelGraph/deps/local/include -L/home/chen/ict/ParallelGraph/deps/local/lib
LIBS  = -lm -lpthread
CXX=/usr/bin/g++-4.8
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,../../bin/cpp/template/%,$(SRCS))

all: $(PROGS)

../../bin/cpp/template/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)