#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

int memo[600][600];
int arr[600];
int ss[600][600];
int p[600][600];
// dp[i][j]: i~j를 합쳤을 때의 답
// dp[i][j] = min(dp[i][i] + dp[i+1][j], dp[i][i+1] + dp[i+2][j], ...)

int dp(int i, int j)
{
    if(memo[i][j] != 0) return memo[i][j];
    if(i == j) return 0;
    if(j - i == 1) return memo[i][j] = arr[i] + arr[j];
    int ans = 2e9;
    int s = p[i][j-1], e = p[i+1][j];
    if(s == 0) s = i;
    if(e == 0) e = j-1;
    for(int a = s; a <= e; a++)
    {
        int t = dp(i, a) + dp(a+1, j) + ss[i][j];
        if(t < ans)
        {
            p[i][j] = a;
            ans = t;
        }
    }
    return memo[i][j] = ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while(t --> 0)
    {
        int k;
        scanf("%d", &k);
        for(int i = 1; i <= k; i++) scanf("%d", &arr[i]);
        memset(memo, 0, sizeof(memo));
        memset(ss, 0, sizeof(ss));
        memset(p, 0, sizeof(p));
        for(int i = 1; i <= k; i++)
            for(int j = i; j <= k; j++)
                ss[i][j] = ss[i][j-1] + arr[j];
        printf("%d\n", dp(1, k));
    }
}
