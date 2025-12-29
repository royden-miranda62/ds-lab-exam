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

// reverse a linked list
void reverseList(Node **head)
{
    Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL)
    {
        next = current->next; // node after current node assigned to next
        current->next = prev; // node after current node set to null
        prev = current;       // prev shifted ahead by one node
        current = next;       // current shifted ahead by one node
    }

    *head = prev; // head updated
}

// bubble sort a list
void sortList(Node **head)
{
    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    int swapped;
    Node *currentNode;

    do
    {
        swapped = 0;
        currentNode = *head;

        while (currentNode->next != NULL)
        {
            if (currentNode->data > currentNode->next->data)
            {
                int temp = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = temp;
                swapped = 1;
            }
            currentNode = currentNode->next;
        }
    } while (swapped);
}

// concatenate two unsorted lists
void concatenateLists(Node **list1, Node *list2)
{
    if (*list1 == NULL) // if list1 is empty
    {
        *list1 = list2; // list1 becomes list2
        return;
    }

    if (list2 == NULL)
        return;

    Node *currentNode = *list1; // traversal node assigned to start of list 1
    while (currentNode->next != NULL)
        currentNode = currentNode->next;
    // current is now at the end of list 1

    currentNode->next = list2; // list 2 is joined at the end of list 1
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
    printf("----- Linked List Operations -----\n");

    Node *list1 = NULL;
    printf("\n--- Creating First List ---\n");
    insAtEnd(&list1, 30);
    insAtEnd(&list1, 10);
    insAtEnd(&list1, 50);
    insAtEnd(&list1, 20);
    insAtEnd(&list1, 40);
    displayList(list1);

    printf("\n--- Reversing ---\n");
    reverseList(&list1);
    displayList(list1);

    printf("\n--- Sorting ---\n");
    sortList(&list1);
    displayList(list1);

    Node *list2 = NULL;
    printf("\n--- Creating Second List ---\n");
    insAtEnd(&list2, 15);
    insAtEnd(&list2, 25);
    insAtEnd(&list2, 35);
    insAtEnd(&list2, 45);
    displayList(list2);

    printf("\n--- Reversing ---\n");
    reverseList(&list2);
    displayList(list2);

    printf("\n--- Sorting ---\n");
    sortList(&list2);
    displayList(list2);

    printf("\n--- Concatenation ---\n");
    concatenateLists(&list1, list2);
    displayList(list1);

    freeList(list1);

    return 0;
}