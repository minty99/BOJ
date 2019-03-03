#include <cstdio>
#include <algorithm>
typedef long long lli;

int n, m, k;
lli arr[1200000];
lli tree[4000000];
using namespace std;

lli init(int node, int start, int end)
{
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
}

lli update(int node, int start, int end, int index, lli diff)
{
    if(start <= index && index <= end)
    {
        if(start == end) tree[node] = diff;
        if(start != end)
            tree[node] = min(update(node*2, start, (start+end)/2, index, diff), update(node*2+1, (start+end)/2+1, end, index, diff));
    }
    return tree[node];
}

lli query(int node, int start, int end, int left, int right)
{
    if(left <= start && end <= right) return tree[node];
    if(right < start || end < left) return 2e9;
    return min(query(node*2, start, (start+end)/2, left, right), query(node*2+1, (start+end)/2+1, end, left, right));
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    for(int i = 1; i <= n*4; i++) tree[i] = 2e9;

    init(1, 1, n);

    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
    {
        int x, a, b;
        scanf("%d %d %d", &x, &a, &b);
        if(x == 1) {
            update(1, 1, n, a, b);
        }
        if(x == 2) {
            printf("%lld\n", query(1, 1, n, a, b));
        }
    }
}
