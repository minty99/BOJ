#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int G[101][101];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n, x, y, m;
    scanf("%d %d %d %d", &n, &x, &y, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            G[i][j] = 987654321;

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][k] + G[k][j], G[i][j]);

    if(G[x][y] == 987654321) G[x][y] = -1;
    printf("%d", G[x][y]);
}
