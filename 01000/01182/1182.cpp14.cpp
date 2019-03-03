#include <cstdio>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, s;
    scanf("%d %d", &n, &s);
    int arr[21];
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    int ans = 0;
    for(int i = 1; i < (1 << n); i++)
    {
        int sum = -2e9;
        for(int j = 1; j <= n; j++)
        {
            if((i & (1 << (j-1))) > 0)
            {
                if(sum == -2e9) sum = 0;
                sum += arr[j];
            }
        }
        if(sum == s) ans++;
    }
    printf("%d", ans);
}
