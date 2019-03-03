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

// dp[i][j]: (i, j) 로 끝나는 정사각형의 변의 길이
int dp[1100][1100];
int h[1100][1100];
int v[1100][1100];
int data[1100][1100];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        char s[1100];
        scanf("%s", s);
        for(int j = 0; j < m; j++)
        {
            data[i][j+1] = s[j] - '0';
            if(data[i][j+1] == 1)
            {
                h[i][j+1] = h[i][j] + 1;
                v[i][j+1] = v[i-1][j+1] + 1;
            }
        }
    }

    int M = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = min(min(dp[i-1][j-1]+1, h[i][j]), v[i][j]);
            M = max(dp[i][j], M);
        }
    }
    printf("%d\n", M*M);
}
