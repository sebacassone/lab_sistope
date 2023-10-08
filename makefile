FLAGS = -Wall
TARGET = programa
SRCS = main.c lectura.c funciones.c
POSTFLAGS = -lm
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	gcc $(FLAGS) -o $(TARGET) $(OBJS) $(POSTFLAGS)

clear:
	rm -f $(OBJS) $(TARGET)
