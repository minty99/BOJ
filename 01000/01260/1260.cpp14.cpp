#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[1001];
int n, m, v;
vector< pair<int, int> > edge;
queue<int> Queue;
vector<int> DFSres;
vector<int> BFSres;

inline void DFS(vector< pair<int, int> > edge, int vertex)
{
    if(visited[vertex]) return;
    visited[vertex] = true;
    DFSres.push_back(vertex);
    vector<int> tovisit;
    for(int i = 0; i < m; i++)
    {
        if(vertex == edge[i].first) tovisit.push_back(edge[i].second);
        if(vertex == edge[i].second) tovisit.push_back(edge[i].first);
    }
    sort(tovisit.begin(), tovisit.end());
    for(int i = 0; i < tovisit.size(); i++) DFS(edge, tovisit[i]);
}

inline void BFS(vector< pair<int, int> > edge)
{
    while(!Queue.empty())
    {
        int vertex = Queue.front();
        Queue.pop();
        if(visited[vertex]) continue;
        BFSres.push_back(vertex);
        visited[vertex] = true;
        vector<int> tovisit;
        for(int i = 0; i < m; i++)
        {
            if(vertex == edge[i].first)
                tovisit.push_back(edge[i].second);
            if(vertex == edge[i].second)
                tovisit.push_back(edge[i].first);
        }
        sort(tovisit.begin(), tovisit.end());
        for(int i = 0; i < tovisit.size(); i++) Queue.push(tovisit[i]);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &v);
    edge.resize(m);
    for(int i = 0; i < m; i++)
        scanf("%d %d", &edge[i].first, &edge[i].second);

    sort(edge.begin(), edge.end());

    for(int i = 1; i <= 1000; i++) visited[i] = false;
    DFS(edge, v);

    for(int i = 1; i <= 1000; i++) visited[i] = false;
    Queue.push(v);
    BFS(edge);

    printf("%d", DFSres[0]);
    for(int i = 1; i < DFSres.size(); i++) printf(" %d", DFSres[i]);
    printf("\n%d", BFSres[0]);
    for(int i = 1; i < BFSres.size(); i++) printf(" %d", BFSres[i]);
    printf("\n");
}
