#include <cstdio>
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long long lli;

int main()
{
    int n;
    scanf("%d", &n);
    int c2 = 0, c5 = 0;
    for(int i = 1; i <= n; i++)
    {
        int t = i;
        while(t % 2 == 0) { c2++; t /= 2; }
        while(t % 5 == 0) { c5++; t /= 5; }
    }

    printf("%d", min(c2, c5));
}
