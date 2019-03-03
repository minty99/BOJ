#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a, b, k = 1;
        scanf("%d %d", &a, &b);
        for(int j = 1; j <= b; j++) k = (k*a)%10;
        if(k == 0) k = 10;
        printf("%d\n", k);
    }
}
