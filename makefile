FLAGS = -Wall -lm
TARGET = programa
SRCS = main.c lectura.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	gcc $(FLAGS) -o $(TARGET) $(OBJS)

clear:
	rm -f $(OBJS) $(TARGET)
