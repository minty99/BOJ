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
#include <unordered_set>
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

vector<string> v;
unordered_set<int> us[20][20];
bitset<100> bs;
int ans = 0;
int r, c;

void DFS(int x, int y, int depth, int visited)
{
    if(x < 0 || x >= r || y < 0 || y >= c) return;
    if(us[x][y].find(visited) != us[x][y].end()) return;

    if(bs[v[x][y]]) return;
    ans = max(ans, depth);
    bs[v[x][y]] = true;
    us[x][y].insert(visited);
    visited |= 1 << (v[x][y] - 65);
    DFS(x+1, y, depth+1, visited);
    DFS(x-1, y, depth+1, visited);
    DFS(x, y+1, depth+1, visited);
    DFS(x, y-1, depth+1, visited);
    visited &= ~(1 << (v[x][y] - 65));
    bs[v[x][y]] = false;
}
int main()
{
    bs.reset();
    scanf("%d %d", &r, &c);

    for(int i = 1; i <= r; i++)
    {
        char s[21];
        scanf("%s", s);
        v.emplace_back(s);
    }

    DFS(0, 0, 1, 1 << (v[0][0] - 65));
    printf("%d", ans);
}
