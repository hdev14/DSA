#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX 50

typedef int Key;

typedef struct Node
{
    Key key;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LinkedList;

void startList(LinkedList *list)
{
    list->head = (Node *)malloc(sizeof(Node));
    list->head->next = list->head;
}

void restartList(LinkedList *list)
{
    Node *next = list->head->next;

    while (next != list->head)
    {
        Node *aux = next;
        next = next->next;
        free(aux);
    }

    list->head->next = list->head;
}

int listSize(LinkedList *list)
{
    Node *next = list->head->next;
    int size = 0;

    while (next != list->head)
    {
        size++;
        next = next->next;
    }

    return size;
}

void printList(LinkedList *list)
{
    Node *next = list->head->next;

    printf("List\n");

    while (next != list->head)
    {
        printf("%i ", next->key);
        next = next->next;
    }

    printf("\n");
}

Node *linearSearch(LinkedList *list, Key key)
{
    Node *next = list->head->next;
    list->head->key = key;

    while (next->key < key)
    {
        next = next->next;
    }

    if (next != list->head && next->key == key)
    {
        return next;
    }

    return NULL;
}

Node *getPreviousNode(LinkedList *list, Key key)
{
    Node *next = list->head->next;
    Node *previous = list->head;

    while (next != list->head && next->key < key)
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
    new_node->next = previous->next;
    previous->next = new_node;

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

    previous->next = node->next;

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
