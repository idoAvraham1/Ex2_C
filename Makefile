CC = gcc
CFLAGS = -Wall -g
OBJ = my_mat.o

all: connections my_Knapsack

# Create shared library with my_mat
libmy_mat.so: $(OBJ) my_mat.h
	$(CC) -shared -fpic -o $@ $^

# Build main with libmy_mat
connections: main.o libmy_mat.so 
	$(CC) $(CFLAGS) main.o ./libmy_mat.so -o connections 

# Compile main.c 
main.o: main.c my_mat.h
	$(CC) $(CFLAGS) -c main.c

my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) my_Knapsack.o -o my_Knapsack

# Clean all
clean:
	rm -f *.o *.so connections my_Knapsack