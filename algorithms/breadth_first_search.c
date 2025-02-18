
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define UNVISITED 0
#define VISITED 1
#define COMPLETED 2

typedef struct Node
{
    int vertice;
    int value;
    Node *next;
} Node;

typedef struct Vertice
{
    Node *head;
} Vertice;

typedef struct Graph
{
    int qty_vertices;
    int qty_edges;
    Vertice *vertices;
} Graph;

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

Graph *createGraph(int qty_vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->qty_edges = 0;
    graph->qty_vertices = qty_vertices;
    graph->vertices = (Vertice *)malloc(qty_vertices * sizeof(Vertice));

    for (int i = 0; i < qty_vertices; i++)
    {
        graph->vertices[i].head = NULL;
    }

    return graph;
}

Node *createNode(int vertice, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = value;
    new_node->vertice = vertice;
    return new_node;
}

bool insertEdge(Graph *graph, int vertice_idx, int vertice, int value)
{
    if (graph == NULL)
    {
        return false;
    }

    if (vertice_idx < 0 || vertice < 0 || vertice_idx >= graph->qty_vertices || vertice >= graph->qty_vertices)
    {
        return false;
    }

    Node *new_node = createNode(vertice, value);
    new_node->next = graph->vertices[vertice_idx].head;
    graph->vertices[vertice_idx].head = new_node;
    graph->qty_edges++;

    return true;
}

void printGraph(Graph *graph)
{
    if (graph == NULL)
    {
        return;
    }

    printf("Graph as %i vertices and %i edges\n", graph->qty_vertices, graph->qty_edges);

    for (int i = 0; i < graph->qty_vertices; i++)
    {
        Node *next = graph->vertices[i].head;

        printf("Vertice %i has -> ", i);

        while (next != NULL)
        {
            printf("V %i (%i)", next->vertice, next->value);
            next = next->next;
        }
        printf("\n");
    }
}

void exploreVertice(Graph *graph, bool *explored, int vertice_idx)
{
    Queue queue;
    startQueue(&queue);
    explored[vertice_idx] = true;

    insertItem(&queue, vertice_idx);

    while (queue.start != NULL)
    {
        int key;
        removeItem(&queue, &key);
        Node *node = graph->vertices[vertice_idx].head;

        while (node != NULL)
        {
            if (explored[node->vertice] == false)
            {
                explored[node->vertice] = true;
                insertItem(&queue, node->vertice);
            }
            node = node->next;
        }

        printf("Visited key %i\n", key);
    }

    restartQueue(&queue);
}

bool *BFS(Graph *graph)
{
    bool *explored = (bool *)malloc(graph->qty_vertices * sizeof(bool));

    for (int i = 0; i < graph->qty_vertices; i++)
    {
        explored[i] = false;
    }

    for (int i = 0; i < graph->qty_vertices; i++)
    {
        if (explored[i] == false)
        {
            exploreVertice(graph, explored, i);
        }
    }

    return explored;
}

int main()
{
    Graph *graph = createGraph(3);

    for (int i = 0; i < 3; i++)
    {
        insertEdge(graph, i, (i + 1) % 3, i * 2);
    }

    printGraph(graph);

    bool *result = BFS(graph);

    for (int i = 0; i < graph->qty_vertices; i++)
    {
        printf("[%i] ", (int)result[i]);
    }

    return 0;
}
