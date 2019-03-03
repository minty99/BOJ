#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <array>
#define x first
#define y second
#define MOD 1000000007
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned long long int ulli;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> v;
    char s[110000];
    scanf("%s", s);
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        v.push_back(s[i]);

    int n;
    scanf("%d", &n);
    char tmp;
    scanf("%c", &tmp);
    auto cur = v.end();
    for (int i = 1; i <= n; i++)
    {
        char cmd[10];
        fgets(cmd, 10, stdin);
        if (cmd[0] == 'L')
        {
            if (cur != v.begin())
                cur--;
        }
        else if (cmd[0] == 'D')
        {
            if (cur != v.end())
                cur++;
        }
        else if (cmd[0] == 'B')
        {
            if (cur != v.begin())
                cur = v.erase(--cur);
        }
        else
        {
            v.insert(cur, cmd[2]);
        }
    }

    for (char c : v)
        printf("%c", c);
    puts("");
}