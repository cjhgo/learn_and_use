CFLAGS = -Wall
LIBS  = -lm
CC=mpicc
SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o "bin/$@" $<  $(LIBS)