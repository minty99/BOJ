#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int t;
int m, n, k;
int grid[2600][2600];

void DFS(int x, int y, int val)
{
    grid[x][y] = val;
    if(x-1 >= 0 && grid[x-1][y] == -1) DFS(x-1, y, val);
    if(y-1 >= 0 && grid[x][y-1] == -1) DFS(x, y-1, val);
    if(x+1 < m && grid[x+1][y] == -1) DFS(x+1, y, val);
    if(y+1 < n && grid[x][y+1] == -1) DFS(x, y+1, val);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &t);

    while(t > 0)
    {
        scanf("%d %d %d", &m, &n, &k);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = 0;

        for(int i = 1; i <= k; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            grid[a][b] = -1;
        }

        int val = 1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == -1) DFS(i, j, val++);
            }
        }
        val--;
        printf("%d\n", val);
        t--;
    }

}
