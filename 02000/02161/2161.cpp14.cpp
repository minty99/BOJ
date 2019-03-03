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
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) Q.push(i);

    while(Q.size() > 1)
    {
        printf("%d ", Q.front());
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    printf("%d", Q.front());
}
