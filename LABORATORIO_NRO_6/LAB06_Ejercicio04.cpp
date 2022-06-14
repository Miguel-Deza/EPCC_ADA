#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "vector"
#include <time.h>

using namespace std;

template <typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <typename T, typename Compare>
T *middleOfThree(T *a, T *b, T *c, Compare comp)
{
    if (comp(*a, *b))
    {
        if (comp(*b, *c))
            return b;
        else if (comp(*a, *c))
            return c;
        else
            return a;
    }
    else
    {
        if (comp(*a, *c))
            return a;
        else if (comp(*b, *c))
            return c;
        else
            return b;
    }
}

template <typename T, typename Compare>
T *partition(T *i, T *j, T *medianPointer, Compare comp)
{
    T medianValue = *medianPointer;
    T *pivot;

    i--;
    j++;

    while (1)
    {
        do
            i++;
        while (comp(*i, medianValue));

        do
            j--;
        while (comp(medianValue, *j));

        if (i >= j)
            return j;

        swap(i, j);
    }
}

template <typename T, typename Compare>
void insertion_sort(T *first, T *last, Compare comp)
{
    int size = last - first;

    for (int i = 1; i < size; i++)
    {
        T key = *(first + i);
        T *j = (first + (i - 1));

        while (comp(key, *j) && j - first >= 0)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

template <typename T, typename Compare>
void quicksort_with_insertion_sort(T *first, T *last, Compare comp)
{
    while (first < last - 1)
    {
        int size = last - first;
        if (size < 56)
        {
            insertion_sort(first, last, comp);
            break;
        }
        else
        {
            int middleElementPointer = (size - 1) / 2;
            T *medianPointer = middleOfThree(first, first + middleElementPointer, last - 1, comp);
            T medianValue = *(medianPointer);

            T *i = first;
            T *j = last - 1;

            T *pivot = partition(i, j, medianPointer, comp);

            if (pivot - first < last - 1 - pivot)
            {
                quicksort_with_insertion_sort(first, pivot + 1, comp);
                first = pivot + 1;
            }
            else
            {
                quicksort_with_insertion_sort(pivot + 1, last, comp);
                last = pivot + 1;
            }
        }
    }
}

void fill_array_with_random_values(int *first, int *last)
{
    for (int i = 0; i < last - first; i++)
    {
        *(first + i) = rand() % 1000;
    }
}

void randomvector(vector<int> &v, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        v.push_back(rand() % 1000 + 1);
    }
}

void printvector(vector<int> &v)
{
    for (unsigned i = 0; i < v.size(); i++)
        printf("%5d", v[i]);
    cout << endl;
}

int main()
{
    // cout << "Tamano del arreglo" << endl;
    // int size;
    // scanf("%d", &size);
    // vector<int> v;
    // randomvector(v, size);
    // cout << "Imprimiendo el arreglo original " << endl;
    // printvector(v);
    // cout << endl;
    // vector<int> c;
    // clock_t t;

    int array[8] = {3, 7, 8, 2, 5, 6, 1, 9};
    quicksort_with_insertion_sort(array, array + 8, [](int a, int b)
                                  { return a > b; });
    for (int i = 0; i < 8; i++)
    {
        cout << array[i] << " ";
    }

    // c = v;
    // t = clock();

    // t = clock() - t;
    // printf("Usando la combinacion de quick sort con insertion sort se realiza en: %f segundos.\n", ((float)t) / CLOCKS_PER_SEC);

    // cout << endl
    //      << "Este es el arreglo ordenado:" << endl;
    // printvector(c);

    return 0;
}