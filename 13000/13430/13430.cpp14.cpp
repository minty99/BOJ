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

lli init[64];

void mod_init(lli n)
{
    // init[i] = n^(2^i) % MOD
    init[0] = n % MOD;
    for(int i = 1; i <= 31; i++)
        init[i] = (init[i-1] * init[i-1]) % MOD;
}

lli mod_power(lli n, lli k)
{
    mod_init(n);
    lli ans = 1;
    for(int i = 0; i <= 31; i++)
    {
        if(((k & (1 << i)) >> i)== 1)
        {
            ans *= init[i];
            ans %= MOD;
        }
    }
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int k, n;
    scanf("%d %d", &k, &n);

    lli ans = 1;
    for(int i = n; i <= n+k; i++) { ans *= i; ans %= MOD; }

    // ans / (k+1)! = ans * (k+1)!^-1 = ans * (k+1)!^(MOD-2)

    for(int i = 1; i <= k+1; i++)
    {
        ans *= mod_power(i, MOD-2);
        ans %= MOD;
    }
    printf("%lld", ans);
}
