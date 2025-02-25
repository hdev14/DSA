#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int findRootIdx(int *idxs, int idx)
{
    while (idx != idxs[idx])
    {
        idxs[idx] = idxs[idxs[idx]]; // path compression
        idx = idxs[idx];
    }
    return idx;
}

void connect(int *idxs, int start_idx, int last_idx)
{
    int root_start_idx = findRootIdx(idxs, start_idx);
    int root_last_idx = findRootIdx(idxs, last_idx);
    idxs[root_start_idx] = root_last_idx;
}

bool isConnected(int *idxs, int start_idx, int last_idx)
{
    return findRootIdx(idxs, start_idx) == findRootIdx(idxs, last_idx);
}

int main()
{

    int idxs[MAX];

    for (int i = 0; i < MAX; i++)
    {
        idxs[i] = i;
    }

    connect(idxs, 0, 1);
    connect(idxs, 2, 3);
    connect(idxs, 3, 4);
    connect(idxs, 2, 3);
    connect(idxs, 0, 5);
    connect(idxs, 7, 6);
    connect(idxs, 9, 1);

    printf(isConnected(idxs, 9, 7) ? "True\n" : "False\n");
    printf(isConnected(idxs, 0, 9) ? "True\n" : "False\n");

    return 0;
}
