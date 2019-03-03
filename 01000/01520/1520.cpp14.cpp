#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int arr[600][600];
int dp[600][600];
vector<tuple<int, int, int>> v;
int m, n;

int main()
{
	scanf("%d %d", &m, &n);

	for(int i = 0; i < 600; i++)
		for(int j = 0; j < 600; j++)
			arr[i][j] = 2e9;

	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			v.emplace_back(arr[i][j], i, j);
		}
	}
	sort(v.begin(), v.end(), [] (auto u, auto v) {
		return u > v;
	});

	dp[1][1] = 1;

	for(int i = 0; i < v.size(); i++)
	{
		int k = get<0>(v[i]);
		int x = get<1>(v[i]);
		int y = get<2>(v[i]);

		if(arr[x-1][y] > k) dp[x][y] += dp[x-1][y];
		if(arr[x+1][y] > k) dp[x][y] += dp[x+1][y];
		if(arr[x][y-1] > k) dp[x][y] += dp[x][y-1];
		if(arr[x][y+1] > k) dp[x][y] += dp[x][y+1];
	}

	printf("%d", dp[m][n]);
}
