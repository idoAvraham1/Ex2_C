#include "my_mat.h"
#include <stdio.h>
#include <math.h>
#define N 10

 void shortestPath(int graph[N][N]){
     for (int k = 0; k < N; k++) {
         for (int i = 0; i < N; i++) {
             for (int j = 0; j < N; j++) {
                 if (i != j) {
                     if (graph[i][k] != 0 &&  graph[k][j] != 0) {
                         if (graph[i][j] == 0 ||graph[i][j] > graph[i][k] + graph[k][j]) {
                             graph[i][j] = graph[i][k] + graph[k][j];
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
                printf("False \n");
            } else {
                printf("True\n");
            }

}
void shortestPathWeight(int graph[N][N], int IsValidMatrix){
    int i, j;
    scanf("%d %d", &i, &j);
            if (graph[i][j] == 0 || IsValidMatrix==0) {
                printf("-1 \n");
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



