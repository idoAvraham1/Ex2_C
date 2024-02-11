#include "my_mat.h"
#include <stdio.h>
#include <math.h>

 
 /**
 * @brief Find the shortest path in the given graph using Floyd-Warshall algorithm.
 *
 * This function calculates the shortest path between all pairs of vertices in the graph
 * using the Floyd-Warshall algorithm and updates the distance matrix accordingly.
 *
 * @param graph The input graph represented as an adjacency matrix.
 * @param dist The matrix to store the shortest distances between each pair of vertices.
 */
 void shortestPath(int graph[N][N],int dist[N][N]){
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
     }
     for (int k = 0; k < N; k++) {
         for (int i = 0; i < N; i++) {
             for (int j = 0; j < N; j++) {
                 if (i != j) {
                     if (dist[i][k] != 0 &&  dist[k][j] != 0) {
                         if (dist[i][j] == 0 || dist[i][j] > dist[i][k] + dist[k][j]) {
                             dist[i][j] = dist[i][k] + dist[k][j];
                         }
                     }
                 }
             }
         }
     }
 }

 /**
 * @brief Check if a path in the graph is valid.
 *
 * This function checks if a path between two vertices in the graph is valid based on the
 * values in the dist matrix.
 *
 * @param graph The distnace matrix of the corresponding graph represented as an adjacency matrix.
 * @param IsValidMatrix flag for checking if the matrix is init.
 *                      (1 if valid, 0 if not valid)
 */
void isValidPath(int graph[N][N], int IsValidMatrix){
        int i, j;
         scanf("%d %d", &i, &j);
            if (graph[i][j] == 0 || IsValidMatrix==0) {
                printf("False\n");
            } else {
                printf("True\n");
            }

}
/**
 * @brief Calculate the weight of the shortest path between two vertices in the graph.
 *
 * This function calculates the weight of the shortest path between two vertices in the graph
 * based on the values in the distances matrix.
 *
 * @param graph The input graph represented as an adjacency matrix.
 * @param IsValidMatrix flag for checking if the matrix is init.
                        (1 if valid, 0 if not valid)
 */
void shortestPathWeight(int graph[N][N], int IsValidMatrix){
    int i, j;
    scanf("%d %d", &i, &j);
            if (graph[i][j] == 0 || IsValidMatrix==0) {
                printf("-1\n");
            } else {
                printf("%d\n", graph[i][j]);
            }

}

/**
 * @brief Initialize the matrix with values from the user.
 *
 * @param graph The matrix to be initialized.
 */
void initMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            scanf("%d", &val);
            matrix[i][j]=val;
        }
    }
}



