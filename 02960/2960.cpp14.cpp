#include <stdio.h>

bool flag[1001];
int count;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 2; i <= n; i++) flag[i] = false;
    for(int i = 2; i <= n; i++)
    {
        if(flag[i] == false)
        {
            for(int j = i; j <= n; j += i)
            {
                if(flag[j] == false) k--;
                if(k == 0)
                {
                    printf("%d\n", j);
                    return 0;
                }
                flag[j] = true;
            }
        }
    }
}
