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

int G[101][101];
int P[101][101];
int x[101], y[101];
int n, m;
int dest;

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int a, b;
    scanf("%d %d", &a, &b);
    dest = b;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            G[i][j] = 1e7;
    for(int i = 1; i <= m; i++) G[i][i] = 0;

    for(int i = 1; i <= m; i++)
    {
        for(int j = i+1; j <= m; j++)
        {
            for(int k = x[i]; k <= n; k += y[i])
            {
                if((k >= x[j]) && (k - x[j]) % y[j] == 0)
                {
                    G[i][j] = 1;
                    G[j][i] = 1;
                    P[i][j] = j;
                    P[j][i] = i;
                    break;
                }
            }
        }
    }

    for(int k = 1; k <= m; k++)
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++)
            {
                if(G[i][j] > G[i][k] + G[k][j])
                {
                    G[i][j] = G[i][k] + G[k][j];
                    P[i][j] = P[i][k];
                }
            }
    int ans = 1e8;
    int st = 0;
    int en = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a >= x[i] && b >= x[j] && (a - x[i]) % y[i] == 0 && (b - x[j]) % y[j] == 0)
            {
                if(G[i][j] < ans)
                {
                    ans = G[i][j];
                    st = i;
                    en = j;
                }
            }
        }
    }


    if(ans >= 1e7) ans = -2;
    printf("%d\n", ans+1);
    if(ans == -2) return 0;
    while(st != en)
    {
        printf("%d\n", st);
        st = P[st][en];
    }
    printf("%d\n", en);
}
