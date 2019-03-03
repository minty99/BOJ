#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int dp[1010000];

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    printf("%d", dp[n]);
}
