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

int data[10001];
int dp[10001][3];
int maxs[10001];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &data[i]);

    if(n == 1) printf("%d", data[1]);
    else if(n == 2) printf("%d", data[1]+data[2]);
    else
    {
        dp[1][1] = data[1];
        maxs[1] = data[1];
        int nowmax = 0;
        for(int i = 2; i <= n; i++)
        {
            if(nowmax < maxs[i-2]) nowmax = maxs[i-2];
            dp[i][1] = nowmax + data[i];
            dp[i][2] = dp[i-1][1] + data[i];
            maxs[i] = max(dp[i][1], dp[i][2]);
            // printf("dp[%d][1] = %d, dp[%d][2] = %d, maxs[%d] = %d\n", i, dp[i][1], i, dp[i][2], i, maxs[i]);
        }

        int answer = 0;
        for(int i = 1; i <= n; i++)
            if(answer < maxs[i]) answer = maxs[i];
        printf("%d", answer);
    }
}
