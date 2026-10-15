CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude

TARGET = geoshot
SOURCES = src/main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
