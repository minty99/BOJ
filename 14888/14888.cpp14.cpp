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

int arr[12];
int op[11];
int n;
int x, y, z, w;
lli M = -2e9, m = 2e9;
const int PLUS = 1;
const int MINUS = 2;
const int MULTIPLY = 3;
const int DIVIDE = 4;

lli calc()
{
    lli ret = arr[1];
    for (int i = 2; i <= n; i++)
    {
        if (op[i - 1] == PLUS)
            ret += arr[i];
        if (op[i - 1] == MINUS)
            ret -= arr[i];
        if (op[i - 1] == MULTIPLY)
            ret *= arr[i];
        if (op[i - 1] == DIVIDE)
            ret /= arr[i];
    }
    return ret;
}
void DFS(int a, int b, int c, int d, int depth)
{
    if (a <= x && b <= y && c <= z && d <= w)
    {
        if (depth == n)
        {
            lli res = calc();
            M = max(res, M);
            m = min(res, m);
            return;
        }
        op[depth] = PLUS;
        DFS(a + 1, b, c, d, depth + 1);
        op[depth] = MINUS;
        DFS(a, b + 1, c, d, depth + 1);
        op[depth] = MULTIPLY;
        DFS(a, b, c + 1, d, depth + 1);
        op[depth] = DIVIDE;
        DFS(a, b, c, d + 1, depth + 1);
        op[depth] = 0;
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

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d %d %d", &x, &y, &z, &w);

    DFS(0, 0, 0, 0, 1);
    printf("%d\n%d\n", M, m);
}