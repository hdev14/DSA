#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

#define ALPHABET 26

typedef struct Node
{
    Node *characters[ALPHABET];
    bool value;
} Node;

Node *createNode()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = false;
    for (int i = 0; i < ALPHABET; i++)
    {
        root->characters[i] = NULL;
    }
    return root;
}

int getCharacterIdx(char character)
{
    return ((int)character - (int)'a');
}

bool insertWord(Node *root, char *word)
{
    int length = strlen(word);
    Node *position = root;

    for (int i = 0; i < length; i++)
    {
        int character_idx = getCharacterIdx(word[i]);
        if (position->characters[character_idx] == NULL)
        {
            position->characters[character_idx] = createNode();
        }
        position = position->characters[character_idx];
    }

    position->value = true;
    return true;
}

bool wordExists(Node *root, char *word)
{
    int length = strlen(word);
    Node *position = root;

    for (int i = 0; i < length; i++)
    {
        int character_idx = getCharacterIdx(word[i]);
        if (position->characters[character_idx] == NULL)
        {
            return false;
        }
        position = position->characters[character_idx];
    }

    return position->value;
}

int main()
{
    Node *root_tree = createNode();

    insertWord(root_tree, "dog");
    insertWord(root_tree, "cat");
    insertWord(root_tree, "bird");
    insertWord(root_tree, "elephant");
    insertWord(root_tree, "lion");

    if (wordExists(root_tree, "hermerson"))
    {
        printf("This word exists\n");
    }
    else
    {
        printf("This word doesn't exist\n");
    }

    return 0;
}
