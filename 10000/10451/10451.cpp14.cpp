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

void check(vector<int> &arr, vector<bool> &cover, int idx)
{
    if (cover[idx])
        return;
    cover[idx] = true;
    check(arr, cover, arr[idx]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);

    vector<int> arr(1001);
    vector<bool> cover(1001);

    while (t-- > 0)
    {
        fill(arr.begin(), arr.end(), 0);
        fill(cover.begin(), cover.end(), false);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!cover[i])
            {
                check(arr, cover, i);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}