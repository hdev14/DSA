
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

void setupValuesAndPrevious(int qty_vertices, int *values, int *previous, int vertice_idx)
{
    for (int i = 0; i < qty_vertices; i++)
    {
        values[i] = __INT_MAX__;
        previous[i] = -1;
    }

    values[vertice_idx] = 0;
}

void relaxation(Graph *graph, int *values, int *previous, int current_vertice_idx, int next_vertice_idx)
{
    Node *node = graph->vertices[current_vertice_idx].head;

    while (node != NULL && node->vertice != next_vertice_idx)
    {
        node = node->next;
    }

    if (node)
    {
        if (values[next_vertice_idx] > values[current_vertice_idx] + node->value)
        {
            values[next_vertice_idx] = values[current_vertice_idx] + node->value;
            previous[next_vertice_idx] = current_vertice_idx;
        }
    }
}

bool existUnvisited(int qty_vertices, bool *visited)
{
    for (int i = 0; i < qty_vertices; i++)
    {
        if (visited[i] == false)
        {
            return true;
        }
    }

    return false;
}

int findSmallest(int qty_vertices, int *values, bool *visited)
{
    int i = 0;
    int smallest = __INT_MAX__;
    int idx = -1;
    while (i < qty_vertices)
    {
        if (visited[i] != true && values[i] < smallest)
        {
            smallest = values[i];
            idx = i;
        }
        i++;
    }

    return idx;
}

int *dijkstra(Graph *graph, int first_vertice_idx)
{
    int *values = (int *)malloc(graph->qty_vertices * sizeof(int));
    int previous[graph->qty_vertices * sizeof(int)];
    bool visited[graph->qty_vertices];
    setupValuesAndPrevious(graph->qty_vertices, values, previous, first_vertice_idx);

    for (int i = 0; i < graph->qty_vertices; i++)
    {
        visited[i] = false;
    }

    while (existUnvisited(graph->qty_vertices, visited))
    {
        int vertice_idx = findSmallest(graph->qty_vertices, values, visited);

        if (vertice_idx == -1)
        {
            continue;
        }

        visited[vertice_idx] = true;
        Node *node = graph->vertices[vertice_idx].head;

        while (node != NULL)
        {
            relaxation(graph, values, previous, vertice_idx, node->vertice);
            node = node->next;
        }
    }

    return values;
}

int main()
{
    Graph *graph = createGraph(3);

    for (int i = 0; i < 3; i++)
    {
        insertEdge(graph, i, (i + 1) % 3, (i + 1) * 2);
    }

    printGraph(graph);

    int *values = dijkstra(graph, 0);

    for (int i = 0; i < graph->qty_vertices; i++)
    {
        printf("D(v0 -> v%i) = %i\n", i, values[i]);
    }

    return 0;
}
