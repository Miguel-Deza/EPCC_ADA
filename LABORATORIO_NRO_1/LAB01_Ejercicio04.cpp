#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <math.h>

using namespace std;

vector<int> bubbleSort(vector<int> toSort);

int main() {

    for(int k = 1, n=1000; k <= 100; k++, n+=1000){

        int total = n;

        vector<int> preSortArray;
        vector<int> sortedBubble;

        srand(total);
        preSortArray.resize(total);
        sortedBubble.resize(total);
        for (int i = 0; i < total; i++) {
            preSortArray[i] = (rand() % 100000) + 1;
        }

        auto beginInsertion = chrono::high_resolution_clock::now();
        sortedBubble = bubbleSort(preSortArray);
        auto endInsertion = chrono::high_resolution_clock::now();
        auto insertionElapsed = chrono::duration_cast<chrono::microseconds>(endInsertion - beginInsertion);

        cout << "Iteracion Numero " << k << " con " << total << " elementos" << endl;
        cout << "Bubble Sort: " + to_string(insertionElapsed.count()) + " microsegundos."<< endl;
        cout << endl;

        sortedBubble.clear();
        preSortArray.clear();
    }
    return 0;
}


vector<int> bubbleSort(vector<int> toSort){ 
    for(int i=0; i<toSort.size(); i++){
        for(int j=0; j<toSort.size() - 1; j++){
            if(toSort[j] >= toSort[j+1]){
                int temp = toSort[j+1];
                toSort[j+1] = toSort[j];
                toSort[j] = temp;
            }
        }
    }
    return toSort;
}