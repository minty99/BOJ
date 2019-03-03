#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> adj[1000];
int tm[1000];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int c;
        scanf("%d", &c);
        tm[i] = c;
        while(true)
        {
            int k;
            scanf("%d", &k);
            if(k == -1) break;
            adj[i].push_back(k);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        queue<int> Q;
        vector<int> G[1000];
        vector<int> indeg_list[1000];
        int indeg[1000];
        bool visited[1000];
        memset(indeg, 0, sizeof(indeg));
        memset(visited, 0, sizeof(visited));
        Q.push(i);
        while(!Q.empty())
        {
            int idx = -1;
            do {
                idx = Q.front();
                Q.pop();
            } while(visited[idx] && !Q.empty());
            if(idx == -1) break;
            fflush(stdout);
            visited[idx] = true;
            for(int j = 0; j < adj[idx].size(); j++)
            {
                G[adj[idx][j]].push_back(idx);  // 우선순위 빠른 것 -> 늦은 것.
                indeg[idx]++;
                indeg_list[idx].push_back(adj[idx][j]);
                Q.push(adj[idx][j]);
            }
        }

        // 그래프 생성 완료
        // Topological Sort!
        // now Q is empty
        for(int j = 0; j < n; j++)
        {
            if(visited[j])  // node exists
            {
                if(indeg[j] == 0) Q.push(j);
            }
        }

        int fin_tm[1000];
        memset(fin_tm, 0, sizeof(fin_tm));
        while(!Q.empty())
        {
            int sz = Q.size();
            for(int j = 1; j <= sz; j++)
            {
                int idx = Q.front();
                Q.pop();
                int M = 0;
                for(int k = 0; k < indeg_list[idx].size(); k++)
                    M = fin_tm[indeg_list[idx][k]] > M ? fin_tm[indeg_list[idx][k]] : M;
                fin_tm[idx] = M + tm[idx];
                for(int k = 0; k < G[idx].size(); k++)
                {
                    indeg[G[idx][k]]--;
                    if(indeg[G[idx][k]] == 0) Q.push(G[idx][k]);
                }
            }
        }
        printf("%d\n", fin_tm[i]);
    }
}
