#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    setbuf(stdout, NULL);
    #endif

    int n, L;
    scanf("%d", &n);
    v.resize(n);
    vector<int> li;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = { min(a, b), max(a, b) };
        li.push_back(a);
        li.push_back(b);
    }
    scanf("%d", &L);
    sort(v.begin(), v.end());
    sort(li.begin(), li.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq1, pq2;
    int st, en;
    int idx = 0;
    int M = 0;
    for(int i = 0; i < li.size(); i++)
    {
        st = li[i];
        en = st + L;

        while(idx < n and v[idx].x <= en)
        {
            pq1.emplace(v[idx].y, v[idx].x);
            idx++;
        }

        while(!pq1.empty() and pq1.top().x <= en)
        {
            pii p = pq1.top();
            pq1.pop();
            pq2.emplace(p.y, p.x);
        }

        while(!pq2.empty() and pq2.top().x < st) pq2.pop();
        M = max(M, (int) pq2.size());
    }

    printf("%d", M);
}
