#include <cstdio>
typedef long long lli;

lli arr[1200];
lli tree[5000];
int n, q;

lli init(int node, int start, int end)
{
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

void update(int node, int start, int end, int index, lli diff)
{
    if(start <= index && index <= end)
    {
        tree[node] += diff;
        if(start != end)
        {
            update(node*2, start, (start+end)/2, index, diff);
            update(node*2+1, (start+end)/2+1, end, index, diff);
        }
    }
}

lli sum(int node, int start, int end, int left, int right)
{
    if(left <= start && end <= right) return tree[node];
    if(right < start || end < left) return 0;
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

lli sum(int left, int right)
{
    return sum(1, 1, n, left, right);
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    init(1, 1, n);

    for(int i = 1; i <= q; i++)
    {
        lli x, a, b, c, d;
        scanf("%lld", &x);
        if(x == 1)
        {
            scanf("%lld %lld", &a, &b);
            printf("%lld\n", sum(a, b));
            update(1, 1, n, a, (arr[b] - arr[a]));
            update(1, 1, n, b, (arr[a] - arr[b]));
            int t = arr[a];
            arr[a] = arr[b];
            arr[b] = t;
        }
        if(x == 2)
        {
            scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
            printf("%lld\n", sum(a, b) - sum(c, d));
        }
    }
}
