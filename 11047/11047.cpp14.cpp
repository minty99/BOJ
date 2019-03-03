#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <stack>
#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;

stack<int> coin;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        coin.push(t);
    }

    int ans = 0;
    while(!coin.empty())
    {
        int t = coin.top();
        coin.pop();
        if(t > k) continue;
        ans += k / t;
        k %= t;
    }

    printf("%d", ans);
}
