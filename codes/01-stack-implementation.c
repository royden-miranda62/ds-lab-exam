#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int stack[SIZE];
int top = -1; // initializing the top pointer

// check if the stack is full
bool isFull()
{
    return (top == SIZE - 1);
}

// check if the stack is empty
bool isEmpty()
{
    return (top == -1);
}

// insert an element into the stack
void push(int item)
{
    if (isFull()) // top at max. index
    {
        printf("Stack overflow. Cannot push %d.\n", item);
        return;
    }

    stack[++top] = item; // incrementing the top before assignment
    printf("Pushed %d to stack.\n", item);
}

// delete an element from the stack
void pop()
{
    int popped;
    if (isEmpty()) // top below min. index
    {
        printf("Stack underflow. Cannot pop.\n");
        return;
    }

    popped = stack[top--]; // decrementing the top after assignment
    printf("Popped %d from stack.\n", popped);
}

// print the element at the top of the stack
void peek()
{
    if (isEmpty())
        printf("Stack is empty.\n");
    else
        printf("Top element: %d\n", stack[top]);
}

// print all the elements in the stack
void display()
{
    if (isEmpty())
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nStack elements (top to bottom): \n");
    printf("------\n");
    for (int i = top; i > -1; i--)
        printf("| %d |\n", stack[i]);
    printf("------\n\n");
}

int main()
{
    printf("----- Stack Operations -----\n");
    printf("Size of stack = %d\n", SIZE);

    printf("\n--- Push ---\n");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    display();

    printf("\n--- Pop ---\n");
    pop();
    pop();
    pop();

    display();

    pop();
    pop();
    pop();

    display();

    printf("\n--- Peek ---\n");
    push(1);
    push(2);
    push(3);
    peek();

    return 0;
}