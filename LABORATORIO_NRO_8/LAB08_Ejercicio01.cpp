#include <cstdio>
#include <cstring>
#include <algorithm>
#include <time.h>

#define maxn 10000
using namespace std;

int w[2], t, d1[maxn], d2[maxn], dt[maxn];
int main()
{
    clock_t t;
    while (scanf("%d%d%d", &w[0], &w[1], &t) != EOF)
    {
        t = clock();
        memset(d1, 0x8f, sizeof(d1));
        memset(dt, 0, sizeof(dt));
        memset(d2, 0, sizeof(d2));

        d1[0] = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = w[i]; j <= t; ++j)
            {
                d1[j] = max(d1[j], d1[j - w[i]] + 1);
                if ((dt[j] < dt[j - w[i]] + w[i]) ||
                    ((dt[j] == dt[j - w[i]] + w[i]) &&
                     (d2[j] < d2[j - w[i]] + 1)))
                {
                    dt[j] = dt[j - w[i]] + w[i];
                    d2[j] = d2[j - w[i]] + 1;
                }
            }
        if (dt[t] == t)
            printf("%d\n", d1[t]);
        else
            printf("%d %d\n", d2[t], t - dt[t]);
        t = clock() - t;
        printf("%f segundos.\n", ((float)t) / CLOCKS_PER_SEC);
    }
    return 0;
}