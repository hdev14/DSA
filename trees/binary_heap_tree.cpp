#include <iostream>
#include <vector>

using namespace std;

// k = root || 2k/2 || (2k + 1) / 2
// left leaf = 2k
// right leaf = 2k + 1

void exchange(vector<int> &heap, int first_idx, int second_idx)
{
    int value = heap[first_idx];
    heap[first_idx] = heap[second_idx];
    heap[second_idx] = value;
}

bool isLess(vector<int> &heap, int first_idx, int second_idx)
{
    return heap[first_idx] < heap[second_idx];
}
void swim(vector<int> &heap)
{
    int last_idx = heap.size() - 1;

    while (last_idx > 1 && isLess(heap, last_idx / 2, last_idx))
    {
        exchange(heap, last_idx, last_idx / 2);
        last_idx = last_idx / 2;
    }
}

void sink(vector<int> &heap, int root_idx)
{
    while (root_idx * 2 < heap.size())
    {
        int right_leaf_idx = root_idx * 2;
        int left_leaf_idx = right_leaf_idx + 1;
        int leaf_idx = right_leaf_idx;

        if (right_leaf_idx < heap.size() && isLess(heap, right_leaf_idx, left_leaf_idx))
        {
            leaf_idx = left_leaf_idx;
        }

        if (!isLess(heap, root_idx, right_leaf_idx))
        {
            break;
        }

        exchange(heap, root_idx, leaf_idx);
        root_idx = leaf_idx;
    }
}

void insert(vector<int> &heap, int value)
{
    if (heap.size() == 0)
    {
        heap.push_back(-1);
    }
    heap.push_back(value);
    swim(heap);
}

int removeMax(vector<int> &heap)
{
    if (heap.size() == 1 && heap[0] == -1)
    {
        return NULL;
    }

    int value = heap[1];
    exchange(heap, 1, heap.size() - 1);
    heap.pop_back();
    sink(heap, 1);

    return value;
}

void printTree(vector<int> &heap, int idx)
{
    if (idx >= heap.size())
    {
        return;
    }

    printf(" %i (", heap[idx]);
    printTree(heap, idx * 2);
    printTree(heap, idx * 2 + 1);
    printf(") ");
}

int main()
{
    vector<int> heap;

    insert(heap, 1);
    insert(heap, 3);
    insert(heap, 5);
    insert(heap, 2);
    insert(heap, 7);
    insert(heap, 8);

    printTree(heap, 1);

    removeMax(heap);

    printf("\n");

    printTree(heap, 1);
    return 0;
}
