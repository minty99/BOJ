#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int h[1000000];
int n;
lli m;

int BS(int left, int right)
{
    if(left == right) return left;
    int mid = (left + right + 1) / 2;
    lli sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(h[i] <= mid) continue;
        else sum += (lli) h[i] - (lli) mid;
    }

    if(sum >= m) return BS(mid, right);
    else return BS(left, mid-1);
}

int main()
{
    scanf("%d %lld", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]);
    printf("%d\n", BS(0, 1000000000));
}
