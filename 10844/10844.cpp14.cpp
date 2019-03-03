#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long lli;

long long dp[101][10];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= 9; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
        for(int j = 1; j <= 8; j++) { dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]; dp[i][j] %= 1000000000; }
    }

    long long answer = 0;
    for(int i = 0; i <= 9; i++) { answer += dp[n][i]; answer %= 1000000000; }
    printf("%lld", answer);
}
