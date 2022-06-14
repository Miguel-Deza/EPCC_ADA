#include <bits/stdc++.h>
using namespace std;

int printAllSubsetsRec(int arr[],
                       int n,
                       vector<int> v,
                       int sum)
{
    if (sum == 0)
    {
        return (int)v.size();
    }

    if (sum < 0)
        return INT_MAX;

    if (n == 0)
        return INT_MAX;

    int x = printAllSubsetsRec(
        arr,
        n - 1, v, sum);

    v.push_back(arr[n - 1]);
    int y = printAllSubsetsRec(
        arr, n, v,
        sum - arr[n - 1]);
    return min(x, y);
}

int printAllSubsets(int arr[],
                    int n, int sum)
{
    vector<int> v;
    return printAllSubsetsRec(arr, n,
                              v, sum);
}

int main()
{
    int arr[] = {1, 2, 5, 7, 11, 13};
    int sum = 1360;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << printAllSubsets(arr, n, sum)
         << endl;
    return 0;
}