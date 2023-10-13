FLAGS = -Wall
TARGET = lab1
SRCS = lab1.c lectura.c funciones.c salida.c
POSTFLAGS = -lm
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	gcc $(FLAGS) -o $(TARGET) $(OBJS) $(POSTFLAGS)

clear:
	rm -f $(OBJS) $(TARGET)
