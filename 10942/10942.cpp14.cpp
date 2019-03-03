#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int arr[2010];
int dp[2010][2010];

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    // Process
    for(int i = 1; i <= n; i++)
    {
        int l, r;
        for(l = i, r = i; l >= 1 && r <= n; l--, r++)
        {
            if(l == r) dp[l][r] = 1;
            else dp[l][r] = (arr[l] == arr[r]) ? dp[l+1][r-1] : 0;
        }

        if(i+1 <= n && arr[i] == arr[i+1]) dp[i][i+1] = 1;
        for(l = i-1, r = i+2; l >= 1 && r <= n; l--, r++)
            dp[l][r] = (arr[l] == arr[r]) ? dp[l+1][r-1] : 0;
    }

    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
}
