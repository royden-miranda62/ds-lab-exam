#include <stdio.h>
#include <conio.h>

#define SIZE 20

void bfs(int adjacencyMatrix[SIZE][SIZE],
         int numOfNodes,
         int sourceNode,
         int traversalTree[SIZE][2],
         int visited[SIZE])
{
    int queue[SIZE];
    int front = 0, rear = 0;
    int currentNode, neighbor;
    int edgeCount = 0;

    for (int i = 0; i < numOfNodes; i++)
        visited[i] = 0;

    queue[rear] = sourceNode;
    visited[sourceNode] = 1;

    while (front <= rear)
    {
        currentNode = queue[front++];
        for (neighbor = 0; neighbor < numOfNodes; neighbor++)
        {
            if (adjacencyMatrix[currentNode][neighbor] == 1 &&
                visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                queue[++rear] = neighbor;
                traversalTree[edgeCount][0] = currentNode;
                traversalTree[edgeCount][1] = neighbor;
                edgeCount++;
            }
        }
    }
}

int main()
{
    int adjacencyMatrix[SIZE][SIZE], traversalTree[SIZE][2];
    int numOfNodes, sourceNode;
    int visited[SIZE];

    // clrscr();

    printf("Enter the number of nodes: ");
    scanf("%d", &numOfNodes);

    printf("Enter the adjacency matrix (%d x %d):\n", numOfNodes, numOfNodes);
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }

    printf("Enter the source node (0 to %d): ", numOfNodes - 1);
    scanf("%d", &sourceNode);

    bfs(adjacencyMatrix, numOfNodes, sourceNode, traversalTree, visited);

    int unreachable = 0;
    printf("\nReachability from source node %d:\n", sourceNode);
    for (int i = 0; i < numOfNodes; i++)
    {
        if (visited[i] == 0)
        {
            printf("Node %d: NOT reachable\n", i);
            unreachable = 1;
        }
        else
            printf("Node %d: Reachable\n", i);
    }

    if (unreachable == 1)
        printf("\nGraph is disconnected.\n");
    else
    {
        printf("\nBFS traversal edges:\n");
        for (int i = 0; i < numOfNodes - 1; i++)
            printf("%d -> %d\n", traversalTree[i][0], traversalTree[i][1]);
    }

    // getch();

    return 0;
}