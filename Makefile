CC = gcc
CFLAGS = -g

TARGET = blackjack

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c functions.c

$(TARGET): 

clean:
	$(RM) $(TARGET)
