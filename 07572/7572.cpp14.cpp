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

    int n;
    scanf("%d", &n);

    if (n <= 2013)
    {
        char a = 'F';
        int b = 9;
        for (int i = 2012; i >= n; i--)
        {
            a--;
            b--;
            if (a < 'A')
                a = 'L';
            if (b < 0)
                b = 9;
        }
        printf("%c%d\n", a, b);
    }
    else
    {
        char a = 'F';
        int b = 9;
        for (int i = 2014; i <= n; i++)
        {
            a++;
            b++;
            if (a > 'L')
                a = 'A';
            if (b > 9)
                b = 0;
        }
        printf("%c%d\n", a, b);
    }
}