#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <sstream>
#include <bitset>
#include <random>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

vector<int> v[510000];
bool visited[510000];
int leaf_cnt = 0;

void DFS(int idx, int depth)
{
    visited[idx] = true;
    int l = v[idx].size();
    bool isleaf = true;
    for(int i = 0; i < l; i++)
    {
        if(!visited[v[idx][i]])
        {
            DFS(v[idx][i], depth+1);
            isleaf = false;
        }
    }
    if(isleaf) leaf_cnt += depth;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n-1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1, 0);
    if(leaf_cnt % 2 == 1) printf("Yes");
    else printf("No");
}
