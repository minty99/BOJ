#include <cstdio>

int grid[30][30];
int n, m;
int answer = 0;

void Process(int x, int y, int val, int depth)
{
    grid[x][y] = val;
    if(val == 1)
    {
        if(grid[x-1][y] + grid[x][y-1] + grid[x-1][y-1] == 3) return;
        if(grid[x+1][y] + grid[x][y-1] + grid[x+1][y-1] == 3) return;
        if(grid[x-1][y] + grid[x][y+1] + grid[x-1][y+1] == 3) return;
        if(grid[x+1][y] + grid[x][y+1] + grid[x+1][y+1] == 3) return;
    }
    if(x < n)
    {
        x++;
        Process(x, y, 1, depth+1);
        Process(x, y, 0, depth+1);
    }
    else if(y < m)
    {
        x = 1;
        y++;
        Process(x, y, 1, depth+1);
        Process(x, y, 0, depth+1);
    }
    else answer++;

    grid[x][y] = -1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            grid[i][j] = -1;
    Process(1, 1, 0, 1);
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            grid[i][j] = -1;
    Process(1, 1, 1, 1);

    printf("%d", answer);
}
