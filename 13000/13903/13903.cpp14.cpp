#include <cstdio>
#include <utility>
#include <queue>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pii;

typedef struct _p3 {
	int x, y, z;

	_p3(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}
} piii;

int r, c, n;
int block[1001][1001];
bool visited[1001][1001];
pii ways[11];
int answer = 987654321;
queue<piii> que;

inline bool isValid(piii p)
{
	return !(p.x < 0 || p.y < 0 || p.x >= r || p.y >= c || block[p.x][p.y] != 1 || visited[p.x][p.y]);
}

int BFS()
{
	while(!que.empty())
	{
		piii curr = que.front();
		que.pop();
		if(!isValid(curr)) continue;
		if(curr.x == r-1) return curr.z;
		visited[curr.x][curr.y] = true;
		for(int i = 1; i <= n; i++)
			que.emplace(curr.x + ways[i].x, curr.y + ways[i].y, curr.z+1);
	}
	return 987654321;
}

int main()
{
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &block[i][j]);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &ways[i].x, &ways[i].y);

	for(int i = 0; i < c; i++)
		if(block[0][i] == 1) que.emplace(0, i, 0);

	answer = BFS();

	if(answer == 987654321) printf("-1");
	else printf("%d", answer);
}
