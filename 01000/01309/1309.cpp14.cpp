#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int n;
int dp[100001][2];  // [0]: 마지막 줄에 사자가 있는 경우, [1]: 마지막 줄에 사자가 없는 경우
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    dp[0][0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] * 2;
        dp[i][0] %= 9901;
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] %= 9901;
    }

    printf("%d", (dp[n][0] + dp[n][1]) % 9901);
}
