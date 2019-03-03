#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int coin[101];
int dp[10001][101];

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &coin[i]);

    for(int i = 1; i <= 10000; i++)
        for(int j = 0; j <= 100; j++)
            dp[i][j] = 1e9;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++)
        {
            int a = dp[i][j-1];
            int b = (i-coin[j] < 0) ? 1e9 : (dp[i-coin[j]][j] + 1);
            dp[i][j] = min(a, b);
            // printf("dp[%d][%d] = min(%d, %d)\n", i, j, a, b);
        }
    int ans = 1e9;
    for(int i = 1; i <= n; i++) ans = min(dp[k][i], ans);

    if(ans == 1e9) ans = -1;
    printf("%d", ans);
}
