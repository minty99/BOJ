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

char v[60][60];
int a, b;
int M = 0;
void BFS(int x, int y)
{
    bool check[60][60];
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 60; j++)
            check[i][j] = false;
    queue<pair<pii, int>> Q;
    Q.emplace(pii(x, y), 0);
    while (!Q.empty())
    {
        pair<pii, int> p = Q.front();
        Q.pop();
        int i = p.x.x, j = p.x.y, d = p.y;
        if (i < 0 or i >= a or j < 0 or j >= b or check[i][j] or v[i][j] == 'W')
            continue;
        M = max(M, d);
        check[i][j] = true;
        Q.emplace(pii(i - 1, j), d + 1);
        Q.emplace(pii(i + 1, j), d + 1);
        Q.emplace(pii(i, j - 1), d + 1);
        Q.emplace(pii(i, j + 1), d + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d %d", &a, &b);

    for (int i = 0; i < a; i++)
        scanf("%s\n", v[i]);

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (v[i][j] == 'L')
                BFS(i, j);
        }
    }
    printf("%d\n", M);
}