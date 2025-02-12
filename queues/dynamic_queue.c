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
    Item *end;
} Queue;

void startQueue(Queue *queue)
{
    queue->start = NULL;
    queue->end = NULL;
}

void restartQueue(Queue *queue)
{
    Item *end = queue->start;

    while (end != NULL)
    {
        Item *aux = end;
        end = end->next;
        free(aux);
    }

    queue->start = NULL;
    queue->end = NULL;
}

int queueSize(Queue *queue)
{
    Item *end = queue->start;
    int size = 0;

    while (end != NULL)
    {
        size++;
        end = end->next;
    }

    return size;
}
void printQueue(Queue *queue)
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

bool insertItem(Queue *queue, int key)
{
    Item *new_item = (Item *)malloc(sizeof(Item));
    new_item->key = key;
    new_item->next = NULL;

    if (queue->start == NULL)
    {
        queue->start = new_item;
        queue->end = new_item;
    }
    else
    {
        queue->end->next = new_item;
        queue->end = new_item;
    }

    return true;
}

bool removeItem(Queue *queue, int *key)
{
    if (queue->start == NULL)
    {
        return false;
    }

    *key = queue->start->key;
    Item *aux = queue->start;
    queue->start = aux->next;

    if (queue->start == NULL)
    {
        queue->end = NULL;
    }

    free(aux);

    return true;
}

int main()
{

    Queue queue;
    startQueue(&queue);

    for (int i = 0; i < MAX; i++)
    {
        insertItem(&queue, i + 1);
    }

    printQueue(&queue);

    printf("Queue size => %i \n", queueSize(&queue));

    for (int i = 0; i < MAX / 2; i++)
    {
        int item;
        removeItem(&queue, &item);
        printf("%i ", item);
    }

    printQueue(&queue);

    restartQueue(&queue);

    return 0;
}
