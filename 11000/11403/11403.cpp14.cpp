#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> G[101];
int memo[101];
bool DFS(int from, int to, bool depth)
{
    if(from == to && depth == true) return true;
    if(from != to) memo[from] = true;

    for(int i = 0; i < G[from].size(); i++)
    {
        bool result = false;
        if(memo[G[from][i]] == false) result = DFS(G[from][i], to, true);
        if(result == true) return true;
    }
    // memo[from] = false;
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int k;
            scanf("%d", &k);
            if(k == 1) G[i].push_back(j);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            memset(memo, 0, sizeof(memo));
            bool way = DFS(i, j, false);
            if(way == true) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
}
