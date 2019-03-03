#include <stdio.h>

int GCD(int a, int b)
{
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main()
{
    int a, b, G, L;
    scanf("%d %d", &a, &b);
    G = GCD(a, b);
    L = a*b/G;

    printf("%d\n%d\n", G, L);
}
