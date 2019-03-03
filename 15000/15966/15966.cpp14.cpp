#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        dp[k] = max(dp[k], dp[k-1] + 1);
        ans = max(ans, dp[k]);
    }
    printf("%d", ans);
}
