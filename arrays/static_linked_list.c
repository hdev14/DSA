#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 50
#define INVALID -1

typedef int Key;

typedef struct
{
    Key key;
    int next;
} Node;

typedef struct
{
    Node nodes[MAX];
    int start;
    int next_available;
} LinkedList;

void startList(LinkedList *list)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        list->nodes[i].next = i + 1;
    }

    list->nodes[MAX - 1].next = INVALID;
    list->start = INVALID;
    list->next_available = 0;
}

void restartList(LinkedList *list)
{
    startList(list);
}

int listSize(LinkedList *list)
{
    int size = 0;
    int next = list->start;

    while (next != INVALID)
    {
        size++;
        next = list->nodes[next].next;
    }

    return size;
}

void printList(LinkedList *list)
{
    int next = list->start;

    printf("List\n");

    while (next != INVALID)
    {
        printf("%i ", list->nodes[next].key);
        next = list->nodes[next].next;
    }

    printf("\n");
}

int getNextAvailable(LinkedList *list)
{
    int next_available = list->next_available;
    list->next_available = list->nodes[list->next_available].next;
    return next_available;
}

void makeAvailable(LinkedList *list, int next)
{
    list->nodes[next].next = list->next_available;
    list->next_available = next;
}

int linearSearch(LinkedList *list, Key key)
{

    for (
        int next = list->start;
        next != INVALID && list->nodes[next].key <= key;
        next = list->nodes[next].next)
    {
        if (list->nodes[next].key == key)
        {
            return next;
        }
    }

    return -1;
}

bool insertItem(LinkedList *list, Key key)
{
    if (list->next_available == INVALID)
    {
        return false;
    }

    int previous = INVALID;
    int next = list->start;

    while (next != INVALID && list->nodes[next].key < key)
    {
        previous = next;
        next = list->nodes[next].next;
    }

    if (next != INVALID && list->nodes[next].key == key)
    {
        return false;
    }

    int next_available = getNextAvailable(list);

    list->nodes[next_available].key = key;

    if (previous == INVALID)
    {
        list->nodes[next_available].next = list->start;
        list->start = next_available;
    }
    else
    {
        list->nodes[next_available].next = next;
        list->nodes[previous].next = next_available;
    }

    return true;
}

bool removeItem(LinkedList *list, Key key)
{
    int next = list->start;
    int previous = INVALID;

    while (next != INVALID && list->nodes[next].key < key)
    {
        previous = next;
        next = list->nodes[next].next;
    }

    if (next == INVALID || list->nodes[next].key != key)
    {
        return false;
    }

    if (previous == INVALID)
    {
        list->start = list->nodes[next].next;
    }
    else
    {
        list->nodes[previous].next = list->nodes[next].next;
    }

    makeAvailable(list, next);

    return true;
}

int main()
{
    LinkedList list;
    startList(&list);

    for (int i = 0; i < MAX; i++)
    {
        insertItem(&list, i + 1);
    }

    printList(&list);

    return 0;
}
