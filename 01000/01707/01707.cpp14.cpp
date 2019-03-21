#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tgmath.h>
#include <tuple>
#include <unistd.h>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

vector<int> G[21000];
bool visited[21000];
int color[21000];

bool DFS(int idx)
{
    visited[idx] = true;
    for (int next_visit : G[idx])
    {
        if (!visited[next_visit])
        {
            color[next_visit] = !color[idx];
            bool result = DFS(next_visit);
            if (!result)
                return false;
        }
        else
        {
            if (color[idx] == color[next_visit])
                return false;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
    {
        int v, e;
        scanf("%d %d", &v, &e);

        for (int i = 1; i <= v; i++)
        {
            visited[i] = false;
            color[i] = -1;
            G[i].clear();
        }
        for (int i = 0; i < e; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 1; i <= v; i++)
        {
            if (!visited[i])
            {
                color[i] = 0;
                if (!DFS(i))
                {
                    printf("NO\n");
                    goto FAIL;
                }
            }
        }
        printf("YES\n");
    FAIL:;
    }
}