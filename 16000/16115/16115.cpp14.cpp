#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lli;

lli dist(lli x, lli y)
{
    return x*x + y*y;
}
long double PI = 3.14159265358979;

lli a[310000], b[310000];
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    lli M = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld %lld", &a[i], &b[i]);
        M = max(M, dist(a[i], b[i]));
    }

    vector<long double> v;
    for(int i = 1; i <= n; i++)
    {
        if(dist(a[i], b[i]) == M)
        {
            long double deg = 180.0 / PI * acos((long double)a[i] / sqrt(M));
            if(a[i] <= 0 && b[i] < 0) deg = 360 - deg;
            if(a[i] > 0 && b[i] < 0) deg = 360 - deg;
            v.push_back(deg);
            //printf("%Lf\n", v.back());
        }
    }
    sort(v.begin(), v.end());
    long double ans = 0;
    for(int i = 0; i < v.size()-1; i++)
    {
        ans = max(ans, abs(v[i+1] - v[i]));
    }
    ans = max(ans, 360 + v[0]- v.back());
    printf("%.12Lf", ans);
}
