#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

auto comp = [](int a, int b) { if(abs(a) != abs(b)) return abs(a) > abs(b); else return a > b; };
priority_queue<int, vector<int>, decltype(comp)> pq(comp);

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if(x == 0)
        {
            if(pq.size() > 0)
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else printf("0\n");
        }
        else pq.push(x);
    }
}
