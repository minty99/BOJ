#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

// arr[k]: min+k
int arr[1100000];

int main()
{
    lli m, M;
    scanf("%lld %lld", &m, &M);

    for(lli i = 2; i*i <= M; i++)
    {
        lli sq = i*i;
        for(lli j = m/sq - 1; j <= M/sq + 1; j++)
        {
            if(m <= j*sq && j*sq <= M) arr[j*sq - m] = 1;
        }
    }

    int ans = 0;
    for(lli i = m; i <= M; i++)
    {
        if(arr[i - m] == 0) ans++;
    }
    printf("%d", ans);
}
