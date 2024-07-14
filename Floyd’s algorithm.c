#include <stdio.h>
#define INF 999
#define min(a, b) ((a) < (b) ? (a) : (b))

void floyd(int p[][10], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main() {
    int a[10][10], n;
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (enter %d for infinity):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    floyd(a, n);

    printf("Shortest path matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (a[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", a[i][j]);
        printf("\n");
    }
    return 0;
}
