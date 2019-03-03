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

lli fact[21];

bitset<21> used;
int getUnused(int order)
{
    if(order < 1) order = 1;
    for(int i = 1; i < 21; i++)
    {
        if(!used[i])
        {
            order--;
            if(order == 0) { used[i] = true; return i; }
        }
    }
    return -1;
}

lli getOrder(int num, bitset<21> used)
{
    lli order = 0;
    for(int i = 1; i < 21; i++)
    {
        if(!used[i])
        {
            order++;
            if(num == i) return order;
        }
    }
    return -1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    int n;
    scanf("%d", &n);

    fact[0] = 1;
    for(int i = 1; i <= 20; i++) fact[i] = fact[i-1] * i;

    int q;
    scanf("%d", &q);

    if(q == 1)
    {
        lli k;
        scanf("%lld", &k);
        lli remain = k;
        for(int i = n-1; i >= 0; i--)
        {
            printf("%d ", getUnused((remain + fact[i]-1) / fact[i]));
            remain -= ((remain + fact[i]-1) / fact[i] - 1) * fact[i];
        }
    }

    if(q == 2)
    {
        vector<int> v(n);
        for(int i = 0; i < n; i++) scanf("%d", &v[i]);
        bitset<21> used;
        used.reset();

        lli cnt = 1;
        for(int i = 0; i < n; i++)
        {
            cnt += (getOrder(v[i], used) - 1) * fact[n - i - 1];
            used[v[i]] = true;
        }
        printf("%lld", cnt);
    }
}
