// PORORO TEAM
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
pair <int, pair<int, int> > a[1001][1001], b[1001][1001];
int n, m, check[1001][1001];
long long int sum, ans;

int main(){
    int i, j, x;

    scanf("%d %d", &n, &m);

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
        {
            scanf("%d", &x);

            sum += x;

            a[i][j].first = x;
            b[j][i].first = x;
            a[i][j].second.first = i;
            a[i][j].second.second = j;
            b[j][i].second.first = j;
            b[j][i].second.second = i;
        }
    }


    for(i=1 ; i<=n ; i++)
    {
        sort(a[i]+1, a[i]+m+1);

        ans += a[i][m].first;
        check[a[i][m].second.first][a[i][m].second.second] = 1;
    }


    for(i=1 ; i<=m ; i++)
    {
        sort(b[i]+1, b[i]+n+1);

        if(check[b[i][n].second.second][b[i][n].second.first]==0)
        {
            ans += b[i][n].first;
        }
    }

    printf("%lld", sum - ans);

    return 0;
}
