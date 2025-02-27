#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Node
{
    int value;
    Node *next;
} Node;

typedef struct Dequeue
{
    Node *head;
    Node *tail;
    int size;
} Dequeue;

void startDequeue(Dequeue *dequeue)
{
    dequeue->head = NULL;
    dequeue->tail = NULL;
    dequeue->size = 0;
}

Node *createNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

bool isEmpty(Dequeue *dequeue)
{
    return dequeue->head == NULL & dequeue->tail == NULL;
}

bool addFirst(Dequeue *dequeue, int new_value)
{
    Node *node = createNode(new_value);

    if (isEmpty(dequeue))
    {
        dequeue->head = node;
        dequeue->tail = node;
    }
    else
    {
        Node *aux = dequeue->head;
        dequeue->head = node;
        node->next = aux;
    }

    dequeue->size++;
    return true;
}

bool addLast(Dequeue *dequeue, int new_value)
{
    Node *node = createNode(new_value);

    if (isEmpty(dequeue))
    {
        dequeue->head = node;
        dequeue->tail = node;
    }
    else
    {
        Node *aux = dequeue->tail;
        aux->next = node;
        dequeue->tail = node;
    }

    dequeue->size++;

    return true;
}

bool removeFirst(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        return false;
    }

    Node *first = dequeue->head;

    if (first->next == NULL)
    {
        dequeue->head = NULL;
        dequeue->tail = NULL;
    }
    else
    {
        dequeue->head = first->next;
    }

    free(first);
    dequeue->size--;
    return true;
}

Node *findPenult(Dequeue *dequeue)
{
    Node *next = dequeue->head;
    Node *penult = NULL;

    while (next->next != NULL)
    {
        penult = next;
        next = next->next;
    }

    return penult;
}

bool removeLast(Dequeue *dequeue)
{
    if (isEmpty(dequeue))
    {
        return false;
    }

    Node *last = dequeue->tail;
    Node *penult = findPenult(dequeue);

    if (penult == NULL)
    {
        dequeue->head = NULL;
        dequeue->tail = NULL;
    }
    else
    {
        dequeue->tail = penult;
        penult->next = NULL;
    }

    free(last);

    dequeue->size--;

    return true;
}

void printDequeue(Dequeue *dequeue)
{
    Node *next = dequeue->head;
    printf("Dequeue\n");
    while (next != NULL)
    {
        printf("%i ", next->value);
        next = next->next;
    }
    printf("\n");
}

int main()
{
    Dequeue dequeue;
    startDequeue(&dequeue);
    addFirst(&dequeue, 1);
    addFirst(&dequeue, 2);
    addFirst(&dequeue, 3);
    printDequeue(&dequeue);
    removeFirst(&dequeue);
    printDequeue(&dequeue);
    addLast(&dequeue, 5);
    addLast(&dequeue, 6);
    removeLast(&dequeue);
    printDequeue(&dequeue);
    return 0;
}
