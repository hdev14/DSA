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

Node *getNode(Node *root, float value, Node **previous)
{
    Node *current = root;
    *previous = NULL;

    while (current != NULL && current->value != value)
    {
        *previous = current;
        if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    if (current != NULL && current->value == value)
    {
        return current;
    }

    return NULL;
}

Node *removeNode(Node *root, float value)
{
    Node *previous = NULL;
    Node *node = getNode(root, value, &previous);

    if (node == NULL)
    {
        return root;
    }

    Node *child;

    if (node->left == NULL || node->right == NULL)
    {
        child = node->left == NULL ? node->right : node->left;
    }
    else
    {
        Node *father = node;
        child = node->left;
        while (child->right != NULL)
        {
            father = child;
            child = child->right;
        }

        if (father != node)
        {
            father->right = child->left;
            child->left = node->left;
        }

        child->right = node->right;
    }

    // ROOT
    if (previous == NULL)
    {
        free(node);
        return child;
    }

    if (value < previous->value)
    {
        previous->left = child;
    }
    else
    {
        previous->right = child;
    }

    free(node);

    return root;
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

    root_tree = removeNode(root_tree, 9);

    printTree(root_tree);

    return 0;
}
