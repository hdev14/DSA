#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 50
typedef int Key;

typedef struct
{
  Key key;
} Item;

typedef struct
{
  Item items[MAX];
  int size;
} List;

void startList(List *list)
{
  list->size = 0;
}

void restartList(List *list)
{
  startList(list);
}

void printList(List *list)
{
  printf("List \n");

  for (int i = 0; i < list->size; i++)
  {
    printf("%i \n", list->items[i].key);
  }

  printf("\n");
}

int linearSearch(List *list, Key key)
{
  for (int i = 0; i < list->size; i++)
  {
    if (list->items[i].key == key)
    {
      return i;
    }
  }

  return -1;
}

bool insertItem(List *list, Item item, int idx)
{
  if (list->size == MAX || idx < 1 || idx > MAX)
  {
    return false;
  }

  for (int i = list->size - 1; i >= idx; i--)
  {
    list->items[i] = list->items[i - 1];
  }

  list->items[idx - 1] = item;
  list->size++;

  return true;
}

bool removeItem(List *list, Key key)
{
  int idx = linearSearch(list, key);

  if (idx == -1)
  {
    return false;
  }

  for (int i = idx; i < list->size - 1; i++)
  {
    list->items[i] = list->items[i + 1];
  }

  list->size--;

  return true;
}

int main()
{
  List list;

  startList(&list);

  for (int i = 0; i < MAX; i++)
  {
    Item item;
    item.key = i + 1;
    insertItem(&list, item, i + 1);
  }

  printList(&list);

  printf("Item -> %i \n", linearSearch(&list, 40));

  printf("Item -> %i \n", linearSearch(&list, 100));

  removeItem(&list, 40);

  printList(&list);

  return 0;
}