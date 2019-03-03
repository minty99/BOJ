#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

char pw[5010];
int dp[5010][2];

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%s", pw);
    int l = strlen(pw);
    dp[0][0] = (pw[0] != '0') ? 1 : 0;
    dp[0][1] = 0;
    for(int i = 1; i < l; i++)
    {
        // dp[i][0]: i번째 칸까지의 답, 단 마지막은 숫자 1개로.
        // dp[i][1]: i번째 칸까지의 답, 단 마지막은 숫자 2개로.
        dp[i][0] = (pw[i] != '0') ? dp[i-1][0] + dp[i-1][1] : 0;
        if(pw[i-1] == '1' || (pw[i-1] == '2' && pw[i] <= '6'))
            dp[i][1] = (i >= 2) ? (dp[i-2][0] + dp[i-2][1]) : 1;
        else dp[i][1] = 0;
        dp[i][0] %= 1000000;
        dp[i][1] %= 1000000;
    }

    printf("%d", (dp[l-1][0] + dp[l-1][1]) % 1000000);
}
