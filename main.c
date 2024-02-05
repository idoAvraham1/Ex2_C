#include <stdio.h>
#include "my_mat.h"
int main() {
    int graph[N][N];
    int i, j;
    char options;
    int IsValidMatrix=0;
    do {
        scanf(" %c", &options); 

        if (options == 'A') {
            initMatrix(graph);
            IsValidMatrix=1;
        } else if (options == 'B') {
            isValidPath(graph,IsValidMatrix);
           
        } else if (options == 'C') {
            shortestPathWeight(graph,IsValidMatrix);
        }
    } while (options != 'D');

    return 0;
}