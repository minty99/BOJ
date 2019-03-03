#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>
#include <array>
using namespace std;
typedef long long int lli;

array<lli, 4> x[120000], y[120000], z[120000];
vector<array<lli, 3>> idx(120000);

inline lli dist(array<lli, 4> a, array<lli, 4> b) {
    return min(min(abs(a[0] - b[0]), abs(a[1] - b[1])), abs(a[2] - b[2]));
}

void pq_add(priority_queue<array<lli, 3>, vector<array<lli, 3>>, greater<array<lli, 3>>> &pq, int st)
{
    pq.push({{dist(x[idx[st][0]], x[idx[st][0]+1]), st, x[idx[st][0]+1][3]}});
    pq.push({{dist(x[idx[st][0]], x[idx[st][0]-1]), st, x[idx[st][0]-1][3]}});
    pq.push({{dist(y[idx[st][1]], y[idx[st][1]+1]), st, y[idx[st][1]+1][3]}});
    pq.push({{dist(y[idx[st][1]], y[idx[st][1]-1]), st, y[idx[st][1]-1][3]}});
    pq.push({{dist(z[idx[st][2]], z[idx[st][2]+1]), st, z[idx[st][2]+1][3]}});
    pq.push({{dist(z[idx[st][2]], z[idx[st][2]-1]), st, z[idx[st][2]-1][3]}});
}

lli Prim(lli st, lli n) {
    // { weight, from, to }
    lli ret = 0;
    bitset<100001> bs;
    bs[0] = true;
    priority_queue<array<lli, 3>, vector<array<lli, 3>>, greater<array<lli, 3>>> pq;
    pq_add(pq, st);
    bs[st] = true;
    int vcnt = 1;
    while(vcnt < n)
    {
        array<lli, 3> edge = pq.top();
        pq.pop();
        if(edge[2] == 0 || bs[edge[2]]) continue;
        bs[edge[2]] = true;
        ret += edge[0];
        vcnt++;
        pq_add(pq, edge[2]);
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &x[i][0], &x[i][1], &x[i][2]);
        x[i][3] = i;
        y[i] = x[i];
        z[i] = x[i];
    }

    sort(x+1, x+n+1, [](array<lli, 4> a, array<lli, 4> b) {
        return a[0] < b[0];
    });

    sort(y+1, y+n+1, [](array<lli, 4> a, array<lli, 4> b) {
        return a[1] < b[1];
    });

    sort(z+1, z+n+1, [](array<lli, 4> a, array<lli, 4> b) {
        return a[2] < b[2];
    });

    for(int i = 1; i <= n; i++)
    {
        idx[x[i][3]][0] = i;
        idx[y[i][3]][1] = i;
        idx[z[i][3]][2] = i;
    }

    lli cost = Prim(1, n);
    printf("%lld", cost);
}
