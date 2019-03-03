#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> pii;
using namespace std;

int main()
{
        int n;
        scanf("%d", &n);
        vector<pii> v(n);

        for(int i = 0; i < n; i++)
                scanf("%d %d", &v[i].first, &v[i].second);
        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++)
                printf("%d %d\n", v[i].first, v[i].second);
}