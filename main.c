
#include <stdio.h>
#include "my_mat.h"
#define N 10
int main() {
    int graph[N][N];
    int dist[N][N];

    int i=0;
    int j=0;
    char options='o';

   do {
        scanf("%c", &options);
        if(options =='A'){
            initMatrix(graph);
        }
        else if(options=='B'){
            scanf("%d %d ", &i, &j);
            shortestPath( graph, dist);
            if(dist[i][j]==0){
                printf("False \n");
            }
            else{
                printf("True \n");
            }
        }


        else if(options=='C'){
            scanf("%d %d ", &i, &j);
            shortestPath( graph, dist);
            if(dist[i][j]==0){
                printf("-1 \n");
            }
            else{
                printf("%d \n",dist[i][j]);
            }
        }
        if (options=='D'){
            return 0;
        }

    }
     while(options!='D');
}