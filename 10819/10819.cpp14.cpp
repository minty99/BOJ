#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int ans = 0;
    do {
        int s = 0;
        for(int i = 0; i < n-1; i++)
            s += abs(v[i] - v[i+1]);
        ans = max(ans, s);
    } while(next_permutation(v.begin(), v.end()));

    printf("%d", ans);
}