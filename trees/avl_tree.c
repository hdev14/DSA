#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Node
{
    int value;
    Node *left;
    Node *right;
    int height;
} Node;

Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 0;

    return new_node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int calculateHeight(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    return max(calculateHeight(root->left), calculateHeight(root->right)) + 1;
}

Node *rotateLeft(Node *root)
{
    Node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    new_root->height = calculateHeight(new_root);
    root->height = calculateHeight(root);

    return new_root;
}

Node *rotateRight(Node *root)
{
    Node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    new_root->height = calculateHeight(new_root);
    root->height = calculateHeight(root);

    return new_root;
}

Node *rotateLeftRight(Node *node)
{
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

Node *rotateRightLeft(Node *node)
{
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

int isBalanced(Node *left, Node *right)
{
    int leftHeight = left != NULL ? left->height : -1;
    int rightHeight = right != NULL ? right->height : -1;
    int result = leftHeight - rightHeight;
    return result < 2 && result > -2;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
        if (!isBalanced(root->left, root->right))
        {
            root = value < root->left->value
                       ? rotateRight(root)
                       : rotateLeftRight(root);
        }
    }
    else
    {
        root->right = insert(root->right, value);
        if (!isBalanced(root->left, root->right))
        {
            root = value > root->right->value
                       ? rotateLeft(root)
                       : rotateRightLeft(root);
        }
    }

    root->height = calculateHeight(root);

    return root;
}

// TODO bool remove(Node* root, int value)

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %i[%i] (", root->value, root->height);
    printTree(root->left);
    printTree(root->right);
    printf(") ");
}

int main()
{
    Node *root_tree = insert(NULL, 10);

    root_tree = insert(root_tree, 11);
    root_tree = insert(root_tree, 9);
    root_tree = insert(root_tree, 8);
    root_tree = insert(root_tree, 7);

    printTree(root_tree);

    return 0;
}
