#include <stdio.h>
#include <stdlib.h>

// node implementation
typedef struct Node
{
    int data;
    struct Node *next; // pointer to location of next node
} Node;

// create a node
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // allocate memory for the node
    // node is typecasted to a pointer

    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// insert a node at the start of the list
void insAtStart(Node **head, int item)
{
    Node *newNode = createNode(item); // creating a new node with passed data

    newNode->next = *head; // newNode points to previous head
    *head = newNode;       // newNode becomes new head

    printf("Inserted %d at start.\n", item);
}

// insert a node at the end of the list
void insAtEnd(Node **head, int item)
{
    Node *newNode = createNode(item);

    if (*head == NULL) // if list is empty
    {
        *head = newNode; // make the newNode the head
        printf("Inserted %d at end (first node).\n", item);
        return;
    }

    Node *lastNode = *head;        // traversal node assigned to the head (start of list)
    while (lastNode->next != NULL) // traverse till end of list
        lastNode = lastNode->next; // traversal node shifted ahead
    // lastNode is now the last node in the list

    lastNode->next = newNode; // lastNode points to the new node, newNode at the end

    printf("Inserted %d at end.\n", item);
}

// insert a node at a user-defined position
void insAtLeft(Node **head, int pos, int item)
{
    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insAtStart(head, item);
        return;
    }

    Node *prevNode = *head;
    for (int i = 1; i < pos - 1 && prevNode != NULL; i++)
        prevNode = prevNode->next;
    // prevNode is now the node just before the target position

    if (prevNode == NULL) // if target position does not exist
    {
        printf("\nInvalid position.\n");
        return;
    }

    Node *newNode = createNode(item);
    Node *targetNode = prevNode->next;
    newNode->next = targetNode; // newNode points to targetNode
    prevNode->next = newNode;   // prevNode points to newNode
    // prevNode -> newNode -> targetNode

    printf("Inserted %d at position %d.\n", item, pos);
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

    printf("----- Linked List Insertion -----\n");

    printf("\n--- Insertion At Start ---\n");
    insAtStart(&head, 10);
    insAtStart(&head, 20);
    insAtStart(&head, 30);
    displayList(head);

    printf("\n--- Insertion At End ---\n");
    insAtEnd(&head, 40);
    insAtEnd(&head, 50);
    displayList(head);

    printf("\n--- Insertion At Position ---\n");
    insAtLeft(&head, 2, 25);
    insAtLeft(&head, 5, 45);
    displayList(head);

    freeList(head);

    return 0;
}