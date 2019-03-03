#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

vector<int> v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int left = 0, right = n - 1;
    int ans_x = 1e9, ans_y = 1e9, ans_abs = 2e9;
    while (v[left] <= 0 && left < right)
    {
        if (abs(v[left] + v[right]) < ans_abs)
        {
            ans_x = v[left];
            ans_y = v[right];
            ans_abs = abs(v[left] + v[right]);
        }
        if (abs(v[left] + v[right - 1]) < abs(v[left + 1] + v[right]))
            right--;
        else
            left++;
    }

    vector<pii> m;
    pii p1 = make_pair(v[0], v[1]);
    pii p2 = make_pair(v[n - 2], v[n - 1]);
    pii p3 = make_pair(ans_x, ans_y);
    pii p = min({p1, p2, p3}, [](const auto &a, const auto &b) {
        return abs(a.first + a.second) < abs(b.first + b.second);
    });
    printf("%d %d\n", p.first, p.second);
}
