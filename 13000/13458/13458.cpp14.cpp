#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[1000001];
int b, c;
int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    for(int i = 1; i <= n; i++) { a[i] -= b; if(a[i] < 0) a[i] = 0; }
    sort(a+1, a+n+1);

    long long answer = n;
    for(int i = 1; i <= n; i++)
    {
        answer += a[i] / c;
        if(a[i] % c != 0) answer += 1;
    }

    printf("%lld", answer);
}