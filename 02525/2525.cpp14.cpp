#include <stdio.h>

int main()
{
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    b += t;
    while(b >= 60)
    {
        b -= 60;
        a++;
    }
    while(a >= 24) a -= 24;
    printf("%d %d", a, b);
}