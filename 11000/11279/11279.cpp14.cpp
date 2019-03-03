#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

priority_queue<int> pq;

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
