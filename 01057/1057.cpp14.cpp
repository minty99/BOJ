#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int count = 1;
    while(true)
    {
        if((a+1)/2 == (b+1)/2)
        {
            printf("%d", count);
            return 0;
        }
        if(a==b && a==1) break;
        count++;
        a++; a/=2;
        b++; b/=2;
    }
    printf("-1");
}