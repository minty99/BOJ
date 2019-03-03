#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int arr[1000001];    // 0 unused

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 2; i <= n; i++)
    {
        int a1, a2, a3;
        a1 = i%3 == 0 ? arr[i/3]+1 : 987654321;
        a2 = i%2 == 0 ? arr[i/2]+1 : 987654321;
        a3 = arr[i-1]+1;
        arr[i] = min(min(a1, a2), a3);
    }

    printf("%d\n", arr[n]);
}
