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

vector<int> v[110000];
vector<int> w[110000];
lli answer = 0;
bool visited[110000];
lli tw[110000][2];

// S = d1 + d2 + ... + dn
// SQ = d1^2 + d2^2 + ... + dn^2
// tw[idx][0] = S % MOD
// tw[idx][1] = [(S * S - SQ) / 2] % MOD
lli DFS(int idx)
{
    visited[idx] = true;
    lli sq = 0;
    for(int i = 0; i < v[idx].size(); i++)
    {
        if(visited[v[idx][i]]) continue;
        lli diff = (DFS(v[idx][i]) + 1) % MOD * w[idx][i] % MOD;
        tw[idx][0] += diff;
        sq += diff * diff;
        tw[idx][0] %= MOD;
        sq %= MOD;
    }

    // tw[idx][1] = (tw[idx][0] * tw[idx][0] - sq) / 2;
    // tw[idx][1] = (tw[idx][0] * tw[idx][0] - sq) * 500000004;
    tw[idx][1] = (tw[idx][0] % MOD * tw[idx][0] % MOD * 500000004 % MOD) + MOD - (sq % MOD * 500000004 % MOD);
    tw[idx][1] %= MOD;
    return tw[idx][0];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n-1; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(b);
        v[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    DFS(1);
    // tw[i][0]: i에서 시작하고, 경유하는 정점 중 i가 최대 높이인 경로들의 가중치 총합
    // tw[i][1]: i를 경유하고, 경유하는 정점 중 i가 최대 높이인 경로들의 가중치 총합
    lli answer = 0;
    for(int i = 1; i <= n; i++)
    {
        answer += tw[i][0] + tw[i][1];
        answer %= MOD;
    }
    printf("%lld", answer);
}
