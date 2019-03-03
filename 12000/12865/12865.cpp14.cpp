#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int dp[110000][110];
vector<pii> item;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        item.emplace_back(a, b);
    }

    sort(item.begin(), item.end());

    // dp[i][j] = 무게 i까지, 물건 j까지를 사용할 때의 답

    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int w = item[j].first;
            int v = item[j].second;
            if(j == 0) dp[i][j] = (w <= i) ? v : 0;
            else if(i - w < 0) dp[i][j] = dp[i][j-1];
            else dp[i][j] = max(dp[i-w][j-1] + v, dp[i][j-1]);
            // printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }

    printf("%d", dp[k][n-1]);
}
