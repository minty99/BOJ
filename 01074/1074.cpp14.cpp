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

int curr = -1;
int n, r, c;
void solve(int lx, int ly, int rx, int ry)
{
    if(lx == r && ly == c && rx == r && ry == c)
    {
        curr++;
        printf("%d", curr);
        exit(0);
    }
    if(lx <= r && r <= rx && ly <= c && c <= ry)
    {
        int mid_x = (lx + rx) / 2;
        int mid_y = (ly + ry) / 2;
        solve(lx, ly, mid_x, mid_y);
        solve(lx, mid_y+1, mid_x, ry);
        solve(mid_x+1, ly, rx, mid_y);
        solve(mid_x+1, mid_y+1, rx, ry);
    }
    else curr += (rx - lx + 1) * (ry - ly + 1);
}
int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d %d %d", &n, &r, &c);

    solve(0, 0, (1 << n) - 1, (1 << n) - 1);
}
