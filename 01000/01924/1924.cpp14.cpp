#include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char day[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int ans = 0;
    for(int i = 1; i <= 12; i++)
    {
        for(int j = 1; j <= arr[i]; j++)
        {
            ans++;
            ans %= 7;
            if(i == a && j == b)
            {
                printf("%s", day[ans]);
                return 0;
            }
        }
    }
}
