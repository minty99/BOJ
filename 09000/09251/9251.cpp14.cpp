#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

char s1[1001];
char s2[1001];
int dp[1001][1001];

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%s", s1);
    scanf("%s", s2);

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for(int i = 0; i < l1; i++)
    {
        for(int j = 0; j < l2; j++)
        {
            if(i > 0) dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if(j > 0) dp[i][j] = max(dp[i][j-1], dp[i][j]);
            if(i > 0 && j > 0) dp[i][j] = max(dp[i-1][j-1] + (s1[i] == s2[j]), dp[i][j]);
            else dp[i][j] = max((s1[i] == s2[j]) ? 1 : 0, dp[i][j]);
        }
    }

    printf("%d", dp[l1-1][l2-1]);
}
