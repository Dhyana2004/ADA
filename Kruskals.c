#include <stdio.h>
#define INF 999
#define MAX 100

int p[MAX], c[MAX][MAX], t[MAX][2];

int find(int v) {
    while (p[v]) v = p[v];
    return v;
}

void union1(int i, int j) {
    p[j] = i;
}

void kruskal(int n) {
    int i, j, k, u, v, min, sum = 0;
    for (k = 1; k < n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i != j && c[i][j] < min) {
                    u = find(i); v = find(j);
                    if (u != v) {
                        t[k][0] = i; t[k][1] = j;
                        min = c[i][j];
                    }
                }
            }
        }
        union1(t[k][0], find(t[k][1]));
        sum += min;
    }
    printf("\nCost of spanning tree = %d\nEdges of spanning tree:\n", sum);
    for (i = 1; i < n; i++) printf("%d -> %d\n", t[i][0], t[i][1]);
}

int main() {
    int i, j, n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) p[i] = 0;
    printf("Enter the graph data (adjacency matrix):\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0 && i != j) c[i][j] = INF;
        }
    kruskal(n);
    return 0;
}
