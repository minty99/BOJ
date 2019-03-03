#include <cstdio>

using namespace std;
int dp[230][230];	// dp[i][j]: 수 i개를 써서 j를 만드는 방법의 수

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	dp[0][0] = 1;
	for(int i = 1; i <= k; i++)
	{
		dp[i][0] = 1;
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
			dp[i][j] %= 1000000000;
		}
	}

	printf("%d", dp[k][n]);
}
