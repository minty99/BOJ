#include <stdio.h>

int main()
{
    int n, m, arr[301][301], k;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) scanf("%d", &arr[i][j]);

    scanf("%d", &k);

    for(int i = 1; i <= k; i++)
    {
        int a, b, x, y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        int sum = 0;
        for(int j = a; j <= x; j++)
            for(int k = b; k <= y; k++)
                sum += arr[j][k];
        printf("%d\n", sum);
    }
}
