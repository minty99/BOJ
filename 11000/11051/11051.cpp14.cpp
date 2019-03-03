#include <cstdio>
typedef long long lli;
lli C[1200][1200];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    C[1][0] = 1;
    C[1][1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            C[i][j] %= 10007;
        }
    }
    printf("%lld", C[n][k]);
}
