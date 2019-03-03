#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long lli;
int n;
lli a[10001];

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    sort(a+1, a+n+1);

    int zero = -1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] < 0 && a[i+1] >= 0) zero = i+1;
    }
    lli b[7];
    b[1] = a[1];
    b[2] = a[2];
    b[3] = a[3];
    b[4] = a[n-2];
    b[5] = a[n-1];
    b[6] = a[n];

    if(n == 3) b[4] = b[5] = b[6] = -99999;
    if(n == 4) b[4] = b[5] = -99999;
    if(n == 5) b[4] = -99999;

    // n >= 6
    lli mul = a[1] * a[2] * a[3];
    for(int i = 1; i <= 6; i++)
    {
        for(int j = i+1; j <= 6; j++)
        {
            for(int k = j; k <= 6; k++)
            {
                if(k == j)
                {
                    if(b[i] == -99999 || b[j] == -99999) continue;
                    mul = max(mul, b[i] * b[j]);
                    continue;
                }
                if(b[i] == -99999 || b[j] == -99999 || b[k] == -99999) continue;
                mul = max(mul, b[i] * b[j] * b[k]);
                // printf("mul = %lld, %d, %d, %d\n", mul, b[i], b[j], b[k]);
            }
        }
    }
    if(zero != -1)
    {
        mul = zero <= 2 ? mul : max(mul, a[zero-1] * a[zero-2]);
        mul = zero <= 3 ? mul : max(mul, a[zero-1] * a[zero-2] * a[zero-3]);
    }

    printf("%lld\n", mul);
}
