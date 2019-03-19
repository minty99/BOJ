#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tgmath.h>
#include <tuple>
#include <unistd.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

typedef pair<plli, plli> Matrix22;

Matrix22 MM(Matrix22 a, Matrix22 b)
{
    Matrix22 c;
    c.first.first = a.first.first * b.first.first + a.first.second * b.second.first;
    c.first.second = a.first.first * b.first.second + a.first.second * b.second.second;
    c.second.first = a.second.first * b.first.first + a.second.second * b.second.first;
    c.second.second = a.second.first * b.first.second + a.second.second * b.second.second;
    c.first.first %= 1000000;
    c.first.second %= 1000000;
    c.second.first %= 1000000;
    c.second.second %= 1000000;
    return c;
}

Matrix22 M_pow(Matrix22 m, lli mul)
{
    if (mul >= 2)
    {
        Matrix22 x = M_pow(m, mul / 2);
        return mul % 2 == 0 ? MM(x, x) : MM(MM(x, x), m);
    }
    else if (mul == 1)
        return m;
    else
    {
        Matrix22 x;
        x.first.first = x.second.second = 1;
        x.first.second = x.second.first = 0;
        return x;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    lli n;
    scanf("%lld", &n);

    Matrix22 m;
    m.first.first = m.first.second = 1;
    m.second.first = 1;
    m.second.second = 0;
    Matrix22 result = n % 2 == 0 ? M_pow(m, n) : MM(M_pow(m, n - 1), m);
    printf("%lld\n", result.first.second);
}