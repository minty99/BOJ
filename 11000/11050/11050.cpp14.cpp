#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    long long ans = 1;
    for(int i = 1; i <= k; i++)
        ans *= (n - i + 1);

    for(int i = 1; i <= k; i++) ans /= i;
    printf("%lld", ans);
}
