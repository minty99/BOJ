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

int arr[41];
int dp[41];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++) scanf("%d", &arr[i]);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= 40; i++) dp[i] = dp[i-2] * 2 + dp[i-3];
    // for(int i = 1; i <= 40; i++) printf("%d\n", dp[i]);
    int ans = 1;
    for(int i = 1; i <= m; i++) ans *= dp[arr[i] - arr[i-1] - 1];
    ans *= dp[n - arr[m]];
    printf("%d", ans);
}
