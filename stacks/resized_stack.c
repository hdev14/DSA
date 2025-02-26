#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct Stack
{
    int *items;
    int size;
} Stack;

void startStack(Stack *stack)
{
    stack->items = NULL;
    stack->size = 0;
}

void resize(Stack *stack, int new_length)
{
    int *new_items = (int *)malloc(sizeof(int) * new_length);
    for (int i = 0; i < stack->size; i++)
    {
        new_items[i] = stack->items[i];
    }

    stack->items = new_items;
}

bool push(Stack *stack, int new_item)
{
    int length = sizeof(stack->items) / sizeof(int);
    if (stack->items == NULL || stack->size == length)
    {
        int new_length = stack->items == NULL ? 1 : 2 * length;
        resize(stack, new_length);
    }
    stack->items[stack->size] = new_item;
    stack->size++;
    return true;
}

int pop(Stack *stack)
{
    if (stack->size == 0)
    {
        return -1;
    }

    int item = stack->items[--stack->size];

    return item;
}

void printStack(Stack *stack)
{
    printf("Stack: \n");

    for (int i = 0; i < stack->size; i++)
    {
        printf("%i ", stack->items[i]);
    }

    printf("\n");
}

int main()
{
    Stack stack;
    startStack(&stack);
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 2);
    printStack(&stack);
    printf("Removed item %i\n", pop(&stack));
    printf("Removed item %i\n", pop(&stack));
    printStack(&stack);
    return 0;
}
