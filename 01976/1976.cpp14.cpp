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

int G[201][201];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &G[i][j]);
            if(i == j) G[i][j] = 0;
            else if(G[i][j] == 0) G[i][j] = 1e7;
        }
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

    int a1, a2;
    scanf("%d", &a1);
    for(int i = 2; i <= m; i++)
    {
        scanf("%d", &a2);
        if(G[a1][a2] >= 1e7) { printf("NO"); return 0; }
        a1 = a2;
    }
    printf("YES");
}
