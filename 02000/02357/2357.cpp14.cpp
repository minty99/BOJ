#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

#define INF 2100000000
pii tree[400000];
int arr[120000];
int n, m;

pii init(int node, int start, int end)
{
    if(start == end) return tree[node] = make_pair(arr[start], arr[start]);
    else
    {
        pii a = init(node*2, start, (start+end)/2);
        pii b = init(node*2+1, (start+end)/2+1, end);
        return tree[node] = make_pair(max(a.first, b.first), min(a.second, b.second));
    }
}

pii update(int node, int start, int end, int index, int newval)
{
    if(start <= index && index && end)
    {
        if(start == end) return tree[node] = make_pair(newval, newval);
        else
        {
            pii a = update(node*2, start, (start+end)/2, index, newval);
            pii b = update(node*2+1, (start+end)/2+1, end, index, newval);
            return tree[node] = make_pair(max(a.first, b.first), min(a.second, b.second));
        }
    }
    return make_pair(0, INF);
}

int get_max(int node, int start, int end, int left, int right)
{
    if(left <= start && end <= right) return tree[node].first;
    if(right < start || end < left) return 0;
    if(start == end) return tree[node].first;
    return max(get_max(node*2, start, (start+end)/2, left, right), get_max(node*2+1, (start+end)/2+1, end, left, right));
}

int get_min(int node, int start, int end, int left, int right)
{
    if(left <= start && end <= right) return tree[node].second;
    if(right < start || end < left) return INF;
    if(start == end) return tree[node].second;
    return min(get_min(node*2, start, (start+end)/2, left, right), get_min(node*2+1, (start+end)/2+1, end, left, right));
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    init(1, 1, n);

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %d\n", get_min(1, 1, n, a, b), get_max(1, 1, n, a, b));
    }

}
