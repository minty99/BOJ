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

int dp[201];
int arr[201];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int M = 0;
        for(int j = 1; j <= n-1; j++)
        {
            if(arr[j] < arr[i]) M = max(dp[j], M);
        }
        dp[i] = M+1;
        ans = max(dp[i], ans);
    }
    ans = n - ans;
    printf("%d", ans);
}
