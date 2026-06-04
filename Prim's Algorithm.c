#include <stdio.h>

#define INF 999999

int minKey(int key[], int mstSet[], int n) {
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[100][100], int n) {
    int totalCost = 0;
    
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++) {
        int weight = graph[i][parent[i]];
        printf("%d - %d \t%d\n", parent[i], i, weight);
        totalCost = totalCost + weight;
    }
    
    printf("Total Cost of MST = %d\n", totalCost);
}

void primMST(int graph[100][100], int n) {
    int parent[100];
    int key[100];
    int mstSet[100];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && mstSet[v] == 0) {
                if (graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
    }

    printMST(parent, graph, n);
}

int main() {
    int graph[100][100];
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%dx%d):\n", n, n);
    printf("(Enter 0 if no edge exists)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, n);

    return 0;
}
