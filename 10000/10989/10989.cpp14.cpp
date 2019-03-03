#include <stdio.h>

int arr[10001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        arr[t]++;
    }
    
    for(int i = 0; i <= 10000; i++)
    {
        for(int j = 1; j <= arr[i]; j++) printf("%d\n", i);
    }
}