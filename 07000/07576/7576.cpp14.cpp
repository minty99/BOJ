#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int state[1100][1100];
int m, n;
int cnt = 0;
int nextday = 0;
int pushed = 0;
int day = 0;
int total;
queue<pair<int, int>> Queue;

void process(int i, int j)
{
    if(state[i][j] == 0 && i > 0 && j > 0 && i <= n && j <= m)
    {
        cnt++;
        state[i][j] = 1;
        Queue.push(make_pair(i, j));
        nextday++;
    }
}

void BFS()
{
    while(Queue.size() > 0)
    {
        pair<int, int> p = Queue.front();
        Queue.pop();
        if(pushed == 0)
        {
            day++;
            pushed = nextday;
            nextday = 0;
        }
        pushed--;

        int i = p.first;
        int j = p.second;
        process(i-1, j);
        process(i+1, j);
        process(i, j-1);
        process(i, j+1);
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    total = m*n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &state[i][j]);
            if(state[i][j] == 1)
            {
                cnt++;
                Queue.push(make_pair(i, j));
                pushed++;
            }
            if(state[i][j] == -1) total--;
        }
    }

    BFS();
    if(cnt == total) printf("%d", day);
    else printf("-1");
}
