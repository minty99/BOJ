#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int dp[1001][1001];
int arr[1001][1001];
int n, m;

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &arr[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max(max(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + arr[i][j];
    printf("%d", dp[n][m]);
}
