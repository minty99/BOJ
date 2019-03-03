#include <cstdio>
typedef long long lli;

lli fact(int n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fact(n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld", fact(n));
}