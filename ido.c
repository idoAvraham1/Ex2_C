#include <stdio.h>

#define N 4

void shortestPath(int graph[N][N], int dist[N][N]) {
    // Copy the input graph to the distance matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] != 0 && dist[k][j] != 0) {
                    if (dist[i][j] == 0 || dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[N][N] = {
        {0, 1, 0, 4},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {4, 0, 1, 0}
    };

    int dist[N][N];
    shortestPath(graph, dist);

    printf("Shortest distances between every pair of vertices:\n");
    printMatrix(dist);

    return 0;
}
