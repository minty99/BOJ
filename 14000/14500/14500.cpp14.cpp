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

int arr[510][510];
int M = 0;
int n, m;
bool visited[510][510];

void checkT(int x, int y)
{
    // Check for T shape tetromino
    if (x + 2 < n && y + 1 < m)
        M = max(M, arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y + 1]);
    if (x + 2 < n && y - 1 >= 0)
        M = max(M, arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y - 1]);
    if (y + 2 < m && x - 1 >= 0)
        M = max(M, arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x - 1][y + 1]);
    if (y + 2 < m && x + 1 < n)
        M = max(M, arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1]);
}

void DFS(int x, int y, int depth, int curr)
{
    if (depth == 1)
        checkT(x, y);
    if (visited[x][y])
        return;
    else
        visited[x][y] = true;
    if (depth == 4)
        M = max(M, curr);
    else
    {
        if (x + 1 < n)
            DFS(x + 1, y, depth + 1, curr + arr[x + 1][y]);
        if (y + 1 < m)
            DFS(x, y + 1, depth + 1, curr + arr[x][y + 1]);
        if (x - 1 >= 0)
            DFS(x - 1, y, depth + 1, curr + arr[x - 1][y]);
        if (y - 1 >= 0)
            DFS(x, y - 1, depth + 1, curr + arr[x][y - 1]);
    }
    visited[x][y] = false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            DFS(i, j, 1, arr[i][j]);

    printf("%d\n", M);
}