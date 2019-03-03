#include <cstdio>
#include <vector>
using namespace std;

int G[16][16];

int solve(int);
int fill(int, int);
vector<int> add(int, int);
bool isLegal(int, int, int);
bool exist[16];
int status[16];
int st_size = 0;

int solve(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 0;
    int answer = 0;
    for(int sy = 1; sy <= n; sy++)
    {
        G[1][sy] = 1;
        exist[sy] = true;
        status[st_size++] = sy;
        answer += fill(2, n);
        G[1][sy] = 0;
        exist[sy] = false;
        st_size--;
    }
    return answer;
}

int fill(int stage, int sz)
{
    int ret = 0;
    vector<int> v = add(stage, sz);
    if(stage == sz) return v.size();

    int s = v.size();
    for(int i = 0; i < s; i++)
    {
        G[stage][v[i]] = 1;
        status[st_size++] = v[i];
        exist[v[i]] = true;
        int ok = fill(stage+1, sz);
        ret += ok;
        exist[v[i]] = false;
        st_size--;
        G[stage][v[i]] = 0;
    }
    return ret;
}

inline vector<int> add(int x, int sz)
{
    vector<int> ret;
    for(int y = 1; y <= sz; y++)
    {
        if(!exist[y] && isLegal(x, y, sz)) ret.emplace_back(y);
    }
    return ret;
}

inline bool isLegal(int x, int y, int sz)
{
    for(int z = 0; z < st_size; z++)
    {
        int i = z+1, j = status[z];
        if(i - j == x - y) return false;
        if(i + j == x + y) return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", solve(n));
}
