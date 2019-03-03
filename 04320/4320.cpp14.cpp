#include <cstdio>
#include <cmath>
using namespace std;

typedef long long int lli;

long double process(lli left, lli right, long double target)
{
    long double mid = (left + right) / 2;
    long double l = log(mid);
    if(left == right && abs(l - target) < 1e-15) return mid;
    else if(left == right) return -1;

    if(target - l > 1e-15) return process(mid+1, right, target);
    else return process(left, mid, target);
}

int main()
{
    while(true)
    {
        lli n;
        scanf("%lld", &n);
        if(n == 0) break;

        long double lx = n > 0 ? log((long double) n) : log((long double) -n);
        int ans = 0;
        for(int p = 1; p <= 32; p++)
        {
            if(n < 0 and p % 2 == 0) continue;
            long double m = process(1, 4294967296LL, lx/p);
            if(m != -1) ans = p;
        }
        printf("%d\n", ans);
    }
}
