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
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    vector<int> v(n);
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    priority_queue<pii> Q;

    for(int i = n-1; i >= 0; i--)
    {
        while(!Q.empty())
        {
            int idx = Q.top().second;
            int val = -Q.top().first;
            // printf("Queue top: idx = %d val = %d\n", idx, val);
            if(val < v[i])
            {
                ans[idx] = i+1;
                Q.pop();
            }
            else break;
        }
        Q.emplace(-v[i], i);
    }

    for(int i = 0; i < n; i++) printf("%d ", ans[i]);
}
