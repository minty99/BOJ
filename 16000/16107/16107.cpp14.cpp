#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long lli;

// 답이 10억을 넘지 않는다.
lli answer = 2e9;
lli memo[100000];
char s[100000];
int cnt = 0;
int len = 0;
// 0, 1, 4, 5, 6, 9
void calc(int idx, lli curr, lli ans)
{
    cnt++;
    // printf("%dth: %d %lld %lld\n", cnt, idx, curr, ans);
    if(curr > 100000000) return;
    if(curr >= answer) return;
    if(ans >= answer) return;
    if(curr == 0 and s[idx] == '0') return;
    while(true)
    {
        if(idx >= len) return;
        int last = s[idx] - '0';
        curr *= 10;
        curr += last;
        if(curr > 1000000000) return;
        if(last == 2 or last == 3 or last == 7 or last == 8) idx++;
        else break;
    }
    lli sq = (lli) sqrt(curr);
    if(curr != 0 && sq * sq == curr)
    {
        if(idx+1 >= len)
        {
            answer = min(ans+curr, answer);
            return;
        }
        if(memo[idx] > ans + curr)
        {
            memo[idx] = ans + curr;
            calc(idx+1, 0, ans + curr);
        }
    }
    if(idx+1 < len) calc(idx+1, curr, ans);
}

int main()
{
    // freopen("in.txt", "r", stdin);

    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < 100000; i++) memo[i] = 2e9;
    calc(0, 0, 0);
    if(answer > 1e9) answer = -1;
    printf("%lld", answer);
}
