#include <cstdio>
using namespace std;

long long arr[110][110], dp[110][110];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%lld", &arr[i][j]);

	dp[1][1] = 1;
	for(int i = 2; i <= n*2; i++)
	{
		for(int x = 1, y = i-x; x <= n && y >= 1; x++, y--)
		{
			if(arr[x][y] == 0) continue;
			dp[x+arr[x][y]][y] += dp[x][y];
			dp[x][y+arr[x][y]] += dp[x][y];
		}
	}
	printf("%lld", dp[n][n]);
}
