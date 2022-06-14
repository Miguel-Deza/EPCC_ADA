#include <bits/stdc++.h>
using namespace std;

int Count(int S[], int m, int n)
{
    vector<vector<int>> table(
        m + 1,
        vector<int>(
            n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        table[0][i] = INT_MAX - 1;
    }

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (S[i - 1] > j)
            {
                table[i][j] = table[i - 1][j];
            }
            else
            {

                table[i][j] = min(
                    table[i - 1][j],
                    table[i][j - S[i - 1]] + 1);
            }
        }
    }
    return table[m][n];
}

int main()
{
    int arr[] = {1, 2, 5, 7, 11, 13};
    int m = sizeof(arr) / sizeof(arr[0]);
    cout << Count(arr, m, 1360);
    return 0;
}