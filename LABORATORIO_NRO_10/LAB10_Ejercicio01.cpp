#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int main(int argc, char **argv){
    int c = stoi(st.nextToken());
    int s = stoi(st.nextToken());
    std::vector<int> arr(c << 1);
    int sum = 0;
    double imbalance = 0;
    for (int i = 0; i < s; i++)
    {
        arr[i] = stoi(st.nextToken());
        sum += arr[i];
    }
    std::vector<int> arr2 = arr->clone();
    sort(arr2.begin(),arr2.end());
    out.append("Set #" + std::to_string(cases++) + "\n");
    double a = sum * 1.0 / c;
    for (int i = 0; i < c; i++)
    {
        int x = arr2[i];
        int y = arr2[2 * c - 1 - i];
        out.append(" " + std::to_string(i) + ":");
        if (x == 0 || y == 0)
        {
            if (x != 0)
            {
                out.append(" " + std::to_string(x));
            }
            if (y != 0)
            {
                out.append(" " + std::to_string(y));
            }
        }
        else 
        {
            out.append(" " + std::to_string(x) + " " + std::to_string(y));
        }
        imbalance += abs((x + y) - a);
        out.append("\n");
    }
    out.append("IMBALANCE = " + f.format(imbalance) + "\n\n");
	return 0;
}