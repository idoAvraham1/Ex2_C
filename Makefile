CC = gcc
CFLAGS = -Wall -g
OBJ = my_mat.o

all: main

# Create shared library with my_mat
libmy_mat.so: $(OBJ) my_mat.h
	$(CC) -shared -fpic -o $@ $^

# Build main with libmy_mat
main: main.o libmy_mat.so 
	$(CC) $(CFLAGS) main.o ./libmy_mat.so -o main  

# Compile main.c 
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

# Clean all
clean:
	rm -f *.o *.so main