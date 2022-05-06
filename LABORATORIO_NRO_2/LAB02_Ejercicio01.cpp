#include <iostream>

using namespace std;

void print(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
}

void merge(int A[], int low, int mid, int high) {
    int n1 = mid - low + 1; 
    int n2 = high - mid;    

    int i, j, k;

    int* L = new int[n1];
    int* R = new int[n2];   

    for (i = 0; i < n1; i++) {
        L[i] = A[low + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
    }

    i = 0;
    j = 0;

    for (k = low; i < n1 && j < n2; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }

    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int q = (low + high) / 2;
        mergeSort(A, low, q);
        mergeSort(A, q + 1, high);
        merge(A, low, q, high);
    }
}


int main() {
    int *A;
    int size;
    cout<<"Ingrese el tamano del arreglo: ";
    cin >> size;
    A = new int[size];

    for (int i = 0; i < size; i++) {
        cout<<"Ingrese el elemento "<<i+1<<": ";
        cin >> A[i];
    }

    mergeSort(A, 0, size - 1);
    print(A, size);


    delete[] A;
    return 0;
}
