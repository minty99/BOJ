#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[100001];
int main()
{
	int n;
	scanf("%d", &n);

	dp[1] = 1;

	for(int i = 2; i <= n; i++)
	{
		dp[i] = 987654321;
		for(int j = 1; i - j*j >= 0; j++)
		{
			dp[i] = min(dp[i], dp[i-j*j]);
		}
		dp[i] += 1;
	}

	printf("%d\n", dp[n]);
}
