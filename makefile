CC = gcc
CFLAGS = -Wall -Wextra -O2 -MMD -MP
OBJS = matrix_test.o Matrix.o utilities.o Layer.o
DEPS = $(OBJS:.o=.d)
TARGET = matrix_test

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $<

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)