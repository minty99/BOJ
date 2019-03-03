#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long lli;
lli arr[310000];
int main()
{
    // freopen("in.txt", "r", stdin);

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    sort(arr+1, arr+n+1);

    lli ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int mul = min(i-1, k);
        ans += arr[i] * mul;
    }
    printf("%lld", ans);
}
