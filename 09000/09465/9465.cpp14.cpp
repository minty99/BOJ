#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))

int t, n, arr[100001][3], dp[100001][3];
int main()
{
    scanf("%d", &t);

    while(t > 0)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i][1]);
        for(int i = 1; i <= n; i++) scanf("%d", &arr[i][2]);

        for(int i = 1; i <= n; i++)
        {
            dp[i][1] = max(max(dp[i-2][1], dp[i-2][2]), dp[i-1][2]) + arr[i][1];
            dp[i][2] = max(max(dp[i-2][1], dp[i-2][2]), dp[i-1][1]) + arr[i][2];
        }

        printf("%d\n", max(dp[n][1], dp[n][2]));
        t--;
    }
}
