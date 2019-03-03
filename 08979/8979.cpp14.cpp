#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, k;
    scanf("%d %d", &n, &k);
    pair<long long, int> p[1001];

    for(int i = 1; i <= n; i++)
    {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        long long e = b*1000001*1000001+c*1000001+d;
        p[i] = { -e, a };
    }
    sort(p+1, p+n+1);

    for(int i = 1; i <= n; i++)
    {
        if(p[i].second == k)
        {
            while(i > 1 && p[i-1].first == p[i].first) i--;
            printf("%d", i);
            return 0;
        }
    }
}
