#include <cstdio>
using namespace std;

int t[20];
int p[20];
int dp[20];

int max_possible(int idx)
{
    int M = 0;
    for(int i = 1; i <= idx-1; i++)
    {
        if(i + t[i] - 1 < idx && M < dp[i]) M = dp[i];
    }
    return M;
}

int main()
{
    // dp[i]: i번째 날 상담이 마지막일 때의 정답
    // dp[i] = max_possible(dp[1...i-1]) + cost[i]

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d %d", &t[i], &p[i]);

    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i + t[i] - 1 > n) dp[i] = 0;
        else dp[i] = max_possible(i) + p[i];
        if(answer < dp[i]) answer = dp[i];
    }

    printf("%d", answer);
}
