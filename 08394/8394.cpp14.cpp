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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);
    vector<pii> v(n + 1);

    v[1] = {0, 1};
    v[2] = {1, 1};
    // first: 마지막 1명 악수 / second: 마지막 1명 악수 안 함
    for (int i = 3; i <= n; i++)
    {
        v[i].first = v[i - 1].second % 10;
        v[i].second = (v[i - 1].first + v[i - 1].second) % 10;
    }

    printf("%d\n", (v[n].first + v[n].second) % 10);
}