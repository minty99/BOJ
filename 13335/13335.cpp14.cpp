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

int arr[1100];

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, w, L;
    scanf("%d %d %d", &n, &w, &L);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    queue<pii> q;
    int next = 1;
    int curr = 0;
    int t = 0;
    while(next <= n or !q.empty())
    {
        t++;
        while(!q.empty() and q.front().y == t)
        {
            pii p = q.front();
            curr -= p.x;
            q.pop();
        }
        if(q.size() == L) continue;
        else if(next <= n and curr + arr[next] <= L)
        {
            curr += arr[next];
            q.emplace(arr[next++], t+w);
        }
    }
    printf("%d", t);
}
