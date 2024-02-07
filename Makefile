CC = gcc
CFLAGS = -Wall -g
OBJ = my_mat.o

all: my_graph my_Knapsack

# Create shared library with my_mat
libmy_mat.so: $(OBJ) my_mat.h
	$(CC) -shared -fpic -o $@ $^

# Build main with libmy_mat
my_graph: my_graph.o libmy_mat.so 
	$(CC) $(CFLAGS) my_graph.o ./libmy_mat.so -o my_graph

# Compile main.c 
my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) my_Knapsack.o -o my_Knapsack

# Clean all
clean:
	rm -f *.o *.so my_graph my_Knapsack