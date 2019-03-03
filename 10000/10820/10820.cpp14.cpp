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

    char s[120];
    while (fgets(s, 120, stdin) != NULL)
    {
        int a = 0, b = 0, c = 0, d = 0;
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            char t = s[i];
            if ('a' <= t and t <= 'z')
                a++;
            if ('A' <= t and t <= 'Z')
                b++;
            if ('0' <= t and t <= '9')
                c++;
            if (t == ' ')
                d++;
        }
        printf("%d %d %d %d\n", a, b, c, d);
    }
}