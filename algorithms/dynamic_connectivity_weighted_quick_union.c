#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int findRootIdx(int *idxs, int idx)
{
    while (idx != idxs[idx])
    {
        idx = idxs[idx];
    }
    return idx;
}

void connect(int *idxs, int *tree_sizes, int start_idx, int last_idx)
{
    int root_start_idx = findRootIdx(idxs, start_idx);
    int root_last_idx = findRootIdx(idxs, last_idx);
    if (root_start_idx == root_last_idx)
    {
        return;
    }

    if (idxs[root_start_idx] < idxs[root_last_idx])
    {
        idxs[root_start_idx] = root_last_idx;
        tree_sizes[root_last_idx] += tree_sizes[root_start_idx];
    }
    else
    {
        idxs[root_last_idx] = root_start_idx;
        tree_sizes[root_start_idx] += tree_sizes[root_last_idx];
    }
}

bool isConnected(int *idxs, int start_idx, int last_idx)
{
    return findRootIdx(idxs, start_idx) == findRootIdx(idxs, last_idx);
}

int main()
{

    int idxs[MAX], tree_sizes[MAX];

    for (int i = 0; i < MAX; i++)
    {
        idxs[i] = i;
        tree_sizes[i] = 0;
    }

    connect(idxs, tree_sizes, 0, 1);
    connect(idxs, tree_sizes, 2, 3);
    connect(idxs, tree_sizes, 3, 4);
    connect(idxs, tree_sizes, 2, 3);
    connect(idxs, tree_sizes, 0, 5);
    connect(idxs, tree_sizes, 7, 6);
    connect(idxs, tree_sizes, 9, 1);

    printf(isConnected(idxs, 9, 7) ? "True\n" : "False\n");
    printf(isConnected(idxs, 0, 9) ? "True\n" : "False\n");

    return 0;
}
