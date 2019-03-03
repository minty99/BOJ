#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

int G[101][101];

int answer = 0;
bitset<101> visited[101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;

void DFS(int x, int y)
{
	visited[x][y] = true;
	for(int i = 0; i < 4; i++)
	{
		if(x+dx[i] >= 1 && x+dx[i] <= n && y+dy[i] >= 1 && y+dy[i] <= n && !visited[x+dx[i]][y+dy[i]])
			DFS(x+dx[i], y+dy[i]);
	}
}

int main()
{
	// freopen("in.txt", "r", stdin);

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}

	int ans = 0;
	for(int z = 0; z <= 100; z++)
	{
		answer = 0;
		for(int i = 1; i <= n; i++)
		{
			visited[i].reset();
			for(int j = 1; j <= n; j++)
				if(G[i][j] <= z) visited[i][j] = true;
		}

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(!visited[i][j])
				{
					DFS(i, j);
					answer++;
				}
			}
		}
		ans = max(ans, answer);
	}


	printf("%d", ans);
}
