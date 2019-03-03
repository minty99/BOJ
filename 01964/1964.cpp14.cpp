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

    int n;
    scanf("%d", &n);

    int a = 5;
    for(int i = 2; i <= n; i++) { a += (i+1)*3-2; a %= 45678;}
    printf("%d", a);
}
