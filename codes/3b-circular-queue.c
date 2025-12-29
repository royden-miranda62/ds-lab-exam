#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int cirQueue[SIZE];
int front = -1, rear = -1;

// check if the queue is full
bool isFull()
{
    return ((rear + 1) % SIZE == front);
}

// check if the queue is empty
bool isEmpty()
{
    return (front == -1);
}

// insert an element into the queue
void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue overflow. Cannot insert %d.\n", item);
        return;
    }

    // if queue is empty
    if (front == -1)
        front = rear = 0; // initialize front and rear pointers for first element
    // if some elements are already in queue
    else
        rear = (rear + 1) % SIZE; // move rear pointer to next position
    // if rear at end (SIZE - 1), reset to 0 after insertion
    // (SIZE - 1 + 1) % SIZE = SIZE % SIZE = 0

    cirQueue[rear] = item;
    printf("Inserted %d at the rear.\n", item);
}

// delete an element from the queue
void dequeue()
{
    if (isEmpty())
    {
        printf("Underflow. Cannot delete.\n");
        return;
    }

    printf("Deleted %d from the front.\n", cirQueue[front]);

    if (front == rear)              // if queue now empty
        front = rear = -1;          // reset front and rear pointers
    else                            // if elements remain
        front = (front + 1) % SIZE; // move front pointer to next position
}

// display the elements in the queue
void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular queue elements: \n");
    int i = front;
    printf("|");
    do
    {
        printf(" %d |", cirQueue[i]);
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);
    printf("\n\n");
}

int main()
{
    printf("----- Circular Queue Operations -----\n");
    printf("Size of circular queue = %d\n", SIZE);

    printf("\n--- Enqueue ---\n");
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(30);

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