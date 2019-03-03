#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> parent(100000);
vector<int> height(100000);
vector<int> sz(100000);
unordered_map<string, int> m;

int _find(int a)
{
    if(parent[a] == a) return a;
    else return parent[a] = _find(parent[a]);
}

void _union(int a, int b)
{
    a = _find(a);
    b = _find(b);
    if(a == b) return;

    if(height[a] > height[b]) { int t = a; a = b; b = t; }

    parent[a] = b;
    sz[b] += sz[a];
    if(height[a] == height[b]) height[b]++;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t --> 0)
    {
        int f;
        scanf("%d", &f);
        m.clear();
        for(int i = 1; i <= f; i++)
        {
            char a[25], b[25];
            scanf("%s %s", a, b);
            string s1(a);
            string s2(b);
            if(m.find(s1) == m.end())
            {
                int k = m.size();
                m.insert({s1, k});
                parent[k] = k;
                height[k] = 1;
                sz[k] = 1;
            }
            if(m.find(s2) == m.end())
            {
                int k = m.size();
                m.insert({s2, k});
                parent[k] = k;
                height[k] = 1;
                sz[k] = 1;
            }

            _union(m[s1], m[s2]);
            printf("%d\n", sz[_find(m[s1])]);
        }
    }
}
