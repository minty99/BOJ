#include <stdio.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    long long t, n, a, b;
    scanf("%lld", &t);

    for(long long i = 1; i <= t; i++)
    {
        scanf("%lld %lld %lld", &n, &a, &b);
        long long m = min(a, b);
        while(true)
        {
            int count = 0;
            long long i = 1;
            for(i = 1; ; i*=2, count++)
            {
                if(i == m) { printf("%lld\n", n-count); break; }
                else if(i > m) { m -= i/2; break; }
            }
            if(i == m) break;
        }
    }
}
