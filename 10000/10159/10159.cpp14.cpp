#include <cstdio>
#include <algorithm>
using namespace std;
int arr[101][101];
int arr2[101][101];
int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            arr[i][j] = arr2[i][j] = 10000;

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr2[b][a] = 1;
    }

    for(int k = 1; k <= n; k++)
        for(int j = 1; j <= n; j++)
            for(int i = 1; i <= n; i++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                arr2[i][j] = min(arr2[i][j], arr2[i][k] + arr2[k][j]);
            }

    for(int i = 1; i <= n; i++)
    {
        int ans = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i != j && arr[i][j] == 10000 && arr2[i][j] == 10000) ans++;
        }
        printf("%d\n", ans);
    }
}
