#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX 5

typedef struct Item
{
    int key;
    struct Item *next;
} Item;

typedef struct
{
    Item *start;
} PriorityQueue;

void startQueue(PriorityQueue *queue)
{
    queue->start = NULL;
}

void restartQueue(PriorityQueue *queue)
{
    Item *next = queue->start;

    while (next != NULL)
    {
        Item *aux = next;
        next = next->next;
        free(aux);
    }

    queue->start = NULL;
}

int queueSize(PriorityQueue *queue)
{
    Item *next = queue->start;
    int size = 0;

    while (next != NULL)
    {
        size++;
        next = next->next;
    }

    return size;
}
void printQueue(PriorityQueue *queue)
{
    Item *next = queue->start;

    printf("\nQueue\n");

    while (next != NULL)
    {
        printf("%i ", next->key);
        next = next->next;
    }

    printf("\n");
}

bool insert(PriorityQueue *queue, int key)
{
    Item *new_item = (Item *)malloc(sizeof(Item));
    new_item->key = key;
    new_item->next = NULL;

    if (queue->start == NULL)
    {
        queue->start = new_item;
    }
    else
    {
        Item *next = queue->start;
        Item *previous = NULL;
        while (next != NULL)
        {
            if (next->key > new_item->key)
            {
                break;
            }
            previous = next;
            next = next->next;
        }

        if (previous == NULL)
        {
            new_item->next = queue->start;
            queue->start = new_item;
        }
        else
        {
            previous->next = new_item;
            new_item->next = next;
        }
    }

    return true;
}

bool removeMin(PriorityQueue *queue, int *key)
{
    if (queue->start == NULL)
    {
        return false;
    }

    Item *aux = queue->start;
    *key = aux->key;
    queue->start = aux->next;

    free(aux);

    return true;
}

int main()
{

    PriorityQueue queue;
    startQueue(&queue);

    for (int i = 0; i < MAX; i++)
    {
        insert(&queue, i + 1);
    }

    printQueue(&queue);

    printf("Queue size => %i \n", queueSize(&queue));

    for (int i = 0; i < MAX / 2; i++)
    {
        int item;
        removeMin(&queue, &item);
        printf("%i ", item);
    }

    printQueue(&queue);

    restartQueue(&queue);

    return 0;
}
