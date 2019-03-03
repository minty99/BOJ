#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    x /= 10;
    if(x == 10) x--;
    if(x < 6) x = 4;
    char k = 65 + (9 - x);
    printf("%c", k);
}
