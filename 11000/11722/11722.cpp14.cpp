#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dp[1001], arr[1001], ans;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for(int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(arr[j] > arr[i]) dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}
