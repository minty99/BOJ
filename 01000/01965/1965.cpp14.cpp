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
int arr[1001];
int dp[1001];

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j <= i-1; j++)
        {
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }

    int M = 0;
    for(int i = 1; i <= n; i++) M = max(M, dp[i]);
    printf("%d", M);
}
