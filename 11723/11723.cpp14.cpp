#include <cstdio>
#include <iostream>
#include <cassert>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
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

bitset<21> bs;
int main()
{
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    char cmd[10];
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", cmd);
        string s(cmd);
        int k;
        if(s == "add")
        {
            scanf("%d", &k);
            bs[k] = true;
        }
        if(s == "remove")
        {
            scanf("%d", &k);
            bs[k] = false;
        }
        if(s == "check")
        {
            scanf("%d", &k);
            printf(bs[k] ? "1\n" : "0\n");
        }
        if(s == "toggle")
        {
            scanf("%d", &k);
            bs.flip(k);
        }
        if(s == "all") bs.set();
        if(s == "empty") bs.reset();
    }
}
