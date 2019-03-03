#include <stdio.h>

bool flag[10001];
int d(int n)
{
    int ret = n;
    while(n > 0)
    {
        ret += (n % 10);
        n /= 10;
    }
    return ret;
}

int main()
{
    for(int i = 1; i <= 10000; i++)
    {
        int x = d(i);
        if(x > 10000) continue;
        flag[d(i)] = true;
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(!flag[i]) printf("%d\n", i);
    }
}
