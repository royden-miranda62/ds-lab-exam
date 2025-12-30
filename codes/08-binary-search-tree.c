#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} Node;

// create a node
Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// insert a node into the tree
void insert(Node **root, int item)
{
    if (*root == NULL)
    {
        *root = createNode(item);
        return;
    }

    // insert in left subtree
    if (item < (*root)->data)
    {
        if ((*root)->left != NULL) // if nodes already present
            insert(&((*root)->left), item);
        else // if no nodes present
            (*root)->left = createNode(item);
    }
    
    // insert in right subtree
    else if (item > (*root)->data)
    {
        if ((*root)->right != NULL)
            insert(&((*root)->right), item);
        else
            (*root)->right = createNode(item);
    }

}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    char opt;
    int value;
    Node *root = NULL;

    printf("-- Binary Search Tree Operations --\n");

    do
    {
        printf("\nEnter value to insert: ");
        scanf("%d", &value);

        insert(&root, value);

        printf("Do you want to insert more values? (y/n): ");
        getchar(); // Clear newline from buffer
        scanf("%c", &opt);
    } while (opt == 'y' || opt == 'Y');

    printf("\n--- Tree Traversals ---\n");

    printf("Preorder Traversal : ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal  : ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}