#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int, int> pii;

int n;
int arr[1001];
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);

    sort(arr+1, arr+n+1);
    // 3 4 5 8 10
    int i = 0;
    int M = 0;
    for(int k = 0; k <= arr[n]; k++)
    {
        while(i < n && arr[i] < k) i++;
        // printf("i = %d, k = %d, M = %d\n", i, k, M);
        if(n-i+1 >= k && arr[n-k] <= k) M = k;
    }

    printf("%d", M);
}
