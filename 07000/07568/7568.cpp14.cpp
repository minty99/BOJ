#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pii> v;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    
    for(int i = 0; i < n; i++)
    {
        int ans = 0;
        for(int j = 0; j < n; j++)
        {
        	if(i == j) continue;
        	if(v[j].first > v[i].first && v[j].second > v[i].second) ans++;
        }
        printf("%d ", ans+1);
    }
}