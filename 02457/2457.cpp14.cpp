#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> f[100002];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        f[i].first = 100*a + b;
        f[i].second = 100*c + d;
    }
    f[n+1] = { 1201, 1231 };
    sort(f+1, f+n+1);

    int last = 301;
    int ans = 0;
    int M = 0;
    for(int i = 1; i <= n+1; i++)
    {
        if(last < f[i].first)
        {
            ans++;
            last = M;
            M = 0;
        }
        if(f[i].first <= last && last < f[i].second) M = max(M, f[i].second);
        // printf("%d %d %d\n", last, ans, M);
    }

    if(last <= 1130) ans = 0;
    printf("%d", ans);
}
