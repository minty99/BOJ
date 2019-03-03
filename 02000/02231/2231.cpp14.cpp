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

int arr[1000001];

int sum_of_digits(int n)
{
    int ret = 0;
    while (n > 0)
    {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 1000000; i++)
        arr[i] = 987654321;
    for (int i = 1; i <= n; i++)
    {
        int s = i + sum_of_digits(i);
        if (s > 1000000)
            continue;
        arr[s] = min(arr[s], i);
    }
    if (arr[n] == 987654321)
        arr[n] = 0;
    printf("%d\n", arr[n]);
}