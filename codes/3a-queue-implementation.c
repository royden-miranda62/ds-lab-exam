#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1; // initializing the front and rear pointers

// check if queue is full
bool isFull()
{
    return (rear == SIZE - 1);
}

// check if queue is empty
bool isEmpty()
{
    return (front == -1 || front > rear);
}

// insert an element at the rear of the queue
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue overflow. Cannot insert %d.\n", item);
        return;
    }

    if (front == -1) // if queue is empty
        front = 0; // initialize the front pointer for first element

    queue[++rear] = item;
    printf("Inserted %d at rear.\n", item);
}

// delete an element from the front of the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow. Cannot delete.\n");
        front = rear = -1;
        return;
    }

    int deleted = queue[front++];
    printf("Deleted %d from front.\n", deleted);
}

// display all the elements in the queue
void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nQueue elements (front to rear): \n");
    printf("|");
    for (int i = front; i <= rear; i++)
        printf(" %d |", queue[i]);
    printf("\n\n");
}

int main()
{
    printf("----- Queue Operations -----\n");
    printf("Size of queue = %d\n", SIZE);

    printf("\n--- Enqueue ---\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);

    display();

    printf("\n--- Dequeue ---\n");
    dequeue();
    dequeue();
    dequeue();

    display();

    dequeue();
    dequeue();
    dequeue();

    display();
    
    return 0;
}