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

int t, n;
lli x[20], y[20];
bitset<20> check;
lli m = 9223372036854775807;
lli sx, sy;

inline lli vSize2(lli x, lli y)
{
    return x*x + y*y;
}

void DFS(int idx, lli cx, lli cy, int depth)
{
    // printf("DFS %d %lld %lld %d\n", idx, cx, cy, depth);
    if(depth == n/2)
    {
        lli sum = vSize2(sx - 2*cx, sy - 2*cy);
        if(sum < m) m = sum;
        return;
    }
    check[idx] = true;
    for(int i = idx; i < n; i++)
    {
        if(!check[i]) DFS(i, cx+x[i], cy+y[i], depth+1);
    }
    check[idx] = false;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &t);
    while(t --> 0)
    {
        check.reset();
        sx = sy = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &x[i], &y[i]);
            sx += x[i];
            sy += y[i];
        }

        m = 9223372036854775807;
        for(int i = 0; i < n; i++) DFS(i, x[i], y[i], 1);

        long double ans = sqrt(m);
        printf("%.10Lf\n", ans);
    }
}
