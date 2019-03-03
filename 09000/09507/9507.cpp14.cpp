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

lli dp[68];

int main()
{
    // freopen("in.txt", "r", stdin);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 67; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    int t;
    scanf("%d", &t);

    while(t --> 0)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
}
