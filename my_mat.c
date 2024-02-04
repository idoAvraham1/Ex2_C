
#include "my_mat.h"
#include <math.h>
#define N 4

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


void initMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            scanf("%d", &val);
            matrix[i][j]=val;
        }
    }
}



