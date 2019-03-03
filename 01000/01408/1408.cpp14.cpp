#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

queue<int> Q;
int main()
{
    int a, b, c;
    scanf("%d:%d:%d", &a, &b, &c);
    int d, e, f;
    scanf("%d:%d:%d", &d, &e, &f);

    int h = d-a, m = e-b, s = f-c;

    while(s < 0) { m--; s += 60; }
    while(m < 0) { h--; m += 60; }
    while(h < 0) { h += 24; }
    printf("%02d:%02d:%02d", h, m, s);
}
