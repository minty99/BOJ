#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

lli dp[31];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    if(n % 2 == 1) printf("0");
    else
    {
        dp[0] = 1;
        lli sum = 1;
        for(int i = 2; i <= n; i += 2)
        {
            dp[i] = dp[i-2] + 2 * sum;
            sum += dp[i];
        }
        printf("%lld", dp[n]);
    }
}
