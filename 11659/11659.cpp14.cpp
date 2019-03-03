#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

vector<int> arr;
int init(vector<int> &v, int node, vector<int> &arr, int left, int right)
{
    if(left == right)
    {
        v[node] = arr[left];
        return v[node];
    }
    else
    {
        int mid = (left + right) / 2;
        v[node] = init(v, node*2, arr, left, mid) + init(v, node*2+1, arr, mid+1, right);
        return v[node];
    }
}

void update(vector<int> &v, int size, int idx, int diff)
{
    int node = 1;
    int left = 1;
    int right = size;
    while(left != right)
    {
        int mid = (left + right) / 2;
        if(left <= idx && idx <= mid) { node *= 2; right = mid; }
        else { node *= 2; node++; left = mid+1; }
    }

    v[node] += diff;
    node /= 2;
    while(node > 0)
    {
        v[node] = v[node*2] + v[node*2+1];
        node /= 2;
    }
}

int getVal(vector<int> &v, int node, int left, int right, int idxL, int idxR)
{
    int mid = (left + right) / 2;
    if(left > idxR || right < idxL) return 0;
    if(idxL <= left && right <= idxR) return v[node];
    return getVal(v, node*2, left, mid, idxL, idxR) + getVal(v, node*2+1, mid+1, right, idxL, idxR);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    arr.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        arr.push_back(t);
    }

    vector<int> v(4*n);
    init(v, 1, arr, 1, n);

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", getVal(v, 1, 1, n, a, b));
    }
}
