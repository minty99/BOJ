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

int v[10001];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int s = 0;
        for(int j = i; j <= n; j++)
        {
            s += v[j];
            if(s == m) ans++;
            if(s > m) break;
        }
    }
    printf("%d", ans);
}
