#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int arr[500001];
int cnt[8001];
int n;
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    sort(arr+1, arr+n+1);

    long long sum = 0;
    int mid = arr[(n+1)/2];
    int M = -5000, m = 5000;
    for(int i = 1; i <= n; i++)
    {
        sum += arr[i];
        cnt[arr[i]+4000]++;
        M = max(arr[i], M);
        m = min(arr[i], m);
    }

    int mode = 0;
    int MM = -1;
    int flag = false;
    for(int i = 0; i <= 8000; i++)
    {
        if(MM == cnt[i])
        {
            if(flag == false)
            {
                MM = cnt[i];
                mode = i - 4000;
                flag = true;
            }
        }
        if(MM < cnt[i])
        {
            MM = cnt[i];
            mode = i - 4000;
            flag = false;
        }
    }

    printf("%lld\n", (long long)round((double)sum / n));
    printf("%d\n", mid);
    printf("%d\n", mode);
    printf("%d\n", M - m);
}
