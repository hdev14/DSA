#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX 50

typedef int Key;

typedef struct Item
{
    Key key;
    struct Item *next;
} Item;

typedef struct
{
    Item *top;
} Stack;

void startStack(Stack *stack)
{
    stack->top = NULL;
}

void restartStack(Stack *stack)
{
    Item *next = stack->top;

    while (next != NULL)
    {
        Item *aux = next;
        next = next->next;
        free(aux);
    }

    stack->top = NULL;
}

int stackSize(Stack *stack)
{
    int size = 0;
    Item *next = stack->top;

    while (next != NULL)
    {
        size++;
        next = next->next;
    }

    return size;
}

bool isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void printStack(Stack *stack)
{
    printf("Stack\n");
    Item *next = stack->top;

    while (next != NULL)
    {
        printf("%i ", next->key);
        next = next->next;
    }

    printf("\n");
}

bool push(Stack *stack, Key key)
{
    Item *new_item = (Item *)malloc(sizeof(Item));
    new_item->key = key;
    new_item->next = stack->top;
    stack->top = new_item;
    return true;
}

bool pop(Stack *stack, Key *key)
{
    if (stack->top == NULL)
    {
        return false;
    }

    *key = stack->top->key;
    Item *aux = stack->top;
    stack->top = stack->top->next;
    free(aux);
    return true;
}

int main()
{
    Stack stack;
    startStack(&stack);

    for (int i = 0; i < MAX; i++)
    {
        push(&stack, i + 1);
    }

    printStack(&stack);

    printf("Stack size => %i \n", stackSize(&stack));

    for (int i = 0; i < MAX / 2; i++)
    {
        Key key;
        pop(&stack, &key);
        printf("%i ", key);
    }

    restartStack(&stack);

    if (isEmpty(&stack))
    {
        printf("\nStack empty!!\n");
    }

    return 0;
}
