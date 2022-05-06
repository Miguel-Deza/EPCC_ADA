#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int binarySearch(vector<int> toSort, int value, int lower, int higher) {

    int midpoint = 0;

    while (lower <= higher) {
        midpoint = ceil((lower + higher) / 2);
        if (value > toSort[midpoint]) {
            lower = midpoint + 1;
        }
        else {
            higher = midpoint - 1;
        }
        if (higher <= lower) {
            return (value > toSort[lower]) ? (lower + 1) : lower;
        }
    }
}

void insertionSortBinary(vector<int> &toSort) {

    int value;
    int check;
    int location;

    for (size_t i = 1; i < toSort.size(); i++) {
        value = toSort[i];
        check = i - 1;
        location = binarySearch(toSort, value, 0, check);
        while (check >= location) {
            toSort[check + 1] = toSort[check];
            check--;
        }
        toSort[check + 1] = value;
    }
}

int main(){
	vector<int> v = {7,10,1,2,4,6,3};
    insertionSortBinary(v);  
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}



