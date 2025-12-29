#include <stdio.h>
#include <stdlib.h>

// node implementation
typedef struct Node
{
    int data;
    struct Node *next; 
} Node;

// create a node
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); 

    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// insert a node at the end of the list
void insAtEnd(Node **head, int item)
{
    Node *newNode = createNode(item);

    if (*head == NULL) // if list is empty
    {
        *head = newNode; // make the new node the head
        printf("Inserted %d at end (first node).\n", item);
        return;
    }

    Node *lastNode = *head;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    // lastNode is now the last node in the list

    lastNode->next = newNode; // lastNode points to the new node, newNode at the end

    printf("Inserted %d at end.\n", item);
}

// delete a node from the start of the list
void delFromStart(Node **head)
{
    if (*head == NULL) // if list is empty
    {
        printf("\nList is empty.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        printf("Deleted node from start (only node).\n");
        return;
    }

    Node *temp = *head;    // assign temporary node to head position
    *head = (*head)->next; // node after head becomes new head
    free(temp);            // memory at previous head's address freed

    printf("Deleted node from start.\n");
}

// delete a node from the end of the list
void delFromEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    if ((*head)->next == NULL) // if only one node in the list
    {
        free(*head);  // memory at head location freed
        *head = NULL; // head points to null (empty list)
        printf("Deleted node from end (only node).\n");
        return;
    }

    // if multiple nodes in the list
    Node *lastNode = *head;
    Node *prevNode = NULL; // temporary node to hold second last node's address

    while (lastNode->next != NULL)
    {
        prevNode = lastNode;
        lastNode = lastNode->next;
    }
    // lastNode is now the last node in the list
    // prevNode is now the node before the last node
    // prevNode -> lastNode -> NULL

    prevNode->next = NULL; // current node points to NULL
    // current node is now the new last node
    free(lastNode); // memory at previous last node's address freed
    printf("Deleted last node.\n");
}

// delete a node from a user-defined position
void delFromPos(Node **head, int pos)
{
    if (*head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        delFromStart(head);
        return;
    }

    Node *currentNode = *head;
    for (int i = 1; i < pos - 1 && currentNode != NULL; i++)
        currentNode = currentNode->next;
    // currentNode is now the node just before the target position

    if (currentNode == NULL || currentNode->next == NULL) // if currentNode is the last node
    {
        printf("\nCannot delete at position %d.\n", pos);
        return;
    }

    Node *targetNode = currentNode->next;
    currentNode->next = targetNode->next; // currentNode points to same address as targetNode
    free(targetNode);                     // memory at targetNode's address freed

    printf("Deleted %d position node.\n", pos);
}

// display nodes in the list
void displayList(Node *head)
{

    if (head == NULL)
    {
        printf("\nList: \nNULL\n");
        return;
    }

    Node *temp = head;
    printf("\nList: \n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// free the memory used by the list
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\nMemory freed successfully.\n");
}

int main()
{
    Node *head = NULL;

    printf("----- Linked List Deletion -----\n");

    printf("\n--- Insertion At End ---\n");
    insAtEnd(&head, 10);
    insAtEnd(&head, 20);
    insAtEnd(&head, 30);
    insAtEnd(&head, 40);
    insAtEnd(&head, 50);
    displayList(head);

    printf("\n--- Deletion From Start ---\n");
    delFromStart(&head);
    displayList(head);

    printf("\n--- Deletion From End ---\n");
    delFromEnd(&head);
    displayList(head);

    printf("\n--- Deletion From Position ---\n");
    delFromPos(&head, 2);
    displayList(head);

    freeList(head);

    return 0;
}