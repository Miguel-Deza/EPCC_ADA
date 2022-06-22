#include <stdio.h>
#include <string.h>
#include <time.h>

int m, n, t, dp[10005], i;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    clock_t t;
    while (~scanf("%d%d%d", &m, &n, &t))
    {
        t = clock();
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (i = m; i <= t; i++)
        {
            if (dp[i - m] != -1)
                dp[i] = max(dp[i - m] + 1, dp[i]);
        }
        for (i = n; i <= t; i++)
        {
            if (dp[i - n] != -1)
                dp[i] = max(dp[i - n] + 1, dp[i]);
        }
        if (dp[t] != -1)
            printf("%d", dp[t]);
        else
        {
            for (i = t; i >= 0; i--)
                if (dp[i] != -1)
                {
                    printf("%d %d", dp[i], t - i);
                    break;
                }
        }
        printf("\n");
        t = clock() - t;
        printf("%f segundos.\n", ((float)t) / CLOCKS_PER_SEC);
    }
    return 0;
}
