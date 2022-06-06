#include <iostream>

template <class T>
void exchange(T *summable, int i, int j)
{
    T buffer;
    buffer = summable[i];
    summable[i] = summable[j];
    summable[j] = buffer;
}

template <class T>
int partition(T *summable, int left, int right)
{
    int i = left, j = right + 1;
    while (true)
    {
        while (summable[++i] < summable[left])
            if (i == right)
                break;
        while (summable[--j] > summable[left])
            if (j == left)
                break;

        if (i >= j)
            break;

        exchange(summable, i, j);
    }
    exchange(summable, left, j);
    return j;
}

template <class T>
void quickSort(T *summable, int left, int right, int size)
{
    if (left < 0 || right >= size)
    {
        std::cout << "Numero de arrays no permitido.\n";
        return;
    }
    if (left >= right)
        return;

    int partitionEl = partition(summable, left, right);
    quickSort(summable, left, partitionEl - 1, size);
    quickSort(summable, partitionEl + 1, right, size);
}

int main()
{
    int array1[10] = {7, 32, -11, 0, -29, -50, 38, 9, 28, -20};
    quickSort(array1, 0, 9, 10);
    for (int i = 0; i < 10; i++)
        std::cout << array1[i] << " ";
    return 0;
}