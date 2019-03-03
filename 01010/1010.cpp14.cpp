#include <stdio.h>
int t, n, m, dp[31][31];

int main()
{
	scanf("%d", &t);

	for(int x = 1; x <= t; x++)
	{
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				dp[i][j] = 0;

		for(int i = 1; i <= m; i++) dp[1][i] = 1;
		for(int i = 2; i <= n; i++)
		{
			int sum = 0;
			for(int j = 1; j <= i-2; j++) sum += dp[i-1][j];
			for(int j = i; j <= m; j++)
			{
				sum += dp[i-1][j-1];
				dp[i][j] = sum;
			}
		}

		int answer = 0;
		for(int j = 1; j <= m; j++) answer += dp[n][j];
		printf("%d\n", answer);
	}
}
