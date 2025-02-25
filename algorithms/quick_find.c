#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void connect(int *idxs, int start_idx, int last_idx)
{
    int start_value = idxs[start_idx];
    int last_value = idxs[last_idx];
    for (int i = 0; i < MAX; i++)
    {
        if (idxs[i] == start_value)
        {
            idxs[i] = last_value;
        }
    }
}

bool isConnected(int *idxs, int start_idx, int last_idx)
{
    return idxs[start_idx] == idxs[last_idx];
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
