#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>

#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int t;
long long p[101];
int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &t);
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    for(int i = 6; i <= 100; i++) p[i] = p[i-1] + p[i-5];
    while(t > 0)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", p[n]);
        t--;
    }
}
