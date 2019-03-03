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

int dp[1001][10];
int n;

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for(int i = 0; i <= 9; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            for(int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i <= 9; i++)
    {
        sum += dp[n][i];
        sum %= 10007;
    }
    printf("%d", sum);
}
