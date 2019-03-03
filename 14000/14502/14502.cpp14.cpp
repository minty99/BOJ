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

int arr[10][10];
int ans = 0;

void Fill(int (&t)[10][10], int x, int y, int n, int m)
{
    if (!(0 <= x && x < n && 0 <= y && y < m))
        return;
    if (t[x][y] == 0)
    {
        t[x][y] = 2;
        Fill(t, x - 1, y, n, m);
        Fill(t, x + 1, y, n, m);
        Fill(t, x, y - 1, n, m);
        Fill(t, x, y + 1, n, m);
    }
}

int Try(int w1, int w2, int w3, int n, int m)
{
    if (arr[w1 / m][w1 % m] != 0)
        return 0;
    if (arr[w2 / m][w2 % m] != 0)
        return 0;
    if (arr[w3 / m][w3 % m] != 0)
        return 0;
    if (w1 == w2 || w1 == w3 || w2 == w3)
        return 0;
    // printf("%d %d %d %d %d %d\n", w1 / m, w1 % m, w2 / m, w2 % m, w3 / m, w3 % m);

    int t[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[i][j] = arr[i][j];

    t[w1 / m][w1 % m] = t[w2 / m][w2 % m] = t[w3 / m][w3 % m] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (t[i][j] == 2)
            {
                Fill(t, i - 1, j, n, m);
                Fill(t, i + 1, j, n, m);
                Fill(t, i, j - 1, n, m);
                Fill(t, i, j + 1, n, m);
            }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += t[i][j] == 0 ? 1 : 0;
    return cnt;
}

void Process(int n, int m)
{
    for (int w1 = 0; w1 < n * m; w1++)
        for (int w2 = w1 + 1; w2 < n * m; w2++)
            for (int w3 = w2 + 1; w3 < n * m; w3++)
                ans = max(Try(w1, w2, w3, n, m), ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);

    Process(n, m);
    printf("%d\n", ans);
}