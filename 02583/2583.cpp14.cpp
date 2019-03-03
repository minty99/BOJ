#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int v[110][110];
vector<int> ans;

int cnt = 0;
int m, n, k;
void DFS(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(v[x][y] == 0)
    {
        ans[cnt-1]++;
        v[x][y] = -cnt;
        DFS(x-1, y);
        DFS(x+1, y);
        DFS(x, y-1);
        DFS(x, y+1);
    }
}

int main()
{
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 1; i <= k; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        for(int x = a; x < c; x++)
            for(int y = b; y < d; y++)
                v[x][y] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 0)
            {
                cnt++;
                ans.push_back(0);
                DFS(i, j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", cnt);
    for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
