#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v(n);
    unordered_map<int, string> m;
    for(int i = 0; i < n; i++)
    {
        int a;
        char c[105];
        scanf("%d %s", &a, c);
        v[i] = { a, i };
        string s(c);
        m[i] = c;
    }
    stable_sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        printf("%d %s\n", v[i].first, m[v[i].second].c_str());
    }
}