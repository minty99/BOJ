// Floyd-Warshall 알고리즘을 사용해야 합니다.
#include <cstdio>
#include <vector>
using namespace std;

vector<int> computers[101];
int infected[101];  // 0: 미감염, 1: 감염
bool visited[101];
void DFS(int n)
{
    infected[n] = 1;
    visited[n] = true;
    for(int i = 0; i < computers[n].size(); i++)
    {
        if(!visited[computers[n][i]]) DFS(computers[n][i]);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        computers[a].push_back(b);
        computers[b].push_back(a);
    }
    infected[1] = 1;
    DFS(1);
    int answer = -1;
    for(int i = 1; i <= n; i++)
        if(infected[i] == 1) answer++;
    printf("%d", answer);
}
