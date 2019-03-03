#include <stdio.h>

long long min(long long a, long long b) { return a < b ? a : b; }
int main()
{
    long long x, y, w, s;
    scanf("%lld %lld %lld %lld", &x, &y, &w, &s);

    if(x > y) { int t = x; x = y; y = t; }
    long long a1 = (x+y)*w;
    long long a2 = x*s + (((x-y)%2 == 0) ? ((y-x)*s) : ((y-x-1)*s+w));
    long long a3 = x*s + (y-x)*w;
    printf("%lld\n", min(min(a1, a2), a3));
}
