#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
typedef long long lli;

int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    int k = 0;
    int now = 1;
    while(t > 0)
    {
        k += now * (t % 9);
        t /= 9;
        now *= 10;
    }
    printf("%d", k);
}
