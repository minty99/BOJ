#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int main()
{
    int n, m;
    vector<int> v1, v2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        v1.push_back(t);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        v2.push_back(t);
    }

    sort(v1.begin(), v1.end());

    for(int i = 0; i < m; i++)
    {
        if(binary_search(v1.begin(), v1.end(), v2[i]))
            printf("1 ");
        else printf("0 ");
    }
}
