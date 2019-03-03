#include <stdio.h>

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);

    for(int i = l; i <= 100; i++)
    {
        int init = i*(i+1)/2;
        if(n < init - i) break;
        if((n - init) % i == 0)
        {
            for(int j = (n - init) / i + 1; j <= (n - init) / i + i; j++)
                printf("%d ", j);
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
}
