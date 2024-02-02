int main() {
    int graph[N][N];
    int dist[N][N];
    int i, j;
    char options;

    do {
        scanf(" %c", &options); 

        if (options == 'A') {
            initMatrix(graph);
        } else if (options == 'B') {
            scanf("%d %d", &i, &j);
            shortestPath(graph, dist);
            if (dist[i][j] == 0) {
                printf("False\n");
            } else {
                printf("True\n");
            }
        } else if (options == 'C') {
            scanf("%d %d", &i, &j);
            shortestPath(graph, dist);
            if (dist[i][j] == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", dist[i][j]);
            }
        }
    } while (options != 'D');

    return 0;
}