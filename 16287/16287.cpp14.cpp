#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int arr[10000];
vector<pii> v[1000000];
int main()
{
    // freopen("in.txt", "r", stdin);
    int w, n;
    scanf("%d %d", &w, &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(i == j) continue;
            v[arr[i] + arr[j]].emplace_back(i, j);
        }
    }

    for(int i = 1; i <= 400000; i++) sort(v[i].begin(), v[i].end());

    for(int i = 1; i <= w; i++)
    {
        int left = i;
        int right = w-i;
        if(left > right) break;

        if(v[left].size() >= 3 || v[right].size() >= 3)
        {
            if(v[left].size() == 0 || v[right].size() == 0) continue;
            else
            {
                puts("YES");
                return 0;
            }
        }

        for(int j = 0; j < v[left].size(); j++)
        {
            for(int k = 0; k < v[right].size(); k++)
            {
                if(v[left][j].first != v[right][k].first && v[left][j].first != v[right][k].second)
                {
                    if(v[left][j].second != v[right][k].first && v[left][j].second != v[right][k].second)
                    {
                        puts("YES");
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");
}