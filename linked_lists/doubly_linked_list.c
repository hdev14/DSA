#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX 50

typedef int Key;

typedef struct Node
{
    Key key;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct
{
    Node *start;
} LinkedList;

void startList(LinkedList *list)
{
    list->start = NULL;
}

void restartList(LinkedList *list)
{
    Node *next = list->start;

    while (next != NULL)
    {
        Node *aux = next;
        next = next->next;
        free(aux);
    }

    list->start = NULL;
}

int listSize(LinkedList *list)
{
    Node *next = list->start;
    int size = 0;

    while (next != NULL)
    {
        size++;
        next = next->next;
    }

    return size;
}

void printList(LinkedList *list)
{
    Node *next = list->start;

    printf("List\n");

    while (next != NULL)
    {
        printf("%i ", next->key);
        next = next->next;
    }

    printf("\n");
}

Node *linearSearch(LinkedList *list, Key key)
{
    Node *next = list->start;

    while (next != NULL)
    {
        if (next->key == key)
        {
            return next;
        }

        next = next->next;
    }

    return NULL;
}

Node *getPreviousNode(LinkedList *list, Key key)
{
    Node *next = list->start;
    Node *previous = NULL;

    while (next != NULL && next->key < key)
    {
        previous = next;
        next = next->next;
    }

    return previous;
}

bool insertNode(LinkedList *list, Key key)
{
    if (linearSearch(list, key) != NULL)
    {
        return false;
    }

    Node *previous = getPreviousNode(list, key);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;

    if (previous == NULL)
    {
        new_node->next = list->start;
        list->start = new_node;
    }
    else
    {
        new_node->next = previous->next;
        previous->next = new_node;
        new_node->previous = previous;
        if (new_node->next != NULL)
        {
            new_node->next->previous = new_node;
        }
    }

    return true;
}

bool removeNode(LinkedList *list, Key key)
{
    Node *node = linearSearch(list, key);

    if (node == NULL)
    {
        return false;
    }

    Node *previous = getPreviousNode(list, node->key);

    if (previous == NULL)
    {
        list->start = node->next;
        list->start->previous = NULL;
    }
    else
    {
        previous->next = node->next;
        previous->next->previous = previous;
    }

    free(node);
    return true;
}

int main()
{
    LinkedList list;
    startList(&list);

    for (int i = 0; i < MAX; i++)
    {
        insertNode(&list, i + 1);
    }

    printList(&list);

    printf("List size => %i \n", listSize(&list));

    printf("Item -> %i \n", linearSearch(&list, 40)->key);

    removeNode(&list, 40);

    printList(&list);

    restartList(&list);

    return 0;
}
