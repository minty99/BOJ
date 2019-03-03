#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    vector<int> up(n), down(n);

    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        if(i == 0) { up[i] = 1; down[i] = 1; continue; }
        up[i] = v[i] >= v[i-1] ? up[i-1]+1 : 1;
        down[i] = v[i] <= v[i-1] ? down[i-1]+1 : 1;
        ans = max(ans, up[i]);
        ans = max(ans, down[i]);
    }
    printf("%d", ans);
}
