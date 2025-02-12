#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct
{
    int items[MAX];
    int start_idx;
    int size;
} Queue;

void startQueue(Queue *queue)
{
    queue->size = 0;
    queue->start_idx = 0;
}

void restartQueue(Queue *queue)
{
    startQueue(queue);
}

void printQueue(Queue *queue)
{
    int idx = queue->start_idx;

    printf("Queue\n");

    for (int i = 0; i < queue->size; i++)
    {
        printf("%i ", queue->items[idx]);
        idx = (idx + 1) % MAX;
    }

    printf("\n");
}

bool insertItem(Queue *queue, int item)
{
    if (queue->size >= MAX)
    {
        return false;
    }

    int idx = (queue->start_idx + queue->size) % MAX;
    queue->items[idx] = item;
    queue->size++;
    return false;
}

bool removeItem(Queue *queue, int *item)
{
    if (queue->size == 0)
    {
        return false;
    }

    *item = queue->items[queue->start_idx];
    queue->items[queue->start_idx] = NULL;
    queue->start_idx = (queue->start_idx + 1) % MAX;
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

    printf("Queue size => %i \n", queue.size);

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
