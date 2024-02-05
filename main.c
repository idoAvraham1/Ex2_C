#include <stdio.h>
#include "my_mat.h"
int main() {
    int graph[N][N];
    int dist[N][N];
    char options;
    int IsValidMatrix=0;
    do {
        scanf(" %c", &options); 

        if (options == 'A') {
            initMatrix(graph);
            shortestPath(graph,dist);
            IsValidMatrix=1;
        } else if (options == 'B') {

            isValidPath(dist,IsValidMatrix);
           
        } else if (options == 'C') {
            shortestPathWeight(dist,IsValidMatrix);
        }
    } while (options != 'D');

    return 0;
}