#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <array>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

vector<int> G[110000];
int dp[110000];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    priority_queue<pii> pq;
    for(int i = 0; i <= n-1; i++) pq.emplace(G[i].size(), i);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        pii p = pq.top();
        pq.pop();
        for(int j = 0; j < p.x; j++)
        {
            if(G[G[p.y][j]].size() > p.x) dp[p.y] = max(dp[p.y], dp[G[p.y][j]]);
        }
        dp[p.y]++;
        ans = max(ans, dp[p.y]);
    }
    printf("%d", ans);
}
