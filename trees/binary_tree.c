#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Node
{
    int value;
    Node *left;
    Node *right;
} Node;

Node *addNode(Node *root, Node *new_node)
{
    if (root == NULL)
    {
        return new_node;
    }

    if (new_node->value < root->value)
    {
        root->left = addNode(root->left, new_node);
    }

    if (new_node->value > root->value)
    {
        root->right = addNode(root->right, new_node);
    }

    return root;
}

Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("/ %i \\", root->value);
    printTree(root->right);
}

Node *binarySearch(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->value == value)
    {
        return root;
    }

    if (value < root->value)
    {
        return binarySearch(root->left, value);
    }

    return binarySearch(root->right, value);
}

int qtyNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return qtyNodes(root->left) + 1 + qtyNodes(root->right);
}

int main()
{
    Node *root_tree = addNode(NULL, createNode(10));

    root_tree = addNode(root_tree, createNode(11));
    root_tree = addNode(root_tree, createNode(9));
    root_tree = addNode(root_tree, createNode(8));

    printTree(root_tree);

    Node *node = binarySearch(root_tree, 7);
    if (node == NULL)
    {
        printf("\nNode not found\n");
    }
    else
    {
        printf("\n%i", node->value);
    }

    printf("Qty Nodes %i\n", qtyNodes(root_tree));

    return 0;
}
