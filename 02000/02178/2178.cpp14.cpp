#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int arr[102][102], n, m, visited[102][102];
int min = 987654321;
typedef struct _Point {
    int x, y, count;
} Point;

queue<Point> que;
void qpush(int x, int y, int count)
{
    Point p = { x, y, count };
    que.push(p);
}

void BFS()
{
    while(!que.empty())
    {
		int x, y, count;
		Point p = que.front();
		que.pop();
		x = p.x;
		y = p.y;
		count = p.count;

        if(visited[x][y] == 0)
        {
	        visited[x][y] = 1;
	        if(x == n && y == m)
	        {
	            printf("%d\n", count);
	            exit(0);
	        }
			if(arr[x-1][y] == 1) qpush(x-1, y, count+1);
            if(arr[x+1][y] == 1) qpush(x+1, y, count+1);
            if(arr[x][y-1] == 1) qpush(x, y-1, count+1);
            if(arr[x][y+1] == 1) qpush(x, y+1, count+1);
		}
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        char s[102];
        scanf("%s", s);
        for(int j = 1; j <= m; j++) arr[i][j] = s[j-1] - '0';
    }

	Point p = { 1, 1, 1 };
	que.push(p);
    BFS();
}
