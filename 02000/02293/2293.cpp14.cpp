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

int dpnow[10001], dplast[10001];
int coins[101];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) scanf("%d", &coins[i]);
    sort(coins+1, coins+n+1);

    dplast[0] = 1;
    for(int j = 1; j <= n; j++)
    {
        for(int i = 0; i <= k; i++)
        {
            dpnow[i] = dplast[i];
            if(i - coins[j] >= 0) dpnow[i] += dpnow[i - coins[j]];
            // printf("dpnow[%d] = %d\n", i, dpnow[i]);
        }
        for(int i = 1; i <= k; i++) { dplast[i] = dpnow[i]; dpnow[i] = 0; }
    }
    printf("%d", dplast[k]);
}