#include <stdio.h>
#include "my_mat.h"
int main() {
    int graph[N][N];
    int dist[N][N];
    int i, j;
    char options;
    int IsValidMatrix=0;
    do {
        scanf(" %c", &options); 

        if (options == 'A') {
            initMatrix(graph);
              shortestPath(graph, dist);
            IsValidMatrix=1;
        } else if (options == 'B') {
            scanf("%d %d", &i, &j);
            if (dist[i][j] == 0 || IsValidMatrix==0) {
                printf("False\n");
            } else {
                printf("True\n");
            }
        } else if (options == 'C') {
            scanf("%d %d", &i, &j);
            if (dist[i][j] == 0 || IsValidMatrix==0) {
                printf("-1\n");
            } else {
                printf("%d\n", dist[i][j]);
            }
        }
    } while (options != 'D');

    return 0;
}