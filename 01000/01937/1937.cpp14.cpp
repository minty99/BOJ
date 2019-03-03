#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int, int, int>> pq;

int dp[600][600];
int arr[600][600];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			pq.emplace(arr[i][j], i, j);
		}
	}

	for(int i = 0; i < 600; i++)
		for(int j = 0; j < 600; j++)
			dp[i][j] = -1;

	int answer = -1;
	while(!pq.empty())
	{
		tuple<int, int, int> t = pq.top();
		pq.pop();
		int i = get<1>(t);
		int j = get<2>(t);
		dp[i][j] = 0;
		if(arr[i-1][j] > arr[i][j]) dp[i][j] = max(dp[i][j], dp[i-1][j]);
		if(arr[i+1][j] > arr[i][j]) dp[i][j] = max(dp[i][j], dp[i+1][j]);
		if(arr[i][j-1] > arr[i][j]) dp[i][j] = max(dp[i][j], dp[i][j-1]);
		if(arr[i][j+1] > arr[i][j]) dp[i][j] = max(dp[i][j], dp[i][j+1]);
		dp[i][j]++;
		answer = max(dp[i][j], answer);
	}
	printf("%d", answer);
}
