#include <cstdio>
int arr[1001];
int main()
{
    int p = 1;
    for(int i = 1; p <= 1000; i++)
    {
        for(int j = 1; j <= i; j++) arr[p++] = i;
    }
    
    int a, b;
    scanf("%d %d", &a, &b);
    int s = 0;
    for(int i = a; i <= b; i++) s += arr[i];
    printf("%d", s);
}