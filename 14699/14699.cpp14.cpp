#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
int n, m;
pii height[5001];
vector<int> lines[5001];
int answer = 0;
int dp[5001];

void DFS(int n, int count);

bool compare(pii a, pii b)
{
    return a.second > b.second;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        height[i].first = i;
        scanf("%d", &height[i].second);
    }

    for(int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(height[x].second < height[y].second) lines[x].push_back(y);
        else lines[y].push_back(x);
    }
    sort(height+1, height+n+1, compare);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < lines[height[i].first].size(); j++)
            dp[height[i].first] = max(dp[lines[height[i].first][j]], dp[height[i].first]);
        dp[height[i].first]++;
    }

    for(int i = 1; i <= n; i++) printf("%d\n", dp[i]);
}
