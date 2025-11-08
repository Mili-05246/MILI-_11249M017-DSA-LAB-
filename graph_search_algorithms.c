#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];
int n;  // Number of vertices

// Function declarations
void createGraph();
void BFS(int start);
void DFS(int start);

int main() {
    int choice, start;

    printf("------ Graph Search Algorithms (BFS and DFS) ------\n");

    createGraph();

    do {
        printf("\nMenu:\n");
        printf("1. Breadth First Search (BFS)\n");
        printf("2. Depth First Search (DFS)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                for (int i = 0; i < n; i++)
                    visited[i] = 0;
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;

            case 2:
                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);
                for (int i = 0; i < n; i++)
                    visited[i] = 0;
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

// Function to create a graph using adjacency matrix
void createGraph() {
    int edges, origin, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (origin destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &origin, &dest);
        if (origin >= n || dest >= n || origin < 0 || dest < 0) {
            printf("Invalid edge!\n");
            i--;
        } else {
            adj[origin][dest] = 1;
            adj[dest][origin] = 1; // Undirected graph
        }
    }
}

// Breadth-First Search
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Depth-First Search (recursive)
void DFS(int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] && !visited[i])
            DFS(i);
    }
}
