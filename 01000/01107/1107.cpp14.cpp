#include <stdio.h>
#include <math.h>
#include <limits.h>

int n, m, num[10];  // num: 고장난 버튼은 1
bool isValid(int n);
int min(int a, int b);

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int t;
        scanf("%d", &t);
        num[t]++;
    }

    int a0 = -1, a1 = -1, a2 = -1;

    if(n >= 100) a0 = n - 100;
    else a0 = 100 - n;
    if(m == 10) { printf("%d\n", a0); return 0; }

    for(int i = n; i >= 0; i--) // MAX: 500000
    {
        if(isValid(i)) { a1 = i; break; }
    }
    int ans1 = -1, ans2 = -1;
    if(a1 > 0) ans1 = (int)(log10(a1)) + 1 + (n - a1);
    else if(a1 == 0) ans1 = 1 + n - a1;
    else ans1 = INT_MAX;

    for(int i = n; i <= n+(a0 < ans1 ? a0 : ans1); i++)
    {
        if(isValid(i)) { a2 = i; break; }
    }
    if(a2 > 0) ans2 = (int)(log10(a2)) + 1 + (a2 - n);
    else if(a2 == 0) ans2 = 1 + n - a2;
    else ans2 = INT_MAX;

    printf("%d\n", min(min(a0, ans1), ans2));
}

bool isValid(int n)
{
    if(n == 0) return num[0] == 0 ? true : false;
    for(int i = 1; ; i *= 10)
    {
        if(n/i == 0) break;
        int k = (n/i)%10;
        if(num[k] == 1) return false;
    }
    return true;
}

int min(int a, int b) { return a < b ? a : b; }
