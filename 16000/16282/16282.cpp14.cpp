#include <cstdio>
using namespace std;
typedef unsigned long long ulli;
typedef long long lli;

int main()
{
    // freopen("in.txt","r",stdin);
    lli n;
    scanf("%lld", &n);

    ulli curr = 2;
    for(int i = 1; i <= 63; i++)
    {
        if(n <= curr * i - 1)
        {
            printf("%d\n", i-1);
            return 0;
        }
        curr *= 2;
    }
}
