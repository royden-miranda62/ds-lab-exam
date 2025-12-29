#include <stdio.h>
#include <stdlib.h>

// node implementation
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// creating a node
Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Error:Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// insert a node at the start of the list
void insAtStart(Node **head, int item)
{
    Node *newNode = createNode(item);

    if (*head == NULL)
    {
        *head = newNode;
        printf("Inserted %d at start (first node).\n", item);
        return;
    }

    newNode->next = *head;   // head is after newNode
    (*head)->prev = newNode; // newNode is before head
    *head = newNode;         // newNode becomes head
    // NULL <-> newNode >-> head

    printf("Inserted %d at start.\n", item);
}

// insert a node at the left of a given node
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
    // prevNode is now the node just before the target node

    if (prevNode == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    Node *newNode = createNode(item);
    Node *targetNode = prevNode->next;
    newNode->next = targetNode; // targetNode is after newNode
    newNode->prev = prevNode;   // prevNode is before newNode

    if (targetNode != NULL)
        targetNode->prev = newNode; // newNode is before targetNode
    prevNode->next = newNode;       // newNode is after prevNode
    // prevNode <-> newNode <-> targetNode

    printf("Inserted %d at position %d.\n", item, pos);
}

// delete a node by value
void delByValue(Node **head, int item)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *targetNode = *head;

    // search for the node
    while (targetNode != NULL && targetNode->data != item)
        targetNode = targetNode->next;

    // item not found
    if (targetNode == NULL)
    {
        printf("Item not found.\n");
        return;
    }

    // if targetNode is head
    if (targetNode->prev == NULL)
    {
        *head = targetNode->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }

    else
        (targetNode->prev)->next = targetNode->next;
    // if targetNode is not the last node
    if (targetNode->next != NULL)
        (targetNode->next)->prev = targetNode->prev;

    free(targetNode);
    printf("Deleted value %d node.\n", item);
}

// display nodes in the list
void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("\nList: \nNULL");
        return;
    }

    Node *temp = head;
    printf("\nList:\n");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    printf("----- Doubly Linked List Operations -----\n");

    printf("\n--- Insert At Start ---\n");
    insAtStart(&head, 30);
    insAtStart(&head, 20);
    insAtStart(&head, 10);
    displayList(head);

    printf("\n--- Insert At Left ---\n");
    insAtLeft(&head, 2, 15);
    displayList(head);

    insAtLeft(&head, 5, 40);
    displayList(head);

    printf("\n--- Delete By Value ---\n");
    delByValue(&head, 20);
    displayList(head);

    return 0;
}