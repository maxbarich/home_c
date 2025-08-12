CC = gcc
CFLAGS = -Wall -std=c11
TARGET = temp_app.exe

all: $(TARGET)

$(TARGET): main.c temp_api.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c temp_api.c

clean:
	del /Q $(TARGET)