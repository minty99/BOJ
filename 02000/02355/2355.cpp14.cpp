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

int main()
{
    // freopen("in.txt", "r", stdin);

    lli a, b;
    scanf("%lld %lld", &a, &b);
    if(a > b) { int t = a; a = b; b = t; }
    lli s1 = 0, s2 = 0;
    if(a < 0 && b > 0) { s1 = -(-a)*((-a)+1)/2; s2 = b*(b+1)/2; }
    else s1 = b*(b+1)/2 - (a-1)*a/2;
    printf("%lld", s1+s2);
}
