#include <stdio.h>

int dp[15];

void dp_calc(int goal)
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= goal; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
}

int main()
{
    dp_calc(11);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        int goal;
        scanf("%d", &goal);
        printf("%d\n", dp[goal]);
    }
}
