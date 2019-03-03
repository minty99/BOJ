#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define min3(a, b, c) (min((min((a), (b))), (c)))
int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    printf("%d", min3(a, b, c) + min(d, e) - 50);
}
