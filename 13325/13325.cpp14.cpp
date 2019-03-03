#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <array>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int tree[2200000];
int diff[2200000];
int M = 0;
int k;
void DFS(int idx, int depth, int curr)
{
    if(depth < k)
    {
        DFS(idx*2, depth+1, curr+tree[idx]);
        DFS(idx*2+1, depth+1, curr+tree[idx]);
    }
    else
    {
        M = max(curr+tree[idx], M); 
        diff[idx] = curr+tree[idx];
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &k);
    int ans = 0;
    int n = (1 << (k+1)) - 1;
    for(int i = 2; i <= n; i++)
    {
        scanf("%d", &tree[i]);
        ans += tree[i];
    }
    DFS(1, 0, 0);

    int leaf = n / 2 + 1;
    for(int i = leaf; i <= n; i++) diff[i] = M - diff[i];
    int left = leaf, right = n;

    // O(n)
    while(left > 1)
    {
        for(int i = left; i <= right; i += 2)
        {
            diff[i/2] = min(diff[i], diff[i+1]);
            diff[i] -= diff[i/2];
            diff[i+1] -= diff[i/2];
        }
        right = left-1;
        left /= 2;
    }

    for(int i = 2; i <= n; i++) ans += diff[i];
    printf("%d", ans);
}
