#include <cstdio>
typedef long long lli;

int n, m, k;
lli arr[1100000];
lli tree[4400000];
lli lazy[4400000];

lli init(int node, int start, int end)
{
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

void update_lazy(int node, int start, int end)
{
    tree[node] += lazy[node] * (end - start + 1);
    if(start != end)
    {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int left, int right, lli diff)
{
    update_lazy(node, start, end);
    if(right < start || end < left) return;
    if(left <= start && end <= right)
    {
        tree[node] += diff * (end - start + 1);
        if(start != end)
        {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
    }
    else
    {
        update(node*2, start, (start+end)/2, left, right, diff);
        update(node*2+1, (start+end)/2+1, end, left, right, diff);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

lli sum(int node, int start, int end, int left, int right)
{
    update_lazy(node, start, end);
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    init(1, 1, n);

    for(int i = 1; i <= m+k; i++)
    {
        int a, b, c;
        lli d;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1)
        {
            scanf("%lld", &d);
            update(1, 1, n, b, c, d);
        }
        if(a == 2) printf("%lld\n", sum(1, 1, n, b, c));
    }
}
