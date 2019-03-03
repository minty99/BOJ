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

vector<int> v;
vector<pii> ani;
int main()
{
    // freopen("in.txt", "r", stdin);

    int m, n;
    lli l;
    scanf("%d %d %lld", &m, &n, &l);
    v.resize(m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    int x, y;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if(y > l) continue;
        ani.emplace_back(x, y);
    }
    n = ani.size();
    sort(ani.begin(), ani.end());

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        lli a = ani[i].x;
        lli b = ani[i].y;
        lli left = min(a + l - b, a - l + b);
        lli right = max(a + l - b, a - l + b);

        int idx1 = lower_bound(v.begin(), v.end(), left) - v.begin();
        // printf("%lld %lld %d\n", left, right, v[idx1]);
        if(idx1 < v.size() && v[idx1] <= right) ans++;
    }

    printf("%d", ans);

}
