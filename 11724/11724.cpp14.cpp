#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

vector<int> G[1001];
int answer = 0;
bitset<1001> visited;

void DFS(int idx)
{
        visited[idx] = true;
        for(int i = 0; i < G[idx].size(); i++)
        {
                if(!visited[G[idx][i]]) DFS(G[idx][i]);
        }
}

int main()
{
        // freopen("in.txt", "r", stdin);

        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
        {
                int u, v;
                scanf("%d %d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
        }
        
        visited.reset();
        for(int i = 1; i <= n; i++)
        {
                if(!visited[i]) 
                {
                        DFS(i);
                        answer++;
                }
        }

        printf("%d", answer);
}