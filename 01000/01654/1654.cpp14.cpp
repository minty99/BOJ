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

    int n, k;
    scanf("%d %d", &k, &n);

    vector<lli> arr(k);
    for (int i = 0; i < k; i++)
        scanf("%lld", &arr[i]);
    // Parametric Search
    lli m = 1, M = (1LL << 31) - 1;
    lli ans = 0;
    while (m <= M)
    {
        lli mid = (m + M) / 2;
        lli t = 0;
        for (int i = 0; i < k; i++)
            t += arr[i] / mid;
        if (t >= n)
        {
            // Success
            ans = max(ans, mid);
            m = mid + 1;
        }
        else
            M = mid - 1;
    }

    printf("%lld\n", ans);
}