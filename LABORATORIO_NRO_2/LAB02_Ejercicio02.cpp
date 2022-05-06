#include <iostream>
#include <string>

using namespace std;

const int maxn = 20;
int arr[maxn];

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

void bottomUpSort(int *A, int n){
    int t = 1, s, i;
    while(t < n){
        s = t; t = 2*s; i = -1;
        while(i + t < n){
            merge(A, i+1, i+s, i+t);
            i = i+t;
        }
        if(i+s < n)
            merge(A, i+1, i+s, n-1);
    }

    for (int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
}

int main(){

    cout<<"Ingrese cantidad de numeros a Generar: ";
    int total;
    cin>>total;

    int *preMergedSort = new int[total];
    int *sortedInsertionMergeSort = new int[total];

    
    srand(total);
    for (int i = 0; i < total; i++) {
        preMergedSort[i] = (rand() % 10000) + 1;
    }

    for (int i = 0; i < total; i++) {
        cout<<preMergedSort[i]<<" ";
    }

    cout<<endl<<endl<<"Despues de bottomUpSort"<<endl<<endl<<endl;

    bottomUpSort(preMergedSort, total);

    return 0;
}