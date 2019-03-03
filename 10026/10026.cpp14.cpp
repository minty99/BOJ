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

char v[120][120];
int n;
void DFS1(int x, int y, char c) // 색약 x
{
    if (x < 0 or y < 0 or x >= n or y >= n)
        return;
    if (v[x][y] == c)
    {
        v[x][y] += 32;
        DFS1(x - 1, y, c);
        DFS1(x + 1, y, c);
        DFS1(x, y - 1, c);
        DFS1(x, y + 1, c);
    }
}
void DFS2(int x, int y, char c) // 색약 o
{
    if (x < 0 or y < 0 or x >= n or y >= n)
        return;
    if (v[x][y] == c)
    {
        v[x][y] -= 32;
        DFS2(x - 1, y, c);
        DFS2(x + 1, y, c);
        DFS2(x, y - 1, c);
        DFS2(x, y + 1, c);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d", &n);
    char t;
    scanf("%c", &t);
    // Too simple DFS
    for (int i = 0; i < n; i++)
        fgets(v[i], 120, stdin);
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] <= 'Z')
            {
                DFS1(i, j, v[i][j]);
                c1++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == 'r')
                v[i][j] = 'g';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ('a' <= v[i][j])
            {
                DFS2(i, j, v[i][j]);
                c2++;
            }
        }
    }
    printf("%d %d\n", c1, c2);
}