TARGET =	pg
OBJS =		main.o

CC =		gcc
CFLAGS =	-Wall -D_GNU_SOURCE
LDFLAGS =	-pthread

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)

call: clean all
