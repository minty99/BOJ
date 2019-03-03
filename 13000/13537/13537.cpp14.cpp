#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

vector<int> v;
vector<int> tree[500000];

// node: 노드 번호, start~end: node가 담당하는 구간
// O(2n log 2n) (?)
void init(int node, int start, int end)
{
    for(int i = start; i <= end; i++) tree[node].push_back(v[i]);
    sort(tree[node].begin(), tree[node].end());

    if(start == end) return;
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
}

int query(int node, int start, int end, int left, int right, int k)
{
    int ans = 0;
    if(end < left) return 0;
    if(right < start) return 0;
    if(left <= start && end <= right)
    {
        int idx = upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        ans = tree[node].size() - idx;
        return ans;
    }
    ans += query(node*2, start, (start+end)/2, left, right, k);
    ans += query(node*2+1, (start+end)/2+1, end, left, right, k);
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    init(1, 0, n-1);

    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", query(1, 0, n-1, a-1, b-1, c));
    }
}
