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

lli v[510];
inline double V(int st, int en, int sum)
{
    double avg = (double) sum / (en-st+1);
    double p = 0.0;
    for(int i = st; i <= en; i++) p += (v[i] - avg) * (v[i] - avg);
    return p / (en-st+1);
}

int main()
{
    // freopen("in.txt", "r", stdin);

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);

    double m = -1;
    for(int i = k; i <= n; i++)
    {
        lli sum = 0;
        for(int j = 1; j <= i; j++) sum += v[j];

        m = m == -1 ? V(1, i, sum) : min(m, V(1, i, sum));

        for(int j = 2; j+i-1 <= n; j++)
        {
            // j: start
            // range: j ~ j+i-1
            sum -= v[j-1];
            sum += v[j+i-1];
            m = min(m, V(j, j+i-1, sum));
        }
    }

    printf("%.11lf", sqrt(m));
}
