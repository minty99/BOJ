#include <stdio.h>

int arr[2000001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        arr[1000000+t]++;
    }
    
    for(int i = 0; i <= 2000000; i++)
    {
        if(arr[i] != 0) printf("%d\n", i-1000000);
    }
}