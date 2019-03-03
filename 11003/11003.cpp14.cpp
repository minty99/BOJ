#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
typedef long long lli;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        pq.emplace(a, i);

        while(!(i - l + 1 <= pq.top().second && pq.top().second <= i)) pq.pop();
        printf("%d ", pq.top().first);
    }
}
