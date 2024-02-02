CC = gcc
CFLAGS = -Wall -g
OBJ= my_mat.o

all: main

# Create static library with my_mat
my_mat.a: $(OBJ)
	ar rcs $@ $^

# Build main with my_mat
main: main.o my_mat.a 
	$(CC) $(CFLAGS) main.o ./my_mat.a -o main  

#compile main.c 
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

# clean all
 clean:
	rm -f *.o *.a 