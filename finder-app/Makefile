# define the source files and the resulting binary
SRCS := writer.c
OBJS := $(SRCS:.c=.o)
TARGET := writer

#compiler and flags
CC := gcc
CFLAGS := -Wall
LIBS :=

#support for cross-compileation
ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)gcc
endif

#default target

all: $(TARGET)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET) $(OBJS)

