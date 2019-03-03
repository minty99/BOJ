#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int arr[1001][4];    // 0 unused
int dp[1001][4];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);
        
    for(int i = 1; i <= n; i++)
    {
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + arr[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + arr[i][2];
        dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + arr[i][3];
    }

    printf("%d\n", min(dp[n][1], min(dp[n][2], dp[n][3])));
}
