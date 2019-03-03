#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, arr[501][501], dp[501][501];

void DP()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++) scanf("%d", &arr[i][j]);
    DP();
    int M = 0;
    for(int i = 1; i <= n; i++)
        if(M < dp[n][i]) M = dp[n][i];
    printf("%d\n", M);
}
