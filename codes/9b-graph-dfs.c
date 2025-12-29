#include <stdio.h>
#include <conio.h>

#define SIZE 10

void dfs(int numOfNodes,
         int adjacencyMatrix[SIZE][SIZE],
         int currentNode,
         int visited[])
{
    int neighbor;
    visited[currentNode] = 1;

    for (neighbor = 0; neighbor < numOfNodes; neighbor++)
    {
        if ((adjacencyMatrix[currentNode][neighbor] == 1) &&
            (visited[neighbor] == 0))
            dfs(numOfNodes, adjacencyMatrix, neighbor, visited);
    }
}

int main()
{
    int numOfNodes;
    int adjacencyMatrix[SIZE][SIZE], visited[SIZE];
    int isConnected, allReachable;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numOfNodes);

    printf("Enter the adjacency matrix (%d x %d):\n", numOfNodes, numOfNodes);
    for (int i = 0; i < numOfNodes; i++)
    {
        for (int j = 0; j < numOfNodes; j++)
            scanf("%d", &adjacencyMatrix[i][j]);
    }

    isConnected = 0;

    // Check connectivity by performing DFS from each node
    for (int j = 0; j < numOfNodes; j++)
    {
        // Reset visited array for new DFS
        for (int i = 0; i < numOfNodes; i++)
            visited[i] = 0;

        // Perform DFS starting from node j
        dfs(numOfNodes, adjacencyMatrix, j, visited);

        allReachable = 1;

        // Check if all nodes were visited from source j
        for (int i = 0; i < numOfNodes; i++)
        {
            if (visited[i] == 0)
                allReachable = 0; // Node i was not reached
        }

        // If all nodes are reachable from node j, graph is connected
        if (allReachable == 1)
            isConnected = 1;
    }

    if (isConnected == 1)
        printf("\nThe graph is connected.\n");
    else
        printf("\nThe graph is not connected.\n");

    return 0;
}