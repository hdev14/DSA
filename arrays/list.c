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
    printf("%i ", list->items[i].key);
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

int linearSearchWithSentinel(List *list, Key key)
{
  int i = 0;
  list->items[list->size].key = key; // sentinel

  while (list->items[i].key == key)
  {
    i++;
  }

  return i == list->size ? -1 : i;
}

int binarySearch(List *list, Key key)
{
  int left = 0;
  int right = list->size - 1;
  int mid;

  while (left <= right)
  {
    mid = (left + right) / 2;

    if (list->items[mid].key == key)
    {
      return mid;
    }

    if (list->items[mid].key < key)
    {
      left = mid + 1;
      continue;
    }

    if (list->items[mid].key > key)
    {
      right = mid - 1;
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

bool insertItemInOrder(List *list, Item item)
{
  if (list->size >= MAX)
  {
    return false;
  }

  int idx = list->size;

  for (; idx > 0 && list->items[idx - 1].key > item.key; idx--)
  {
    list->items[idx] = list->items[idx - 1];
  }

  list->items[idx] = item;
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

bool removeItemBS(List *list, Key key)
{
  int idx = binarySearch(list, key);

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
  printf("-------------------- List -------------------- \n");

  List unsorted_list;

  startList(&unsorted_list);

  for (int i = 0; i < MAX; i++)
  {
    Item item;
    item.key = i + 1;
    insertItem(&unsorted_list, item, i + 1);
  }

  printList(&unsorted_list);

  printf("Item -> %i \n", linearSearch(&unsorted_list, 40));

  printf("Item -> %i \n", linearSearch(&unsorted_list, 100));

  removeItem(&unsorted_list, 40);

  printList(&unsorted_list);

  // -----------------------

  printf("-------------------- Sorted List -------------------- \n");

  List sorted_list;

  startList(&sorted_list);

  for (int i = MAX; i > 0; i--)
  {
    Item item;
    item.key = i;
    insertItemInOrder(&sorted_list, item);
  }

  printList(&sorted_list);

  printf("Item -> %i \n", binarySearch(&sorted_list, 40));

  printf("Item -> %i \n", binarySearch(&sorted_list, 100));

  removeItemBS(&sorted_list, 40);

  printList(&sorted_list);

  return 0;
}