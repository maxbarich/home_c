TARGET = temp_stats.exe
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRCS = main.c temp_functions.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	del /Q $(OBJS) $(TARGET) 2>nul

.PHONY: all clean