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
#include <sstream>
#include <bitset>
#include <random>
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
    // freopen("in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        lli k;
        scanf("%lld", &k);
        if(k % 2 == 0) { puts("NO"); continue; }
        bool flag = true;
        for(int j = 3; j <= 1000000; j += 2)
        {
            if(k % j == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
}
