 TARGET = temp_app_2.exe
 CC = gcc
 CFLAGS = -Wall -Wextra
 SRCS = main.c temp_api.c
 OBJS = $(SRCS:.c=.o)

 all: $(TARGET)

 $(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

 %.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	del /Q *.o *.exe 2>nul