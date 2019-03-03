#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int n, m, k;
vector<int> arr;
int tree[500000];

int init(int node, int start, int end)
{
    if(start == end) return tree[node] = arr[start];
    else return tree[node] = min(init(node*2, start, (start+end)/2), init(node*2+1, (start+end)/2+1, end));
}

void update(int node, int start, int end, int index, int newvalue)
{
    if(start <= index && index <= end)
    {
        tree[node] = min(tree[node], newvalue);
        if(start != end)
        {
            update(node*2, start, (start+end)/2, index, newvalue);
            update(node*2+1, (start+end)/2+1, end, index, newvalue);
        }
    }
}

int get_min(int node, int start, int end, int left, int right)
{
    if(left <= start && end <= right) return tree[node];
    if(right < start || end < left) return 1100000000;
    return min(get_min(node*2, start, (start+end)/2, left, right), get_min(node*2+1, (start+end)/2+1, end, left, right));
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);

    int size = 1 << (int)ceil(log2(n)+1);

    arr.push_back(1100000000);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        arr.push_back(t);
    }

    while(arr.size() < size+1) arr.push_back(1100000000);

    n = size/2;
    init(1, 1, n);

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", get_min(1, 1, n, a, b));
    }
}
