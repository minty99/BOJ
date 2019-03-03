#include <cstdio>
#include <queue>

using namespace std;

int state[110][110][110];
int m, n, h;
int cnt = 0;
int total;
int curr_day;

typedef struct _tomato {
	int x, y, z, day;
} Tomato;

queue<Tomato> Queue;

void qpush(int x, int y, int z, int day)
{
	Tomato t = { x, y, z, day };
	Queue.push(t);
}

void process(int x, int y, int z, int day)
{
    if(state[x][y][z] == 0 && x > 0 && y > 0 && z > 0 && x <= h && y <= n && z <= m)
    {
        cnt++;
        state[x][y][z] = 1;
        qpush(x, y, z, day);
		curr_day = day;
    }
}

void BFS()
{
    while(Queue.size() > 0)
    {
        Tomato t = Queue.front();
        Queue.pop();
        process(t.x, t.y - 1, t.z, t.day + 1);
        process(t.x, t.y + 1, t.z, t.day + 1);
		process(t.x, t.y, t.z - 1, t.day + 1);
		process(t.x, t.y, t.z + 1, t.day + 1);
        process(t.x - 1, t.y, t.z, t.day + 1);
        process(t.x + 1, t.y, t.z, t.day + 1);
    }
}

int main()
{
    scanf("%d %d %d", &m, &n, &h);
    total = m*n*h;
    for(int k = 1; k <= h; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &state[k][i][j]);
                if(state[k][i][j] == 1)
                {
                    cnt++;
                    qpush(k, i, j, 0);
                }
                if(state[k][i][j] == -1) total--;
            }
        }
    }


    BFS();
    if(cnt == total) printf("%d", curr_day);
    else printf("-1");
}
