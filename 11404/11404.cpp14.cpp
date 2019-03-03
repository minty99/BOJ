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

int n, m;
int cost[101][101];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cost[i][j] = i == j ? 0 : 1e9+7;

    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = min(cost[a][b], c);
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(cost[i][j] >= 1e9+7) cost[i][j] = 0;
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}
