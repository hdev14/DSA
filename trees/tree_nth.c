#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Node
{
    int value;
    Node *next;
    Node *adjcent;
} Node;

Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->adjcent = NULL;
    new_node->next = NULL;
    return new_node;
}

Node *findNode(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->value == value)
    {
        return root;
    }

    Node *next = root->next;

    while (next != NULL)
    {
        Node *node = findNode(next, value);
        if (node != NULL)
        {
            return node;
        }
        next = next->adjcent;
    }

    return NULL;
}

bool insertNode(Node *root, int parent_value, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node *parent = findNode(root, parent_value);

    if (parent == NULL)
    {
        return root;
    }

    Node *new_node = createNode(value);

    if (parent->next == NULL)
    {
        parent->next = new_node;
        return true;
    }

    Node *next = parent->next;

    while (next->adjcent != NULL)
    {
        next = next->adjcent;
    }

    next->adjcent = new_node;

    return true;
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%i(", root->value);

    Node *next = root->next;

    while (next != NULL)
    {
        printTree(next);
        next = next->adjcent;
    }

    printf(")");
}

int main()
{
    Node *root_tree = createNode(10);

    insertNode(root_tree, 10, 2);
    insertNode(root_tree, 10, 3);
    insertNode(root_tree, 3, 1);
    insertNode(root_tree, 2, 6);

    printTree(root_tree);

    Node *result = findNode(root_tree, 11);

    if (result == NULL)
    {
        printf("\nNot found\n");
    }
    else
    {
        printf("\nNode %i\n", result->value);
    }

    return 0;
}
