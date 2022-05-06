#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &list)
{
    for (unsigned int i = 1; i < list.size(); i++) {
        int key = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j]; 
            j--;
        }
        list[j + 1] = key;
    }
}

int main(){
	vector<int> v = {85,69,2,4,6,3};
    insertionSort(v); 

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } 
}



