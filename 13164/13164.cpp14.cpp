#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long lli;
int arr[304000];
int diff[304000];

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for(int i = 1; i < n; i++) diff[i] = arr[i+1] - arr[i];
    sort(diff+1, diff+n);
    int ans = arr[n] - arr[1];
    for(int i = 1; i <= k-1; i++) ans -= diff[n - i];
    printf("%d", ans);
}
