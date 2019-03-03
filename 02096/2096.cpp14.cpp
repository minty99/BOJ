#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int n;
int maxdp[4];
int mindp[4];
int newdp[4];
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        newdp[1] = max(maxdp[1], maxdp[2]) + a;
        newdp[2] = max(max(maxdp[1], maxdp[2]), maxdp[3]) + b;
        newdp[3] = max(maxdp[2], maxdp[3]) + c;
        maxdp[1] = newdp[1];
        maxdp[2] = newdp[2];
        maxdp[3] = newdp[3];

        newdp[1] = min(mindp[1], mindp[2]) + a;
        newdp[2] = min(min(mindp[1], mindp[2]), mindp[3]) + b;
        newdp[3] = min(mindp[2], mindp[3]) + c;
        mindp[1] = newdp[1];
        mindp[2] = newdp[2];
        mindp[3] = newdp[3];
    }

    printf("%d %d", max(max(maxdp[1], maxdp[2]), maxdp[3]), min(min(mindp[1], mindp[2]), mindp[3]));
}
