NAME = libgpio.a
TARGET = ../bin/$(NAME)
INC = -I../include/
OBJ = gpio.o
SRC = gpio.c

$(OBJ): $(SRC)
	$(CC) -c $^ $(INC)
	ar rcs $(TARGET) $@

clean:
	rm -f $(OBJ) $(TARGET)

