TARGET := racecondition
C_SOURCES := $(shell ls *.c)
CC := gcc

default: all

all:
	$(CC) $(C_SOURCES) -o $(TARGET)

clean:
	rm -rf $(TARGET) *.o
