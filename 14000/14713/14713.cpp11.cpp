#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <functional>

using namespace std;
typedef long long lli;

string s[101][101];
size_t table[101][101];
queue<size_t> que[101];
int n;
std::hash<std::string> hash_fn;
char tt[1000000];

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    gets(tt);
    for(int i = 1; i <= n; i++)
    {
        gets(tt);
        string t = tt;
        int start = 0, end;
        for(int j = 1; ; j++)
        {
            end = t.find(" ", start);
            if(end == -1) end = t.length();
            s[i][j] = t.substr(start, end-start);
            table[i][j] = hash_fn(s[i][j]);
            que[i].push(table[i][j]);
            start = end+1;
            if(end == -1) break;
            if(start >= t.length()) break;
        }
    }

    gets(tt);
    string l = tt;
    int start = 0, end = 0;
    while(end >= 0)
    {
        end = l.find(" ", start);
        if(end == -1) end = l.length();
        string sub = l.substr(start, end-start);
        size_t hsh = hash_fn(sub);
        bool flag = false;
        for(int j = 1; j <= n; j++)
        {
            if(que[j].front() == hsh) { que[j].pop(); flag = true; break; }
        }
        if(!flag) { printf("Impossible"); return 0; }
        start = end+1;
        if(end == -1) break;
        if(start >= l.length()) break;
    }

    for(int i = 1; i <= n; i++)
    {
        if(que[i].size() > 0) { printf("Impossible"); return 0; }
    }
    printf("Possible");
}
