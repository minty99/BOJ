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

typedef long long int ulli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int uulli;

vector<ulli> fact(1000001);
vector<ulli> fact_inv(1000001);

ulli fast_pow(ulli a, ulli k)
{
    ulli pow_sq[64];
    pow_sq[0] = a;
    for (int i = 1; i < 64; i++)
        pow_sq[i] = (pow_sq[i - 1] * pow_sq[i - 1]) % MOD;
    ulli ret = 1;
    bitset<64> bs(k);
    for (int i = 0; i < 64; i++)
    {
        if (bs[i])
            ret = (ret * pow_sq[i]) % MOD;
    }
    return ret;
}

ulli comb(int n, int r)
{
    if (n < r)
        return 0;
    ulli ret = fact[n];
    ret *= fact_inv[n - r];
    ret %= MOD;
    ret *= fact_inv[r];
    ret %= MOD;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    fact_inv[n] = fast_pow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--)
        fact_inv[i - 1] = i * fact_inv[i] % MOD;

    ulli ans = comb(n, x);
    ans *= comb(n, y);
    ans %= MOD;
    ans *= comb(n, z);
    ans %= MOD;
    int mul = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        ulli sub = comb(n, i) % MOD;
        sub *= comb(i, x);
        sub %= MOD;
        sub *= comb(i, y);
        sub %= MOD;
        sub *= comb(i, z);
        sub %= MOD;
        ans = ans + MOD + sub * mul;
        ans %= MOD;
        mul = -mul;
    }

    printf("%lld\n", ans);
}