#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int Key;

typedef struct
{
    Key key;
} Item;

typedef struct
{
    Item items[MAX];
    int top;
} Stack;

void startStack(Stack *stack)
{
    stack->top = -1;
}

void restartStack(Stack *stack)
{
    startStack(stack);
}

int stackSize(Stack *stack)
{
    return stack->top + 1;
}

void printStack(Stack *stack)
{
    printf("Stack\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%i ", stack->items[i].key);
    }
    printf("\n");
}

bool push(Stack *stack, Key key)
{
    if (stack->top == MAX - 1)
    {
        return false;
    }

    stack->top++;
    stack->items[stack->top].key = key;

    return true;
}

bool pop(Stack *stack, Item *item)
{
    if (stack->top == -1)
    {
        return false;
    }

    *item = stack->items[stack->top];
    stack->top--;

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
        Item item;
        pop(&stack, &item);
        printf("%i ", item.key);
    }

    restartStack(&stack);

    return 0;
}
