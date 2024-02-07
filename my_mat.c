#include "my_mat.h"
#include <stdio.h>
#include <math.h>

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
void isValidPath(int graph[N][N], int IsValidMatrix){
        int i, j;
         scanf("%d %d", &i, &j);
            if (graph[i][j] == 0 || IsValidMatrix==0) {
                printf("False\n");
            } else {
                printf("True\n");
            }

}
void shortestPathWeight(int graph[N][N], int IsValidMatrix){
    int i, j;
    scanf("%d %d", &i, &j);
            if (graph[i][j] == 0 || IsValidMatrix==0) {
                printf("-1\n");
            } else {
                printf("%d\n", graph[i][j]);
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



