

void exchange(int *array, int first_idx, int second_idx)
{
    int aux = array[second_idx];
    array[second_idx] = array[first_idx];
    array[first_idx] = aux;
}

void shuffle(int *array, int length)
{
    for (int idx = 0; idx < length; idx++)
    {
        int random_idx = 0; // TODO use rand()
        exchange(array, idx, random_idx);
    }
}

int main()
{
    return 0;
}
