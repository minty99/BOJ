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

int v[2200][2200];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &v[i][j]);

    queue<pair<pii, int>> Q;
    Q.emplace(pii(1, 1), n);
    int ans[3] = {0, 0, 0};
    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();
        int x = p.x.x, y = p.x.y, sz = p.y;
        int k = v[x][y];
        for (int i = x; i < x + sz; i++)
        {
            for (int j = y; j < y + sz; j++)
            {
                if (v[i][j] != k)
                {
                    int new_sz = sz / 3;
                    for (int t = 0; t <= 2; t++)
                        for (int w = 0; w <= 2; w++)
                            Q.emplace(pii(x + new_sz * t, y + new_sz * w), new_sz);
                    goto fail;
                }
            }
        }
        ans[k + 1]++;

    fail:
        continue;
    }
    printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
}