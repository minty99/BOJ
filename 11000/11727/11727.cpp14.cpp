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

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int n, dp[1001][2];
int main()
{
    // freopen("in.txt", "r", stdin);
    // dp[i][0] = 2*i 직사각형을 채우는 방법의 수 / 10,007
    // dp[i][1] = 2*i 직사각형을 채우는 방법의 수 중 마지막 것이 1*2 타일인 것의 수
    scanf("%d", &n);

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i-2][0] * 3 + dp[i-1][0] - dp[i-1][1];
        dp[i][1] = dp[i-2][0] + (dp[i-1][0] - dp[i-1][1]);
        dp[i][0] %= 10007;
        dp[i][1] %= 10007;
        // printf("dp[%d][0] = %d, dp[%d][1] = %d\n", i, dp[i][0], i, dp[i][1]);
    }

    printf("%d", dp[n][0]);

}
