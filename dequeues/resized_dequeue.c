// TODO: finish implementation
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct
{
    int *items;
    int start_idx;
    int end_idx;
    int size;
} Dequeue;

void startdequeue(Dequeue *dequeue)
{
    dequeue->items = NULL;
    dequeue->size = 0;
    dequeue->start_idx = 0;
    dequeue->end_idx = 0;
}

bool isEmpty(Dequeue *dequeue)
{
    return dequeue->items == NULL;
}

int getLength(Dequeue *dequeue)
{
    return sizeof(dequeue->items) / sizeof(int);
}

void printDequeue(Dequeue *dequeue)
{
    int idx = dequeue->start_idx;
    int length = getLength(dequeue);

    printf("dequeue\n");

    for (int i = 0; i < dequeue->size; i++)
    {
        printf("%i ", dequeue->items[idx]);
        idx = (idx + 1) % length;
    }

    printf("\n");
}

void resize(Dequeue *dequeue, int length)
{
    int new_length = length == 0 ? 1 : 2 * length;
    int *new_items = (int *)malloc(sizeof(int) * new_length);

    if (dequeue->size > 0)
    {
        for (int i = 0; i < length; i++)
        {
            new_items[i] = dequeue->items[i];
        }
    }

    dequeue->items = new_items;
}

bool insertItem(Dequeue *dequeue, int item)
{
    int length = isEmpty(dequeue) ? 0 : getLength(dequeue);

    if (dequeue->size == length)
    {
        resize(dequeue, length);
        length = getLength(dequeue);
    }

    int idx = (dequeue->start_idx + dequeue->size) % length;
    dequeue->items[idx] = item;
    dequeue->size++;
    return false;
}

bool removeItem(Dequeue *dequeue, int *item)
{
    if (dequeue->size == 0)
    {
        return false;
    }

    *item = dequeue->items[dequeue->start_idx];
    dequeue->items[dequeue->start_idx] = NULL;
    dequeue->start_idx = (dequeue->start_idx + 1) % getLength(dequeue);
    return true;
}

int main()
{

    Dequeue dequeue;
    startdequeue(&dequeue);

    for (int i = 0; i < 5; i++)
    {
        insertItem(&dequeue, i + 1);
    }

    printDequeue(&dequeue);

    printf("dequeue size => %i \n", dequeue.size);

    for (int i = 0; i < 5 / 2; i++)
    {
        int item;
        removeItem(&dequeue, &item);
        printf("%i ", item);
    }

    printDequeue(&dequeue);

    return 0;
}
