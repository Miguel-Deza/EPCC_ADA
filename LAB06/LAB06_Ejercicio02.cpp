#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "vector"
#include <time.h>
using namespace std;

const int npos = -1;

void randomvector(vector<int> &v, int size);
void printvector(vector<int> &v);

void quickSort(vector<int> &v, int start = 0, int stop = npos);
vector<int> copyOfvector(vector<int> &v, int index, int size);

int main()
{

    cout << "Tamano del arreglo" << endl;
    int size;
    scanf("%d", &size);
    vector<int> v;
    randomvector(v, size);
    cout << "Imprimiendo el arreglo original " << endl;
    printvector(v);
    cout << endl;
    vector<int> c;
    clock_t t;

    c = v;
    t = clock();
    quickSort(c);
    t = clock() - t;
    printf("Usando quick sort lo ordena en: %f segundos.\n", ((float)t) / CLOCKS_PER_SEC);

    cout << endl
         << "Este es el arreglo ordenado:" << endl;
    printvector(c);

    return (0);
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

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

int partition(vector<int> &v, int start, int stop)
{
    int lh = start + 1, rh = stop;
    int pivot = v[start];
    while (true)
    {
        while (lh < rh && v[rh] >= pivot)
            rh--;
        while (lh < rh && v[lh] < pivot)
            lh++;
        if (lh == rh)
            break;
        swap(v[lh], v[rh]);
    }
    if (v[lh] >= pivot)
        return (start);
    swap(v[lh], v[start]);
    return (lh);
}

/*
 * En el caso de una matriz ya ordenada, este algoritmo producirá n divisiones de
 * la matriz, ya que cada pivote estará en el lugar correcto y no hay un lado derecho para ordenar
 * entonces producirá:
 * O = (n-1) * n
 */

void quickSort(vector<int> &v, int start, int stop)
{
    if (stop == npos)
        stop = v.size() - 1;
    if (start < stop)
    {
        int pivot = partition(v, start, stop);
        quickSort(v, start, pivot);
        quickSort(v, pivot + 1, stop);
    }
}