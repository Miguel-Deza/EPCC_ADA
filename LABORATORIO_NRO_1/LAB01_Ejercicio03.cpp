#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <chrono>
using namespace std;

vector<int> insertionSort(vector<int> toSort);
vector<int> insertionSortBinary(vector<int> toSort);
int binarySearch(vector<int> toSort, int value, int lower, int higher);

int main() {
    
    for(int k = 1, n=1000; k <= 100; k++, n+=1000){

        int total = n;
        
        vector<int> preSortArray;
        vector<int> sortedInsertion;
        vector<int> sortedBinary;

        srand(total);
        preSortArray.resize(total);
        sortedInsertion.resize(total);
        sortedBinary.resize(total);
        for (int i = 0; i < total; i++) {
            preSortArray[i] = (rand() % 100000) + 1;
        }

        auto beginInsertion = chrono::high_resolution_clock::now();
        sortedInsertion = insertionSort(preSortArray);
        auto endInsertion = chrono::high_resolution_clock::now();
        auto insertionElapsed = chrono::duration_cast<chrono::microseconds>(endInsertion - beginInsertion);


        auto beginBinary = chrono::high_resolution_clock::now();
        sortedBinary = insertionSortBinary(preSortArray);
        auto endBinary = chrono::high_resolution_clock::now();
        auto binaryElapsed = chrono::duration_cast<chrono::microseconds>(endBinary - beginBinary);

        cout << "Iteracion Numero " << k << " con " << total << " elementos" << endl;
        cout << "Insertion Sort: " + to_string(insertionElapsed.count()) + " microsegundos."<< endl;
        cout << "Insertion Sort BB: " + to_string(binaryElapsed.count()) + " microsegundos " << endl;
        cout << endl;

        sortedInsertion.clear();
        sortedBinary.clear();
        preSortArray.clear();

    }

    return 0;
}


vector<int> insertionSort(vector<int> toSort) {

    int value;
    int check;

    for (size_t i = 1; i < toSort.size(); i++) {
        value = toSort[i];
        check = i - 1;

        while ((check >= 0) && toSort[check] > value) {
            toSort[check + 1] = toSort[check];
            check--;
        }
        toSort[check + 1] = value;
    }

    return toSort;
}


vector<int> insertionSortBinary(vector<int> toSort) {

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

    return toSort;
}

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
