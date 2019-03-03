#include <stdio.h>

int main()
{
    int tot, t;
    scanf("%d", &tot);
    for(int i = 1; i <= 9; i++)
    {
        scanf("%d", &t);
        tot -= t;
    }
    printf("%d", tot);
}
