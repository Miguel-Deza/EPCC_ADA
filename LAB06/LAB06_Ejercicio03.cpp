#include <iostream>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define SIZE 100000

class STACK
{
private:
    int num[SIZE];
    int top;

public:
    STACK();
    int push(int);
    int isFull();
};

STACK::STACK()
{
    top = -1;
}

int STACK::isFull()
{
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

int STACK::push(int n)
{

    if (isFull())
    {
        return 0;
    }
    ++top;
    num[top] = n;
    return n;
}

template <class a>
void randomNumbers(a data[], int size)
{
    for (int i = 0; i < size; i++)

    {

        data[i] = (rand() % 1000);
    }
}

template <class a>
void print(a data[], long size)
{

    for (long i = 0; i < size; i++)
    {
        cout << data[i] << ",";
    }
    cout << "" << endl;
}

template <class Tmp>
void partition3(Tmp data[], long l, long r, long &i, long &j)
{
    i = l - 1, j = r;
    long p = l - 1, q = r;
    Tmp v = data[r];

    while (true)
    {
        while (data[++i] < v)
            ;
        while (v < data[--j])
            if (j == l)
                break;

        if (i >= j)
            break;

        swap(data[i], data[j]);

        if (data[i] == v)
        {
            p++;
            swap(data[p], data[i]);
        }

        if (data[j] == v)
        {
            q--;
            swap(data[j], data[q]);
        }
    }
    swap(data[i], data[r]);
    j = i - 1;
    for (long k = l; k < p; k++, j--)
        swap(data[k], data[j]);
    i = i + 1;
    for (long k = r - 1; k > q; k--, i++)
        swap(data[i], data[k]);
}

template <class Tmp>
void quicksort3(Tmp data[], long l, long r)
{
    if (r <= l)
        return;

    long i, j;
    partition3(data, l, r, i, j);
    quicksort3(data, l, j);
    quicksort3(data, i, r);
}

int main()
{
    long size;
    cout << "EScribe el tamano del arreglo" << endl;
    cin >> size;
    long data[size];
    srand((unsigned)time(0));
    randomNumbers(data, size);
    int i = 0;

    quicksort3(data, 0, size - 1);
    cout << "Ordenado por algoritmos Quicksort (particionamiento de 3 vías) :" << endl;

    print(data, size);
    STACK stk;

    for (long j = size - 1; j >= 0; j--)
    {
        stk.push(data[j]);
    }
    return 0;
}