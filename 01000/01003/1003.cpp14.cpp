#include <stdio.h>

int c0 = 0;
int c1 = 0;
int memo[41][2];
void fibonacci(int n) {
    for(int i = 0; i <= n; i++)
    {
        if (i==0)
        {
            memo[i][0] = 1;
            memo[i][1] = 0;
        }
        else if (i==1)
        {
            memo[i][0] = 0;
            memo[i][1] = 1;
        }
        else
        {
            memo[i][0] = memo[i-1][0] + memo[i-2][0];
            memo[i][1] = memo[i-1][1] + memo[i-2][1];
        }
    }

}

int main()
{
    int t;
    scanf("%d", &t);
    fibonacci(40);
    for(int i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", memo[n][0], memo[n][1]);
    }
}
