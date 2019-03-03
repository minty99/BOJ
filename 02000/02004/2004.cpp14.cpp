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

    int n, m;
    scanf("%d %d", &n, &m);
    // nCm = n! / m!(n-m)!

    int c2 = 0;
    int c5 = 0;

    for(int i = n/2; i > 0; i /= 2) c2 += i;
    for(int i = n/5; i > 0; i /= 5) c5 += i;

    for(int i = m/2; i > 0; i /= 2) c2 -= i;
    for(int i = m/5; i > 0; i /= 5) c5 -= i;

    for(int i = (n-m)/2; i > 0; i /= 2) c2 -= i;
    for(int i = (n-m)/5; i > 0; i /= 5) c5 -= i;

    printf("%d", min(c2, c5));
}
