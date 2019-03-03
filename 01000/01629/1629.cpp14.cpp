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
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int a, b, c;
lli multiply(lli n, lli cnt)
{
    // cnt: 2^n form.
    cnt >>= 1;
    while(cnt > 0)
    {
        n *= n;
        n %= c;
        cnt >>= 1;
    }
    return n;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d %d %d", &a, &b, &c);

    bitset<32> bs(b);
    lli n = 1;
    for(int i = 0; i < 32; i++)
    {
        if(bs[i] == 1) n *= multiply(a, 1 << i);
        n %= c;
    }
    printf("%lld", n);
}
