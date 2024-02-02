CC = gcc
CFLAGS = -Wall -g
OBJ= my_mat.o

all: main

# Create static library with my_mat
libmy_mat.so: $(OBJ) my_mat.h
	$(CC) -shared -fpic -o $@ $^

# Build main with my_mat
main: main.o my_mat.so 
	$(CC) $(CFLAGS) main.o ./libmy_mat.so -o main  

#compile main.c 
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

# clean all
 clean:
	rm -f *.o *.a main 