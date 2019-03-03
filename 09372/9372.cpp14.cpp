#include <cstdio>
#include <iostream>
#include <cassert>
#include <array>
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
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

array<int, 3> edge[100000];

int main()
{
    // freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    while(t --> 0)
    {
        int v, e;
        scanf("%d %d", &v, &e);

        for(int i = 0; i < e; i++) {
            scanf("%d %d", &edge[i][1], &edge[i][2]);
        }
        //printf("%lld\n", Kruskal(edge, e));
        printf("%d\n", v-1);
    }
}
