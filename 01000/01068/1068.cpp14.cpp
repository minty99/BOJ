#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int arr[60];
vector<vector<int>> tree(60);
set<int> s;

void solve(int n)
{
    if(tree[n].size() == 0) s.insert(n);
    else for(int v: tree[n]) solve(v);
}

int main()
{
    int n;
    scanf("%d", &n);
    int root = -1;
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        arr[i] = k;
        if(k != -1) tree[k].push_back(i);
        else root = i;
    }
    int del;
    scanf("%d", &del);
    tree[del].clear();
    if(arr[del] != -1)
        tree[arr[del]].erase(find(tree[arr[del]].begin(), tree[arr[del]].end(), del));
    solve(root);

    if(del == root) printf("0");
    else printf("%lu", s.size());
}
