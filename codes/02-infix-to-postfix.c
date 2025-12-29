#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50

// declaring and initializing a stack
char stack[SIZE];
int top = -1;

// insert a character into the stack
void push(char item)
{
    if (top >= SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = item;
}

// delete a character from the stack
char pop()
{
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

// check the precedence of a character (pedmas)
int precedence(char symb)
{
    if (symb == '^')
        return 3;
    else if (symb == '*' || symb == '/')
        return 2;
    else if (symb == '+' || symb == '-')
        return 1;
    else
        return 0;
}

// convert a given infix expression to postfix
void convertToPostfix(char infix[], char postfix[])
{
    char ch;
    int i = 0, j = 0;

    push('#'); // "sentinel" character, avoids having to repeatedly checking for isEmpty

    while ((ch = infix[i++]) != '\0')
    {
        if (isspace(ch))
            continue;

        if (isalnum(ch)) // for variables/operands
            postfix[j++] = ch;

        else if (ch == '(')
            push(ch);

        else if (ch == ')')
        {
            while (stack[top] != '#' && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // discards '('
        }

        else
        {
            while (stack[top] != '#' && precedence(ch) <= precedence(stack[top]))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, SIZE, stdin);

    convertToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}