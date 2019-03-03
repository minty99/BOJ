#include <stdio.h>
#define min(a, b) (a) < (b) ? (a) : (b)

int n;
int arr[11][11];
int dp[17][65536];

int shortestPath(int current, int visited)
{
    if(visited == ((1 << n) - 1)) dp[current][visited] = arr[current][1];
    if(dp[current][visited] > 0) return dp[current][visited];
    int result = 987654321;
    for(int i = 1; i <= n; i++)
    {
        if((visited & (1 << (i-1))) == 0 && arr[current][i] != 0)
            result = min(result, shortestPath(i, visited | (1 << (i-1))) + arr[current][i]);
    }
    dp[current][visited] = result;
    return result;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);

    shortestPath(1, 1);

    printf("%d", dp[1][1]);
}
