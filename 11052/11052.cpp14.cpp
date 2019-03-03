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

int n, arr[1001], dp[1001];
int main()
{
    // freopen("in.txt", "r", stdin);
    // dp[i] = i개 붕어빵을 판매할 때의 최적해

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i-j] + arr[j]);
    printf("%d", dp[n]);

}
