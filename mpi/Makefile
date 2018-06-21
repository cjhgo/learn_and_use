CFLAGS = -Wall
LIBS  = -lm
CC=mpicc
SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,../bin/mpi/%,$(SRCS))

all: $(PROGS)

../bin/mpi/%: %.c
	$(CC) $(CFLAGS) -o $@ $<  $(LIBS)