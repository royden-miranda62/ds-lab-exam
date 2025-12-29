#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *stack = NULL, *queue = NULL; // declaring a stack and a queue linked list

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

// insert a node into the stack
void push(Node **head, int item)
{
    Node *newNode = createNode(item);

    newNode->next = *head;
    *head = newNode;

    printf("Pushed %d to stack.\n", item);
}

// delete a node from the stack
void pop(Node **head)
{
    if (*head == NULL)
    {
        printf("Stack underflow. Cannot delete.\n");
        return;
    }

    Node *tempNode = *head;
    *head = tempNode->next;

    printf("Popped %d from stack.\n", tempNode->data);
    free(tempNode);
}

// display all the nodes in the stack
void displayStack(Node *head)
{
    if (head == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack nodes (top to bottom): \n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// insert a node into the queue
void enqueue(Node **head, int item)
{
    Node *newNode = createNode(item);

    if (*head == NULL)
    {
        *head = newNode;
        printf("Inserted %d at rear (first node).\n", item);
        return;
    }

    Node *lastNode = *head;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;

    lastNode->next = newNode;
    printf("Inserted %d at rear.\n", item);
}

// delete a node from the queue
void dequeue(Node **head)
{
    if (*head == NULL)
    {
        printf("Queue underflow. Cannot delete.\n");
        return;
    }

    Node *tempNode = *head;
    *head = (*head)->next;
    printf("Deleted %d from front.\n", tempNode->data);
    free(tempNode);
}

// display all the nodes in the queue
void displayQueue(Node *head)
{
    if (head == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue nodes (front to rear): \n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");
        else
            printf("");

        temp = temp->next;
    }
    printf("\n\n");
}

int main()
{
    printf("--- Stack Operations ---\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    displayStack(stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack);

    printf("\n--- Queue Operations ---\n");
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    displayQueue(queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}