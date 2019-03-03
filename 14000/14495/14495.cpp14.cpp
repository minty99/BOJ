#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
typedef long long lli;

lli memo[120];
lli yusa_fibo(int n)
{
    if(n <= 3) return 1;
    if(memo[n] != 0) return memo[n];
    lli k = yusa_fibo(n-1) + yusa_fibo(n-3);
    memo[n] = k;
    return memo[n];
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    memo[1] = memo[2] = memo[3] = 1;

    printf("%lld", yusa_fibo(n));
}
