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
int ans[110000];
bitset<110000> visited;

int Process(int r)
{
    ans[r] = 1;
    visited[r] = true;
    for(int i = 0; i < G[r].size(); i++)
    {
        if(!visited[G[r][i]]) ans[r] += Process(G[r][i]);
    }
    return ans[r];
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, r, q;
    scanf("%d %d %d", &n, &r, &q);

    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    Process(r);

    for(int i = 1; i <= q; i++)
    {
        int u;
        scanf("%d", &u);
        printf("%d\n", ans[u]);
    }
}
