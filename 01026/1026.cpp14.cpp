#include <stdio.h>
#include <algorithm>
#define min(a, b) ((a) < (b) ? (a) : (b))
int a[100], b[100];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    std::sort(a+1, a+n+1);
    std::sort(b+1, b+n+1);

    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a[i] * b[n+1-i];
    printf("%d\n", sum);
}
