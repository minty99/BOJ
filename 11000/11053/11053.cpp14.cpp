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

int dp[1001];
int data[1001];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &data[i]);
    for(int i = 1; i <= n; i++)
    {
        int M = 0;
        for(int j = 1; j <= i-1; j++)
        {
            if(dp[j] > M && data[j] < data[i]) M = dp[j];
        }
        dp[i] = M + 1;
    }

    int M = 0;
    for(int i = 1; i <= n; i++)
        if(M < dp[i]) M = dp[i];
    printf("%d", M);
}
