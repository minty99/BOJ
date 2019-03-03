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

int adj[101][101];
int bacon[101];
int n, m;

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            adj[i][j] = 10000;

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for(int i = 1; i <= n; i++) adj[i][i] = 0;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            bacon[i] += adj[i][j];

    int m = 10000, answer = 0;
    for(int i = 1; i <= n; i++)
        if(bacon[i] < m) { m = bacon[i]; answer = i; }

    printf("%d", answer);
}
