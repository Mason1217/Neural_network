CC = gcc
CFLAGS = -Wall -Wextra -O2
OBJS = matrix_test.o Matrix.o utilities.o activation_functions.o Layer.o
TARGET = matrix_test

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
