#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
long long dp[100];

int main()
{
    int n;
    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

    printf("%lld", dp[n]);
}
