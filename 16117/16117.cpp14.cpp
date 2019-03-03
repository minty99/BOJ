#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int G[2000][2000], dp[2000][2000];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &G[i][j]);

    for(int i = m; i >= 0; i--)
    {
        for(int j = 1; j <= n; j++)
        {
            int a = G[j][i] + dp[j-1][i+1];
            int b = G[j][i] + dp[j+1][i+1];
            int c = G[j][i] + G[j][i+1] + dp[j][i+2];
            dp[j][i] = max(a, b);
            dp[j][i] = max(dp[j][i], c);
            ans = max(ans, dp[j][i]);
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = 0;

    int real_ans = ans;
    ans = 0;
    for(int i = m; i >= 1; i--)
    {
        for(int j = 1; j <= n+1; j++)
        {
            int a = j-1 >= 0 ? G[j-1][i] + dp[j-1][i+1] : 0;
            int b = G[j][i] + dp[j+1][i+1];
            dp[j][i] = max(a, b);
            ans = max(ans, dp[j][i]);
        }
    }

    printf("%d", max(ans, real_ans));
}
