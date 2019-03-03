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

int find_cost(vector<int> &cost, vector<int> &d, vector<vector<int>> &c, int w)
{
    if (cost[w] != -1)
        return cost[w];
    int pre = 0;
    for (int p : c[w])
    {
        pre = max(pre, find_cost(cost, d, c, p));
    }
    cost[w] = pre + d[w];
    return cost[w];
}

int solve(int n, int k, vector<int> &d, vector<vector<int>> &c, int w)
{
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++)
        cost[i] = -1;
    return find_cost(cost, d, c, w);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        vector<int> d(n + 1);
        vector<vector<int>> c(n + 1);
        for (int i = 1; i <= n; i++)
            scanf("%d", &d[i]);
        for (int i = 1; i <= k; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            c[b].push_back(a);
        }
        int w;
        scanf("%d", &w);
        int ans = solve(n, k, d, c, w);
        printf("%d\n", ans);
    }
}