# Compiler and flags
CC     = gcc
CFLAGS = -Wall -Wextra -O2

# The target executable
TARGET = memomemofib

# Object files
OBJS   = main.o memofib.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

memofib.o: memofib.c memofib.h
	$(CC) $(CFLAGS) -c memofib.c

main.o: main.c memofib.h
	$(CC) $(CFLAGS) -c main.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
